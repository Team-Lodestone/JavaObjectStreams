/** @file JavaSerializedClassParser.cpp
*
* @author Zero_DSRS_VX
* @date 3/22/26
*
* @device mac-8
*
* @copyright Copyright (c) 2026 Team Lodestone
* @license This project is licensed under the MIT license, see the LICENSE file for details.
*/

#include "JavaObject/JavaSerializedClassParser.h"
#include "BinaryIO/stream/BinaryInputStream.h"
#include "JavaObject/EJavaFieldDescriptorType.h"

namespace javaobject {
    SerializedField
    SerializedField::parseFieldEntry(const SerializedClass &clazz,
                                     bio::stream::BinaryInputStream &strm) {
        // Parse field entry
        const EJavaFieldDescriptorType type = strm.read<
            EJavaFieldDescriptorType>();
        auto descriptor = std::string(1, type);

        const std::string name = strm.readStringWithLength<char>(
            bio::util::ByteOrder::BIG,
            bio::util::string::StringLengthEncoding::LENGTH_PREFIX);

        // Check if descriptor is object or array
        if (type == TYPE_OBJECT || type == TYPE_ARRAY) {
            descriptor = parseSignature(clazz, type, strm);
        }
        return SerializedField{clazz, name, type, descriptor};
    }

    std::string SerializedField::parseSignature(const SerializedClass &clazz,
                                                const char type,
                                                bio::stream::BinaryInputStream &
                                                strm) {
        // TODO separate type from descriptor, we should then store some tree of types ig?
        // we'll see.
        auto descriptor = std::string(1, type);

        // Check if descriptor is object or array
        if (type == TYPE_OBJECT || type == TYPE_ARRAY) {
            char typeCode = strm.readByte();
            if (typeCode == TYPE_ARRAY) {
                // Read primitive array
                const char arrayType = strm.readByte();
                if (arrayType != TYPE_OBJECT) {
                    descriptor += arrayType;
                } else {
                    descriptor += parseSignature(clazz, arrayType, strm);
                }
            } else if (typeCode == 't') {
                descriptor = strm.readStringWithLength<char>(
                    bio::util::ByteOrder::BIG,
                    bio::util::string::StringLengthEncoding::LENGTH_PREFIX);
            } else if (typeCode == 'q') {
                // Type is the same as the field before this one
                if (!clazz.m_fields.empty()) {
                    descriptor = clazz.m_fields.back().desc;

                    // skip a few bytes
                    // TODO: Figure out if this means anything
                    for (int i = 0; i < 4; i++) {
                        strm.readByte();
                    }
                }
            } else {
                // LOG_DEBUG("Unrecognized type code!");
            }
        }
        return descriptor;
    }

    JavaValue SerializedField::readFieldValue(JavaSerializedClassParser &parser,
                                              const SerializedField &field,
                                              bio::stream::BinaryInputStream &
                                              strm) {
        const auto descriptor = field.desc;
        if (field.type == TYPE_BYTE) {
            return JavaValue{strm.readSignedByte()};
        }
        if (field.type == TYPE_BOOLEAN) {
            return JavaValue{(strm.readByte() != 0)};
        }
        if (field.type == TYPE_CHARACTER) {
            return JavaValue{static_cast<char>(strm.readByte())};
        }
        if (field.type == TYPE_DOUBLE) {
            return JavaValue{strm.readBE<double>()};
        }
        if (field.type == TYPE_FLOAT) {
            return JavaValue{strm.readBE<float>()};
        }
        if (field.type == TYPE_INT) {
            // Java always stores integers as signed
            // C++ uses two's-complements when reading the integer in
            // which means we need to shift this down to get the
            // correct sign and value.
            return JavaValue
                {static_cast<int32_t>(strm.readBE<uint32_t>() >> 8)};
        }
        if (field.type == TYPE_LONG) {
            return JavaValue
                {static_cast<int64_t>(strm.readBE<uint64_t>() >> 8)};
        }
        if (field.type == TYPE_OBJECT) {
            if (descriptor == "Ljava/lang/String;") {
                return JavaValue{
                    std::string(strm.readStringWithLength<char>(
                        bio::util::ByteOrder::BIG,
                        bio::util::string::StringLengthEncoding::LENGTH_PREFIX))};
            }
            strm.seekRelative(-1);
            int offset = strm.getOffset();
            // Object!
            SerializedClass clazz = parser.parseEntry();
            return JavaValue{std::make_shared<JavaObject>(clazz)};
        }
        if (field.type == TYPE_ARRAY) {
            // Array!
            return readFieldValue(parser, field, strm);
        }

        // LOG_DEBUG("Descriptor not yet implemented!");
        return {};
    }

    std::vector<SerializedClass> JavaSerializedClassParser::parseAllEntries() {
        std::vector<SerializedClass> result;
        if (!this->m_stream.getStream().eof()) {
            SerializedClass clazz = this->parseEntry();
        }

        return result;
    }

    SerializedClass JavaSerializedClassParser::parseEntry() {
        SerializedClass result;

        if (const uint16_t classMagic = this->m_stream.readBE<uint16_t>();
            classMagic != 0x7372) {
            return result;
        }

        // Read class name
        result.m_className = this->m_stream.readStringWithLength<char>(
            bio::util::ByteOrder::BIG,
            bio::util::string::StringLengthEncoding::LENGTH_PREFIX);
        this->m_stream.seekRelative(8);

        // TODO: Read fields from serialized class object
        this->m_stream.seekRelative(2); // TODO: Look at this more

        const int8_t numberOfFields = this->m_stream.readSignedByte();

        result.m_fields.clear();

        for (int i = 0; i < numberOfFields; i++) {
            SerializedField field = SerializedField::parseFieldEntry(
                result, this->m_stream);
            result.m_fields.push_back(field);
        }

        char tcEndBlockData = this->m_stream.readByte();
        if (tcEndBlockData != 0x78) {
            // LOG_ERROR(
            // "TCEndBlockData was not found after reading fields! Stream is either corrupted or signature parsing failed!");
        }
        char tcSuperclassDesc = this->m_stream.readByte();
        if (tcSuperclassDesc == 0x72) {
            // Superclass was specified
            // TODO: Implement reading of superclass

            tcEndBlockData = this->m_stream.readByte();
            if (tcEndBlockData != 0x78) {
                // LOG_ERROR(
                // "TCEndBlockData was not found after reading superclass! Stream is either corrupted or superclass could not be parsed!");
            }

            // TODO: Remove this hack:
            // This will skip over the superclass declaration if it exists
            while (true) {
                if (this->m_stream.readByte() == 0x78) {
                    break;
                }
            }
        } else if (tcSuperclassDesc == 0x70) {
            // Superclass was null
        }
        // Skip one byte
        this->m_stream.seekRelative(1);

        // Read field values
        for (int i = 0; i < numberOfFields; i++) {
            SerializedField &field = result.m_fields[i];
            field.value = field.readFieldValue(*this, field, this->m_stream);
        }

        this->m_serializedClasses.push_back(result);
        return result;
    }
} // lodestone::minecraft::common::java::classic::minev3
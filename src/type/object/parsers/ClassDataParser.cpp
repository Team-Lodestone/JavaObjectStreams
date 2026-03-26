/** @file ClassDataParser.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/object/parsers/ClassDataParser.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/object/types/NullObject.h"
#include "JavaObject/type/object/types/descriptor/ClassDescriptorInfoObject.h"

#include <assert.h>

#include "JavaObject/type/primitive/PrimitiveTypeCodeParser.h"

namespace javaobject::type::object::parsers {
    ClassDataParser::ClassDataParser(const std::shared_ptr<object::descriptor::ClassDescriptorInfoObject> &classDescInfo) : m_classDescInfo(classDescInfo) {
        // this->m_parsers = {{
        //
        // }};
    }

    std::shared_ptr<object::IObject> ClassDataParser::operator()(type::object::ObjectTypeCodeParser &parser) const {
        if (this->m_classDescInfo->flags & object::descriptor::ClassDescriptorInfoObject::Flags::SC_SERIALIZABLE) {
            if (this->m_classDescInfo->flags & object::descriptor::ClassDescriptorInfoObject::Flags::SC_WRITE_METHOD) {
                return parseSerializableWriteMethodClassData(parser);
            }
            return parseSerializableClassData(parser);
        }

        if (this->m_classDescInfo->flags & object::descriptor::ClassDescriptorInfoObject::Flags::SC_EXTERNALIZABLE) {
            if (this->m_classDescInfo->flags & object::descriptor::ClassDescriptorInfoObject::Flags::SC_BLOCK_DATA) {
                return parseExternalizableBlockDataClassData(parser);
            }

            return parseExternalizableClassData(parser);
        }

        assert("We're reading classdata, but the result would be null?");
        return std::make_unique<object::NullObject>();
    }

    std::shared_ptr<object::SerializableClassDataObject> ClassDataParser::parseSerializableClassData(type::object::ObjectTypeCodeParser &parser) const {
        auto d = std::make_shared<object::SerializableClassDataObject>();

        auto primitiveParser = parser.parserStorage().primitiveParser;

        // BUG WORKAROUND, REMOVE AFTER WE FIND THE FIX
        parser.stream().seekRelative(-2);
        for (auto &[name, value] : this->m_classDescInfo->fields) {
            const auto typeCode = value->primitiveDescriptor->typeCode;

            //todo check this out since I can't easily see whats going on when using codewithme
            std::shared_ptr<primitive::types::IPrimitiveObject> obj = primitiveParser->readUsingParser(*primitiveParser->getParser(typeCode));

            d->values.emplace(name, obj);
        }

        return d;
    }

    std::shared_ptr<object::SerializableWriteMethodClassDataObject> ClassDataParser::parseSerializableWriteMethodClassData(type::object::ObjectTypeCodeParser &parser) const {

    }

    std::shared_ptr<object::ExternalizableClassDataObject> ClassDataParser::parseExternalizableClassData(type::object::ObjectTypeCodeParser &parser) const {

    }

    std::shared_ptr<object::ExternalizableBlockDataClassDataObject> ClassDataParser::parseExternalizableBlockDataClassData(type::object::ObjectTypeCodeParser &parser) const {

    }
} // namespace javaobject::type::object::parsers
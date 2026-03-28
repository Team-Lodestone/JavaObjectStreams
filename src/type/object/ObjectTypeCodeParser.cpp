/** @file TypeCode.cpp
 *
 * @author DexrnZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 */
#include "JavaObject/type/object/ObjectTypeCodeParser.h"

#include "JavaObject/type/object/parsers/ArrayObjectParser.h"

#include <cassert>
#include <format>

#include "JavaObject/type/primitive/PrimitiveTypeCodeParser.h"

#include "JavaObject/type/object/types/NullObject.h"
#include "JavaObject/type/object/parsers/ObjectParser.h"
#include "JavaObject/type/object/parsers/ReferenceParser.h"
#include "JavaObject/type/object/parsers/StringParser.h"
#include "JavaObject/type/object/parsers/descriptor/NewClassDescriptorParser.h"

#include <istream>

#include "JavaObject/type/object/parsers/EndBlockDataObjectParser.h"
#include "JavaObject/type/object/parsers/LongBlockDataObjectParser.h"
#include "JavaObject/type/object/parsers/NullObjectParser.h"
#include "JavaObject/type/object/parsers/ShortBlockDataObjectParser.h"

namespace javaobject::type::object {
    ObjectTypeCodeParser::ObjectTypeCodeParser(std::istream &input, HandleContainer &handleContainer, TypeCodeParserStorage &parserStorage) : ITypeCodeParser(input, handleContainer), ITypeCodeParserStorageHolder(parserStorage) {
        this->m_parsers[EObjectTypeCode::TC_STRING] = std::make_unique<object::parsers::StringParser>();
        this->m_parsers[EObjectTypeCode::TC_OBJECT] = std::make_unique<object::parsers::ObjectParser>();
        this->m_parsers[EObjectTypeCode::TC_CLASSDESC] = std::make_unique<object::parsers::descriptor::NewClassDescriptorParser>();
        this->m_parsers[EObjectTypeCode::TC_REFERENCE] = std::make_unique<object::parsers::ReferenceParser>();
        this->m_parsers[EObjectTypeCode::TC_ENDBLOCKDATA] = std::make_unique<object::parsers::EndBlockDataObjectParser>();
        this->m_parsers[EObjectTypeCode::TC_BLOCKDATA] = std::make_unique<object::parsers::ShortBlockDataObjectParser>();
        this->m_parsers[EObjectTypeCode::TC_BLOCKDATALONG] = std::make_unique<object::parsers::LongBlockDataObjectParser>();
        this->m_parsers[EObjectTypeCode::TC_NULL] = std::make_unique<parsers::NullObjectParser>();
        this->m_parsers[EObjectTypeCode::TC_ARRAY] = std::make_unique<parsers::ArrayObjectParser>();
    }

    std::shared_ptr<IObject> ObjectTypeCodeParser::readUsingTypeCode(const EObjectTypeCode &typecode) {
        return this->readUsingParser(*this->getParser(typecode));
    }

    std::shared_ptr<object::IObject> ObjectTypeCodeParser::readNext() {
        const EObjectTypeCode tc = static_cast<EObjectTypeCode>(this->m_input.readByte());

#ifdef DEBUG
        std::cout << "tc: " << static_cast<int>(tc) << std::endl;
        std::cout << "pos: " << this->m_input.getOffset() << std::endl;
#endif

        if (const auto it = m_parsers.find(tc); it != this->m_parsers.end()) {
            return this->readUsingParser(*it->second);
        }

        if (tc < EObjectTypeCode::TC_BASE || tc > EObjectTypeCode::TC_MAX) {
            throw std::runtime_error(std::format("typecode {} is out of range!!!", static_cast<int>(tc)));
        }

        throw std::runtime_error(std::format("invalid typecode {}", static_cast<int>(tc)));
        return std::make_shared<object::NullObject>();
    }

    std::shared_ptr<object::IObject> ObjectTypeCodeParser::readUsingParser(const object::parsers::IObjectParser &parser) {
        return parser(*this);
    }
} // namespace javaobject::type
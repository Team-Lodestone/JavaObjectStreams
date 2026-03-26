/** @file PrimitiveTypeCodeParser.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/primitive/PrimitiveTypeCodeParser.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/primitive/parsers/PrimitiveBooleanObjectParser.h"
#include "JavaObject/type/primitive/parsers/PrimitiveByteObjectParser.h"
#include "JavaObject/type/primitive/parsers/PrimitiveCharObjectParser.h"
#include "JavaObject/type/primitive/parsers/PrimitiveDoubleObjectParser.h"
#include "JavaObject/type/primitive/parsers/PrimitiveFloatObjectParser.h"
#include "JavaObject/type/primitive/parsers/PrimitiveIntegerObjectParser.h"
#include "JavaObject/type/primitive/parsers/PrimitiveJavaObjectParser.h"
#include "JavaObject/type/primitive/parsers/PrimitiveLongObjectParser.h"
#include "JavaObject/type/primitive/parsers/PrimitiveShortObjectParser.h"

namespace javaobject::type::primitive {
    PrimitiveTypeCodeParser::PrimitiveTypeCodeParser(std::istream &input, HandleContainer &handleContainer,
        TypeCodeParserStorage &parserStorage) : ITypeCodeParser(input, handleContainer), ITypeCodeStorageHolder(parserStorage) {
        this->m_parsers[EPrimitiveTypeCode::TYPE_BOOLEAN] = std::make_unique<parsers::PrimitiveBooleanObjectParser>();
        this->m_parsers[EPrimitiveTypeCode::TYPE_BYTE] = std::make_unique<parsers::PrimitiveByteObjectParser>();
        this->m_parsers[EPrimitiveTypeCode::TYPE_CHARACTER] = std::make_unique<parsers::PrimitiveCharObjectParser>();
        this->m_parsers[EPrimitiveTypeCode::TYPE_DOUBLE] = std::make_unique<parsers::PrimitiveDoubleObjectParser>();
        this->m_parsers[EPrimitiveTypeCode::TYPE_FLOAT] = std::make_unique<parsers::PrimitiveFloatObjectParser>();
        this->m_parsers[EPrimitiveTypeCode::TYPE_INT] = std::make_unique<parsers::PrimitiveIntegerObjectParser>();
        this->m_parsers[EPrimitiveTypeCode::TYPE_LONG] = std::make_unique<parsers::PrimitiveLongObjectParser>();
        this->m_parsers[EPrimitiveTypeCode::TYPE_SHORT] = std::make_unique<parsers::PrimitiveShortObjectParser>();
        // this->m_parsers[EPrimitiveTypeCode::TYPE_ARRAY] = std::make_unique<parsers::PrimitiveByteObjectParser>();
        this->m_parsers[EPrimitiveTypeCode::TYPE_OBJECT] = std::make_unique<parsers::PrimitiveJavaObjectParser>();
    }

    std::shared_ptr<types::IPrimitiveObject> PrimitiveTypeCodeParser::readNext() {
        const auto tc = static_cast<EPrimitiveTypeCode>(this->m_input.readByte());

        if (const auto it = m_parsers.find(tc); it != this->m_parsers.end()) {
            return this->readUsingParser(*it->second);
        }

        // return std::make_shared<object::NullObject>();
        throw std::runtime_error("Couldn't find parser for primitive typecode");
    }

    std::shared_ptr<types::IPrimitiveObject> PrimitiveTypeCodeParser::readUsingParser(
        const parsers::IPrimitiveObjectParser &parser) {
        return parser(*this);
    }
} // namespace javaobject::type::primitive

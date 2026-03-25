/** @file PrimitiveCharObjectParser.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/primitive/parsers/PrimitiveCharObjectParser.h"

#include "JavaObject/type/primitive/PrimitiveTypeCodeParser.h"
#include "JavaObject/type/primitive/types/PrimitiveCharObject.h"

namespace javaobject::type::primitive::parsers {
    std::shared_ptr<types::IPrimitiveObject> PrimitiveCharObjectParser::operator()(PrimitiveTypeCodeParser &parser) const {
        return std::make_unique<types::PrimitiveCharObject>(parser.stream().readBE<char16_t>());
    }
} // namespace javaobject::type::primitive::parsers
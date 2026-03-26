/** @file PrimitiveFloatObjectParser.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/primitive/parsers/PrimitiveFloatObjectParser.h"

#include "JavaObject/type/primitive/PrimitiveTypeCodeParser.h"
#include "JavaObject/type/primitive/types/PrimitiveFloatObject.h"

namespace javaobject::type::primitive::parsers {
    std::shared_ptr<types::IPrimitiveObject> PrimitiveFloatObjectParser::operator()(PrimitiveTypeCodeParser &parser) const {
        return std::make_unique<types::PrimitiveFloatObject>(parser.stream().readBE<float>());
    }
} // namespace javaobject::type::primitive::parsers
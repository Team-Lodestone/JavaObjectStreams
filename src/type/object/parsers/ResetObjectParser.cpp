/** @file ResetObjectParser.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/28/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/object/parsers/ResetObjectParser.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/object/types/ResetObject.h"

namespace javaobject::type::object::parsers {
    std::shared_ptr<object::IObject> ResetObjectParser::operator()(type::object::ObjectTypeCodeParser &parser) const {
        parser.handleContainer().reset();

        return std::make_unique<types::ResetObject>();
    }
} // namespace javaobject::type::object::parsers
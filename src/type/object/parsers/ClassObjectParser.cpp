/** @file ClassObjectParser.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/28/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/object/parsers/ClassObjectParser.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"

namespace javaobject::type::object::parsers {
    std::shared_ptr<object::IObject> ClassObjectParser::operator()(type::object::ObjectTypeCodeParser &parser) const {
        std::shared_ptr<object::IObject> desc = parser.readNext();
        parser.handleContainer().registerHandle(desc);

        return desc;
    }
} // namespace javaobject::type::object::parsers
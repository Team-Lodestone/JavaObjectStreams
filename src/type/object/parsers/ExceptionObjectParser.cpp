/** @file ExceptionObjectParser.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/28/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/object/parsers/ExceptionObjectParser.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"

namespace javaobject::type::object::parsers {
    std::shared_ptr<object::IObject> ExceptionObjectParser::operator()(type::object::ObjectTypeCodeParser &parser) const {
        parser.handleContainer().reset();

        std::shared_ptr<IObject> ex = parser.readNext();

        parser.handleContainer().reset();

        return ex;
    }
} // namespace javaobject::type::object::parsers
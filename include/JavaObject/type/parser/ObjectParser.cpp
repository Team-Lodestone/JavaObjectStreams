/** @file ObjectParser.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file
 * for details.
 */
#include "ObjectParser.h"

#include "JavaObject/type/TypeCodeParser.h"
#include "JavaObject/type/object/NullObject.h"
#include "JavaObject/type/object/Object.h"

namespace javaobject::type::parser {
    std::shared_ptr<object::IObject> ObjectParser::operator()(TypeCodeParser &parser) const {
        std::shared_ptr<object::IObject> obj = parser.readNext();
        // todo classdata descriptor

        return std::make_shared<object::Object>(std::move(obj), std::make_shared<object::NullObject>());
    }
} // namespace javaobject::type::parser
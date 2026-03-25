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
#include "JavaObject/type/object/parsers/ObjectParser.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/object/parsers/ClassDataParser.h"
#include "JavaObject/type/object/types/NullObject.h"
#include "JavaObject/type/object/types/Object.h"

namespace javaobject::type::object::parsers {
    std::shared_ptr<object::IObject> ObjectParser::operator()(type::object::ObjectTypeCodeParser &parser) const {
        std::shared_ptr<object::IObject> obj = parser.readNext();
        std::shared_ptr<IObject> data = ClassDataParser(std::static_pointer_cast<descriptor::ClassDescriptorObject>(obj)->desc->info)(parser);

        return std::make_shared<object::Object>(std::move(obj), std::make_shared<object::NullObject>());
    }
} // namespace javaobject::type::object::parsers
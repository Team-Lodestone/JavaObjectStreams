/** @file ClassDescriptorParser.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/parser/descriptor/ClassDescriptorParser.h"

#include "JavaObject/type/TypeCodeParser.h"
#include "JavaObject/type/object/descriptor/ClassDescriptorObject.h"
#include "JavaObject/type/object/descriptor/NewClassDescriptorObject.h"
#include "JavaObject/type/parser/descriptor/NewClassDescriptorParser.h"
#include "JavaObject/util/SmartPointerCast.h"

namespace javaobject::type::parser::descriptor {
    std::unique_ptr<object::IObject> ClassDescriptorParser::operator()(TypeCodeParser &parser) const {
        // TODO UNSAFE!!!!!!
        // Class objects can sometimes be references, or not exist at all!
        // We can probably wrap many types in an std::variant to bypass this.
        auto desc = util::SmartPointerCast::staticUniquePtrCast<object::descriptor::NewClassDescriptorObject>(NewClassDescriptorParser()(parser));
        auto nullReference = parser.readNext();
        auto prevObject = parser.readNext();

        return std::make_unique<object::descriptor::ClassDescriptorObject>(
            std::move(desc),
            std::move(nullReference),
            std::move(prevObject)
        );
    }
} // namespace javaobject::type::parser::descriptor
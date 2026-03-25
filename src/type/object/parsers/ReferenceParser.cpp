/** @file ReferenceParser.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/object/parsers/ReferenceParser.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/object/types/NullObject.h"
#include "JavaObject/type/object/types/ReferenceObject.h"

namespace javaobject::type::object::parsers {
    std::shared_ptr<object::IObject> ReferenceParser::operator()(type::object::ObjectTypeCodeParser &parser) const {
        const auto ref = std::make_shared<object::ReferenceObject>(
            parser.stream().readBE<object::ReferenceObject::handle_t>()
        );

        auto v = parser.handleContainer().resolveReference(ref.get());
        if (v == nullptr) {
            return std::make_shared<object::NullObject>();
        }

        return v;
    }
} // namespace javaobject::type::object::parsers
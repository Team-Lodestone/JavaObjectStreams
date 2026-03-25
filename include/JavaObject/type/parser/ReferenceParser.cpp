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
#include "ReferenceParser.h"

#include "JavaObject/type/TypeCodeParser.h"
#include "JavaObject/type/object/ReferenceObject.h"

namespace javaobject::type::parser {
    std::unique_ptr<object::IObject> ReferenceParser::operator()(TypeCodeParser &parser) const {
        // TODO link classes to references!!!!!!!!!
        return std::make_unique<object::ReferenceObject>(
            parser.stream().readBE<object::ReferenceObject::handle_t>()
        );
    }
} // namespace javaobject::type::parser
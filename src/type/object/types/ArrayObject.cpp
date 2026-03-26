/** @file ArrayObject.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/object/types/ArrayObject.h"

#include <format>

namespace javaobject::type::object::types {
    std::string ArrayObject::toString() {
        return std::format("Array(type={}, size={})", typeDescriptor->toString(), this->values.size());
    }
} // namespace javaobject::type::object::types
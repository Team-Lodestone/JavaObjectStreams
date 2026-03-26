/** @file PrimitiveDescriptorObject.cpp
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
#include "JavaObject/type/object/types/descriptor/PrimitiveDescriptorObject.h"

#include <format>
#include "JavaObject/EPrimitiveTypeCode.h"

namespace javaobject::type::object::descriptor {
    std::string PrimitiveDescriptorObject::toString() {
        return std::format("PrimitiveDescriptor(name=\"{}\", typecode={})", this->name, this->typeCode);
    }
} // namespace javaobject::type::object::descriptor
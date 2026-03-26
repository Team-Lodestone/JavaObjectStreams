/** @file FieldDescriptorObject.cpp
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
#include "JavaObject/type/object/types/descriptor/FieldDescriptorObject.h"

namespace javaobject::type::object::descriptor {
    std::string FieldDescriptorObject::toString() {
        if (this->objectDescriptor != nullptr)
            return std::format("FieldDescriptor(name=\"{}\", type={})", this->primitiveDescriptor->name, this->objectDescriptor->toString());

        return std::format("FieldDescriptor(name=\"{}\", type={})", this->primitiveDescriptor->name, this->primitiveDescriptor->typeCode);
    }
} // namespace javaobject::type::object::descriptor
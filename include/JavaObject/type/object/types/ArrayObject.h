/** @file ArrayObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_ARRAYOBJECT_H
#define JAVAOBJECTSTREAMS_ARRAYOBJECT_H
#include "JavaObject/type/object/types/IObject.h"
#include "JavaObject/type/object/types/descriptor/NewClassDescriptorObject.h"
#include "JavaObject/type/primitive/types/IPrimitiveObject.h"

#include <memory>
#include <vector>

namespace javaobject::type::object::types {
    struct ArrayObject : IObject {
        ArrayObject(const std::shared_ptr<descriptor::NewClassDescriptorObject> &typeDescriptor, const std::vector<std::shared_ptr<primitive::types::IPrimitiveObject>> &values)
            : typeDescriptor(typeDescriptor), values(values) {}

        explicit ArrayObject(const std::shared_ptr<descriptor::NewClassDescriptorObject> &typeDescriptor)
            : typeDescriptor(typeDescriptor) {}

        std::string toString() override;

        std::shared_ptr<descriptor::NewClassDescriptorObject> typeDescriptor;
        std::vector<std::shared_ptr<primitive::types::IPrimitiveObject>> values;
    };
} // namespace javaobject::type::object::types

#endif // JAVAOBJECTSTREAMS_ARRAYOBJECT_H

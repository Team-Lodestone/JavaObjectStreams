/** @file FieldDescriptorObject.h
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
#ifndef JAVAOBJECTSTREAMS_FIELDDESCRIPTOROBJECT_H
#define JAVAOBJECTSTREAMS_FIELDDESCRIPTOROBJECT_H
#include "JavaObject/type/object/types/IObject.h"
#include "JavaObject/type/object/types/descriptor/PrimitiveDescriptorObject.h"

#include <memory>

namespace javaobject::type::object::descriptor {
    struct FieldDescriptorObject : public IObject {
        FieldDescriptorObject(std::shared_ptr<PrimitiveDescriptorObject> &&primitiveDescriptor, std::shared_ptr<IObject> &&objectDescriptor)
            : primitiveDescriptor(std::move(primitiveDescriptor)),
              objectDescriptor(std::move(objectDescriptor)) {}

        std::shared_ptr<PrimitiveDescriptorObject> primitiveDescriptor;
        std::shared_ptr<IObject> objectDescriptor; // nullptr if primitive type is not OBJECT, ARRAY
    };
} // namespace javaobject::type::object::descriptor

#endif // JAVAOBJECTSTREAMS_FIELDDESCRIPTOROBJECT_H

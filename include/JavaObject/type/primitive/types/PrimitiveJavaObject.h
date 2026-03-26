/** @file PrimitiveJavaObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_PRIMITIVEJAVAOBJECT_H
#define JAVAOBJECTSTREAMS_PRIMITIVEJAVAOBJECT_H
#include "JavaObject/type/object/types/IObject.h"
#include "JavaObject/type/primitive/types/IPrimitiveObject.h"
#include <memory>

namespace javaobject::type::primitive::types {
    struct PrimitiveJavaObject : IPrimitiveTypeObject<std::shared_ptr<object::IObject>> {
        explicit PrimitiveJavaObject(const std::shared_ptr<object::IObject> &obj) : IPrimitiveTypeObject(obj) {}

        EPrimitiveTypeCode typeCode() override;
    };
} // namespace javaobject::type::primitive::types

#endif // JAVAOBJECTSTREAMS_PRIMITIVEJAVAOBJECT_H

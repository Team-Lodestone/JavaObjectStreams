/** @file PrimitiveIntegerObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_PRIMITIVEINTEGEROBJECT_H
#define JAVAOBJECTSTREAMS_PRIMITIVEINTEGEROBJECT_H
#include "JavaObject/type/primitive/types/IPrimitiveObject.h"

#include <cstdint>

namespace javaobject::type::primitive::types {
    struct PrimitiveIntegerObject : IPrimitiveTypeObject<std::int32_t> {
        explicit PrimitiveIntegerObject(const std::int32_t i) : IPrimitiveTypeObject(i) {}

        EPrimitiveTypeCode typeCode() override;
    };
} // namespace javaobject::type::primitive::types

#endif // JAVAOBJECTSTREAMS_PRIMITIVEINTEGEROBJECT_H

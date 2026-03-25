/** @file PrimitiveByteObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_PRIMITIVEBYTEOBJECT_H
#define JAVAOBJECTSTREAMS_PRIMITIVEBYTEOBJECT_H
#include "JavaObject/type/primitive/types/IPrimitiveObject.h"

#include <cstdint>

namespace javaobject::type::primitive::types {
    struct PrimitiveByteObject : IPrimitiveTypeObject<std::int8_t> {
        explicit PrimitiveByteObject(const std::int8_t byte) : IPrimitiveTypeObject(byte) {}

        EPrimitiveTypeCode typeCode() override;
    };
} // namespace javaobject::type::primitive::types

#endif // JAVAOBJECTSTREAMS_PRIMITIVEBYTEOBJECT_H

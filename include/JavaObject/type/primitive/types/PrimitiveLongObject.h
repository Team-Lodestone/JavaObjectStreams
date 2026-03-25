/** @file PrimitiveLongObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_PRIMITIVELONGOBJECT_H
#define JAVAOBJECTSTREAMS_PRIMITIVELONGOBJECT_H
#include "JavaObject/type/primitive/types/IPrimitiveObject.h"

#include <cstdint>

namespace javaobject::type::primitive::types {
    struct PrimitiveLongObject : IPrimitiveTypeObject<std::int64_t> {
        explicit PrimitiveLongObject(const std::int64_t l) : IPrimitiveTypeObject(l) {}

        EPrimitiveTypeCode typeCode() override;
    };
} // namespace javaobject::type::primitive::types

#endif // JAVAOBJECTSTREAMS_PRIMITIVELONGOBJECT_H

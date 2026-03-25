/** @file PrimitiveBooleanObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_PRIMITIVEBOOLEANOBJECT_H
#define JAVAOBJECTSTREAMS_PRIMITIVEBOOLEANOBJECT_H
#include "JavaObject/type/primitive/types/IPrimitiveObject.h"

namespace javaobject::type::primitive::types {
    struct PrimitiveBooleanObject : IPrimitiveTypeObject<bool> {
        explicit PrimitiveBooleanObject(const bool b) : IPrimitiveTypeObject(b) {}

        EPrimitiveTypeCode typeCode() override;
    };
} // namespace javaobject::type::primitive::types

#endif // JAVAOBJECTSTREAMS_PRIMITIVEBOOLEANOBJECT_H

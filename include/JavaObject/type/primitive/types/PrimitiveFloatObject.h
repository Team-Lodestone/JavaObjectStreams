/** @file PrimitiveFloatObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_PRIMITIVEFLOATOBJECT_H
#define JAVAOBJECTSTREAMS_PRIMITIVEFLOATOBJECT_H
#include "JavaObject/type/primitive/types/IPrimitiveObject.h"

namespace javaobject::type::primitive::types {
    struct PrimitiveFloatObject : IPrimitiveTypeObject<float> {
        explicit PrimitiveFloatObject(const float f) : IPrimitiveTypeObject(f) {}

        EPrimitiveTypeCode typeCode() override;
    };
} // namespace javaobject::type::primitive::types

#endif // JAVAOBJECTSTREAMS_PRIMITIVEFLOATOBJECT_H

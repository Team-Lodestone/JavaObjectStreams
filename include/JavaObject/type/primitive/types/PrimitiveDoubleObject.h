/** @file PrimitiveDoubleObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_PRIMITIVEDOUBLEOBJECT_H
#define JAVAOBJECTSTREAMS_PRIMITIVEDOUBLEOBJECT_H
#include "JavaObject/type/primitive/types/IPrimitiveObject.h"

namespace javaobject::type::primitive::types {
    struct PrimitiveDoubleObject : IPrimitiveTypeObject<double> {
        explicit PrimitiveDoubleObject(const double d) : IPrimitiveTypeObject(d) {}

        EPrimitiveTypeCode typeCode() override;
    };
} // namespace javaobject::type::primitive::types

#endif // JAVAOBJECTSTREAMS_PRIMITIVEDOUBLEOBJECT_H

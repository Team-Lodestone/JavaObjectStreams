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
#include "JavaObject/type/primitive/types/IPrimitiveObject.h"

namespace javaobject::type::primitive::types {
    struct PrimitiveJavaObject : IPrimitiveObject {
        EPrimitiveTypeCode typeCode() override;
    };
} // namespace javaobject::type::primitive::types

#endif // JAVAOBJECTSTREAMS_PRIMITIVEJAVAOBJECT_H

/** @file PrimitiveJavaObject.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/primitive/types/PrimitiveJavaObject.h"

namespace javaobject::type::primitive::types {
    EPrimitiveTypeCode PrimitiveJavaObject::typeCode() {
        return EPrimitiveTypeCode::TYPE_OBJECT;
    }
} // namespace javaobject::type::primitive::types
/** @file PrimitiveArrayObject.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/primitive/types/PrimitiveArrayObject.h"

namespace javaobject::type::primitive::types {
    EPrimitiveTypeCode PrimitiveArrayObject::typeCode() {
        return EPrimitiveTypeCode::TYPE_ARRAY;
    }
} // namespace javaobject::type::primitive::types
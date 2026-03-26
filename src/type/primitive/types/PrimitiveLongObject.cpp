/** @file PrimitiveLongObject.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/primitive/types/PrimitiveLongObject.h"

namespace javaobject::type::primitive::types {
    EPrimitiveTypeCode PrimitiveLongObject::typeCode() {
        return EPrimitiveTypeCode::TYPE_LONG;
    }
} // namespace javaobject::type::primitive::types
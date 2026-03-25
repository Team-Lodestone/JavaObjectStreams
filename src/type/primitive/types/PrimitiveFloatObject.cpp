/** @file PrimitiveFloatObject.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/primitive/types/PrimitiveFloatObject.h"

namespace javaobject::type::primitive::types {
    EPrimitiveTypeCode PrimitiveFloatObject::typeCode() {
        return EPrimitiveTypeCode::TYPE_FLOAT;
    }
} // namespace javaobject::type::primitive::types
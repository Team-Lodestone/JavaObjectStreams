/** @file PrimitiveShortObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_PRIMITIVESHORTOBJECT_H
#define JAVAOBJECTSTREAMS_PRIMITIVESHORTOBJECT_H
#include "JavaObject/type/primitive/types/IPrimitiveObject.h"

#include <cstdint>

namespace javaobject::type::primitive::types {
    struct PrimitiveShortObject : IPrimitiveTypeObject<std::int16_t> {
        explicit PrimitiveShortObject(const std::int16_t s) : IPrimitiveTypeObject(s) {}

        EPrimitiveTypeCode typeCode() override;
    };
} // namespace javaobject::type::primitive::types

#endif // JAVAOBJECTSTREAMS_PRIMITIVESHORTOBJECT_H

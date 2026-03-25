/** @file IPrimitiveObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_IPRIMITIVEOBJECT_H
#define JAVAOBJECTSTREAMS_IPRIMITIVEOBJECT_H
#include "JavaObject/EPrimitiveTypeCode.h"

#include <type_traits>

namespace javaobject::type::primitive::types {
    struct IPrimitiveObject {
        virtual ~IPrimitiveObject() = default;

        virtual EPrimitiveTypeCode typeCode() = 0;

        template <typename T>
        requires std::is_base_of_v<IPrimitiveObject, T>
        T *as() {
            return dynamic_cast<T>(this);
        }
    };

    template <typename T>
    struct IPrimitiveTypeObject : IPrimitiveObject {
        explicit IPrimitiveTypeObject(T value) : value(value) {}

        operator T() {
            return value;
        }

        T value;
    };
} // namespace javaobject::type::primitive::types

#endif // JAVAOBJECTSTREAMS_IPRIMITIVEOBJECT_H

/** @file IObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file
 * for details.
 */
#ifndef JAVAOBJECTSTREAMS_IOBJECT_H
#define JAVAOBJECTSTREAMS_IOBJECT_H

#include <memory>
#include <string>
#include <typeinfo>

namespace javaobject::type::object {
    class IObject {
    public:
        virtual ~IObject() = default;

        virtual std::string toString();

        template <typename T>
        requires std::is_base_of_v<IObject, T>
        constexpr bool instanceOf() {
            return typeid(*this) == typeid(T);
        }

        template <typename T>
        requires std::is_base_of_v<IObject, T>
        bool instanceOf(std::shared_ptr<T> object) {
           return typeid(*this) == typeid(*object);
        }

        template <typename T>
        requires std::is_base_of_v<IObject, T>
        T *as() {
            return dynamic_cast<T *>(this);
        }
    };
} // namespace javaobject::type::object

#endif // JAVAOBJECTSTREAMS_IOBJECT_H

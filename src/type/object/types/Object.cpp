/** @file Object.cpp
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
#include "JavaObject/type/object/types/Object.h"

#include <format>

namespace javaobject::type::object {
    Object::Object(std::shared_ptr<object::IObject> &&clazz, std::shared_ptr<object::IObject> &&classData)
        : clazz(std::move(clazz)), classData(std::move(classData)) {}

    std::string Object::toString() {
        return std::format("Object(class={}, data={})", clazz->toString(), classData != nullptr ? classData->toString() : "null");
    }
} // namespace javaobject::type::object
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
#include "Object.h"

namespace javaobject::type::object {
    Object::Object(std::unique_ptr<object::IObject> &&clazz, std::unique_ptr<object::IObject> &&classData)
        : clazz(std::move(clazz)), classData(std::move(classData)) {}
} // namespace javaobject::type::object
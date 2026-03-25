/** @file StringObject.cpp
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
#include "StringObject.h"

namespace javaobject::type::object {
    StringObject::StringObject(const std::string &value) : value(value) {}
} // namespace javaobject::type::object
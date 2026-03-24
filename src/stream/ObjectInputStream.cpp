/** @file ObjectInputStream.cpp
 *
 * @author DexrnZacAttack
 * @date 3/23/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/stream/ObjectInputStream.h"

namespace javaobject::stream {
    ObjectInputStream::ObjectInputStream(std::istream &input) : m_input(input) {
    }
}

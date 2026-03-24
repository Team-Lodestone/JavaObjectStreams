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

#include "JavaObject/type/object/NullObject.h"

namespace javaobject::stream {
    ObjectInputStream::ObjectInputStream(std::istream &input) : m_input(input), m_stream(input), m_parser(input) {
    }

    std::unique_ptr<type::object::IObject> ObjectInputStream::readObject() {
        uint16_t magic = this->m_stream.readBE<uint16_t>();
        if (magic != 0xACED) {
            return std::make_unique<type::object::NullObject>();
        }

        int16_t count = this->m_stream.readBE<uint16_t>();

        return this->m_parser.readNext();
    }
} // namespace javaobject::stream
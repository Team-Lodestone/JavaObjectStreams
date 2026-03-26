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

#include "JavaObject/type/object/types/NullObject.h"
#include "JavaObject/type/primitive/PrimitiveTypeCodeParser.h"

namespace javaobject::stream {
    ObjectInputStream::ObjectInputStream(std::istream &input) : m_handleContainer(), m_input(input), m_stream(input) {
        this->m_parsers.objectParser = std::make_shared<type::object::ObjectTypeCodeParser>(input, m_handleContainer, m_parsers);
        this->m_parsers.primitiveParser = std::make_shared<type::primitive::PrimitiveTypeCodeParser>(input, m_handleContainer, m_parsers);
    }

    std::shared_ptr<type::object::IObject> ObjectInputStream::readObject() {
        const uint16_t magic = this->m_stream.readBE<uint16_t>();
        if (magic != 0xACED) {
            return std::make_shared<type::object::NullObject>();
        }

        int16_t count = this->m_stream.readBE<uint16_t>();

        return this->m_parsers.objectParser->readNext();
    }
} // namespace javaobject::stream
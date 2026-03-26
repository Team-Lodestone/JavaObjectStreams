/** @file ObjectInputStream.h
 *
 * @author DexrnZacAttack
 * @date 3/23/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_OBJECTINPUTSTREAM_H
#define JAVAOBJECTSTREAMS_OBJECTINPUTSTREAM_H
#include "../type/object/ObjectTypeCodeParser.h"
#include "../type/object/types/IObject.h"

#include <iostream>
#include <memory>

// TODO

namespace javaobject::stream {
    class ObjectInputStream {
    public:
        explicit ObjectInputStream(std::istream &input);

        std::shared_ptr<type::object::IObject> readObject();

        ObjectInputStream &operator>>(std::shared_ptr<type::object::IObject> &object);
    private:
        type::HandleContainer m_handleContainer;

        std::istream &m_input;
        bio::stream::BinaryInputStream m_stream;

        type::TypeCodeParserStorage m_parsers;
    };

    //some people might prefer STL naming scheme for this, so why not:
    using iobjectstream = ObjectInputStream;
}

#endif // JAVAOBJECTSTREAMS_OBJECTINPUTSTREAM_H
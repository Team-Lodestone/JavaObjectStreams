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
#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/object/types/IObject.h"
#include "JavaObject/type/object/types/StringObject.h"
#include "JavaObject/type/primitive/types/PrimitiveBooleanObject.h"
#include "JavaObject/type/primitive/types/PrimitiveByteObject.h"
#include "JavaObject/type/primitive/types/PrimitiveDoubleObject.h"
#include "JavaObject/type/primitive/types/PrimitiveFloatObject.h"
#include "JavaObject/type/primitive/types/PrimitiveIntegerObject.h"
#include "JavaObject/type/primitive/types/PrimitiveLongObject.h"
#include "JavaObject/type/primitive/types/PrimitiveShortObject.h"

#include <iostream>
#include <memory>

// TODO

namespace javaobject::stream {
    class ObjectInputStream {
    public:
        explicit ObjectInputStream(std::istream &input);

        std::shared_ptr<type::object::IObject> readObject() const;

        // TODO seemingly these objects are all written into a BlockData section, ugh!
        std::shared_ptr<type::primitive::types::PrimitiveBooleanObject> readBool() const = delete;
        std::shared_ptr<type::primitive::types::PrimitiveByteObject> readByte() const = delete;
        std::shared_ptr<type::primitive::types::PrimitiveShortObject> readShort() const = delete;
        std::shared_ptr<type::primitive::types::PrimitiveIntegerObject> readInt() const = delete;
        std::shared_ptr<type::primitive::types::PrimitiveLongObject> readLong() const = delete;
        std::shared_ptr<type::primitive::types::PrimitiveFloatObject> readFloat() const = delete;
        std::shared_ptr<type::primitive::types::PrimitiveDoubleObject> readDouble() const = delete;


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

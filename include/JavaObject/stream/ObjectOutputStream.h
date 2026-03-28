/** @file ObjectOutputStream.h
 *
 * @author DexrnZacAttack
 * @date 3/23/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_OBJECTOUTPUTSTREAM_H
#define JAVAOBJECTSTREAMS_OBJECTOUTPUTSTREAM_H
#include "JavaObject/type/object/types/IObject.h"

#include <cstdint>
#include <memory>
#include <string>

// TODO

namespace javaobject::stream {
    class ObjectOutputStream {
        void writeObject(std::shared_ptr<type::object::IObject> obj);
        void writeBool(bool b);
        void writeByte(std::int8_t b);
        void writeShort(std::int16_t s);
        void writeInt(std::int32_t i);
        void writeLong(std::int64_t l);
        void writeFloat(float f);
        void writeDouble(double d);
        void writeString(const std::string &s);
    };

    using oobjectstream = ObjectOutputStream;
}

#endif // JAVAOBJECTSTREAMS_OBJECTOUTPUTSTREAM_H

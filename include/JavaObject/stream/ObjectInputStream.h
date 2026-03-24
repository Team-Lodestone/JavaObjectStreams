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
#include <iostream>

// TODO

namespace javaobject::stream {
    class ObjectInputStream {
    public:
        explicit ObjectInputStream(std::istream &input);

        //todo
        // ObjectInputStream &operator>>(? value);
    private:
        std::istream &m_input;
    };

    //some people might prefer STL naming scheme for this, so why not:
    using iobjectstream = ObjectInputStream;
}

#endif // JAVAOBJECTSTREAMS_OBJECTINPUTSTREAM_H

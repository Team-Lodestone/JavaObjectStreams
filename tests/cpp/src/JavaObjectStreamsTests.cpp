/** @file JavaObjectStreamsTests.cpp
 *
 * @author DexrnZacAttack
 * @date 3/23/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include <TestFramework/TestFramework.h>

#include "BinaryIO/stream/BinaryInputStream.h"
#include "JavaObject/JavaSerializedClassParser.h"

int main() {
    //todo add all tests
    tfw::TestFramework::getInstance()->addTest(READ_OBJECT_FILE, "Read input object", [](const tfw::test::util::TestOutputLogger &logger) {
        std::ifstream is("../../../../JavaObjectStreams/tests/cpp/input/JOSTestClass.obj");
        if (!is.is_open()) {
            throw std::runtime_error("Could not open input object");
        }
        bio::stream::BinaryInputStream bis(is);
        bis.seekRelative(4);

        auto parser = javaobject::JavaSerializedClassParser(bis);
        parser.parseEntry();
    });

    tfw::TestFramework::getInstance()->run();

    return 0;
}

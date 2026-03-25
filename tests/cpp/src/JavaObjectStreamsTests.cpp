/** @file JavaObjectStreamsTests.cpp
 *
 * @author DexrnZacAttack
 * @date 3/23/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file
 * for details.
 */
#include "JavaObject/stream/ObjectInputStream.h"

#include <TestFramework/TestFramework.h>

int main() {
    //todo add all tests
    // tfw::TestFramework::getInstance()->addTest(READ_OBJECT_FILE, "Read input object", [](const tfw::test::util::TestOutputLogger &logger) {
        std::ifstream input("input/JOSTestClass.obj");
        input.exceptions(std::ios::badbit | std::ios::eofbit);

        if (!input.is_open()) {
            throw std::runtime_error("nah");
        }

        javaobject::stream::ObjectInputStream ois(input);
        auto obj = ois.readObject();
    // });

    // tfw::TestFramework::getInstance()->run();

    return 0;
}
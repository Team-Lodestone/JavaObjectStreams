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

int main() {
    //todo add all tests
    tfw::TestFramework::getInstance()->addTest(READ_OBJECT_FILE, "Read input object", [](const tfw::test::util::TestOutputLogger &logger) {
       throw std::runtime_error("Not implemented");
    });

    tfw::TestFramework::getInstance()->run();

    return 0;
}
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
#include "JavaObject/type/object/types/ArrayObject.h"
#include "JavaObject/type/object/types/NullObject.h"

#include <TestFramework/TestFramework.h>

int main() {
    //todo add all tests
    tfw::TestFramework::getInstance()->addTest(READ_OBJECT_FILE, "Read input object", [](const tfw::test::util::TestOutputLogger &logger) {
        std::ifstream input("input/JOSTestClass.obj");
        input.exceptions(std::ios::badbit | std::ios::eofbit);

        if (!input.is_open()) {
            throw std::runtime_error("nah");
        }

        javaobject::stream::ObjectInputStream ois(input);
        auto obj = ois.readObject();
    });

    tfw::TestFramework::getInstance()->addTest(READ_NULL_OBJECT_FILE, "Read null input object", [](const tfw::test::util::TestOutputLogger &logger) {
        std::ifstream input("input/JOSTestNull.obj");
        input.exceptions(std::ios::badbit | std::ios::eofbit);

        if (!input.is_open()) {
            throw std::runtime_error("nah");
        }

        javaobject::stream::ObjectInputStream ois(input);
        auto obj = ois.readObject();

        return tfw::test::result::TestResult(obj->instanceOf<javaobject::type::object::NullObject>());
    });

    tfw::TestFramework::getInstance()->addTest(READ_ARRAY_OBJECT_FILE, "Read array input object", [](const tfw::test::util::TestOutputLogger &logger) {
        std::ifstream input("input/JOSTestArray.obj");
        input.exceptions(std::ios::badbit | std::ios::eofbit);

        if (!input.is_open()) {
            throw std::runtime_error("nah");
        }

        javaobject::stream::ObjectInputStream ois(input);
        auto obj = ois.readObject();

        return tfw::test::result::TestResult(obj->instanceOf<javaobject::type::object::types::ArrayObject>());
    });

    tfw::TestFramework::getInstance()->addTest(READ_ARRAY_OBJECT_FILE_WITH_EXTRA_DATA, "Read array + extra data input object", [](const tfw::test::util::TestOutputLogger &logger) {
        std::ifstream input("input/JOSTestArrayWithExtraData.obj");
        input.exceptions(std::ios::badbit | std::ios::eofbit);

        if (!input.is_open()) {
            throw std::runtime_error("nah");
        }

        javaobject::stream::ObjectInputStream ois(input);
        auto dat = ois.readObject();
        auto array = ois.readObject();

        return tfw::test::result::TestResult(array->instanceOf<javaobject::type::object::types::ArrayObject>());
    });

    // TODO: Re-serialize read object in WRITE_MINECRAFT_OBJECT_FILE
    tfw::TestFramework::getInstance()->addTest(READ_MINECRAFT_OBJECT_FILE, "Read Minecraft object", [](const tfw::test::util::TestOutputLogger &logger) {
        std::ifstream input("input/MinecraftJOSTestClass.obj");
        input.exceptions(std::ios::badbit | std::ios::eofbit);

        if (!input.is_open()) {
            throw std::runtime_error("nah");
        }

        javaobject::stream::ObjectInputStream ois(input);
        auto obj = ois.readObject();
    });

    tfw::TestFramework::getInstance()->run();

    return 0;
}
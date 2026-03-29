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

std::shared_ptr<javaobject::type::object::IObject> readObject(tfw::test::logging::loggers::ITestLogger &logger, const std::string &path) {
    std::ifstream input(path);
    input.exceptions(std::ios::badbit | std::ios::eofbit);

    if (!input.is_open()) {
        throw std::system_error(std::make_error_code(std::errc::no_such_file_or_directory));
    }

    logger << "Hello, world!" << std::endl;

    javaobject::stream::ObjectInputStream ois(input);
    return ois.readObject();
}

tfw::test::result::TestResult readObjectTest(tfw::test::logging::loggers::ITestLogger &logger, const std::string &path) {
    const auto obj = readObject(logger, path);

    return tfw::test::result::TestResult(true, obj->toString());
}

template <typename T>
requires std::is_base_of_v<javaobject::type::object::IObject, T>
tfw::test::result::TestResult readObjectTestRequireInstanceOf(tfw::test::logging::loggers::ITestLogger &logger, const std::string &path) {
    const auto obj = readObject(logger, path);

    return tfw::test::result::TestResult(obj->instanceOf<T>(), obj->toString());
}

int main(const int argv, char *argc[]) {
    tfw::TestFramework t = tfw::TestFramework::fromArgs(argv, argc);

    //todo add all tests
    t.addTest(READ_OBJECT_FILE, "Read data class object", readObjectTest, "input/JOSDataClass.obj");
    t.addTest(READ_SUBCLASSED_CLASS_OBJECT_FILE, "Read class object with subclass fields", readObjectTest, "input/JOSSubclassedClass.obj");
    t.addTest(READ_NULL_OBJECT_FILE, "Read null object", readObjectTestRequireInstanceOf<javaobject::type::object::NullObject>, "input/JOSNullObject.obj");
    t.addTest(READ_PROXY_OBJECT_FILE, "Read proxy class object", readObjectTest, "input/JOSProxyClass.obj");

    t.addTest(READ_EXTERNALIZABLE_CLASS_OBJECT_FILE, "Read externalizable class object", readObjectTest, "input/JOSExternalizableClass.obj");
    t.addTest(READ_EXTERNALIZABLE_EXTRA_DATA_CLASS_OBJECT_FILE, "Read externalizable class object with extra data", readObjectTest, "input/JOSExternalizableWithExtraDataClass.obj");
    t.addTest(READ_EMPTY_EXTERNALIZABLE_CLASS_OBJECT_FILE, "Read empty externalizable class object", readObjectTest, "input/JOSEmptyExternalizableClass.obj");

    t.addTest(READ_ARRAY_OBJECT_FILE, "Read array object", readObjectTest, "input/JOSArrayClass.obj");
    t.addTest(READ_NESTED_ARRAY_OBJECT_FILE, "Read nested array object", readObjectTest, "input/JOSNestedArrayClass.obj");

    t.addTest(READ_POLYMORPHIC_OBJECT_FILE, "Read polymorphic class object", readObjectTest, "input/JOSPolymorphicClass.obj");
    t.addTest(READ_ENUM_OBJECT_FILE, "Read enum object", readObjectTest, "input/JOSEnumClass.obj");

    t.addTest(READ_CUSTOM_UID_OBJECT_FILE, "Read object with custom serialVersionUid", readObjectTest, "input/JOSHasCustomSvUIDClass.obj");
    t.addTest(READ_CLASS_OBJECT_WITH_LONG_FIELD_NAME, "Read class object with long field name", readObjectTest, "input/JOSClassWithLongFieldName.obj");
    t.addTest(READ_TORTURE_CLASS_OBJECT, "Read torture object", readObjectTest, "input/JOSTortureClass.obj");

    // t.addTest(READ_ARRAY_OBJECT_FILE_WITH_EXTRA_DATA, "Read array + extra data input object", [](const tfw::test::util::TestOutputLogger *logger) {
    //     std::ifstream input("input/JOSTestArrayWithExtraData.obj");
    //     input.exceptions(std::ios::badbit | std::ios::eofbit);
    //
    //     if (!input.is_open()) {
    //         throw std::runtime_error("nah");
    //     }
    //
    //     javaobject::stream::ObjectInputStream ois(input);
    //     auto dat = ois.readObject();
    //     auto array = ois.readObject();
    //
    //     return tfw::test::result::TestResult(array->instanceOf<javaobject::type::object::types::ArrayObject>());
    // });

    // TODO: Re-serialize read object in WRITE_MINECRAFT_OBJECT_FILE
    // t.addTest(READ_MINECRAFT_OBJECT_FILE, "Read Minecraft object", [](const tfw::test::util::TestOutputLogger *logger) {
    //     std::ifstream input("input/MinecraftJOSTestClass.obj");
    //     input.exceptions(std::ios::badbit | std::ios::eofbit);
    //
    //     if (!input.is_open()) {
    //         throw std::runtime_error("nah");
    //     }
    //
    //     javaobject::stream::ObjectInputStream ois(input);
    //     auto obj = ois.readObject();
    // });

    t.run();

    return 0;
}
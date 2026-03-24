cmake_minimum_required(VERSION VERSION 3.30)
project(JavaObjectStreams VERSION 1.0.2)

set(CMAKE_CXX_STANDARD 20)

if (NOT TARGET bio)
    include(FetchContent)
    FetchContent_Declare(
            bio
            GIT_REPOSITORY https://codeberg.org/Dexrn/libBIO.git
            GIT_TAG 4.0.0-dev.5
    )

    FetchContent_MakeAvailable(bio)
endif ()

set(FILES
        include/JavaObject/EObjectTypeCode.h
        include/JavaObject/EPrimitiveTypeCode.h
        src/stream/ObjectOutputStream.cpp
        include/JavaObject/stream/ObjectOutputStream.h
        src/stream/ObjectInputStream.cpp
        include/JavaObject/stream/ObjectInputStream.h
        src/io/Serializable.cpp
        include/JavaObject/io/Serializable.h
        include/JavaObject/type/TypeCodeParser.cpp
        include/JavaObject/type/TypeCodeParser.h
        include/JavaObject/type/parser/IObjectParser.cpp
        include/JavaObject/type/parser/IObjectParser.h
        include/JavaObject/type/object/IObject.cpp
        include/JavaObject/type/object/IObject.h
        include/JavaObject/type/object/NullObject.h
        include/JavaObject/type/parser/StringParser.cpp
        include/JavaObject/type/parser/StringParser.h
        include/JavaObject/type/object/StringObject.cpp
        include/JavaObject/type/object/StringObject.h
        include/JavaObject/type/parser/ObjectParser.cpp
        include/JavaObject/type/parser/ObjectParser.h
        include/JavaObject/type/object/Object.cpp
        include/JavaObject/type/object/Object.h
        include/JavaObject/type/parser/descriptor/ClassDescriptorParser.cpp
        include/JavaObject/type/parser/descriptor/ClassDescriptorParser.h
        include/JavaObject/type/object/descriptor/ClassDescriptorObject.cpp
        include/JavaObject/type/object/descriptor/ClassDescriptorObject.h
        include/JavaObject/type/parser/descriptor/ClassDescriptorInfoParser.cpp
        include/JavaObject/type/parser/descriptor/ClassDescriptorInfoParser.h
        include/JavaObject/type/parser/descriptor/FieldDescriptorParser.cpp
        include/JavaObject/type/parser/descriptor/FieldDescriptorParser.h
        include/JavaObject/type/object/descriptor/FieldDescriptorObject.cpp
        include/JavaObject/type/object/descriptor/FieldDescriptorObject.h
        include/JavaObject/type/object/descriptor/PrimitiveDescriptorObject.cpp
        include/JavaObject/type/object/descriptor/PrimitiveDescriptorObject.h
        include/JavaObject/type/parser/descriptor/PrimitiveDescriptorParser.cpp
        include/JavaObject/type/parser/descriptor/PrimitiveDescriptorParser.h
        include/JavaObject/util/SmartPointerCast.cpp
        include/JavaObject/util/SmartPointerCast.h
)

add_library(JavaObjectStreams SHARED ${FILES})
target_include_directories(JavaObjectStreams
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(JavaObjectStreams PUBLIC bio-cpp20)

option(JAVAOBJECTSTREAMS_BUILD_TESTS "Build JavaObjectStreams Tests" ON)

if (JAVAOBJECTSTREAMS_BUILD_TESTS)
    add_subdirectory(tests)
endif()

unset(JAVAOBJECTSTREAMS_BUILD_TESTS CACHE)
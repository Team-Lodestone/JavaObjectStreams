cmake_minimum_required(VERSION VERSION 3.30)
project(JavaObjectStreams VERSION 1.3.2)

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
        src/type/object/parsers/ObjectParser.cpp
        include/JavaObject/type/object/parsers/ObjectParser.h
        src/type/object/types/IObject.cpp
        include/JavaObject/type/object/parsers/IObjectParser.h
        src/type/object/parsers/IObjectParser.cpp
        include/JavaObject/type/object/types/IObject.h
        include/JavaObject/type/object/types/NullObject.h
        src/type/object/parsers/StringParser.cpp
        include/JavaObject/type/object/parsers/StringParser.h
        src/type/object/types/StringObject.cpp
        include/JavaObject/type/object/types/StringObject.h
        src/type/object/types/Object.cpp
        include/JavaObject/type/object/types/Object.h
        src/type/object/parsers/descriptor/NewClassDescriptorParser.cpp
        include/JavaObject/type/object/parsers/descriptor/NewClassDescriptorParser.h
        src/type/object/parsers/descriptor/ClassDescriptorInfoParser.cpp
        include/JavaObject/type/object/parsers/descriptor/ClassDescriptorInfoParser.h
        src/type/object/parsers/descriptor/FieldDescriptorParser.cpp
        include/JavaObject/type/object/parsers/descriptor/FieldDescriptorParser.h
        src/type/object/types/descriptor/PrimitiveDescriptorObject.cpp
        include/JavaObject/type/object/types/descriptor/PrimitiveDescriptorObject.h
        src/type/object/parsers/descriptor/PrimitiveDescriptorParser.cpp
        include/JavaObject/type/object/parsers/descriptor/PrimitiveDescriptorParser.h
        src/util/SmartPointerCast.cpp
        include/JavaObject/util/SmartPointerCast.h
        src/type/object/types/ClassDataObject.cpp
        include/JavaObject/type/object/types/ClassDataObject.h
        src/type/object/types/AnnotationObject.cpp
        include/JavaObject/type/object/types/AnnotationObject.h
        src/type/object/parsers/ClassDataParser.cpp
        include/JavaObject/type/object/parsers/ClassDataParser.h
        src/type/object/types/ReferenceObject.cpp
        include/JavaObject/type/object/types/ReferenceObject.h
        src/type/object/parsers/ReferenceParser.cpp
        include/JavaObject/type/object/parsers/ReferenceParser.h
        src/type/object/types/descriptor/ClassDescriptorInfoObject.cpp
        include/JavaObject/type/object/types/descriptor/ClassDescriptorInfoObject.h
        src/type/object/parsers/NewClassParser.cpp
        include/JavaObject/type/object/parsers/NewClassParser.h
        src/type/primitive/PrimitiveTypeCodeParser.cpp
        include/JavaObject/type/primitive/PrimitiveTypeCodeParser.h
        src/type/primitive/types/IPrimitiveObject.cpp
        include/JavaObject/type/primitive/types/IPrimitiveObject.h
        src/type/HandleContainer.cpp
        include/JavaObject/type/HandleContainer.h
        src/type/ITypeCodeParser.cpp
        include/JavaObject/type/ITypeCodeParser.h
        src/type/primitive/parsers/IPrimitiveObjectParser.cpp
        include/JavaObject/type/primitive/parsers/IPrimitiveObjectParser.h
        src/type/primitive/types/PrimitiveByteObject.cpp
        include/JavaObject/type/primitive/types/PrimitiveByteObject.h
        src/type/primitive/types/PrimitiveCharObject.cpp
        include/JavaObject/type/primitive/types/PrimitiveCharObject.h
        src/type/primitive/types/PrimitiveDoubleObject.cpp
        include/JavaObject/type/primitive/types/PrimitiveDoubleObject.h
        src/type/primitive/types/PrimitiveFloatObject.cpp
        include/JavaObject/type/primitive/types/PrimitiveFloatObject.h
        src/type/primitive/types/PrimitiveIntegerObject.cpp
        include/JavaObject/type/primitive/types/PrimitiveIntegerObject.h
        src/type/primitive/types/PrimitiveLongObject.cpp
        include/JavaObject/type/primitive/types/PrimitiveLongObject.h
        src/type/primitive/types/PrimitiveShortObject.cpp
        include/JavaObject/type/primitive/types/PrimitiveShortObject.h
        src/type/primitive/types/PrimitiveBooleanObject.cpp
        include/JavaObject/type/primitive/types/PrimitiveBooleanObject.h
        src/type/primitive/types/PrimitiveJavaObject.cpp
        include/JavaObject/type/primitive/types/PrimitiveJavaObject.h
        src/type/primitive/types/PrimitiveArrayObject.cpp
        include/JavaObject/type/primitive/types/PrimitiveArrayObject.h
        src/type/primitive/parsers/PrimitiveByteObjectParser.cpp
        include/JavaObject/type/primitive/parsers/PrimitiveByteObjectParser.h
        src/type/primitive/parsers/PrimitiveCharObjectParser.cpp
        include/JavaObject/type/primitive/parsers/PrimitiveCharObjectParser.h
        src/type/primitive/parsers/PrimitiveDoubleObjectParser.cpp
        include/JavaObject/type/primitive/parsers/PrimitiveDoubleObjectParser.h
        src/type/primitive/parsers/PrimitiveFloatObjectParser.cpp
        include/JavaObject/type/primitive/parsers/PrimitiveFloatObjectParser.h
        src/type/primitive/parsers/PrimitiveIntegerObjectParser.cpp
        include/JavaObject/type/primitive/parsers/PrimitiveIntegerObjectParser.h
        src/type/primitive/parsers/PrimitiveShortObjectParser.cpp
        include/JavaObject/type/primitive/parsers/PrimitiveShortObjectParser.h
        src/type/primitive/parsers/PrimitiveLongObjectParser.cpp
        include/JavaObject/type/primitive/parsers/PrimitiveLongObjectParser.h
        src/type/primitive/parsers/PrimitiveBooleanObjectParser.cpp
        include/JavaObject/type/primitive/parsers/PrimitiveBooleanObjectParser.h
        include/JavaObject/type/object/ObjectTypeCodeParser.h
        src/type/object/ObjectTypeCodeParser.cpp
        src/type/TypeCodeParserStorage.cpp
        include/JavaObject/type/TypeCodeParserStorage.h
        src/type/ITypeCodeStorageHolder.cpp
        include/JavaObject/type/ITypeCodeStorageHolder.h
        src/type/primitive/parsers/PrimitiveJavaObjectParser.cpp
        include/JavaObject/type/primitive/parsers/PrimitiveJavaObjectParser.h
        src/type/primitive/parsers/PrimitiveArrayObjectParser.cpp
        include/JavaObject/type/primitive/parsers/PrimitiveArrayObjectParser.h
        src/type/object/types/EndBlockDataObject.cpp
        include/JavaObject/type/object/types/EndBlockDataObject.h
        src/type/object/parsers/EndBlockDataObjectParser.cpp
        include/JavaObject/type/object/parsers/EndBlockDataObjectParser.h
        src/type/object/types/BlockDataObject.cpp
        include/JavaObject/type/object/types/BlockDataObject.h
        src/type/object/parsers/ShortBlockDataObjectParser.cpp
        include/JavaObject/type/object/parsers/ShortBlockDataObjectParser.h
        src/type/object/parsers/LongBlockDataObjectParser.cpp
        include/JavaObject/type/object/parsers/LongBlockDataObjectParser.h
        src/type/object/types/descriptor/NewClassDescriptorObject.cpp
        src/type/object/types/descriptor/FieldDescriptorObject.cpp
        src/type/object/types/NullObject.cpp
        src/type/object/parsers/NullObjectParser.cpp
        include/JavaObject/type/object/parsers/NullObjectParser.h
        src/type/object/types/ArrayObject.cpp
        include/JavaObject/type/object/types/ArrayObject.h
        include/JavaObject/type/object/types/descriptor/NewClassDescriptorObject.h
        src/type/object/parsers/ArrayObjectParser.cpp
        include/JavaObject/type/object/parsers/ArrayObjectParser.h
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

option(JAVAOBJECTSTREAMS_DOCS_TARGET "Create documentation target" ON)

if (JAVAOBJECTSTREAMS_DOCS_TARGET STREQUAL "ON")
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/doxygen.cmake")
endif ()

unset(JAVAOBJECTSTREAMS_DOCS_TARGET CACHE)
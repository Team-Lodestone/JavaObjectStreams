cmake_minimum_required(VERSION VERSION 3.30)
project(JavaObjectStreams VERSION 1.0.0)

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
        include/JavaObject/JavaSerializedClassParser.h
        src/JavaSerializedClassParser.cpp
)

add_library(JavaObjectStreams SHARED ${FILES})
target_include_directories(JavaObjectStreams
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(JavaObjectStreams PUBLIC bio-cpp20)
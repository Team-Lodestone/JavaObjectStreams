cmake_minimum_required(VERSION VERSION 3.30)
project(JavaObjectStreams.Tests.CPP)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(FILES
        src/JavaObjectStreamsTests.cpp
)

include(FetchContent)
if (NOT TARGET tfw)
    FetchContent_Declare(
            tfw
            GIT_REPOSITORY https://codeberg.org/Dexrn/tfw.git
            GIT_TAG 1.0.3
            GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(tfw)
endif()

add_executable(JavaObjectStreams.Tests.CPP ${FILES})

target_include_directories(JavaObjectStreams.Tests.CPP
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(JavaObjectStreams.Tests.CPP PRIVATE JavaObjectStreams tfw)

# ENABLE INDIVIDUAL TESTS HERE
target_compile_definitions(JavaObjectStreams.Tests.CPP PRIVATE
        READ_OBJECT_FILE=true
)
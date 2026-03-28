cmake_minimum_required(VERSION VERSION 3.30)
project(JavaObjectStreams.Utils.JavaObjectDump)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(FILES
        src/main.cpp
)

add_executable(JavaObjectStreams.Utils.JavaObjectDump ${FILES})

target_include_directories(JavaObjectStreams.Utils.JavaObjectDump
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(JavaObjectStreams.Utils.JavaObjectDump PRIVATE JavaObjectStreams)
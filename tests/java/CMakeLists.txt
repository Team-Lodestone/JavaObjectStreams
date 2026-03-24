cmake_minimum_required(VERSION VERSION 3.30)
project(JavaObjectStreams.Tests.Java)

add_custom_target("JavaOutputStreams.Tests.Java" ALL
        COMMAND ./gradlew :jar -PjarDir="${CMAKE_CURRENT_BINARY_DIR}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target("JavaOutputStreams.Tests.Java.Input" ALL
        COMMAND java -cp "JavaOutputStreams.Tests.Java.Input:JavaOutputStreams.Tests.Java.Common.jar" me.dexrn.jos.input.InputTests "${CMAKE_CURRENT_SOURCE_DIR}/../cpp/output"
        DEPENDS JavaOutputStreams.Tests.Java
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)

add_custom_target("JavaOutputStreams.Tests.Java.Output" ALL
        COMMAND java -cp "JavaOutputStreams.Tests.Java.Output.jar:JavaOutputStreams.Tests.Java.Common.jar" me.dexrn.jos.output.OutputTestFile "${CMAKE_CURRENT_SOURCE_DIR}/../cpp/input"
        DEPENDS JavaOutputStreams.Tests.Java
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)
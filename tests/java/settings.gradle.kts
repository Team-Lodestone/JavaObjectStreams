rootProject.name = "JavaOutputStreams.Tests.Java"
include("Common", "Input", "Output")

project(":Common").projectDir = file("modules/Common")
project(":Input").projectDir = file("modules/Input")
project(":Output").projectDir = file("modules/Output")

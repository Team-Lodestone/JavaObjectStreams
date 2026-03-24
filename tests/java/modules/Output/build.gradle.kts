plugins {
	id("application")
}

application {
	mainClass = "me.dexrn.jos.output.OutputTestFile"
}

tasks.jar {
	manifest {
		attributes("Main-Class" to "me.dexrn.jos.output.OutputTestFile")
	}
}

dependencies {
	implementation(project(":Common"))
}
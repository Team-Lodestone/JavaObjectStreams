import sun.tools.jar.resources.jar

plugins {
	id("application")
}

application {
	mainClass = "me.dexrn.jos.input.InputTests"
}

tasks.jar {
	manifest {
		attributes("Main-Class" to "me.dexrn.jos.input.InputTests")
	}
}

dependencies {
	implementation(project(":Common"))
}
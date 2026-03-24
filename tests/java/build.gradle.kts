import kotlin.collections.map

plugins {
	id("java")
}

subprojects {
	tasks.withType<Jar>() {
		archiveFileName.set("${rootProject.name}.${project.name}.jar")
	}
}

allprojects {
	group = "io.github.team-lodestone"
	version = "1.0-SNAPSHOT"

	repositories {
		mavenCentral();
	}
}

val f = file(if (project.hasProperty("jarDir")) (project.findProperty("jarDir") as String) else layout.buildDirectory.dir("libs"));

val copy = tasks.register<Copy>("copyJars") {
	into(f)
	
	subprojects.forEach { p ->
		val t = p.tasks.findByName("jar")
		if (t != null) {
			from(t)
		}
	}
}

tasks.named("jar").configure {
	dependsOn(copy)
}

package me.dexrn.jos.common.test;

import java.io.Serializable;

public class JOSSubclassedClass implements Serializable {
	@SuppressWarnings("InnerClassMayBeStatic")
	public class Subclass implements Serializable {
		String info = "I am a subclass of " + JOSSubclassedClass.class.getName();
	}
	
	public static class StaticSubclass implements Serializable {
		String info = "I am a static subclass of " + JOSSubclassedClass.class.getName();
	}
	
	Subclass subclass = new Subclass();
	StaticSubclass staticSubclass = new StaticSubclass();
}

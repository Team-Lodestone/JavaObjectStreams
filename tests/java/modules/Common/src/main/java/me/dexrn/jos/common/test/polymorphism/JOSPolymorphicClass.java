package me.dexrn.jos.common.test.polymorphism;

import java.io.Serializable;

public class JOSPolymorphicClass extends JOSPolymorphicBase implements Serializable {
	String derivedInfo = "Hello from " + JOSPolymorphicClass.class.getName();
}

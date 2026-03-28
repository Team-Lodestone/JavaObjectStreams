package me.dexrn.jos.common.test.polymorphism;

import java.io.Serializable;

public abstract class JOSPolymorphicBase implements Serializable {
	String baseInfo = "Hello from " + JOSPolymorphicBase.class.getName();
}

package me.dexrn.jos.common.test;

import java.io.Serializable;

public enum JOSEnumClass implements Serializable {
	FIRST("First value"),
	SECOND("Second value"),
	THIRD("Third value"),
	FOURTH("Fourth value"),
	FIFTH("Fifth value"),
	INFO("Enum test class");
	
	final String info;
	
	JOSEnumClass(String info) {
		this.info = info;
	}
}

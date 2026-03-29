package me.dexrn.jos.output.outputs;

import me.dexrn.jos.common.test.JOSEnumClass;
import me.dexrn.jos.output.AbstractObjectOutput;

import java.io.Serializable;

public class EnumClassOutput extends AbstractObjectOutput<JOSEnumClass> {
	public EnumClassOutput() {
		super(JOSEnumClass.class);
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public JOSEnumClass construct() {
		return JOSEnumClass.INFO;
	}
}

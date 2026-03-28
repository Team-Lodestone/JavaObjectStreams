package me.dexrn.jos.output.outputs;

import me.dexrn.jos.common.test.JOSArrayClass;
import me.dexrn.jos.output.AbstractObjectOutput;

public class ArrayClassOutput extends AbstractObjectOutput<JOSArrayClass> {
	public ArrayClassOutput() {
		super(JOSArrayClass.class);
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public JOSArrayClass construct() {
		return new JOSArrayClass();
	}
}

package me.dexrn.jos.output.outputs.array;

import me.dexrn.jos.common.test.array.JOSArrayClass;
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

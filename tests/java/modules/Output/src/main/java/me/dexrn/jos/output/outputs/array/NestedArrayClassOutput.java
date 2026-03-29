package me.dexrn.jos.output.outputs.array;

import me.dexrn.jos.common.test.array.JOSNestedArrayClass;
import me.dexrn.jos.output.AbstractObjectOutput;

public class NestedArrayClassOutput extends AbstractObjectOutput<JOSNestedArrayClass> {
	public NestedArrayClassOutput() {
		super(JOSNestedArrayClass.class);
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public JOSNestedArrayClass construct() {
		return new JOSNestedArrayClass();
	}
}

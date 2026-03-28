package me.dexrn.jos.output.outputs;

import me.dexrn.jos.common.test.JOSSubclassedClass;
import me.dexrn.jos.output.AbstractObjectOutput;

public class SubclassedClassOutput extends AbstractObjectOutput<JOSSubclassedClass> {
	public SubclassedClassOutput() {
		super(JOSSubclassedClass.class);
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public JOSSubclassedClass construct() {
		return new JOSSubclassedClass();
	}
}

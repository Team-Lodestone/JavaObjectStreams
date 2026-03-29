package me.dexrn.jos.output.outputs.polymorphism;

import me.dexrn.jos.common.test.polymorphism.JOSPolymorphicClass;
import me.dexrn.jos.output.AbstractObjectOutput;

public class PolymorphicClassOutput extends AbstractObjectOutput<JOSPolymorphicClass> {
	public PolymorphicClassOutput() {
		super(JOSPolymorphicClass.class);
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public JOSPolymorphicClass construct() {
		return new JOSPolymorphicClass();
	}
}

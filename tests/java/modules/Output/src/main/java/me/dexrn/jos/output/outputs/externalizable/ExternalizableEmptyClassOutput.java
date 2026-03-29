package me.dexrn.jos.output.outputs.externalizable;

import me.dexrn.jos.common.test.externalizable.JOSEmptyExternalizableClass;
import me.dexrn.jos.output.AbstractObjectOutput;

import java.io.Serializable;

public class ExternalizableEmptyClassOutput extends AbstractObjectOutput<JOSEmptyExternalizableClass> {
	public ExternalizableEmptyClassOutput() {
		super(JOSEmptyExternalizableClass.class);
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public JOSEmptyExternalizableClass construct() {
		return new JOSEmptyExternalizableClass();
	}
}

package me.dexrn.jos.output.outputs.externalizable;

import me.dexrn.jos.common.test.externalizable.JOSExternalizableClass;
import me.dexrn.jos.output.AbstractObjectOutput;

public class ExternalizableClassOutput extends AbstractObjectOutput<JOSExternalizableClass> {
	public ExternalizableClassOutput() {
		super(JOSExternalizableClass.class);
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public JOSExternalizableClass construct() {
		return new JOSExternalizableClass();
	}
}

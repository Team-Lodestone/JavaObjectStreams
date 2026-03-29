package me.dexrn.jos.output.outputs.externalizable;

import me.dexrn.jos.common.test.externalizable.JOSExternalizableWithExtraDataClass;
import me.dexrn.jos.output.AbstractObjectOutput;

public class ExternalizableWithExtraDataObjectOutput extends AbstractObjectOutput<JOSExternalizableWithExtraDataClass> {
	public ExternalizableWithExtraDataObjectOutput() {
		super(JOSExternalizableWithExtraDataClass.class);
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public JOSExternalizableWithExtraDataClass construct() {
		return new JOSExternalizableWithExtraDataClass();
	}
}

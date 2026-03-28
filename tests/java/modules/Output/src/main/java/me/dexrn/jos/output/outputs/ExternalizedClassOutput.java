package me.dexrn.jos.output.outputs;

import me.dexrn.jos.common.test.externalizable.JOSExternalizableDataClass;
import me.dexrn.jos.output.AbstractObjectOutput;

import java.io.Serializable;

public class ExternalizedClassOutput extends AbstractObjectOutput<JOSExternalizableDataClass> {
	public ExternalizedClassOutput() {
		super(JOSExternalizableDataClass.class);
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public JOSExternalizableDataClass construct() {
		return new JOSExternalizableDataClass();
	}
}

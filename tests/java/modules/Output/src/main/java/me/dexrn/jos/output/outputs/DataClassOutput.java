package me.dexrn.jos.output.outputs;

import me.dexrn.jos.common.test.JOSDataClass;
import me.dexrn.jos.output.AbstractObjectOutput;

public class DataClassOutput extends AbstractObjectOutput<JOSDataClass> {
	public DataClassOutput() {
		super(JOSDataClass.class);
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public JOSDataClass construct() {
		return new JOSDataClass();
	}
}

package me.dexrn.jos.output.outputs.extra;

import me.dexrn.jos.common.test.extra.JOSHasCustomSvUIDClass;
import me.dexrn.jos.output.AbstractObjectOutput;

public class CustomSvUIDClassOutput extends AbstractObjectOutput<JOSHasCustomSvUIDClass> {
	public CustomSvUIDClassOutput() {
		super(JOSHasCustomSvUIDClass.class);
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public JOSHasCustomSvUIDClass construct() {
		return new JOSHasCustomSvUIDClass();
	}
}

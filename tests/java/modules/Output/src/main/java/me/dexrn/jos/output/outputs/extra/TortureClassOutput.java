package me.dexrn.jos.output.outputs.extra;

import me.dexrn.jos.common.test.extra.JOSTortureClass;
import me.dexrn.jos.output.AbstractObjectOutput;

public class TortureClassOutput extends AbstractObjectOutput<JOSTortureClass> {
	public TortureClassOutput() {
		super(JOSTortureClass.class);
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public JOSTortureClass construct() {
		return new JOSTortureClass();
	}
}

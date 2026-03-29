package me.dexrn.jos.output.outputs.extra;

import me.dexrn.jos.common.test.extra.JOSClassWithLongFieldName;
import me.dexrn.jos.output.AbstractObjectOutput;

public class LongFieldNameClassOutput extends AbstractObjectOutput<JOSClassWithLongFieldName> {
	public LongFieldNameClassOutput() {
		super(JOSClassWithLongFieldName.class);
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public JOSClassWithLongFieldName construct() {
		return new JOSClassWithLongFieldName();
	}
}

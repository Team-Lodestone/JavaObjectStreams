package me.dexrn.jos.output.outputs;

import me.dexrn.jos.output.AbstractObjectOutput;

import java.io.Serializable;

public class NullObjectOutput extends AbstractObjectOutput<Serializable> {
	public NullObjectOutput() {
		super(Serializable.class);
	}

	@Override
	public String getFilename() {
		return "JOSNullObject.obj";
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public Serializable construct() {
		return null;
	}
}

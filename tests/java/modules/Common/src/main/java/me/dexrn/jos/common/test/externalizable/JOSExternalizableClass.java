package me.dexrn.jos.common.test.externalizable;

import me.dexrn.jos.common.test.JOSDataClass;

import java.io.Externalizable;
import java.io.IOException;
import java.io.ObjectInput;
import java.io.ObjectOutput;

public class JOSExternalizableClass implements Externalizable {
	String chars = "Hello, externalizable world!";

	@Override
	public void writeExternal(ObjectOutput objectOutput) throws IOException {
		objectOutput.writeObject(chars);
	}

	@Override
	public void readExternal(ObjectInput objectInput) throws IOException, ClassNotFoundException {
		this.chars = (String) objectInput.readObject();
	}
}

package me.dexrn.jos.common.test.externalizable;

import me.dexrn.jos.common.test.JOSDataClass;

import java.io.Externalizable;
import java.io.IOException;
import java.io.ObjectInput;
import java.io.ObjectOutput;
import java.util.List;

public class JOSExternalizableWithExtraDataClass implements Externalizable {
	JOSDataClass dataClass = new JOSDataClass();
	String chars = "Hello, externalizable (with BlockData) world!";
	
	@Override
	public void writeExternal(ObjectOutput objectOutput) throws IOException {
		objectOutput.writeChars(chars);

		objectOutput.writeBoolean(dataClass.b);
		objectOutput.writeChar(dataClass.ch);
		objectOutput.writeByte(dataClass.bt);
		objectOutput.writeShort(dataClass.s);
		objectOutput.writeInt(dataClass.i);
		objectOutput.writeLong(dataClass.l);
		objectOutput.writeFloat(dataClass.f);
		objectOutput.writeDouble(dataClass.d);
		objectOutput.writeUTF(dataClass.str);
		objectOutput.writeObject(dataClass.chars);
	}

	@Override
	public void readExternal(ObjectInput objectInput) throws IOException, ClassNotFoundException {
		StringBuilder ch = new StringBuilder();
		for (int i = 0; i < chars.length(); i++) {
			ch.append(objectInput.readChar());
		}
		
		this.chars = ch.toString();
		
		dataClass.b = objectInput.readBoolean();
		dataClass.ch = objectInput.readChar();
		dataClass.bt = objectInput.readByte();
		dataClass.s = objectInput.readShort();
		dataClass.i = objectInput.readInt();
		dataClass.l = objectInput.readLong();
		dataClass.f = objectInput.readFloat();
		dataClass.d = objectInput.readDouble();
		dataClass.str = objectInput.readUTF();
		dataClass.chars = (List<Character>)objectInput.readObject();
	}
}

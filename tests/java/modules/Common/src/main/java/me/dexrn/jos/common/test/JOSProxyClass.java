package me.dexrn.jos.common.test;

import java.io.InvalidObjectException;
import java.io.ObjectInputStream;
import java.io.Serial;
import java.io.Serializable;

public class JOSProxyClass implements Serializable {
	private int myFunnyInt = 69420;

	@Serial
	private void readObject(ObjectInputStream stream) throws InvalidObjectException {
		throw new InvalidObjectException("Proxy required.");
	}


	@Serial
	private Object writeReplace() {
		return new SerializationProxy(this);
	}

	public static class SerializationProxy implements Serializable {
		@Serial
		private static final long serialVersionUID = 0L;

		private final int myProxiedFunnyInt;

		public SerializationProxy(JOSProxyClass josProxyClass) {
			this.myProxiedFunnyInt = josProxyClass.myFunnyInt;
		}


		@Serial
		private Object readResolve() {
			JOSProxyClass jos = new JOSProxyClass();
			jos.myFunnyInt = this.myProxiedFunnyInt;
			return jos;
		}
	}
}

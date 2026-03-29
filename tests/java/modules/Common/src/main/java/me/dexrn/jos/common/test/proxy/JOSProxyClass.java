package me.dexrn.jos.common.test.proxy;

import java.io.Serializable;
import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;

public class JOSProxyClass implements Serializable, InvocationHandler {
	private final Object obj;

	public JOSProxyClass(Object obj) {
		this.obj = obj;
	}
	
	@Override
	public Object invoke(Object o, Method method, Object[] objects) throws Throwable {
		return null;
	}
}

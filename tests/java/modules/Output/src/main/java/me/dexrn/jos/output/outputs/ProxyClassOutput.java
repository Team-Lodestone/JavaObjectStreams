package me.dexrn.jos.output.outputs;

import me.dexrn.jos.common.test.JOSDataClass;
import me.dexrn.jos.common.test.proxy.JOSProxyClass;
import me.dexrn.jos.common.test.proxy.JOSServiceImplementation;
import me.dexrn.jos.common.test.proxy.JOSServiceInterface;
import me.dexrn.jos.output.AbstractObjectOutput;

import java.lang.reflect.Proxy;

public class ProxyClassOutput extends AbstractObjectOutput<JOSServiceInterface> {
	public ProxyClassOutput() {
		super(JOSServiceInterface.class);
	}

	@Override
	public String getFilename() {
		return "JOSProxyClass.obj";
	}

	/**
	 * Constructs the object to be outputted into the stream
	 */
	@Override
	public JOSServiceInterface construct() {
		JOSServiceImplementation impl = new JOSServiceImplementation();
		
		return (JOSServiceInterface) Proxy.newProxyInstance(
			JOSServiceInterface.class.getClassLoader(),
			new Class[] { JOSServiceInterface.class },
			new JOSProxyClass(impl)
		);
	}
}

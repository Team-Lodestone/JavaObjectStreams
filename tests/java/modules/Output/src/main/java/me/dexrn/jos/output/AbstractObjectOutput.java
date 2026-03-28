package me.dexrn.jos.output;

import me.dexrn.jos.common.util.LoggerHandler;

import java.io.Serializable;
import java.util.logging.*;

public abstract class AbstractObjectOutput<T extends Serializable> {
	private final Class<T> type;
	
	public AbstractObjectOutput(Class<T> t) {
		type = t;
	}
	
	/** Constructs the object to be outputted into the stream */
	public abstract T construct();
	
	/** Returns the filename that should be used for the stream output file */
	public String getFilename() {
		return type.getSimpleName() + ".obj";
	}

	public final Logger getLogger() {
		Logger l = Logger.getLogger(this.getFilename());
		l.setUseParentHandlers(false);
		l.addHandler(new LoggerHandler());
		
		return l;
	}
}

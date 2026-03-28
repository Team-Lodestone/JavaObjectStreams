package me.dexrn.jos.common.util;

import java.time.ZoneId;
import java.time.format.DateTimeFormatter;
import java.util.logging.*;

public class LoggerHandler extends StreamHandler {
	private final ConsoleHandler stderr = new ConsoleHandler();
	
	public LoggerHandler() {
		super(System.out, new Formatter() {
			@Override
			public String format(LogRecord logRecord) {
				return String.format("%s [%s | %s] %s\n", DateTimeFormatter.ofPattern("HH:mm:ss").withZone(ZoneId.systemDefault()).format(logRecord.getInstant()), logRecord.getLevel(), logRecord.getLoggerName(), logRecord.getMessage());
			}
		});
	}

	@Override
	public synchronized void publish(LogRecord record) {
		if (record.getLevel().intValue() >= Level.WARNING.intValue()) {
			//stderr
			stderr.publish(record);
			stderr.flush();
			
			return;
		}
		
		//stdout
		super.publish(record);
		super.flush();
	}
}

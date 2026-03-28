package me.dexrn.jos.common.test;

import java.io.Serializable;
import java.util.stream.Stream;

public class JOSNestedArrayClass implements Serializable {
	byte[][][] bytes = new byte[9][9][9];
	int[][][] ints = new int[9][9][9];
	long[][][] longs = new long[9][9][9];
	float[][][] floats = new float[9][9][9];
	double[][][] doubles = new double[9][9][9];

	JOSDataClass[][][] classes = Stream.generate(() ->
		Stream.generate(
			() -> Stream.generate(JOSDataClass::new).limit(9).toArray(JOSDataClass[]::new)
		).limit(9).toArray(JOSDataClass[][]::new)
	).limit(9).toArray(JOSDataClass[][][]::new);
}

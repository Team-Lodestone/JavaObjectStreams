package me.dexrn.jos.common.test.array;

import me.dexrn.jos.common.test.JOSDataClass;

import java.io.Serializable;
import java.util.stream.IntStream;
import java.util.stream.LongStream;
import java.util.stream.Stream;

public class JOSArrayClass implements Serializable {
	byte[] bytes = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int[] ints = IntStream.range(0, 9).toArray();
	long[] longs = LongStream.range(0, 9).toArray();
	float[] floats = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double[] doubles = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	JOSDataClass[] classes = Stream.generate(JOSDataClass::new).limit(10).toArray(JOSDataClass[]::new);
}

package me.dexrn.jos.common.test;

import java.io.Serializable;

public class JOSNestedArrayClass implements Serializable {
	byte[][][] bytes = new byte[9][9][9];
	int[][][] ints = new int[9][9][9];
	long[][][] longs = new long[9][9][9];
	float[][][] floats = new float[9][9][9];
	double[][][] doubles = new double[9][9][9];
}

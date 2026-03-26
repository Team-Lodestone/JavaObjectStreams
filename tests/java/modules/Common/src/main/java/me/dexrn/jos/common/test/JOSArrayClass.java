package me.dexrn.jos.common.test;

import java.io.Serializable;

public class JOSArrayClass implements Serializable {
	public class Subclass implements Serializable {
		int i = 0;
	}
	
	byte[] bytes = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int[] ints = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	long[] longs = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	float[] floats = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double[] doubles = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Subclass[] sc = { new Subclass(), new Subclass(), new Subclass() };
}

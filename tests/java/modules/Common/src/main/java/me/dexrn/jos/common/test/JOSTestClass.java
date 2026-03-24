/** @file JOSTestClass.java
 *
 * @author DexrnZacAttack
 * @date 3/23/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
package me.dexrn.jos.common.test;

import java.io.Serializable;

public class JOSTestClass implements Serializable {
    public int funnyInt = 69420;
    // public int[] ints = new int[] {1, 2, 3, 4, 5};
//     public Integer[] integers = new Integer[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     public long[] integers = new long[]{4, 6, 8, 12, 14};
    public class Subclass implements Serializable {
        public int notSoFunnyInt = 69421;
    }
    public Subclass[] subclasses = new Subclass[] {new Subclass()};
//     public int[] inttts = new int[] {6, 7, 8, 9, 10};
//     public int notSoFunnyInt = 69;
// 	public class Subclass implements Serializable {
// 		boolean b = true;
// 		char c = 'b';
// 		byte bt = 7;
// 		short s = 8;
// 		int i = 9;
// 		long l = 10;
// 		float f = 11.0f;
// 		double d = 12.0;
// 	}
//
// 	Subclass sc = new Subclass();
// 	JOSDataClass dc = new JOSDataClass();
//
// 	boolean b = false;
// 	char c = 'a';
// 	byte bt = 1;
// 	short s = 2;
// 	int i = 3;
// 	long l = 4;
// 	float f = 5.0f;
// 	double d = 6.0;
}

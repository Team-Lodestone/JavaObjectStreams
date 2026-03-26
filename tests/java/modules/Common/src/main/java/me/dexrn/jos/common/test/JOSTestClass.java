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
import java.util.ArrayList;
import java.util.List;

public class JOSTestClass implements Serializable {
	public class Subclass implements Serializable {
		boolean b = true;
		char c = 'b';
		byte bt = 7;
		short s = 8;
		int i = 9;
		long l = 10;
		float f = 11.0f;
		double d = 12.0;
	}
	
	Subclass sc = new Subclass();
	JOSDataClass dc = new JOSDataClass();
	JOSArrayClass ac = new JOSArrayClass();
	JOSNestedArrayClass nac = new JOSNestedArrayClass();

	boolean b = false;
	char c = 'a';
	byte bt = 1;
	short s = 2;
	int i = 3;
	long l = 4;
	float f = 5.0f;
	double d = 6.0;
	String str = "Hello, world!";
	
	List<Character> carr = new ArrayList<Character>();
	{
		str.chars().forEach(c -> carr.add((char) c));
	}
}

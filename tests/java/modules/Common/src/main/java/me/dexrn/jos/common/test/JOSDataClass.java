/** @file JOSDataClass.java
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
import java.util.List;

public class JOSDataClass implements Serializable {
	public boolean b = false;
	public char ch = 'a';
	public byte bt = 1;
	public short s = 2;
	public int i = 3;
	public long l = 4;
	public float f = 5.0f;
	public double d = 6.0;
	public String str = "Hello, world!";
	public List<Character> chars = List.of(
		'H','e','l','l','o',',', ' ',
		'J','a','v','a','.','l','a','n','g','.','C','h','a','r','a','c','t','e','r', ' ',
		'w','o','r','l','d','!'
	);
}

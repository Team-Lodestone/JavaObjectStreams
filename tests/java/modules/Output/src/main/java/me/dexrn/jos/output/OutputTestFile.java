/** @file OutputTestFile.java
 *
 * @author DexrnZacAttack
 * @date 3/23/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
package me.dexrn.jos.output;

import me.dexrn.jos.common.test.JOSTestClass;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.nio.file.Path;

public class OutputTestFile {
	public static void main(String[] args) throws IOException {
		String dir = "";
		if (args.length != 0) {
			dir = args[0];
		}
		
		writeClass(dir);
		writeArray(dir);
		writeNull(dir);
		writeCustom(dir);
	}
	
	private static void writeClass(String dir) throws IOException {
		FileOutputStream fos = new FileOutputStream(Path.of(dir, "JOSTestClass.obj").toFile());
		ObjectOutputStream oos = new ObjectOutputStream(fos);

		oos.writeObject(new JOSTestClass());
	}
	
	private static void writeArray(String dir) throws IOException {
		int[] arr = new int[512];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = i;
		}
		
		FileOutputStream fos = new FileOutputStream(Path.of(dir, "JOSTestArray.obj").toFile());
		ObjectOutputStream oos = new ObjectOutputStream(fos);
		
		oos.writeObject(arr);
	}
	
	private static void writeNull(String dir) throws IOException {
		FileOutputStream fos = new FileOutputStream(Path.of(dir, "JOSTestNull.obj").toFile());
		ObjectOutputStream oos = new ObjectOutputStream(fos);

		oos.writeObject(null);
	}
	
	private static void writeCustom(String dir) throws IOException {
		int[] arr = new int[512];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = i;
		}

		FileOutputStream fos = new FileOutputStream(Path.of(dir, "JOSTestArrayWithExtraData.obj").toFile());
		ObjectOutputStream oos = new ObjectOutputStream(fos);

		oos.writeUTF("Hello, world!");
		oos.writeInt(0x12345678);
		oos.writeObject(arr);
	}
}
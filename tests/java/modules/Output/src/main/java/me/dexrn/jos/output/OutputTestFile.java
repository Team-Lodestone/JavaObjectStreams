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
import java.io.ObjectOutputStream;
import java.nio.file.Path;

public class OutputTestFile {
	public static void main(String[] args) throws IOException {
		String dir = "";
		if (args.length != 0) {
			dir = args[0];
		}
		
		FileOutputStream fos = new FileOutputStream(Path.of(dir, "JOSTestClass.obj").toFile());
		ObjectOutputStream oos = new ObjectOutputStream(fos);
		
		oos.writeObject(new JOSTestClass());
	}
}
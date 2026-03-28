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

import me.dexrn.jos.output.outputs.*;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Logger;

public class OutputTestFile {
	private final List<AbstractObjectOutput<?>> outputs = new ArrayList<>();
	private final String parentDir;
	
	private OutputTestFile(String parentDir) {
		this.parentDir = parentDir;
		
		outputs.add(new DataClassOutput());
		outputs.add(new SubclassedClassOutput());
		
		outputs.add(new ArrayClassOutput());
		outputs.add(new NestedArrayClassOutput());

		outputs.add(new PolymorphicClassOutput());
		outputs.add(new ExternalizedClassOutput());
		
		outputs.add(new CustomSvUIDClassOutput());
		outputs.add(new LongFieldNameClassOutput());
	}
	
	public static void main(String[] args) throws IOException {
		String dir = "";
		if (args.length != 0) {
			dir = args[0];
		}
		
		new OutputTestFile(dir).run();
	}
	
	private void run() {
		outputs.forEach(outputter -> {
			Logger l = outputter.getLogger();
			
			try {
				FileOutputStream fos = new FileOutputStream(Path.of(this.parentDir, outputter.getFilename()).toFile());
				ObjectOutputStream oos = new ObjectOutputStream(fos);

				oos.writeObject(outputter.construct());

				l.info("Done!");
			} catch (Exception ex) {
				l.severe("Failed!");
				ex.printStackTrace(); //shut up!!!!!
			}
		});
	}
}
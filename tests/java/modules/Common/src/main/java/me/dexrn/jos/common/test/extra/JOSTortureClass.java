package me.dexrn.jos.common.test.extra;

import me.dexrn.jos.common.test.polymorphism.JOSPolymorphicClass;

import java.io.Serializable;
import java.util.List;
import java.util.Map;

/** Contains fields designed to stress out the parser */
public class JOSTortureClass implements Serializable {
	Map<List<JOSPolymorphicClass>, Map<String, Map<List<String>, String[]>>> shitfuck = Map.of(
		List.of(
			new JOSPolymorphicClass(),
			new JOSPolymorphicClass(),
			new JOSPolymorphicClass()
		),
		Map.of(
			"fraud tomorrow",
			Map.of(
				List.of(
					"Ahh...",
					"Free at last",
					"O Gabriel",
					"Now dawns thy reckoning",
					"And thy gore shall glisten before the temples of man",
					"Creature of steel...",
					"My gratitude upon thee for my freedom",
					"but the crimes thy kind have committed against humanity",
					"are NOT forgotten",
					"and thy punishment...",
					"is DEATH"
				),
				new String[]{
					"Prepare thyself!",
					"Crush!",
					"Die!"
				}
			)
		)
	); // the shitfuck I
}

# JavaObjectStreams

[![GitHub tag](https://img.shields.io/github/tag/Team-Lodestone/JavaObjectStreams?include_prereleases=&sort=semver&color=blue)](https://github.com/Team-Lodestone/JavaObjectStreams/releases/)
[![License](https://img.shields.io/badge/License-MIT-blue)](#license)

[![Read the docs](https://cdn.jsdelivr.net/npm/@intergrav/devins-badges@3/assets/compact-minimal/documentation/ghpages_vector.svg)](https://team-lodestone.github.io/JavaObjectStreams/ "Go to project documentation")

A C++ library to provide serialization and deserialization of Java objects (ala ObjectInputStream and ObjectOutputStream).

### JavaObjectStreams is not...
- a Java class file parser.
- a Java disassembler.

---

|                     | [V2](https://docs.oracle.com/javase/9/docs/specs/serialization/protocol.html#stream-protocol-versions) | [V1](https://docs.oracle.com/javase/9/docs/specs/serialization/protocol.html#stream-protocol-versions) |
|:-------------------:|:------------------------------------------------------------------------------------------------------:|:------------------------------------------------------------------------------------------------------:|
| **Deserialization** |                                                   ✅                                                    |                                                   ✅                                                    |
|  **Serialization**  |                                                   ❌                                                    |                                                   ❌                                                    |

#### TODO
- Fix up API (probably in the style of the Java Reflection API)
- Add and implement common interfaces between similar objects (looking at you ProxyClass and NewClass)
- Properly validate expected types, use std::variant (or actually it would be nicer to make a custom holder) in place of IObject when available.
  - For object types like TC_ENDBLOCKDATA, we can ignore it and store nullptr.
## Contributing
Unless otherwise stated, contributions are licensed under the terms of the
MIT license.

## Credits
https://docs.oracle.com/javase/9/docs/specs/serialization/protocol.html#grammar-for-the-stream-format
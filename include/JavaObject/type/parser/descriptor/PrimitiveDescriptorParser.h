/** @file PrimitiveDescriptorParser.h
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file
 * for details.
 */
#ifndef JAVAOUTPUTSTREAMS_PRIMITIVEDESCRIPTORPARSER_H
#define JAVAOUTPUTSTREAMS_PRIMITIVEDESCRIPTORPARSER_H
#include "JavaObject/type/parser/IObjectParser.h"

namespace javaobject {
    namespace type {
        namespace parser {
            namespace descriptor {
                class PrimitiveDescriptorParser : public IObjectParser {
                  public:
                    std::unique_ptr<object::IObject>
                    operator()(TypeCodeParser &parser) override;
                };
            } // namespace descriptor
        } // namespace parser
    } // namespace type
} // namespace javaobject

#endif // JAVAOUTPUTSTREAMS_PRIMITIVEDESCRIPTORPARSER_H

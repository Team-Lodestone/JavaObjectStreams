/** @file PrimitiveDescriptorParser.cpp
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
#include "PrimitiveDescriptorParser.h"

#include "JavaObject/EPrimitiveTypeCode.h"
#include "JavaObject/type/TypeCodeParser.h"
#include "JavaObject/type/object/descriptor/PrimitiveDescriptorObject.h"

namespace javaobject {
    namespace type {
        namespace parser {
            namespace descriptor {
                std::unique_ptr<object::IObject>
                PrimitiveDescriptorParser::operator()(TypeCodeParser &parser) {
                    EPrimitiveTypeCode tc = parser.stream().read<EPrimitiveTypeCode>();
                    std::string name = parser.stream().readStringWithLength<char>(bio::util::ByteOrder::BIG, bio::util::string::StringLengthEncoding::LENGTH_PREFIX);

                    return std::make_unique<object::descriptor::PrimitiveDescriptorObject>(
                        tc,
                        name
                    );
                }
            } // namespace descriptor
        } // namespace parser
    } // namespace type
} // namespace javaobject
/** @file ClassDescriptorParser.cpp
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
#include "ClassDescriptorParser.h"

#include "JavaObject/type/TypeCodeParser.h"
#include "JavaObject/type/object/descriptor/ClassDescriptorObject.h"
#include "JavaObject/type/parser/descriptor/ClassDescriptorInfoParser.h"
#include "JavaObject/util/SmartPointerCast.h"

namespace javaobject {
    namespace type {
        namespace parser {
            namespace descriptor {
                std::unique_ptr<object::IObject> ClassDescriptorParser::operator()(TypeCodeParser &parser) {
                    std::string className =
                        parser.stream().readStringWithLength<char>(bio::util::ByteOrder::BIG, bio::util::string::StringLengthEncoding::LENGTH_PREFIX);
                    uint64_t uid = parser.stream().readBE<uint64_t>();

                    auto info = util::SmartPointerCast::staticUniquePtrCast<object::descriptor::ClassDescriptorObject::Info>(
                        ClassDescriptorInfoParser()(parser));

                    return std::make_unique<object::descriptor::ClassDescriptorObject>(
                        className,
                        uid,
                        std::move(info)
                    );
                }
            } // namespace descriptor
        } // namespace parser
    } // namespace type
} // namespace javaobject
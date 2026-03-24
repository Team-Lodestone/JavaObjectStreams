/** @file ClassDescriptorInfoParser.cpp
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
#include "ClassDescriptorInfoParser.h"

#include "JavaObject/type/TypeCodeParser.h"
#include "JavaObject/type/object/descriptor/ClassDescriptorObject.h"
#include "JavaObject/type/parser/descriptor/FieldDescriptorParser.h"
#include "JavaObject/util/SmartPointerCast.h"

namespace javaobject {
    namespace type {
        namespace parser {
            namespace descriptor {
                std::unique_ptr<object::IObject>
                ClassDescriptorInfoParser::operator()(TypeCodeParser &parser) {
                    int8_t flags = parser.stream().readSignedByte();

                    int16_t fieldCount = parser.stream().readBE<int16_t>();
                    std::unordered_map<std::unique_ptr<object::descriptor::FieldDescriptorObject>, std::unique_ptr<object::IObject>> objects(fieldCount);

                    for (int i = 0; i < fieldCount; i++) {
                        objects.emplace(util::SmartPointerCast::staticUniquePtrCast<object::descriptor::FieldDescriptorObject>(FieldDescriptorParser()(parser)), nullptr);
                    }

                    std::unique_ptr<object::IObject> classAnnotation = parser.readNext();
                    std::unique_ptr<object::IObject> superClassDescriptor = parser.readNext();

                    return std::make_unique<object::descriptor::ClassDescriptorObject::Info>(
                        flags,
                        std::move(objects),
                        std::move(classAnnotation),
                        std::move(superClassDescriptor)
                    );
                }
            } // namespace descriptor
        } // namespace parser
    } // namespace type
} // namespace javaobject
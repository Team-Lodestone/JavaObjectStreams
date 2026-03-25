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
#include "JavaObject/type/object/descriptor/NewClassDescriptorObject.h"
#include "JavaObject/type/parser/descriptor/FieldDescriptorParser.h"

namespace javaobject::type::parser::descriptor {
    std::shared_ptr<object::IObject> ClassDescriptorInfoParser::operator()(TypeCodeParser &parser) const {
        int8_t flags = parser.stream().readSignedByte();

        int16_t fieldCount = parser.stream().readBE<int16_t>();
        std::unordered_map<std::shared_ptr<object::descriptor::FieldDescriptorObject>, std::shared_ptr<object::IObject>> objects(fieldCount);

        for (int i = 0; i < fieldCount; i++) {
            objects.emplace(parser.readAsUsingParser<object::descriptor::FieldDescriptorObject>(FieldDescriptorParser()), nullptr);
        }

        std::shared_ptr<object::IObject> classAnnotation = parser.readNext();
        std::shared_ptr<object::IObject> superClassDescriptor = parser.readNext();

        return std::make_shared<object::descriptor::ClassDescriptorInfoObject>(flags, std::move(objects), std::move(classAnnotation),
                                                                               std::move(superClassDescriptor));
    }
} // namespace javaobject::type::parser::descriptor
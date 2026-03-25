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
#include "JavaObject/type/object/parsers/descriptor/ClassDescriptorInfoParser.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/object/types/descriptor/NewClassDescriptorObject.h"
#include "JavaObject/type/object/parsers/descriptor/FieldDescriptorParser.h"

namespace javaobject::type::object::parsers::descriptor {
    std::shared_ptr<object::IObject> ClassDescriptorInfoParser::operator()(object::ObjectTypeCodeParser &parser) const {
        int8_t flags = parser.stream().readSignedByte();

        const int16_t fieldCount = parser.stream().readBE<int16_t>();
        std::vector<std::pair<std::string, std::shared_ptr<object::descriptor::FieldDescriptorObject>>> objects(fieldCount);

        for (int i = 0; i < fieldCount; i++) {
            auto f = parser.readAsUsingParser<object::descriptor::FieldDescriptorObject>(FieldDescriptorParser());

            objects[i] = std::make_pair(f->primitiveDescriptor->name, f);
        }

        std::shared_ptr<object::IObject> classAnnotation = parser.readNext();
        std::shared_ptr<object::IObject> superClassDescriptor = parser.readNext();

        return std::make_shared<object::descriptor::ClassDescriptorInfoObject>(flags, std::move(objects), std::move(classAnnotation),
                                                                               std::move(superClassDescriptor));
    }
} // namespace javaobject::type::parser::descriptor
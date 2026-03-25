/** @file FieldDescriptorParser.cpp
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
#include "JavaObject/type/object/parsers/descriptor/FieldDescriptorParser.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/object/types/descriptor/FieldDescriptorObject.h"
#include "JavaObject/type/object/types/descriptor/PrimitiveDescriptorObject.h"
#include "JavaObject/type/object/parsers/descriptor/PrimitiveDescriptorParser.h"
#include "JavaObject/util/SmartPointerCast.h"

namespace javaobject::type::object::parsers::descriptor {
    std::shared_ptr<object::IObject>
    FieldDescriptorParser::operator()(ObjectTypeCodeParser &parser) const {
        auto fd = std::make_shared<object::descriptor::FieldDescriptorObject>(
            nullptr, nullptr);

        fd->primitiveDescriptor = std::static_pointer_cast<
            object::descriptor::PrimitiveDescriptorObject>(
            std::move(PrimitiveDescriptorParser()(parser)));

        if (fd->primitiveDescriptor->typeCode ==
                EPrimitiveTypeCode::TYPE_OBJECT ||
            fd->primitiveDescriptor->typeCode ==
                EPrimitiveTypeCode::TYPE_ARRAY) {
            fd->objectDescriptor = parser.readNext();
        }

        return std::move(fd);
    }
} // namespace javaobject::type::parser::descriptor
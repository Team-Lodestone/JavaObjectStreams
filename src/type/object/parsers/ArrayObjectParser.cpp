/** @file ArrayObjectParser.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/object/parsers/ArrayObjectParser.h"

#include "JavaObject/type/object/types/ArrayObject.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/primitive/PrimitiveTypeCodeParser.h"

namespace javaobject::type::object::parsers {
    std::shared_ptr<object::IObject> ArrayObjectParser::operator()(type::object::ObjectTypeCodeParser &parser) const {
        auto dc = std::dynamic_pointer_cast<descriptor::NewClassDescriptorObject>(parser.readNext());

        if (!dc) {
            throw std::runtime_error("Array type descriptor is TC_NULL!!!!!");
        }

        auto obj = std::make_shared<types::ArrayObject>(dc);
        parser.handleContainer().registerHandle(obj);

        const int32_t size = parser.stream().readBE<int32_t>();
        obj->values.resize(size);

        const auto primitiveParser = parser.parserStorage().primitiveParser;
        const auto parserClass = primitiveParser->getParser(static_cast<EPrimitiveTypeCode>(dc->name.at(1)));
        for (int32_t i = 0; i < size; i++) {
            obj->values[i] = primitiveParser->readUsingParser(*parserClass);
        }

        return obj;
    }
} // namespace javaobject::type::object::parsers
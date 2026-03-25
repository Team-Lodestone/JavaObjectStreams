/** @file TypeCode.cpp
 *
 * @author DexrnZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 */
#include "JavaObject/type/object/ObjectTypeCodeParser.h"

#include "JavaObject/type/object/types/NullObject.h"
#include "JavaObject/type/object/parsers/ObjectParser.h"
#include "JavaObject/type/object/parsers/ReferenceParser.h"
#include "JavaObject/type/object/parsers/StringParser.h"
#include "JavaObject/type/object/parsers/descriptor/ClassDescriptorParser.h"
#include "JavaObject/type/object/parsers/descriptor/NewClassDescriptorParser.h"

#include <istream>

namespace javaobject::type::object {
    ObjectTypeCodeParser::ObjectTypeCodeParser(std::istream &input, HandleContainer &handleContainer) : ITypeCodeParser(input, handleContainer), m_primitiveParser(input, handleContainer) {
        this->m_parsers[EObjectTypeCode::TC_STRING] = std::make_unique<object::parsers::StringParser>();
        this->m_parsers[EObjectTypeCode::TC_OBJECT] = std::make_unique<object::parsers::ObjectParser>();
        this->m_parsers[EObjectTypeCode::TC_CLASSDESC] = std::make_unique<object::parsers::descriptor::ClassDescriptorParser>();
        this->m_parsers[EObjectTypeCode::TC_REFERENCE] = std::make_unique<object::parsers::ReferenceParser>();
    }

    std::shared_ptr<object::IObject> ObjectTypeCodeParser::readNext() {
        const EObjectTypeCode tc = static_cast<EObjectTypeCode>(this->m_input.readByte());

        if (const auto it = m_parsers.find(tc); it != this->m_parsers.end()) {
            return this->readUsingParser(*it->second);
        }

        return std::make_shared<object::NullObject>();
    }

    std::shared_ptr<object::IObject> ObjectTypeCodeParser::readUsingParser(const object::parsers::IObjectParser &parser) { return parser(*this); }
    primitive::PrimitiveTypeCodeParser &ObjectTypeCodeParser::primitiveTypeCodeParser() {
        return this->m_primitiveParser;
    }
} // namespace javaobject::type
/** @file TypeCode.cpp
 *
 * @author DexrnZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 */
#include "TypeCodeParser.h"

#include "JavaObject/type/object/NullObject.h"
#include "JavaObject/type/parser/ObjectParser.h"
#include "JavaObject/type/parser/StringParser.h"
#include "JavaObject/type/parser/descriptor/ClassDescriptorParser.h"

#include <istream>

namespace javaobject {
    namespace type {
        TypeCodeParser::TypeCodeParser(std::istream &input) : m_input(input) {
            this->m_parsers[EObjectTypeCode::TC_STRING] = std::make_unique<parser::StringParser>();
            this->m_parsers[EObjectTypeCode::TC_OBJECT] = std::make_unique<parser::ObjectParser>();
            this->m_parsers[EObjectTypeCode::TC_CLASSDESC] = std::make_unique<parser::descriptor::ClassDescriptorParser>();
        }

        std::unique_ptr<object::IObject> TypeCodeParser::readNext() {
            const EObjectTypeCode tc = static_cast<EObjectTypeCode>(this->m_input.readByte());

            const auto it = m_parsers.find(tc);
            if (it != this->m_parsers.end()) {
                return (*it->second)(*this);
            }

            return std::make_unique<object::NullObject>();
        }

        parser::IObjectParser *
        TypeCodeParser::getParser(const EObjectTypeCode typeCode) {
            const auto it = m_parsers.find(typeCode);
            if (it != this->m_parsers.end()) {
                return it->second.get();
            }

            return nullptr;
        }

        bio::stream::BinaryInputStream &TypeCodeParser::stream() {
            return this->m_input;
        }
    } // namespace type
} // namespace javaobject
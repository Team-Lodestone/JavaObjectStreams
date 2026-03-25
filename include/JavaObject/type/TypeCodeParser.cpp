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
#include "JavaObject/type/parser/ReferenceParser.h"
#include "JavaObject/type/parser/StringParser.h"
#include "JavaObject/type/parser/descriptor/ClassDescriptorParser.h"
#include "JavaObject/type/parser/descriptor/NewClassDescriptorParser.h"

#include <istream>

namespace javaobject {
    namespace type {
        TypeCodeParser::TypeCodeParser(std::istream &input) : m_input(input) {
            this->m_parsers[EObjectTypeCode::TC_STRING] = std::make_unique<parser::StringParser>();
            this->m_parsers[EObjectTypeCode::TC_OBJECT] = std::make_unique<parser::ObjectParser>();
            this->m_parsers[EObjectTypeCode::TC_CLASSDESC] = std::make_unique<parser::descriptor::ClassDescriptorParser>();
            this->m_parsers[EObjectTypeCode::TC_REFERENCE] = std::make_unique<parser::ReferenceParser>();
        }

        std::unique_ptr<object::IObject> TypeCodeParser::readNext() {
            const EObjectTypeCode tc = static_cast<EObjectTypeCode>(this->m_input.readByte());

            const auto it = m_parsers.find(tc);
            if (it != this->m_parsers.end()) {
                return this->readUsingParser(*it->second);
            }

            return std::make_unique<object::NullObject>();
        }

        std::unique_ptr<object::IObject> TypeCodeParser::readUsingParser(const parser::IObjectParser &parser)  {
            return parser(*this);
        }

        parser::IObjectParser *
        TypeCodeParser::getParser(const EObjectTypeCode typeCode) {
            const auto it = m_parsers.find(typeCode);
            if (it != this->m_parsers.end()) {
                return it->second.get();
            }

            return nullptr;
        }

        void TypeCodeParser::registerHandle(object::IObject *object) {
            this->m_handles[m_nextHandle] = object;
            this->m_nextHandle++;
        }

        object::IObject *TypeCodeParser::resolveHandle(const object::ReferenceObject::handle_t handle) {
            if (const auto it = m_handles.find(handle); it != this->m_handles.end()) {
                return it->second;
            }

            return nullptr;
        }

        bio::stream::BinaryInputStream &TypeCodeParser::stream() {
            return this->m_input;
        }
    } // namespace type
} // namespace javaobject
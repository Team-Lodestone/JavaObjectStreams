/** @file ProxyClassDescriptorInfoParser.cpp
 *
 * @author DexrnZacAttack
 * @date 3/29/26
 * 
 * @device zPc-i2
 */
#include "JavaObject/type/object/parsers/descriptor/ProxyClassDescriptorInfoParser.h"

#include "BinaryIO/util/ByteOrder.h"
#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/object/types/AnnotationObject.h"
#include "JavaObject/type/object/types/descriptor/ProxyClassDescriptorInfoObject.h"

#include <format>

namespace javaobject::type::object::parsers::descriptor {
    std::shared_ptr<object::IObject> ProxyClassDescriptorInfoParser::operator()(type::object::ObjectTypeCodeParser &parser) const {
        auto dci = std::make_shared<types::descriptor::ProxyClassDescriptorInfoObject>();

        const int32_t c = parser.stream().readBE<int32_t>();
        dci->m_interfaces.reserve(c);

        for (int i = 0; i < c; i++) {
            dci->m_interfaces.push_back(
                parser.stream().readStringWithLength<char>(bio::util::ByteOrder::BIG, bio::util::string::StringLengthEncoding::LENGTH_PREFIX)
            );
        }

        const std::shared_ptr<IObject> a = parser.readNext();

        dci->m_annotation = std::dynamic_pointer_cast<AnnotationObject>(a);
        dci->m_superClassDesc = parser.readNext();

        return dci;
    }
}
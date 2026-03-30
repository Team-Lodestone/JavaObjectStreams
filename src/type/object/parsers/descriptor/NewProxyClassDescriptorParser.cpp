/** @file NewProxyClassDescriptorParser.cpp
 *
 * @author DexrnZacAttack
 * @date 3/29/26
 * 
 * @device zPc-i2
 */
#include "JavaObject/type/object/parsers/descriptor/NewProxyClassDescriptorParser.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/object/parsers/descriptor/ProxyClassDescriptorInfoParser.h"
#include "JavaObject/type/object/types/descriptor/ProxyClassDescriptorObject.h"

#include <format>

namespace javaobject::type::object::parsers::descriptor {
    std::shared_ptr<object::IObject> NewProxyClassDescriptorParser::operator()(type::object::ObjectTypeCodeParser &parser) const {
        std::shared_ptr<types::descriptor::ProxyClassDescriptorObject> dc = std::make_shared<types::descriptor::ProxyClassDescriptorObject>(nullptr);

        parser.handleContainer().registerHandle(dc);

        dc->info = parser.readAsUsingParser<types::descriptor::ProxyClassDescriptorInfoObject>(ProxyClassDescriptorInfoParser());

        return dc;
    }
}
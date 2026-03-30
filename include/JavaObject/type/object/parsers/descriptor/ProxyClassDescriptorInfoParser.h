/** @file ProxyClassDescriptorInfoParser.h
 *
 * @author DexrnZacAttack
 * @date 3/29/26
 * 
 * @device zPc-i2
 */
#ifndef JAVAOBJECTSTREAMS_PROXYCLASSDESCRIPTORINFOPARSER_H
#define JAVAOBJECTSTREAMS_PROXYCLASSDESCRIPTORINFOPARSER_H
#include "JavaObject/type/object/parsers/IObjectParser.h"

namespace javaobject::type::object::parsers::descriptor {
    struct ProxyClassDescriptorInfoParser : IObjectParser {
        std::shared_ptr<object::IObject> operator()(type::object::ObjectTypeCodeParser &parser) const override;
    };
}

#endif // JAVAOBJECTSTREAMS_PROXYCLASSDESCRIPTORINFOPARSER_H
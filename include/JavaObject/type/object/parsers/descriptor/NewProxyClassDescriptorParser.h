/** @file NewProxyClassDescriptorParser.h
 *
 * @author DexrnZacAttack
 * @date 3/29/26
 * 
 * @device zPc-i2
 */
#ifndef JAVAOBJECTSTREAMS_NEWPROXYCLASSDESCRIPTORPARSER_H
#define JAVAOBJECTSTREAMS_NEWPROXYCLASSDESCRIPTORPARSER_H
#include "JavaObject/type/object/parsers/IObjectParser.h"

namespace javaobject::type::object::parsers::descriptor {
    struct NewProxyClassDescriptorParser : IObjectParser {
        std::shared_ptr<object::IObject> operator()(type::object::ObjectTypeCodeParser &parser) const override;
    };
}

#endif // JAVAOBJECTSTREAMS_NEWPROXYCLASSDESCRIPTORPARSER_H
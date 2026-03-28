/** @file ObjectTypeCodeParser.h
 *
 * @author DexrnZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 */
#ifndef JAVAOBJECTSTREAMS_TYPECODE_H
#define JAVAOBJECTSTREAMS_TYPECODE_H
#include "JavaObject/EObjectTypeCode.h"
#include "JavaObject/type/HandleContainer.h"
#include "JavaObject/type/ITypeCodeParser.h"
#include "JavaObject/type/object/parsers/IObjectParser.h"

#include <iosfwd>
#include <memory>

#include "JavaObject/type/ITypeCodeParserStorageHolder.h"

namespace javaobject::type::primitive {
    class PrimitiveTypeCodeParser;
}

namespace javaobject::type::object {
    class ObjectTypeCodeParser : public ITypeCodeParser<IObject, parsers::IObjectParser, EObjectTypeCode>, public ITypeCodeParserStorageHolder {
    public:
        explicit ObjectTypeCodeParser(std::istream &input, HandleContainer &handleContainer, TypeCodeParserStorage &parserStorage);

        std::shared_ptr<object::IObject> readNext() override;
        std::shared_ptr<object::IObject> readUsingParser(const object::parsers::IObjectParser &parser) override;
        std::shared_ptr<IObject> readUsingTypeCode(const EObjectTypeCode &typecode) override;
    };
} // namespace javaobject::type

#endif // JAVAOBJECTSTREAMS_TYPECODE_H
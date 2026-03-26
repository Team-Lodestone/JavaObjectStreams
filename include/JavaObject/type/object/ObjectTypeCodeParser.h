/** @file TypeCode.h
 *
 * @author DexrnZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 */
#ifndef JAVAOBJECTSTREAMS_TYPECODE_H
#define JAVAOBJECTSTREAMS_TYPECODE_H
#include "BinaryIO/stream/BinaryInputStream.h"
#include "JavaObject/EObjectTypeCode.h"
#include "JavaObject/type/HandleContainer.h"
#include "JavaObject/type/ITypeCodeParser.h"
#include "JavaObject/type/object/parsers/IObjectParser.h"
#include "JavaObject/type/object/parsers/ReferenceParser.h"
#include "JavaObject/type/primitive/PrimitiveTypeCodeParser.h"
#include "JavaObject/util/SmartPointerCast.h"
#include "types/ReferenceObject.h"

#include <functional>
#include <iosfwd>
#include <memory>
#include <unordered_map>
#include <variant>

namespace javaobject::type::primitive {
    class PrimitiveTypeCodeParser;
}

namespace javaobject::type::object {
    class ObjectTypeCodeParser : public ITypeCodeParser<IObject, parsers::IObjectParser, EObjectTypeCode> {
    public:
        explicit ObjectTypeCodeParser(std::istream &input, HandleContainer &handleContainer);

        std::shared_ptr<object::IObject> readNext() override;
        std::shared_ptr<object::IObject> readUsingParser(const object::parsers::IObjectParser &parser) override;

        primitive::PrimitiveTypeCodeParser &primitiveTypeCodeParser();

    private:
        primitive::PrimitiveTypeCodeParser m_primitiveParser;
    };
} // namespace javaobject::type

#endif // JAVAOBJECTSTREAMS_TYPECODE_H
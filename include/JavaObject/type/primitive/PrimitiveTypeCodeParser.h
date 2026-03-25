/** @file PrimitiveTypeCodeParser.h
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_PRIMITIVETYPECODEPARSER_H
#define JAVAOBJECTSTREAMS_PRIMITIVETYPECODEPARSER_H
#include "BinaryIO/stream/BinaryInputStream.h"
#include "JavaObject/EPrimitiveTypeCode.h"
#include "JavaObject/type/HandleContainer.h"
#include "JavaObject/type/ITypeCodeParser.h"
#include "JavaObject/type/primitive/parsers/IPrimitiveObjectParser.h"
#include "JavaObject/type/primitive/types/IPrimitiveObject.h"

namespace javaobject::type::primitive {
    class PrimitiveTypeCodeParser : public ITypeCodeParser<types::IPrimitiveObject, parsers::IPrimitiveObjectParser, EPrimitiveTypeCode> {
    public:
        explicit PrimitiveTypeCodeParser(std::istream &input, HandleContainer &handleContainer);

        std::shared_ptr<types::IPrimitiveObject> readNext() override;
        std::shared_ptr<types::IPrimitiveObject> readUsingParser(const parsers::IPrimitiveObjectParser &parser) override;
    };
} // namespace javaobject::type::primitive

#endif // JAVAOBJECTSTREAMS_PRIMITIVETYPECODEPARSER_H

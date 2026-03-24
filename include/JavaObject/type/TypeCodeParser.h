/** @file TypeCode.h
 *
 * @author DexrnZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 */
#ifndef JAVAOUTPUTSTREAMS_TYPECODE_H
#define JAVAOUTPUTSTREAMS_TYPECODE_H
#include "BinaryIO/stream/BinaryInputStream.h"
#include "JavaObject/EObjectTypeCode.h"
#include "JavaObject/type/parser/IObjectParser.h"

#include <functional>
#include <iosfwd>
#include <memory>
#include <unordered_map>
#include <variant>

namespace javaobject::type {
    class TypeCodeParser {
    public:
        TypeCodeParser(std::istream &input);

        std::unique_ptr<object::IObject> readNext();

        parser::IObjectParser *getParser(const EObjectTypeCode typeCode);

        bio::stream::BinaryInputStream &stream();
    private:
        std::unordered_map<EObjectTypeCode, std::unique_ptr<parser::IObjectParser>> m_parsers;

        bio::stream::BinaryInputStream m_input;
    };
} // namespace javaobject::type

#endif // JAVAOUTPUTSTREAMS_TYPECODE_H
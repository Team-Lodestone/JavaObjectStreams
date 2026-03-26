/** @file EPrimitiveTypeCode.h
 *
 * @author DexrnZacAttack
 * @date 3/23/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_EPRIMITIVETYPECODE_H
#define JAVAOBJECTSTREAMS_EPRIMITIVETYPECODE_H
#include <format>

enum class EPrimitiveTypeCode : signed char {
    TYPE_BYTE = 'B',
    TYPE_CHARACTER = 'C',
    TYPE_DOUBLE = 'D',
    TYPE_FLOAT = 'F',
    TYPE_INT = 'I',
    TYPE_LONG = 'J',
    TYPE_OBJECT = 'L',
    TYPE_SHORT = 'S',
    TYPE_BOOLEAN = 'Z',
    TYPE_ARRAY = '['
};

static constexpr const char *primitiveTypeCodeToString(const EPrimitiveTypeCode tc) {
    switch (tc) {
    case EPrimitiveTypeCode::TYPE_BYTE:
        return "Byte";
    case EPrimitiveTypeCode::TYPE_CHARACTER:
        return "Character";
    case EPrimitiveTypeCode::TYPE_DOUBLE:
        return "Double";
    case EPrimitiveTypeCode::TYPE_FLOAT:
        return "Float";
    case EPrimitiveTypeCode::TYPE_INT:
        return "Integer";
    case EPrimitiveTypeCode::TYPE_LONG:
        return "Long";
    case EPrimitiveTypeCode::TYPE_OBJECT:
        return "Object";
    case EPrimitiveTypeCode::TYPE_SHORT:
        return "Short";
    case EPrimitiveTypeCode::TYPE_BOOLEAN:
        return "Boolean";
    case EPrimitiveTypeCode::TYPE_ARRAY:
        return "Array";
    default:
        throw std::invalid_argument("not valid EPrimitiveTypeCode");
    }
}

template <> struct std::formatter<EPrimitiveTypeCode> {
    template <typename FormatParseContext> constexpr auto parse(FormatParseContext &pc) { return pc.begin(); }

    template <typename FormatContext> auto format(EPrimitiveTypeCode tc, FormatContext &fc) const { return std::format_to(fc.out(), "{}", primitiveTypeCodeToString(tc)); }
};

#endif // JAVAOBJECTSTREAMS_EPRIMITIVETYPECODE_H
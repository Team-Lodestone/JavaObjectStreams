/** @file IPrimitiveObjectParser.h
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_IPRIMITIVEOBJECTPARSER_H
#define JAVAOBJECTSTREAMS_IPRIMITIVEOBJECTPARSER_H
#include <memory>

namespace javaobject::type::primitive {
    class PrimitiveTypeCodeParser;
}
namespace javaobject::type::primitive::types {
    struct IPrimitiveObject;
}

namespace javaobject::type::primitive::parsers {
    class IPrimitiveObjectParser {
    public:
        virtual ~IPrimitiveObjectParser() = default;

        virtual std::shared_ptr<types::IPrimitiveObject> operator()(PrimitiveTypeCodeParser &parser) const = 0;
    };
} // namespace javaobject::type::primitive::parsers

#endif // JAVAOBJECTSTREAMS_IPRIMITIVEOBJECTPARSER_H

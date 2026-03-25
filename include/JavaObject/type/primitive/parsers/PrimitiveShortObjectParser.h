/** @file PrimitiveShortObjectParser.h
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_PRIMITIVESHORTOBJECTPARSER_H
#define JAVAOBJECTSTREAMS_PRIMITIVESHORTOBJECTPARSER_H
#include "JavaObject/type/primitive/parsers/IPrimitiveObjectParser.h"

namespace javaobject::type::primitive::parsers {
    struct PrimitiveShortObjectParser : IPrimitiveObjectParser {
        std::shared_ptr<types::IPrimitiveObject> operator()(PrimitiveTypeCodeParser &parser) const override;
    };
} // namespace javaobject::type::primitive::parsers

#endif // JAVAOBJECTSTREAMS_PRIMITIVESHORTOBJECTPARSER_H

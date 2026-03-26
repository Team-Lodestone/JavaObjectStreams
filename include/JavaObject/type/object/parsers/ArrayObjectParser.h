/** @file ArrayObjectParser.h
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_ARRAYOBJECTPARSER_H
#define JAVAOBJECTSTREAMS_ARRAYOBJECTPARSER_H
#include "JavaObject/type/object/parsers/IObjectParser.h"

namespace javaobject::type::object::parsers {
    // the c lion does not concern itself with compiler errors
    struct ArrayObjectParser : IObjectParser {
        std::shared_ptr<object::IObject> operator()(type::object::ObjectTypeCodeParser &parser) const override;
    };
} // namespace javaobject::type::object::parsers

#endif // JAVAOBJECTSTREAMS_ARRAYOBJECTPARSER_H

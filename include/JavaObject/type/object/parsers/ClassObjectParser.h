/** @file ClassObjectParser.h
 *
 * @author Dexrn ZacAttack
 * @date 3/28/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_CLASSOBJECTPARSER_H
#define JAVAOBJECTSTREAMS_CLASSOBJECTPARSER_H
#include "JavaObject/type/object/parsers/IObjectParser.h"

namespace javaobject::type::object::parsers {
    struct ClassObjectParser : public IObjectParser {
        std::shared_ptr<object::IObject> operator()(type::object::ObjectTypeCodeParser &parser) const override;
    };
} // namespace javaobject::type::object::parsers

#endif //JAVAOBJECTSTREAMS_CLASSOBJECTPARSER_H

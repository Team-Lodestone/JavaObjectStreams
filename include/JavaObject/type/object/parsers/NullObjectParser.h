/** @file NullObjectParser.h
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_NULLOBJECTPARSER_H
#define JAVAOBJECTSTREAMS_NULLOBJECTPARSER_H
#include "IObjectParser.h"

namespace javaobject::type::object::parsers {
    struct NullObjectParser : IObjectParser {
        std::shared_ptr<object::IObject> operator()(type::object::ObjectTypeCodeParser& parser) const override;
    };
}

#endif //JAVAOBJECTSTREAMS_NULLOBJECTPARSER_H

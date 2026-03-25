/** @file StringParser.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file
 * for details.
 */
#include "JavaObject/type/object/parsers/StringParser.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/object/types/StringObject.h"

namespace javaobject::type::object::parsers {
    std::shared_ptr<object::IObject> StringParser::operator()(type::object::ObjectTypeCodeParser &parser) const {
        auto str = std::make_shared<object::StringObject>(
            parser.stream().readStringWithLength<char>(bio::util::ByteOrder::BIG, bio::util::string::StringLengthEncoding::LENGTH_PREFIX)
        );

        parser.handleContainer().registerHandle(str);

        return str;
    }
} // namespace javaobject::type::object::parsers
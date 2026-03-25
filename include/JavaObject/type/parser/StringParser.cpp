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
#include "StringParser.h"

#include "JavaObject/type/TypeCodeParser.h"
#include "JavaObject/type/object/StringObject.h"

namespace javaobject::type::parser {
    std::unique_ptr<object::IObject> StringParser::operator()(TypeCodeParser &parser) const {
        return std::make_unique<object::StringObject>(
            parser.stream().readStringWithLength<char>(bio::util::ByteOrder::BIG, bio::util::string::StringLengthEncoding::LENGTH_PREFIX)
        );
    }
} // namespace javaobject::type::parser
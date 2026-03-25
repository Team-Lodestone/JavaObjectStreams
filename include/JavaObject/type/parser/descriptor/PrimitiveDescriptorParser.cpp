/** @file PrimitiveDescriptorParser.cpp
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
#include "PrimitiveDescriptorParser.h"

#include "JavaObject/EPrimitiveTypeCode.h"
#include "JavaObject/type/TypeCodeParser.h"
#include "JavaObject/type/object/descriptor/PrimitiveDescriptorObject.h"

namespace javaobject::type::parser::descriptor {
    std::shared_ptr<object::IObject> PrimitiveDescriptorParser::operator()(TypeCodeParser &parser) const {
        EPrimitiveTypeCode tc = parser.stream().read<EPrimitiveTypeCode>();
        std::string name =
            parser.stream().readStringWithLength<char>(bio::util::ByteOrder::BIG, bio::util::string::StringLengthEncoding::LENGTH_PREFIX);

        return std::make_shared<object::descriptor::PrimitiveDescriptorObject>(tc, name);
    }
} // namespace javaobject::type::parser::descriptor
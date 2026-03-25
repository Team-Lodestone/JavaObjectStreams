/** @file NewClassDescriptorParser.cpp
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
#include "NewClassDescriptorParser.h"

#include "JavaObject/type/TypeCodeParser.h"
#include "JavaObject/type/object/descriptor/NewClassDescriptorObject.h"
#include "JavaObject/type/parser/descriptor/ClassDescriptorInfoParser.h"

namespace javaobject::type::parser::descriptor {
    std::shared_ptr<object::IObject> NewClassDescriptorParser::operator()(TypeCodeParser &parser) const {
        std::string className =
            parser.stream().readStringWithLength<char>(bio::util::ByteOrder::BIG, bio::util::string::StringLengthEncoding::LENGTH_PREFIX);
        uint64_t uid = parser.stream().readBE<uint64_t>();

        auto desc = std::make_shared<object::descriptor::NewClassDescriptorObject>(className, uid, nullptr);
        parser.registerHandle(desc); //register handle

        desc->info = std::static_pointer_cast<object::descriptor::ClassDescriptorInfoObject>(ClassDescriptorInfoParser()(parser));

        return desc;
    }
} // namespace javaobject::type::parser::descriptor
/** @file LongBlockDataObjectParser.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/object/parsers/LongBlockDataObjectParser.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/object/types/BlockDataObject.h"

namespace javaobject::type::object::parsers {
    std::shared_ptr<object::IObject> LongBlockDataObjectParser::operator()(type::object::ObjectTypeCodeParser& parser) const {
        const int32_t sz = parser.stream().readBE<int32_t>();

        std::vector<int8_t> d(sz);
        parser.stream().readInto(reinterpret_cast<uint8_t*>(d.data()), sz);

        return std::make_shared<BlockDataObject>(
            d
        );
    }
}

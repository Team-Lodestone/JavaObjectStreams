/** @file EndBlockDataObjectParser.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/object/parsers/EndBlockDataObjectParser.h"

#include "JavaObject/type/object/types/EndBlockDataObject.h"

namespace javaobject::type::object::parsers {
    std::shared_ptr<object::IObject> EndBlockDataObjectParser::operator()(type::object::ObjectTypeCodeParser& parser) const {
        return std::make_shared<types::EndBlockDataObject>();
    }
}

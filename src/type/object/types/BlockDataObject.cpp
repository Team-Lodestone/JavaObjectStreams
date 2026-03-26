/** @file BlockDataObject.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/object/types/BlockDataObject.h"

#include <format>

namespace javaobject::type::object::parsers {
    std::string BlockDataObject::toString() {
        return std::format("BlockData(size={})", this->data.size());
    }
} // namespace javaobject::type::object::parsers
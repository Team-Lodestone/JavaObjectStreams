/** @file ClassDataObject.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/object/types/ClassDataObject.h"

#include <format>

namespace javaobject::type::object {
    std::string ClassDataObject::toString() {
        return "ClassData";
    }

    std::string SerializableClassDataObject::toString() {
        return std::format("SerializableClassData(values={})", this->values.size());
    }
    std::string SerializableWriteMethodClassDataObject::toString() {
        return std::format("SerializableWriteMethodClassData(values={}, annotationContents={})", this->values.size(), this->annotation->contents.size());
    }
} // namespace javaobject::type::object
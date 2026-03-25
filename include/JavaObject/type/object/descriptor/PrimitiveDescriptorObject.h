/** @file PrimitiveDescriptorObject.h
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
#ifndef JAVAOBJECTSTREAMS_PRIMITIVEDESCRIPTOROBJECT_H
#define JAVAOBJECTSTREAMS_PRIMITIVEDESCRIPTOROBJECT_H
#include "JavaObject/EPrimitiveTypeCode.h"
#include "JavaObject/type/object/IObject.h"

#include <string>

namespace javaobject::type::object::descriptor {
    struct PrimitiveDescriptorObject : public IObject {
        PrimitiveDescriptorObject(const EPrimitiveTypeCode typeCode, const std::string &name) : typeCode(typeCode), name(name) {}

        EPrimitiveTypeCode typeCode;
        std::string name;
    };
} // namespace javaobject::type::object::descriptor

#endif // JAVAOBJECTSTREAMS_PRIMITIVEDESCRIPTOROBJECT_H

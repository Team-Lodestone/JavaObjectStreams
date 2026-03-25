/** @file ClassDescriptorInfoObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_CLASSDESCRIPTORINFO_H
#define JAVAOBJECTSTREAMS_CLASSDESCRIPTORINFO_H
#include "JavaObject/type/object/types/IObject.h"
#include "JavaObject/type/object/types/descriptor/FieldDescriptorObject.h"

#include <cstdint>
#include <memory>
#include <unordered_map>
#include <vector>

namespace javaobject::type::object::descriptor {
    struct ClassDescriptorInfoObject : public IObject {
        ClassDescriptorInfoObject(const std::int8_t flags, std::vector<std::pair<std::string, std::shared_ptr<FieldDescriptorObject>>> fields, std::shared_ptr<IObject> classAnnotation,
             std::shared_ptr<IObject> superClassDescriptor)
            : flags(flags), fields(std::move(fields)), classAnnotation(std::move(classAnnotation)),
              superClassDescriptor(std::move(superClassDescriptor)) {}

        enum Flags : std::int8_t {
            SC_WRITE_METHOD = 0x01,
            SC_BLOCK_DATA = 0x08,
            SC_SERIALIZABLE = 0x02,
            SC_EXTERNALIZABLE = 0x04,
            SC_ENUM = 0x10
        };

        std::int8_t flags;
        // field -> value
        // nvm since we have to store field values separately, we will just key them by field name there.
        std::vector<std::pair<std::string, std::shared_ptr<FieldDescriptorObject>>> fields; // TODO yoink map that preserves insert order later
        std::shared_ptr<IObject> classAnnotation;

        std::shared_ptr<IObject> superClassDescriptor;
    };
} // namespace javaobject::type::object::descriptor

#endif // JAVAOBJECTSTREAMS_CLASSDESCRIPTORINFO_H

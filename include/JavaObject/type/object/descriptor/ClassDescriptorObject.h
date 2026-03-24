/** @file ClassDescriptorObject.h
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
#ifndef JAVAOUTPUTSTREAMS_CLASSDESCRIPTOROBJECT_H
#define JAVAOUTPUTSTREAMS_CLASSDESCRIPTOROBJECT_H
#include "JavaObject/type/object/IObject.h"
#include "JavaObject/type/object/descriptor/FieldDescriptorObject.h"

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace javaobject::type::object::descriptor {
    class ClassDescriptorObject : public IObject {
      public:
        struct Info : public IObject {
            Info(const std::int8_t flags, std::unordered_map<std::unique_ptr<FieldDescriptorObject>, std::unique_ptr<IObject>> fields, std::unique_ptr<IObject> classAnnotation,
                 std::unique_ptr<IObject> superClassDescriptor)
                : flags(flags), fields(std::move(fields)), classAnnotation(std::move(classAnnotation)),
                  superClassDescriptor(std::move(superClassDescriptor)) {}

            enum Flags : int8_t {
                SC_WRITE_METHOD = 0x01,
                SC_BLOCK_DATA = 0x08,
                SC_SERIALIZABLE = 0x02,
                SC_EXTERNALIZABLE = 0x04,
                SC_ENUM = 0x10
            };

            std::int8_t flags;
            // field -> value
            std::unordered_map<std::unique_ptr<FieldDescriptorObject>, std::unique_ptr<IObject>> fields;
            std::unique_ptr<IObject> classAnnotation;

            std::unique_ptr<IObject> superClassDescriptor;
        };

        ClassDescriptorObject(const std::string &name, const std::uint64_t serialVersionUid, std::unique_ptr<Info> info)
            : name(name), serialVersionUid(serialVersionUid), info(std::move(info)) {}

        std::string name;
        std::uint64_t serialVersionUid;

        std::unique_ptr<Info> info;
    };
} // namespace javaobject::type::object::descriptor

#endif // JAVAOUTPUTSTREAMS_CLASSDESCRIPTOROBJECT_H

/** @file NewClassDescriptorObject.h
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
#ifndef JAVAOBJECTSTREAMS_NEWCLASSDESCRIPTOROBJECT_H
#define JAVAOBJECTSTREAMS_NEWCLASSDESCRIPTOROBJECT_H
#include "JavaObject/type/object/types/IObject.h"
#include "JavaObject/type/object/types/descriptor/ClassDescriptorInfoObject.h"
#include "JavaObject/type/object/types/descriptor/FieldDescriptorObject.h"

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace javaobject::type::object::descriptor {
    class NewProxyClassDescriptorObject : public IObject {
        // TODO
    };

    struct NewClassDescriptorObject : IObject {
      public:
        NewClassDescriptorObject(const std::string &name, const std::uint64_t serialVersionUid, std::shared_ptr<ClassDescriptorInfoObject> info)
            : name(name), serialVersionUid(serialVersionUid), info(std::move(info)) {}

        std::string toString() override;

        std::string name;
        std::uint64_t serialVersionUid;

        std::shared_ptr<ClassDescriptorInfoObject> info;
    };
} // namespace javaobject::type::object::descriptor

#endif //JAVAOBJECTSTREAMS_NEWCLASSDESCRIPTOROBJECT_H

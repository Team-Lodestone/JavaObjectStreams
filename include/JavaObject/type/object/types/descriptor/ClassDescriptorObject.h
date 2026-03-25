/** @file ClassDescriptorObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_CLASSDESCRIPTOROBJECT_H
#define JAVAOBJECTSTREAMS_CLASSDESCRIPTOROBJECT_H
#include "JavaObject/type/object/types/IObject.h"
#include "JavaObject/type/object/types/descriptor/NewClassDescriptorObject.h"

#include <memory>

namespace javaobject::type::object::descriptor {
    struct ClassDescriptorObject : public IObject {
        ClassDescriptorObject(std::shared_ptr<NewClassDescriptorObject> desc, std::shared_ptr<IObject> nullReference,
                              std::shared_ptr<IObject> prevObject)
            : desc(std::move(desc)), nullReference(std::move(nullReference)), prevObject(std::move(prevObject)) {}

        std::shared_ptr<NewClassDescriptorObject> desc;
        std::shared_ptr<IObject> nullReference;
        std::shared_ptr<IObject> prevObject;
    };
} // namespace javaobject::type::object::descriptor

#endif // JAVAOBJECTSTREAMS_CLASSDESCRIPTOROBJECT_H

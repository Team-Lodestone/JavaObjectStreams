/** @file HandleContainer.h
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_HANDLECONTAINER_H
#define JAVAOBJECTSTREAMS_HANDLECONTAINER_H
#include "JavaObject/type/object/types/IObject.h"
#include "JavaObject/type/object/types/ReferenceObject.h"

#include <memory>
#include <unordered_map>

namespace javaobject::type {
    class HandleContainer {
    public:
        void registerHandle(const std::shared_ptr<object::IObject> &object);

        std::shared_ptr<object::IObject> resolveHandle(const object::ReferenceObject::handle_t handle);
        std::shared_ptr<object::IObject> resolveReference(const object::ReferenceObject *reference);
        std::shared_ptr<object::IObject> resolveReference(const std::shared_ptr<object::ReferenceObject> &reference);

    private:
        /** Links handles to objects by pointer, these objects are expected to be stored already, otherwise it would leave a dangling/invalid pointer. */
        std::unordered_map<object::ReferenceObject::handle_t, std::shared_ptr<object::IObject>> m_handles;
        object::ReferenceObject::handle_t m_nextHandle = 0x7E000000;
    };
} // namespace javaobject::type

#endif // JAVAOBJECTSTREAMS_HANDLECONTAINER_H

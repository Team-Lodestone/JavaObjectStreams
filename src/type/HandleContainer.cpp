/** @file HandleContainer.cpp
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#include "JavaObject/type/HandleContainer.h"

#include <format>
#include <iostream>

namespace javaobject::type {
    void HandleContainer::registerHandle(const std::shared_ptr<object::IObject> &object) {
        this->m_handles.push_back(object);
#ifdef DEBUG
        std::cout << std::format("New handle @ {:#05x}: {}", this->m_handles.size() - 1, object->toString()) << std::endl;
#endif
    }

    std::shared_ptr<object::IObject> HandleContainer::resolveHandle(const object::ReferenceObject::handle_t handle) {
#ifdef DEBUG
        size_t idx = this->getIndex(handle);
        std::shared_ptr<object::IObject> o = this->m_handles[idx];

        std::cout << std::format("Resolved handle @ {:#05x}: {}", idx, o->toString()) << std::endl;
        return o;
#else
        return this->m_handles[this->getIndex(handle)];
#endif
    }

    std::shared_ptr<object::IObject> HandleContainer::resolveReference(const object::ReferenceObject *reference) {
        return this->resolveHandle(reference->handle);
    }

    std::shared_ptr<object::IObject> HandleContainer::resolveReference(const std::shared_ptr<object::ReferenceObject> &reference) {
        return this->resolveReference(reference.get());
    }
    // TODO or maybe reset should just increment the base and we count from there, would prevent references from being nuked
    void HandleContainer::reset() {
        this->m_handles.clear();
    }
} // namespace javaobject::type
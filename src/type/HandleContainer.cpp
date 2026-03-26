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
        this->m_handles.emplace(m_nextHandle, object);
        std::cout << std::format("new handle at {:#05x}: {}", m_nextHandle, object->toString()) << std::endl;

        this->m_nextHandle++;
    }

    std::shared_ptr<object::IObject> HandleContainer::resolveHandle(const object::ReferenceObject::handle_t handle) {
        if (const auto it = m_handles.find(handle); it != this->m_handles.end()) {
            std::cout << std::format("resolved handle at {:#05x}: {}", m_nextHandle, it->second->toString()) << std::endl;
            return it->second;
        }

        static_assert("We should never be missing a handle!!!!");
        return nullptr;
    }

    std::shared_ptr<object::IObject> HandleContainer::resolveReference(const object::ReferenceObject *reference) {
        return this->resolveHandle(reference->handle);
    }

    std::shared_ptr<object::IObject> HandleContainer::resolveReference(const std::shared_ptr<object::ReferenceObject> &reference) {
        return this->resolveReference(reference.get());
    }
}
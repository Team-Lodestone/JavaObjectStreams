/** @file ReferenceObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_REFERENCEOBJECT_H
#define JAVAOBJECTSTREAMS_REFERENCEOBJECT_H
#include "IObject.h"

#include <cstdint>

namespace javaobject::type::object {
    struct ReferenceObject : public IObject {
        using handle_t = std::int32_t;

        explicit ReferenceObject(const handle_t handle) : handle(handle) {}

        std::string toString() override;

        handle_t handle;
    };
} // namespace javaobject::type::object

#endif // JAVAOBJECTSTREAMS_REFERENCEOBJECT_H

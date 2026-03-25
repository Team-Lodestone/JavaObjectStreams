/** @file Object.h
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
#ifndef JAVAOBJECTSTREAMS_OBJECT_H
#define JAVAOBJECTSTREAMS_OBJECT_H
#include "JavaObject/type/object/IObject.h"
#include "JavaObject/type/object/NullObject.h"

#include <memory>

namespace javaobject::type::object {
    struct Object : public IObject {
        Object(std::unique_ptr<object::IObject> &&clazz, std::unique_ptr<object::IObject> &&classData);

        std::unique_ptr<IObject> clazz;
        std::unique_ptr<IObject> classData; // todo use right type
    };
} // namespace javaobject::type::object

#endif // JAVAOBJECTSTREAMS_OBJECT_H

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
#include "IObject.h"
#include "NullObject.h"

#include <memory>

namespace javaobject::type::object {
    struct Object : public IObject {
        Object(std::shared_ptr<object::IObject> &&clazz, std::shared_ptr<object::IObject> &&classData);

        std::string toString() override;

        std::shared_ptr<IObject> clazz;
        std::shared_ptr<IObject> classData; // todo use right type
    };
} // namespace javaobject::type::object

#endif // JAVAOBJECTSTREAMS_OBJECT_H

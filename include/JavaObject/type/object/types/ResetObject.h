/** @file ResetObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/28/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_RESETOBJECT_H
#define JAVAOBJECTSTREAMS_RESETOBJECT_H
#include "JavaObject/type/object/types/IObject.h"

namespace javaobject::type::object::types {
    struct ResetObject : public IObject {
        std::string toString() override;
    };
} // namespace javaobject::type::object

#endif //JAVAOBJECTSTREAMS_RESETOBJECT_H

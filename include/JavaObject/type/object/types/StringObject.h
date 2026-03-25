/** @file StringObject.h
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
#ifndef JAVAOBJECTSTREAMS_STRINGOBJECT_H
#define JAVAOBJECTSTREAMS_STRINGOBJECT_H
#include "IObject.h"

#include <string>

namespace javaobject::type::object {
    struct StringObject : public IObject {
        explicit StringObject(const std::string &value);

        std::string value;
    };
} // namespace javaobject::type::object

#endif // JAVAOBJECTSTREAMS_STRINGOBJECT_H

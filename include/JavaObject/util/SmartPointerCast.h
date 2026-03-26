/** @file UniquePtrCast.h
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
#ifndef JAVAOBJECTSTREAMS_UNIQUEPTRCAST_H
#define JAVAOBJECTSTREAMS_UNIQUEPTRCAST_H
#include <memory>

namespace javaobject::util {
    class SmartPointerCast {
      public:
        template <typename To, typename From> static std::unique_ptr<To> staticUniquePtrCast(std::unique_ptr<From> ptr) {
            To *p = static_cast<To *>(ptr.release());

            return std::unique_ptr<To>(p);
        }
    };
} // namespace javaobject::util

#endif // JAVAOBJECTSTREAMS_UNIQUEPTRCAST_H

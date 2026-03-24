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
#ifndef JAVAOUTPUTSTREAMS_UNIQUEPTRCAST_H
#define JAVAOUTPUTSTREAMS_UNIQUEPTRCAST_H
#include <memory>

namespace javaobject {
    namespace util {
        class SmartPointerCast {
        public:
            template <typename To, typename From>
            static std::unique_ptr<To> staticUniquePtrCast(std::unique_ptr<From> ptr) {
                To *p = static_cast<To *>(ptr.release());

                return std::unique_ptr<To>(p);
            }
        };
    } // namespace util
} // namespace javaobject

#endif // JAVAOUTPUTSTREAMS_UNIQUEPTRCAST_H

/** @file AnnotationObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_ANNOTATIONOBJECT_H
#define JAVAOBJECTSTREAMS_ANNOTATIONOBJECT_H
#include "IObject.h"

#include <memory>
#include <vector>

namespace javaobject::type::object {
    struct AnnotationObject : IObject {
        explicit AnnotationObject(const std::vector<std::shared_ptr<IObject>>& contents) : contents(contents) {}

        std::vector<std::shared_ptr<IObject>> contents;
    };
} // namespace javaobject::type::object

#endif // JAVAOBJECTSTREAMS_ANNOTATIONOBJECT_H

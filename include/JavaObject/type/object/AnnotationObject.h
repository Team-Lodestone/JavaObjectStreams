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
#include "JavaObject/type/object/IObject.h"

#include <memory>

namespace javaobject::type::object {
    struct AnnotationObject : public IObject {
        AnnotationObject(std::shared_ptr<IObject> type, std::shared_ptr<IObject> value) : type(std::move(type)), value(std::move(value)) {}

        std::shared_ptr<IObject> type;
        std::shared_ptr<IObject> value; // only present if type != TC_ENDBLOCKDATA
    };
} // namespace javaobject::type::object

#endif // JAVAOBJECTSTREAMS_ANNOTATIONOBJECT_H

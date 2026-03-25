/** @file ClassDataObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_CLASSDATAOBJECT_H
#define JAVAOBJECTSTREAMS_CLASSDATAOBJECT_H
#include "JavaObject/type/object/AnnotationObject.h"
#include "JavaObject/type/object/IObject.h"

#include <cstdint>
#include <memory>
#include <unordered_map>

namespace javaobject::type::object {
    struct ClassDataObject : public IObject {};

    struct NowrClassClassDataObject : public ClassDataObject {
        std::unordered_map<std::string, std::unique_ptr<IObject>> values;
    };

    struct AnnotationClassDataObject : public ClassDataObject {
        std::unique_ptr<AnnotationObject> annotation;
    };

    struct WrClassClassDataObject : NowrClassClassDataObject, AnnotationClassDataObject {};

    struct ExternalContentsClassDataObject : ClassDataObject {
        // TODO
    };

} // namespace javaobject::type::object

#endif // JAVAOBJECTSTREAMS_CLASSDATAOBJECT_H

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
#include "AnnotationObject.h"
#include "IObject.h"
#include "JavaObject/type/primitive/types/IPrimitiveObject.h"

#include <memory>
#include <unordered_map>
#include <string>

namespace javaobject::type::object
{
    struct ClassDataObject : public IObject
    {
        std::string toString() override;
    };

    //nowrclass
    struct SerializableClassDataObject : public ClassDataObject
    {
        SerializableClassDataObject() = default;

        explicit SerializableClassDataObject(
            const std::unordered_map<std::string, std::shared_ptr<primitive::types::IPrimitiveObject>>&
            values) : values(values)
        {
        }

        std::string toString() override;

        std::unordered_map<std::string, std::shared_ptr<primitive::types::IPrimitiveObject>> values;
    };

    //wrclass, objectAnnotation
    struct SerializableWriteMethodClassDataObject : public SerializableClassDataObject
    {
        SerializableWriteMethodClassDataObject(
            const std::shared_ptr<SerializableClassDataObject>& base,
            const std::shared_ptr<AnnotationObject>& annotation)
            : SerializableClassDataObject(*base), annotation(annotation)
        {
        }

        SerializableWriteMethodClassDataObject(
            const std::unordered_map<std::string, std::shared_ptr<primitive::types::IPrimitiveObject>>& values,
            const std::shared_ptr<AnnotationObject>& annotation)
            : SerializableClassDataObject(values), annotation(annotation)
        {
        }

        std::string toString() override;

        std::shared_ptr<AnnotationObject> annotation;
    };

    //externalContents
    struct ExternalizableClassDataObject : ClassDataObject
    {
        //TODO
    };

    //objectAnnotation
    struct ExternalizableBlockDataClassDataObject : ClassDataObject
    {
        // TODO
    };
} // namespace javaobject::type::object

#endif // JAVAOBJECTSTREAMS_CLASSDATAOBJECT_H

/** @file ProxyClassDescriptorInfoObject.h
 *
 * @author DexrnZacAttack
 * @date 3/29/26
 * 
 * @device zPc-i2
 */
#ifndef JAVAOBJECTSTREAMS_PROXYCLASSDESCRIPTORINFOOBJECT_H
#define JAVAOBJECTSTREAMS_PROXYCLASSDESCRIPTORINFOOBJECT_H
#include "JavaObject/type/object/types/AnnotationObject.h"
#include "JavaObject/type/object/types/IObject.h"

#include <vector>

namespace javaobject::type::object::types::descriptor {
    class ProxyClassDescriptorInfoObject : public IObject {
    public:
        std::string toString() override;

        std::vector<std::string> m_interfaces;
        /** if nullptr, endblockdata was hit instead */
        std::shared_ptr<AnnotationObject> m_annotation;
        std::shared_ptr<IObject> m_superClassDesc;
    };
}

#endif // JAVAOBJECTSTREAMS_PROXYCLASSDESCRIPTORINFOOBJECT_H
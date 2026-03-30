/** @file ProxyClassDescriptorObject.h
 *
 * @author DexrnZacAttack
 * @date 3/29/26
 * 
 * @device zPc-i2
 */
#ifndef JAVAOBJECTSTREAMS_PROXYCLASSDESCRIPTOROBJECT_H
#define JAVAOBJECTSTREAMS_PROXYCLASSDESCRIPTOROBJECT_H
#include "JavaObject/type/object/types/IObject.h"
#include "JavaObject/type/object/types/descriptor/ProxyClassDescriptorInfoObject.h"

namespace javaobject::type::object::types::descriptor {
    class ProxyClassDescriptorObject : public IObject {
    public:
        explicit ProxyClassDescriptorObject(const std::shared_ptr<ProxyClassDescriptorInfoObject> &info)
            : info(info) {
        }

        std::string toString() override;

        std::shared_ptr<ProxyClassDescriptorInfoObject> info;
    };
}

#endif // JAVAOBJECTSTREAMS_PROXYCLASSDESCRIPTOROBJECT_H
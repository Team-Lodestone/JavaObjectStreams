/** @file ObjectParser.cpp
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
#include "JavaObject/type/object/parsers/ObjectParser.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/object/parsers/ClassDataParser.h"
#include "JavaObject/type/object/types/NullObject.h"
#include "JavaObject/type/object/types/Object.h"
#include "JavaObject/type/object/types/descriptor/NewClassDescriptorObject.h"
#include "JavaObject/type/object/types/descriptor/ProxyClassDescriptorObject.h"

namespace javaobject::type::object::parsers {
    std::shared_ptr<object::IObject> ObjectParser::operator()(type::object::ObjectTypeCodeParser &parser) const {
        std::shared_ptr<object::Object> obj = std::make_shared<Object>(std::make_shared<NullObject>(), std::make_shared<NullObject>());

        obj->clazz = parser.readNext();
        parser.handleContainer().registerHandle(obj);

        // TODO we can implement common interface between proxy and non proxy class object with getters
        // TODO this really needs a cleanup
        if (auto c = std::dynamic_pointer_cast<descriptor::NewClassDescriptorObject>(obj->clazz)) {
            obj->classData = ClassDataParser(c->info)(parser);
        } else if (auto c = std::dynamic_pointer_cast<types::descriptor::ProxyClassDescriptorObject>(obj->clazz)) {
            if (auto ci = std::dynamic_pointer_cast<descriptor::NewClassDescriptorObject>(c->info->m_superClassDesc))
                obj->classData = ClassDataParser(ci->info)(parser);
        }

        return obj;
    }
} // namespace javaobject::type::object::parsers
/** @file ClassDataParser.h
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_CLASSDATAPARSER_H
#define JAVAOBJECTSTREAMS_CLASSDATAPARSER_H
#include "../types/ClassDataObject.h"
#include "JavaObject/type/object/parsers/IObjectParser.h"

#include <functional>

#include "JavaObject/type/object/types/descriptor/ClassDescriptorInfoObject.h"

namespace javaobject::type::object::parsers {
    struct ClassDataParser : public IObjectParser {
        explicit ClassDataParser(const std::shared_ptr<object::descriptor::ClassDescriptorInfoObject> &classDescInfo);

        std::shared_ptr<object::IObject> operator()(type::object::ObjectTypeCodeParser &parser) const override;

        std::shared_ptr<object::SerializableClassDataObject> parseSerializableClassData(type::object::ObjectTypeCodeParser &parser) const;
        std::shared_ptr<object::SerializableWriteMethodClassDataObject> parseSerializableWriteMethodClassData(type::object::ObjectTypeCodeParser &parser) const;
        std::shared_ptr<object::ExternalizableClassDataObject> parseExternalizableClassData(type::object::ObjectTypeCodeParser &parser) const;
        std::shared_ptr<object::ExternalizableBlockDataClassDataObject> parseExternalizableBlockDataClassData(type::object::ObjectTypeCodeParser &parser) const;

      private:
        const std::shared_ptr<object::descriptor::ClassDescriptorInfoObject> m_classDescInfo;
    };
} // namespace javaobject::type::object::parsers

#endif // JAVAOBJECTSTREAMS_CLASSDATAPARSER_H

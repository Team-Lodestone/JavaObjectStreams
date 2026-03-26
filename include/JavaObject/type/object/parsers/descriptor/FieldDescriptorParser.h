/** @file FieldDescriptorParser.h
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
#ifndef JAVAOBJECTSTREAMS_FIELDDESCRIPTORPARSER_H
#define JAVAOBJECTSTREAMS_FIELDDESCRIPTORPARSER_H
#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/object/parsers/IObjectParser.h"

namespace javaobject::type::object::parsers::descriptor {
    class FieldDescriptorParser : public IObjectParser {
      public:
        std::shared_ptr<object::IObject>
        operator()(type::object::ObjectTypeCodeParser &parser) const override;
    };
} // namespace javaobject::type::object::parsers::descriptor

#endif // JAVAOBJECTSTREAMS_FIELDDESCRIPTORPARSER_H

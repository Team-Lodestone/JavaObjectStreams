/** @file IObjectParser.h
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
#ifndef JAVAOBJECTSTREAMS_IOBJECTPARSER_H
#define JAVAOBJECTSTREAMS_IOBJECTPARSER_H
#include "JavaObject/type/object/types/IObject.h"

#include <memory>

namespace javaobject::type::object {
    class ObjectTypeCodeParser;
}

namespace javaobject::type::object::parsers {
    class IObjectParser {
      public:
        virtual ~IObjectParser() = default;

        virtual std::shared_ptr<object::IObject> operator()(type::object::ObjectTypeCodeParser &parser) const = 0;
    };
} // namespace javaobject::type::object::parsers

#endif // JAVAOBJECTSTREAMS_IOBJECTPARSER_H

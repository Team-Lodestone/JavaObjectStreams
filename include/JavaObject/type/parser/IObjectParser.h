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
#include "JavaObject/type/object/IObject.h"

#include <memory>

namespace javaobject::type {
    class TypeCodeParser;
}
namespace javaobject::type::parser {
    class IObjectParser {
      public:
        virtual ~IObjectParser() = default;

        virtual std::unique_ptr<object::IObject> operator()(TypeCodeParser &parser) const = 0;
    };
} // namespace javaobject::type::parser

#endif // JAVAOBJECTSTREAMS_IOBJECTPARSER_H

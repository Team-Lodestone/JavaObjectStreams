/** @file PrimitiveArrayObjectParser.cpp
 *
 * @author Zero_DSRS_VX
 * @date 3/25/26
 *
 * @device mac-8
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the LGPL 3.0 license, see the LICENSE file for details.
 */
#include "JavaObject/type/primitive/parsers/PrimitiveArrayObjectParser.h"

#include "JavaObject/type/object/ObjectTypeCodeParser.h"
#include "JavaObject/type/primitive/PrimitiveTypeCodeParser.h"
#include "JavaObject/type/primitive/types/PrimitiveArrayObject.h"
#include "JavaObject/type/primitive/types/PrimitiveJavaObject.h"

namespace javaobject::type::primitive::parsers {
    std::shared_ptr<types::IPrimitiveObject> PrimitiveArrayObjectParser::operator()(PrimitiveTypeCodeParser &parser) const {
        return std::make_shared<types::PrimitiveJavaObject>(parser.parserStorage().objectParser->readNext());
    }
} // namespace javaobject::type::primitive::parsers
/** @file PrimitiveJavaObjectParser.h
*
* @author Zero_DSRS_VX
* @author Dexrn ZacAttack
*
* @date 3/25/26
*
* @device mac-8
*
* @copyright Copyright (c) 2026 Team Lodestone
* @license This project is licensed under the LGPL 3.0 license, see the LICENSE file for details.
*/
#ifndef JAVAOBJECTSTREAMS_PRIMITIVEJAVAOBJECTPARSER_H
#define JAVAOBJECTSTREAMS_PRIMITIVEJAVAOBJECTPARSER_H
#include "IPrimitiveObjectParser.h"

namespace javaobject::type::primitive::parsers {
    struct PrimitiveJavaObjectParser : IPrimitiveObjectParser {
        std::shared_ptr<types::IPrimitiveObject> operator()(PrimitiveTypeCodeParser &parser) const override;
    };
}

#endif //JAVAOBJECTSTREAMS_PRIMITIVEJAVAOBJECTPARSER_H

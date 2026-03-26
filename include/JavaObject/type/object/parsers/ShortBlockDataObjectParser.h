/** @file BlockDataObjectParser.h
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_BLOCKDATAOBJECTPARSER_H
#define JAVAOBJECTSTREAMS_BLOCKDATAOBJECTPARSER_H
#include "IObjectParser.h"

namespace javaobject::type::object::parsers {
    struct ShortBlockDataObjectParser : IObjectParser {
        std::shared_ptr<object::IObject> operator()(type::object::ObjectTypeCodeParser& parser) const override;
    };
}

#endif //JAVAOBJECTSTREAMS_BLOCKDATAOBJECTPARSER_H

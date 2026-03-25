/** @file NewClassDescriptorParser.h
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
#ifndef JAVAOBJECTSTREAMS_NEWCLASSDESCRIPTORPARSER_H
#define JAVAOBJECTSTREAMS_NEWCLASSDESCRIPTORPARSER_H
#include "JavaObject/type/parser/IObjectParser.h"

namespace javaobject::type::parser::descriptor {

    class NewClassDescriptorParser : public IObjectParser {
      public:
        std::unique_ptr<object::IObject>
        operator()(TypeCodeParser &parser) const override;
    };

} // namespace javaobject::type::parser::descriptor

#endif // JAVAOBJECTSTREAMS_CLASSDESCRIPTORPARSER_H

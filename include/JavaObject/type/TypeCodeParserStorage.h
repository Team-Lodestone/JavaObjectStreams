/** @file TypeCodeParserStorage.h
*
* @author Zero_DSRS_VX
* @date 3/25/26
*
* @device mac-8
*
* @copyright Copyright (c) 2026 Team Lodestone
* @license This project is licensed under the LGPL 3.0 license, see the LICENSE file for details.
*/
#ifndef JAVAOBJECTSTREAMS_TYPECODESTORAGE_H
#define JAVAOBJECTSTREAMS_TYPECODESTORAGE_H
#include <memory>


namespace javaobject::type {
    namespace object {
        class ObjectTypeCodeParser;
    }

    namespace primitive {
        class PrimitiveTypeCodeParser;
    }

    struct TypeCodeParserStorage {
        std::shared_ptr<primitive::PrimitiveTypeCodeParser> primitiveParser;
        std::shared_ptr<object::ObjectTypeCodeParser> objectParser;
    };
}

#endif //JAVAOBJECTSTREAMS_TYPECODESTORAGE_H

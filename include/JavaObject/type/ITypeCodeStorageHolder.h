/** @file ITypeCodeStorageHolder.h
*
* @author Zero_DSRS_VX
* @date 3/25/26
*
* @device mac-8
*
* @copyright Copyright (c) 2026 Team Lodestone
* @license This project is licensed under the LGPL 3.0 license, see the LICENSE file for details.
*/
#ifndef PROJECTLODESTONE_ITYPECODESTORAGEHOLDER_H
#define PROJECTLODESTONE_ITYPECODESTORAGEHOLDER_H
#include "TypeCodeParserStorage.h"

namespace javaobject::type {
    class ITypeCodeStorageHolder {
    public:
        explicit ITypeCodeStorageHolder(TypeCodeParserStorage &parserStorage);

        TypeCodeParserStorage &parserStorage();

    protected:
        TypeCodeParserStorage &m_parserStorage;
    };
}

#endif //PROJECTLODESTONE_ITYPECODESTORAGEHOLDER_H

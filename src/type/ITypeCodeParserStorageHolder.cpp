/** @file ITypeCodeStorageHolder.cpp
*
* @author Zero_DSRS_VX
* @date 3/25/26
*
* @device mac-8
*
* @copyright Copyright (c) 2026 Team Lodestone
* @license This project is licensed under the LGPL 3.0 license, see the LICENSE file for details.
*/
#include "JavaObject/type/ITypeCodeParserStorageHolder.h"

namespace javaobject::type {
    ITypeCodeParserStorageHolder::ITypeCodeParserStorageHolder(TypeCodeParserStorage &parserStorage) : m_parserStorage(parserStorage) {}

    TypeCodeParserStorage &ITypeCodeParserStorageHolder::parserStorage() {
        return this->m_parserStorage;
    }
} // javaobject::type
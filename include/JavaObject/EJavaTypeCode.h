/** @file EJavaTypeCode.h
 *
 * @author DexrnZacAttack
 * @date 3/23/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_EJAVATYPECODE_H
#define JAVAOBJECTSTREAMS_EJAVATYPECODE_H

enum EJavaTypeCode : signed char {
    TC_NULL = 0x70,
    TC_REFERENCE = 0x71,
    TC_CLASSDESC = 0x72,
    TC_OBJECT = 0x73,
    TC_STRING = 0x74,
    TC_ARRAY = 0x75,
    TC_CLASS = 0x76,
    TC_BLOCKDATA = 0x77,
    TC_ENDBLOCKDATA = 0x78,
    TC_RESET = 0x79,
    TC_BLOCKDATALONG = 0x7a,
    TC_EXCEPTION = 0x7B,
    TC_LONGSTRING = 0x7C,
    TC_PROXYCLASSDESC = 0x7D,
    TC_ENUM = 0x7E,

    TC_BASE = TC_NULL, // lowest value
    TC_MAX = TC_ENUM // highest value
};

#endif // JAVAOBJECTSTREAMS_EJAVATYPECODE_H

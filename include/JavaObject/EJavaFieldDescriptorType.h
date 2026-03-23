/** @file EJavaFieldDescriptorType.h
 *
 * @author DexrnZacAttack
 * @date 3/23/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_EJAVAFIELDDESCRIPTORTYPE_H
#define JAVAOBJECTSTREAMS_EJAVAFIELDDESCRIPTORTYPE_H

enum EJavaFieldDescriptorType : signed char {
  TYPE_BYTE = 'B',
  TYPE_CHARACTER = 'C',
  TYPE_DOUBLE = 'D',
  TYPE_FLOAT = 'F',
  TYPE_INT = 'I',
  TYPE_LONG = 'J',
  TYPE_OBJECT = 'L',
  TYPE_SHORT = 'S',
  TYPE_BOOLEAN = 'Z',
  TYPE_ARRAY = '['
};

#endif // JAVAOBJECTSTREAMS_EJAVAFIELDDESCRIPTORTYPE_H
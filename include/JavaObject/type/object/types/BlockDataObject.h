/** @file BlockDataObject.h
 *
 * @author Dexrn ZacAttack
 * @date 3/25/26
 * 
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_BLOCKDATAOBJECT_H
#define JAVAOBJECTSTREAMS_BLOCKDATAOBJECT_H
#include <cstdint>
#include <vector>

#include "IObject.h"

namespace javaobject::type::object::parsers {
    struct BlockDataObject : IObject {
        explicit BlockDataObject(const std::vector<std::int8_t>& data)
            : data(data) {
        }

        std::string toString() override;

        std::vector<std::int8_t> data;
    };
}

#endif //JAVAOBJECTSTREAMS_BLOCKDATAOBJECT_H

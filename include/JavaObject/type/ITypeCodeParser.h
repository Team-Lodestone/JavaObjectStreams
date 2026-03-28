/** @file ITypeCodeParser.h
 *
 * @author Dexrn ZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 *
 * @copyright Copyright (c) 2026 Team Lodestone
 * @license This project is licensed under the MIT license, see the LICENSE file for details.
 */
#ifndef JAVAOBJECTSTREAMS_ITYPECODEPARSER_H
#define JAVAOBJECTSTREAMS_ITYPECODEPARSER_H
#include "BinaryIO/stream/BinaryInputStream.h"
#include "JavaObject/type/HandleContainer.h"

namespace javaobject::type {
    template <typename ObjectT, typename ParserT, typename TypeCodeT>
    class ITypeCodeParser {
    public:
        explicit ITypeCodeParser(std::istream &input, HandleContainer &handleContainer) : m_input(input), m_handleContainer(handleContainer) {}

        virtual ~ITypeCodeParser() = default;

        virtual std::shared_ptr<ObjectT> readNext() = 0;
        virtual std::shared_ptr<ObjectT> readUsingParser(const ParserT &parser) = 0;
        virtual std::shared_ptr<ObjectT> readUsingTypeCode(const TypeCodeT &typecode) = 0;

        template <typename T>
        requires std::is_base_of_v<ObjectT, T>
        std::shared_ptr<T> readNextAs() {
            return std::static_pointer_cast<T>(this->readNext());
        }
        
        template <typename T>
        requires std::is_base_of_v<ObjectT, T>
        std::shared_ptr<T> readAsUsingParser(const ParserT &parser) {
            return std::static_pointer_cast<T>(this->readUsingParser(parser));
        }

        ParserT *getParser(const TypeCodeT typeCode) {
            if (const auto it = m_parsers.find(typeCode); it != this->m_parsers.end()) {
                return it->second.get();
            }

            return nullptr;
        }

        HandleContainer &handleContainer() {
            return this->m_handleContainer;
        }

        bio::stream::BinaryInputStream &stream() {
            return this->m_input;
        }

    protected:
        /** Links typecodes to their parser class */
        std::unordered_map<TypeCodeT, std::unique_ptr<ParserT>> m_parsers;

        bio::stream::BinaryInputStream m_input;
        HandleContainer &m_handleContainer;
    };
} // namespace javaobject::type

#endif // JAVAOBJECTSTREAMS_ITYPECODEPARSER_H

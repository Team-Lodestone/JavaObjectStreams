/** @file TypeCode.h
 *
 * @author DexrnZacAttack
 * @date 3/24/26
 *
 * @device zPc-i2
 */
#ifndef JAVAOBJECTSTREAMS_TYPECODE_H
#define JAVAOBJECTSTREAMS_TYPECODE_H
#include "BinaryIO/stream/BinaryInputStream.h"
#include "JavaObject/EObjectTypeCode.h"
#include "JavaObject/type/object/ReferenceObject.h"
#include "JavaObject/type/parser/IObjectParser.h"
#include "JavaObject/type/parser/ReferenceParser.h"
#include "JavaObject/util/SmartPointerCast.h"

#include <functional>
#include <iosfwd>
#include <memory>
#include <unordered_map>
#include <variant>

namespace javaobject::type {
    class TypeCodeParser {
    public:
        explicit TypeCodeParser(std::istream &input);

        std::shared_ptr<object::IObject> readNext();

        template <typename T>
        requires std::is_base_of_v<object::IObject, T>
        std::shared_ptr<T> readNextAs() {
            return std::static_pointer_cast<T>(this->readNext());
        }

        std::shared_ptr<object::IObject> readUsingParser(const parser::IObjectParser &parser);

        template <typename T>
        requires std::is_base_of_v<object::IObject, T>
        std::shared_ptr<T> readAsUsingParser(const parser::IObjectParser &parser) {
            return std::static_pointer_cast<T>(this->readUsingParser(parser));
        }

        parser::IObjectParser *getParser(const EObjectTypeCode typeCode);

        void registerHandle(std::shared_ptr<object::IObject> object);
        std::shared_ptr<object::IObject> resolveHandle(const object::ReferenceObject::handle_t handle);
        std::shared_ptr<object::IObject> resolveReference(const object::ReferenceObject *reference);

        bio::stream::BinaryInputStream &stream();
    private:
        //todo should they be shared_ptr????
        // sounds like big change but if needed im fine with it.
        /** Links handles to objects by pointer, these objects are expected to be stored already, otherwise it would leave a dangling/invalid pointer. */
        std::unordered_map<object::ReferenceObject::handle_t, std::shared_ptr<object::IObject>> m_handles;
        object::ReferenceObject::handle_t m_nextHandle = 0x7E000000;

        /** Links typecodes to their parser class */
        std::unordered_map<EObjectTypeCode, std::unique_ptr<parser::IObjectParser>> m_parsers;

        bio::stream::BinaryInputStream m_input;
    };
} // namespace javaobject::type

#endif // JAVAOBJECTSTREAMS_TYPECODE_H
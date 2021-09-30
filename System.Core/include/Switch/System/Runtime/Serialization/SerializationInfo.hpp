/// @file
/// @brief Contains Switch::System::Runtime::Serialization::SerializationInfo class.
#pragma once

#include "../../../Types.hpp"
#include "../../../RefPtr.hpp"
#include "../../Boolean.hpp"
#include "../../Byte.hpp"
#include "../../Char.hpp"
#include "../../DateTime.hpp"
#include "../../Decimal.hpp"
#include "../../Double.hpp"
#include "../../Int16.hpp"
#include "../../Int32.hpp"
#include "../../Int64.hpp"
#include "../../Object.hpp"
#include "../../SByte.hpp"
#include "../../Single.hpp"
#include "../../String.hpp"
#include "../../UInt16.hpp"
#include "../../UInt32.hpp"
#include "../../UInt64.hpp"
#include "../../Collections/Generic/KeyValuePair.hpp"
#include "../../Collections/Generic/Dictionary.hpp"
#include "SerializationEntry.hpp"
#include "SerializationException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Runtime namespaces contain types that support an application's interaction with the common language runtime, and types that enable features such as application data caching, advanced exception handling, application activation within application domains, COM interop, distributed applications, serialization and deserialization, and versioning.
    namespace Runtime {
      /// @brief The System::Runtime::Serialization namespace contains classes that can be used for serializing and deserializing objects. Serialization is the process of converting an object or a graph of objects into a linear sequence of bytes for either storage or transmission to another location. Deserialization is the process of taking in stored information and recreating objects from it.
      /// The ISerializable interface provides a way for classes to control their own serialization behavior. Classes in the System::Runtime::Serialization::Formatters namespace control the actual formatting of various data types encapsulated in the serialized objects.
      /// Formatters that serialize and deserialize objects to and from a particular format can be found in the System::Runtime::Serialization::Formatters namespace.
      namespace Serialization {
        /// @cond
        class ISerializable;
        /// @endcond

        /// @brief Provides functionality for formatting serialized objects.
        class core_export_ SerializationInfo : public Object, public System::Collections::Generic::IEnumerable<System::Collections::Generic::KeyValuePair<System::String, SerializationEntry>> {
        public:
          /// @brief Initializes a new instance of the SerializationInfo interface.
          SerializationInfo() {}

          /// @brief Initializes a new instance of the SerializationInfo interface.
          SerializationInfo(const String& objectType) : objectType(objectType) {}


          /// @brief Adds a String value into the SerializationInfo store.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The String value to serialize.
          /// @exception ArgumentNullException name is null
          void AddValue(const String& name, const String& value);

          /// @brief Adds a Boolean value into the SerializationInfo store.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The Boolean value to serialize.
          /// @exception ArgumentNullException name is null
          void AddValue(const String& name, const Boolean& value);

          /// @brief Adds a Byte value into the SerializationInfo store.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The Byte value to serialize.
          /// @exception ArgumentNullException name is null
          void AddValue(const String& name, const Byte& value);

          /// @brief Adds a SByte value into the SerializationInfo store.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The SByte value to serialize.
          /// @exception ArgumentNullException name is null
          void AddValue(const String& name, const SByte& value);

          /// @brief Adds a Char value into the SerializationInfo store.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The Char value to serialize.
          /// @exception ArgumentNullException name is null
          void AddValue(const String& name, const Char& value);

          /// @brief Adds a DateTime value into the SerializationInfo store.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The DateTime value to serialize.
          /// @exception ArgumentNullException name is null
          void AddValue(const String& name, const DateTime& value);

          /// @brief Adds a Double value into the SerializationInfo store.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The Double value to serialize.
          /// @exception ArgumentNullException name is null
          void AddValue(const String& name, const Double& value);

          /// @brief Adds a Single value into the SerializationInfo store.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The Single value to serialize.
          /// @exception ArgumentNullException name is null
          void AddValue(const String& name, const Single& value);

          /// @brief Adds a Int16 value into the SerializationInfo store.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The Int16 value to serialize.
          /// @exception ArgumentNullException name is null
          void AddValue(const String& name, const Int16& value);

          /// @brief Adds a Int32 value into the SerializationInfo store.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The Int32 value to serialize.
          /// @exception ArgumentNullException name is null
          void AddValue(const String& name, const Int32& value);

          /// @brief Adds a Int64 value into the SerializationInfo store.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The Int64 value to serialize.
          /// @exception ArgumentNullException name is null
          void AddValue(const String& name, const Int64& value);

          /// @brief Adds a UInt16 value into the SerializationInfo store.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The UInt16 value to serialize.
          /// @exception ArgumentNullException name is null
          void AddValue(const String& name, const UInt16& value);

          /// @brief Adds a UInt32 value into the SerializationInfo store.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The UInt32 value to serialize.
          /// @exception ArgumentNullException name is null
          void AddValue(const String& name, const UInt32& value);

          /// @brief Adds a UInt64 value into the SerializationInfo store.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The UInt64 value to serialize.
          /// @exception ArgumentNullException name is null
          void AddValue(const String& name, const UInt64& value);

          /// @brief Adds the specified ISerializable object into the SerializationInfo store, where it is associated with a specified name.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The value to be serialized. Any children of this object will automatically be serialized.
          /// @exception ArgumentNullException name or value is null
          /// @exception NotSupportedException value is not a ValueType or ISerializable.
          void AddValue(const String& name, const ISerializable& value, const String& typeName);

          /// @brief Adds the specified ISerializable object into the SerializationInfo store, where it is associated with a specified name.
          /// @param name The name to associate with the value, so it can be deserialized later.
          /// @param value The value to be serialized. Any children of this object will automatically be serialized.
          /// @exception ArgumentNullException name or value is null
          /// @exception NotSupportedException value is not a ValueType or ISerializable.
          void AddValue(const String& name, const ISerializable& value);

          void AddValue(const String& name, bool value);
          void AddValue(const String& name, byte value);
          void AddValue(const String& name, int16 value);
          void AddValue(const String& name, int32 value);
          void AddValue(const String& name, int64 value);
          void AddValue(const String& name, sbyte value);
          void AddValue(const String& name, float value);
          void AddValue(const String& name, double value);
          void AddValue(const String& name, uint16 value);
          void AddValue(const String& name, uint32 value);
          void AddValue(const String& name, char32 value);
          template<typename T>
          void AddValue(const String& name, const System::Collections::Generic::IEnumerable<T>& value) {
            AddValue(name, refptr<object>(new Array<T>(value)), "System::Collections::Generic::IEnumerable");
          }

          System::Collections::Generic::Enumerator<System::Collections::Generic::KeyValuePair<System::String, SerializationEntry>> GetEnumerator() const;

          bool GetBoolean(const String& name) const;
          byte GetByte(const String& name) const;
          sbyte GetSByte(const String& name) const;
          int16 GetInt16(const String& name) const;
          int32 GetInt32(const String& name) const;
          int64 GetInt64(const String& name) const;
          uint16 GetUInt16(const String& name) const;
          uint32 GetUInt32(const String& name) const;
          uint64 GetUInt64(const String& name) const;
          char32 GetChar32(const String& name) const;
          float GetSingle(const String& name) const;
          double GetDouble(const String& name) const;

          String GetString(const String& name) const;

          const Object& GetObject(const String& name) const;

          template<typename T>
          refptr<T> GetValue(const String& name) const {
            const SerializationEntry& entry = mItems[name];
            if (is<System::Runtime::Serialization::SerializationInfo>(entry.Value().ToObject()))
              return T::Deserialize(as<System::Runtime::Serialization::SerializationInfo>(entry.Value()).ToObject());
            else
              throw System::Runtime::Serialization::SerializationException(caller_);
          }

          const String& GetObjectType() const { return this->objectType; }

          void SetObjectType(const String& objectType) { this->objectType = objectType; }

          int32 GetMemberCount() { return mItems.Count; }

        private:
          void AddValue(const String& name, refptr<Object> value, const String& typeName);
          String objectType;
          System::Collections::Generic::Dictionary<String, SerializationEntry> mItems;
        };

        template<> refptr<System::Boolean>
        SerializationInfo::GetValue<System::Boolean>(const String& name) const;

        template<> refptr<String>
        SerializationInfo::GetValue<String>(const String& name) const;

        template<> refptr<System::Byte>
        SerializationInfo::GetValue<System::Byte>(const String& name) const;

        template<> refptr<System::SByte>
        SerializationInfo::GetValue<System::SByte>(const String& name) const;

        template<> refptr<System::Char>
        SerializationInfo::GetValue<System::Char>(const String& name) const;

        template<> refptr<System::DateTime>
        SerializationInfo::GetValue<System::DateTime>(const String& name) const;

        template<> refptr<System::Single>
        SerializationInfo::GetValue<System::Single>(const String& name) const;

        template<> refptr<System::Double>
        SerializationInfo::GetValue<System::Double>(const String& name) const;

        template<> refptr<System::Int16>
        SerializationInfo::GetValue<System::Int16>(const String& name) const;

        template<> refptr<System::Int32>
        SerializationInfo::GetValue<System::Int32>(const String& name) const;

        template<> refptr<System::Int64>
        SerializationInfo::GetValue<System::Int64>(const String& name) const;

        template<> refptr<System::UInt16>
        SerializationInfo::GetValue<System::UInt16>(const String& name) const;

        template<> refptr<System::UInt32>
        SerializationInfo::GetValue<System::UInt32>(const String& name) const;

        template<> refptr<System::UInt64>
        SerializationInfo::GetValue<System::UInt64>(const String& name) const;
      }
    }
  }
}

using namespace Switch;


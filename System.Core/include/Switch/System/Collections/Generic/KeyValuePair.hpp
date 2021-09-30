/// @file
/// @brief Contains Switch::System::Collections::Generic::KeyValuePair <TKey, TValue> class.
#pragma once

#include "../../../Property.hpp"
#include "../../../Is.hpp"
#include "../../../NullPtr.hpp"
#include "../../../Types.hpp"
#include "../../Object.hpp"
#include "../../_String.hpp"
#include "../../ArgumentNullException.hpp"
#include "../../Type.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @cond
        template<typename TKey = NullPtr, typename TValue = NullPtr>
        class KeyValuePair;
        /// @endcond

        /// @brief Defines a key/value pair that can be set or retrieved.
        template<typename TKey, typename TValue>
        class KeyValuePair : public Object {
        public:
          /// @brief Initializes a new instance of the KeyValuePair<TKey, TValue> class with the specified key and value.
          /// @param Key The object defined in each key/value pair
          /// @param value The definition associated with key
          KeyValuePair(const TKey& key, const TValue& value) : pair(std::make_pair(key, value)) {}

          /// @cond
          KeyValuePair() {}
          KeyValuePair(const KeyValuePair& keyValuePair) : pair(keyValuePair.pair) {}
          KeyValuePair(const std::pair<TKey, TValue>& pair) : pair(pair) {}
          operator std::pair<TKey, TValue>() const {return this->pair;}
          /// @endcond

          /// @brief Gets the key in the key/value pair.
          /// @return TKey A TKey that is the key of the KeyValuePair<TKey, TValue>.
          property_<const TKey&, readonly_> Key {
            get_->const TKey& {return this->pair.first;}
          };

          /// @brief Gets the value in the key/value pair.
          /// @return TValue A TValue that is the value of the KeyValuePair<TKey, TValue>.
          property_<const TValue&, readonly_> Value {
            get_->const TValue& {return this->pair.second;}
          };

          /// @brief Returns a String representation of the KeyValuePair<TKey, TValue>, using the String representations of the key and value.
          /// @return const String A String representation of the KeyValuePair<TKey, TValue>, which includes the String representations of the key and value.
          /// @return String
          String ToString() const override {return String::Format("[{0}, {1}]", this->pair.first, this->pair.second);}

          bool Equals(const KeyValuePair& value) const {return this->pair == value.pair;}

          bool Equals(const Object& obj) const override {return is<KeyValuePair>(obj) && Equals(static_cast<const KeyValuePair&>(obj));}

        private:
          std::pair<TKey, TValue> pair;
        };

        /// @brief Defines a key/value pair that can be set or retrieved.
        template<>
        class KeyValuePair<> : public object {
        public:
          template<typename TKey, typename TValue>
          static KeyValuePair<TKey, TValue> Create(TKey key, TValue value) {return KeyValuePair<TKey, TValue>(key, value);}

        private:
          KeyValuePair() = delete;
        };
      }
    }
  }
}

using namespace Switch;

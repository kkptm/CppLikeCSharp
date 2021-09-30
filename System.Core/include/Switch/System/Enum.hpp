/// @file
/// @brief Contains Switch::System::Enum class.
#pragma once

#include <map>
#include "../Lock.hpp"
#include "../Types.hpp"
#include "FormatException.hpp"
#include "Type.hpp"
#include "Collections/Generic/IDictionary.hpp"
#include "Collections/Generic/KeyValuePair.hpp"
#include "Array.hpp"
#include "Int64.hpp"
#include "_String.hpp"

namespace Switch {
  using FalseType = std::false_type;
  using TrueType = std::true_type;
}

/// @cond
template<typename T>
struct EnumRegister {
  void operator()(System::Collections::Generic::IDictionary<T, string>& values, bool& flags) {}
};

template <typename T, bool = std::is_enum<T>::value>
class AddFlagOperators;

template <typename T>
class AddFlagOperators<T, true> : public FalseType { };

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T & operator+=(T& lhs, T rhs) {
  lhs = static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) + static_cast<typename std::underlying_type<T>::type>(rhs));
  return lhs;
}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T & operator-=(T& lhs, T rhs) {
  lhs = static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) - static_cast<typename std::underlying_type<T>::type>(rhs));
  return lhs;
}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T & operator &=(T& lhs, T rhs) {
  lhs = static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) & static_cast<typename std::underlying_type<T>::type>(rhs));
  return lhs;
}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T & operator |=(T& lhs, T rhs) {
  lhs = static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) | static_cast<typename std::underlying_type<T>::type>(rhs));
  return lhs;
}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T & operator ^=(T& lhs, T rhs) {
  lhs = static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) ^ static_cast<typename std::underlying_type<T>::type>(rhs));
  return lhs;
}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T operator+(T lhs, T rhs) {return static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) + static_cast<typename std::underlying_type<T>::type>(rhs));}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T operator-(T lhs, T rhs) {return static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) - static_cast<typename std::underlying_type<T>::type>(rhs));}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T operator &(T lhs, T rhs) {return static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) & static_cast<typename std::underlying_type<T>::type>(rhs));}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T operator |(T lhs, T rhs) {return static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) | static_cast<typename std::underlying_type<T>::type>(rhs));}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T operator ^(T lhs, T rhs) {return static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) ^ static_cast<typename std::underlying_type<T>::type>(rhs));}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T operator ~(T rhs) {return static_cast<T>(~static_cast<typename std::underlying_type<T>::type>(rhs));}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Provides the base class for enumerations.
    template<typename T = NullPtr>
    class Enum : public object, public System::IComparable {
    public:
      /// @brief Initializes a new instance of the Enum class.
      Enum() {}

      /// @cond
      Enum(T value) : value(value) {}
      Enum(const Enum& value) : value(value.value) {}
      Enum(Enum&& value) : value(Move(value.value)) {}
      Enum& operator=(const Enum& value) {
        this->value = value.value;
        return *this;
      }
      /// @endcond

      /// @brief Compares this instance to a specified Enum object and returns an indication of their relative values.
      /// @param value An Int32 object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// @return Less than zero      This instance is less than value.
      /// @return Zero                This instance is equal to value.
      /// @return Greater than zero   This instance is greater than value.
      int32 CompareTo(const Enum& value) const {
        if ((int64)this->value < (int64)value.value) return -1;
        if ((int64)this->value == (int64)value.value) return 0;
        return 1;
      }

      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// @return Less than zero      This instance is less than value.
      /// @return Zero                This instance is equal to value.
      /// @return Greater than zero   This instance is greater than value.
      /// -or-
      /// @return obj is nullNothingnullptra null reference.
      int32 CompareTo(const System::IComparable& obj) const override {return is<Enum<T>>(obj) && this->CompareTo((Enum<T>&)obj);}

      /// @brief Determines whether two specified DateTime objects have the same value.
      /// @param dateTimeA The first DateTime to compare.
      /// @param dateTimeB The second DateTime to compare.
      /// @return Boolean true if the value of dateTimenA is the same as the value of dateTimeB; otherwise, false.
      bool Equals(T value) const {return this->value == value;}

      /// @cond
      bool Equals(const Enum& value) const {return this->value == value.value;}

      template<typename TT>
      bool Equals(TT value) const {return false;}
      /// @endcond

      /// @brief Determines whether this instance of Exception and a specified object, which must also be a Exception object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const object& obj) const override {return is<Enum<T>>(obj) && Equals(((const Enum&)obj).value);}

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current object.
      int32 GetHashCode() const override {return System::Int64((int64)this->value).GetHashCode();}

      /// @brief Retrieves an array of the values of the constants in a specified enumeration.
      /// @param flag An enumeration value.
      /// @return Boolean true if the bit field or bit fields that are set in flag are also set in the current instance; otherwise, false.
      /// @remarks The HasFlag method returns the result of the following Boolean expression : thisInstance And flag = flag
      bool HasFlag(T flag) const {return ((int64)this->value & (int64)flag) == (int64)flag;}

      /// @brief Returns a String that represents the current Int32.
      /// @return String A String that represents the current Int32.
      string ToString() const override {
        Values();
        if (flags)
          return ToStringFlags();

        if (!Values().ContainsKey(this->value))
          return string::Format("{0}", int64(this->value));

        return Values()[this->value];
      }

    private:
      friend class Enum<NullPtr>;

      class ValuesDictionary : public Object,  public System::Collections::Generic::IDictionary<T, string> {
        using Item = System::Collections::Generic::KeyValuePair<T, string>;
      public:
        using KeyCollection = typename System::Collections::Generic::IDictionary<T, string>::KeyCollection;
        using ValueCollection = typename System::Collections::Generic::IDictionary<T, string>::ValueCollection;

        ValuesDictionary() : operationNumber(0), comparer(new System::Collections::Generic::Comparer<T>()), map(MapComparer(*this->comparer)) {}
        ValuesDictionary(const ValuesDictionary& dictionary) : operationNumber(dictionary.operationNumber), comparer(dictionary.comparer), map(MapComparer(*this->comparer)) {
          for (const auto& item : dictionary)
            Add(item);
        }
        ValuesDictionary(InitializerList<System::Collections::Generic::KeyValuePair<T, string>> il) : operationNumber(0), comparer(new System::Collections::Generic::Comparer<T>()), map(MapComparer(*this->comparer)) {
          for (typename InitializerList<Item>::const_iterator iterator = il.begin(); iterator != il.end(); ++iterator)
            this->Add(*iterator);
        }

        void Add(const System::Collections::Generic::KeyValuePair<T, string>& keyValue) override {Add(keyValue.Key(), keyValue.Value());}
        void Add(const T& key, const string& value) override {
          if (ContainsKey(key))
            throw System::ArgumentException(caller_);
          (*this)[key] = value;
        }

        void Clear() override {this->map.clear();}

        virtual bool Contains(const System::Collections::Generic::KeyValuePair<T, string>& keyValue) const override {
          if (!ContainsKey(keyValue.Key()))
            return false;
          return keyValue.Value() == (*this)[keyValue.Key()];
        }

        virtual bool ContainsKey(const T& key) const override {return this->map.find(key) != this->map.end();}

        bool ContainsValue(const string& value) const {
          for (auto p : *this)
            if (p.Value() == value)
              return true;
          return false;
        }

        void CopyTo(System::Array<System::Collections::Generic::KeyValuePair<T, string>>& array, int32 index) const override {
          if (index < 0 || array.Length < index + this->Count)
            throw System::ArgumentOutOfRangeException(caller_);
          int32 count = index;
          for (auto elem : *this)
            array[count++] = System::Collections::Generic::KeyValuePair<T, string>(elem.Key(), elem.Value());
        }

        System::Collections::Generic::Enumerator<System::Collections::Generic::KeyValuePair<T, string>> GetEnumerator() const override {return System::Collections::Generic::Enumerator<System::Collections::Generic::KeyValuePair<T, string>>(new ValuesDictionary::Enumerator(*const_cast<ValuesDictionary*>(this)));}

        bool Remove(const System::Collections::Generic::KeyValuePair<T, string>& kvp) override {
          if (!Contains(kvp))
            return false;
          this->operationNumber++;
          return this->map.erase(kvp.Key()) >= 1;
        }

        virtual bool Remove(const T& key) override {
          this->operationNumber++;
          return this->map.erase(key) >= 1;
        }

        virtual bool TryGetValue(const T& key, string& value) const override {
          if (! ContainsKey(key))
            return false;
          value = (*this)[key];
          return true;
        }

        string& operator[](const T& key) override {
          this->operationNumber++;
          return this->map[key];
        }

        const string& operator[](const T& key) const override {
          if (! ContainsKey(key))
            throw System::ArgumentException(caller_);
          return const_cast<std::map<T, string, MapComparer>&>(this->map)[key];
        }

        ValuesDictionary& operator=(const ValuesDictionary& dictionary) {
          this->comparer = dictionary.comparer;
          this->map = dictionary.map;
          this->operationNumber = 0;
          return *this;
        }

      private:
        class MapComparer : public std::binary_function<T, T, bool> {
        private:
          ref<System::Collections::Generic::IComparer<T>> comparer;

        public:
          MapComparer(ref<System::Collections::Generic::IComparer<T>> c) : comparer(c) { }
          MapComparer(const MapComparer& mc) { comparer = mc.comparer; }
          ~MapComparer() { }

          MapComparer& operator=(const MapComparer& mc) { comparer = mc.comparer; return *this; }
          bool operator()(const T& e1, const T& e2) const { return comparer().Compare(e1, e2) < 0; }
        };

      public:
        class const_iterator : public std::iterator<std::input_iterator_tag, System::Collections::Generic::KeyValuePair<T, string>> {
        public:
          const_iterator(const typename std::map<T, string, MapComparer>::const_iterator& value) : value(value) {}
          const_iterator(const const_iterator& value) : value(value.value) {}
          const_iterator& operator++() {++this->value; return *this;}
          const_iterator operator++(int) {const_iterator tmp(*this); operator++(); return tmp;}
          bool operator==(const const_iterator& rhs) const {return this->value == rhs.value;}
          bool operator!=(const const_iterator& rhs) const {return this->value != rhs.value;}
          const System::Collections::Generic::KeyValuePair<T, string> operator*() {return System::Collections::Generic::KeyValuePair<T, string>((*value).first, (*value).second);}

        private:
          typename std::map<T, string, MapComparer>::const_iterator value;
        };

        const_iterator cbegin() const {return const_iterator(this->map.begin());}
        const_iterator cend() const {return const_iterator(this->map.end());}
        const_iterator begin() const {return const_iterator(this->map.begin());}
        const_iterator end() const {return const_iterator(this->map.end());}

        class Enumerator : public object, public System::Collections::Generic::IEnumerator<System::Collections::Generic::KeyValuePair<T, string>> {
        public:
          Enumerator(ValuesDictionary& dictionary) : dictionary(dictionary) {Reset();}
          Enumerator(const Enumerator& other): operationNumber(other.operationNumber), dictionary(other.dictionary), currentKeyValuePair(other.currentKeyValuePair), iterator(other.iterator), beforeFirst(other.beforeFirst) {}

          void Reset() {
            this->operationNumber = this->dictionary.operationNumber;
            this->iterator = this->dictionary.map.begin();
            this->beforeFirst = true;
          }

          virtual bool MoveNext() {

            if (this->operationNumber != this->dictionary.operationNumber)
              throw System::InvalidOperationException(caller_);

            if (IsFinished())
              return false;

            if (this->beforeFirst)
              this->beforeFirst = false;
            else
              this->iterator++;

            if (IsFinished()) return false;

            this->currentKeyValuePair = System::Collections::Generic::KeyValuePair<T, string>((*this->iterator).first, (*this->iterator).second);

            return true;
          }

        protected:
          const System::Collections::Generic::KeyValuePair<T, string>& GetCurrent() const  {
            if (this->beforeFirst || IsFinished())
              throw System::InvalidOperationException(caller_);
            return this->currentKeyValuePair;
          }

          bool IsFinished() const {return this->iterator == this->dictionary.map.end();}
          int64 operationNumber;
          ValuesDictionary& dictionary;
          System::Collections::Generic::KeyValuePair<T, string> currentKeyValuePair;
          typename std::map<T, string, MapComparer>::iterator iterator;
          bool beforeFirst;
        };

      protected:
        int64 operationNumber;
        refptr<System::Collections::Generic::IComparer<T>> comparer;
        std::map<T, string, MapComparer> map;
        object syncRoot;

      private:
        int32 GetCount() const override {return static_cast<int32>(this->map.size());}

        bool GetIsReadOnly() const override {return false;}

        bool GetIsSynchronized() const override {return false;}

        KeyCollection GetKeys() const override {
          KeyCollection keys;
          for (auto item : this->map)
            keys.Add(item.first);
          return keys;
        }

        ValueCollection GetValues() const override {
          ValueCollection values;
          for (auto item : this->map)
            values.Add(item.second);
          return values;
        }

        const object& GetSyncRoot() const override {return this->syncRoot;}
      };

      string GetName() const {
        if (this->Values().ContainsKey(this->value))
          return this->values[this->value];
        return string::Format("{0}", (int)(value));
      }

      string ToStringFlags() const {
        if (int64(this->value) == 0 && !Values().ContainsKey(this->value))
          return "0";

        if (int64(this->value) == 0)
          return Values()[(T)0];

        string str;
        int64 rest = int64(this->value);
        System::Collections::Generic::List<System::Collections::Generic::KeyValuePair<T, string>> reversed;
        for (auto item : Values())
          reversed.Insert(0, item);

        for (auto item : reversed) {
          if ((int64)item.Key() != 0 && (rest & (int64)item.Key()) == (int64)item.Key()) {
            rest -= (int64)item.Key();
            if (str != string::Empty)
              str = ", " + str;
            str = Values()[item.Key()] + str;
          }
        }

        if (string::IsNullOrEmpty(str) || rest > 0)
          return  System::Int64((int64)this->value).ToString();

        return str;
      }

      static ValuesDictionary& Values() {
        lock_(values) {
          if (values.Count == 0)
            EnumRegister<T>()(values, flags);
        }
        return values;
      };

      static ValuesDictionary values;
      static bool flags;
      T value = T();
    };

    /// @cond
    template<typename T>
    typename Enum<T>::ValuesDictionary Enum<T>::values;

    template<typename T>
    bool Enum<T>::flags = false;
    /// @endcond

    /// @brief Provides the base class for enumerations.
    template<>
    class Enum<NullPtr> static_ {
    public:
      /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
      /// @param value The value of a particular enumerated constant in terms of its underlying type.
      /// @return String A String containing the name of the enumerated constant in enumType whose value is value; or the value int32 to String if no such constant is found.
      /// @exception ArgumentException The value is ! a value of enumType.
      template<typename T>
      static string GetName(T value) {return Enum<T>(value).ToString();}

      /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
      /// @param value The value of a particular enumerated constant in terms of its underlying type.
      /// @return String A String containing the name of the enumerated constant in enumType whose value is value; or the value int32 to String if no such constant is found.
      /// @exception ArgumentException The value is ! a value of enumType.
      template<typename T>
      static string GetName(int32 value) {return Enum<T>((T)value).ToString();}

      /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
      /// @param value The value of a particular enumerated constant in terms of its underlying type.
      /// @return String A String containing the name of the enumerated constant in enumType whose value is value; or the value int32 to String if no such constant is found.
      /// @exception ArgumentException The value is ! a value of enumType.
      template<typename T>
      static string GetName(int64 value) {return Enum<T>((T)value).ToString();}

      /// @brief Retrieves an array of the names of the constants in a specified enumeration.
      /// @return Array<String> A String array of the names of the constants in enumType.
      /// @exception ArgumentException The value is ! a value of enumType.
      template<typename T>
      static System::Array<string> GetNames() {return Enum<T>().Values().Values().ToArray();}

      /// @brief Retrieves an array of the values of the constants in a specified enumeration.
      /// @return Array<T> An array that contains the values of the constants in enumType.
      /// @exception ArgumentException The value is ! a value of enumType.
      template<typename T>
      static System::Array<T> GetValues() {return Enum<T>().Values().Keys().ToArray();}

      /// @brief Returns an indication whether a constant with a specified value exists in a specified enumeration.
      /// @param fromValue An enumeration value.
      /// @return Boolean true if a constant in enumType has a value equal to value; otherwise, false.
      /// @exception ArgumentException The value is ! a value of enumType.
      template<typename T>
      static bool IsDefined(T value) {return Enum<T>().Values().ContainsKey(value);}

      /// @brief Converts the String representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object.
      /// @param value An A String containing the name or value to convert.
      /// @return Enum An enum whose value is represented by value.
      /// @exception ArgumentException The value is ! a value of enumType.
      template<typename T>
      static T Parse(const string& value) {return Parse<T>(value, false);}

      /// @brief Converts the String representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object.
      /// @param str An A String containing the name or value to convert.
      /// @param ignoreCase true to Ignore case; false to regard case.
      /// @return Enum An enum whose value is represented by value.
      /// @exception ArgumentException The value is ! a value of enumType.
      template<typename T>
      static T Parse(const string& str, bool ignoreCase) {
        Enum<T>().Values();
        if (Enum<T>().flags)
          return ParseFlags<T>(str, ignoreCase);

        for (auto item : Enum<T>().Values()) {
          if (string::Compare(str, item.Value(), ignoreCase) == 0)
            return (T)item.Key();
        }

        return (T)System::Int64::Parse(str);
      }

      /// @brief Converts the String representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object. The return value indicates whether the conversion succeeded.
      /// @param vaue The String representation of the enumeration name or underlying value to convert.
      /// @param reslt When this method returns, result contains an object of type TEnum whose value is represented by value if the parse operation succeeds. If the parse operation fails, result contains the default value of the underlying type of TEnum. Note that this value need ! be a member of the TEnum enumeration. This parameter is passed uninitialized.
      /// @return true if the value parameter was converted successfully; otherwise, false.
      template<typename T>
      static bool TryParse(const string& value, T& result) {return TryParse<T>(value, false, result);}

      /// @brief Converts the String representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object. A parameter specifies whether the operation is case-sensitive. The return value indicates whether the conversion succeeded.
      /// @param vaue The String representation of the enumeration name or underlying value to convert.
      /// @param ignoreCase true to Ignore case; false to regard case.
      /// @param reslt When this method returns, result contains an object of type TEnum whose value is represented by value if the parse operation succeeds. If the parse operation fails, result contains the default value of the underlying type of TEnum. Note that this value need ! be a member of the TEnum enumeration. This parameter is passed uninitialized.
      /// @return true if the value parameter was converted successfully; otherwise, false.
      template<typename T>
      static bool TryParse(const string& value, bool ignoreCase, T& result) {
        try {
          result = Parse<T>(value, ignoreCase);
          return true;
        } catch (...) {
          return false;
        }
      }

    private:
      template<typename T>
      static T ParseFlags(const string& value, bool ignoreCase) {
        System::Array<string> values = value.Split(',');
        for (string& str : values)
          str = str.TrimStart(' ').TrimEnd(' ');

        if (values.Count == 1) {
          for (auto item : Enum<T>().Values()) {
            if (string::Compare(value, item.Value(), ignoreCase) == 0)
              return (T)item.Key();
          }
          return (T)System::Int64::Parse(value);
        }

        int64 result = 0;
        for (string str : values) {
          bool found = false;
          for (auto item : Enum<T>().Values()) {
            if (string::Compare(str, item.Value(), ignoreCase) == 0) {
              found = true;
              result |= (int64)item.Key();
              break;
            }
          }
          if (found == false)
            throw System::FormatException(caller_);
        }

        return (T)result;
      }
    };
  }
}

using namespace Switch;

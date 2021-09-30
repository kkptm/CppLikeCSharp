/// @file
/// @brief Contains Switch::Any class.
#pragma once

#include "Boxing.hpp"
#include "GetHashCode.hpp"
#include "RefPtr.hpp"
#include "System/Boolean.hpp"
#include "System/Byte.hpp"
#include "System/Char.hpp"
#include "System/Double.hpp"
#include "System/Enum.hpp"
#include "System/Int16.hpp"
#include "System/Int32.hpp"
#include "System/Int64.hpp"
#include "System/IntPtr.hpp"
#include "System/SByte.hpp"
#include "System/Single.hpp"
#include "System/UInt16.hpp"
#include "System/UInt32.hpp"
#include "System/UInt64.hpp"
#include "System/UIntPtr.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Represent a polymorphic wrapper capable of holding any type.
  /// @par Examples
  /// This example show how to use Any:
  /// @include Any.cpp
  class core_export_ Any : public System::IComparable, public object {
    template <typename T, typename Bool>
    struct EnumOrOtherToAny {};

    template <typename T>
    struct EnumOrOtherToAny<T, std::true_type> {
      refptr<object> operator()(T value) {return new System::Enum<T>(value);}
    };

    template <typename T>
    struct EnumOrOtherToAny<T, std::false_type> {
      //refptr<object> operator()(T value) {return new System::IntPtr((intptr)&value);}
      refptr<object> operator()(T value) {return new Boxer<T>(value);}
    };

    template <typename T, typename Bool>
    struct ObjectOrOtherToAny {};

    template <typename T>
    struct ObjectOrOtherToAny<T, std::true_type> {
      refptr<object> operator()(T value) {return new T(value);}
    };

    template <typename T>
    struct ObjectOrOtherToAny<T, std::false_type> {
      refptr<object> operator()(T value) {return EnumOrOtherToAny<T, typename std::conditional<std::is_enum<T>::value, std::true_type, std::false_type>::type>()(value);}
    };

    template <typename T>
    struct ObjectOrEnumOrOtherToAny {
      refptr<object> operator()(T value) {return ObjectOrOtherToAny<T, typename std::conditional<std::is_base_of<object, T>::value, std::true_type, std::false_type>::type>()(value);}
    };

  public:
    /// @brief Initializes a new instance of the Any class to the specified value.
    /// @param value A vlue type.
    template<typename T>
    Any(T value) : value(ObjectOrEnumOrOtherToAny<T>()(value)) {}

    /// @cond
    Any();
    Any(const Any& any);
    Any& operator=(const Any& any);
    Any(NullPtr value);
    Any(bool value);
    Any(byte value);
    Any(char value);
    Any(wchar value);
    Any(char16 value);
    Any(char32 value);
    Any(double value);
    Any(int16 value);
    Any(int32 value);
    Any(int64 value);
    Any(const char* value);
    Any(char* value);
    Any(const unsigned char* value);
    Any(unsigned char* value);
    Any(const wchar* value);
    Any(wchar* value);
    Any(const char16* value);
    Any(char16* value);
    Any(const char32* value);
    Any(char32* value);
    Any(const std::string& value);
    Any(const std::wstring& value);
    Any(const std::u16string& value);
    Any(const std::u32string& value);
    Any(sbyte value);
    Any(float value);
    Any(uint16 value);
    Any(uint32 value);
    Any(uint64 value);
    Any(void* value);
    Any(llong value);
    Any(ullong value);
    template<typename T, typename Attribute>
    Any(const property_<T, Attribute>& value) : value(ObjectOrEnumOrOtherToAny<T>()(value())) {}
    template <typename T>
    operator T() const {
      if (!this->HasValue)
        throw System::InvalidOperationException(caller_);
      return To<T>();
    }

    bool operator==(NullPtr value) const;
    bool operator==(bool value) const;
    bool operator==(byte value) const;
    bool operator==(char value) const;
    bool operator==(wchar value) const;
    bool operator==(char16 value) const;
    bool operator==(char32 value) const;
    bool operator==(double value) const;
    bool operator==(int16 value) const;
    bool operator==(int32 value) const;
    bool operator==(int64 value) const;
    bool operator==(const char* value) const;
    bool operator==(char* value) const;
    bool operator==(const wchar* value) const;
    bool operator==(wchar* value) const;
    bool operator==(const char16* value) const;
    bool operator==(char16* value) const;
    bool operator==(const char32* value) const;
    bool operator==(char32* value) const;
    bool operator==(const std::string& value) const;
    bool operator==(const std::wstring& value) const;
    bool operator==(const std::u16string& value) const;
    bool operator==(const std::u32string& value) const;
    bool operator==(sbyte value) const;
    bool operator==(float value) const;
    bool operator==(uint16 value) const;
    bool operator==(uint32 value) const;
    bool operator==(uint64 value) const;
    bool operator==(void* value) const;
    bool operator==(llong value) const;
    bool operator==(ullong value) const;
    template<typename T>
    bool operator==(const T& value) const {return As<T>() == value;}
    template<typename T>
    bool operator!=(const T& value) const {return !this->operator==(value);}

    bool operator==(const Any& value) const {
      if (!this->HasValue && !value.HasValue) return true;
      return *this->value == *value.value;
    }
    bool operator!=(const Any& value) const {return !this->operator==(value);}

    /// @endcond

    /// @brief Gets a value indicating whether the current Nullable<T> object has a valid value of its underlying type.
    /// @return true if the current Nullable<T> object has a value; false if the current Nullable<T> object has no value.
    /// @remarks If the HasValue property is true, the value of the current Nullable<T> object can be accessed with the Value property. Otherwise, attempting to access its value throws an InvalidOperationException exception.
    property_<bool, readonly_> HasValue {
      get_ {return this->value != null;}
    };

    /// @brief Gets the value of the current Any object if it has been assigned a valid underlying value.
    /// @return The value of the current Any object if the HasValue property is true. An exception is thrown if the HasValue property is false.
    /// @exception InvalidOperationException The HasValue property is false.
    property_<const object&, readonly_> Value {
      get_->const object& {
        if (!this->HasValue)
          throw System::InvalidOperationException(caller_);
        return this->value.ToObject();
      }
    };

    /// @brief Used to static cast a type into another type. A To expression takes the following form:
    /// @par Examples
    /// @code
    /// refptr<string> str = new Switch::string("A new string");
    /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
    /// @endcode
    /// @exception InvalidOperationException The parameters is null.
    template<typename T>
    T& As() {
      if (!this->HasValue)
        throw System::InvalidOperationException(caller_);
      return as<T>(this->value.ToObject());
    }

    /// @brief Used to static cast a type into another type. A To expression takes the following form:
    /// @par Examples
    /// @code
    /// refptr<string> str = new Switch::string("A new string");
    /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
    /// @endcode
    /// @exception InvalidOperationException The parameters is null.
    template<typename T>
    const T& As() const {
      if (!this->HasValue)
        throw System::InvalidOperationException(caller_);
      return as<T>(this->value.ToObject());
    }

    /// @brief Compares the current instance with another object of the same type.
    /// @param obj An object to compare with this instance.
    /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared.
    /// The return value has these meanings:
    /// | Value             | Condition                          |
    /// |-------------------|------------------------------------|
    /// | Less than zero    | This instance is less than obj.    |
    /// | Zero              | This instance is equal to obj.     |
    /// | Greater than zero | This instance is greater than obj. |
    int32 CompareTo(const IComparable& obj) const override;

    /// @brief Compares the current instance with another object of the same type.
    /// @param obj An object to compare with this instance.
    /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared.
    /// The return value has these meanings:
    /// | Value             | Condition                          |
    /// |-------------------|------------------------------------|
    /// | Less than zero    | This instance is less than obj.    |
    /// | Zero              | This instance is equal to obj.     |
    /// | Greater than zero | This instance is greater than obj. |
    int32 CompareTo(const Any& obj) const;

    /// @brief Serves as a hash function for a particular type.
    /// @return Int32 A hash code for the current Object.
    int32 GetHashCode() const override;

    /// @brief Determines whether this instance of Any and a specified Object, which must also be a Any Object, have the same value.
    /// @param obj The Object to compare with the current Object.
    /// @return true if the specified Object is equal to the current Object. otherwise, false.
    bool Equals(const object& obj) const override;

    /// @brief Determines whether this instance of Any and a specified Object, which must also be an Any Object, have the same value.
    /// @param value The Any to compare with the current Object.
    /// @return true if the specified value is equal to the current Any. otherwise, false.
    bool Equals(const Any& value) const;

    /// @brief Determines whether this instance of Any and a specified Object, which must also be an Any Object, have the same value.
    /// @param value The Any to compare with the current Object.
    /// @return true if the specified value is equal to the current Any. otherwise, false.
    template <typename T>
    bool Equals(T value) const {
      if (!this->HasValue) return false;
      return *this->value == value;
    }

    /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
    /// @par Examples
    /// @code
    /// System::Int32 i = 0;
    /// bool isInt32 = is<System::Int32>(i);
    /// @endcode
    /// @see Switch::System::Type
    template<typename T>
    bool Is() {
      if (!this->HasValue) return false;
      return is<T>(this->value.ToObject());
    }

    /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
    /// @par Examples
    /// @code
    /// System::Int32 i = 0;
    /// bool isInt32 = is<System::Int32>(i);
    /// @endcode
    /// @see Switch::System::Type
    template<typename T>
    bool Is() const {
      if (!this->HasValue) return false;
      return is<T>(this->value.ToObject());
    }

    /// @brief Returns the text representation of the value of the current Nullable<T> object.
    /// @return The text representation of the value of the current Nullable<T> object if the HasValue property is true, or an empty string ("") if the HasValue property is false.
    /// @remarks The ToString property returns the string yielded by calling the ToString property of the object returned by the Value property.
    string ToString() const override {
      if (this->HasValue == false)
        return "";
      return value->ToString();
    }

  private:
    template <typename T>
    T To() const {return *dynamic_cast<const T*>(this->value.ToPointer());}

    template <typename T>
    T To() {return *dynamic_cast<T*>(this->value.ToPointer());}

    refptr<object> value;
  };

  /// @cond
  template <>
  inline bool Any::To<bool>() const {
    return as<System::Boolean>(this->value.ToObject());
  }

  template <>
  inline byte Any::To<byte>() const {
    return as<System::Byte>(this->value.ToObject());
  }

  template <>
  inline char Any::To<char>() const {
    return (char)as<System::Char>(this->value.ToObject());
  }

  template <>
  inline char16 Any::To<char16>() const {
    return (char16)as<System::Char>(this->value.ToObject());
  }

  template <>
  inline char32 Any::To<char32>() const {
    return as<System::Char>(this->value.ToObject());
  }

  template <>
  inline wchar Any::To<wchar>() const {
    return (wchar)as<System::Char>(this->value.ToObject());
  }

  template <>
  inline double Any::To<double>() const {
    return as<System::Double>(this->value.ToObject());
  }

  template <>
  inline int16 Any::To<int16>() const {
    return as<System::Int16>(this->value.ToObject());
  }

  template <>
  inline int32 Any::To<int32>() const {
    return as<System::Int32>(this->value.ToObject());
  }

  template <>
  inline sbyte Any::To<sbyte>() const {
    return as<System::SByte>(this->value.ToObject());
  }

  template <>
  inline float Any::To<float>() const {
    return as<System::Single>(this->value.ToObject());
  }

  template <>
  inline string Any::To<string>() const {
    return this->ToString();
  }

  template <>
  inline int64 Any::To<int64>() const {
    return as<System::Int64>(this->value.ToObject());
  }

  template <>
  inline uint16 Any::To<uint16>() const {
    return as<System::UInt16>(this->value.ToObject());
  }

  template <>
  inline uint32 Any::To<uint32>() const {
    return as<System::UInt32>(this->value.ToObject());
  }

  template <>
  inline uint64 Any::To<uint64>() const {
    return as<System::UInt64>(this->value.ToObject());
  }
  /// @endcond

  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Switch::string("A new string");
  /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  template<typename T>
  T as(const Any& value) {
    return value.As<T>();
  }

  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Switch::string("A new string");
  /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  template<typename T>
  T as(Any& value) {
    return value.As<T>();
  }

  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Switch::System::Type
  template<typename T>
  bool is(const Any& value) {
    return value.Is<T>();
  }

  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Switch::System::Type
  template<typename T>
  bool is(Any& value) {
    return value.Is<T>();
  }

  /// @cond
  template<>
  inline bool as<bool>(const Any& value) {
    return value.As<System::Boolean>();
  }

  template<>
  inline byte as<byte>(const Any& value) {
    return value.As<System::Byte>();
  }

  template<>
  inline char32 as<char32>(const Any& value) {
    return value.As<System::Char>();
  }

  template<>
  inline int16 as<int16>(const Any& value) {
    return value.As<System::Int16>();
  }

  template<>
  inline int32 as<int32>(const Any& value) {
    return value.As<System::Int32>();
  }

  template<>
  inline int64 as<int64>(const Any& value) {
    return value.As<System::Int64>();
  }

  #if defined(__APPLE__)
  template<>
  inline intptr as<intptr>(const Any& value) {
    return value.As<System::IntPtr>();
  }
  #endif

  template<>
  inline sbyte as<sbyte>(const Any& value) {
    return value.As<System::SByte>();
  }

  template<>
  inline uint16 as<uint16>(const Any& value) {
    return value.As<System::UInt16>();
  }

  template<>
  inline uint32 as<uint32>(const Any& value) {
    return value.As<System::UInt32>();
  }

  template<>
  inline uint64 as<uint64>(const Any& value) {
    return value.As<System::UInt64>();
  }

  #if defined(__APPLE__)
  template<>
  inline uintptr as<uintptr>(const Any& value) {
    return value.As<System::UIntPtr>();
  }
  #endif

  template<>
  inline bool as<bool>(Any& value) {
    return value.As<System::Boolean>();
  }

  template<>
  inline byte as<byte>(Any& value) {
    return value.As<System::Byte>();
  }

  template<>
  inline char32 as<char32>(Any& value) {
    return value.As<System::Char>();
  }

  template<>
  inline int16 as<int16>(Any& value) {
    return value.As<System::Int16>();
  }

  template<>
  inline int32 as<int32>(Any& value) {
    return value.As<System::Int32>();
  }

  template<>
  inline int64 as<int64>(Any& value) {
    return value.As<System::Int64>();
  }

  #if defined(__APPLE__)
  template<>
  inline intptr as<intptr>(Any& value) {
    return value.As<System::IntPtr>();
  }
  #endif

  template<>
  inline sbyte as<sbyte>(Any& value) {
    return value.As<System::SByte>();
  }

  template<>
  inline uint16 as<uint16>(Any& value) {
    return value.As<System::UInt16>();
  }

  template<>
  inline uint32 as<uint32>(Any& value) {
    return value.As<System::UInt32>();
  }

  template<>
  inline uint64 as<uint64>(Any& value) {
    return value.As<System::UInt64>();
  }

  #if defined(__APPLE__)
  template<>
  inline uintptr as<uintptr>(Any& value) {
    return value.As<System::UIntPtr>();
  }
  #endif
  /// @endcond

  /// @brief Represent a polymorphic wrapper capable of holding any type.
  /// @par Examples
  /// This example show how to use any:
  /// @include Any.cpp
  /// @ingroup Types
  using any = Any;
}

using namespace Switch;

#include "System/String.hpp"

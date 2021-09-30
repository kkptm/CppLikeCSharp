/// @file
/// @brief Contains Switch::System::Nullable struct.
#pragma once

#include "../GetHashCode.hpp"
#include "../NullPtr.hpp"
#include "../Property.hpp"
#include "Convert.hpp"
#include "IComparable.hpp"
#include "InvalidOperationException.hpp"
#include "Object.hpp"

namespace Switch {
  namespace System {
    /// @brief Represents a value type that can be assigned null.
    /// @par Examples
    /// The following code example defines three rows of a table in the Microsoft Pubs sample database. The table contains two columns that are not nullable and two columns that are nullable.
    /// @include Nullable.cpp
    template <class T>
    struct Nullable : public IComparable, public object {
    public:
      /// @brief Initializes a new instance of the Nullable<T> structure to the specified value.
      /// @param value A vlue type.
      /// @remarks The Nullable<T> constructor initializes the HasValue property of the new Nullable<T> object to true, and the Value property to the value of the value parameter.
      Nullable(T value) : value{value}, hasValue{true} {}

      /// @cond
      Nullable() {}
      Nullable(NullPtr) {}
      Nullable(const Nullable& value) : value(value.value), hasValue(value.hasValue) {}

      Nullable& operator=(const Nullable& value) {
        this->value = value.value;
        this->hasValue = value.hasValue;
        return *this;
      }

      Nullable& operator=(T value) {
        this->value = value;
        this->hasValue = true;
        return *this;
      }

      Nullable& operator=(NullPtr) {
        this->hasValue = false;
        return *this;
      }

      bool operator==(NullPtr value) const {return !this->HasValue();}
      bool operator!=(NullPtr value) const {return !this->operator==(value);}
      bool operator==(const Nullable& value) const {return this->HasValue() == value.HasValue() && this->value == value.value;}
      bool operator!=(const Nullable& value) const {return !this->operator==(value);}
      bool operator==(T value) const {return this->HasValue() && this->value == value;}
      bool operator!=(T value) const {return !this->operator==(value);}
      /// @endcond

      /// @brief Gets a value indicating whether the current Nullable<T> object has a valid value of its underlying type.
      /// @return true if the current Nullable<T> object has a value; false if the current Nullable<T> object has no value.
      /// @remarks If the HasValue property is true, the value of the current Nullable<T> object can be accessed with the Value property. Otherwise, attempting to access its value throws an InvalidOperationException exception.
      property_<bool, readonly_> HasValue {
        get_ {return this->hasValue;}
      };

      /// @brief Gets the value of the current Nullable<T> object if it has been assigned a valid underlying value.
      /// @return The value of the current Nullable<T> object if the HasValue property is true. An exception is thrown if the HasValue property is false.
      /// @exception InvalidOperationException The HasValue property is false.
      /// @remarks If a value of type T has not been assigned to the Nullable<T> object, you can compare it to null and retrieve its HasValue property, but you cannot access its Value property or call its other members.
      property_<T&, readonly_> Value {
        get_->T& {
          if (!this->hasValue)
            throw System::InvalidOperationException(caller_);
          return this->value;
        }
      };

      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared.
      /// The return value has these meanings:
      /// | Value             | Condition                          |
      /// |-------------------|------------------------------------|
      /// | Less than zero    | This instance is less than obj.    |
      /// | Zero              | This instance is equal to obj.     |
      /// | Greater than zero | This instance is greater than obj. |
      int32 CompareTo(const IComparable& obj) const override {
        if (!is<Nullable>(obj)) return -1;
        return CompareTo(as<Nullable<T>>(obj));
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
      int32 CompareTo(const Nullable& obj) const {
        if (this->value < obj.value) return -1;
        if (this->value > obj.value) return 1;
        return 0;
      }

      /// @brief Determines whether this instance of Any and a specified Object, which must also be a Nullable<T> Object, have the same value.
      /// @param obj The Object to compare with the current Object.
      /// @return true if the specified Object is equal to the current Object. otherwise, false.
      bool Equals(const object& obj) const override {return is<Nullable<T>>(obj) && Equals(as<Nullable<T>>(obj));}

      /// @brief Determines whether this instance of Nullable<T> and a specified Object, which must also be a Nullable<T> Object, have the same value.
      /// @param value The Nullable<T> to compare with the current Object.
      /// @return true if the specified value is equal to the current Nullable<T>. otherwise, false.
      bool Equals(const Nullable& value) const {
        if (this->hasValue == false && value.hasValue == false)
          return true;
        return this->hasValue == value.hasValue && this->value == value.value;
      }

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current Object.
      int32 GetHashCode() const override {
        return ::GetHashCode(this->value);
      }

      /// @brief Retrieves the value of the current Nullable<T> object, or the object's default value.
      /// @return The value of the Value property if the HasValue property is true; otherwise, the default value of the current Nullable<T> object. The type of the default value is the type argument of the current Nullable<T> object, and the value of the default value consists solely of binary zeroes.
      /// @remarks The GetValueOrDefault method returns a value even if the HasValue property is false (unlike the Value property, which throws an exception).
      T GetValueOrDefault() {
        return GetValueOrDefault(T());
      }

      /// @brief Retrieves the value of the current Nullable<T> object, or the specified default value.
      /// @param A value to return if the HasValue property is false.
      /// @return The value of the Value property if the HasValue property is true; otherwise, the defaultValue parameter.
      /// @remarks The GetValueOrDefault method returns a value even if the HasValue property is false (unlike the Value property, which throws an exception).
      T GetValueOrDefault(T defaultValue) {
        if (!this->hasValue)
          return defaultValue;
        return this->value;
      }

      /// @brief Returns the text representation of the value of the current Nullable<T> object.
      /// @return The text representation of the value of the current Nullable<T> object if the HasValue property is true, or an empty string ("") if the HasValue property is false.
      /// @remarks The ToString property returns the string yielded by calling the ToString property of the object returned by the Value property.
      String ToString() const override {
        if (!this->hasValue)
          return "";
        return Convert::ToString(this->value);
      }

    private:
      T value;
      bool hasValue = false;
    };
  }

  /// @brief Represents a value type that can be assigned null.
  /// @par Examples
  /// The following code example defines three rows of a table in the Microsoft Pubs sample database. The table contains two columns that are not nullable and two columns that are nullable.
  /// @include Nullable.cpp
  template<typename T>
  using n = System::Nullable<T>;

  template<typename TT, typename T>
  bool is(const System::Nullable<T>& value) {
    if (!value.HasValue)
      return false;
    return is<TT>(value.Value());
  }

  template<typename TT, typename T>
  bool is(System::Nullable<T>& value) {
    if (!value.HasValue)
      return false;
    return is<TT>(value.Value());
  }
}

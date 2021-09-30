/// @file
/// @brief Contains Switch::System::Object class.
#pragma once

#include <ostream>

#include "../Types.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @cond
  template<typename T>
  class $;
  template<typename T>
  using refptr = $<T>;
  /// @endcond

  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    class Type;
    class String;
    /// @endcond

    /// @brief Supports all classes in the Switch class hierarchy and provides low-level services to derived classes.
    /// This is the ultimate base class of all classes in the Switch.
    /// It is the root of the type hierarchy.
    /// @par Examples
    /// The following example defines a Point type derived from the Object class and virtuals many of the virtual methods of the Object class. In addition, the example shows how to call many of the static and instance methods of the Object class.
    /// @include Object.cpp
    class core_export_ Object {
    public:
      /// @brief Create a new instance of the ultimate base class Object
      /// @remarks This constructor is called by constructors in derived classes, but it can also be used to directly create an instance of the Object class.
      Object() = default;

      /// @cond
      Object(const Object&) = default;
      Object& operator=(const Object&) = default;
      virtual ~Object() = default;
      bool operator==(const Object& obj) const {return Equals(obj);}
      bool operator!=(const Object& obj) const {return !this->operator==(obj);}
      friend core_export_ std::ostream& operator<<(std::ostream& output, const Object& value);
      /// @endcond

      /// @brief Determines whether the specified Object is equal to the current Object.
      /// @param obj The Object to compare with the current Object.
      /// @return bool true if the specified Object is equal to the current Object. otherwise, false.
      /// @par Examples
      /// The following code example compares the current instance with another object.
      /// @include ObjectEquals.cpp
      virtual bool Equals(const Object& obj) const {return this == &obj;}

      /// @brief Determines whether the specified Object instances are considered equal.
      /// @param objectA The first Object to compare.
      /// @param objectB The second Object to compare.
      /// @return bool true if objectA is the same instance as objectB or if both are null references or if objectA(objectB) returns true. otherwise, false.
      /// @par Examples
      /// The following code example compares different objects.
      /// @include ObjectEquals2.cpp
      static bool Equals(const Object& objectA, const Object& objectB) {return objectA.Equals(objectB);}

      /// @brief Serves as a hash function for a particular type.
      /// @return int32 A hash code for the current Object.
      virtual int32 GetHashCode() const {return int32(int64(this) & 0x00000000FFFFFFFF) ^ int32((int64(this) >> 32) & 0x00000000FFFFFFFF);}

      /// @brief Gets the Type of the current instance.
      /// @return Type The Type instance that represents the exact runtime type of the current instance.
      /// @par Examples
      /// The following code example demonstrates that GetType returns the runtime type of the current instance.
      /// @include ObjectGetType.cpp
      virtual Type GetType() const;

      /// @brief Creates a shallow copy of the current Object.
      /// @return refptr<Object> A shallow copy of the current Object.
      /// @par Examples
      /// The following code example shows how to copy an instance of a class using MemberwiseClone.
      /// @include ObjectMemberwiseClone.cpp
      template<typename T>
      refptr<Object> MemberwiseClone() const;

      /// @brief Determines whether the specified Object instances are the same instance.
      /// @param objectA The first Object to compare.
      /// @param objectB The second Object to compare.
      /// @return bool true if objectA is the same instance as objectB or if both are null references; otherwise, false.
      /// @par Examples
      /// The following code example uses ReferenceEquals to determine if two objects are the same instance.
      /// @include ObjectReferenceEquals.cpp
      static bool ReferenceEquals(const Object& objectA, const Object& objectB) {return &objectA == &objectB;}

      /// @brief Returns a String that represents the current Object.
      /// @return string A string that represents the current Object.
      /// @par Examples
      /// The following code example demonstrates what ToString returns.
      /// @include ObjectToString.cpp
      virtual String ToString() const;
    };
  }

  /// @brief Supports all classes in the Switch class hierarchy and provides low-level services to derived classes.
  /// @see System::Object
  using object = System::Object;
}

#include "_String.hpp"
#include "Type.hpp"

#include "../As.hpp"
#include "../RefPtr.hpp"

namespace Switch {
  namespace System {
    template<typename T>
    refptr<Object> Object::MemberwiseClone() const {return ref_new<T>(as<T>(*this));}
  }
}

using namespace Switch;

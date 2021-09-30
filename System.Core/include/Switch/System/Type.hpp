/// @file
/// @brief Contains Switch::System::Type class.
#pragma once

#include "../As.hpp"
#include "../Is.hpp"
#include "../Property.hpp"
#include "ICloneable.hpp"
#include "IConvertible.hpp"
#include "Boolean.hpp"
#include "Object.hpp"
#include "_String.hpp"
#include "TypeCode.hpp"
#include "ValueType.hpp"

/// @cond
namespace Switch {
  namespace System {
    class Type;
    class Object;
  }
}

namespace __s__ {
  template<typename T>
  Switch::System::Type __typeof_();

  template<typename T>
  Switch::System::Type __typeof_(const T& value);
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents type declarations: class types, interface types, array types, value types, enumeration types, type parameters, generic type definitions, and open or closed constructed generic types.
    class core_export_ Type : public Object {
    public:
      /// @cond
      Type(const Type& type);
      /// @endcond

      /// @brief Gets the fully qualified name of the Type, including the namespace of the Type.
      /// @return The fully qualified name of the Type, including the namespace of the Type.
      /// @remarks For example, the fully qualified name of the String type is String.
      property_<String, readonly_> FullName;

      /// @brief Gets the name of the Type.
      /// @return The name of the Type.
      /// @remarks For example, the name of the String type is String.
      property_<String, readonly_> Name;

      /// @brief Gets the namespace of the Type.
      /// @return The namespace of the Type.
      /// @remarks For example, the namespace of the String type is System::
      property_<String, readonly_> Namespace;

      /// @brief Determines whether the specified Object is equal to the current Object.
      /// @param obj The Object to compare with the current Object.
      /// @return bool true if the specified Object is equal to the current Object. otherwise, false.
      bool Equals(const Object& obj) const override;

      /// @brief Determines whether the specified Type is equal to the current Type.
      /// @param type The Type to compare with the current Object.
      /// @return bool true if the specified type is equal to the current Type. otherwise, false.
      bool Equals(const Type& type) const;

      /// @brief Gets the underlying type code of the specified Type
      /// @param value The value of type whose underlying type code to get.
      /// @return The code of the underlying type, or Empty if type is null.
      template<typename T>
      static TypeCode GetTypeCode(const T& value) {
        if (!is<IConvertible>(value))
          return TypeCode::Object;
        return dynamic_cast<const IConvertible&>(value).GetTypeCode();
      }

      template<typename T>
      static bool IsComparable(T value) {return is<IComparable>(value);}

      template<typename T, class TT>
      static bool IsInstanceOfType(TT value) {return is<T>(value);}

      template<typename T>
      static bool IsValueType(T obj) {return is<ValueType>(obj);}

      /// @brief Returns a String representing the name of the current Type.
      /// @return A String representing the name of the current Type.
      String ToString() const override;

    private:
      String GetFullName() const;
      String GetName() const;
      String GetNamespace() const;

      template<typename T>
      friend Type __s__::__typeof_();
      template<typename T>
      friend Type __s__::__typeof_(const T& value);
      friend class Object;

      Type();
      Type(const std::type_info& type);
      Type& operator=(const Type& type);

      const std::type_info& type;
    };
  }
}

/// @cond
namespace __s__ {
  template<typename T>
  Switch::System::Type __typeof_() {
    return System::Type(typeid(T));
  }

  template<typename T>
  Switch::System::Type __typeof_(const T& value) {
    return System::Type(typeid(value));
  }
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Used to obtain the type Object for a type. A typeof_ expression takes the following form:
  /// @par Examples
  /// @code
  /// Type type1 = typeof_<Int32>();
  ///
  /// Int32 i = 42;
  /// Type type2 = typeof_(i);
  /// @endcode
  /// @par Examples
  /// To obtain the run-time type of an expression, you can use the Switch method GetType, as in the following example:
  /// @code
  /// Int32 42 = 0;
  /// System::Type Type = i.GetType();
  /// @endcode
  /// @remarks The typeof_ operator cannot be overloaded.
  /// @see System::Type
  /// @ingroup Keywords
#define typeof_  \
  __s__::__typeof_
}

using namespace Switch;

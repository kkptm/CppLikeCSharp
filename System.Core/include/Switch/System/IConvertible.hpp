/// @file
/// @brief Contains Switch::System::IConvertible interface.
#pragma once

#include "../Interface.hpp"
#include "../Types.hpp"

/// @cond
namespace Switch {
  namespace System {
    struct DateTime;
    class IFormatProvider;
    enum class TypeCode;
    class String;
  }
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @interface IConvertible
    /// @brief Defines a generalized comparison method that a value type or class implements to create a type-specific comparison method.
    class core_export_ IConvertible interface_ {
    public:
      /// @brief Returns the TypeCode for this instance.
      /// @return TypeCode The enumerated constant that is the TypeCode of the class or value type that implements this interface.
      virtual TypeCode GetTypeCode() const = 0;

      /// @brief Converts the value of this instance to a bool using the specified culture-specific formatting information.
      /// @param provider An IFormatProvider interface implementation that supplies culture-specific formatting information.
      /// @return bool A bool value equivalent to the value of this instance.
      virtual bool ToBoolean(const IFormatProvider& provider) const = 0;

      /// @brief Converts the value of this instance to a Byte using the specified culture-specific formatting information.
      /// @param provider An IFormatProvider interface implementation that supplies culture-specific formatting information.
      /// @return byte An Byte equivalent to the value of this instance.
      virtual byte ToByte(const IFormatProvider& provider) const = 0;

      /// @brief Converts the value of this instance to a Chars using the specified culture-specific formatting information.
      /// @param provider An IFormatProvider interface implementation that supplies culture-specific formatting information.
      /// @return char32 A Char equivalent to the value of this instance.
      virtual char32 ToChar(const IFormatProvider& provider) const = 0;

      /// @brief Converts the value of this instance to a DateTime using the specified culture-specific formatting information.
      /// @param provider An IFormatProvider interface implementation that supplies culture-specific formatting information.
      /// @return DateTime A DateTime equivalent to the value of this instance.
      virtual DateTime ToDateTime(const IFormatProvider& provider) const = 0;

      /// @brief Converts the value of this instance to a Double using the specified culture-specific formatting information.
      /// @param provider An IFormatProvider interface implementation that supplies culture-specific formatting information.
      /// @return double A Double equivalent to the value of this instance.
      virtual double ToDouble(const IFormatProvider& provider) const = 0;

      /// @brief Converts the value of this instance to a Int16 using the specified culture-specific formatting information.
      /// @param provider An IFormatProvider interface implementation that supplies culture-specific formatting information.
      /// @return Byte A Int16 equivalent to the value of this instance.
      virtual int16 ToInt16(const IFormatProvider& provider) const = 0;

      /// @brief Converts the value of this instance to a Int32 using the specified culture-specific formatting information.
      /// @param provider An IFormatProvider interface implementation that supplies culture-specific formatting information.
      /// @return int32 A Int32 equivalent to the value of this instance.
      virtual int32 ToInt32(const IFormatProvider& provider) const = 0;

      /// @brief Converts the value of this instance to a Int64 using the specified culture-specific formatting information.
      /// @param provider An IFormatProvider interface implementation that supplies culture-specific formatting information.
      /// @return int64 A Int64 equivalent to the value of this instance.
      virtual int64 ToInt64(const IFormatProvider& provider) const = 0;

      /// @brief Converts the value of this instance to an UInt16 using the specified culture-specific formatting information.
      /// @param provider An IFormatProvider interface implementation that supplies culture-specific formatting information.
      /// @return uit16 An UInt16 equivalent to the value of this instance.
      virtual uint16 ToUInt16(const IFormatProvider& provider) const = 0;

      /// @brief Converts the value of this instance to an UInt32 using the specified culture-specific formatting information.
      /// @param provider An IFormatProvider interface implementation that supplies culture-specific formatting information.
      /// @return uint32 An UInt32 equivalent to the value of this instance.
      virtual uint32 ToUInt32(const IFormatProvider& provider) const = 0;

      /// @brief Converts the value of this instance to an UInt64 using the specified culture-specific formatting information.
      /// @param provider An IFormatProvider interface implementation that supplies culture-specific formatting information.
      /// @return uint64 An UInt64 equivalent to the value of this instance.
      virtual uint64 ToUInt64(const IFormatProvider& provider) const = 0;

      /// @brief Converts the value of this instance to a SByte using the specified culture-specific formatting information.
      /// @param provider An IFormatProvider interface implementation that supplies culture-specific formatting information.
      /// @return sbyte A  SByte equivalent to the value of this instance.
      virtual sbyte ToSByte(const IFormatProvider& provider) const = 0;

      /// @brief Converts the value of this instance to a Single using the specified culture-specific formatting information.
      /// @param provider An IFormatProvider interface implementation that supplies culture-specific formatting information.
      /// @return single A Single equivalent to the value of this instance.
      virtual float ToSingle(const IFormatProvider& provider) const = 0;

      /// @brief Converts the value of this instance to a string using the specified culture-specific formatting information.
      /// @param provider An IFormatProvider interface implementation that supplies culture-specific formatting information.
      /// @return string A string equivalent to the value of this instance.
      virtual String ToString(const IFormatProvider& provider) const = 0;
    };
  }
}

using namespace Switch;

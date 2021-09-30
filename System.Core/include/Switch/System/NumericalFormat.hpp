/// @file
/// @brief Contains Switch::System::NumericalFormat class.
#pragma once

#include "../Types.hpp"
#include "String.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    class core_export_ NumericalFormat {
    public:
      NumericalFormat() = delete;

      static char32 GetFormatType(const String& format, int32& precision);

      static String Format_B(int64 value, int32 precision, int32 nbBits);

      static String Format_B(uint64 value, int32 precision);

      static String Format_D(int64 value, int32 precision);

      static String Format_D(uint64 value, int32 precision);

      static String Format_E(uint64 value, int32 precision, bool upper);

      static String Format_E(int64 value, int32 precision, bool upper);

      static String Format_E(double value, int32 precision, bool upper);

      static String Format_E(decimal value, int32 precision, bool upper);

      static String Format_F(uint64 value, int32 precision);

      static String Format_F(int64 value, int32 precision);

      static String Format_F(double value, int32 precision);

      static String Format_F(decimal value, int32 precision);

      static String Format_G(uint64 value, int32 precision, bool upper);

      static String Format_G(int64 value, int32 precision, bool upper);

      static String Format_G(double value, int32 precision, bool upper);

      static String Format_G(decimal value, int32 precision, bool upper);

      static String Format_N(uint64 value, int32 precision);

      static String Format_N(int64 value, int32 precision);

      static String Format_N(double value, int32 precision);

      static String Format_N(decimal value, int32 precision);

      static String Format_P(uint64 value, int32 precision);

      static String Format_P(int64 value, int32 precision);

      static String Format_P(double value, int32 precision);

      static String Format_P(decimal value, int32 precision);

      static String Format_X(int64 value, int32 precision, bool upper, int32 size);

      static String Format_X(uint64 value, int32 precision, bool upper, int32 size);

      static String Format_Custom(int64 value, const String& format);

      static String Format_Custom(uint64 value, const String& format);

      static String Format_Custom(double value, const String& format);

      static String Format_Custom(decimal value, const String& format);
    };
    /// @endcond
  }
}

using namespace Switch;

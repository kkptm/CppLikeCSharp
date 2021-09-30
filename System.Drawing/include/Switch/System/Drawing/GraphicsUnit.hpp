/// @file
/// @brief Contains Switch::System::Drawing::FontStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
      /// @par Library
      /// Switch.System.Drawing
      enum class GraphicsUnit {
        /// @brief Specifies the unit of measure for the given data.
        World = 0,
        /// @brief Specifies 1/75 inch as the unit of measure.
        Display = 1,
        /// @brief Specifies a device pixel as the unit of measure.
        Pixel = 2,
        /// @brief Specifies a printer's point (1/72 inch) as the unit of measure.
        Point = 3,
        /// @brief Specifies the inch as the unit of measure.
        Inch = 4,
        /// @brief Specifes the document unit (1/300 inch) as the unit of measure.
        Document = 5,
        /// @brief Specifies the millimeter as the unit of measure.
        Millimeter = 6
      };
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Drawing::GraphicsUnit> {
  void operator()(System::Collections::Generic::IDictionary<System::Drawing::GraphicsUnit, string>& values, bool& flags) {
    values[System::Drawing::GraphicsUnit::World] = "World";
    values[System::Drawing::GraphicsUnit::Display] = "Display";
    values[System::Drawing::GraphicsUnit::Pixel] = "Pixel";
    values[System::Drawing::GraphicsUnit::Point] = "Point";
    values[System::Drawing::GraphicsUnit::Inch] = "Inch";
    values[System::Drawing::GraphicsUnit::Document] = "Document";
    values[System::Drawing::GraphicsUnit::Millimeter] = "Millimeter";
    flags = false;
  }
};
/// @endcond

using namespace Switch;

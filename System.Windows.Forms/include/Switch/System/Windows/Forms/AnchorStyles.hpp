/// @file
/// @brief Contains Switch::System::Windows::Forms::AnchorStyles enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Specifies how a control anchors to the edges of its container.
        /// @remarks When a control is anchored to an edge of its container, the distance between the control and the specified edge remains constant when the container resizes. For example, if a control is anchored to the right edge of its container, the distance between the right edge of the control and the right edge of the container remains constant when the container resizes. A control can be anchored to any combination of control edges. If the control is anchored to opposite edges of its container (for example, to the top and bottom), it resizes when the container resizes. If a control has its Anchor property set to AnchorStyles.None, the control moves half of the distance that the container of the control is resized. For example, if a Button has its Anchor property set to AnchorStyles.None and the Form that the control is located on is resized by 20 pixels in either direction, the button will be moved 10 pixels in both directions.
        enum class AnchorStyles {
          /// @brief The control is not anchored to any edges of its container.
          None = 0,
          /// @brief The control is anchored to the top edge of its container.
          Top = 0b1,
          /// @brief The control is anchored to the bottom edge of its container.
          Bottom = 0b10,
          /// @brief The control is anchored to the left edge of its container.
          Left = 0b100,
          /// @brief The control is anchored to the right edge of its container.
          Right = 0b1000,
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::AnchorStyles> : public TrueType {};

template<>
struct EnumRegister<System::Windows::Forms::AnchorStyles> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::AnchorStyles, string>& values, bool& flags) {
    values[System::Windows::Forms::AnchorStyles::None] = "None";
    values[System::Windows::Forms::AnchorStyles::Top] = "Top";
    values[System::Windows::Forms::AnchorStyles::Bottom] = "Bottom";
    values[System::Windows::Forms::AnchorStyles::Left] = "Left";
    values[System::Windows::Forms::AnchorStyles::Right] = "Right";
    flags = true;
  }
};
/// @endcond

using namespace Switch;

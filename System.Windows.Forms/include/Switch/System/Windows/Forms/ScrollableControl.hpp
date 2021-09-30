/// @file
/// @brief Contains Switch::System::Windows::Forms::ScrollableControl class.
#pragma once

#include "../../../SystemWindowsFormsExport.hpp"
#include "Control.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Defines a base class for controls that support auto-scrolling behavior.
        class system_windows_forms_export_ ScrollableControl : public Control {
        public:
          /// @brief Initializes a new instance of the ScrollableControl class with default settings.
          ScrollableControl() {}

          /// @brief Initializes a new instance of the ScrollableControl class with specific text, size, and location.
          /// @param text The text displayed by the control.
          /// @param left The X position of the control, in pixels, from the left edge of the control's container. The value is assigned to the Left property.
          /// @param top The Y position of the control, in pixels, from the top edge of the control's container. The value is assigned to the Top property.
          /// @param width The height of the control, in pixels. The value is assigned to the Height property.
          /// @param height The width of the control, in pixels. The value is assigned to the Width property.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          /// @remarks This version of the Control constructor sets the initial Text property value to the text parameter value. The initial Size and Location of the control are determined by the left, top, width and height parameter values.
          /// @note To maintain better performance, do not set the size of a control in its constructor. The preferred method is to virtual the DefaultSize property.
          ScrollableControl(const string& text, int32 left, int32 top, int32 width, int32 height) : Control(text, left, top, width, height) {}

          /// @cond
          ScrollableControl(const ScrollableControl& scrollableControl) : Control(scrollableControl) {}
          /// @endcond

          property_<bool> HScroll {
            get_ {return this->hscroll;},
            set_ {this->hscroll = value;}
          };

          property_<bool> VScroll {
            get_ {return this->vscroll;},
            set_ {this->vscroll = value;}
          };

        protected:
          /// @cond
          bool hscroll = false;
          bool vscroll = false;
          /// @endcond
        };
      }
    }
  }
}

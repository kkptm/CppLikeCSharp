/// @file
/// @brief Contains Switch::System::Windows::Forms::ListControl class.
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
        /// @brief Provides a common implementation of members for the ListBox and ComboBox classes.
        class system_windows_forms_export_ ListControl: public Control {
        public:
          /// @brief Initializes a new instance of the ListControl class with default settings.
          ListControl() {}

          /// @brief Initializes a new instance of the ListControl class with specific text, size, and location.
          /// @param text The text displayed by the control.
          /// @param left The X position of the control, in pixels, from the left edge of the control's container. The value is assigned to the Left property.
          /// @param top The Y position of the control, in pixels, from the top edge of the control's container. The value is assigned to the Top property.
          /// @param width The height of the control, in pixels. The value is assigned to the Height property.
          /// @param height The width of the control, in pixels. The value is assigned to the Width property.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          /// @remarks This version of the Control constructor sets the initial Text property value to the text parameter value. The initial Size and Location of the control are determined by the left, top, width and height parameter values.
          /// @note To maintain better performance, do not set the size of a control in its constructor. The preferred method is to virtual the DefaultSize property.
          ListControl(const string& text, int32 left, int32 top, int32 width, int32 height) { /*: Control(text, left, top, width, height)*/
          }

          /// @cond
          ListControl(const ListControl& listControl) : Control(listControl) {}
          /// @endcond

          const string& ValueMember() const {
            return this->valueMember;
          }

          void SetValueMember(const string& valueMember) {
            if (this->valueMember != valueMember) {
              this->valueMember = valueMember;
              ValueMemberChanged(*this, EventArgs::Empty);
            }
          }

          EventHandler ValueMemberChanged;

        private:
          string valueMember;
        };
      }
    }
  }
}

/// @file
/// @brief Contains Switch::System::Windows::Forms::UICuesEventArgs class.
#pragma once

#include <Switch/System/EventArgs.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "UICues.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Provides data for the Control::ChangeUICues event.
        /// @remarks A System::Windows::Forms::UICuesEventArgs specifies which user interface feature changed and its new value.
        /// @remarks The Control::ChangeUICues event occurs when the user interface changes by showing or hiding focus indicators or keyboard cues. This is usually when the user presses the TAB, ALT, or F10 keys.
        class system_windows_forms_export_ UICuesEventArgs : public EventArgs {
        public:
          /// @brief Initializes a new instance of the UICuesEventArgs class.
          UICuesEventArgs() {}
          /// @brief Initializes a new instance of the UICuesEventArgs class with the specified UICues.
          /// @param change A bitwise combination of the UICues values.
          UICuesEventArgs(const UICues& change) : changed(change) {}

          /// @brief Gets the bitwise combination of the UICues values.
          /// @return A bitwise combination of the UICues values. The default is Changed.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the Control.ChangeUICues event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.
          /// To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the Control.ChangeUICues event.
          /// @code
          /// void Control1ChangeUICues(const bject& sender, const UICuesEventArgs& e) {
          ///   System::Text::StringBuilder messageBoxCS;
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ShowFocus", e.ShowFocus());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ShowKeyboard", e.ShowKeyboard());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ChangeFocus", e.ChangeFocus());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ChangeKeyboard", e.ChangeKeyboard());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "Changed", e.Changed());
          ///   messageBoxCS.AppendLine();
          ///   MessageBox::Show(messageBoxCS.ToString(), "ChangeUICues Event");
          /// }
          /// @endcode
          const UICues& Changed() const { return changed; }

          /// @brief Gets a value indicating whether the state of the focus cues has changed.
          /// @return A bitwise combination of the UICues values. The default is Changed.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the Control.ChangeUICues event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.
          /// To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the Control.ChangeUICues event.
          /// @code
          /// void Control1ChangeUICues(const bject& sender, const UICuesEventArgs& e) {
          ///   System::Text::StringBuilder messageBoxCS;
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ShowFocus", e.ShowFocus());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ShowKeyboard", e.ShowKeyboard());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ChangeFocus", e.ChangeFocus());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ChangeKeyboard", e.ChangeKeyboard());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "Changed", e.Changed());
          ///   messageBoxCS.AppendLine();
          ///   MessageBox::Show(messageBoxCS.ToString(), "ChangeUICues Event");
          /// }
          /// @endcode
          bool ChangeFocus() const { return Enum<UICues>(this->changed).HasFlag(UICues::ChangeFocus); }

          /// @brief Gets a value indicating whether the state of the keyboard cues has changed.
          /// @return true if the state of the keyboard cues has changed; otherwise, false.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the Control.ChangeUICues event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.
          /// To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the Control.ChangeUICues event.
          /// @code
          /// void Control1ChangeUICues(const bject& sender, const UICuesEventArgs& e) {
          ///   System::Text::StringBuilder messageBoxCS;
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ShowFocus", e.ShowFocus());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ShowKeyboard", e.ShowKeyboard());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ChangeFocus", e.ChangeFocus());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ChangeKeyboard", e.ChangeKeyboard());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "Changed", e.Changed());
          ///   messageBoxCS.AppendLine();
          ///   MessageBox::Show(messageBoxCS.ToString(), "ChangeUICues Event");
          /// }
          /// @endcode
          bool ChangeKeyboard() const { return Enum<UICues>(this->changed).HasFlag(UICues::ChangeKeyboard); }

          /// @brief Gets a value indicating whether focus rectangles are shown after the change.
          /// @return true if focus rectangles are shown after the change; otherwise, false.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the Control.ChangeUICues event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.
          /// To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the Control.ChangeUICues event.
          /// @code
          /// void Control1ChangeUICues(const bject& sender, const UICuesEventArgs& e) {
          ///   System::Text::StringBuilder messageBoxCS;
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ShowFocus", e.ShowFocus());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ShowKeyboard", e.ShowKeyboard());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ChangeFocus", e.ChangeFocus());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ChangeKeyboard", e.ChangeKeyboard());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "Changed", e.Changed());
          ///   messageBoxCS.AppendLine();
          ///   MessageBox::Show(messageBoxCS.ToString(), "ChangeUICues Event");
          /// }
          /// @endcode
          bool ShowFocus() const { return Enum<UICues>(this->changed).HasFlag(UICues::ShowFocus); }

          /// @brief Gets a value indicating whether keyboard cues are underlined after the change.
          /// @return true if keyboard cues are underlined after the change; otherwise, false.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the Control.ChangeUICues event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.
          /// To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the Control.ChangeUICues event.
          /// @code
          /// void Control1ChangeUICues(const bject& sender, const UICuesEventArgs& e) {
          ///   System::Text::StringBuilder messageBoxCS;
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ShowFocus", e.ShowFocus());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ShowKeyboard", e.ShowKeyboard());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ChangeFocus", e.ChangeFocus());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ChangeKeyboard", e.ChangeKeyboard());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "Changed", e.Changed());
          ///   messageBoxCS.AppendLine();
          ///   MessageBox::Show(messageBoxCS.ToString(), "ChangeUICues Event");
          /// }
          /// @endcode
          bool ShowKeyboard() const { return Enum<UICues>(this->changed).HasFlag(UICues::ShowKeyboard); }

        private:
          UICues changed;
        };
      }
    }
  }
}

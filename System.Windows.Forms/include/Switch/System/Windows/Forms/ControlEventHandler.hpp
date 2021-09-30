/// @file
/// @brief Contains Switch::System::Windows::Forms::ControlEventHandler event handler.
#pragma once

#include <Switch/System/EventHandler.hpp>

#include "ControlEventArgs.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Represents the method that will handle the ControlAdded and ControlRemoved events of the Control class.
        /// @param sender The source of the event.
        /// @param e A ControlEventArgs that contains the event data.
        /// @remarks When you create a ControlEventArgs delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate. For more information about event handler delegates, see Handling and Raising Events.
        /// @par Examples
        /// The following code example demonstrates the use of the ControlAdded and ControlRemoved events. The example requires that two Button controls are added to the form and connected to the addControl_Click and removeControl_Click event handling methods.
        /// @code
        /// // This example demonstrates the use of the ControlAdded and
        /// // ControlRemoved events. This example assumes that two Button controls
        /// // are added to the form and connected to the AddControlClick and
        /// // RemoveControlClick event-handler methods.
        /// void Form1Load(const object& sender, const System::EventArgs& e) {
        ///   // Connect the ControlRemoved and ControlAdded event handlers
        ///   // to the event-handler methods.
        ///   // ControlRemoved and ControlAdded are not available at design time.
        ///   ControlRemoved += new System::Windows::Forms::ControlEventHandler(*this, &Form1::ControlRemoved);
        ///   ControlAdded += new System::Windows::Forms::ControlEventHandler(*this, &Form1::ControlAdded);
        /// }
        /// void ControlAdded(const object& sender, const System::Windows::Forms::ControlEventArgs& e) {
        ///   MessageBox::Show("The control named " + e.Control()->Name() + " has been added to the form.");
        /// }
        /// void ControlRemoved(const object& sender, const System::Windows::Forms::ControlEventArgs& e) {
        ///   MessageBox::Show("The control named " + e.Control()->Name() + " has been removed from the form.");
        /// }
        /// // Click event handler for a Button control. Adds a TextBox to the form.
        /// void AddControlClick(const object& sender, const System::EventArgs& e) {
        ///   // Create a new TextBox control and add it to the form.
        ///   refptr<TextBox> textBox1 = new TextBox();
        ///   textBox1->Size(Size(100, 10));
        ///   textBox1->Location(Point(10, 10));
        ///   // Name the control in order to remove it later. The name must be specified
        ///   // if a control is added at run time.
        ///   textBox1->Name("textBox1");
        ///   // Add the control to the form's control collection.
        ///   Controls.Add(textBox1);
        /// }
        /// // Click event handler for a Button control.
        /// // Removes the previously added TextBox from the form.
        /// void RemoveControlClick(const object& sender, const System::EventArgs& e) {
        ///   // Loop through all controls in the form's control collection.
        ///   for (refptr<Control> tempCtrl : Controls) {
        ///     // Determine whether the control is textBox1,
        ///     // and if it is, remove it.
        ///     if (tempCtrl->Name() == "textBox1") {
        ///       Controls.Remove(tempCtrl);
        ///     }
        ///   }
        /// }
        /// @endcode
        using ControlEventHandler = GenericEventHandler<const ControlEventArgs&>;
      }
    }
  }
}

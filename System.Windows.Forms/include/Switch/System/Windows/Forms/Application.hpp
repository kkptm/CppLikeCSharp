/// @file
/// @brief Contains Switch::System::Windows::Forms::Application class.
#pragma once

#include <Switch/Static.hpp>
#include <Switch/System/EventHandler.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "Form.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Provides static methods and properties to manage an application, such as methods to start and stop an application, to process Windows messages, and properties to get information about an application. This class cannot be inherited.
        class system_windows_forms_export_ Application static_ {
        public:
          static void EnableVisualStyles();

          /// @brief Informs all message pumps that they must terminate, and then closes all application windows after the messages have been processed.
          /// @remarks The Exit method stops all running message loops on all threads and closes all windows of the application. This method does not necessarily force the application to exit. The Exit method is typically called from within a message loop, and forces Run to return. To exit a message loop for the current thread only, call ExitThread.
          /// @remarks Exit raises the following events and performs the associated conditional actions:
          /// * A FormClosing event is raised for every form represented by the OpenForms property. This event can be canceled by setting the Cancel property of their FormClosingEventArgs parameter to true.
          /// * If one of more of the handlers cancels the event, then Exit returns without further action. Otherwise, a FormClosed event is raised for every open form, then all running message loops and forms are closed.
          /// @note The Exit method does not raise the Closed and Closing events
          static void Exit();

          /// @brief Begins running a standard application message loop on the current thread, without a form.
          /// @exception InvalidOperationException A main message loop is already running on this thread.
          /// @remarks In a Win32-based or Windows Forms application, a message loop is a routine in code that processes user events, such as mouse clicks and keyboard strokes. Every running Windows-based application requires an active message loop, called the main message loop. When the main message loop is closed, the application exits. In Windows Forms, this loop is closed when the Exit method is called, or when the ExitThread method is called on the thread that is running the main message loop.
          /// @remarks Most Windows Forms developers will not need to use this version of the method. You should use the Run(Form) overload to start an application with a main form, so that the application terminates when the main form is closed. For all other situations, use the Run(ApplicationContext) overload, which supports supplying an ApplicationContext object for better control over the lifetime of the application.
          static void Run() {
            Start();
            MessageLoop();
          }

          /// @brief Begins running a standard application message loop on the current thread, and makes the specified form visible.
          /// @param mainForm A Form that represents the form to make visible.
          /// @remarks Typically, the main function of an application calls this method and passes to it the main window of the application.
          /// @remarks This method adds an event handler to the mainForm parameter for the Closed event. The event handler calls ExitThread to clean up the application.
          template <typename TForm>
          static void Run(const TForm& mainForm) {
            Start();
            Application::mainForm = as<Form>(mainForm);
            Application::mainForm().Visible = true;
            Application::mainForm().FormClosed += delegate_(const object & sender, const FormClosedEventArgs & e) {
              Exit();
            };
            MessageLoop();
          }

          /// @brief Occurs when the application finishes processing and is about to enter the idle state.
          static EventHandler Idle;

        private:
          static void AddForm();
          static void Start();
          static void MessageLoop();
          static ref<Form> mainForm;
        };
      }
    }
  }
}

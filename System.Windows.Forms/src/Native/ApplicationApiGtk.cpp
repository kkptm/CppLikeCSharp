#if defined(__linux__)

#undef interface_
#undef get_
#undef set_

#include <gtkmm.h>
#include <gtkmm/application.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/window.h>
#include <Switch/System/Console.hpp>
#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

extern Glib::RefPtr<Gtk::Application> __application__;

namespace {
  int32 exitCode = 0;
}

bool Native::ApplicationApi::visualStylesEnabled = false;

void Native::ApplicationApi::Exit() {
  Environment::Exit(exitCode);
}

void Native::ApplicationApi::MessageLoop(const System::Windows::Forms::Form& mainForm, EventHandler idle) {
  Glib::signal_idle().connect(delegate_ {
    idle.Invoke(object(), EventArgs::Empty);
    return mainForm.Visible() && !idle.IsEmpty();
  });
  exitCode = __application__->run(as<Gtk::Window>(((Native::IWidget*)mainForm.Handle())->ToWidget()));
}

namespace {
  void AddButtons(Gtk::MessageDialog& dialog, MessageBoxButtons buttons) {
    switch (buttons) {
    case MessageBoxButtons::AbortRetryIgnore:
      dialog.add_button("Abort", (int)DialogResult::Abort);
      dialog.add_button("Retry", (int)DialogResult::Retry);
      dialog.add_button("Ignore", (int)DialogResult::Ignore);
      break;
    case MessageBoxButtons::OK:
      dialog.add_button("Ok", (int)DialogResult::OK);
      break;
    case MessageBoxButtons::OKCancel:
      dialog.add_button("Ok", (int)DialogResult::OK);
      dialog.add_button("Cancel", (int)DialogResult::Cancel);
      break;
    case MessageBoxButtons::RetryCancel:
      dialog.add_button("Retry", (int)DialogResult::Retry);
      dialog.add_button("Cancel", (int)DialogResult::Cancel);
      break;
    case MessageBoxButtons::YesNo:
      dialog.add_button("Yes", (int)DialogResult::Yes);
      dialog.add_button("No", (int)DialogResult::No);
      break;
    case MessageBoxButtons::YesNoCancel:
      dialog.add_button("Yes", (int)DialogResult::Yes);
      dialog.add_button("No", (int)DialogResult::No);
      dialog.add_button("Cancel", (int)DialogResult::Cancel);
      break;
    }
  }
}

DialogResult Native::ApplicationApi::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  static System::Collections::Generic::Dictionary<MessageBoxIcon, Gtk::MessageType> icons = {{MessageBoxIcon::None, Gtk::MESSAGE_OTHER}, {MessageBoxIcon::Error, Gtk::MESSAGE_ERROR}, {MessageBoxIcon::Question, Gtk::MESSAGE_QUESTION}, {MessageBoxIcon::Warning, Gtk::MESSAGE_WARNING}, {MessageBoxIcon::Information, Gtk::MESSAGE_INFO}};
  static refptr<Gtk::Window> emptyWindow = ref_new<Gtk::Window>();
  Gtk::Window* activeWindow = __application__->get_active_window();
  if (activeWindow == null) activeWindow = emptyWindow.ToPointer();
  Gtk::MessageDialog dialog(*activeWindow, caption.c_str(), true /* use_markup */, icons[icon], Gtk::BUTTONS_NONE, true);
  AddButtons(dialog, buttons);
  dialog.set_secondary_text(message.c_str());
  dialog.set_modal();
  dialog.set_position(Gtk::WindowPosition::WIN_POS_CENTER);
  int result = dialog.run();
  if (result < 0)
    return DialogResult::Cancel;
  return (DialogResult)result;
}

void Native::ApplicationApi::Start() {
  // no implementation
}

void Native::ApplicationApi::Stop() {
  // no implementation
}

#endif

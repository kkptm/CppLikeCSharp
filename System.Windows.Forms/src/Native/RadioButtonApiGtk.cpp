#if defined(__linux__)

#include <gtkmm/radiobutton.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class RadioButton : public Widget, public Gtk::RadioButton {
  public:
    RadioButton() {this->RegisterEvent();}
    void Text(const string& text) override {this->set_label(text.c_str());}
  };
}

intptr Native::RadioButtonApi::Create(const System::Windows::Forms::RadioButton& radioButton) {
  Native::RadioButton* handle = new Native::RadioButton();
  handle->Move(radioButton.Location().X, radioButton.Location().Y);
  handle->Text(radioButton.Text);
  handle->show();
  return (intptr)handle;
}

void Native::RadioButtonApi::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  ((Native::RadioButton*)radioButton.Handle())->set_active(radioButton.Checked);
}

void Native::RadioButtonApi::SetGroup(const System::Windows::Forms::RadioButton& radioButton) {
  ((Native::RadioButton*)radioButton.Handle())->reset_group();
  if (radioButton.Parent != null)
    ((Native::RadioButton*)radioButton.Handle())->set_group(((Native::Widget*)radioButton.Parent()().Handle())->RadioButtonGroup());
}

#endif

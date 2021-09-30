#if defined(__linux__)

#include <gtkmm/button.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class Button : public Widget, public Gtk::Button {
  public:
    Button() {this->RegisterEvent();}
    void Text(const string& text) override {this->set_label(text.c_str());}
  };
}

intptr Native::ButtonApi::Create(const System::Windows::Forms::Button& button) {
  Native::Button* handle = new Native::Button();
  handle->Move(button.Location().X, button.Location().Y);
  handle->Text(button.Text);
  handle->show();
  return (intptr)handle;
}

void Native::ButtonApi::SetIsDefault(const System::Windows::Forms::Button& button) {

}

#endif

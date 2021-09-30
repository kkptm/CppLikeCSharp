#if defined(__linux__)

#include <gtkmm/frame.h>
#include <gtkmm/scrolledwindow.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class GroupBox : public Widget, public Gtk::Frame {
  public:
    GroupBox() {
      this->RegisterEvent();
      this->add(this->scrolledWindow);
      this->scrolledWindow.add(this->fixed);

      this->signal_show().connect(delegate_ {
        this->scrolledWindow.show();
        this->fixed.show();
      });
    }

    const Gtk::Container& Container() const override {return this->fixed;}

    Gtk::Container& Container() override {return this->fixed;}

    void Text(const string& text) override {this->set_label(text.c_str());}

  private:
    Gtk::ScrolledWindow scrolledWindow;
    Gtk::Fixed fixed;
  };
}

intptr Native::GroupBoxApi::Create(const System::Windows::Forms::GroupBox& groupBox) {
  Native::GroupBox* handle = new Native::GroupBox();
  handle->Move(groupBox.Location().X, groupBox.Location().Y);
  handle->Text(groupBox.Text);
  handle->set_shadow_type(Gtk::SHADOW_IN);
  handle->show();
  return (intptr)handle;
}

#endif

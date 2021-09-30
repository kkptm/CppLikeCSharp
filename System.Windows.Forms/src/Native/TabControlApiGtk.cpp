#if defined(__linux__)

#include <gtkmm/notebook.h>
#include <gtkmm/scrolledwindow.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class TabControl : public Widget, public Gtk::Notebook {
  public:
    TabControl() {
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

    void Text(const string& text) override {}

  private:
    Gtk::ScrolledWindow scrolledWindow;
    Gtk::Fixed fixed;
  };
}

intptr Native::TabControlApi::Create(const System::Windows::Forms::TabControl& tabControl) {
  Native::TabControl* handle = new Native::TabControl();
  handle->Move(tabControl.Location().X, tabControl.Location().Y);
  handle->Text(tabControl.Text);
  handle->show();
  return (intptr)handle;
}

void Native::TabControlApi::SetAlignment(const System::Windows::Forms::TabControl& tabControl) {
}

#endif

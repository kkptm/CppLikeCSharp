#if defined(__linux__)

#include <gtkmm/frame.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/notebook.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class TabPage : public Widget, public Gtk::Frame {
  public:
    TabPage() {
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

intptr Native::TabPageApi::Create(const System::Windows::Forms::TabPage& tabPage) {
  Native::TabPage* handle = new Native::TabPage();
  handle->Text(tabPage.Text);
  handle->show();
  return (intptr)handle;
}

#endif

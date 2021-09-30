#if defined(__linux__)

#include <gtkmm/frame.h>
#include <gtkmm/scrolledwindow.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class Panel : public Widget, public Gtk::Frame {
  public:
    Panel() {
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

intptr Native::PanelApi::Create(const System::Windows::Forms::Panel& panel) {
  Native::Panel* handle = new Native::Panel();
  handle->Move(panel.Location().X, panel.Location().Y);
  handle->Text(panel.Text);
  handle->show();
  return (intptr)handle;
}

void Native::PanelApi::SetBorderStyle(const System::Windows::Forms::Panel& panel) {
  switch (panel.BorderStyle) {
  case System::Windows::Forms::BorderStyle::None: ((Native::Panel*)panel.Handle())->set_shadow_type(Gtk::SHADOW_NONE); break;
  case System::Windows::Forms::BorderStyle::FixedSingle: ((Native::Panel*)panel.Handle())->set_shadow_type(Gtk::SHADOW_IN); break;
  case System::Windows::Forms::BorderStyle::Fixed3D: ((Native::Panel*)panel.Handle())->set_shadow_type(Gtk::SHADOW_ETCHED_IN); break;
  }
}

#endif

#if defined(__linux__)

#include <gtkmm.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class ProgressBar : public Widget, public Gtk::ProgressBar {
  public:
    ProgressBar() {this->RegisterEvent();}
    void BackColor(const System::Drawing::Color& color) override {}

    void Text(const string& text) override {}
    guint marquee = 0;
    bool isMarquee = false;
  };

  int MarqueeProc(gpointer progressBar) {
    ((Native::ProgressBar*)progressBar)->pulse();
    return 1;
  }
}

intptr Native::ProgressBarApi::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  Native::ProgressBar* handle = new Native::ProgressBar();
  handle->Move(progressBar.Location().X, progressBar.Location().Y);
  handle->Text(progressBar.Text);
  handle->show();
  return (intptr)handle;
}

void Native::ProgressBarApi::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {
  // no implementation
}

void Native::ProgressBarApi::SetMinimum(const System::Windows::Forms::ProgressBar& progressBar) {
  // no implementation
}

void Native::ProgressBarApi::SetMarquee(const System::Windows::Forms::ProgressBar& progressBar) {
  if (progressBar.Style == ProgressBarStyle::Marquee) {
    ((Native::ProgressBar*)progressBar.Handle())->isMarquee = true;
    ((Native::ProgressBar*)progressBar.Handle())->marquee = g_timeout_add(progressBar.MarqueeAnimationSpeed(), MarqueeProc, (gpointer)progressBar.Handle());
  } else {
    if (((Native::ProgressBar*)progressBar.Handle())->isMarquee == true) {
      g_source_remove(((Native::ProgressBar*)progressBar.Handle())->marquee);
      ((Native::ProgressBar*)progressBar.Handle())->isMarquee = false;
    }
  }
}

void Native::ProgressBarApi::SetValue(const System::Windows::Forms::ProgressBar& progressBar) {
  ((Native::ProgressBar*)progressBar.Handle())->set_fraction(double(progressBar.Value()) / (double(progressBar.Maximum()) - double(progressBar.Minimum)));
}

#endif

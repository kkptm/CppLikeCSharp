#if defined(__linux__)

#include <gtkmm/widget.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class Control : public Widget, public Gtk::Widget {
  public:
    Control() {this->RegisterEvent();}
    void Text(const string& text) override {}
  };
}

intptr Native::ControlApi::Create(const System::Windows::Forms::Control& control) {
  Native::Control* handle = new Native::Control();
  handle->Move(control.Location().X, control.Location().Y);
  handle->Text(control.Text);
  handle->show();
  return (intptr)handle;
}

void Native::ControlApi::DefWndProc(System::Windows::Forms::Message& message) {

}

void Native::ControlApi::Destroy(const System::Windows::Forms::Control& control) {
  delete (Gtk::Widget*)control.Handle();
}

intptr Native::ControlApi::GetHandleWindowFromDeviceContext(intptr hdc) {
  return hdc;
}

void Native::ControlApi::Invalidate(const System::Windows::Forms::Control& control, bool invalidateChildren) {

}

void Native::ControlApi::Invalidate(const System::Windows::Forms::Control& control, const System::Drawing::Rectangle& rect, bool invalidateChildren) {

}

System::Drawing::Point Native::ControlApi::PointToClient(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  System::Drawing::Point pointToClient = point - control.Location();
  ref<System::Windows::Forms::Control> workControl = control;
  while (workControl().Parent() != null && !is<System::Windows::Forms::Form>(workControl().Parent())) {
    workControl = workControl().Parent();
    pointToClient -= workControl().Location();
  }

  if (workControl().Parent != null)
    pointToClient -= workControl().Parent()().Location();

  return pointToClient;
}

System::Drawing::Point Native::ControlApi::PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  System::Drawing::Point pointToScreen = point + control.Location();
  ref<System::Windows::Forms::Control> workControl = control;
  while (workControl().Parent != null && !is<System::Windows::Forms::Form>(workControl().Parent())) {
    workControl = workControl().Parent();
    pointToScreen += workControl().Location();
  }

  if (workControl().Parent != null)
    pointToScreen += workControl().Parent()().Location();

  return pointToScreen;
}

intptr Native::ControlApi::SendMessage(intptr handle, int32 msg, intptr wparam, intptr lparam) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(handle);
  if (control == null) return -1;
  System::Windows::Forms::Message message = System::Windows::Forms::Message::Create(handle, msg, wparam, lparam, 0);
  control().WndProc(message);
  return message.Result;
}

void Native::ControlApi::SetBackColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  ((Native::Widget*)control().Handle())->BackColor(System::Environment::OSVersion().Platform == System::PlatformID::MacOSX && is<System::Windows::Forms::Button>(control) && as<System::Windows::Forms::Button>(control)().IsDefault ? System::Drawing::SystemColors::Highlight() : control().BackColor());
}

void Native::ControlApi::SetBackColor(const System::Windows::Forms::Control& control) {
  ((Native::Widget*)control.Handle())->BackColor(System::Environment::OSVersion().Platform == System::PlatformID::MacOSX && is<System::Windows::Forms::Button>(control) && as<System::Windows::Forms::Button>(control).IsDefault ? System::Drawing::SystemColors::Highlight() : control.BackColor());
}

void Native::ControlApi::SetClientSize(System::Windows::Forms::Control& control) {
  ((Native::Widget*)control.Handle())->ToWidget().set_size_request(control.ClientSize().Width, control.ClientSize().Height);
  if (is<System::Windows::Forms::Form>(control))
    control.Size = System::Drawing::Size::Add(control.ClientSize, {0, SystemInformationApi::GetCaptionHeight()});
  else
    control.Size = control.ClientSize;
}

void Native::ControlApi::SetEnabled(const System::Windows::Forms::Control& control) {
  ((Native::Widget*)control.Handle())->ToWidget().set_sensitive(control.Enabled);
}

bool Native::ControlApi::SetFocus(const System::Windows::Forms::Control& control) {
  ((Native::Widget*)control.Handle())->ToWidget().grab_focus();
  return true;
}

void Native::ControlApi::SetForeColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  ((Native::Widget*)control().Handle())->ForeColor(System::Environment::OSVersion().Platform == System::PlatformID::MacOSX && is<System::Windows::Forms::Button>(control) && as<System::Windows::Forms::Button>(control)().IsDefault ? System::Drawing::Color::White() : control().ForeColor());
}

void Native::ControlApi::SetForeColor(const System::Windows::Forms::Control& control) {
  ((Native::Widget*)control.Handle())->ForeColor(System::Environment::OSVersion().Platform == System::PlatformID::MacOSX && is<System::Windows::Forms::Button>(control) && as<System::Windows::Forms::Button>(control).IsDefault ? System::Drawing::Color::White() : control.ForeColor());
}

void Native::ControlApi::SetLocation(const System::Windows::Forms::Control& control) {
  ((Native::Widget*)control.Handle())->Move(control.Location().X, control.Location().Y);
}

void Native::ControlApi::SetParent(const System::Windows::Forms::Control& control) {
  if (control.Parent() != null) {
    //((Native::Widget*)control.Handle())->ToWidget().reparent(((Native::Widget*)control.Parent()().Handle())->Container());
    ((Native::Widget*)control.Parent()().Handle())->Container().add(((Native::Widget*)control.Handle())->ToWidget());
    SetLocation(control);
    SetVisible(control);
  }
}

void Native::ControlApi::SetSize(System::Windows::Forms::Control& control) {
  if (is<System::Windows::Forms::Form>(control)) {
    ((Native::Widget*)control.Handle())->ToWidget().set_size_request(control.Width, control.Height - SystemInformationApi::GetCaptionHeight());
    control.ClientSize = System::Drawing::Size::Subtract(control.Size, {0, SystemInformationApi::GetCaptionHeight()});
  } else {
    ((Native::Widget*)control.Handle())->ToWidget().set_size_request(control.Width, control.Height);
    control.ClientSize = control.Size;
  }
}

void Native::ControlApi::SetTabStop(const System::Windows::Forms::Control& control) {
  ((Native::Widget*)control.Handle())->ToWidget().set_can_focus(control.TabStop);
}

void Native::ControlApi::SetText(const System::Windows::Forms::Control& control) {
  ((Native::Widget*)control.Handle())->Text(control.Text);
}

void Native::ControlApi::SetVisible(const System::Windows::Forms::Control& control) {
  ((Gtk::Widget*)control.Handle())->show();
}

#endif

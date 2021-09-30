#if defined(__linux__)

#undef interface_
#undef get_
#undef set_

#include <gtkmm.h>
#include "Api.hpp"

using namespace System;
using namespace Native;

Glib::RefPtr<Gtk::Application> __application__ = Gtk::Application::create();

namespace {
  System::Drawing::Color ToColor(const Gdk::RGBA& color) {
    return System::Drawing::Color::FromArgb(color.get_alpha() * 255, color.get_red() * 255, color.get_green() * 255, color.get_blue() * 255);
  }
}

int32 Native::SystemColorsApi::GetActiveBorder() {
  return (int32)0xFFB4B4B4;
}

int32 Native::SystemColorsApi::GetActiveCaption() {
  return (int32)0xFF99B4D1;
}

int32 Native::SystemColorsApi::GetActiveCaptionText() {
  return (int32)0xFF000000;
}

int32 Native::SystemColorsApi::GetAppWorkspace() {
  return (int32)0xFFABABAB;
}

int32 Native::SystemColorsApi::GetButtonFace() {
  return ToColor(Gtk::Button().get_style_context()->get_background_color()).ToArgb();
}

int32 Native::SystemColorsApi::GetButtonHighlight() {
  return (int32)0xFFFFFFFF;
}

int32 Native::SystemColorsApi::GetButtonShadow() {
  return (int32)0xFFF0F0F0;
}

int32 Native::SystemColorsApi::GetControl() {
  return ToColor(Gtk::Button().get_style_context()->get_background_color()).ToArgb();
}

int32 Native::SystemColorsApi::GetControlDark() {
  return ToColor(Gtk::Button().get_style_context()->get_background_color()).ToArgb();
}

int32 Native::SystemColorsApi::GetControlDarkDark() {
  return ToColor(Gtk::Button().get_style_context()->get_background_color()).ToArgb();
}

int32 Native::SystemColorsApi::GetControlLight() {
  return ToColor(Gtk::Button().get_style_context()->get_background_color()).ToArgb();
}

int32 Native::SystemColorsApi::GetControlLightLight() {
  return ToColor(Gtk::Button().get_style_context()->get_background_color()).ToArgb();
}

int32 Native::SystemColorsApi::GetControlText() {
  //return ToColor(Gtk::Button().get_style_context()->get_color()).ToArgb();
  return ToColor(Gtk::Window().get_style_context()->get_color()).ToArgb();
}

int32 Native::SystemColorsApi::GetDesktop() {
  return (int32)0xFF000000;
}

int32 Native::SystemColorsApi::GetGradientActiveCaption() {
  return (int32)0xFF99B4D1;
}

int32 Native::SystemColorsApi::GetGradientInactiveCaption() {
  return (int32)0xFF9DB9EB;
}

int32 Native::SystemColorsApi::GetGrayText() {
  return (int32)0xFF6D6D6D;
}

int32 Native::SystemColorsApi::GetHighlight() {
  return (int32)0xFF3399FF;
}

int32 Native::SystemColorsApi::GetHighlightText() {
  return (int32)0xFFFFFFFF;
}

int32 Native::SystemColorsApi::GetHotTrack() {
  return (int32)0xFF0066CC;
}

int32 Native::SystemColorsApi::GetInactiveBorder() {
  return (int32)0xFFF4F7FC;
}

int32 Native::SystemColorsApi::GetInactiveCaption() {
  return (int32)0xFFBFCDDB;
}

int32 Native::SystemColorsApi::GetInactiveCaptionText() {
  return (int32)0xFF000000;
}

int32 Native::SystemColorsApi::GetInfo() {
  return (int32)0xFFFFFFE1;
}

int32 Native::SystemColorsApi::GetInfoText() {
  return (int32)0xFF000000;
}

int32 Native::SystemColorsApi::GetMenu() {
  return (int32)0xFFF0F0F0;
}

int32 Native::SystemColorsApi::GetMenuBar() {
  return (int32)0xFFF0F0F0;
}

int32 Native::SystemColorsApi::GetMenuHighlight() {
  return (int32)0xFF3399FF;
}

int32 Native::SystemColorsApi::GetMenuText() {
  return (int32)0xFF000000;
}

int32 Native::SystemColorsApi::GetScrollBar() {
  return (int32)0xFFC8C8C8;
}

int32 Native::SystemColorsApi::GetWindow() {
  return ToColor(Gtk::Window().get_style_context()->get_background_color()).ToArgb();
}

int32 Native::SystemColorsApi::GetWindowFrame() {
  return ToColor(Gtk::Window().get_style_context()->get_border_color()).ToArgb();
}

int32 Native::SystemColorsApi::GetWindowText() {
  return ToColor(Gtk::Window().get_style_context()->get_color()).ToArgb();
}

#endif

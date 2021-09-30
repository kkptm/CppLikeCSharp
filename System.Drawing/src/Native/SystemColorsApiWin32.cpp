#if defined(_WIN32)
#include <windows.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"

using namespace System;

namespace {
  inline int32 GetSystemColor(int32 index) {
    DWORD color = GetSysColor(index);
    return (int32(0xFF) << 24) + (int32(GetRValue(color)) << 16) + (int32(GetGValue(color)) << 8) + int32(GetBValue(color));
  }
}

int32 Native::SystemColorsApi::GetActiveBorder() {
  return GetSystemColor(COLOR_ACTIVEBORDER);
}

int32 Native::SystemColorsApi::GetActiveCaption() {
  return GetSystemColor(COLOR_ACTIVECAPTION);
}

int32 Native::SystemColorsApi::GetActiveCaptionText() {
  return GetSystemColor(COLOR_CAPTIONTEXT);
}

int32 Native::SystemColorsApi::GetAppWorkspace() {
  return GetSystemColor(COLOR_APPWORKSPACE);
}

int32 Native::SystemColorsApi::GetButtonFace() {
  return GetSystemColor(COLOR_BTNFACE);
}

int32 Native::SystemColorsApi::GetButtonHighlight() {
  return GetSystemColor(COLOR_BTNHIGHLIGHT);
}

int32 Native::SystemColorsApi::GetButtonShadow() {
  return GetSystemColor(COLOR_BTNSHADOW);
}

int32 Native::SystemColorsApi::GetControl() {
  return GetSystemColor(COLOR_BTNFACE);
}

int32 Native::SystemColorsApi::GetControlDark() {
  return GetSystemColor(COLOR_BTNSHADOW);
}

int32 Native::SystemColorsApi::GetControlDarkDark() {
  return GetSystemColor(COLOR_3DDKSHADOW);
}

int32 Native::SystemColorsApi::GetControlLight() {
  return GetSystemColor(COLOR_3DLIGHT);
}

int32 Native::SystemColorsApi::GetControlLightLight() {
  return GetSystemColor(COLOR_BTNHIGHLIGHT);
}

int32 Native::SystemColorsApi::GetControlText() {
  return GetSystemColor(COLOR_BTNTEXT);
}

int32 Native::SystemColorsApi::GetDesktop() {
  return GetSystemColor(COLOR_DESKTOP);
}

int32 Native::SystemColorsApi::GetGradientActiveCaption() {
  return GetSystemColor(COLOR_GRADIENTACTIVECAPTION);
}

int32 Native::SystemColorsApi::GetGradientInactiveCaption() {
  return GetSystemColor(COLOR_GRADIENTINACTIVECAPTION);
}

int32 Native::SystemColorsApi::GetGrayText() {
  return GetSystemColor(COLOR_GRAYTEXT);
}

int32 Native::SystemColorsApi::GetHighlight() {
  return GetSystemColor(COLOR_HIGHLIGHT);
}

int32 Native::SystemColorsApi::GetHighlightText() {
  return GetSystemColor(COLOR_HIGHLIGHTTEXT);
}

int32 Native::SystemColorsApi::GetHotTrack() {
  return GetSystemColor(COLOR_HOTLIGHT);
}

int32 Native::SystemColorsApi::GetInactiveBorder() {
  return GetSystemColor(COLOR_INACTIVEBORDER);
}

int32 Native::SystemColorsApi::GetInactiveCaption() {
  return GetSystemColor(COLOR_INACTIVECAPTION);
}

int32 Native::SystemColorsApi::GetInactiveCaptionText() {
  return GetSystemColor(COLOR_INACTIVECAPTIONTEXT);
}

int32 Native::SystemColorsApi::GetInfo() {
  return GetSystemColor(COLOR_INFOBK);
}

int32 Native::SystemColorsApi::GetInfoText() {
  return GetSystemColor(COLOR_INFOTEXT);
}

int32 Native::SystemColorsApi::GetMenu() {
  return GetSystemColor(COLOR_MENU);
}

int32 Native::SystemColorsApi::GetMenuBar() {
  return GetSystemColor(COLOR_MENUBAR);
}

int32 Native::SystemColorsApi::GetMenuHighlight() {
  return GetSystemColor(COLOR_MENUHILIGHT);
}

int32 Native::SystemColorsApi::GetMenuText() {
  return GetSystemColor(COLOR_MENUTEXT);
}

int32 Native::SystemColorsApi::GetScrollBar() {
  return GetSystemColor(COLOR_SCROLLBAR);
}

int32 Native::SystemColorsApi::GetWindow() {
  return GetSystemColor(COLOR_WINDOW);
}

int32 Native::SystemColorsApi::GetWindowFrame() {
  return GetSystemColor(COLOR_WINDOWFRAME);
}

int32 Native::SystemColorsApi::GetWindowText() {
  return GetSystemColor(COLOR_WINDOWTEXT);
}

#endif

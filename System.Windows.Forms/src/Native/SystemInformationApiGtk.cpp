#if defined(__linux__)
#include "Api.hpp"

using namespace System;
using namespace System::Windows::Forms;

int32 Native::SystemInformationApi::GetActiveWindowTrackingDelay() {
  return 0;
}

ArrangeDirection Native::SystemInformationApi::GetArrangeDirection() {
  return ArrangeDirection::Left;
}

ArrangeStartingPosition Native::SystemInformationApi::GetArrangeStartingPosition() {
  return ArrangeStartingPosition::Hide;
}

BootMode Native::SystemInformationApi::GetBootMode() {
  return BootMode::Normal;
}

System::Drawing::Size Native::SystemInformationApi::GetBorder3DSize() {
  return System::Drawing::Size(1, 1);
}

int32 Native::SystemInformationApi::GetBorderMultiplierFactor() {
  return 1;
}

System::Drawing::Size Native::SystemInformationApi::GetBorderSize() {
  return System::Drawing::Size(1, 1);
}

System::Drawing::Size Native::SystemInformationApi::GetCaptionButtonSize() {
  return System::Drawing::Size(16, 16);
}

int32 Native::SystemInformationApi::GetCaptionHeight() {
  return 29;
}

int32 Native::SystemInformationApi::GetCaretBlinkTime() {
  return 530;
}

int32 Native::SystemInformationApi::GetCaretWidth() {
  return 1;
}

System::Drawing::Size Native::SystemInformationApi::GetCursorSize() {
  return System::Drawing::Size(32, 32);
}

bool Native::SystemInformationApi::GetDbcsEnabled() {
  return false;
}

bool Native::SystemInformationApi::GetDebugOS() {
  return false;
}

System::Drawing::Size Native::SystemInformationApi::GetDoubleClickSize() {
  return System::Drawing::Size(4, 4);
}

int32 Native::SystemInformationApi::GetDoubleClickTime() {
  return 500;
}

bool Native::SystemInformationApi::GetDragFullWindows() {
  return true;
}

System::Drawing::Size Native::SystemInformationApi::GetDragSize() {
  return System::Drawing::Size(4, 4);
}

System::Drawing::Size Native::SystemInformationApi::GetFixedFrameBorderSize() {
  return System::Drawing::Size(0, 0);
}

int32 Native::SystemInformationApi::GetFontSmoothingContrast() {
  return 1200;
}

int32 Native::SystemInformationApi::GetFontSmoothingType() {
  return 2;
}

System::Drawing::Size Native::SystemInformationApi::GetFrameBorderSize() {
  return System::Drawing::Size(0, 0);
}

bool Native::SystemInformationApi::GetHighContrast() {
  return false;
}

int32 Native::SystemInformationApi::GetHorizontalFocusThickness() {
  return 1;
}

int32 Native::SystemInformationApi::GetHorizontalResizeBorderThickness() {
  return 4;
}

int32 Native::SystemInformationApi::GetHorizontalScrollBarArrowWidth() {
  return 17;
}

int32 Native::SystemInformationApi::GetHorizontalScrollBarHeight() {
  return 17;
}

int32 Native::SystemInformationApi::GetHorizontalScrollBarThumbWidth() {
  return 17;
}

int32 Native::SystemInformationApi::GetIconHorizontalSpacing() {
  return 75;
}

System::Drawing::Size Native::SystemInformationApi::GetIconSize() {
  return System::Drawing::Size(64, 64);
}

System::Drawing::Size Native::SystemInformationApi::GetIconSpacingSize() {
  return System::Drawing::Size(75, 75);
}

int32 Native::SystemInformationApi::GetIconVerticalSpacing() {
  return 75;
}

bool Native::SystemInformationApi::GetIsActiveWindowTrackingEnabled() {
  return false;
}

bool Native::SystemInformationApi::GetIsComboBoxAnimationEnabled() {
  return false;
}

bool Native::SystemInformationApi::GetIsDropShadowEnabled() {
  return false;
}

bool Native::SystemInformationApi::GetIsFlatMenuEnabled() {
  return true;
}

bool Native::SystemInformationApi::GetIsFontSmoothingEnabled() {
  return true;
}

bool Native::SystemInformationApi::GetIsHotTrackingEnabled() {
  return true;
}

bool Native::SystemInformationApi::GetIsIconTitleWrappingEnabled() {
  return true;
}

bool Native::SystemInformationApi::GetIsKeyboardPreferred() {
  return false;
}

bool Native::SystemInformationApi::GetIsListBoxSmoothScrollingEnabled() {
  return false;
}

bool Native::SystemInformationApi::GetIsMenuAnimationEnabled() {
  return false;
}

bool Native::SystemInformationApi::GetIsMenuFadeEnabled() {
  return false;
}

bool Native::SystemInformationApi::GetIsMinimizeRestoreAnimationEnabled() {
  return false;
}

bool Native::SystemInformationApi::GetIsSelectionFadeEnabled() {
  return true;
}

bool Native::SystemInformationApi::GetIsSnapToDefaultEnabled() {
  return false;
}

bool Native::SystemInformationApi::GetIsTitleBarGradientEnabled() {
  return true;
}

bool Native::SystemInformationApi::GetIsToolTipAnimationEnabled() {
  return false;
}

int32 Native::SystemInformationApi::GetKanjiWindowHeight() {
  return 0;
}

int32 Native::SystemInformationApi::GetKeyboardDelay() {
  return 1;
}

int32 Native::SystemInformationApi::GetKeyboardSpeed() {
  return 31;
}

System::Drawing::Size Native::SystemInformationApi::GetMaxWindowTrackSize() {
  return System::Drawing::Size(0, 0);
}

bool Native::SystemInformationApi::GetMenuAccessKeysUnderlined() {
  return false;
}

System::Drawing::Size Native::SystemInformationApi::GetMenuBarButtonSize() {
  return System::Drawing::Size(19, 19);
}

System::Drawing::Size Native::SystemInformationApi::GetMenuButtonSize() {
  return System::Drawing::Size(19, 19);
}

System::Drawing::Size Native::SystemInformationApi::GetMenuCheckSize() {
  return System::Drawing::Size(15, 15);
}

System::Drawing::Font Native::SystemInformationApi::GetMenuFont() {
  return System::Drawing::Font::FromLogFont((intptr)0);
}

int32 Native::SystemInformationApi::GetMenuHeight() {
  return 23;
}

#endif

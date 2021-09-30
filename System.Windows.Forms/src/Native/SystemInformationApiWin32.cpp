#if defined(_WIN32)

#include <windows.h>
#include <Windowsx.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

int32 Native::SystemInformationApi::GetActiveWindowTrackingDelay() {
  return 0;
}

ArrangeDirection Native::SystemInformationApi::GetArrangeDirection() {
  return (ArrangeDirection)(GetSystemMetrics(SM_ARRANGE) & int32(ArrangeDirection::Down | ArrangeDirection::Left | ArrangeDirection::Right | ArrangeDirection::Up));
}

ArrangeStartingPosition Native::SystemInformationApi::GetArrangeStartingPosition() {
  return (ArrangeStartingPosition)(GetSystemMetrics(SM_ARRANGE) & int32(ArrangeStartingPosition::BottomLeft | ArrangeStartingPosition::BottomRight | ArrangeStartingPosition::Hide | ArrangeStartingPosition::TopLeft | ArrangeStartingPosition::TopRight));
}

BootMode Native::SystemInformationApi::GetBootMode() {
  return (BootMode)GetSystemMetrics(SM_CLEANBOOT);
}

Size Native::SystemInformationApi::GetBorder3DSize() {
  return Size(GetSystemMetrics(SM_CXEDGE), GetSystemMetrics(SM_CYEDGE));
}

int32 Native::SystemInformationApi::GetBorderMultiplierFactor() {
  int32 value;
  SystemParametersInfo(SPI_GETBORDER, 0, &value, 0);
  return value;
}

Size Native::SystemInformationApi::GetBorderSize() {
  return Size(GetSystemMetrics(SM_CXBORDER), GetSystemMetrics(SM_CYBORDER));
}

Size Native::SystemInformationApi::GetCaptionButtonSize() {
  return Size(GetSystemMetrics(SM_CXSIZE), GetSystemMetrics(SM_CYSIZE));
}

int32 Native::SystemInformationApi::GetCaptionHeight() {
  return GetSystemMetrics(SM_CYCAPTION);
}

int32 Native::SystemInformationApi::GetCaretBlinkTime() {
  return ::GetCaretBlinkTime();
}

int32 Native::SystemInformationApi::GetCaretWidth() {
  int32 value;
  SystemParametersInfo(SPI_GETCARETWIDTH, 0, &value, 0);
  return value;
}

Size Native::SystemInformationApi::GetCursorSize() {
  return Size(GetSystemMetrics(SM_CXCURSOR), GetSystemMetrics(SM_CYCURSOR));
}

bool Native::SystemInformationApi::GetDbcsEnabled() {
  return GetSystemMetrics(SM_DBCSENABLED) != 0;
}

bool Native::SystemInformationApi::GetDebugOS() {
  return GetSystemMetrics(SM_DEBUG) != 0;
}

Size Native::SystemInformationApi::GetDoubleClickSize() {
  return Size(GetSystemMetrics(SM_CXDOUBLECLK), GetSystemMetrics(SM_CYDOUBLECLK));
}

int32 Native::SystemInformationApi::GetDoubleClickTime() {
  return ::GetDoubleClickTime();
}

bool Native::SystemInformationApi::GetDragFullWindows() {
  int32 value;
  SystemParametersInfo(SPI_GETDRAGFULLWINDOWS, 0, &value, 0);
  return value != 0;
}

Size Native::SystemInformationApi::GetDragSize() {
  return Size(GetSystemMetrics(SM_CXDRAG), GetSystemMetrics(SM_CYDRAG));
}

Size Native::SystemInformationApi::GetFixedFrameBorderSize() {
  return Size(GetSystemMetrics(SM_CXFIXEDFRAME), GetSystemMetrics(SM_CYFIXEDFRAME));
}

int32 Native::SystemInformationApi::GetFontSmoothingContrast() {
  int32 value;
  SystemParametersInfo(SPI_GETFONTSMOOTHINGCONTRAST, 0, &value, 0);
  return value;
}

int32 Native::SystemInformationApi::GetFontSmoothingType() {
  int32 value;
  SystemParametersInfo(SPI_GETFONTSMOOTHINGTYPE, 0, &value, 0);
  return value;
}

Size Native::SystemInformationApi::GetFrameBorderSize() {
  return Size(GetSystemMetrics(SM_CXFRAME), GetSystemMetrics(SM_CYFRAME));
}

bool Native::SystemInformationApi::GetHighContrast() {
  HIGHCONTRAST value{sizeof(HIGHCONTRAST), 0, NULL};
  SystemParametersInfo(SPI_GETDRAGFULLWINDOWS, sizeof(value), &value, 0);
  return (value.dwFlags & HCF_HIGHCONTRASTON) == HCF_HIGHCONTRASTON;
}

int32 Native::SystemInformationApi::GetHorizontalFocusThickness() {
  return GetSystemMetrics(SM_CXFOCUSBORDER);
}

int32 Native::SystemInformationApi::GetHorizontalResizeBorderThickness() {
  return GetSystemMetrics(SM_CXSIZEFRAME);
}

int32 Native::SystemInformationApi::GetHorizontalScrollBarArrowWidth() {
  return GetSystemMetrics(SM_CXHSCROLL);
}

int32 Native::SystemInformationApi::GetHorizontalScrollBarHeight() {
  return GetSystemMetrics(SM_CYHSCROLL);
}

int32 Native::SystemInformationApi::GetHorizontalScrollBarThumbWidth() {
  return GetSystemMetrics(SM_CXHTHUMB);
}

int32 Native::SystemInformationApi::GetIconHorizontalSpacing() {
  int32 value;
  SystemParametersInfo(SPI_ICONHORIZONTALSPACING, 0, &value, 0);
  return value;
}

Size Native::SystemInformationApi::GetIconSize() {
  return Size(GetSystemMetrics(SM_CXICON), GetSystemMetrics(SM_CYICON));
}

Size Native::SystemInformationApi::GetIconSpacingSize() {
  return Size(GetSystemMetrics(SM_CXICONSPACING), GetSystemMetrics(SM_CYICONSPACING));
}

int32 Native::SystemInformationApi::GetIconVerticalSpacing() {
  int32 value;
  SystemParametersInfo(SPI_ICONVERTICALSPACING, 0, &value, 0);
  return value;
}

bool Native::SystemInformationApi::GetIsActiveWindowTrackingEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETACTIVEWINDOWTRACKING, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsComboBoxAnimationEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETCOMBOBOXANIMATION, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsDropShadowEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETDROPSHADOW, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsFlatMenuEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETFLATMENU, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsFontSmoothingEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETFONTSMOOTHING, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsHotTrackingEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETHOTTRACKING, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsIconTitleWrappingEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETICONTITLEWRAP, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsKeyboardPreferred() {
  int32 value;
  SystemParametersInfo(SPI_GETKEYBOARDPREF, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsListBoxSmoothScrollingEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETLISTBOXSMOOTHSCROLLING, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsMenuAnimationEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETMENUANIMATION, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsMenuFadeEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETMENUFADE, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsMinimizeRestoreAnimationEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETANIMATION, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsSelectionFadeEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETSELECTIONFADE, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsSnapToDefaultEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETSNAPTODEFBUTTON, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsTitleBarGradientEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETGRADIENTCAPTIONS, 0, &value, 0);
  return value != 0;
}

bool Native::SystemInformationApi::GetIsToolTipAnimationEnabled() {
  int32 value;
  SystemParametersInfo(SPI_GETTOOLTIPANIMATION, 0, &value, 0);
  return value != 0;
}

int32 Native::SystemInformationApi::GetKanjiWindowHeight() {
  return GetSystemMetrics(SM_CYKANJIWINDOW);
}

int32 Native::SystemInformationApi::GetKeyboardDelay() {
  int32 value;
  SystemParametersInfo(SPI_GETKEYBOARDDELAY, 0, &value, 0);
  return value;
}

int32 Native::SystemInformationApi::GetKeyboardSpeed() {
  int32 value;
  SystemParametersInfo(SPI_GETKEYBOARDSPEED, 0, &value, 0);
  return value;
}

Size Native::SystemInformationApi::GetMaxWindowTrackSize() {
  return Size(GetSystemMetrics(SM_CXMAXTRACK), GetSystemMetrics(SM_CYMAXTRACK));
}

bool Native::SystemInformationApi::GetMenuAccessKeysUnderlined() {
  int32 value;
  SystemParametersInfo(SPI_GETKEYBOARDCUES, 0, &value, 0);
  return value != 0;
}

Size Native::SystemInformationApi::GetMenuBarButtonSize() {
  NONCLIENTMETRICS value;
  value.cbSize = sizeof(value);
  SystemParametersInfo(SPI_GETNONCLIENTMETRICS, value.cbSize, &value, 0);
  return Size(value.iMenuWidth, value.iMenuHeight);
}

Size Native::SystemInformationApi::GetMenuButtonSize() {
  return Size(GetSystemMetrics(SM_CXMENUSIZE), GetSystemMetrics(SM_CYMENUSIZE));
}

Size Native::SystemInformationApi::GetMenuCheckSize() {
  return Size(GetSystemMetrics(SM_CXMENUCHECK), GetSystemMetrics(SM_CYMENUCHECK));
}

Font Native::SystemInformationApi::GetMenuFont() {
  NONCLIENTMETRICS value;
  value.cbSize = sizeof(value);
  SystemParametersInfo(SPI_GETNONCLIENTMETRICS, value.cbSize, &value, 0);
  return Font::FromLogFont((intptr)&value.lfMenuFont);
}

int32 Native::SystemInformationApi::GetMenuHeight() {
  return GetSystemMetrics(SM_CYMENU);
}

#endif

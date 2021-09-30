#include "../../../../../include/Switch/System/Windows/Forms/SystemInformation.hpp"
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

property_<int32, readonly_> SystemInformation::ActiveWindowTrackingDelay {
  [] {return Native::SystemInformationApi::GetActiveWindowTrackingDelay();}
};

property_<System::Windows::Forms::ArrangeDirection, readonly_> SystemInformation::ArrangeDirection{
  [] {return Native::SystemInformationApi::GetArrangeDirection(); }
};

property_<System::Windows::Forms::ArrangeStartingPosition, readonly_> SystemInformation::ArrangeStartingPosition{
  [] {return Native::SystemInformationApi::GetArrangeStartingPosition(); }
};

property_<System::Windows::Forms::BootMode, readonly_> SystemInformation::BootMode{
  [] {return Native::SystemInformationApi::GetBootMode(); }
};

property_<System::Drawing::Size, readonly_> SystemInformation::Border3DSize{
  [] {return Native::SystemInformationApi::GetBorder3DSize(); }
};

property_<int32, readonly_> SystemInformation::BorderMultiplierFactor{
  [] {return Native::SystemInformationApi::GetBorderMultiplierFactor(); }
};

property_<System::Drawing::Size, readonly_> SystemInformation::BorderSize{
  [] {return Native::SystemInformationApi::GetBorderSize(); }
};

property_<System::Drawing::Size, readonly_> SystemInformation::CaptionButtonSize{
  [] {return Native::SystemInformationApi::GetCaptionButtonSize(); }
};

property_<int32, readonly_> SystemInformation::CaptionHeight {
  [] {return Native::SystemInformationApi::GetCaptionHeight();}
};

property_<int32, readonly_> SystemInformation::CaretBlinkTime{
  [] {return Native::SystemInformationApi::GetCaretBlinkTime(); }
};

property_<int32, readonly_> SystemInformation::CaretWidth{
  [] {return Native::SystemInformationApi::GetCaretWidth(); }
};

property_<string, readonly_> SystemInformation::ComputerName{
  [] {return Environment::MachineName(); }
};

property_<System::Drawing::Size, readonly_> SystemInformation::CursorSize{
  [] {return Native::SystemInformationApi::GetCursorSize(); }
};

property_<bool, readonly_> SystemInformation::DbcsEnabled{
  [] {return Native::SystemInformationApi::GetDbcsEnabled(); }
};

property_<bool, readonly_> SystemInformation::DebugOS{
  [] {return Native::SystemInformationApi::GetDebugOS(); }
};

property_<System::Drawing::Size, readonly_> SystemInformation::DoubleClickSize{
  [] {return Native::SystemInformationApi::GetDoubleClickSize(); }
};

property_<int32, readonly_> SystemInformation::DoubleClickTime{
  [] {return Native::SystemInformationApi::GetDoubleClickTime(); }
};

property_<bool, readonly_> SystemInformation::DragFullWindows{
  [] {return Native::SystemInformationApi::GetDragFullWindows(); }
};

property_<System::Drawing::Size, readonly_> SystemInformation::DragSize{
  [] {return Native::SystemInformationApi::GetDragSize(); }
};

property_<System::Drawing::Size, readonly_> SystemInformation::FixedFrameBorderSize{
  [] {return Native::SystemInformationApi::GetFixedFrameBorderSize(); }
};

property_<int32, readonly_> SystemInformation::FontSmoothingContrast{
  [] {return Native::SystemInformationApi::GetFontSmoothingContrast(); }
};

property_<int32, readonly_> SystemInformation::FontSmoothingType{
  [] {return Native::SystemInformationApi::GetFontSmoothingType(); }
};

property_<System::Drawing::Size, readonly_> SystemInformation::FrameBorderSize{
  [] {return Native::SystemInformationApi::GetFrameBorderSize(); }
};

property_<bool, readonly_> SystemInformation::HighContrast{
  [] {return Native::SystemInformationApi::GetHighContrast(); }
};

property_<int32, readonly_> SystemInformation::HorizontalFocusThickness{
  [] {return Native::SystemInformationApi::GetHorizontalFocusThickness(); }
};

property_<int32, readonly_> SystemInformation::HorizontalResizeBorderThickness{
  [] {return Native::SystemInformationApi::GetHorizontalResizeBorderThickness(); }
};

property_<int32, readonly_> SystemInformation::HorizontalScrollBarArrowWidth{
  [] {return Native::SystemInformationApi::GetHorizontalScrollBarArrowWidth(); }
};

property_<int32, readonly_> SystemInformation::HorizontalScrollBarHeight{
  [] {return Native::SystemInformationApi::GetHorizontalScrollBarHeight(); }
};

property_<int32, readonly_> SystemInformation::HorizontalScrollBarThumbWidth{
  [] {return Native::SystemInformationApi::GetHorizontalScrollBarThumbWidth(); }
};

property_<int32, readonly_> SystemInformation::IconHorizontalSpacing{
  [] {return Native::SystemInformationApi::GetIconHorizontalSpacing(); }
};

property_<System::Drawing::Size, readonly_> SystemInformation::IconSize{
  [] {return Native::SystemInformationApi::GetIconSize(); }
};

property_<System::Drawing::Size, readonly_> SystemInformation::IconSpacingSize{
  [] {return Native::SystemInformationApi::GetIconSpacingSize(); }
};

property_<int32, readonly_> SystemInformation::IconVerticalSpacing{
  [] {return Native::SystemInformationApi::GetIconVerticalSpacing(); }
};

property_<bool, readonly_> SystemInformation::IsActiveWindowTrackingEnabled{
  [] {return Native::SystemInformationApi::GetIsActiveWindowTrackingEnabled(); }
};

property_<bool, readonly_> SystemInformation::IsComboBoxAnimationEnabled{
  [] {return Native::SystemInformationApi::GetIsComboBoxAnimationEnabled(); }
};

property_<bool, readonly_> SystemInformation::IsDropShadowEnabled{
  [] {return Native::SystemInformationApi::GetIsDropShadowEnabled(); }
};

property_<bool, readonly_> SystemInformation::IsFlatMenuEnabled{
  [] {return Native::SystemInformationApi::GetIsFlatMenuEnabled(); }
};

property_<bool, readonly_> SystemInformation::IsFontSmoothingEnabled{
  [] {return Native::SystemInformationApi::GetIsFontSmoothingEnabled(); }
};

property_<bool, readonly_> SystemInformation::IsHotTrackingEnabled{
  [] {return Native::SystemInformationApi::GetIsHotTrackingEnabled(); }
};

property_<bool, readonly_> SystemInformation::IsIconTitleWrappingEnabled{
  [] {return Native::SystemInformationApi::GetIsIconTitleWrappingEnabled(); }
};

property_<bool, readonly_> SystemInformation::IsKeyboardPreferred{
  [] {return Native::SystemInformationApi::GetIsKeyboardPreferred(); }
};

property_<bool, readonly_> SystemInformation::IsListBoxSmoothScrollingEnabled{
  [] {return Native::SystemInformationApi::GetIsListBoxSmoothScrollingEnabled(); }
};

property_<bool, readonly_> SystemInformation::IsMenuAnimationEnabled{
  [] {return Native::SystemInformationApi::GetIsMenuAnimationEnabled(); }
};

property_<bool, readonly_> SystemInformation::IsMenuFadeEnabled{
  [] {return Native::SystemInformationApi::GetIsMenuFadeEnabled(); }
};

property_<bool, readonly_> SystemInformation::IsMinimizeRestoreAnimationEnabled{
  [] {return Native::SystemInformationApi::GetIsMinimizeRestoreAnimationEnabled(); }
};

property_<bool, readonly_> SystemInformation::IsSelectionFadeEnabled{
  [] {return Native::SystemInformationApi::GetIsSelectionFadeEnabled(); }
};

property_<bool, readonly_> SystemInformation::IsSnapToDefaultEnabled{
  [] {return Native::SystemInformationApi::GetIsSnapToDefaultEnabled(); }
};

property_<bool, readonly_> SystemInformation::IsTitleBarGradientEnabled{
  [] {return Native::SystemInformationApi::GetIsTitleBarGradientEnabled(); }
};

property_<bool, readonly_> SystemInformation::IsToolTipAnimationEnabled{
  [] {return Native::SystemInformationApi::GetIsToolTipAnimationEnabled(); }
};

property_<int32, readonly_> SystemInformation::KanjiWindowHeight{
  [] {return Native::SystemInformationApi::GetKanjiWindowHeight(); }
};

property_<int32, readonly_> SystemInformation::KeyboardDelay{
  [] {return Native::SystemInformationApi::GetKeyboardDelay(); }
};

property_<int32, readonly_> SystemInformation::KeyboardSpeed{
  [] {return Native::SystemInformationApi::GetKeyboardSpeed(); }
};

property_<System::Drawing::Size, readonly_> SystemInformation::MaxWindowTrackSize{
  [] {return Native::SystemInformationApi::GetMaxWindowTrackSize(); }
};

property_<bool, readonly_> SystemInformation::MenuAccessKeysUnderlined{
  [] {return Native::SystemInformationApi::GetMenuAccessKeysUnderlined(); }
};

property_<System::Drawing::Size, readonly_> SystemInformation::MenuBarButtonSize{
  [] {return Native::SystemInformationApi::GetMenuBarButtonSize(); }
};

property_<System::Drawing::Size, readonly_> SystemInformation::MenuButtonSize{
  [] {return Native::SystemInformationApi::GetMenuButtonSize(); }
};

property_<System::Drawing::Size, readonly_> SystemInformation::MenuCheckSize{
  [] {return Native::SystemInformationApi::GetMenuCheckSize(); }
};

property_<System::Drawing::Font, readonly_> SystemInformation::MenuFont{
  [] {return Native::SystemInformationApi::GetMenuFont(); }
};

property_<int32, readonly_> SystemInformation::MenuHeight{
  [] {return Native::SystemInformationApi::GetMenuHeight(); }
};


#pragma once

#include <Switch/Static.hpp>
#include <Switch/System/Array.hpp>

#include "../../include/Switch/System/Drawing/Brush.hpp"
#include "../../include/Switch/System/Drawing/Color.hpp"
#include "../../include/Switch/System/Drawing/FontFamily.hpp"
#include "../../include/Switch/System/Drawing/Pen.hpp"
#include "../../include/Switch/System/Drawing/Rectangle.hpp"

namespace Native {
  class BrushApi static_ {
  public:
    static intptr CreateSolidBrush(const System::Drawing::Color& color);
    static void DeleteBrush(intptr handle);
  };

  class PenApi static_ {
  public:
    static intptr CreatePen(const System::Drawing::Drawing2D::DashStyle& dashStyle, int32 width, const System::Drawing::Color& color);
    static void DeletePen(intptr handle);
  };

  class FontFamilyApi static_ {
  public:
    static System::Array<System::Drawing::FontFamily> GetInstalledFontFamilies();
    static System::Drawing::FontFamily GetFontFamilyFromName(const string& name);
    static string GetName(intptr handle);
    static bool IsStyleAvailable(intptr handle, System::Drawing::FontStyle style);
    static void ReleaseResource(intptr handle);
  };

  class GdiApi static_ {
  public:
    //static intptr BeginPaint(intptr hwnd, System::Drawing::Rectangle& clipRectangle);
    //static void EndPaint(intptr hwnd, intptr hdc);
    static intptr GetDeviceContext(intptr hwnd);
    static void ReleaseDeviceContext(intptr hwnd, intptr hdc);
    static System::Drawing::Rectangle GetClipRectangleFromHdc(intptr hhdcwd);
    static System::Drawing::Rectangle GetClipRectangleFromHwnd(intptr hwnd);
    static void DrawRectangle(intptr hdc, const System::Drawing::Pen& pen, int32 x, int32 y, int32 w, int32 h);
    static void FillPie(intptr hdc, const System::Drawing::Brush& brush, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle);
    static void FillRectangle(intptr hdc, const System::Drawing::Brush& brush, int32 x, int32 y, int32 w, int32 h);
  };

  class SystemColorsApi static_ {
  public:
    static int32 GetActiveBorder();
    static int32 GetActiveCaption();
    static int32 GetActiveCaptionText();
    static int32 GetAppWorkspace();
    static int32 GetButtonFace();
    static int32 GetButtonHighlight();
    static int32 GetButtonShadow();
    static int32 GetControl();
    static int32 GetControlDark();
    static int32 GetControlDarkDark();
    static int32 GetControlLight();
    static int32 GetControlLightLight();
    static int32 GetControlText();
    static int32 GetDesktop();
    static int32 GetGradientActiveCaption();
    static int32 GetGradientInactiveCaption();
    static int32 GetGrayText();
    static int32 GetHighlight();
    static int32 GetHighlightText();
    static int32 GetHotTrack();
    static int32 GetInactiveBorder();
    static int32 GetInactiveCaption();
    static int32 GetInactiveCaptionText();
    static int32 GetInfo();
    static int32 GetInfoText();
    static int32 GetMenu();
    static int32 GetMenuBar();
    static int32 GetMenuHighlight();
    static int32 GetMenuText();
    static int32 GetScrollBar();
    static int32 GetWindow();
    static int32 GetWindowFrame();
    static int32 GetWindowText();
  };
}


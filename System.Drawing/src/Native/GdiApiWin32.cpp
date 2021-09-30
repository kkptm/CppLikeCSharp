#if defined(_WIN32)
#include <windows.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"
#include <Switch/System/Diagnostics/Debug.hpp>
#include <Switch/System/ArgumentException.hpp>

using namespace System;
using namespace System::Drawing;

namespace {
  inline System::Drawing::Rectangle ToRectangle(const RECT& rectangle) {
    return { rectangle.left, rectangle.top, rectangle.right - rectangle.left, rectangle.bottom - rectangle.top };
  }
}

intptr Native::GdiApi::GetDeviceContext(intptr hwnd) {
  return (intptr)GetDC((HWND)hwnd);
}

/*
intptr Native::GdiApi::BeginPaint(intptr hwnd, System::Drawing::Rectangle& clipRectangle) {
  PAINTSTRUCT paintStruct;
  intptr hdc = (intptr)::BeginPaint((HWND)hwnd, &paintStruct);
  clipRectangle = ToRectangle(paintStruct.rcPaint);
  return hdc;
}

void Native::GdiApi::EndPaint(intptr hwnd, intptr hdc) {
  PAINTSTRUCT paintStruct;
  paintStruct.hdc = (HDC)hdc;
  GetClientRect((HWND)hwnd, &paintStruct.rcPaint);
  ::EndPaint((HWND)hwnd, &paintStruct);
}*/

void Native::GdiApi::ReleaseDeviceContext(intptr hwnd, intptr hdc) {
  ReleaseDC((HWND)hwnd, (HDC)hdc);
}

System::Drawing::Rectangle Native::GdiApi::GetClipRectangleFromHdc(intptr hdc) {
  RECT clipRectangle;
  GetClientRect((HWND)WindowFromDC((HDC)hdc), &clipRectangle);
  return ToRectangle(clipRectangle);
}

System::Drawing::Rectangle Native::GdiApi::GetClipRectangleFromHwnd(intptr hwnd) {
  RECT clipRectangle;
  GetClientRect((HWND)hwnd, &clipRectangle);
  return ToRectangle(clipRectangle);
}

void Native::GdiApi::DrawRectangle(intptr handle, const System::Drawing::Pen& pen, int32 x, int32 y, int32 w, int32 h) {
  RECT rect { x, y, x + w, y + h };
  HGDIOBJ oldBrush = SelectObject((HDC)handle, GetStockObject(NULL_BRUSH));
  HGDIOBJ oldPen = SelectObject((HDC)handle, (HGDIOBJ)pen.GetNativePen());
  ::Rectangle((HDC)handle, x, y, x + w, y + h);
  SelectObject((HDC)handle, oldBrush);
  SelectObject((HDC)handle, oldPen);
}


void Native::GdiApi::FillPie(intptr handle, const System::Drawing::Brush& brush, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle) {
  RECT rect { x, y, x + w, y + h };
  Pie((HDC)handle, x, y, w, h, (int32)startAngle, (int32)sweepAngle, (int32)startAngle, (int32)sweepAngle);
}

void Native::GdiApi::FillRectangle(intptr handle, const System::Drawing::Brush& brush, int32 x, int32 y, int32 w, int32 h) {
  RECT rect { x, y, x + w, y + h };
  FillRect((HDC)handle, &rect, (HBRUSH)brush.GetNativeBrush());
}

#endif

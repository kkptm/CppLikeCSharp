#include "../../../../include/Switch/System/Drawing/Graphics.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;

Graphics::~Graphics() {
  if (this->hwnd != IntPtr::Zero)
    //Native::GdiApi::EndPaint(this->hwnd, this->hdc);
    Native::GdiApi::ReleaseDeviceContext(this->hwnd, this->hdc);
}

void Graphics::Clear(const Color& color) {
  this->FillRectangle(SolidBrush(color), clipRectangle);
}

void Graphics::DrawArc(const Pen& pen, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle) {
}

void Graphics::DrawBezier(const Pen& pen, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
}

void Graphics::DrawLine(const Pen& pen, int32 x1, int32 y1, int32 x2, int32 y2) {
}

void Graphics::DrawPie(const Pen& pen, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle) {
}

void Graphics::DrawRectangle(const Pen& pen, int32 x, int32 y, int32 w, int32 h) {
  Native::GdiApi::DrawRectangle(this->hdc, pen, x, y, w, h);
}

void Graphics::DrawString(const string& str, const Font& font, const Brush& brush, const RectangleF& layoutRectangle, const StringFormat& format) {
}

void Graphics::FillPie(const System::Drawing::Brush& brush, int32 x, int32 y, int32 w, int32 h, float startAngle, float sweepAngle) {
  Native::GdiApi::FillPie(this->hdc, brush, x, y, w, h, startAngle, sweepAngle);
}

void Graphics::FillRectangle(const Brush& brush, int32 x, int32 y, int32 w, int32 h) {
  Native::GdiApi::FillRectangle(this->hdc, brush, x, y, w, h);
}

void Graphics::SetColor(const System::Drawing::Color& color) {
}

SizeF Graphics::MeasureString(const string& str, const Font& font) const {
  return SizeF();
}

Graphics Graphics::FromHwndInternal(intptr hwnd) {
  intptr hdc = Native::GdiApi::GetDeviceContext(hwnd);
  Rectangle clipRectangle = Native::GdiApi::GetClipRectangleFromHwnd(hwnd);
  return Graphics(hwnd, hdc, clipRectangle);
  //return Graphics(hwnd, Native::GdiApi::GetDeviceContext(hwnd), Native::GdiApi::GetClipRectangleFromHwnd(hwnd));
}

Graphics Graphics::FromHdcInternal(intptr hdc) {
  return Graphics(hdc, Native::GdiApi::GetClipRectangleFromHdc(hdc));
}


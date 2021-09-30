#include "../../../../include/Switch/System/Drawing/Brush.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;

Brush::~Brush() {
  ReleaseNativeBrush();
}

void Brush::SetNativeBrush(intptr brush) {
  ReleaseNativeBrush();
  this->brush = brush;
}

void Brush::ReleaseNativeBrush() {
  if (this->brush != IntPtr::Zero)
    Native::BrushApi::DeleteBrush(this->brush);
  this->brush = IntPtr::Zero;
}

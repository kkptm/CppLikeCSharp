#include "../../../../include/Switch/System/Drawing/SolidBrush.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;

SolidBrush::SolidBrush(const System::Drawing::Color& color) : color(color) {
  this->SetNativeBrush(Native::BrushApi::CreateSolidBrush(this->color));
}

SolidBrush& SolidBrush::operator=(const SolidBrush& brush) {
  this->color = brush.color;
  this->SetNativeBrush(Native::BrushApi::CreateSolidBrush(this->color));
  return *this;
}

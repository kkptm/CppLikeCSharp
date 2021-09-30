#include "../../../../include/Switch/System/Drawing/Pen.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;

void Pen::Create() {
  this->Destroy();
  this->pen = Native::PenApi::CreatePen(this->dashStyle, (int32)this->width, as<SolidBrush>(this->brush)().Color);
}

void Pen::Destroy() {
  if (this->pen != IntPtr::Zero)
    Native::PenApi::DeletePen(this->pen);
  this->pen = IntPtr::Zero;
}

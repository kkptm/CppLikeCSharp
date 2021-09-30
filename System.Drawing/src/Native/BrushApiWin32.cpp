#if defined(_WIN32)
#include <windows.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"
#include <Switch/System/Diagnostics/Debug.hpp>
#include <Switch/System/ArgumentException.hpp>

using namespace System;
using namespace System::Drawing;

intptr Native::BrushApi::CreateSolidBrush(const Color& color) {
  return (intptr)::CreateSolidBrush(RGB(color.R, color.G, color.B));
}

void Native::BrushApi::DeleteBrush(intptr handle) {
  DeleteObject((HGDIOBJ)handle);
}

#endif

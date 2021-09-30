#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include <Switch/System/Diagnostics/Debug.hpp>
#include <Switch/System/ArgumentException.hpp>
#include "Api.hpp"

using namespace System;
using namespace System::Drawing;

intptr Native::PenApi::CreatePen(const System::Drawing::Drawing2D::DashStyle& dashStyle, int32 width, const Color& color) {
  return IntPtr::Zero;
}

void Native::PenApi::DeletePen(intptr handle) {
}

#endif

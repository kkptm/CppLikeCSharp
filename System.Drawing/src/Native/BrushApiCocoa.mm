#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#include <Switch/System/Diagnostics/Debug.hpp>
#include <Switch/System/ArgumentException.hpp>
#include "Api.hpp"

using namespace System;
using namespace System::Drawing;

intptr Native::BrushApi::CreateSolidBrush(const Color& color) {
  return IntPtr::Zero;
}

void Native::BrushApi::DeleteBrush(intptr handle) {
}

#endif

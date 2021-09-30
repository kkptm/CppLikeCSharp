#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

#include "Api.hpp"

using namespace System;

namespace {
  System::Drawing::Color ToColor(NSColor* color) {
    const CGFloat* components = CGColorGetComponents(color.CGColor);
    return System::Drawing::Color::FromArgb(CGColorGetAlpha(color.CGColor) * 0xFF, components[0] * 0xFF, components[1] * 0xFF, components[2] * 0xFF);
  }
}

int32 Native::SystemColorsApi::GetActiveBorder() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetActiveCaption() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetActiveCaptionText() {
  @autoreleasepool {
    NSColor* color = [[NSColor textColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetAppWorkspace() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlBackgroundColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetButtonFace() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetButtonHighlight() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetButtonShadow() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlShadowColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetControl() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetControlDark() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlShadowColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetControlDarkDark() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlDarkShadowColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetControlLight() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetControlLightLight() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlLightHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetControlText() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlTextColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetDesktop() {
  return (int32)0xFF000000;
}

int32 Native::SystemColorsApi::GetGradientActiveCaption() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetGradientInactiveCaption() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetGrayText() {
  @autoreleasepool {
    NSColor* color = [[NSColor disabledControlTextColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetHighlight() {
  @autoreleasepool {
    NSColor* color = [[NSColor selectedControlColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetHighlightText() {
  @autoreleasepool {
    NSColor* color = [[NSColor selectedTextColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetHotTrack() {
  @autoreleasepool {
    NSColor* color = [[NSColor secondarySelectedControlColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetInactiveBorder() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetInactiveCaption() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetInactiveCaptionText() {
  @autoreleasepool {
    NSColor* color = [[NSColor disabledControlTextColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetInfo() {
  return (int32)0xFFFFFFE1;
}

int32 Native::SystemColorsApi::GetInfoText() {
  @autoreleasepool {
    NSColor* color = [[NSColor textColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetMenu() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetMenuBar() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlHighlightColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetMenuHighlight() {
  @autoreleasepool {
    NSColor* color = [[NSColor selectedMenuItemColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetMenuText() {
  @autoreleasepool {
    NSColor* color = [[NSColor textColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetScrollBar() {
  @autoreleasepool {
    NSColor* color = [[NSColor scrollBarColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetWindow() {
  @autoreleasepool {
    NSColor* color = [[NSColor controlBackgroundColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetWindowFrame() {
  @autoreleasepool {
    NSColor* color = [[NSColor windowFrameColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

int32 Native::SystemColorsApi::GetWindowText() {
  @autoreleasepool {
    NSColor* color = [[NSColor windowFrameTextColor] colorUsingColorSpaceName:NSCalibratedRGBColorSpace];
    return ToColor(color).ToArgb();
  }
}

#endif

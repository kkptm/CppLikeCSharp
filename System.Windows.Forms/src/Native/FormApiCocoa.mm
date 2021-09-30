#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"
#include <Switch/System/Random.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace {
  class CocoaApi static_ {
  public:
    static NSWindowStyleMask FormToNSWindowStyleMask(const Form& form) {
      constexpr int CP_NOCLOSE_BUTTON = 0x200;
      NSWindowStyleMask windowStyleMask = NSWindowStyleMaskBorderless;
      
      if (form.FormBorderStyle != FormBorderStyle::None) {
        windowStyleMask |= NSWindowStyleMaskTitled;
        
        if (form.MaximizeBox && (form.FormBorderStyle == FormBorderStyle::Sizable || form.FormBorderStyle == FormBorderStyle::SizableToolWindow))
          windowStyleMask |= NSWindowStyleMaskResizable;
        
        if (form.MinimizeBox)
          windowStyleMask |= NSWindowStyleMaskMiniaturizable;
        
        if (CP_NOCLOSE_BUTTON /*(form.GetCreateParams().ClassStyle | CP_NOCLOSE_BUTTON) == CP_NOCLOSE_BUTTON*/)
          windowStyleMask |= NSWindowStyleMaskClosable;
      }
      
      return windowStyleMask;
    }
  };
}

@interface FormCocoa : NSWindow
- (BOOL)windowShouldClose:(id)sender;
@end

@implementation FormCocoa
- (BOOL)windowShouldClose:(id)sender {
  Message event = Message::Create((intptr)sender, WM_CLOSE, 0, 0, 0, 0);
  const_cast<Control&>(Native::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
  return NO;
}
@end

void Native::FormApi::Close(System::Windows::Forms::Form& form) {
  Message event = Message::Create((intptr)form.Handle(), WM_CLOSE, 0, 0, 0, 0);
  form.WndProc(event);
  //[(NSWindow*)form.Handle() close];
}

intptr Native::FormApi::Create(System::Windows::Forms::Form& form) {
  @autoreleasepool {
    System::Drawing::Rectangle bounds = form.Bounds;
    Random random;
    switch (form.StartPosition) {
      case FormStartPosition::Manual: bounds = form.Bounds; break;
      case FormStartPosition::WindowsDefaultBounds: bounds = System::Drawing::Rectangle(random.Next(50, 300), random.Next(50, 200), random.Next(640, 800), random.Next(480, 600)); break;
      case FormStartPosition::WindowsDefaultLocation: bounds = System::Drawing::Rectangle(random.Next(50, 300), random.Next(50, 200), form.Width, form.Height); break;
      default: break;
    }
    form.Location= System::Drawing::Point(bounds.Left, bounds.Top);
    form.Size= System::Drawing::Size(bounds.Width, bounds.Height);

    FormCocoa* handle = [[FormCocoa alloc] init];
    [handle setStyleMask: CocoaApi::FormToNSWindowStyleMask(form)];
    //[handle setFrame:NSMakeRect(bounds.X(), bounds.Y(), bounds.Width(), bounds.Height()) display:YES];
    //[handle setFrameTopLeftPoint:NSMakePoint(bounds.X(), bounds.Y())];
    
    [handle setTitle:[NSString stringWithUTF8String:form.Text().c_str()]];
    [handle makeKeyAndOrderFront:nil];
    [NSApp activateIgnoringOtherApps:YES];
    //handle.color = CocoaApi::FromColor(form.ForeColor);
    Native::WindowProcedure::Controls[(intptr)handle] = form;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::Form&>(form).WndProc(message);
    return (intptr)handle;
  }
}

#endif

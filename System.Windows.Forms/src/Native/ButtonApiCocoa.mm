#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

@interface ButtonCocoa : NSButton
- (IBAction) Click:(id)sender;
@end

@implementation ButtonCocoa
- (IBAction) Click:(id)sender {
  System::Drawing::Point mouseDownLocation;
  Message event = Message::Create((intptr)sender, WM_LBUTTONUP, 0, mouseDownLocation.X() + (mouseDownLocation.Y() << 16), 0, 0);
  const_cast<Control&>(Native::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
}
@end

intptr Native::ButtonApi::Create(const System::Windows::Forms::Button& button) {
  @autoreleasepool {
    ButtonCocoa *handle = [[[ButtonCocoa alloc] init] autorelease];
    [[(NSWindow*)button.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:button.Text().c_str()]];
    [handle setBezelStyle: button.Height <= 32 ? NSBezelStyleRounded : NSBezelStyleTexturedSquare];
    [handle setButtonType:NSButtonTypeMomentaryPushIn];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setTarget:handle];
    [handle setAction:@selector(Click:)];
    Native::WindowProcedure::Controls[(intptr)handle] = button;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::Button&>(button).WndProc(message);
    return (intptr)handle;
  }
}

void Native::ButtonApi::SetIsDefault(const System::Windows::Forms::Button& button) {
  [(NSButton*)button.Handle() setKeyEquivalent: [NSString stringWithUTF8String:button.IsDefault ? "\r" : ""]];
}

#endif

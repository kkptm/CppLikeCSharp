#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

@interface RadioButtonCocoa : NSButton
- (IBAction) Click:(id)sender;
@end

@implementation RadioButtonCocoa
- (IBAction) Click:(id)sender {
  System::Drawing::Point mouseDownLocation;
  Message event = Message::Create((intptr)sender, WM_LBUTTONUP, 0, mouseDownLocation.X() + (mouseDownLocation.Y() << 16), 0, 0);
  const_cast<Control&>(Native::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
}
@end

intptr Native::RadioButtonApi::Create(const System::Windows::Forms::RadioButton& radioButton) {
  @autoreleasepool {
    RadioButtonCocoa *handle = [[[RadioButtonCocoa alloc] init] autorelease];
    [[(NSWindow*)radioButton.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:radioButton.Text().c_str()]];
    [handle setButtonType:NSButtonTypeRadio];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setTarget:handle];
    [handle setState:true];
    [handle setAction:@selector(Click:)];
    Native::WindowProcedure::Controls[(intptr)handle] = radioButton;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::RadioButton&>(radioButton).WndProc(message);
    return (intptr)handle;
  }
}

void Native::RadioButtonApi::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  [(NSButton*)radioButton.Handle() setState:radioButton.Checked()];
}

void Native::RadioButtonApi::SetGroup(const System::Windows::Forms::RadioButton& radioButton) {
}

#endif

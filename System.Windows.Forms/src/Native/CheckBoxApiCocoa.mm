#if defined(__APPLE__)
#include "WidgetCocoa.hpp"
#include "WindowProcedureApiCocoa.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

@interface CheckBoxCocoa : NSButton
- (IBAction) Click:(id)sender;
@end

@implementation CheckBoxCocoa
- (IBAction) Click:(id)sender {
  System::Drawing::Point mouseDownLocation;
  Message event = Message::Create((intptr)sender, WM_LBUTTONUP, 0, mouseDownLocation.X() + (mouseDownLocation.Y() << 16), 0, 0);
  const_cast<Control&>(Native::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
}
@end

intptr Native::CheckBoxApi::Create(const System::Windows::Forms::CheckBox& checkBox) {
  @autoreleasepool {
    CheckBoxCocoa *handle = [[[CheckBoxCocoa alloc] init] autorelease];
    [[(NSWindow*)checkBox.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setTitle:[NSString stringWithUTF8String:checkBox.Text().c_str()]];
    [handle setButtonType:NSButtonTypeSwitch];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setAllowsMixedState:true];
    [handle setTarget:handle];
    [handle setAction:@selector(Click:)];
    Native::WindowProcedure::Controls[(intptr)handle] = checkBox;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::CheckBox&>(checkBox).WndProc(message);
    return (intptr)handle;
  }
}

void Native::CheckBoxApi::SetAutoCheck(const System::Windows::Forms::CheckBox& checkBox) {
}

void Native::CheckBoxApi::SetChecked(const System::Windows::Forms::CheckBox& checkBox) {
  if (checkBox.CheckState == System::Windows::Forms::CheckState::Indeterminate)
    [(NSButton*)checkBox.Handle() setState:-1];
  else
    [(NSButton*)checkBox.Handle() setState:(int32)checkBox.CheckState()];
}

#endif

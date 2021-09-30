#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

@interface LabelCocoa : NSTextField
- (IBAction) Click:(id)sender;
@end

@implementation LabelCocoa
- (IBAction) Click:(id)sender {
  System::Drawing::Point mouseDownLocation;
  Message event = Message::Create((intptr)sender, WM_LBUTTONUP, 0, mouseDownLocation.X() + (mouseDownLocation.Y() << 16), 0, 0);
  const_cast<Control&>(Native::WindowProcedure::Controls[(intptr)sender]()).WndProc(event);
}
@end

intptr Native::LabelApi::Create(const System::Windows::Forms::Label& label) {
  @autoreleasepool {
    LabelCocoa* handle = [[LabelCocoa alloc] init];
    [[(NSWindow*)label.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setStringValue:[NSString stringWithUTF8String:label.Text().c_str()]];
    [handle setBezeled:NO];
    [handle setDrawsBackground:NO];
    [handle setEditable:NO];
    [handle setSelectable:NO];
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    //handle.drawsBackground = TRUE;
    
    [handle setTarget:handle];
    [handle setAction:@selector(Click:)];
    Native::WindowProcedure::Controls[(intptr)handle] = label;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::Label&>(label).WndProc(message);
    return (intptr)handle;
  }
}

#endif

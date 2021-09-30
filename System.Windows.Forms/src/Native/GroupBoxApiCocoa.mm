#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

intptr Native::GroupBoxApi::Create(const System::Windows::Forms::GroupBox& groupBox) {
  @autoreleasepool {
    NSBox* handle = [[[NSBox alloc] init] autorelease];
    [[(NSWindow*)groupBox.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setTitle:[NSString stringWithUTF8String:groupBox.Text().c_str()]];
    //handle.color = CocoaApi::FromColor(groupBox.ForeColor);
    Native::WindowProcedure::Controls[(intptr)handle] = groupBox;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::GroupBox&>(groupBox).WndProc(message);
    return (intptr)handle;
  }
}

#endif

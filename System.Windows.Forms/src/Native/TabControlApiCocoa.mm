#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

intptr Native::TabControlApi::Create(const System::Windows::Forms::TabControl& tabControl) {
  @autoreleasepool {
    NSTabView* handle = [[[NSTabView alloc] init] autorelease];
    [[(NSWindow*)tabControl.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    //handle.color = CocoaApi::FromColor(tabControl.ForeColor);
    Native::WindowProcedure::Controls[(intptr)handle] = tabControl;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::TabControl&>(tabControl).WndProc(message);
    return (intptr)handle;
  }
}

void Native::TabControlApi::SetAlignment(const System::Windows::Forms::TabControl& tabControl) {
}

#endif

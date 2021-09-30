#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

intptr Native::TabPageApi::Create(const System::Windows::Forms::TabPage& tabPage) {
  @autoreleasepool {
    NSScrollView* handle = [[[NSScrollView alloc] init] autorelease];
    [[(NSWindow*)tabPage.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    //handle.color = CocoaApi::FromColor(tabPage.ForeColor);
    Native::WindowProcedure::Controls[(intptr)handle] = tabPage;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::TabPage&>(tabPage).WndProc(message);
    return (intptr)handle;
  }
}

#endif

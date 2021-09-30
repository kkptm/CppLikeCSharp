#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

intptr Native::PanelApi::Create(const System::Windows::Forms::Panel& panel) {
  @autoreleasepool {
    NSScrollView* handle = [[[NSScrollView alloc] init] autorelease];
    [[(NSWindow*)panel.Parent()().Handle() contentView] addSubview: handle];
    
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    //handle.color = CocoaApi::FromColor(panel.ForeColor);
    Native::WindowProcedure::Controls[(intptr)handle] = panel;
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::Panel&>(panel).WndProc(message);
    return (intptr)handle;
  }
}

void Native::PanelApi::SetBorderStyle(const System::Windows::Forms::Panel& panel) {
  switch (panel.BorderStyle) {
    case BorderStyle::None : [(NSScrollView*)panel.Handle() setBorderType:NSNoBorder]; break;
    case BorderStyle::FixedSingle : [(NSScrollView*)panel.Handle() setBorderType:NSLineBorder]; break;
    case BorderStyle::Fixed3D : [(NSScrollView*)panel.Handle() setBorderType:NSBezelBorder]; break;
  }
}

#endif

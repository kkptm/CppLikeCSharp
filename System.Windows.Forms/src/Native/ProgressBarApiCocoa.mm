#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

intptr Native::ProgressBarApi::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  @autoreleasepool {
    NSProgressIndicator* handle = [[[NSProgressIndicator alloc] init] autorelease];
    [[(NSWindow*)progressBar.Parent()().Handle() contentView] addSubview: handle];
    
    Native::WindowProcedure::Controls[(intptr)handle] = progressBar;
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setIndeterminate:progressBar.Style == ProgressBarStyle::Marquee];
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::ProgressBar&>(progressBar).WndProc(message);
    return (intptr)handle;
  }
}

void Native::ProgressBarApi::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {
  [(NSProgressIndicator*)progressBar.Handle() setMaxValue:progressBar.Maximum()];
}

void Native::ProgressBarApi::SetMinimum(const System::Windows::Forms::ProgressBar& progressBar) {
  [(NSProgressIndicator*)progressBar.Handle() setMinValue:progressBar.Minimum()];
}

void Native::ProgressBarApi::SetMarquee(const System::Windows::Forms::ProgressBar& progressBar) {
  [(NSProgressIndicator*)progressBar.Handle() setIndeterminate:progressBar.Style == ProgressBarStyle::Marquee];
  if (progressBar.Style == ProgressBarStyle::Marquee) {
    [(NSProgressIndicator*)progressBar.Handle() startAnimation:nil];
    // Deprecated since macOS 10.6
    //[(NSProgressIndicator*)progressBar.Handle() setAnimationDelay:(double)progressBar.MarqueeAnimationSpeed()/1000];
  } else
    [(NSProgressIndicator*)progressBar.Handle() stopAnimation:nil];
}

void Native::ProgressBarApi::SetValue(const System::Windows::Forms::ProgressBar& progressBar) {
  [(NSProgressIndicator*)progressBar.Handle() setDoubleValue:progressBar.Value()];
}

#endif

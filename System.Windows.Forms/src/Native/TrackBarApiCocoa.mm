#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

@interface SliderCocoa : NSSlider
- (IBAction) ValueChanged:(id)sender;
@end

@implementation SliderCocoa
- (IBAction) ValueChanged:(id)sender {
  Message event = Message::Create((intptr)sender, [self isVertical] ? WM_VSCROLL : WM_HSCROLL, 0, (intptr)sender, 0, 0);
  Native::WindowProcedure::Controls[(intptr)sender]().Parent()().WndProc(event);
}
@end

intptr Native::TrackBarApi::Create(const System::Windows::Forms::TrackBar& trackBar) {
  @autoreleasepool {
    SliderCocoa* handle = [[[SliderCocoa alloc] init] autorelease];
    [[(NSWindow*)trackBar.Parent()().Handle() contentView] addSubview: handle];
    Native::WindowProcedure::Controls[(intptr)handle] = trackBar;
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setTarget:handle];
    [handle setAction:@selector(ValueChanged:)];

    //[handle setIndeterminate:trackBar.Style == ProgressBarStyle::Marquee];
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::TrackBar&>(trackBar).WndProc(message);
    return (intptr)handle;
  }
}

void Native::TrackBarApi::SetLargeChange(const System::Windows::Forms::TrackBar& trackBar) {
  // Not implemented on macOS
}

void Native::TrackBarApi::SetMaximum(const System::Windows::Forms::TrackBar& trackBar) {
  [(NSSlider*)trackBar.Handle() setMaxValue:trackBar.Maximum()];
}

void Native::TrackBarApi::SetMinimum(const System::Windows::Forms::TrackBar& trackBar) {
  [(NSSlider*)trackBar.Handle() setMinValue:trackBar.Minimum()];
}

void Native::TrackBarApi::SetOrientation(const System::Windows::Forms::TrackBar& trackBar) {
  [(NSSlider*)trackBar.Handle() setVertical:trackBar.Orientation == Orientation::Vertical];
}

void Native::TrackBarApi::SetSmallChange(const System::Windows::Forms::TrackBar& trackBar) {
  // Not implemented on macOS
}

void Native::TrackBarApi::SetTickFrequency(const System::Windows::Forms::TrackBar& trackBar) {
  if (trackBar.TickStyle != TickStyle::None)
    [(NSSlider*)trackBar.Handle() setNumberOfTickMarks:(trackBar.Maximum - trackBar.Minimum) / trackBar.TickFrequency];
}

void Native::TrackBarApi::SetTickStyle(const System::Windows::Forms::TrackBar& trackBar) {
  if (trackBar.TickStyle == TickStyle::TopLeft)
    [(NSSlider*)trackBar.Handle() setTickMarkPosition:NSTickMarkPositionAbove];
}

int32 Native::TrackBarApi::GetValue(const System::Windows::Forms::TrackBar& trackBar) {
  return [(NSSlider*)trackBar.Handle() integerValue];
}

void Native::TrackBarApi::SetValue(const System::Windows::Forms::TrackBar& trackBar) {
  [(NSSlider*)trackBar.Handle() setIntegerValue:trackBar.Value()];
}

#endif

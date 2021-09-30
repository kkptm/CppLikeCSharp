#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

#include <Switch/System/Double.hpp>
#include <Switch/System/Collections/Generic/Dictionary.hpp>
#include "Api.hpp"
#include "WindowMessage.hpp"
#include "WindowMessageKey.hpp"

namespace Native {
  class WindowProcedure static_ {
  public:
    using ControlDictionary = System::Collections::Generic::Dictionary<intptr, ref<System::Windows::Forms::Control>>;

    static ControlDictionary Controls;

    static int32 GetMouseButtonState(NSEvent* event) {
      int32 state = 0;
      if ([event buttonNumber] == 1) state &= MK_LBUTTON;
      if ([event buttonNumber] == 2) state &= MK_MBUTTON;
      if ([event buttonNumber] == 3) state &= MK_RBUTTON;
      return state;
    }

    static void WndProc(NSEvent* event) {
      // {NSEventTypeLeftMouseDragged, WM_...}, {NSEventTypeRightMouseDragged, WM_...}, {NSEventTypeKeyDown, WM_KEYDOWN}, {NSEventTypeKeyUp, WM_KEYUP}, {NSEventTypeFlagsChanged, WM_...}, {NSEventTypeAppKitDefined, WM_...}, {NSEventTypeSystemDefined, WM_...}, {NSEventTypeApplicationDefined, WM_...}, {NSEventTypePeriodic, WM_...}, {NSEventTypeCursorUpdate, WM_SETCURSOR}, {NSEventTypeScrollWheel, WM_MOUSEWHEEL}, {NSEventTypeTabletPoint, WM_...}, {NSEventTypeTabletProximity, WM_...}, {NSEventTypeOtherMouseDragged, WM_...},
      static System::Collections::Generic::Dictionary<int32, delegate<void, NSEvent*, System::Windows::Forms::Control&>> events = {
        {NSEventTypeMouseEntered, WindowProcedure::MouseEnterEvent}, {NSEventTypeMouseExited, WindowProcedure::MouseLeaveEvent}, {NSEventTypeLeftMouseDown, WindowProcedure::LeftMouseDownEvent}, {NSEventTypeLeftMouseUp, WindowProcedure::LeftMouseUpEvent}, {NSEventTypeRightMouseDown, WindowProcedure::RightMouseDownEvent}, {NSEventTypeRightMouseUp, WindowProcedure::RightMouseUpEvent}, {NSEventTypeMouseMoved, WindowProcedure::MouseMoveEvent}, {NSEventTypeOtherMouseDown, WindowProcedure::OtherMouseDownEvent}, {NSEventTypeOtherMouseUp, WindowProcedure::OtherMouseUpEvent}
      };
      @autoreleasepool {
        if (events.ContainsKey([event type]) && Controls.ContainsKey((intptr)[event window]))
          events[[event type]](event, Controls[(intptr)[event window]]);
        else
          [NSApp sendEvent:event];
      }
    }

  private:
    static int32 GetMouseXCoordinateRelativeToClientArea(NSEvent* event, System::Windows::Forms::Control& control) {
      int32 captionHeight = !is<System::Windows::Forms::Form>(control) || as<System::Windows::Forms::Form>(control).FormBorderStyle == System::Windows::Forms::FormBorderStyle::None ? 0 : Native::SystemInformationApi::GetCaptionHeight();
      System::Drawing::Point location(event.locationInWindow.x, event.window.frame.size.height - event.locationInWindow.y - captionHeight);
      return location.X;
    }

    static int32 GetMouseYCoordinateRelativeToClientArea(NSEvent* event, System::Windows::Forms::Control& control) {
      int32 captionHeight = !is<System::Windows::Forms::Form>(control) || as<System::Windows::Forms::Form>(control).FormBorderStyle == System::Windows::Forms::FormBorderStyle::None ? 0 : Native::SystemInformationApi::GetCaptionHeight();
      System::Drawing::Point location(event.locationInWindow.x, event.window.frame.size.height - event.locationInWindow.y - captionHeight);
      return location.Y;
    }

    static void MouseEnterEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_MOUSEENTER, notUsed, notUsed, 0, (intptr)event);
      hover = true;
      control.WndProc(message);
    }

    static void MouseLeaveEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_MOUSELEAVE, notUsed, notUsed, 0, (intptr)event);
      hover = false;
      control.WndProc(message);
    }

    static void LeftMouseDownEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_LBUTTONDOWN, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      control.WndProc(message);
    }

    static void LeftMouseUpEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_LBUTTONUP, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      control.WndProc(message);
    }

    static void OtherMouseUpEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_MBUTTONUP, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      control.WndProc(message);
    }

    static void OtherMouseDownEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_MBUTTONDOWN, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      control.WndProc(message);
    }

    static void RightMouseDownEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_RBUTTONDOWN, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      control.WndProc(message);
    }

    static void RightMouseUpEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_RBUTTONUP, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      control.WndProc(message);
    }

    static void MouseMoveEvent(NSEvent* event, System::Windows::Forms::Control& control) {
      if (hover) {
        System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_MOUSEHOVER, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
        control.WndProc(message);
      }
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)event.window, WM_MOUSEMOVE, GetMouseButtonState(event), (GetMouseYCoordinateRelativeToClientArea(event, control) << 16) + GetMouseXCoordinateRelativeToClientArea(event, control), 0, (intptr)event);
      control.WndProc(message);
    }

    static bool messageLoopRunning ;
    static const int32 notUsed = 0;
    static bool hover;
  };
}

#endif

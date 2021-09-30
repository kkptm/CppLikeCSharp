#include <Switch/System/BitConverter.hpp>
#include <Switch/System/Diagnostics/Debug.hpp>
#include <Switch/System/Drawing/Graphics.hpp>
#include <Switch/System/Drawing/SolidBrush.hpp>
#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Control.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Form.hpp"
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

System::Collections::Generic::Dictionary<intptr, ref<Control>> Control::handles;

namespace {
  /*
  struct ShowDebugTrace {
    static constexpr bool AllWindowMessages = true;
    static constexpr bool MouseWindowMessage = true;
    static constexpr bool WindowMessage = true;
  };

  bool AllWindowMessagesFilter(const Message& message) {
    //return false;
    return true;
    //return message.Msg != WM_TIMER && message.Msg != WM_PAINT && message.Msg != WM_ERASEBKGND;
    //return !message.ToString().Contains("WM_NULL");
  }*/

  MouseButtons MessageToMouseButtons(Message message) {
    if (message.Msg == WM_LBUTTONDBLCLK || message.Msg == WM_LBUTTONDOWN || message.Msg == WM_LBUTTONUP)
      return MouseButtons::Left;
    else if (message.Msg == WM_RBUTTONDBLCLK || message.Msg == WM_RBUTTONDOWN || message.Msg == WM_RBUTTONUP)
      return MouseButtons::Right;
    else if (message.Msg == WM_MBUTTONDBLCLK || message.Msg == WM_MBUTTONDOWN || message.Msg == WM_MBUTTONUP)
      return MouseButtons::Middle;
    else if (message.Msg == WM_XBUTTONDBLCLK || message.Msg == WM_XBUTTONDOWN || message.Msg == WM_XBUTTONUP)
      return (message.WParam() & MK_XBUTTON2) == MK_XBUTTON2 ? MouseButtons::XButton2 : MouseButtons::XButton1;
    return MouseButtons::None;
  }

  MouseButtons WParamToMouseButtons(Message message) {
    if ((message.WParam & MK_LBUTTON) == MK_LBUTTON)
      return MouseButtons::Left;
    else if ((message.WParam & MK_RBUTTON) == MK_RBUTTON)
      return MouseButtons::Right;
    else if ((message.WParam & MK_MBUTTON) == MK_MBUTTON)
      return MouseButtons::Middle;
    return MouseButtons::None;
  }

  System::Drawing::Point MakePoint(intptr param) {
    Array<byte> bytes = BitConverter::GetBytes(param);
    return System::Drawing::Point(BitConverter::ToInt16(bytes, 0), BitConverter::ToInt16(bytes, 2));
  }
}

ref<Control> Control::controlEntered;

void Control::ControlCollection::ChangeParent(ref<Control> value) {
  if (value().parent != null)
    value().parent().controls.Remove(value);
  value().parent = this->controlContainer;
  if (this->controlContainer().Visible && this->controlContainer().handle != IntPtr::Zero && value().handle == IntPtr::Zero)
    value().CreateControl();
}

void Control::ControlCollection::RemoveParent(ref<Control> value) {
  value().parent = null;
}

Control::Control() {
  this->messageActions = {{WM_CAPTURECHANGED, {*this, &Control::WmCaptureChange}}, {WM_CLOSE, {*this, &Control::WmClose}}, {WM_COMMAND, {*this, &Control::WmCommand}}, {WM_CONTEXTMENU, {*this, &Control::WmContextMenu}}, {WM_CREATE, {*this, &Control::WmCreate}}, {WM_CTLCOLOR, {*this, &Control::WmCtlColorControl}}, {WM_CTLCOLORBTN, {*this, &Control::WmCtlColorControl}}, {WM_CTLCOLORDLG, {*this, &Control::WmCtlColorControl}}, {WM_CTLCOLORMSGBOX, {*this, &Control::WmCtlColorControl}}, {WM_CTLCOLORSCROLLBAR, {*this, &Control::WmCtlColorControl}}, {WM_CTLCOLOREDIT, {*this, &Control::WmCtlColorControl}}, {WM_CTLCOLORLISTBOX, {*this, &Control::WmCtlColorControl}}, {WM_CTLCOLORSTATIC, {*this, &Control::WmCtlColorControl}}, {WM_DESTROY, {*this, &Control::WmDestroy}}, {WM_DISPLAYCHANGE, {*this, &Control::WmDisplayChange}}, {WM_DRAWITEM, {*this, &Control::WmDrawItem}}, {WM_ERASEBKGND, {*this, &Control::WmEraseBkgnd}}, {WM_EXITMENULOOP, {*this, &Control::WmExitMenuLoop}}, {WM_GETOBJECT, {*this, &Control::WmGetObject}}, {WM_HELP, {*this, &Control::WmHelp}}, {WM_IME_CHAR, {*this, &Control::WmImeChar}}, {WM_IME_NOTIFY, {*this, &Control::WmImeNotify}}, {WM_IME_STARTCOMPOSITION, {*this, &Control::WmImeStartComposition}}, {WM_INITMENUPOPUP, {*this, &Control::WmInitMenuPopup}}, {WM_INPUTLANGCHANGE, {*this, &Control::WmInputLangChange}}, {WM_INPUTLANGCHANGEREQUEST, {*this, &Control::WmInputLangChangeRequest}}, {WM_CHAR, {*this, &Control::WmKeyChar}}, {WM_KEYDOWN, {*this, &Control::WmKeyChar}}, {WM_SYSKEYDOWN, {*this, &Control::WmKeyChar}}, {WM_KEYUP, {*this, &Control::WmKeyChar}}, {WM_SYSKEYUP, {*this, &Control::WmKeyChar}}, {WM_KILLFOCUS, {*this, &Control::WmKillFocus}}, {WM_MEASUREITEM, {*this, &Control::WmMeasureItem}}, {WM_MENUCHAR, {*this, &Control::WmMenuChar}}, {WM_MENUSELECT, {*this, &Control::WmMenuSelect}}, {WM_LBUTTONDBLCLK, {*this, &Control::WmMouseDown}}, {WM_LBUTTONDOWN, {*this, &Control::WmMouseDown}}, {WM_MBUTTONDBLCLK, {*this, &Control::WmMouseDown}}, {WM_MBUTTONDOWN, {*this, &Control::WmMouseDown}}, {WM_XBUTTONDOWN, {*this, &Control::WmMouseDown}}, {WM_XBUTTONDBLCLK, {*this, &Control::WmMouseDown}}, {WM_RBUTTONDBLCLK, {*this, &Control::WmMouseDown}}, {WM_RBUTTONDOWN, {*this, &Control::WmMouseDown}}, {WM_MOUSEHOVER, {*this, &Control::WmMouseHover}}, {WM_MOUSELEAVE, {*this, &Control::WmMouseLeave}}, {WM_NCMOUSELEAVE, {*this, &Control::WmMouseLeave}}, {WM_MOUSEMOVE, {*this, &Control::WmMouseMove}}, {WM_LBUTTONUP, {*this, &Control::WmMouseUp}}, {WM_MBUTTONUP, {*this, &Control::WmMouseUp}}, {WM_XBUTTONUP, {*this, &Control::WmMouseUp}}, {WM_RBUTTONUP, {*this, &Control::WmMouseUp}}, {WM_MOUSEWHEEL, {*this, &Control::WmMouseWheel}}, {WM_NOTIFY, {*this, &Control::WmNotify}}, {WM_NOTIFYFORMAT, {*this, &Control::WmNotifyFormat}}, {WM_PARENTNOTIFY, {*this, &Control::WmParentNotify}}, {WM_PAINT, {*this, &Control::WmPaint}}, {WM_PRINTCLIENT, {*this, &Control::WmPrintClient}}, {WM_QUERYNEWPALETTE, {*this, &Control::WmQueryNewPalette}}, {WM_SHOWWINDOW, {*this, &Control::WmShowWindow}}, {WM_SETCURSOR, {*this, &Control::WmSetCursor}}, {WM_SETFOCUS, {*this, &Control::WmSetFocus}}, {WM_SYSCOMMAND, {*this, &Control::WmSysCommand}}, {WM_UPDATEUISTATE, {*this, &Control::WmUpdateUIState}}, {WM_WINDOWPOSCHANGED, {*this, &Control::WmWindowPosChanged}}, {WM_WINDOWPOSCHANGING, {*this, &Control::WmWindowPosChanging}}};
  // For message : WM_CTLCOLOR, WM_CTLCOLORBTN, WM_CTLCOLORDLG, WM_CTLCOLORMSGBOX, WM_CTLCOLORSCROLLBAR, WM_CTLCOLOREDIT, WM_CTLCOLORLISTBOX, WM_CTLCOLORSTATIC do create reflect message internal ?
  // For message : WM_HSCROLL, WM_VSCROLL, WM_DELETEITEM, WM_VKEYTOITEM, WM_CHARTOITEM, WM_COMPAREITEM do create reflect message internal ?
  // For message : WM_NOTIFYFORMAT do create reflect message internal ?
  SetStyle(ControlStyles((int32)ControlStyles::AllPaintingInWmPaint | (int32)ControlStyles::UserPaint | (int32)ControlStyles::StandardClick | (int32)ControlStyles::StandardDoubleClick | (int32)ControlStyles::UseTextForAccessibility | (int32)ControlStyles::Selectable), true);
}

property_<System::Drawing::Color, readonly_> Control::DefaultBackColor {
  [] { return System::Drawing::SystemColors::Control(); }
};

property_<System::Drawing::Color, readonly_> Control::DefaultForeColor {
  [] { return System::Drawing::SystemColors::ControlText(); }
};

void Control::CreateControl() {
  if (this->size.IsEmpty())
    this->size = this->DefaultSize;
  if (this->parent != null || is<Form>(*this)) {
    if (this->visible && !this->IsHandleCreated)
      CreateHandle();
    for (ref<Control> control : this->controls)
      control().CreateControl();
    OnCreateControl();
  }
}

void Control::CreateHandle() {
  if (!this->IsHandleCreated)
    this->handle = Native::ControlApi::Create(*this);
  handles.Add(this->handle, *this);
  this->backBrush = System::Drawing::SolidBrush(this->BackColor);
  Native::ControlApi::SetParent(*this); // Must be first
  if (this->setClientSizeAfterHandleCreated)
    Native::ControlApi::SetClientSize(*this);
  else
    Native::ControlApi::SetSize(*this);
  Native::ControlApi::SetLocation(*this); // Must be after SetClientSize or SetSize
  if (this->backColor.HasValue)
    Native::ControlApi::SetBackColor(*this);
  Native::ControlApi::SetEnabled(*this);
  if (this->foreColor.HasValue)
    Native::ControlApi::SetForeColor(*this);
  Native::ControlApi::SetTabStop(*this);
  Native::ControlApi::SetText(*this);
  if (this->setFocusAfterHandleCreated)
    Native::ControlApi::SetFocus(*this);
  Native::ControlApi::SetVisible(*this); // Must be last
}

void Control::DestroyHandle() {
  if (this->IsHandleCreated) {
    Native::ControlApi::Destroy(*this);
    handles.Remove(this->handle);
    this->handle = 0;
  }
}

void Control::DefWndProc(Message& message) {
  Native::ControlApi::DefWndProc(message);
}

bool Control::Focus() {
  if (this->IsHandleCreated)
    return Native::ControlApi::SetFocus(*this);
  this->setFocusAfterHandleCreated = true;
  return true;
}

void Control::Invalidate(bool invalidateChildren) {
  if (this->IsHandleCreated)
    Native::ControlApi::Invalidate(*this, invalidateChildren);
  this->OnInvalidated(InvalidateEventArgs(Rectangle(Point(0, 0), this->ClientSize)));
}

void Control::Invalidate(const System::Drawing::Rectangle& rect, bool invalidateChildren) {
  if (this->IsHandleCreated)
    Native::ControlApi::Invalidate(*this, rect, invalidateChildren);
  this->OnInvalidated(InvalidateEventArgs(rect));
}

void Control::OnBackColorChanged(const EventArgs& e) {
  this->backBrush = System::Drawing::SolidBrush(this->BackColor);
  if (this->IsHandleCreated)
    Native::ControlApi::SetBackColor(*this);
  this->BackColorChanged(*this, e);
}

void Control::OnClientSizeChanged(const EventArgs& e) {
  if (this->IsHandleCreated)
    Native::ControlApi::SetClientSize(*this);
  else
    setClientSizeAfterHandleCreated = true;
  this->ClientSizeChanged(*this, e);
}

void Control::OnEnabledChanged(const EventArgs& e) {
  if (this->IsHandleCreated)
    Native::ControlApi::SetEnabled(*this);
  this->ForeColorChanged(*this, e);
}

void Control::OnForeColorChanged(const EventArgs& e) {
  if (this->IsHandleCreated)
    Native::ControlApi::SetForeColor(*this);
  this->ForeColorChanged(*this, e);
}

void Control::OnLocationChanged(const EventArgs& e) {
  if (this->IsHandleCreated)
    Native::ControlApi::SetLocation(*this);
  this->LocationChanged(*this, e);
}

void Control::OnParentChanged(const EventArgs& e) {
  if (this->IsHandleCreated)
    Native::ControlApi::SetParent(*this);
  this->ParentChanged(*this, e);
}

void Control::OnSizeChanged(const EventArgs& e) {
  if (this->IsHandleCreated)
    Native::ControlApi::SetSize(*this);
  else
    setClientSizeAfterHandleCreated = false;
  this->SizeChanged(*this, e);
}

void Control::OnTabStopChanged(const EventArgs& e) {
  if (this->IsHandleCreated)
    Native::ControlApi::SetTabStop(*this);
  this->TabStopChanged(*this, e);
}

void Control::OnTextChanged(const EventArgs& e) {
  if (this->IsHandleCreated)
    Native::ControlApi::SetText(*this);
  this->TextChanged(*this, e);
}

void Control::OnVisibleChanged(const EventArgs& e) {
  if (this->visible == true)
    CreateControl();
  if (this->IsHandleCreated)
    Native::ControlApi::SetVisible(*this);
  this->VisibleChanged(*this, e);
}

System::Drawing::Point Control::PointToClient(System::Drawing::Point point) const {
  return Native::ControlApi::PointToClient(*this, point);
}

System::Drawing::Point Control::PointToScreen(System::Drawing::Point point) const {
  return Native::ControlApi::PointToScreen(*this, point);
}

bool Control::PreProcessMessage(const Message& msg) {
  return true;
}

bool Control::ReflectMessage(intptr hWnd, Message& message) {
  ref<Control> control = FromHandle(hWnd);
  if (control == null) return false;
  message.Result = control().SendMessage(WM_REFLECT + message.Msg, message.WParam, message.LParam);
  return true;
}

intptr Control::SendMessage(int32 msg, intptr wparam, intptr lparam) const {
  return Native::ControlApi::SendMessage(this->handle, msg, wparam, lparam);
}

void Control::WndProc(Message& message) {
  if (this->messageActions.ContainsKey(message.Msg)) {
    //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::AllWindowMessages && AllWindowMessagesFilter(message), "Control::WndProc message=" + message + ", name=" + this->name);
    this->messageActions[message.Msg](message);
  } else {
    // For message : WM_CTLCOLOR, WM_CTLCOLORBTN, WM_CTLCOLORDLG, WM_CTLCOLORMSGBOX, WM_CTLCOLORSCROLLBAR, WM_CTLCOLOREDIT, WM_CTLCOLORLISTBOX, WM_CTLCOLORSTATIC do create reflect message internal ?
    // For message : WM_NOTIFYFORMAT do create reflect message internal ?
    switch (message.Msg) {
    case WM_HSCROLL:
    case WM_VSCROLL:
    case WM_DELETEITEM:
    case WM_VKEYTOITEM:
    case WM_CHARTOITEM:
    case WM_COMPAREITEM:
      if (!ReflectMessage(message.LParam, message))
        DefWndProc(message);
      break;

    default:
      //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::AllWindowMessages && AllWindowMessagesFilter(message), "DefWndProc message=" + message + ", name=" + this->name);
      this->DefWndProc(message);
      break;
    }
  }
}

void Control::WmCaptureChange(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmCaptureChange message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
  this->OnMouseCaptureChanged(EventArgs::Empty);
}

void Control::WmClose(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmClose message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmCommand(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmCommand message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmContextMenu(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmContextMenu message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmCreate(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmCreate message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
  OnHandleCreated(EventArgs::Empty);
}

void Control::WmCtlColorControl(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmCtlColorControl message=" + message + ", name=" + this->name);
  ref<Control> control = FromHandle(message.LParam);
  if (control == null)
    this->DefWndProc(message);
  else {
    Native::ControlApi::SetBackColor(message.WParam());
    Native::ControlApi::SetForeColor(message.WParam());
    message.Result = (intptr)control().backBrush.GetNativeBrush();
  }
}

void Control::WmDestroy(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmDestroy message=" + message + ", name=" + this->name);
  OnHandleDestroyed(EventArgs::Empty);
  this->DefWndProc(message);
}

void Control::WmDisplayChange(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmDisplayChange message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmDrawItem(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmDrawItem message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmEraseBkgnd(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmEraseBkgnd message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmExitMenuLoop(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmExitMenuLoop message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmGetObject(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmGetObject message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmHelp(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmHelp message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmImeChar(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmImeChar message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmImeNotify(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmImeNotify message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmImeStartComposition(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmImeStartComposition message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmInitMenuPopup(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmInitMenuPopup message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmInputLangChange(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmInputLangChange message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmInputLangChangeRequest(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmInputLangChangeRequest message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmKeyChar(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmKeyChar message=" + message + ", name=" + this->name);
  if (message.Msg == WM_KEYDOWN || message.Msg == WM_SYSKEYDOWN) {
    KeyEventArgs keyEventArgs((Keys)message.WParam());
    OnKeyDown(keyEventArgs);
  } else if (message.Msg == WM_CHAR || message.Msg == WM_SYSCHAR) {
    KeyPressEventArgs keyPressEventArgs((char32)message.WParam());
    OnKeyPress(keyPressEventArgs);
  } else if (message.Msg == WM_KEYUP || message.Msg == WM_SYSKEYUP) {
    KeyEventArgs keyEventArgs((Keys)message.WParam());
    OnKeyUp(keyEventArgs);
  }

  this->DefWndProc(message);
}

void Control::WmKillFocus(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmKillFocus message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
  this->OnLostFocus(EventArgs::Empty);
}

void Control::WmMeasureItem(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmMeasureItem message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmMenuChar(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmMenuChar message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmMenuSelect(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmMenuSelect message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmMouseDown(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::MouseWindowMessage, "Control::WmMouseDown message=" + message + ", name=" + this->name);
  SetState(State::DoubleClickFired, message.Msg == WM_LBUTTONDBLCLK || message.Msg == WM_RBUTTONDBLCLK || message.Msg == WM_MBUTTONDBLCLK || message.Msg == WM_XBUTTONDBLCLK);
  this->DefWndProc(message);
  this->OnMouseDown(MouseEventArgs(MessageToMouseButtons(message), MakePoint(message.LParam()), this->GetState(State::DoubleClickFired) ? 2 : 1, 0));
}

void Control::WmMouseEnter(Message& message) {
  if (controlEntered != *this) {
    if (controlEntered) {
      Message messageMouseLeave = Message::Create(controlEntered().Handle, WM_MOUSELEAVE, message.WParam, message.LParam, 0);
      controlEntered().WmMouseLeave(messageMouseLeave);
    }
    //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::MouseWindowMessage, "Control::WmMouseEnter message=" + message + ", name=" + this->name);
    controlEntered = *this;
    this->DefWndProc(message);
    this->OnMouseEnter(EventArgs::Empty);
  }
}

void Control::WmMouseHover(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::MouseWindowMessage, "Control::WmMouseHover message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
  this->OnMouseHover(EventArgs::Empty);
}

void Control::WmMouseLeave(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::MouseWindowMessage, "Control::WmMouseLeave message=" + message + ", name=" + this->name);
  this->SetState(State::MouseEntered, false);
  controlEntered = null;
  this->DefWndProc(message);
  this->OnMouseLeave(EventArgs::Empty);
}

void Control::WmMouseMove(Message& message) {
  // Warning this code produce error for some Control like Scrollbar and GroupBox
  /*
  if (controlEntered != *this) {
    Message messageMouseEnter = Message::Create(message.HWnd, WM_MOUSEENTER, message.WParam, message.LParam, 0);
    this->WmMouseEnter(messageMouseEnter);
  }*/
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::MouseWindowMessage, "Control::WmMouseMove message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
  this->OnMouseMove(MouseEventArgs(WParamToMouseButtons(message), MakePoint(message.LParam()), 0, 0));
}

void Control::WmMouseUp(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::MouseWindowMessage, "Control::WmMouseUp message=" + message + ", name=" + this->name);
  if (this->GetState(State::DoubleClickFired)) {
    this->OnDoubleClick(EventArgs::Empty);
    this->OnMouseDoubleClick(MouseEventArgs(MessageToMouseButtons(message), MakePoint(message.LParam()), 2, 0));
  } else {
    this->OnClick(EventArgs::Empty);
    this->OnMouseClick(MouseEventArgs(MessageToMouseButtons(message), MakePoint(message.LParam()), 1, 0));
  }
  this->DefWndProc(message);
  this->OnMouseUp(MouseEventArgs(MessageToMouseButtons(message), MakePoint(message.LParam()), 1, 0));
}

void Control::WmMouseWheel(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::MouseWindowMessage, "Control::WmMouseWheel message=" + message + ", name=" + this->name);
  System::Drawing::Point point = this->PointToClient(MakePoint(message.LParam));
  Array<byte> bytes = BitConverter::GetBytes(message.WParam());
  this->DefWndProc(message);
  OnMouseWheel(MouseEventArgs(MouseButtons::None, point, 0, BitConverter::ToInt16(bytes, 2)));
}

void Control::WmNotify(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmNotify message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmNotifyFormat(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmNotifyFormat message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmPaint(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmPaint message=" + message + ", name=" + this->name);
  if (this->GetStyle(ControlStyles::UserPaint)) {
  } else
    this->DefWndProc(message);
  Graphics graphics = Graphics::FromHwndInternal(this->handle);
  System::Drawing::Rectangle clipRectangle((int32)graphics.ClipBounds().Left(), (int32)graphics.ClipBounds().Top(), (int32)graphics.ClipBounds().Width(), (int32)graphics.ClipBounds().Height());
  PaintEventArgs paintEventArgs(clipRectangle, graphics);
  this->OnPaint(paintEventArgs);
}

void Control::WmParentNotify(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmParentNotify message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmPrintClient(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmPrintClient message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmQueryNewPalette(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmQueryNewPalette message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmShowWindow(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmShowWindow message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmSetCursor(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmSetCursor message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmSetFocus(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmSetFocus message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmSysCommand(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmSysCommand message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmUpdateUIState(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmUpdateUIState message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmWindowPosChanged(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmWindowPosChanged message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}

void Control::WmWindowPosChanging(Message& message) {
  //System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmWindowPosChanging message=" + message + ", name=" + this->name);
  this->DefWndProc(message);
}



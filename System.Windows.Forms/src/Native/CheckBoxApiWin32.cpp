#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>

#include "WindowProcedureApiWin32.hpp"

using namespace System;
using namespace System::Windows::Forms;

core_export_ extern HINSTANCE __instance;

intptr Native::CheckBoxApi::Create(const System::Windows::Forms::CheckBox& checkBox) {
  HWND handle = CreateWindowEx(0, WC_BUTTON, checkBox.Text().w_str().c_str(), WS_CHILD | BS_3STATE, checkBox.Left, checkBox.Top, checkBox.Width, checkBox.Height, (HWND)checkBox.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  /// @todo to remove after create SetFont method...
  PostMessage(handle, WM_SETFONT, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);
  return (intptr)handle;
}

void Native::CheckBoxApi::SetAutoCheck(const System::Windows::Forms::CheckBox& checkBox) {
}

void Native::CheckBoxApi::SetChecked(const System::Windows::Forms::CheckBox& checkBox) {
  SendMessage((HWND)checkBox.Handle(), BM_SETCHECK, (int32)checkBox.CheckState(), 0);
}

#endif

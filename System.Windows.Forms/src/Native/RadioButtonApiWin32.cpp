#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>

#include "WindowProcedureApiWin32.hpp"

using namespace System;
using namespace System::Windows::Forms;

core_export_ extern HINSTANCE __instance;

intptr Native::RadioButtonApi::Create(const System::Windows::Forms::RadioButton& radioButton) {
  HWND handle = CreateWindowEx(0, WC_BUTTON, radioButton.Text().w_str().c_str(), WS_CHILD | BS_RADIOBUTTON, radioButton.Left, radioButton.Top, radioButton.Width, radioButton.Height, (HWND)radioButton.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  /// @todo to remove after create SetFont method...
  PostMessage(handle, WM_SETFONT, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);
  return (intptr)handle;
}

void Native::RadioButtonApi::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  SendMessage((HWND)radioButton.Handle(), BM_SETCHECK, radioButton.Checked ? BST_CHECKED : BST_UNCHECKED, 0);
}

void Native::RadioButtonApi::SetGroup(const System::Windows::Forms::RadioButton& radioButton) {
}

#endif

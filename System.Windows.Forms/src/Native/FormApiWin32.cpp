#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Windowsx.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>

#include "WindowProcedureApiWin32.hpp"

using namespace System;
using namespace System::Windows::Forms;

core_export_ extern HINSTANCE __instance;

void Native::FormApi::Close(System::Windows::Forms::Form& form) {
  CloseWindow((HWND)form.Handle());
}

intptr Native::FormApi::Create(System::Windows::Forms::Form& form) {
  System::Drawing::Rectangle bounds = form.Bounds;
  switch (form.StartPosition) {
  case FormStartPosition::WindowsDefaultBounds: bounds = Drawing::Rectangle(CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT); break;
  case FormStartPosition::WindowsDefaultLocation: bounds = Drawing::Rectangle(CW_USEDEFAULT, CW_USEDEFAULT, form.Width, form.Height); break;
  }

  HWND handle = CreateWindowEx(0, WC_DIALOG, form.Text().w_str().c_str(), WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_GROUP, bounds.Left, bounds.Top, bounds.Width, bounds.Height, NULL, (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);

  RECT rect = { 0, 0, 0, 0 };
  GetWindowRect(handle, &rect);
  form.Location = System::Drawing::Point(rect.left, rect.top);
  form.Size = System::Drawing::Size(rect.right - rect.left, rect.bottom - rect.top);

  /// @todo to remove after create SetFont method...
  PostMessage(handle, WM_SETFONT, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);
  return (intptr)handle;
}

#endif

#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"
#include "WindowProcedureApiWin32.hpp"

using namespace System;
using namespace System::Windows::Forms;

core_export_ extern HINSTANCE __instance;

intptr Native::TabControlApi::Create(const System::Windows::Forms::TabControl& tabControl) {
  HWND handle = CreateWindowEx(WS_EX_CONTROLPARENT, WC_TABCONTROL, tabControl.Text().w_str().c_str(), WS_CHILD, tabControl.Left, tabControl.Top, tabControl.Width, tabControl.Height, (HWND)tabControl.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  /// @todo to remove after create SetFont method...
  PostMessage(handle, WM_SETFONT, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);

  /*
  static TCITEM item1;
  item1.mask = TCIF_TEXT | TCIF_IMAGE;
  item1.iImage = -1;
  item1.pszText = L"One";
  //TabCtrl_InsertItem(handle, 0, &item1);
  PostMessage(handle, TCM_INSERTITEM, (WPARAM)0, (LPARAM)&item1);
  static TCITEM item2;
  item2.mask = TCIF_TEXT | TCIF_IMAGE;
  item2.iImage = -1;
  item2.pszText = L"Two";
  //TabCtrl_InsertItem(handle, 0, &item2);
  PostMessage(handle, TCM_INSERTITEM, (WPARAM)1, (LPARAM)&item2);
  */

  return (intptr)handle;
}

void Native::TabControlApi::SetAlignment(const System::Windows::Forms::TabControl& tabControl) {
}

#endif

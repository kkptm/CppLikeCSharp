#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>

#include "WindowProcedureApiWin32.hpp"

using namespace System;
using namespace System::Windows::Forms;

core_export_ extern HINSTANCE __instance;

intptr Native::ProgressBarApi::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  static INITCOMMONCONTROLSEX icc;
  icc.dwSize = sizeof(INITCOMMONCONTROLSEX);
  icc.dwICC = ICC_PROGRESS_CLASS;
  InitCommonControlsEx(&icc);
  int style = WS_CHILD;
  switch (progressBar.Style) {
  case ProgressBarStyle::Continuous: style |= PBS_SMOOTH; break;
  case ProgressBarStyle::Marquee: style |= PBS_MARQUEE; break;
  }
  HWND handle = CreateWindowEx(0, PROGRESS_CLASS, progressBar.Text().w_str().c_str(), style, progressBar.Left, progressBar.Top, progressBar.Width, progressBar.Height, (HWND)progressBar.Parent()().Handle(), (HMENU)0, __instance, (LPVOID)NULL);
  WindowProcedure::SetWindowTheme(handle);
  WindowProcedure::DefWindowProcs[(intptr)handle] = (WNDPROC)SetWindowLongPtr(handle, GWLP_WNDPROC, (LONG_PTR)WindowProcedure::WndProc);
  /// @todo to remove after create SetFont method...
  PostMessage(handle, WM_SETFONT, WPARAM((HFONT)GetStockObject(DEFAULT_GUI_FONT)), TRUE);
  return (intptr)handle;
}

void Native::ProgressBarApi::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {
  SendMessage((HWND)progressBar.Handle(), PBM_SETRANGE32, progressBar.Minimum(), progressBar.Maximum());
}

void Native::ProgressBarApi::SetMinimum(const System::Windows::Forms::ProgressBar& progressBar) {
  SendMessage((HWND)progressBar.Handle(), PBM_SETRANGE32, progressBar.Minimum(), progressBar.Maximum());
}

void Native::ProgressBarApi::SetMarquee(const System::Windows::Forms::ProgressBar& progressBar) {
  SendMessage((HWND)progressBar.Handle(), PBM_SETMARQUEE, progressBar.Style == ProgressBarStyle::Marquee ? 1 : 0, progressBar.MarqueeAnimationSpeed);
}

void Native::ProgressBarApi::SetValue(const System::Windows::Forms::ProgressBar& progressBar) {
  SendMessage((HWND)progressBar.Handle(), PBM_SETPOS, progressBar.Value(), 0);
}

#endif

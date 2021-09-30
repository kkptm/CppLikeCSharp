#if defined(_WIN32)

#include <windows.h>
#include <Windowsx.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>

#include "WindowProcedureApiWin32.hpp"
#include "../../include/Switch/System/Windows/Forms/Control.hpp"
#include "../../include/Switch/System/Windows/Forms/Message.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

#if _WIN64
Dictionary<int64, intptr(__stdcall*)(HWND, uint32, uintptr, int64)> Native::WindowProcedure::DefWindowProcs;
#else
Dictionary<int64, long(__stdcall*)(HWND, uint32, uint32, long)> Native::WindowProcedure::DefWindowProcs;
#endif
//Dictionary<intptr, WNDPROC> WindowProcedure::DefWindowProcs;

void Native::WindowProcedure::SetWindowTheme(HWND handle) {
  if (!Native::ApplicationApi::HasVisualStylesEnabled())
    ::SetWindowTheme(handle, L"", L"");
}

LRESULT CALLBACK Native::WindowProcedure::WndProc(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam) {
  Message message = Message::Create((intptr)hwnd, msg, wParam, lParam, 0);
  Control::FromHandle(message.HWnd)().WndProc(message);
  return message.Result;
}

#endif

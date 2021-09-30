#if defined(_WIN32)

#include <windows.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>

#include "WindowProcedureApiWin32.hpp"

using namespace System;
using namespace System::Windows::Forms;

core_export_ extern HINSTANCE __instance;

namespace {
  static System::Collections::Generic::Dictionary<intptr, delegate<void>> ticks;
  void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
    ticks[idEvent]();
  }
}

intptr Native::TimerApi::Create(int32 interval, delegate<void> tick) {
  intptr handle = (intptr)SetTimer(null, 0, interval, TimerProc);
  ticks[handle] = tick;
  return (intptr)handle;
}

void Native::TimerApi::Destroy(intptr handle) {
  ticks.Remove(handle);
  KillTimer(null, handle);
}

#endif

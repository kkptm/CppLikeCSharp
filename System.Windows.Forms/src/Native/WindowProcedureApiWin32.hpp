#if defined(_WIN32)

#include "Api.hpp"
#include <Switch/System/Collections/Generic/Dictionary.hpp>

  typedef HWND__* HWND;

namespace Native {
  class WindowProcedure static_ {
  public:
    #if _WIN64
    static System::Collections::Generic::Dictionary<int64, intptr(__stdcall*)(HWND, uint32, uintptr, int64)> DefWindowProcs;
    #else
    static System::Collections::Generic::Dictionary<int64, long(__stdcall*)(HWND, uint32, uint32, long)> DefWindowProcs;
    #endif

    static void SetWindowTheme(HWND handle);
    #if _WIN64
    static int64 __stdcall WndProc(HWND hwnd, uint32 msg, uintptr wParam, int64 lParam);
    #else
    static long __stdcall WndProc(HWND hwnd, uint32 msg, uint32 wParam, long lParam);
    #endif
  };
}

#endif

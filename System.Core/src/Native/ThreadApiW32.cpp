#if defined(_WIN32)

#include <windows.h>
#include "../../include/Switch/Undef.hpp"

#include "Api.hpp"

namespace {
  // https://msdn.microsoft.com/en-us/library/xcb2z8hs.aspx
  void SetThreadName(DWORD dwThreadID, const char* threadName) {
#pragma pack(push, 8)
    struct THREADNAME_INFO {
      DWORD dwType;
      LPCSTR szName;
      DWORD dwThreadID;
      DWORD dwFlags;
    };
#pragma pack(pop)

#pragma warning(push)
#pragma warning(disable: 6320 6322)
    __try {
      THREADNAME_INFO info {0x1000, threadName, dwThreadID, 0};
      RaiseException(0x406D1388, 0, sizeof(info) / sizeof(ULONG_PTR), (ULONG_PTR*)&info);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
    }
#pragma warning(pop)
  }
}

bool Native::ThreadApi::Cancel(intptr handle) {
  return TerminateThread((HANDLE)handle, (DWORD) - 1) != FALSE;
}

intptr Native::ThreadApi::GetCurrent() {
  return (intptr)GetCurrentThread();
}

void Native::ThreadApi::Resume(intptr handle) {
  ResumeThread((HANDLE)handle);
}

void Native::ThreadApi::SetNameOfCurrentThread(const string& name) {
#pragma warning(push)
#pragma warning(disable: 4302 4311)
  ::SetThreadName(GetCurrentThreadId(), name.Data());
#pragma warning(pop)
}

bool Native::ThreadApi::SetPriority(intptr handle, int32 priority) {
  return SetThreadPriority((HANDLE)handle, priority - 2) != FALSE;
}

void Native::ThreadApi::Suspend(intptr handle) {
  SuspendThread((HANDLE)handle);
}

#endif

#if defined(_WIN32)

#include <windows.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"

void Native::DebuggerApi::Log(int32 level, const string& category, const string& message) {
  if (string::IsNullOrEmpty(category))
    OutputDebugStringA(message.Data);
  else {
    OutputDebugStringA(category.Data);
    OutputDebugStringA(": ");
    OutputDebugStringA(message.Data);
  }
}

#endif

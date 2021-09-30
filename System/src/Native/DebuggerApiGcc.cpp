#if defined(__linux__) || defined(__APPLE__)

#include <syslog.h>

#include "Api.hpp"

namespace {
  int32 LevelToNative(int32 level) {
    switch (level) {
    case 0: return LOG_EMERG;
    case 1: return LOG_ALERT;
    case 2: return LOG_CRIT;
    case 3: return LOG_ERR;
    case 4: return LOG_WARNING;
    case 5: return LOG_NOTICE;
    case 6: return LOG_INFO;
    case 7: return LOG_DEBUG;
    }
    return LOG_NOTICE;
  }
}

void Native::DebuggerApi::Log(int32 level, const string& category, const string& message) {
  if (string::IsNullOrEmpty(category))
    syslog(LevelToNative(level) | LOG_USER, "%s", message.Data());
  else
    syslog(LevelToNative(level) | LOG_USER, "%.256s: %s", category.Data(), message.Data());
}

#endif

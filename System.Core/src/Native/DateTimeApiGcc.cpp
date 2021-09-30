#if defined(__linux__) || defined(__APPLE__)

#include <cstring>
#include <ctime>

#if !defined(__ANDROID__)
#include <sys/timeb.h>
#else
struct timeb {
  time_t    time;   /* [XSI] Seconds since the Epoch */
  unsigned short  millitm;  /* [XSI] Milliseconds since the Epoch */
  short   timezone; /* [XSI] Minutes west of CUT */
  short   dstflag;  /* [XSI] non-zero if DST in effect */
};

int ftime(struct timeb*);
#endif
#include "../../include/Switch/Undef.hpp"

#include "Api.hpp"

int32 Native::DateTimeApi::Ftime(int64& seconds, int32& milliseconds, int32& timeZone, bool& daylight) {
  struct timeb value;
  if (ftime(&value) != 0)
    return -1;

  seconds = value.time;
  milliseconds = value.millitm;
  timeZone = value.timezone;
  daylight = value.dstflag != 0;
  return 0;
}

int32 Native::DateTimeApi::Gmtime(int64 time, int32& year, int32& month, int32& day, int32& hour, int32& minute, int32& second, int32& dayOfYear, int32& dayOfWeek) {
  struct tm value;
  if (gmtime_r((const time_t*)&time, &value) == null)
    return -1;

  year = value.tm_year + 1900;
  month = value.tm_mon + 1;
  day = value.tm_mday;
  hour = value.tm_hour;
  minute = value.tm_min;
  second = value.tm_sec;
  dayOfYear = value.tm_yday + 1;
  dayOfWeek = value.tm_wday;
  return 0;
}

int32 Native::DateTimeApi::Localtime(int64 time, int32& year, int32& month, int32& day, int32& hour, int32& minute, int32& second, int32& dayOfYear, int32& dayOfWeek) {
  struct tm value;
  if (localtime_r((const time_t*)&time, &value) == null)
    return -1;

  year = value.tm_year + 1900;
  month = value.tm_mon + 1;
  day = value.tm_mday;
  hour = value.tm_hour;
  minute = value.tm_min;
  second = value.tm_sec;
  dayOfYear = value.tm_yday + 1;
  dayOfWeek = value.tm_wday;
  return 0;
}

int64 Native::DateTimeApi::Mkgmtime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second) {
  struct tm localValue = {second, minute, hour, day, month - 1, year - 1900, 0, 0, -1, 0, null};
  int64 localTime = mktime(&localValue);

  struct tm gmtValue;
  if (gmtime_r((const time_t*)&localTime, &gmtValue) == 0)
    return -1;

  int64 gmtTime = mktime(&gmtValue);
  return localTime + (localTime - gmtTime + (gmtValue.tm_isdst > 0 ? 3600 : 0));
}

int64 Native::DateTimeApi::Mktime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second) {
  struct tm tmValue = {second, minute, hour, day, month - 1, year - 1900, 0, 0, -1, 0, null};
  return mktime(&tmValue);
}

int32 Native::DateTimeApi::Strftime(string& output, const string& format, int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, int32 dayOfYear, int32 dayOfWeek, bool daylight) {
  struct tm value = { second, minute, hour, day, month - 1, year - 1900, dayOfWeek, dayOfYear, daylight == true ? 1 : 0, 0, null };
  char buffer[256];
  int32 result = (int32)strftime(buffer, 256, format.Data, &value);
  output = buffer;
  return result;
}

bool Native::DateTimeApi::IsDaylight(int64 localTime) {
  struct tm value;
  localtime_r((const time_t*)&localTime, &value);
  return value.tm_isdst != 0;
}

#endif

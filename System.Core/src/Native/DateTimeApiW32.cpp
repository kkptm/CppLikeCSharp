#if defined(_WIN32)

#include <time.h>
#include <string>
#include <windows.h>
#include "../../include/Switch/Undef.hpp"

#include "Api.hpp"

namespace {
  const int64 dateFixOs = 116444736000000000ULL; // Diff 01/01/1601 and 01/01/1970
}

int32 Native::DateTimeApi::Ftime(int64& seconds, int32& milliseconds, int32& timeZone, bool& daylight) {
  TIME_ZONE_INFORMATION tzi = { 0 };
  if (GetTimeZoneInformation(&tzi) == TIME_ZONE_ID_UNKNOWN)
    return -1;

  SYSTEMTIME st = { 0 };
  GetSystemTime(&st);
  seconds = Mkgmtime(st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
  milliseconds = st.wMilliseconds;
  daylight = (tzi.Bias == (tzi.StandardBias + tzi.DaylightBias) && tzi.DaylightBias != 0);
  timeZone = (int32)tzi.Bias;
  return 0;
}

int32 Native::DateTimeApi::Gmtime(int64 time, int32& year, int32& month, int32& day, int32& hour, int32& minute, int32& second, int32& dayOfYear, int32& dayOfWeek) {
  ULARGE_INTEGER uli = { 0 };
  uli.QuadPart = (time * 10000000UL) + dateFixOs;
  FILETIME ft = { uli.LowPart, uli.HighPart };
  SYSTEMTIME st = { 0 };
  if (FileTimeToSystemTime(&ft, &st) == 0)
    return -1;

  year = st.wYear;
  month = st.wMonth;
  day = st.wDay;
  dayOfWeek = st.wDayOfWeek;
  hour = st.wHour;
  minute = st.wMinute;
  second = st.wSecond;
  dayOfYear = (int32)((time - Mkgmtime(st.wYear, 1, 1, 0, 0, 0)) / (86400)) + 1;
  return 0;
}

int32 Native::DateTimeApi::Localtime(int64 time, int32& year, int32& month, int32& day, int32& hour, int32& minute, int32& second, int32& dayOfYear, int32& dayOfWeek) {
  ULARGE_INTEGER uli = { 0 };
  uli.QuadPart = (time * 10000000UL) + dateFixOs;
  FILETIME ft = { uli.LowPart, uli.HighPart };
  FILETIME locFt = { 0 };
  if (FileTimeToLocalFileTime((const FILETIME*)&ft, &locFt) == 0)
    return -1;

  SYSTEMTIME st = { 0 };
  if (FileTimeToSystemTime(&locFt, &st) == 0)
    return -1;

  year = st.wYear;
  month = st.wMonth;
  day = st.wDay;
  dayOfWeek = st.wDayOfWeek;
  hour = st.wHour;
  minute = st.wMinute;
  second = st.wSecond;
  dayOfYear = (int32)((time - Mkgmtime(st.wYear, 1, 1, 0, 0, 0)) / (86400)) + 1;
  return 0;
}

int64 Native::DateTimeApi::Mkgmtime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second) {
  SYSTEMTIME st = { (WORD)year, (WORD)month, 0, (WORD)day, (WORD)hour, (WORD)minute, (WORD)second, 0 };
  FILETIME ft = { 0 };
  if (SystemTimeToFileTime(&st, &ft) == 0)
    return -1;

  ULARGE_INTEGER lt = { ft.dwLowDateTime, ft.dwHighDateTime };
  lt.QuadPart -= dateFixOs;
  lt.QuadPart /= 10000000ULL;
  return lt.QuadPart;
}

int64 Native::DateTimeApi::Mktime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second) {
  SYSTEMTIME st = { (WORD)year, (WORD)month, 0, (WORD)day, (WORD)hour, (WORD)minute, (WORD)second, 0 };
  FILETIME ft = { 0 };
  if (SystemTimeToFileTime(&st, &ft) == 0)
    return -1;

  FILETIME ftUtc;
  if (LocalFileTimeToFileTime((const FILETIME*)&ft, &ftUtc) == 0)
    return -1;

  ULARGE_INTEGER lt = { ftUtc.dwLowDateTime, ftUtc.dwHighDateTime };
  lt.QuadPart -= dateFixOs;
  lt.QuadPart /= 10000000ULL;
  return lt.QuadPart;
}

int32 Native::DateTimeApi::Strftime(string& output, const string& format, int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, int32 dayOfYear, int32 dayOfWeek, bool daylight) {
  struct tm value = { second, minute, hour, day, month - 1, year - 1900, dayOfWeek, dayOfYear, daylight == true ? 1 : 0 };
  char buffer[256];
  int32 result = (int32)strftime(buffer, 256, format.Data, &value);
  output = buffer;
  return result;
}

bool Native::DateTimeApi::IsDaylight(int64 localTime) {
  struct tm value = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  localtime_s(&value, &localTime);
  return value.tm_isdst != 0;
}

#endif

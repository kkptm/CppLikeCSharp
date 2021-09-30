#include <cstdio>

#include "../../../include/Switch/System/DateTime.hpp"
#include "../../../include/Switch/System/Convert.hpp"
#include "../../Native/Api.hpp"

using namespace System;

namespace {
  constexpr int64 DateTimeMaximumValue = 3155378975999999999LL;
  constexpr int64 DateTimeMinimumValue = 0LL;
  constexpr int64 TicksTo1970 = 621355968000000000LL;
}

DateTime DateTime::MaxValue = DateTime(DateTimeMaximumValue);
DateTime DateTime::MinValue = DateTime(DateTimeMinimumValue);

DateTime DateTime::Now() {
  int64 secondes = 0;
  int32 milliseconds = 0, timeZone = 0;
  bool daylight = false;

  if (Native::DateTimeApi::Ftime(secondes, milliseconds, timeZone, daylight) != 0)
    return DateTime();

  return DateTime(secondes * TimeSpan::TicksPerSecond + (int64)milliseconds * TimeSpan::TicksPerMillisecond + TicksTo1970, DateTimeKind::Local);
}

DateTime DateTime::Today() {
  int64 secondes = 0;
  int32 milliseconds = 0, timeZone = 0;
  bool daylight = false;

  if (Native::DateTimeApi::Ftime(secondes, milliseconds, timeZone, daylight) != 0)
    return DateTime();

  int64 timeZoneGap = 0;
  if (timeZone < 0)
    timeZoneGap = timeZone - (daylight ? 60 : 0);
  else
    timeZoneGap = timeZone + (daylight ? 60 : 0);

  return DateTime(((secondes) * TimeSpan::TicksPerSecond) / TimeSpan::TicksPerDay * TimeSpan::TicksPerDay + timeZoneGap * TimeSpan::TicksPerMinute + (int64)milliseconds * TimeSpan::TicksPerMillisecond + TicksTo1970, DateTimeKind::Local);
}

DateTime DateTime::UtcNow() {
  int64 secondes = 0;
  int32 milliseconds = 0, timeZone = 0;
  bool daylight = false;

  if (Native::DateTimeApi::Ftime(secondes, milliseconds, timeZone, daylight) != 0)
    return DateTime();

  return DateTime(secondes * TimeSpan::TicksPerSecond + (int64)milliseconds * TimeSpan::TicksPerMillisecond + TicksTo1970, DateTimeKind::Utc);
}

DateTime::DateTime(const DateTime& date) {
  this->value = date.value;
  this->kind = date.kind;
}

DateTime::DateTime() {
}

DateTime::DateTime(int64 ticks): value(ticks), kind(DateTimeKind::Unspecified) {
  if (ticks > DateTimeMaximumValue || ticks < DateTimeMinimumValue)
    throw ArgumentOutOfRangeException(caller_);
}

DateTime::DateTime(int64 ticks, DateTimeKind kind) : value(ticks), kind(kind) {
  if (ticks > DateTimeMaximumValue || ticks < DateTimeMinimumValue)
    throw ArgumentOutOfRangeException(caller_);
}

DateTime::DateTime(int32 year, int32 month, int32 day) {
  SetDateTime(year, month, day, 0, 0, 0, 0, DateTimeKind::Unspecified);
}

DateTime::DateTime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second) {
  SetDateTime(year, month, day, hour, minute, second, 0, DateTimeKind::Unspecified);
}

DateTime::DateTime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, DateTimeKind kind) {
  SetDateTime(year, month, day, hour, minute, second, 0, kind);
}

DateTime::DateTime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, int32 millisecond) {
  SetDateTime(year, month, day, hour, minute, second, millisecond, DateTimeKind::Unspecified);
}

DateTime::DateTime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, int32 millisecond, DateTimeKind kind) {
  SetDateTime(year, month, day, hour, minute, second, millisecond, kind);
}

int32 DateTime::GetDay() const {
  int32 day = 1, ignore = 0;
  GetDateTime(ignore, ignore, day, ignore, ignore, ignore, ignore, ignore);
  return day;
}

System::DayOfWeek DateTime::GetDayOfWeek() const {
  int32 dayOfWeek = 0, ignore = 0;
  GetDateTime(ignore, ignore, ignore, ignore, ignore, ignore, ignore, dayOfWeek);
  return (System::DayOfWeek)dayOfWeek;
}

int32 DateTime::GetDayOfYear() const {
  int32 dayOfYear = 0, ignore = 0;
  GetDateTime(ignore, ignore, ignore, ignore, ignore, ignore, dayOfYear, ignore);
  return dayOfYear;
}

int32 DateTime::GetHour() const {
  int32 hour = 0, ignore = 0;
  GetDateTime(ignore, ignore, ignore, hour, ignore, ignore, ignore, ignore);
  return hour;
}

DateTimeKind DateTime::GetKind() const {
  return this->kind;
}

int32 DateTime::GetMillisecond() const {
  return Convert::ToInt32(int64((this->value % TimeSpan::TicksPerSecond) / TimeSpan::TicksPerMillisecond));
}

int32 DateTime::GetMinute() const {
  int32 minute = 0, ignore = 0;
  GetDateTime(ignore, ignore, ignore, ignore, minute, ignore, ignore, ignore);
  return minute;
}

int32 DateTime::GetMonth() const {
  int32 month = 1, ignore = 0;
  GetDateTime(ignore, month, ignore, ignore, ignore, ignore, ignore, ignore);
  return month;
}

int32 DateTime::GetSecond() const {
  int32 second = 0, ignore = 0;
  GetDateTime(ignore, ignore, ignore, ignore, ignore, second, ignore, ignore);
  return second;
}

int64 DateTime::GetTicks() const {
  return this->value;
}

TimeSpan DateTime::GetTimeOfDay() const {
  int32 hour = 0, minute = 0, second = 1, ignore = 0;
  GetDateTime(ignore, ignore, ignore, hour, minute, second, ignore, ignore);
  return TimeSpan(hour, minute, second);
}

int32 DateTime::GetYear() const {
  int32 year = 1, ignore = 0;
  GetDateTime(year, ignore, ignore, ignore, ignore, ignore, ignore, ignore);
  return year;
}

TypeCode DateTime::GetTypeCode() const {
  return TypeCode::DateTime;
}

int32 DateTime::DaysInMonth(int32 year, int32 month) {
  if (month < 1 || month > 12)
    throw ArgumentOutOfRangeException(caller_);

  if (month == 2)
    return IsLeapYear(year) ? 29 : 28;

  if (month == 4 || month == 6 || month == 9 || month == 11)
    return 30;

  return 31;
}

DateTime DateTime::FromFileTime(int64 fileTime) {
  return FromFileTimeUtc(fileTime).ToLocalTime();
}

DateTime DateTime::FromFileTimeUtc(int64 fileTime) {
  return DateTime(fileTime + 621355968000000000LL, DateTimeKind::Utc);
}

bool DateTime::IsDaylightSavingTime() const {
  if (this->kind != DateTimeKind::Local)
    return false;
  return Native::DateTimeApi::IsDaylight((this->value - TicksTo1970) / TimeSpan::TicksPerSecond);
}

const String DateTime::ToLongDateString() const {
  return ToString("%A %d %B %Y");
}

const String DateTime::ToLongTimeString() const {
  return ToString("%H:%M:%S");
}

const String DateTime::ToShortDateString() const {
  return ToString("%d/%m/%Y");
}

const String DateTime::ToShortTimeString() const {
  return ToString("%H:%M");
}

String DateTime::ToString() const {
  return ToString("%d/%m/%Y %H:%M:%S");
}

DateTime DateTime::Parse(const String& str) {
  return DateTime();
}

DateTime DateTime::SpecifyKind(DateTime value, DateTimeKind kind) {
  if (kind == DateTimeKind::Local && value.kind != DateTimeKind::Local)
    return value.ToLocalTime();

  if (kind == DateTimeKind::Utc && value.kind != DateTimeKind::Utc)
    return value.ToUniversalTime();

  if (kind == DateTimeKind::Unspecified)
    return DateTime(value.value, DateTimeKind::Unspecified);

  return value;
}

DateTime DateTime::ToLocalTime() const {
  if (this->kind != DateTimeKind::Unspecified)
    return DateTime(this->value, DateTimeKind::Local);

  int32 year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, dayOfYear = 0,  dayOfWeek = 0;
  Native::DateTimeApi::Gmtime((this->value - TicksTo1970) / TimeSpan::TicksPerSecond, year, month, day, hour, minute, second, dayOfYear, dayOfWeek);

  int64 seconds = Native::DateTimeApi::Mkgmtime(year, month, day, hour, minute, second);
  if (seconds == -1)
    throw InvalidOperationException(caller_);

  return DateTime(seconds * TimeSpan::TicksPerSecond + TicksTo1970, DateTimeKind::Local);
}

DateTime DateTime::ToUniversalTime() const {
  if (this->kind != DateTimeKind::Unspecified)
    return DateTime(this->value, DateTimeKind::Utc);

  int32 year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, dayOfYear = 0, dayOfWeek = 0;
  Native::DateTimeApi::Gmtime((this->value - TicksTo1970) / TimeSpan::TicksPerSecond, year, month, day, hour, minute, second, dayOfYear, dayOfWeek);

  int64 seconds = Native::DateTimeApi::Mktime(year, month, day, hour, minute, second);
  if (seconds == -1)
    throw InvalidOperationException(caller_);

  return DateTime(seconds * TimeSpan::TicksPerSecond + TicksTo1970, DateTimeKind::Utc);
}

void DateTime::SetDateTime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, int32 millisecond, DateTimeKind kind) {
  int32 dayOfYear = 0, dayOfWeek = 0;

  int32 maxYear = 1, maxMonth = 1, maxDay = 1, maxHour = 0, maxMinute = 0, maxSecond = 0;
  DateTime::MaxValue.GetDateTime(maxYear, maxMonth, maxDay, maxHour, maxMinute, maxSecond, dayOfYear, dayOfWeek);

  int32 minYear = 1, minMonth = 1, minDay = 1, minHour = 0, minMinute = 0, minSecond = 0;
  DateTime::MinValue.GetDateTime(minYear, minMonth, minDay, minHour, minMinute, minSecond, dayOfYear, dayOfWeek);

  if (year  < minYear ||
    (year == minYear && month  < minMonth) ||
    (year == minYear && month == minMonth && day  < minDay) ||
    (year == minYear && month == minMonth && day == minDay && hour  < minHour) ||
    (year == minYear && month == minMonth && day == minDay && hour == minHour && minute  < minMinute) ||
    (year == minYear && month == minMonth && day == minDay && hour == minHour && minute == minMinute && second < minSecond))
    throw ArgumentOutOfRangeException(caller_);

  if (year  > maxYear ||
    (year == maxYear && month  > maxMonth) ||
    (year == maxYear && month == maxMonth && day  > maxDay) ||
    (year == maxYear && month == maxMonth && day == maxDay && hour > maxHour) ||
    (year == maxYear && month == maxMonth && day == maxDay && hour == maxHour && minute > maxMinute) ||
    (year == maxYear && month == maxMonth && day == maxDay && hour == maxHour && minute == maxMinute && second > maxSecond))
    throw ArgumentOutOfRangeException(caller_);

  int64 seconds = kind == DateTimeKind::Local ? Native::DateTimeApi::Mktime(year, month, day, hour, minute, second) : Native::DateTimeApi::Mkgmtime(year, month, day, hour, minute, second);
  if (seconds == -1)
    throw InvalidOperationException(caller_);

  this->kind = kind;
  this->value = seconds * TimeSpan::TicksPerSecond + (int64)millisecond * TimeSpan::TicksPerMillisecond + TicksTo1970;
}

void DateTime::GetDateTime(int32& year, int32& month, int32& day, int32& hour, int32& minute, int32& second, int32& dayOfYear,  int32& dayOfWeek) const {
  if (this->kind == DateTimeKind::Local)
    Native::DateTimeApi::Localtime((this->value - TicksTo1970) / TimeSpan::TicksPerSecond, year, month, day, hour, minute, second, dayOfYear, dayOfWeek);
  else
    Native::DateTimeApi::Gmtime((this->value - TicksTo1970) / TimeSpan::TicksPerSecond, year, month, day, hour, minute, second, dayOfYear, dayOfWeek);
}

bool DateTime::Equals(const DateTime& value) const {
  return this->value == value.value;
}

bool DateTime::Equals(const object& obj) const {
  return is<DateTime>(obj) && Equals((const DateTime&)obj);
}

int32 DateTime::GetHashCode() const {
  return (int32)(this->value & 0x00000000FFFFFFFF) ^ (int32)((this->value >> 32) & 0x00000000FFFFFFFF);
}

String DateTime::ToString(const String& format) const {
  int32 year = 1, month = 1, day = 1, hour = 0, minute = 0, second = 0, dayOfYear = 0, dayOfWeek = 0;
  GetDateTime(year, month, day, hour, minute, second, dayOfYear, dayOfWeek);

  string value;
  Native::DateTimeApi::Strftime(value, format.Data(), year, month, day, hour, minute, second, dayOfYear, dayOfWeek, IsDaylightSavingTime());
  return value;
}

int32 DateTime::CompareTo(const DateTime& value) const {
  if ((this->value - value.value) > 0)
    return 1;

  if ((this->value - value.value) < 0)
    return -1;

  return 0;
}

int32 DateTime::CompareTo(const IComparable& obj) const {
  if (!is<DateTime>(obj))
    return 1;

  return CompareTo(static_cast<const DateTime&>(obj));
}

bool DateTime::ToBoolean(const IFormatProvider& provider) const {
  throw InvalidCastException(caller_);
}

byte DateTime::ToByte(const IFormatProvider& provider) const {
  throw InvalidCastException(caller_);
}

char32 DateTime::ToChar(const IFormatProvider& provider) const {
  throw InvalidCastException(caller_);
}

DateTime DateTime::ToDateTime(const IFormatProvider& provider) const {
  return DateTime(this->value);
}

double DateTime::ToDouble(const IFormatProvider& provider) const {
  return (double)this->value;
}

int16 DateTime::ToInt16(const IFormatProvider& provider) const {
  if (this->value < Int16::MinValue)
    throw OverflowException(caller_);

  if (this->value > Int16::MaxValue)
    throw OverflowException(caller_);

  return (int16)this->value;
}

int32 DateTime::ToInt32(const IFormatProvider& provider) const {
  if (this->value < Int32::MinValue)
    throw OverflowException(caller_);

  if (this->value > Int32::MaxValue)
    throw OverflowException(caller_);

  return (int32)this->value;
}

int64 DateTime::ToInt64(const IFormatProvider& provider) const {
  return (int64)this->value;
}

uint16 DateTime::ToUInt16(const IFormatProvider& provider) const {
  if (this->value < UInt16::MinValue)
    throw OverflowException(caller_);

  if (this->value > UInt16::MaxValue)
    throw OverflowException(caller_);

  return (uint16)this->value;
}

uint32 DateTime::ToUInt32(const IFormatProvider& provider) const {
  if (this->value < static_cast<int32>(UInt32::MinValue))
    throw OverflowException(caller_);

  if (this->value > UInt32::MaxValue)
    throw OverflowException(caller_);

  return (uint32)this->value;
}

uint64 DateTime::ToUInt64(const IFormatProvider& provider) const {
  if (this->value < static_cast<int64>(UInt64::MinValue))
    throw OverflowException(caller_);

  if ((uint64)this->value > UInt64::MaxValue)
    throw OverflowException(caller_);

  return (uint64)this->value;
}

sbyte DateTime::ToSByte(const IFormatProvider& provider) const {
  if (this->value < SByte::MinValue)
    throw OverflowException(caller_);

  if (this->value > SByte::MaxValue)
    throw OverflowException(caller_);

  return (sbyte)this->value;
}

float DateTime::ToSingle(const IFormatProvider& provider) const {
  return (float)this->value;
}

String DateTime::ToString(const IFormatProvider& provider) const {
  return ToString();
}



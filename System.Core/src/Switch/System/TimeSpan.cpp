#include "../../../include/Switch/System/TimeSpan.hpp"
#include "../../../include/Switch/System/Array.hpp"
#include "../../../include/Switch/System/Convert.hpp"
#include "../../../include/Switch/System/Int32.hpp"
#include "../../../include/Switch/System/Int64.hpp"
#include "../../../include/Switch/System/Math.hpp"
#include "../../../include/Switch/System/String.hpp"
#include "../../../include/Switch/System/StringSplitOptions.hpp"
#include "../../../include/Switch/System/SystemException.hpp"
#include "../../../include/Switch/Boxing.hpp"

using namespace System;

TimeSpan TimeSpan::MaxValue {Int64::MaxValue};

TimeSpan TimeSpan::MinValue {Int64::MinValue};

constexpr int64 TimeSpan::TicksPerDay;

constexpr int64 TimeSpan::TicksPerHour;

constexpr int64 TimeSpan::TicksPerMillisecond;

constexpr int64 TimeSpan::TicksPerMinute;

constexpr int64 TimeSpan::TicksPerSecond;

TimeSpan TimeSpan::Zero() {
  return TimeSpan(0);
}

TimeSpan::TimeSpan(const TimeSpan& timeSpan) {
  this->value = timeSpan.value;
}

TimeSpan TimeSpan::Add(const TimeSpan& value) const {
  return TimeSpan(this->value + value.value);
}

int32 TimeSpan::Compare(const TimeSpan& timeSpanA, const TimeSpan& timeSpanB) {
  return timeSpanA.CompareTo(timeSpanB);
}

TimeSpan TimeSpan::Duration() const {
  return TimeSpan(Math::Abs(this->value));
}

bool TimeSpan::Equals(const TimeSpan& value) const {
  return (this->value == value.value);
}

bool TimeSpan::Equals(const TimeSpan& timeSpanA, const TimeSpan& timeSpanB) {
  return timeSpanA.Equals(timeSpanB);
}

TimeSpan TimeSpan::Parse(const string& str) {
  int32 days = 0, hours = 0, minutes = 0, seconds = 0, milliSeconds = 0, ticks = 0;
  Array<string> items = str.Split({'-', ':', '.', '\0'}, StringSplitOptions(StringSplitOptions::RemoveEmptyEntries));

  if (items.Length == 1)
    days = Int32::Parse(items[0]);

  if (items.Length == 2) {
    hours = Int32::Parse(items[0]);
    minutes = Int32::Parse(items[1]);
  }

  if (items.Length == 3) {
    hours = Int32::Parse(items[0]);
    minutes = Int32::Parse(items[1]);
    seconds = Int32::Parse(items[2]);
  }

  if (items.Length == 4) {
    days = Int32::Parse(items[0]);
    hours = Int32::Parse(items[1]);
    minutes = Int32::Parse(items[2]);
    seconds = Int32::Parse(items[3]);
  }

  if (items.Length == 5) {
    if (items[4].Length() != 7)
      throw FormatException(caller_);

    days = Int32::Parse(items[0]);
    hours = Int32::Parse(items[1]);
    minutes = Int32::Parse(items[2]);
    seconds = Int32::Parse(items[3]);
    milliSeconds = Int32::Parse(items[4]) / 10000;
    ticks = Int32::Parse(items[4]) % 10000;
  }

  if (items.Length > 5 || str.LastIndexOf('-') > 0 || (items.Length == 5 && str.LastIndexOf(':') > str.LastIndexOf('.')))
    throw FormatException(caller_);

  if (0 > hours || hours > 24 || 0 > minutes || minutes > 60 || 0 > seconds || seconds > 60 || 0 > milliSeconds || milliSeconds > 999)
    throw OverflowException(caller_);

  if (str[0] == '-')
    return TimeSpan(days * TicksPerDay + hours * TicksPerHour + minutes * TicksPerMinute + seconds * TicksPerSecond + milliSeconds * TicksPerMillisecond + ticks).Negative();

  return TimeSpan(days * TicksPerDay + hours * TicksPerHour + minutes * TicksPerMinute + seconds * TicksPerSecond + milliSeconds * TicksPerMillisecond + ticks);
}

bool TimeSpan::TryParse(const string& str, TimeSpan& value) {
  try {
    value = Parse(str);
  } catch (...) {
    return false;
  }
  return true;
}

bool TimeSpan::Equals(const object& obj) const {
  return is<TimeSpan>(obj) && Equals(static_cast<const TimeSpan&>(obj));
}

int32 TimeSpan::GetHashCode() const {
  int32 hash = 0;

  hash = (int32)(this->value & 0x00000000FFFFFFFF);
  hash = hash ^ (int32)((this->value >> 32) & 0x00000000FFFFFFFF);

  return hash;
}

string TimeSpan::ToString() const {
  string retValue;

  if (this->value < 0)
    retValue += "-";

  if (this->value / TicksPerDay)
    retValue += Box(Math::Abs(Days())).ToString("d") + ".";

  retValue += Box(Math::Abs(Hours())).ToString("d2") + ":" + Box(Math::Abs(Minutes())).ToString("d2") + ":" + Box(Math::Abs(Seconds())).ToString("d2");

  if (this->value % TicksPerSecond)
    retValue += string(".") + Box(Math::Abs(Milliseconds())).ToString("d3") + Box((int32)Math::Abs(this->value % TicksPerMillisecond)).ToString("d4");

  return retValue;
}

int32 TimeSpan::CompareTo(const TimeSpan& value) const {
  if (this->value < value.value)
    return -1;

  if (this->value == value.value)
    return 0;

  return 1;
}

int32 TimeSpan::CompareTo(const IComparable& obj) const {
  if (!is<TimeSpan>(obj))
    return 1;

  return CompareTo(static_cast<const TimeSpan&>(obj));
}

TimeSpan TimeSpan::FromMilliseconds(double milliseconds) {
  return TimeSpan(Convert::ToInt64(milliseconds) * TicksPerMillisecond);
}

TimeSpan& TimeSpan::operator =(const TimeSpan& value) {
  this->value = value.value;
  return *this;
}

TimeSpan& TimeSpan::operator +=(const TimeSpan& value) {
  this->value += value.value;
  return *this;
}

TimeSpan& TimeSpan::operator -=(const TimeSpan& value) {
  this->value -= value.value;
  return *this;
}

TimeSpan TimeSpan::operator +(const TimeSpan& value) {
  TimeSpan result = *this;
  result += value;
  return result;
}

TimeSpan TimeSpan::operator -(const TimeSpan& value) {
  TimeSpan result = *this;
  result -= value;
  return result;
}

TimeSpan& TimeSpan::operator ++() {
  ++this->value;
  return *this;
}

TimeSpan TimeSpan::operator ++(int) {
  return TimeSpan(this->value++);
}

TimeSpan& TimeSpan::operator --() {
  --this->value;
  return *this;
}

TimeSpan TimeSpan::operator --(int) {
  return TimeSpan(this->value--);
}


#include "../../../include/Switch/System/Boolean.hpp"
#include "../../../include/Switch/System/DateTime.hpp"
#include "../../../include/Switch/System/FormatException.hpp"

using namespace System;

constexpr bool Boolean::False;
constexpr bool Boolean::True;

const String Boolean::FalseString = "False";

const String Boolean::TrueString = "True";

bool Boolean::Parse(const String& str) {
  bool value;
  if (TryParse(str, value) == false)
    throw FormatException(caller_);
  return value;
}

bool Boolean::TryParse(const String& str, bool& value) {
  String trimed  = str.TrimStart(' ').TrimEnd(' ');
  if (String::Compare(trimed, TrueString, true) != 0 && String::Compare(trimed, FalseString, true) != 0)
    return false;
  value = String::Compare(trimed, TrueString, true) == 0;
  return true;
}

String Boolean::ToString() const {
  return this->value ? TrueString : FalseString;
}

DateTime Boolean::ToDateTime(const IFormatProvider& provider) const {
  return this->value ? DateTime::MaxValue : DateTime::MinValue;
}

String Boolean::ToString(const IFormatProvider& provider) const {
  return ToString();
}

//std::ostream& System::operator<<(std::ostream& output, const Boolean& value) {
//  return output << value.ToString();
//}

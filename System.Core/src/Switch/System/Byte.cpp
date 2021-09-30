#include "../../../include/Switch/System/Byte.hpp"
#include "../../../include/Switch/System/Convert.hpp"
#include "../../../include/Switch/System/DateTime.hpp"
#include "../../../include/Switch/System/NumericalFormat.hpp"
#include "../../../include/Switch/System/NumericalParsing.hpp"

using namespace System;

constexpr byte Byte::MaxValue;
constexpr byte Byte::MinValue;

byte Byte::Parse(const String& str, const int32 base) {
  return Convert::ToByte(NumericalParsing::ParseUnsigned(str, base));
}

String Byte::ToString(const String& format, const IFormatProvider&) const {
  int32 precision;
  switch (NumericalFormat::GetFormatType(format, precision)) {
  case 0: return NumericalFormat::Format_Custom(Convert::ToUInt64(this->value), format);
  case 'b': return NumericalFormat::Format_B(Convert::ToUInt64(this->value), precision);
  case 'd': return NumericalFormat::Format_D(Convert::ToUInt64(this->value), precision);
  case 'e': return NumericalFormat::Format_E(Convert::ToUInt64(this->value), precision == 0 ? 3 : precision, false);
  case 'E': return NumericalFormat::Format_E(Convert::ToUInt64(this->value), precision == 0 ? 3 : precision, true);
  case 'f': return NumericalFormat::Format_F(Convert::ToUInt64(this->value), format.Length() == 1 ? 2 : precision);
  case 'g': return NumericalFormat::Format_G(Convert::ToUInt64(this->value), precision == 0 ? 3 : precision, false);
  case 'G': return NumericalFormat::Format_G(Convert::ToUInt64(this->value), precision == 0 ? 3 : precision, true);
  case 'n': return NumericalFormat::Format_N(Convert::ToUInt64(this->value), format.Length() == 1 ? 2 : precision);
  case 'p': return NumericalFormat::Format_P(Convert::ToUInt64(this->value), format.Length() == 1 ? 2 : precision);
  case 'x': return NumericalFormat::Format_X(Convert::ToUInt64(this->value), precision, false, 2);
  case 'X': return NumericalFormat::Format_X(Convert::ToUInt64(this->value), precision, true,  2);
  }
  return format;
}

DateTime Byte::ToDateTime(const IFormatProvider& provider) const {
  return this->value;
}

std::ostream& System::operator<<(std::ostream& output, const Byte& value) {
  return output << value.ToString();
}

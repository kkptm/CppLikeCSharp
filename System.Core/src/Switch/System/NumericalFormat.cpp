#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

#include "../../../include/Switch/Types.hpp"
#include "../../../include/Switch/System/NumericalFormat.hpp"
#include "../../../include/Switch/System/Collections/Generic/List.hpp"
#include "../../../include/Switch/System/SystemException.hpp"
#include "../../Native/Api.hpp"

using namespace System;

namespace Switch {
  namespace System {
    static inline bool IsDigit(char32  c) {
      return c >= '0' && c <= '9';
    }

    // avoid returning "-0"
    static inline string notMinusZero(const char* s) {
      if (strcmp(s, "-0") == 0) return "0";
      else return s;
    }

    // verify that :
    // any exponent contains the minimum number of numbers, but at least 'size'.
    // 'e' in the exponent is transformed in 'E' if 'upper' is true.
    static string controlLengthExp(const string& s, bool upper, int size) {
      int32 endNumber = s.IndexOfAny({'e', 'E'});
      if (endNumber == -1) return s;
      return s.Remove(endNumber) + (upper ? s.Substring(endNumber, 2).ToUpper() :  s.Substring(endNumber, 2)) + Int32(Int32::Parse(s.Substring(endNumber + 2))).ToString(string::Format("D{0}", size));
    }

    // do not use Int32::Parse because it allows Trimming and allows to have sign
    // the .net standard does not allow that in format precision specifiers
    static bool ParsePrecision(const String& format, int32& precision) {
      char32 c1 = 0, c2 = 0;
      int32 count = 0;

      CharEnumerator reverseEnumerator = format.GetReverseEnumerator();
      while (reverseEnumerator.MoveNext()) {
        char32 c = reverseEnumerator.Current;
        if (!IsDigit(c))
          return false;
        if (count == 0)
          c2 = c - '0';
        else if (count == 1)
          c1 = c - '0';
        else if (c > '0')
          return false;

        count += 1;
      }

      precision = c1 * 10 + c2;
      return true;
    }

    char32 NumericalFormat::GetFormatType(const String& format, int32& precision) {
      if (format.Length() == 0) {
        precision = 0;
        return 'G';
      }

      char32 type = format[0];
      if (type == 'D') type = 'd';
      else if (type == 'P') type = 'p';
      else if (type == 'B') type = 'b';
      else if (type == 'N') type = 'n';
      else if (type == 'F') type = 'f';

      if (type == 'b' || type == 'e' || type == 'E' || type == 'g' || type == 'G' || type == 'x' || type == 'X' || type == 'd' || type == 'n' || type == 'f' || type == 'p') {
        if (!ParsePrecision(format.Substring(1), precision))
          return 0;
      }
      // types R, r, C, c, are not supported by now.
      return type;
    }

    String NumericalFormat::Format_D(int64 value, int32 precision) {
      char cout[192];
      if (precision > 0)
        sprintf(cout, Native::FormatApi::IntegerWithPrecision().Data, precision, value);
      else
        sprintf(cout, Native::FormatApi::Integer().Data, value);
      if (cout[0] == '-') {
        int32 pad = precision - static_cast<int32>(strlen(cout));
        if (pad == 0)
          return string("-0") + &cout[1];
      }
      return cout;
    }

    String NumericalFormat::Format_D(uint64 value, int32 precision) {
      char cout[192];
      if (precision > 0)
        sprintf(cout, Native::FormatApi::UnsignedIntegerWithPrecision().Data, precision, value);
      else
        sprintf(cout, Native::FormatApi::UnsignedInteger().Data, value);
      return cout;
    }

    String NumericalFormat::Format_B(int64 v, int32 precision, int32 nbBits) {

      uint64 complement;

      if (v >= 0)
        complement = v;
      else {
        if (nbBits == 64)
          complement = static_cast<uint64>(v);
        else {
          uint64 maxValue = 1;
          maxValue = maxValue << nbBits;
          complement = maxValue + v;
        }
      }
      return Format_B(complement, precision);
    }

    String NumericalFormat::Format_B(uint64 value, int32 precision) {
      char cout[65]; // 0 ... 63 64
      int32 entry = 63;
      cout[64] = 0;
      for (int32 i = 63; i >= 0; i--) {
        if ((value & 1) == 0)
          cout[i] = '0';
        else {
          entry = i;
          cout[i] = '1';
        }
        value = value >> 1;
      }

      String s(&cout[entry]);
      if (s.Length() < precision)
        return String('0', precision - s.Length()) + s;
      return s;
    }

    String NumericalFormat::Format_E(uint64 value, int32 precision, bool upper) {
      char cout[192];
      if (upper)
        sprintf(cout, "%.*E", precision, (double)value);
      else
        sprintf(cout, "%.*e", precision, (double)value);
      if (strchr(cout, 'e') == null) {
        sprintf(cout, Native::FormatApi::UnsignedInteger().Data, value);
        return cout;
      }
      return controlLengthExp(cout, upper, 3);
    }

    String NumericalFormat::Format_E(int64 value, int32 precision, bool upper) {
      char cout[192];
      if (upper)
        sprintf(cout, "%.*E", precision, (double)value);
      else
        sprintf(cout, "%.*e", precision, (double)value);

      if (strchr(cout, 'e') == null) {
        sprintf(cout, Native::FormatApi::Integer().Data, value);
        return cout;
      }
      return controlLengthExp(cout, upper, 3);
    }

    String NumericalFormat::Format_E(double value, int32 precision, bool upper) {
      char cout[192];
      if (upper)
        sprintf(cout, "%.*E", precision, (double)value);
      else
        sprintf(cout, "%.*e", precision, (double)value);
      string output = controlLengthExp(cout, upper, 3);
      if (output == "-0") return "0";
      return output;
    }

    String NumericalFormat::Format_E(decimal value, int32 precision, bool upper) {
      char cout[192];
      if (upper)
        sprintf(cout, "%.*LE", precision, (decimal)value);
      else
        sprintf(cout, "%.*Le", precision, (decimal)value);
      string output = controlLengthExp(cout, upper, 3);
      if (output == "-0") return "0";
      return output;
    }

    String NumericalFormat::Format_F(uint64 value, int32 precision) {
      String format_d = Format_D(value, 0);
      if (precision > 0) return format_d + "." + String('0', precision);
      return format_d;
    }

    String NumericalFormat::Format_F(int64 value, int32 precision) {
      String format_d = Format_D(value, 0);
      if (precision > 0) return format_d + "." + String('0', precision);
      return format_d;
    }

    String NumericalFormat::Format_F(double value, int32 precision) {
      char cout[192];
      sprintf(cout, "%.*f", precision, value);
      return notMinusZero(cout);
    }

    String NumericalFormat::Format_F(decimal value, int32 precision) {
      char cout[192];
      sprintf(cout, "%.*Lf", precision, value);
      return notMinusZero(cout);
    }

    String NumericalFormat::Format_G(uint64 value, int32 precision, bool upper) {
      char cout[192];
      sprintf(cout, "%.*g", precision, (double)value);
      if (strchr(cout, 'e') == null) {
        sprintf(cout, Native::FormatApi::UnsignedInteger().Data, value);
        return cout;
      }
      return controlLengthExp(cout, upper, 2);
    }

    String NumericalFormat::Format_G(int64 value, int32 precision, bool upper) {
      char cout[192];
      sprintf(cout, "%.*g", precision, (double)value);

      if (strchr(cout, 'e') == null) {
        sprintf(cout, Native::FormatApi::Integer().Data, value);
        return cout;
      }
      return controlLengthExp(cout, upper, 2);
    }

    String NumericalFormat::Format_G(double value, int32 precision, bool upper) {
      char cout[192];
      sprintf(cout, "%.*g", precision, (double)value);
      string output = controlLengthExp(cout, upper, 2);
      if (output == "-0") return "0";
      return output;
    }

    String NumericalFormat::Format_G(decimal value, int32 precision, bool upper) {
      char cout[192];
      sprintf(cout, "%.*Lg", precision, (decimal)value);
      string output = controlLengthExp(cout, upper, 2);
      if (output == "-0") return "0";
      return output;
    }

    static String InsertGroupSeparator(const String& s, char32 separator, char32 groupSeparator) {
      String output;
      int distance_from_separator = s.IndexOf(separator);
      if (distance_from_separator == -1) distance_from_separator = s.Length();
      for (char32 c : s) {
        output += c;
        if (c == '-')
          distance_from_separator -= 1;
        else {
          distance_from_separator -= 1;
          if (distance_from_separator > 0 && (distance_from_separator % 3 == 0))
            output += groupSeparator;
        }
      }
      return output;
    }

    String NumericalFormat::Format_N(uint64 value, int32 precision) {
      String format_f(Format_F(value, precision));
      return InsertGroupSeparator(format_f, '.', ',');
    }

    String NumericalFormat::Format_N(int64 value, int32 precision) {
      String format_f(Format_F(value, precision));
      return InsertGroupSeparator(format_f, '.', ',');
    }

    String NumericalFormat::Format_N(double value, int32 precision) {
      String format_f(Format_F(value, precision));
      return InsertGroupSeparator(format_f, '.', ',');
    }

    String NumericalFormat::Format_N(decimal value, int32 precision) {
      String format_f(Format_F(value, precision));
      return InsertGroupSeparator(format_f, '.', ',');
    }

    String NumericalFormat::Format_P(uint64 value, int32 precision) {
      // no multiplication by 100 when value is zero
      if (value == uint64(0))
        return Format_N(uint64(0), precision) + " %";

      // multiply by 100 (but avoid overflow by not not using value*100)
      String s = Format_D(value, 0) + "00";
      // add the decimals
      if (precision > 0) s += "." + String('0', precision);
      // format result
      return InsertGroupSeparator(s, '.', ',') + " %";
    }

    String NumericalFormat::Format_P(int64 value, int32 precision) {
      // no multiplication by 100 when value is zero
      if (value == uint64(0))
        return Format_N(uint64(0), precision) + " %";

      // multiply by 100 (but avoid overflow by not not using value*100)
      String s = Format_D(value, 0) + "00";
      // add the decimals
      if (precision > 0) s += "." + String('0', precision);
      // format result
      return InsertGroupSeparator(s, '.', ',') + " %";
    }

    String NumericalFormat::Format_P(double value, int32 precision) {
      // no multiplication by 100 when value is zero
      if (value <= 0.0 && value >= 0.0f)
        return Format_N(uint64(0), precision) + " %";

      // format with augmented precision (will be multiplied by 100).
      String s = Format_F(value, precision + 2);

      if (s.Substring(0, 1) == "0") s = s.Substring(1);
      if (s.Substring(0, 2) == "-0") s = "-" + s.Substring(2);

      int32 split = s.IndexOf('.');
      if (split == -1) // in case of "." is not used as separator anymore, and code needs refactoring
        throw FormatException(caller_);

      // multiply by 100
      s = s.Remove(split, 1);
      split += 2;

      // add the decimals
      if (precision > 0)
        s = s.Insert(split, ".");

      // format result
      return InsertGroupSeparator(s, '.', ',') + " %";
    }

    String NumericalFormat::Format_P(decimal value, int32 precision) {
      // no multiplication by 100 when value is zero
      if (value <= 0.0 && value >= 0.0f)
        return Format_N(uint64(0), precision) + " %";

      // format with augmented precision (will be multiplied by 100).
      String s = Format_F(value, precision + 2);

      if (s.Substring(0, 1) == "0") s = s.Substring(1);
      if (s.Substring(0, 2) == "-0") s = "-" + s.Substring(2);

      int32 split = s.IndexOf('.');
      if (split == -1) // in case of "." is not used as separator anymore, and code needs refactoring
        throw FormatException(caller_);

      // multiply by 100
      s = s.Remove(split, 1);
      split += 2;

      // add the decimals
      if (precision > 0)
        s = s.Insert(split, ".");

      // format result
      return InsertGroupSeparator(s, '.', ',') + " %";
    }

    String NumericalFormat::Format_X(uint64 value, int32 precision, bool upper, int32 size) {
      char cout[192];
      char* trimmed = cout;
      if (upper)
        sprintf(cout, Native::FormatApi::HexadecimalWithPrecision().Data, precision, value);
      else
        sprintf(cout, Native::FormatApi::LowerHexadecimalWithPrecision().Data, precision, value);
      String output = cout;
      int32 excess = static_cast<int32>(strlen(cout)) - size;
      if (excess > 0) trimmed = &cout[excess];
      int32 pad = precision - static_cast<int32>(strlen(trimmed));
      if (pad > 0) return String('0', pad) + trimmed;
      return trimmed;
    }

    String NumericalFormat::Format_X(int64 value, int32 precision, bool upper, int32 size) {
      char cout[192];
      char* trimmed = cout;
      if (upper)
        sprintf(cout, Native::FormatApi::HexadecimalWithPrecision().Data, precision, value);
      else
        sprintf(cout, Native::FormatApi::LowerHexadecimalWithPrecision().Data, precision, value);
      String output = cout;
      int32 excess = static_cast<int32>(strlen(cout)) - size;
      if (excess > 0) trimmed = &cout[excess];
      int32 pad = precision - static_cast<int32>(strlen(trimmed));
      if (pad > 0) return String('0', pad) + trimmed;
      return trimmed;
    }

    String NumericalFormat::Format_Custom(int64 value, const string& format) {
      return "";
    }

    String NumericalFormat::Format_Custom(uint64 value, const string& format) {
      return "";
    }

    String NumericalFormat::Format_Custom(double value, const string& format) {
      return "";
    }

    String NumericalFormat::Format_Custom(decimal value, const string& format) {
      return "";
    }

    //SByte& arg TEMP_FORMAT("%d");
    //Int16& arg TEMP_FORMAT("%d");
    //UInt16& arg TEMP_FORMAT("%u");
    //Int32& arg TEMP_FORMAT("%d");
    //UInt32& arg TEMP_FORMAT("%lu");
    //Int64& arg TEMP_FORMAT("%lld");
    //UInt64& arg TEMP_FORMAT("%llu");
    //Single& arg TEMP_FORMAT("%f");
    //Double& arg TEMP_FORMAT("%g");

  } // System
} // Switch

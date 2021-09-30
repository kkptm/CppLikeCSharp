/// @file
/// @brief Contains Switch::System::Math class.
#pragma once

#include <cmath>
#include "../Static.hpp"
#include "Convert.hpp"
#include "Double.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Int64.hpp"
#include "OverflowException.hpp"
#include "SByte.hpp"
#include "Single.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Provides constants and static methods for trigonometric, logarithmic, and other common mathematical functions.
    /// @par Examples
    /// This class cannot be inherited.
    /// @include Math.cpp
    class core_export_ Math static_ {
    public:
      /// @brief Represents the natural logarithmic base, specified by the constant, e. This field is constant.
      /// @remarks The value of this field is 2.7182818284590452354.
      static constexpr double E = 2.7182818284590452354;

      /// @brief Represents the ratio of the circumference of a circle to its diameter, specified by the constant, p. This field is constant.
      /// @remarks The value of this field is 3.14159265358979323846.
      static constexpr double PI = 3.14159265358979323846;

      /// @brief Returns the absolute value of a double-precision floating-point number
      /// @param value A number in the range double::MinValue <= value <= double::MaxValue
      /// @return double A double-precision floating-point number, x, such that 0 <= x <= double::MaxValue
      static decimal Abs(decimal value) { return value < 0 ? -value : value; }

      /// @brief Returns the absolute value of a double-precision floating-point number
      /// @param value A number in the range double::MinValue <= value <= double::MaxValue
      /// @return double A double-precision floating-point number, x, such that 0 <= x <= double::MaxValue
      static double Abs(double value) { return value < 0 ? -value : value; }

      /// @brief Returns the absolute value of a 16-bit signed integer.
      /// @param value A number in the range int16::MinValue < value <= int16::MaxValue
      /// @return int16 A 16-bit signed integer, x, such that 0 <= x <= int16::MaxValue
      /// @exception OverflowException value equals Int16::MinValue.
      static int16 Abs(int16 value) {
        if (value == Int16::MinValue)
          throw OverflowException(caller_);
        return value < 0 ? -value : value;
      }

      /// @brief Returns the absolute value of a 32-bit signed integer
      /// @param value A number in the range int32::MinValue < value <= int32::MaxValue
      /// @return int32 A 32-bit signed integer, x, such that 0 <= x <= int32::MaxValue
      /// @exception OverflowException value equals Int32::MinValue.
      static int32 Abs(int32 value) {
        if (value == Int32::MinValue)
          throw OverflowException(caller_);
        return value < 0 ? -value : value;
      }

      /// @brief Returns the absolute value of a 64-bit signed integer
      /// @param value A number in the range int64::MinValue < value <= int64::MaxValue
      /// @return int64 A 64-bit signed integer, x, such that 0 <= x <= int64::MaxValue
      /// @exception OverflowException value equals Int64::MinValue.
      static int64 Abs(int64 value) {
        if (value == Int64::MinValue)
          throw OverflowException(caller_);
        return value < 0 ? -value : value;
      }

      /// @brief Returns the absolute value of a 8-bit signed integer.
      /// @param value A number in the range sbyte::MinValue < value <= sbyte::MaxValue
      /// @return sbyte A 8-bit signed integer, x, such that 0 <= x <= sbyte::MaxValue
      /// @exception OverflowException value equals SByte::MinValue.
      static sbyte Abs(sbyte value) {
        if (value == SByte::MinValue)
          throw OverflowException(caller_);
        return value < 0 ? -value : value;
      }

      /// @brief Returns the absolute value of a single-precision floating-point number
      /// @param value A number in the range single::MinValue <= value <= single::MaxValue
      /// @return single A single-precision floating-point number, x, such that 0 <= x <= single::MaxValue
      static float Abs(float value) {return value < 0 ? -value : value;}

      /// @brief Returns the angle whose cosine is the specified number.
      /// @param value A number representing a cosine, where -1 <= value <= 1.
      /// @return double An angle, A, measured in radians, such that 0 <= A <= PI.
      /// -or-
      /// NaN if value < -1 or d > 1.
      static double Acos(double value);

      /// @brief Returns the angle whose sine is the specified number.
      /// @param value A number representing a sine, where -1 <= value <= 1.
      /// @return double An angle, A, measured in radians, such that -PI/2 <= A <= PI/2.
      /// -or-
      /// NaN if value < -1 or d > 1.
      static double Asin(double value);

      /// @brief Returns the angle whose tangent is the specified number.
      /// @param value A number representing a tangent.
      /// @return double An angle, A, measured in radians, such that -PI/2 <= ? <= PI/2.
      /// -or-
      /// NaN if value equals NaN, -PI/2 rounded to double precision (-1.5707963267949) if d equals NegativeInfinity, or PI/2 rounded to double precision (1.5707963267949) if d equals PositiveInfinity
      static double Atan(double value);

      /// @brief Returns the angle whose tangent is the specified number.
      /// @param y The y coordinate of a point.
      /// @param x The x coordinate of a point.
      /// @return double An angle, A, measured in radians, such that -PI <= A <= PI, and tan(?) = y / x, where (x, y) is a point in the Cartesian plane. Observe the following:
      /// * For (x, y) in quadrant 1, 0 < A < PI/2.
      /// * For (x, y) in quadrant 2, PI/2 < A <= PI.
      /// * For (x, y) in quadrant 3, -PI < A < -PI/2.
      /// * For (x, y) in quadrant 4, -PI/2 < A < 0.
      /// * For points on the boundaries of the quadrants, the return value is the following:
      /// * If x is 0 and y is not negative, A = 0.
      /// * If x is 0 and y is negative, A = PI.
      /// * If x is positive and y is 0, A = PI/2.
      /// * If x is negative and y is 0, A = -PI/2.
      /// @remarks The return value is the angle in the Cartesian plane formed by the x-axis, and a vector starting from the origin, (0,0), and terminating at the point, (x,y).
      static double Atan2(double y, double x);

      /// @brief Produces the full product of two 32-bit numbers.
      /// @param a The first int32 to multiply.
      /// @param b The second int32 to multiply.
      /// @return int64 The int64 containing the product of the specified numbers.
      static int64 BigMul(int32 a, int32 b) {return as<int64>(a) * as<int64>(b);}

      /// @brief Returns the smallest integer greater than or equal to the specified double-precision floating-point number.
      /// @param value A double-precision floating-point number.
      /// @return double The smallest integer greater than or equal to value. If value is equal to NaN, NegativeInfinity, or PositiveInfinity, that value is returned.
      static decimal Ceiling(decimal value);

      /// @brief Returns the smallest integer greater than or equal to the specified double-precision floating-point number.
      /// @param value A double-precision floating-point number.
      /// @return double The smallest integer greater than or equal to value. If value is equal to NaN, NegativeInfinity, or PositiveInfinity, that value is returned.
      static double Ceiling(double value);

      /// @brief Returns the cosine of the specified angle.
      /// @param value An angle, measured in radians.
      /// @return double The cosine of value. If value is equal to NaN, NegativeInfinity, or PositiveInfinity, this method returns NaN.
      static double Cos(double value);

      /// @brief Returns the hyperbolic cosine of the specified angle.
      /// @param value An angle, measured in radians.
      /// @return double The hyperbolic cosine of value. If value is equal to NegativeInfinity or PositiveInfinity, PositiveInfinity is returned. If value is equal to NaN, NaN is returned.
      static double Cosh(double value);

      /// @brief Calculates the quotient of two 32-bit signed integers and also returns the remainder in an output parameter.
      /// @param dividend The dividend.
      /// @param divisor The divisor.
      /// @param remainder An angle, measured in radians.
      /// @return int32 The remainder.
      static int32 DivRem(int32 dividend, int32 divisor, int32& remainder) {
        remainder = dividend % divisor;
        return dividend / divisor;
      }

      /// @brief Calculates the quotient of two 64-bit signed integers and also returns the remainder in an output parameter.
      /// @param dividend The dividend.
      /// @param divisor The divisor.
      /// @param remainder An angle, measured in radians.
      /// @return int64 The remainder.
      static int64 DivRem(int64 dividend, int64 divisor, int64& remainder) {
        remainder = dividend % divisor;
        return dividend / divisor;
      }

      /// @brief Returns e raised to the specified power.
      /// @param value A number specifying a power.
      /// @return double The number e raised to the power d. If value equals NaN or PositiveInfinity, that value is returned. If value equals NegativeInfinity, 0 is returned.
      static double Exp(double value);

      /// @brief Returns the largest integer less than or equal to the specified decimal number.
      /// @param value A double-precision floating-point number.
      /// @return  double The largest integer less than or equal to value.
      static decimal Floor(decimal value);

      /// @brief Returns the largest integer less than or equal to the specified decimal number.
      /// @param value A double-precision floating-point number.
      /// @return  double The largest integer less than or equal to value.
      static double Floor(double value);

      /// @brief Returns the remainder resulting from the division of a specified number by another specified number.
      /// @param dividend A dividend.
      /// @param divisor A divisor.
      /// @return double A number equal to x - (y Q), where Q is the quotient of x / y rounded to the nearest integer (if x / y falls halfway between two integers, the even integer is returned).
      /// * If x - (y Q) is zero, the value +0 is returned if x is positive, or -0 if x is negative.
      /// * If y = 0, NaN is returned.
      static double IEEERemainder(double dividend, double divisor) {return divisor == 0 ? Double::NaN : dividend - (divisor * Round(dividend / divisor));}

      /// @brief Returns the natural (base e) logarithm of a specified number.
      /// @param value A number whose logarithm is to be found.
      /// @return double One of the values in the following table.
      /// | value parameter           | Return value                                                  |
      /// |---------------------------|---------------------------------------------------------------|
      /// | Positive                  | The natural logarithm of d; that is, ln value, or log e value |
      /// | Zero                      | NegativeInfinity                                              |
      /// | Negative                  | NaN                                                           |
      /// | Equal to NaN              | NaN                                                           |
      /// | Equal to PositiveInfinity | PositiveInfinity                                              |
      /// @remarks Parameter value is specified as a base 10 number.
      static double Log(double value);

      /// @brief Returns the logarithm of a specified number in a specified base.
      /// @param a The number whose logarithm is to be found.
      /// @param newBase The base of the logarithm.
      /// @return One of the values in the following table. (+Infinity denotes PositiveInfinity, -Infinity denotes NegativeInfinity, and NaN denotes NaN.)
      /// [ a             | newBase                             | Return value    |
      /// |---------------|-------------------------------------| ----------------|
      /// | a > 0         | (0 < newBase < 1) -or-(newBase > 1) | log newBase (a) |
      /// | a < 0         | (any value)                         | NaN             |
      /// | (any value)   | newBase < 0                         | NaN             |
      /// | a != 1        | newBase = 0                         | NaN             |
      /// | a != 1        | newBase = +Infinity                 | NaN             |
      /// | a = NaN       | (any value)                         | NaN             |
      /// | (any value)   | newBase = NaN                       | NaN             |
      /// | (any value)   | newBase = 1                         | NaN             |
      /// | a = 0         | 0 < newBase < 1                     | +Infinity       |
      /// | a = 0         | newBase > 1                         | -Infinity       |
      /// | a = +Infinity | 0 < newBase < 1                     | -Infinity       |
      /// | a = +Infinity | newBase > 1                         | +Infinity       |
      /// | a = 1         | newBase = 0                         | 0               |
      /// | a = 1         | newBase = +Infinity                 | 0               |
      static double Log(double a, double newBase) {
        if (a < 0 || newBase < 0 || (a != 1 && newBase == 0) || (a != 1 && Double::IsPositiveInfinity(newBase)) || Double::IsNaN(a) || Double::IsNaN(newBase) || newBase == 1)
          return Double::NaN;
        if ((a == 0 && 0 < newBase && newBase < 1) || (Double::IsPositiveInfinity(a) && newBase > 1))
          return Double::PositiveInfinity;
        if ((a == 0 && newBase > 1) || (Double::IsPositiveInfinity(a) && 0 < newBase && newBase < 1))
          return Double::NegativeInfinity;
        return (Log(a) / Log(newBase));
      }

      /// @brief Returns the base 10 logarithm of a specified number.
      /// @param value A number whose logarithm is to be found.
      /// @return double One of the values in the following table.
      /// | value parameter           | Return value                                                  |
      /// |---------------------------|---------------------------------------------------------------|
      /// | Positive                  | The natural logarithm of d; that is, ln value, or log e value |
      /// | Zero                      | NegativeInfinity                                              |
      /// | Negative                  | NaN                                                           |
      /// | Equal to NaN              | NaN                                                           |
      /// | Equal to PositiveInfinity | PositiveInfinity                                              |
      /// @remarks Parameter value is specified as a base 10 number.
      static double Log10(double value);

      /// @brief Returns the larger of two 8-bit unsigned integers.
      /// @param a The first of two 8-bit unsigned integers to compare.
      /// @param b The second of two 8-bit unsigned integers to compare.
      /// @return Parameter a or b, whichever is larger.
      static byte Max(byte a, byte b) {return a > b ? a : b;}

      /// @brief Returns the larger of two double single.
      /// @param a The first of two double single to compare.
      /// @param b The second of two double single to compare.
      /// @return Parameter a or b, whichever is larger.
      static decimal Max(decimal a, decimal b) { return a > b ? a : b; }

      /// @brief Returns the larger of two double single.
      /// @param a The first of two double single to compare.
      /// @param b The second of two double single to compare.
      /// @return Parameter a or b, whichever is larger.
      static double Max(double a, double b) { return a > b ? a : b; }

      /// @brief Returns the larger of two 16-bit signed integers.
      /// @param a The first of two 16-bit signed integers to compare.
      /// @param b The second of two 16-bit signed integers to compare.
      /// @return Parameter a or b, whichever is larger.
      static int16 Max(int16 a, int16 b) {return a > b ? a : b;}

      /// @brief Returns the larger of two 32-bit signed integers.
      /// @param a The first of two 32-bit signed integers to compare.
      /// @param b The second of two 32-bit signed integers to compare.
      /// @return Parameter a or b, whichever is larger.
      static int32 Max(int32 a, int32 b) {return a > b ? a : b;}

      /// @brief Returns the larger of two 64-bit signed integers.
      /// @param a The first of two 64-bit signed integers to compare.
      /// @param b The second of two 64-bit signed integers to compare.
      /// @return Parameter a or b, whichever is larger.
      static int64 Max(int64 a, int64 b) {return a > b ? a : b;}

      /// @brief Returns the larger of two 8-bit signed integers.
      /// @param a The first of two 8-bit signed integers to compare.
      /// @param b The second of two 8-bit signed integers to compare.
      /// @return Parameter a or b, whichever is larger.
      static sbyte Max(sbyte a, sbyte b) {return a > b ? a : b;}

      /// @brief Returns the larger of two single single.
      /// @param a The first of two signle single to compare.
      /// @param b The second of two single single to compare.
      /// @return Parameter a or b, whichever is larger.
      static float Max(float a, float b) {return a > b ? a : b;}

      /// @brief Returns the larger of two 16-bit unsigned integers.
      /// @param a The first of two 16-bit unsigned integers to compare.
      /// @param b The second of two 16-bit unsigned integers to compare.
      /// @return Parameter a or b, whichever is larger.
      static uint16 Max(uint16 a, uint16 b) {return a > b ? a : b;}

      /// @brief Returns the larger of two 32-bit unsigned integers.
      /// @param a The first of two 32-bit unsigned integers to compare.
      /// @param b The second of two 32-bit unsigned integers to compare.
      /// @return Parameter a or b, whichever is larger.
      static uint32 Max(uint32 a, uint32 b) {return a > b ? a : b;}

      /// @brief Returns the larger of two 64-bit unsigned integers.
      /// @param a The first of two 64-bit unsigned integers to compare.
      /// @param b The second of two 64-bit unsigned integers to compare.
      /// @return Parameter a or b, whichever is larger.
      static uint64 Max(uint64 a, uint64 b) {return a > b ? a : b;}

      /// @brief Returns the smaller of two 8-bit unsigned integers.
      /// @param a The first of two 8-bit unsigned integers to compare.
      /// @param b The second of two 8-bit unsigned integers to compare.
      /// @return Parameter a or b, whichever is smaller.
      static byte Min(byte a, byte b) {return a < b ? a : b;}

      /// @brief Returns the smaller of two double single.
      /// @param a The first of two double single to compare.
      /// @param b The second of two double single to compare.
      /// @return Parameter a or b, whichever is smaller.
      static decimal Min(decimal a, decimal b) { return a < b ? a : b; }

      /// @brief Returns the smaller of two double single.
      /// @param a The first of two double single to compare.
      /// @param b The second of two double single to compare.
      /// @return Parameter a or b, whichever is smaller.
      static double Min(double a, double b) { return a < b ? a : b; }

      /// @brief Returns the smaller of two 16-bit signed integers.
      /// @param a The first of two 16-bit signed integers to compare.
      /// @param b The second of two 16-bit signed integers to compare.
      /// @return Parameter a or b, whichever is smaller.
      static int16 Min(int16 a, int16 b) {return a < b ? a : b;}

      /// @brief Returns the smaller of two 32-bit signed integers.
      /// @param a The first of two 32-bit signed integers to compare.
      /// @param b The second of two 32-bit signed integers to compare.
      /// @return Parameter a or b, whichever is smaller.
      static int32 Min(int32 a, int32 b) {return a < b ? a : b;}

      /// @brief Returns the smaller of two 64-bit signed integers.
      /// @param a The first of two 64-bit signed integers to compare.
      /// @param b The second of two 64-bit signed integers to compare.
      /// @return Parameter a or b, whichever is smaller.
      static int64 Min(int64 a, int64 b) {return a < b ? a : b;}

      /// @brief Returns the smaller of two 8-bit signed integers.
      /// @param a The first of two 8-bit signed integers to compare.
      /// @param b The second of two 8-bit signed integers to compare.
      /// @return Parameter a or b, whichever is smaller.
      static sbyte Min(sbyte a, sbyte b) {return a < b ? a : b;}

      /// @brief Returns the smaller of two single single.
      /// @param a The first of two signle single to compare.
      /// @param b The second of two single single to compare.
      /// @return Parameter a or b, whichever is smaller.
      static float Min(float a, float b) {return a < b ? a : b;}

      /// @brief Returns the smaller of two 16-bit unsigned integers.
      /// @param a The first of two 16-bit unsigned integers to compare.
      /// @param b The second of two 16-bit unsigned integers to compare.
      /// @return Parameter a or b, whichever is smaller.
      static uint16 Min(uint16 a, uint16 b) {return a < b ? a : b;}

      /// @brief Returns the smaller of two 32-bit unsigned integers.
      /// @param a The first of two 32-bit unsigned integers to compare.
      /// @param b The second of two 32-bit unsigned integers to compare.
      /// @return Parameter a or b, whichever is smaller.
      static uint32 Min(uint32 a, uint32 b) {return a < b ? a : b;}

      /// @brief Returns the smaller of two 64-bit unsigned integers.
      /// @param a The first of two 64-bit unsigned integers to compare.
      /// @param b The second of two 64-bit unsigned integers to compare.
      /// @return Parameter a or b, whichever is smaller.
      static uint64 Min(uint64 a, uint64 b) {return a < b ? a : b;}

      /// @brief Returns a specified number raised to the specified power.
      /// @param x A double-precision floating-point number to be raised to a power.
      /// @param y A double-precision floating-point number that specifies a power.
      /// @return double The number x raised to the power y.
      /// @remarks The following table indicates the return value when various values or ranges of values are specified for the x and y parameters. For more information, see Double::PositiveInfinity, Double::NegativeInfinity, and Double::NaN.
      /// | Parameters                                                                                  | Return value     |
      /// |---------------------------------------------------------------------------------------------|------------------|
      /// | x or y = NaN.                                                                               | NaN              |
      /// | x = Any value except NaN; y = 0.                                                            | 1                |
      /// | x = NegativeInfinity; y < 0.                                                                | 0                |
      /// | x = NegativeInfinity; y is positive odd integer.                                            | NegativeInfinity |
      /// | x = NegativeInfinity; y is positive but not an odd integer.                                 | PositiveInfinity |
      /// | x < 0 but not NegativeInfinity; y is not an integer, NegativeInfinity, or PositiveInfinity. | NaN              |
      /// | x = -1; y = NegativeInfinity or PositiveInfinity.                                           | NaN              |
      /// | -1 < x < 1; y = NegativeInfinity.                                                           | PositiveInfinity |
      /// | -1 < x < 1; y = PositiveInfinity.                                                           | 0                |
      /// | x < -1 or x > 1; y = NegativeInfinity.                                                      | 0                |
      /// | x < -1 or x > 1; y = PositiveInfinity.                                                      | PositiveInfinity |
      /// | x = 0; y < 0.                                                                               | PositiveInfinity |
      /// | x = 0; y > 0.                                                                               | 0                |
      /// | x = 1; y is any value except NaN.                                                           | 1                |
      /// | x = PositiveInfinity; y < 0                                                                 | 0                |
      /// | x = PositiveInfinity; y > 0.                                                                | Positiveinfinity |
      static double Pow(double x, double y);

      /// @brief Rounds a double-precision floating-point value to the nearest integral value.
      /// @param value A double-precision floating-point number to be rounded.
      /// @return double The integer nearest value. If the fractional component of a is halfway between two integers, one of which is even and the other odd, then the even number is returned. Note that this method returns a double instead of an integral type.
      static decimal Round(decimal value) { return Round(value, 0); }

      /// @brief Rounds a decimal value to a specified number of fractional digits.
      /// @param value A double-precision floating-point number to be rounded.
      /// @param decimals The number of decimal places in the return value.
      /// @return The number nearest to d that contains a number of fractional digits equal to decimals.
      static decimal Round(decimal value, int32 decimals) {
        decimal muliplicator = 1;
        for (int32 index = 0; index < decimals; index++)
          muliplicator *= 10;
        return Floor((value * muliplicator) + 0.5) / muliplicator;
      }

      /// @brief Rounds a double-precision floating-point value to the nearest integral value.
      /// @param value A double-precision floating-point number to be rounded.
      /// @return double The integer nearest value. If the fractional component of a is halfway between two integers, one of which is even and the other odd, then the even number is returned. Note that this method returns a double instead of an integral type.
      static double Round(double value) { return Round(value, 0); }

      /// @brief Rounds a decimal value to a specified number of fractional digits.
      /// @param value A double-precision floating-point number to be rounded.
      /// @param decimals The number of decimal places in the return value.
      /// @return The number nearest to d that contains a number of fractional digits equal to decimals.
      static double Round(double value, int32 decimals) {
        double muliplicator = 1;
        for (int32 index = 0; index < decimals; index++)
          muliplicator *= 10;
        return Floor((value * muliplicator) + 0.5) / muliplicator;
      }

      /// @brief Returns a value indicating the sign of a double-precision floating-point number.
      /// @param value A signed number.
      /// @return int32 A number that indicates the sign of value, as shown in the following table.
      /// | Return value | Meaning                     |
      /// |--------------|-----------------------------|
      /// | -1           | value is less than zero.    |
      /// | 0            | value is equal to zero.     |
      /// | 1            | value is greater than zero. |
      /// @exception ArithmeticException value is equal to NaN.
      static int32 Sign(decimal value) {
        if (Decimal::IsNaN(value))
          throw ArithmeticException(caller_);
        return value < 0 ? -1 : value == 0 ? 0 : 1;
      }

      /// @brief Returns a value indicating the sign of a double-precision floating-point number.
      /// @param value A signed number.
      /// @return int32 A number that indicates the sign of value, as shown in the following table.
      /// | Return value | Meaning                     |
      /// |--------------|-----------------------------|
      /// | -1           | value is less than zero.    |
      /// | 0            | value is equal to zero.     |
      /// | 1            | value is greater than zero. |
      /// @exception ArithmeticException value is equal to NaN.
      static int32 Sign(double value) {
        if (Double::IsNaN(value))
          throw ArithmeticException(caller_);
        return value < 0 ? -1 : value == 0 ? 0 : 1;
      }

      /// @brief Returns a value indicating the sign of a 16-bit signed integer.
      /// @param value A signed number.
      /// @return int32 A number that indicates the sign of value, as shown in the following table.
      /// | Return value | Meaning                     |
      /// |--------------|-----------------------------|
      /// | -1           | value is less than zero.    |
      /// | 0            | value is equal to zero.     |
      /// | 1            | value is greater than zero. |
      static int32 Sign(int16 value) {return value < 0 ? -1 : value == 0 ? 0 : 1;}

      /// @brief Returns a value indicating the sign of a 32-bit signed integer.
      /// @param value A signed number.
      /// @return int32 A number that indicates the sign of value, as shown in the following table.
      /// | Return value | Meaning                     |
      /// |--------------|-----------------------------|
      /// | -1           | value is less than zero.    |
      /// | 0            | value is equal to zero.     |
      /// | 1            | value is greater than zero. |
      static int32 Sign(int32 value) {return value < 0 ? -1 : value == 0 ? 0 : 1;}

      /// @brief Returns a value indicating the sign of a 64-bit signed integer.
      /// @param value A signed number.
      /// @return int32 A number that indicates the sign of value, as shown in the following table.
      /// | Return value | Meaning                     |
      /// |--------------|-----------------------------|
      /// | -1           | value is less than zero.    |
      /// | 0            | value is equal to zero.     |
      /// | 1            | value is greater than zero. |
      static int32 Sign(int64 value) {return value < 0 ? -1 : value == 0 ? 0 : 1;}

      /// @brief Returns a value indicating the sign of an 8-bit signed integer.
      /// @param value A signed number.
      /// @return int32 A number that indicates the sign of value, as shown in the following table.
      /// | Return value | Meaning                     |
      /// |--------------|-----------------------------|
      /// | -1           | value is less than zero.    |
      /// | 0            | value is equal to zero.     |
      /// | 1            | value is greater than zero. |
      static int32 Sign(sbyte value) {return value < 0 ? -1 : value == 0 ? 0 : 1;}

      /// @brief Returns a value indicating the sign of a single-precision floating-point number.
      /// @param value A signed number.
      /// @return int32 A number that indicates the sign of value, as shown in the following table.
      /// | Return value | Meaning                     |
      /// |--------------|-----------------------------|
      /// | -1           | value is less than zero.    |
      /// | 0            | value is equal to zero.     |
      /// | 1            | value is greater than zero. |
      /// @exception ArithmeticException value is equal to NaN.
      static int32 Sign(float value) {
        if (Single::IsNaN(value))
          throw ArithmeticException(caller_);
        return value < 0 ? -1 : value == 0 ? 0 : 1;
      }

      /// @brief Returns the sine of the specified angle.
      /// @param value An angle, measured in radians.
      /// @return double The sine of value. If value is equal to NaN, NegativeInfinity, or PositiveInfinity, this method returns NaN.
      static double Sin(double value);

      /// @brief Returns the hyperbolic sine of the specified angle.
      /// @param value An angle, measured in radians.
      /// @return double The sine of a. If a is equal to NaN, NegativeInfinity, or PositiveInfinity, this method returns NaN.
      static double Sinh(double value);

      /// @brief Returns the square root of a specified number.
      /// @param value The number whose square root is to be found.
      /// @return One of the values in the following table.
      /// | value parameter         | Return value                   |
      /// |-------------------------|--------------------------------|
      /// | Zero or positive        | The positive square root of d. |
      /// | Negative                | NaN                            |
      /// | Equals NaN              | NaN                            |
      /// | Equals PositiveInfinity | PositiveInfinity               |
      static double Sqrt(double value);

      /// @brief Returns the tangent of the specified angle.
      /// @param value An angle, measured in radians.
      /// @return The tangent of value. If value is equal to NaN, NegativeInfinity, or PositiveInfinity, this method returns NaN.
      static double Tan(double value);

      /// @brief Returns the hyperbolic tangent of the specified angle.
      /// @param value An angle, measured in radians.
      /// @return The hyperbolic tangent of value. If value is equal to NegativeInfinity, this method returns -1. If value is equal to PositiveInfinity, this method returns 1. If value is equal to NaN, this method returns NaN.
      static double Tanh(double value);

      /// @brief Calculates the integral part of a specified double-precision floating-point number.
      /// @param value A number to truncate.
      /// @return The integral part of d; that is, the number that remains after any fractional digits have been discarded, or one of the values listed in the following table.
      /// | value            | Return value     |
      /// |------------------|------------------|
      /// | NaN              | NaN              |
      /// | NegativeInfinity | NegativeInfinity |
      /// | PositiveInfinity | PositiveInfinity |
      static decimal Truncate(decimal value) { return (value > 0) ? Floor(value) : Ceiling(value); }

      /// @brief Calculates the integral part of a specified double-precision floating-point number.
      /// @param value A number to truncate.
      /// @return The integral part of d; that is, the number that remains after any fractional digits have been discarded, or one of the values listed in the following table.
      /// | value            | Return value     |
      /// |------------------|------------------|
      /// | NaN              | NaN              |
      /// | NegativeInfinity | NegativeInfinity |
      /// | PositiveInfinity | PositiveInfinity |
      static double Truncate(double value) { return (value > 0) ? Floor(value) : Ceiling(value); }
    };
  }
}

using namespace Switch;

/// @cond
inline float operator%(const System::Single& a, const System::Single& b) {return std::fmod(a, b);}
inline double operator%(const System::Double& a, const System::Double& b) {return std::fmod(a, b);}
/// @endcond

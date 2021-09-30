#include <cmath>
#include <cstdio>

#include "../../../include/Switch/System/Math.hpp"

using namespace System;

constexpr double Math::E;

constexpr double Math::PI;

double Math::Acos(double value) {
  return acos(value);
}

double Math::Asin(double value) {
  return asin(value);
}

double Math::Atan(double value) {
  return atan(value);
}

double Math::Atan2(double y, double x) {
  return Double::IsInfinity(y) && Double::IsInfinity(x) ? Double::NaN : atan2(y, x);
}

decimal Math::Ceiling(decimal value) {
  return ceil(value);
}

double Math::Ceiling(double value) {
  return ceil(value);
}

double Math::Cos(double value) {
  return cos(value);
}

double Math::Cosh(double value) {
  return cosh(value);
}

double Math::Exp(double value) {
  return exp(value);
}

decimal Math::Floor(decimal value) {
  return floor(value);
}

double Math::Floor(double value) {
  return floor(value);
}

double Math::Log(double value) {
  return log(value);
}

double Math::Log10(double value) {
  return log10(value);
}

double Math::Pow(double x, double y) {
  return pow(x, y);
}

double Math::Sin(double value) {
  return sin(value);
}

double Math::Sinh(double value) {
  return sinh(value);
}

double Math::Sqrt(double value) {
  return sqrt(value);
}

double Math::Tan(double value) {
  return tan(value);
}

double Math::Tanh(double value) {
  return tanh(value);
}

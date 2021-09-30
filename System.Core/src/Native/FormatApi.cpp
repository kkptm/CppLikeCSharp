#include "Api.hpp"

const string& Native::FormatApi::Integer() {
  #if defined(__GNUC__)
  static string format = "%ld";
  #else
  static string format = "%lld";
  #endif
  return format;
}

const string& Native::FormatApi::IntegerWithPrecision() {
  #if defined(__GNUC__)
  static string format = "%0*ld";
  #else
  static string format = "%0*lld";
  #endif
  return format;
}

const string& Native::FormatApi::UnsignedInteger() {
  #if defined(__GNUC__)
  static string format = "%lu";
  #else
  static string format = "%llu";
  #endif
  return format;
}

const string& Native::FormatApi::UnsignedIntegerWithPrecision() {
  #if defined(__GNUC__)
  static string format = "%0*lu";
  #else
  static string format = "%0*llu";
  #endif
  return format;
}

const string& Native::FormatApi::HexadecimalWithPrecision() {
  #if defined(__GNUC__)
  static string format = "%0*lX";
  #else
  static string format = "%0*llX";
  #endif
  return format;
}

const string& Native::FormatApi::LowerHexadecimalWithPrecision() {
  #if defined(__GNUC__)
  static string format = "%0*lx";
  #else
  static string format = "%0*llx";
  #endif
  return format;
}

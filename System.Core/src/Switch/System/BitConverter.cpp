#include "../../../include/Switch/System/BitConverter.hpp"

namespace {
  bool IsLittleEndian() {
    const int32 endian = 1;
    return *(sbyte*)&endian == 1;
  }
}

using namespace System;

const bool BitConverter::IsLittleEndian = ::IsLittleEndian();

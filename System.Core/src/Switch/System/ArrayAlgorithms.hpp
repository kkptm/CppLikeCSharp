#pragma once

#include "../../../include/Switch/Types.hpp"
#include "../../../include/Switch/System/SystemException.hpp"

namespace {
  class ArrayAlgorithms {
  public:
    ArrayAlgorithms() = delete;
    inline static bool IsValidRange(int32 arraySize, int32 index, int count) {
      return ((index + count <= arraySize) || (arraySize == 0 && index == 1 && count == 0)) && index >= 0 && count >= 0;
    }

    template<typename T>
    inline static bool Contains(const T array[], int32 size, const T& item) {
      for (int32 index = 0; index < size; index++)
        if (array[index] == item)
          return true;
      return false;
    }

    static inline void ValidateArray(const void* array, int32 size) {
      if (size < 0)
        throw System::ArgumentException(caller_);
      if (array == null && size > 0)
        throw System::ArgumentNullException(caller_);
    }

    static inline void ValidateIndex(int32 index, int32 size) {
      if (index < 0 || index > size)
        throw System::ArgumentOutOfRangeException(caller_);
    }

    static inline void ValidateRange(int32 size, int32 index, int32 count) {
      if (! IsValidRange(size, index, count))
        throw System::ArgumentOutOfRangeException(caller_);
    }
  };
}

using namespace Switch;

#include <cstdarg>
#include <cstdlib>
#include <ctime>

#include "../../../include/Switch/System/Random.hpp"
#include "../../../include/Switch/System/Math.hpp"

using namespace System;

Random::Random() {
  srand((uint32_t)time(null));
}

Random::Random(int32 seed) {
  srand(Math::Abs(seed));
}

int32 Random::Next(int32 minValue, int32 maxValue) const {
  if (minValue > maxValue)
    throw ArgumentOutOfRangeException(caller_);

  if (maxValue == minValue)
    return minValue;

  return minValue + Convert::ToInt32(Sample() * RAND_MAX) % ((maxValue - 1) - minValue + 1);
}

double Random::Sample() const {
  return Convert::ToDouble(rand()) / RAND_MAX;
}

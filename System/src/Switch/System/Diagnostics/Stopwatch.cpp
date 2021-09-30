#include <chrono>
#include "../../../../include/Switch/System/Diagnostics/Stopwatch.hpp"

using namespace System::Diagnostics;

property_<int64, readonly_> Stopwatch::Frequency {
  [] {return 10000000;}
};

property_<bool, readonly_> Stopwatch::IsHighResolution {
  [] {return true;}
};

int64 Stopwatch::GetTimestamp() {
  return std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 100;
}

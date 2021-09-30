#include "../../../../include/Switch/System/Threading/Timeout.hpp"

using namespace System;
using namespace System::Threading;

constexpr int32 Timeout::Infinite;
const TimeSpan Timeout::InfiniteTimeSpan = TimeSpan::FromMilliseconds(-1);

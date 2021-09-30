#include "../../../../include/Switch/System/Threading/WaitHandle.hpp"
#include "../../../../include/Switch/System/Threading/Thread.hpp"
#include "../../../../include/Switch/System/Array.hpp"
#include "../../../../include/Switch/System/Boolean.hpp"
#include "../../../../include/Switch/System/DateTime.hpp"

using namespace System;
using namespace System::Threading;

bool WaitHandle::WaitAll(Array<ref<WaitHandle>> waitHandles) {
  return WaitAll(waitHandles, Timeout::Infinite);
}

bool WaitHandle::WaitAll(Array<ref<WaitHandle>> waitHandles, int32 millisecondsTimeout) {
  if (millisecondsTimeout < Timeout::Infinite)
    throw ArgumentException(caller_);

  if (millisecondsTimeout == Timeout::Infinite) {
    for (auto& item : waitHandles)
      item().WaitOne();
    return true;
  }

  int32 timeout = millisecondsTimeout;
  int64 start = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000;
  for (auto& item : waitHandles) {
    if (item().WaitOne(timeout) == false)
      return false;
    timeout = millisecondsTimeout - (int32)(std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000 - start);
    if (timeout < 0)
      return false;
  }
  return true;
}

bool WaitHandle::WaitAll(Array<ref<WaitHandle>> waitHandles, const TimeSpan& timeOut) {
  return WaitAll(waitHandles, Convert::ToInt32(timeOut.TotalMilliseconds()));
}

int32 WaitHandle::WaitAny(Array<ref<WaitHandle>> waitHandles) {
  return WaitAny(waitHandles, Timeout::Infinite);
}

int32 WaitHandle::WaitAny(Array<ref<WaitHandle>> waitHandles, int32 millisecondsTimeout) {
  if (millisecondsTimeout < Timeout::Infinite)
    throw ArgumentException(caller_);

  if (millisecondsTimeout == Timeout::Infinite) {
    for (int32 index = 0; index < waitHandles.Count; index++) {
      if (waitHandles[index]().WaitOne(0) == true)
        return index;
      Thread::Yield();
      Thread::Sleep(1);
    }
    return WaitTimeout;
  }

  int32 timeout = millisecondsTimeout;
  int64 start = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000;
  do {
    for (int32 index = 0; index < waitHandles.Count; index++) {
      if (waitHandles[index]().WaitOne(0) == true)
        return index;
      timeout = millisecondsTimeout - (int32)(std::chrono::nanoseconds(std::chrono::high_resolution_clock::now().time_since_epoch()).count() / 1000000 - start);
      if (timeout < 0)
        return WaitTimeout;
      Thread::Yield();
      Thread::Sleep(1);
    }
  } while (timeout >= 0);
  return WaitTimeout;
}

int32 WaitHandle::WaitAny(Array<ref<WaitHandle>> waitHandles, const TimeSpan& timeOut) {
  return WaitAny(waitHandles, Convert::ToInt32(timeOut.TotalMilliseconds()));
}

bool WaitHandle::DoWait(int32 millisecondsTimeOut) {
  return Thread::DoWait(*this, millisecondsTimeOut);
}


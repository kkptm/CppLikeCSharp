#include "../../../../include/Switch/System/Array.hpp"
#include "../../../../include/Switch/System/Threading/Monitor.hpp"
#include "../../../../include/Switch/System/Threading/Mutex.hpp"
#include "../../../../include/Switch/System/Threading/SynchronizationLockException.hpp"
#include "../../../../include/Switch/System/Threading/Timeout.hpp"

namespace {
  std::recursive_mutex mutex;
}

using namespace System;
using namespace System::Threading;

void Monitor::Pulse(const Object& obj) {
  MonitorItem* monitorItem = null;
  mutex.lock();
  if (IsEntered(obj))
    monitorItem = &MonitorItems()[ToKey(obj)];
  mutex.unlock();

  if (monitorItem == null)
    throw InvalidOperationException(caller_);

  monitorItem->event.ReleaseMutex();
}

void Monitor::PulseAll(const Object& obj) {
  MonitorItem* monitorItem = null;
  mutex.lock();
  if (IsEntered(obj))
    monitorItem = &MonitorItems()[ToKey(obj)];
  mutex.unlock();

  if (monitorItem == null)
    throw InvalidOperationException(caller_);

  monitorItem->event.ReleaseMutex();
}

bool Monitor::Wait(const Object& obj, int32 millisecondsTimeout) {
  MonitorItem* monitorItem = null;
  mutex.lock();
  if (IsEntered(obj))
    monitorItem = &MonitorItems()[ToKey(obj)];
  mutex.unlock();

  if (monitorItem == null)
    throw InvalidOperationException(caller_);

  return monitorItem->event.WaitOne(millisecondsTimeout);
}

bool Monitor::Add(const Object& obj, int32 millisecondsTimeout) {
  mutex.lock();
  if (!IsEntered(obj))
    MonitorItems()[ToKey(obj)] = is<string>(obj) ? MonitorItem((const string&)obj) : MonitorItem();
  MonitorItem& monitorData = MonitorItems()[ToKey(obj)];
  monitorData.usedCounter++;
  mutex.unlock();
  return monitorData.event.WaitOne(millisecondsTimeout);
}

void Monitor::Remove(const Object& obj) {
  MonitorItem saved;
  mutex.lock();
  if (!IsEntered(obj)) {
    mutex.unlock();
    throw SynchronizationLockException(caller_);
  }

  MonitorItem* monitorData = &MonitorItems()[ToKey(obj)];
  if (--monitorData->usedCounter == 0) {
    saved = MonitorItems()[ToKey(obj)];
    MonitorItems().Remove(ToKey(obj));
    monitorData = &saved;
  }
  mutex.unlock();
  monitorData->event.ReleaseMutex();
}

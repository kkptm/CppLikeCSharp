
#include "../../../../../include/Switch/System/Threading/Tasks/Task.hpp"

using namespace System;
using namespace System::Threading::Tasks;

thread_local int32 __opaque_task_id_generator__::currentId = 0;

Nullable<int32> Task<void>::CurrentId() {
  if (__opaque_task_id_generator__::currentId == 0)
    return Nullable<int32>();
  return Nullable<int32>(__opaque_task_id_generator__::currentId);
}

TaskFactory& Task<void>::Factory() {
  static TaskFactory taskFactory;
  return taskFactory;
}



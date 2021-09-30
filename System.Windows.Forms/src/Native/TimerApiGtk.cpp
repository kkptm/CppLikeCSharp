#if defined(__linux__)
#include <gtkmm.h>

#include "Api.hpp"

using namespace System;
using namespace System::Windows::Forms;

namespace {
  struct TimerGtk {
    guint timer = 0;
    delegate<void> tick;
  };

  int TimerPeroc(gpointer timer) {
    ((TimerGtk*)timer)->tick();
    return 1;
  }
}

intptr Native::TimerApi::Create(int32 interval, delegate<void> tick) {
  TimerGtk* handle = new TimerGtk();
  handle->timer = g_timeout_add(interval, TimerPeroc, (gpointer)handle);
  handle->tick = tick;
  return (intptr)handle;
}

void Native::TimerApi::Destroy(intptr handle) {
  g_source_remove(((TimerGtk*)handle)->timer);
}

#endif

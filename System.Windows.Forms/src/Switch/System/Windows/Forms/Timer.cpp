#include "../../../../../include/Switch/System/Windows/Forms/Timer.hpp"
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Windows::Forms;

void Timer::SetEnabled(bool enabled) {
  if (this->enabled != enabled) {
    this->enabled = enabled;
    if (this->enabled)
      this->handle = Native::TimerApi::Create(this->interval, this->tick);
    else
      Native::TimerApi::Destroy(this->handle);
  }
}

void Timer::SetInterval(int32 interval) {
  if (interval < 1)
    throw ArgumentOutOfRangeException(caller_);

  if (this->interval != interval) {
    this->interval = interval;
    if (this->enabled) {
      Native::TimerApi::Destroy(this->handle);
      this->handle = Native::TimerApi::Create(this->interval, this->tick);
    }
  }
}

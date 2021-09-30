#if defined(_WIN32)
#include <windows.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"

using namespace System;

void Native::SystemSoundApi::Play(SoundType type) {
  ::MessageBeep((uint32)type);
}

#endif

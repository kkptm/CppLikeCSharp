#include "../../../../include/Switch/System/Media/SystemSounds.hpp"
#include "../../../Native/Api.hpp"

using namespace System::Media;

struct __opaque_sound_access__ {
  SystemSound operator()(Native::SoundType sounds) {
    return SystemSound((int)sounds);
  }
};

property_<SystemSound, readonly_> SystemSounds::Asterisk {
  [] {return __opaque_sound_access__()(Native::SoundType::Asterisk);}
};

property_<SystemSound, readonly_> SystemSounds::Beep {
  [] {return __opaque_sound_access__()(Native::SoundType::Beep);}
};

property_<SystemSound, readonly_> SystemSounds::Exclamation {
  [] {return __opaque_sound_access__()(Native::SoundType::Exclamation);}
};

property_<SystemSound, readonly_> SystemSounds::Hand {
  [] {return __opaque_sound_access__()(Native::SoundType::Hand);}
};

property_<SystemSound, readonly_> SystemSounds::Question {
  [] {return __opaque_sound_access__()(Native::SoundType::Question);}
};

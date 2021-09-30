#if defined(__APPLE__)
#include "TargetConditionals.h"

#if TARGET_OS_IPHONE == 0
#import <Cocoa/Cocoa.h>
#include "Api.hpp"

void Native::SystemSoundApi::Play(SoundType type) {
  @autoreleasepool {
    System::Collections::Generic::Dictionary<SoundType, string> sounds = {{SoundType::Beep, "Funk"}, {SoundType::Hand, "Sosumi"}, {SoundType::Question, "Purr"}, {SoundType::Exclamation, "Hero"}, {SoundType::Asterisk, "Glass"}, {(SoundType)0xFFFFFFFF, "Funk"}};
    [[NSSound soundNamed:[NSString stringWithUTF8String:sounds[type].c_str()]] play];
  }
}
#else
#include "Api.hpp"

void Native::SystemSoundApi::Play(SoundType type) {
}
#endif

#endif

#if defined(__APPLE__)
#include "WindowProcedureApiCocoa.hpp"
#include "Api.hpp"

#undef property

using namespace System;
using namespace System::Windows::Forms;

namespace{
  static System::Collections::Generic::Dictionary<intptr, delegate<void>> ticks;
}

@interface TimerCocoa : NSObject
@property (strong) NSTimer* timer;

- (void) TimerProc:(NSTimer*)timer;

@end

@implementation TimerCocoa
- (void) TimerProc:(NSTimer*)timer {
  ticks[(intptr)[timer userInfo]]();
}
@end

intptr Native::TimerApi::Create(int32 interval, delegate<void> tick) {
  TimerCocoa* handle = [[[TimerCocoa alloc] init] autorelease];
  ticks[(intptr)handle] = tick;
  handle.timer = [NSTimer timerWithTimeInterval:(double)interval/1000 target:handle selector:@selector(TimerProc:) userInfo:handle repeats:YES];
  NSRunLoop* runLoop = [NSRunLoop currentRunLoop];
  [runLoop addTimer:handle.timer forMode:NSDefaultRunLoopMode];
  return (intptr)handle;
}

void Native::TimerApi::Destroy(intptr handle) {
  [[(TimerCocoa*)handle timer] invalidate];
  ticks.Remove(handle);
}

#endif

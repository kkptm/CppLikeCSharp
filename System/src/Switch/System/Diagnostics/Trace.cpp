#include "../../../../include/Switch/System/Diagnostics/Trace.hpp"

using namespace System;
using namespace System::Diagnostics;

namespace {
  bool autoFlush = false;
  int32 indentLevel = 0;
  int32 indentSize = 4;
  bool useGlobalLock = true;
}

TraceListenerCollection Trace::listeners  {DefaultTraceListener()};
#if defined(_WIN32)
#pragma warning(push)
#pragma warning(disable:4592)
#endif
object Trace::lock;
#if defined(_WIN32)
#pragma warning(pop)
#endif

property_<bool> Trace::AutoFlush {
  [] {return autoFlush;},
  [](bool value) {autoFlush = value;}
};

property_<int32> Trace::IndentLevel {
  [] {return indentLevel;},
  [](int32 value) {
    indentLevel = value;
    for (auto& listener : __get_listeners__())
      listener.IndentLevel = indentLevel;
  }
};

property_<int32> Trace::IndentSize {
  [] {return indentSize;},
  [](int32 value) {
    indentSize = value;
    for (auto& listener : __get_listeners__())
      listener.IndentSize = indentSize;
  }
};

property_<TraceListenerCollection&, readonly_> Trace::Listeners {
  []()->TraceListenerCollection& {return __get_listeners__();}
};

property_<bool> Trace::UseGlobalLock {
  [] {return useGlobalLock;},
  [](bool value) {useGlobalLock = value;}
};

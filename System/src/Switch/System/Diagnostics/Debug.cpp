#include "../../../../include/Switch/System/Diagnostics/Debug.hpp"

using namespace System;
using namespace System::Diagnostics;

namespace {
  static bool autoFlush = false;
  static int32 indentLevel = 0;
  static int32 indentSize = 4;
  static bool useGlobalLock = true;
}

property_<bool> Debug::AutoFlush {
  [] {return autoFlush;},
  [](bool value) {autoFlush = value;}
};

property_<int32> Debug::IndentLevel {
  [] {return indentLevel;},
  [](int32 value) {
    indentLevel = value;
    for (auto& listener : Trace::__get_listeners__())
      listener.IndentLevel = indentLevel;
  }
};

property_<int32> Debug::IndentSize {
  [] {return indentSize;},
  [](int32 value) {
    indentSize = value;
    for (auto& listener : Trace::__get_listeners__())
      listener.IndentSize = indentSize;
  }
};

property_<TraceListenerCollection&, readonly_> Debug::Listeners {
  []()->TraceListenerCollection& {return Trace::__get_listeners__();}
};

property_<bool> Debug::UseGlobalLock {
  [] {return useGlobalLock;},
  [](bool value) {useGlobalLock = value;}
};

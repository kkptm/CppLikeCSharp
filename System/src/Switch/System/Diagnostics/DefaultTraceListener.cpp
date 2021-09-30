#include "../../../../include/Switch/System/Diagnostics/DefaultTraceListener.hpp"
#include "../../../Native/Api.hpp"

using namespace System::Diagnostics;

void DefaultTraceListener::WriteToOutputDebug(const string& message) {
  Native::DebuggerApi::Log(0, "", message);
}


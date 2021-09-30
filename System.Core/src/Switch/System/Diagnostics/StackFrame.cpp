#include "../../../../include/Switch/System/Diagnostics/StackFrame.hpp"
#include "../../../../include/Switch/System/SystemException.hpp"
#include <call_stack/call_stack.hpp>

using namespace System;
using namespace System::Diagnostics;

void StackFrame::FillFrame(int32 skipFrames, bool needFileInfo) {
  if (skipFrames < 0)
    throw ArgumentOutOfRangeException(caller_);

  stacktrace::call_stack st;
  FillFrame(&st, skipFrames, needFileInfo);
}

void StackFrame::FillFrame(void* callStack, int32 skipFrames, bool needFileInfo) {
  if (skipFrames < 0)
    throw ArgumentOutOfRangeException(caller_);

  if (skipFrames < GetFrameCount(callStack)) {
    if (needFileInfo) {
      this->fileName = reinterpret_cast<stacktrace::call_stack*>(callStack)->stack[skipFrames + StackFrameInternalMethodsToSkip].file.c_str();
      this->fileLineNumber = static_cast<int32>(reinterpret_cast<stacktrace::call_stack*>(callStack)->stack[skipFrames + StackFrameInternalMethodsToSkip].line);
      this->offset = static_cast<int32>(reinterpret_cast<stacktrace::call_stack*>(callStack)->stack[skipFrames + StackFrameInternalMethodsToSkip].offset);
      this->fileColumnNumber = static_cast<int32>(reinterpret_cast<stacktrace::call_stack*>(callStack)->stack[skipFrames + StackFrameInternalMethodsToSkip].column);
    }
    this->method = reinterpret_cast<stacktrace::call_stack*>(callStack)->stack[skipFrames + StackFrameInternalMethodsToSkip].function.c_str();
  }
}

int32 StackFrame::GetFrameCount(void* callStack) {
  if (static_cast<int32>(reinterpret_cast<stacktrace::call_stack*>(callStack)->stack.size()) - StackFrameInternalMethodsToSkip > 0)
    return static_cast<int32>(reinterpret_cast<stacktrace::call_stack*>(callStack)->stack.size()) - StackFrameInternalMethodsToSkip;
  else
    return 0;
}

String StackFrame::ToString() const {
  return String::Format("{0} at {1}  in file:line:column {2} : {3} : {4}", (String::IsNullOrEmpty(this->method) ? String("<unknown method>") : this->method), (String::IsNullOrEmpty(this->fileName) ? String("<unknown offset>") : Int32(this->offset).ToString()), (String::IsNullOrEmpty(this->fileName) ? String("<filename unknown>") : this->fileName), this->fileLineNumber, this->fileColumnNumber);
}


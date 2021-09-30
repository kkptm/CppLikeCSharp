/// @file
/// @brief Contains Switch::System::Diagnostics::StackFrame class.
#pragma once

#include "../../Types.hpp"
#include "../Object.hpp"
#include "../String.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @cond
      class StackTrace;
      /// @endcond

      /// @brief Provides information about a StackFrame, which represents a function call on the call stack for the current thread.
      class core_export_ StackFrame : public Object {
        /// @cond
        friend class StackTrace;
        /// @endcond

      private:
        /// @brief Initializes a new instance of the StackFrame class.
        /// @param skipFrames The number of frames up the stack from which to start the trace.
        /// @exception ArgumentOutOfRangeException The skipFrames parameter is negative.
        StackFrame(void* callStack, int32 skipFrames, bool needFileInfo) : fileColumnNumber(0), fileLineNumber(0), offset(0) {FillFrame(callStack, skipFrames, needFileInfo);}

      public:
        /// @brief Initializes a new instance of the StackFrame class.
        StackFrame() : fileColumnNumber(0), fileLineNumber(0), offset(0) {FillFrame(0, false);}

        /// @brief Initializes a new instance of the StackFrame class, optionally capturing source information.
        /// @param needFileInfo true to capture the file name, line number, and column number of the stack frame; otherwise, false.
        StackFrame(bool needFileInfo) : fileColumnNumber(0), fileLineNumber(0), offset(0) {FillFrame(0, needFileInfo);}

        /// @brief nitializes a new instance of the StackFrame class that corresponds to a frame above the current stack frame.
        /// @param skipFrames The number of frames up the stack from which to start the trace.
        /// @exception ArgumentOutOfRangeException The skipFrames parameter is negative.
        StackFrame(int32 skipFrames) : fileColumnNumber(0), fileLineNumber(0), offset(0) {FillFrame(skipFrames, false);}

        /// @brief Initializes a new instance of the StackFrame class that corresponds to a frame above the current stack frame, optionally capturing source information.
        /// @param skipFrames The number of frames up the stack from which to start the trace.
        /// @param skipFrames The number of frames up the stack from which to start the trace.
        /// @exception ArgumentOutOfRangeException The skipFrames parameter is negative.
        StackFrame(int32 skipFrames, bool needFileInfo) : fileColumnNumber(0), fileLineNumber(0), offset(0) {FillFrame(skipFrames, needFileInfo);}

        /// @brief Gets the column number in the file that contains the code that is executing. This information is typically extracted from the debugging symbols for the executable.
        int32 GetFileColumnNumber() const {return this->fileColumnNumber;}

        /// @brief Gets the line number in the file that contains the code that is executing. This information is typically extracted from the debugging symbols for the executable.
        int32 GetFileLineNumber() const {return this->fileLineNumber;}

        /// @brief Gets the file name that contains the code that is executing. This information is typically extracted from the debugging symbols for the executable.
        const String& GetFileName() const {return this->fileName;}

        /// @brief Gets the method in which the frame is executing.
        const String& GetMethod() const {return this->method;}

        /// @brief Gets the offset from the start of the compiled code for the method that is being executed
        int32 GetOffset() const {return this->offset;}

        virtual String ToString() const;

        /// @brief Defines the default for the number of methods to omit from the stack trace. This field is constant.
        static constexpr int32 METHODS_TO_SKIP = 0;

      private:
        /// @brief Gets the number of frames in the stack trace.
        static int32 GetFrameCount(void* callStack);
        /// @cond
        void FillFrame(int32 skipFrames, bool needFileInfo);
        void FillFrame(void* callStack, int32 skipFrames, bool needFileInfo);
        String fileName;
        int32 fileColumnNumber;
        int32 fileLineNumber;
        String method;
        int32 offset;
        /// @endcond
      };
    }
  }
}

using namespace Switch;

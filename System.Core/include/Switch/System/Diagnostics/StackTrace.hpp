/// @file
/// @brief Contains Switch::System::Diagnostics::StackTrace class.
#pragma once

#include "../../Types.hpp"
#include "../Exception.hpp"
#include "../Object.hpp"
#include "../String.hpp"
#include "../Collections/Generic/List.hpp"
#include "StackFrame.hpp"

/// @cond
namespace stacktrace {
  class call_stack;
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Provides information about a StackFrame, which represents a function call on the call stack for the current thread.
      /// @remarks StackTrace information will be most informative with Debug build configurations. By default, Debug builds include debug symbols, while Release builds do not. The debug symbols contain most of the file, method name, line number, and column information used in constructing StackFrame and StackTrace objects.
      /// @remarks StackTrace might not report as many method calls as expected, due to code transformations that occur during optimization.
      class core_export_ StackTrace : public Object {
      private:
        friend class System::Exception;

        /// @brief Initializes a new instance of the StackTrace class using the provided exception object, skipping the specified number of frames and optionally capturing source information.
        /// @param str The string from which to construct the stack trace.
        /// @param skipFrames The number of frames up the stack from which to start the trace.
        /// @param needFileInfo true to capture the file name, line number, and column number; otherwise, false.
        /// @remarks The StackTrace is created with the caller's current thread.
        StackTrace(const String& str, int32 skipFrames, bool needFileInfo) {
          FillFrames(str, skipFrames, needFileInfo);
        }

      public:
        /// @brief Initializes a new instance of the StackTrace class from the caller's frame.
        /// @remarks The StackTrace is created with the caller's current thread, and does not contain file name, line number, or column information.
        /// @remarks Use this default constructor when you want a complete trace with only summary method information about the call stack.
        StackTrace() {
          FillFrames(0, false);
        }

        /// @brief Initializes a new instance of the StackTrace class from the caller's frame, optionally capturing source information.
        /// @param needFileInfo true to capture the file name, line number, and column number; otherwise, false.
        /// @remarks The StackTrace is created with the caller's current thread.
        StackTrace(bool needFileInfo) {
          FillFrames(0, needFileInfo);
        }
        /// @brief Initializes a new instance of the StackTrace class using the provided exception object.
        /// @param exception The exception object from which to construct the stack trace.
        /// @remarks The StackTrace is created with the caller's current thread.
        StackTrace(const System::Exception& exception) {
          FillFrames(exception.GetType().ToString(), 0, false);
        }
        /// @brief Initializes a new instance of the StackTrace class, using the provided exception object and optionally capturing source information.
        /// @param exception The exception object from which to construct the stack trace.
        /// @param needFileInfo true to capture the file name, line number, and column number; otherwise, false.
        /// @remarks The StackTrace is created with the caller's current thread.
        StackTrace(const System::Exception& exception, bool needFileInfo) {
          FillFrames(exception.GetType().ToString(), 0, needFileInfo);
        }

        /// @brief Initializes a new instance of the StackTrace class using the provided exception object and skipping the specified number of frames.
        /// @param exception The exception object from which to construct the stack trace.
        /// @param skipFrames The number of frames up the stack from which to start the trace.
        /// @remarks The StackTrace is created with the caller's current thread.
        StackTrace(const System::Exception& exception, int32 skipFrames) {
          FillFrames(exception.GetType().ToString(), skipFrames, false);
        }

        /// @brief Initializes a new instance of the StackTrace class using the provided exception object, skipping the specified number of frames and optionally capturing source information.
        /// @param exception The exception object from which to construct the stack trace.
        /// @param skipFrames The number of frames up the stack from which to start the trace.
        /// @param needFileInfo true to capture the file name, line number, and column number; otherwise, false.
        /// @remarks The StackTrace is created with the caller's current thread.
        StackTrace(const System::Exception& exception, int32 skipFrames, bool needFileInfo) {
          FillFrames(exception.GetType().ToString(), skipFrames, needFileInfo);
        }

        /// @brief Initializes a new instance of the StackTrace class from the caller's frame, skipping the specified number of frames.
        /// @param skipFrames The number of frames up the stack from which to start the trace.
        /// @exception ArgumentOutOfRangeException The skipFrames parameter is negative.
        /// @remarks The StackTrace is created with the caller's current thread, and does not contain file name, line number, or column information.
        /// @remarks If the number of frames to skip is greater than or equal to the total number of frames on the call stack at the time the instance is created, the StackTrace will contain no frames.
        StackTrace(int32 skipFrames) {
          FillFrames(skipFrames, false);
        }

        /// @brief Initializes a new instance of the StackTrace class from the caller's frame, skipping the specified number of frames and optionally capturing source information.
        /// @param skipFrames The number of frames up the stack from which to start the trace.
        /// @param needFileInfo true to capture the file name, line number, and column number; otherwise, false.
        /// @exception ArgumentOutOfRangeException The skipFrames parameter is negative.
        /// @remarks If the number of frames to skip is greater than or equal to the total number of frames on the call stack at the time the instance is created, the StackTrace will contain no frames.
        StackTrace(int32 skipFrames, bool needFileInfo) {
          FillFrames(skipFrames, needFileInfo);
        }

        /// @brief Gets the number of frames in the stack trace.
        int32 FrameCount() const;

        /// @brief Gets the number of frames in the stack trace.
        /// @deprecated Replaced by System::Diagnostics::StackTrace::FrameCount()
        [[deprecated("Replaced by System::Diagnostics::StackTrace::FrameCount()")]]
        int32 GetFrameCount() const {return FrameCount();}

        /// @brief Gets the specified stack frame.
        /// @param index The index of the stack frame requested.
        /// @return The specified stack frame.
        /// @remarks Stack frames are numbered starting at 0, which is the last stack frame pushed.
        StackFrame GetFrame(int32 index) {
          if (index >= 0 && index < this->frames.Count)
            return StackFrame(*this->frames[index]);

          return StackFrame();
        }

        /// @brief Returns a copy of all stack frames in the current stack trace.
        /// @return An array of type StackFrame representing the function calls in the stack trace.
        /// @remarks Use the returned StackFrame array to enumerate and examine function calls in the StackTrace. The length of the returned array is equal to the FrameCount property value.
        /// @remarks The StackFrame array elements are in reverse chronological order. The StackFrame at array index 0 represents the most recent function call in the stack trace and the last frame pushed onto the call stack. The StackFrame at array index FrameCount minus 1 represents the oldest function call in the stack trace and the first frame pushed onto the call stack.
        /// @remarks Use the GetFrames method to obtain all stack frames in a stack trace; use the GetFrame method to obtain a specific stack frame in a stack trace. The StackFrame indexes are ordered alike by the two methods. For example, the StackFrame at index 0 in the array returned by GetFrames is equivalent to the StackFrame returned by GetFrame with an input index of 0.
        System::Array<refptr<StackFrame>> GetFrames() {
          return this->frames.ToArray();
        }

        /// @brief Builds a readable representation of the stack trace.
        /// @return A readable representation of the stack trace.
        virtual String ToString() const;

      private:
        void FillFrames(int32 skipFrames, bool needFileInfo);
        void FillFrames(const String& str, int32 skipFrames, bool needFileInfo);
        void FillFrames(void* callStack, int32 skipFrames, bool needFileInfo);

        struct CallStack {
          CallStack();
          ~CallStack();
          intptr handle;
        };

        refptr<CallStack> stackTrace;
        System::Collections::Generic::List<refptr<StackFrame>> frames;
      };
    }
  }
}

using namespace Switch;

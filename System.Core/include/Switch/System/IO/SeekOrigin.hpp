/// @file
/// @brief Contains Switch::System::IO::SeekOrigin enum.
#pragma once

#include "../Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Enumeration.
      /// Provides the fields that represent reference points in streams for seeking.
      /// @see Stream
      enum class SeekOrigin {
        /// @brief Specifies the beginning of a stream.
        Begin,
        /// @brief Specifies the current position within a stream.
        Current,
        /// @brief Specifies the end of a stream.
        End,
      };
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::IO::SeekOrigin> {
  void operator()(System::Collections::Generic::IDictionary<System::IO::SeekOrigin, string>& values, bool& flags) {
    values[System::IO::SeekOrigin::Begin] = "Begin";
    values[System::IO::SeekOrigin::Current] = "Current";
    values[System::IO::SeekOrigin::End] = "End";
    flags =  false;
  }
};
/// @endcond

using namespace Switch;

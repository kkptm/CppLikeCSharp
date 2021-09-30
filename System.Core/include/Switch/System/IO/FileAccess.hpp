/// @file
/// @brief Contains Switch::System::IO::FileAccess enum.
#pragma once

#include "../Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @enum FileAccess
      /// @brief Defines constants for read, write, or read/write access to a file.
      /// @see FileStream
      enum class FileAccess {
        /// @brief Read access to the file. Data can be read from the file. Combine with Write for read/write access.
        Read,
        /// @brief Write access to the file. Data can be written to the file. Combine with Read for read/write access.
        Write,
        /// @brief Read and write access to the file. Data can be written to and read from the file.
        ReadWrite,
      };
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::IO::FileAccess> {
  void operator()(System::Collections::Generic::IDictionary<System::IO::FileAccess, string>& values, bool& flags) {
    values[System::IO::FileAccess::Read] = "Read";
    values[System::IO::FileAccess::Write] = "Write";
    values[System::IO::FileAccess::ReadWrite] = "ReadWrite";
    flags = false;
  }
};
/// @endcond

using namespace Switch;

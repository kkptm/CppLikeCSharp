/// @file
/// @brief Contains Switch::System::IO::FileMode enum.
#pragma once

#include "../Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Specifies how the operating system should open a file.
      enum class FileMode {
        /// @brief Specifies that the operating system should create a new file. This requires System::Security::Permissions::FileIOPermissionAccess::Write. If the file already exists, an System::IO::IOException is thrown.
        CreateNew = 1,
        /// @brief Specifies that the operating system should create a new file. If the file already exists, it will be overwritten. This requires System::Security::Permissions.FileIOPermissionAccess.Write. System::IO::FileMode.Create is equivalent to requesting that if the file does not exist, use System::IO::FileMode.CreateNew; otherwise, use System::IO::FileMode.Truncate.
        Create = 2,
        /// @brief Specifies that the operating system should open an existing file. The ability to open the file is dependent on the value specified by System::IO::FileAccess.
        Open = 3,
        /// @brief Specifies that the operating system should open a file if it exists; otherwise, a new file should be created. If the file is opened with FileAccess.Read, System::Security::Permissions.FileIOPermissionAccess.Read is required. If the file access is FileAccess.Write then System::Security::Permissions.FileIOPermissionAccess.Write is required. If the file is opened with FileAccess.ReadWrite, both System::Security::Permissions.FileIOPermissionAccess.Read and System::Security::Permissions.FileIOPermissionAccess.Write are required.
        OpenOrCreate = 4,
        /// @brief Specifies that the operating system should open an existing file. Once opened, the file should be truncated so that its size is zero bytes. This requires System::Security::Permissions::FileIOPermissionAccess.Write. Attempts to read from a file opened with Truncate cause an exception.
        Truncate = 5,
        /// @brief Opens the file if it exists and seeks to the end of the file, or creates a new file. FileMode.Append can only be used in conjunction with FileAccess.Write. Attempting to seek to a position before the end of the file will throw an System::IO::IOException and any attempt to read fails and throws an System::NotSupportedException.
        Append = 6
      };
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::IO::FileMode> {
  void operator()(System::Collections::Generic::IDictionary<System::IO::FileMode, string>& values, bool& flags) {
    values[System::IO::FileMode::CreateNew] = "CreateNew";
    values[System::IO::FileMode::Create] = "Create";
    values[System::IO::FileMode::Open] = "Open";
    values[System::IO::FileMode::OpenOrCreate] = "OpenOrCreate";
    values[System::IO::FileMode::Truncate] = "Truncate";
    values[System::IO::FileMode::Append] = "Append";
    flags = false;
  }
};
/// @endcond

using namespace Switch;

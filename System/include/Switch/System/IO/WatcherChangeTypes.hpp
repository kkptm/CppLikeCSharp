/// @file
/// @brief Contains Switch::System::IO::WatcherChangeTypes enum.
#pragma once

#include <Switch/As.hpp>
#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Exception.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Changes that might occur to a file or directory.
      /// This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
      enum class WatcherChangeTypes {
        /// @brief The creation, deletion, change, or renaming of a file or folder.
        All = 15,
        /// @brief The creation of a file or folder.
        Created = 1,
        /// @brief The deletion of a file or folder.
        Deleted = 2,
        /// @brief The change of a file or folder. The types of changes include: changes to size, attributes, security settings, last write, and last access time.
        Changed = 4,
        /// @brief The renaming of a file or folder.
        Renamed = 8
      };
    }
  }
}

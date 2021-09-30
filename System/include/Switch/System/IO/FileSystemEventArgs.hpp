/// @file
/// @brief Contains Switch::System::IO::FileSystemEventArgs class.
#pragma once

#include <Switch/As.hpp>
#include <Switch/System/EventArgs.hpp>
#include "../../SystemExport.hpp"
#include "WatcherChangeTypes.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Provides data for the directory events: Changed, Created, Deleted.
      /// @par Library
      /// Switch.System
      class system_export_ FileSystemEventArgs : public EventArgs {
      public:
        FileSystemEventArgs(WatcherChangeTypes changeType, const string directory, const string name) : changeType(changeType), directory(directory), name(name) {}

        /// @cond
        FileSystemEventArgs(const FileSystemEventArgs& fsea) : changeType(fsea.changeType), directory(fsea.directory), name(fsea.name) {}
        FileSystemEventArgs& operator=(const FileSystemEventArgs& fsea) {
          this->changeType = fsea.changeType;
          this->directory = fsea.directory;
          this->name = fsea.name;
          return *this;
        }
        /// @endcond

        property_<WatcherChangeTypes, readonly_> ChangeType {
          get_ {return this->changeType;}
        };

        property_<string, readonly_> Directory {
          get_ {return this->directory;}
        };

        property_<string, readonly_> Name {
          get_ {return this->name;}
        };

      private:
        WatcherChangeTypes changeType;
        string directory;
        string name;
      };
    }
  }
}

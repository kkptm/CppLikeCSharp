/// @file
/// @brief Contains Switch::System::IO::ErrorEventArgs class.
#pragma once

#include <Switch/As.hpp>
#include <Switch/System/EventArgs.hpp>
#include <Switch/System/Exception.hpp>
#include "../../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Provides data for the FileSystemWatcher.Error event.
      /// @remarks ErrorEventArgs contains the Exception that caused the FileSystemWatcher.Error event. This class provides the GetException method to retrieve the exception.
      /// @par Library
      /// Switch.System
      class system_export_ ErrorEventArgs : public EventArgs {
      public:
        /// @brief Initializes a new instance of the ErrorEventArgs class.
        template<typename T>
        ErrorEventArgs(const T& exception) : exception(as<T>(exception.template MemberwiseClone<T>())) {}

        /// @cond
        ErrorEventArgs(const ErrorEventArgs& e) : exception(e.exception) {}
        /// @endcond

        /// @brief Gets the Exception that represents the error that occurred.
        /// @return Exception An Exception that represents the error that occurred.
        const Exception& GetException() const {return this->exception();}

      private:
        refptr<Exception> exception;
      };
    }
  }
}

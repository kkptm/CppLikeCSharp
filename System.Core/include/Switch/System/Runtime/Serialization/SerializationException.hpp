/// @file
/// @brief Contains Switch::System::Runtime::Serialization::SerializationException exception.
#pragma once

#include "../../SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Runtime namespaces contain types that support an application's interaction with the common language runtime, and types that enable features such as application data caching, advanced exception handling, application activation within application domains, COM interop, distributed applications, serialization and deserialization, and versioning.
    namespace Runtime {
      /// @brief The System::Runtime::Serialization namespace contains classes that can be used for serializing and deserializing objects. Serialization is the process of converting an object or a graph of objects into a linear sequence of bytes for either storage or transmission to another location. Deserialization is the process of taking in stored information and recreating objects from it.
      /// The ISerializable interface provides a way for classes to control their own serialization behavior. Classes in the System::Runtime::Serialization::Formatters namespace control the actual formatting of various data types encapsulated in the serialized objects.
      /// Formatters that serialize and deserialize objects to and from a particular format can be found in the System::Runtime::Serialization::Formatters namespace.
      namespace Serialization {
        /// @brief The exception thrown when an error occurs during serialization or deserialization.
        class core_export_ SerializationException : public SystemException {
        public:
          /// @brief Create a new instance of class SerializationException
          /// @remarks Message is set with the default message associate to the error.
          SerializationException() : SystemException() {}

          /// @brief Create a new instance of class SerializationException
          /// @param value The Excetion to copy.
          /// @remarks Message is set with the default message associate to the error.
          SerializationException(const SerializationException& value) : SystemException(value) {}

          /// @brief Create a new instance of class SerializationException
          /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
          /// @remarks Message is set with the default message associate to the error.
          SerializationException(const System::Runtime::CompilerServices::Caller& information) : SystemException(information) {}

          /// @brief Create a new instance of class SerializationException
          /// @param message Message string associate to the error.
          SerializationException(const System::String& message) : SystemException(message) {}

          /// @brief Create a new instance of class SerializationException
          /// @param message Message string associate to the error.
          /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
          SerializationException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, information) {}

          /// @brief Create a new instance of class SerializationException
          /// @param message Message string associate to the error.
          /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
          /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
          SerializationException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, innerException, information) {}

        private:
          System::String GetDefaultMessage() const override {return "Serialization error."; }
        };
      }
    }
  }
}


using namespace Switch;

/// @file
/// @brief Contains Switch::System::Runtime::Serialization::Formatter class.
#pragma once

#include "IFormatter.hpp"

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
        /// @brief Provides base functionality for the common language runtime serialization formatters.
        class core_export_ Formatter : public Object, public IFormatter {
        public:
          /// @brief Initializes a new instance of the IFormatter interface.
          Formatter() {}

          virtual void WrtiteBoolean(bool value, const String& name) = 0;
        };
      }
    }
  }
}

using namespace Switch;

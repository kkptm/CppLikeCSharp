/// @file
/// @brief Contains Switch::System::Runtime::Serialization::ISerializable interface.
#pragma once

#include "../../../Interface.hpp"
#include "SerializationInfo.hpp"

/// @cond
namespace Switch {
  namespace System {
    namespace Runtime {
      namespace Serialization {
        class SerializationInfo;
      }
    }
  }
}
/// @endcond

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
        /// @interface ISerializable
        /// @brief Allows an object to control its own serialization and deserialization.
        class core_export_ ISerializable interface_ {
        public:
          /// @brief Populates a SerializationInfo with the data needed to serialize the target object.
          /// @param info The SerializationInfo to populate with data.
          /// @remarks Any objects that are included in the SerializationInfo are automatically tracked and serialized by the formatter.
          /// @remarks Code that calls GetObjectData requires the SecurityPermission for providing serialization services. Associated enumeration: SecurityPermissionFlag.SerializationFormatter.
          /// @note It is not guaranteed that this method will be called only once per object instance during serialization. Therefore, the method should be implemented in such a way that its behavior will be the same regardless of the number of times it is called.
          virtual void GetObjectData(System::Runtime::Serialization::SerializationInfo& info) const = 0;
          // virtual void GetObjectData(System::Runtime::Serialization::SerializationInfo& info, StreamingContext context) const = 0;
        };
      }
    }
  }
}

using namespace Switch;

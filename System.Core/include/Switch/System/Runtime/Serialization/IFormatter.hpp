/// @file
/// @brief Contains Switch::System::Runtime::Serialization::IFormatter interface.
#pragma once

#include "../../../Types.hpp"
#include "../../../Interface.hpp"
#include "../../../RefPtr.hpp"
#include "../../IO/Stream.hpp"
#include "../../Object.hpp"
#include "ISerializable.hpp"

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
        /// @interface IFormatter
        /// @brief Provides functionality for formatting serialized objects.
        class core_export_ IFormatter interface_ {
        public:
          /// @cond
          template<typename T>
          T Deserialize(const refptr<System::IO::Stream>& seralizationStream) {
            T obj;
            Deserialize(seralizationStream, obj);

            return obj;
          }
          /// @endcond

          /// @brief Deserializes the data on the provided stream and reconstitutes the graph of objects.
          /// @param serializationStream The stream that contains the data to deserialize.
          /// @remarks The Deserialize method reads graph information from the stream and reconstructs a clone of the original graph. The topology of the graph is preserved.
          /// @remarks The deserialization process allocates an empty object of the appropriate type and repopulates its fields from the data transmitted in the serializationStream stream.
          /// @remarks It is important to note that no constructor is ever called on the object during deserialization.
          virtual void Deserialize(const refptr<System::IO::Stream>& serializationStream, ISerializable& graph) = 0;

          /// @brief Serializes an object, or graph of objects with the given root to the provided stream.
          /// @param serializationStream The stream where the formatter puts the serialized data. This stream can reference a variety of backing stores (such as files, network, memory, and so on).
          /// @param graph The object, or root of the object graph, to serialize. All child objects of this root object are automatically serialized.
          /// @remarks The Serialize method automatically serializes the provided objects, and all objects connected to it, to the provided stream.
          /// @remarks By default, the serialization process records an object's state by gathering the values of all its fields (public and private).
          /// @remarks These fields are saved to the stream along with information about the object such as the name qualified by the assembly for its type.
          virtual void Serialize(const refptr<System::IO::Stream>& serializationStream, const Object& graph) = 0;
        };
      }
    }
  }
}

using namespace Switch;

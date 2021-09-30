/// @file
/// @brief Contains Switch::System::ICloneable interface.
#pragma once

#include "../Interface.hpp"
#include "../Types.hpp"
#include "../RefPtr.hpp"

/// @cond
namespace Switch {
  namespace System {
    class Object;
  }
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @interface ICloneable
    /// @brief Supports cloning, which creates a new instance of a class with the same value as an existing instance.
    class core_export_ ICloneable interface_ {
    public:
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return object A new object that is a copy of this instance.
      virtual refptr<Object> Clone() const = 0;
    };
  }
}

using namespace Switch;

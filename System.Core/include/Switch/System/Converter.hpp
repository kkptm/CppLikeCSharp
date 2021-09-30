/// @file
/// @brief Contains Switch::System::Converter delegate.
#pragma once

#include "Delegate.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    template<typename TInput, typename TOutput>
    using Converter = Delegate<TOutput, TInput>;

    //using Converter_ = Converter<any, any>;
  }
}

using namespace Switch;

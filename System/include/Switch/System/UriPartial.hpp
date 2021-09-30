/// @file
/// @brief Contains Switch::System::UriPartial enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Defines the parts of a URI for the Uri.GetLeftPart method.
    /// @par Library
    /// Switch.System
    enum class UriPartial {
      /// @brief The scheme segment of the URI.
      Scheme = 0,
      /// @brief The scheme and authority segments of the URI.
      Authority = 1,
      /// @brief The scheme, authority, and path segments of the URI.
      Path = 2,
      /// @brief The scheme, authority, path, and query segments of the URI.
      Query = 3,
    };
  }
}

/// @cond
template<>
struct EnumRegister<System::UriPartial> {
  void operator()(System::Collections::Generic::IDictionary<System::UriPartial, string>& values, bool& flags) {
    values[System::UriPartial::Scheme] = "Scheme";
    values[System::UriPartial::Authority] = "Authority";
    values[System::UriPartial::Path] = "Path";
    values[System::UriPartial::Query] = "Query";
    flags = false;
  }
};
/// @endcond

using namespace Switch;

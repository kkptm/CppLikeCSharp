/// @file
/// @brief Contains Switch::Interface struct and #interface_ keyword.
#pragma once

#include "Types.hpp"
#include "Allocator.hpp"
#include "NullPtr.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Represent an interface class.
  struct core_export_ Interface {
    /// @cond
    virtual ~Interface() {}
    /// @endcond
  };

  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    template<typename T = NullPtr, int32 Rank = 1, typename TAllocator = Allocator<typename std::conditional<std::is_same<bool, T>::value, char, T>::type>>
    class Array;
    /// @endcond
  }

  /// @brief This keyword is use to represent an interface.
  /// @par Examples
  /// @code
  /// class IStringable interface_ {
  /// public:
  ///   virtual String ToString() const = 0;
  /// };
  ///
  /// class Foo : public object, public IStringable {
  /// public:
  ///   Foo() {}
  ///
  ///   String ToString() const override {return "Foo";}
  /// };
  /// @endcode
  /// @ingroup Keywords
#define interface_ \
: public Interface
}

using namespace Switch;

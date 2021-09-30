/// @file
/// @brief Contains Switch::namof kayword.
#pragma once

#include "System/String.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Used to obtain the simple (unqualified) string name of a variable, type, or member.
  ///
  /// When reporting errors in code, hooking up model-view-controller (MVC) links, firing property changed events, etc., you often want to capture the string name of a method. Using nameof helps keep your code valid when renaming definitions. Before, you had to use string literals to refer to definitions, which is brittle when renaming code elements because tools do not know to check these string literals.
  ///
  /// A nameof expression has this form:
  /// @code
  /// if (x == null) throw  ArgumentNullException(nameof_(x));
  /// WriteLine(nameof_(person.Address.ZipCode)); // prints "person.Address.ZipCode"
  /// @endcode
  /// @par Examples
  /// Some C++ examples:
  /// @include Nameof.cpp
  /// @remarks The argument to nameof must be a simple name, qualified name, member access, base access with a specified member, or this access with a specified member. The argument expression identifies a code definition, but it is never evaluated.
  /// @remarks Because the argument needs to be an expression syntactically, there are many things disallowed that are not useful to list. The following are worth mentioning that produce errors: predefined types (for example, int or void), nullable types (Point?), array types (Customer[,]), pointer types (Buffer*), qualified alias (A::B), and unbound generic types (Dictionary<,>), preprocessing symbols (DEBUG), and labels (loop:).
  /// @remarks If you need to get the fully-qualified name, you can use the typeof_ expression along with nameof. For example:
  /// @code
  /// class C {
  /// public:
  ///   void f(int i) {
  ///     Log(string::Format("{0}.{1}", typeof_(C), nameof_(f)), "method entry");
  ///   }
  /// }
  /// @endcode
  /// @ingroup Keywords
#define nameof_(value) \
  System::String(#value)
}

using namespace Switch;

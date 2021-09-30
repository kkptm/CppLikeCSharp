/// @file
/// @brief Contains Switch::System::Action class.
#pragma once

#include <cstddef>

#include "../Types.hpp"
#include "Delegate.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Encapsulates a method that has 0 to 16 parameters and does not return a value.
    /// @param arguments The parameters of the method that this delegate encapsulates.
    /// @remarks You can use the Action<T> delegate to pass a method as a parameter without explicitly declaring a custom delegate. The encapsulated method must correspond to the method signature that is defined by this delegate. This means that the encapsulated method must have one parameter that is passed to it by value, and it must not return a value. Typically, such a method is used to perform an operation.
    /// @note To reference a method that has one parameter and returns a value, use the generic Func<T, TResult> delegate instead.
    ///
    /// When you use the Action<T> delegate, you do not have to explicitly define a delegate that encapsulates a method with a single parameter. For example, the following code explicitly declares a delegate named DisplayMessage and assigns a reference to either the WriteLine method or the ShowWindowsMessage method to its delegate instance.
    /// @include Action1.cpp
    /// The following example simplifies this code by instantiating the Action<T> delegate instead of explicitly defining a new delegate and assigning a named method to it.
    /// @include Action2.cpp
    /// You can also assign a lambda expression to an Action<T> delegate instance, as the following example illustrates. (For an introduction to lambda expressions, see Lambda Expressions (C++ Programming Guide).)
    /// @include Action3.cpp
    /// The ForEach and ForEach<T> methods each take an Action<T> delegate as a parameter. The method encapsulated by the delegate allows you to perform an action on each element in the array or list. The example uses the ForEach method to provide an illustration.
    ///
    /// @par Examples
    /// The following example demonstrates the use of the Action<T> delegate to print the contents of a List<T> object. In this example, the Print method is used to display the contents of the list to the console. In addition, the C++ example also demonstrates the use of anonymous methods to display the contents to the console. Note that the example does not explicitly declare an Action<T> variable. Instead, it passes a reference to a method that takes a single parameter and that does not return a value to the List<T>.ForEach method, whose single parameter is an Action<T> delegate. Similarly, in the C++ example, an Action<T> delegate is not explicitly instantiated because the signature of the anonymous method matches the signature of the Action<T> delegate that is expected by the List<T>.ForEach method.
    /// @include Action.cpp
    template<typename... Arguments>
    using Action = Delegate<void, Arguments...>;
  }
}

using namespace Switch;

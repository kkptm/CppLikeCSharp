/// @file
/// @brief Contains Switch::System::Func <...Arguments, TResults> delegate.
#pragma once

#include "Object.hpp"
#include "../NullPtr.hpp"
#include "../Types.hpp"
#include "_String.hpp"
#include "Delegate.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    template<typename T1 = NullPtr, typename T2 = NullPtr, typename T3 = NullPtr, typename T4 = NullPtr, typename T5 = NullPtr, typename T6 = NullPtr, typename T7 = NullPtr, typename T8 = NullPtr, typename T9 = NullPtr, typename T10 = NullPtr, typename T11 = NullPtr, typename T12 = NullPtr, typename T13 = NullPtr, typename T14 = NullPtr, typename T15 = NullPtr, typename T16 = NullPtr, class TResult = void>
    class Func;
    /// @endcond

    /// @brief Encapsulates a method that has 16 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @param arg10 The tenth parameter of the method that this delegate encapsulates.
    /// @param arg11 The eleventh parameter of the method that this delegate encapsulates.
    /// @param arg12 The twelfth parameter of the method that this delegate encapsulates.
    /// @param arg13 The thirteenth parameter of the method that this delegate encapsulates.
    /// @param arg14 The fourteenth parameter of the method that this delegate encapsulates.
    /// @param arg15 The fifteenth parameter of the method that this delegate encapsulates.
    /// @param arg16 The sixteenth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16, class TResult>
    class Func : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16>& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 15 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @param arg10 The tenth parameter of the method that this delegate encapsulates.
    /// @param arg11 The eleventh parameter of the method that this delegate encapsulates.
    /// @param arg12 The twelfth parameter of the method that this delegate encapsulates.
    /// @param arg13 The thirteenth parameter of the method that this delegate encapsulates.
    /// @param arg14 The fourteenth parameter of the method that this delegate encapsulates.
    /// @param arg15 The fifteenth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 14 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @param arg10 The tenth parameter of the method that this delegate encapsulates.
    /// @param arg11 The eleventh parameter of the method that this delegate encapsulates.
    /// @param arg12 The twelfth parameter of the method that this delegate encapsulates.
    /// @param arg13 The thirteenth parameter of the method that this delegate encapsulates.
    /// @param arg14 The fourteenth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 13 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @param arg10 The tenth parameter of the method that this delegate encapsulates.
    /// @param arg11 The eleventh parameter of the method that this delegate encapsulates.
    /// @param arg12 The twelfth parameter of the method that this delegate encapsulates.
    /// @param arg13 The thirteenth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 12 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @param arg10 The tenth parameter of the method that this delegate encapsulates.
    /// @param arg11 The eleventh parameter of the method that this delegate encapsulates.
    /// @param arg12 The twelfth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 11 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @param arg10 The tenth parameter of the method that this delegate encapsulates.
    /// @param arg11 The eleventh parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 10 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @param arg10 The tenth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 9 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9>& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 8 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8>& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 7 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2, T3, T4, T5, T6, T7>& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 6 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2, T3, T4, T5, T6>& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2, T3, T4, T5, T6>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 5 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, class TResult>
    class Func<T1, T2, T3, T4, T5, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2, T3, T4, T5>& function) : Delegate<TResult, T1, T2, T3, T4, T5>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2, T3, T4, T5>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2, T3, T4, T5>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 4 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, class TResult>
    class Func<T1, T2, T3, T4, TResult> : public Delegate<TResult, T1, T2, T3, T4> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2, T3, T4>& function) : Delegate<TResult, T1, T2, T3, T4>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2, T3, T4>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2, T3, T4>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 3 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, class TResult>
    class Func<T1, T2, T3, TResult> : public Delegate<TResult, T1, T2, T3> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2, T3>& function) : Delegate<TResult, T1, T2, T3>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2, T3>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2, T3>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 2 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, class TResult>
    class Func<T1, T2, TResult> : public Delegate<TResult, T1, T2> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T1, T2>& function) : Delegate<TResult, T1, T2>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T1, T2>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T1, T2>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 1 parameter and returns a value of the type specified by the TResult parameter.
    /// @param arg The first parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<class T, class TResult>
    class Func<T, TResult> : public Delegate<TResult, T> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult, T>& function) : Delegate<TResult, T>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult, T>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult, T>(object, function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has no parameter and returns a value of the type specified by the TResult parameter.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<class TResult>
    class Func<TResult> : public Delegate<TResult> {
    public:
      /// @cond
      Func() {}
      Func(const Delegate<TResult>& function) : Delegate<TResult>(function) {}
      template<typename Function> Func(Function function) : Delegate<TResult>(function) {}
      template<typename Object, typename Function> Func(const Object& object, Function function) : Delegate<TResult>(object, function) {}
      /// @endcond
    };
  }
}

using namespace Switch;

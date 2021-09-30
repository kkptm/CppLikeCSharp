/// @file
/// @brief Contains Switch::System::Delegate <Result, ...Arguments> class.
#pragma once

#include <algorithm>
#include <vector>

#include "Object.hpp"
#include "../Is.hpp"
#include "../Types.hpp"
#include "_String.hpp"
#include "ArgumentNullException.hpp"
#include "NullReferenceException.hpp"
#include "Type.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents a delegate, which is a data structure that refers to a static method or to a class instance and an instance method of that class.
    /// @par Examples
    /// The following example shows how to define a delegate named myMethodDelegate. Instances of this delegate are created for an instance method and a static method of the nested mySampleClass class. The delegate for the instance method requires an instance of mySampleClass. The mySampleClass instance is saved in a variable named mySC.
    /// @include Delegate.cpp
    template<typename Result, typename... Arguments>
    class Delegate : public object {
    public:
      /// @brief Function pointer type
      using Function = std::function<Result(Arguments...)>;

      /// @brief Function pointer type
      using FunctionPointer = Result(*)(Arguments...);

      /// @brief Initializes an empty delegate.
      Delegate() {}

      /// @brief Initializes a delegate that invokes the specified delegate instance.
      /// @param delegate The delegate instance.
      Delegate(const Delegate& delegate) : functions(delegate.functions) {}

      /// @brief Initializes a delegate that invokes the specified instance method.
      /// @param function the method instance.
      Delegate(const Function& function) {this->functions.push_back(function);}

      /// @brief Initializes a delegate that invokes the specified instance method on the specified class instance.
      /// @param object the class instance.
      /// @param function the method instance.
      template<typename Object>
      Delegate(const Object& object, Result(Object::*member)() const) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object))));
      }

      /// @brief Initializes a delegate that invokes the specified instance method on the specified class instance.
      /// @param object the class instance.
      /// @param function the method instance.
      template<typename Object>
      Delegate(const Object& object, Result(Object::*member)()) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object))));
      }

      /// @cond
      template<typename Fn>
      Delegate(Fn function) {this->functions.push_back(function);}

      template<typename Object, typename A1>
      Delegate(const Object& object, Result(Object::*member)(A1) const) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1)));
      }

      template<typename Object, typename A1>
      Delegate(const Object& object, Result(Object::*member)(A1)) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1)));
      }

      template<typename Object, typename A1, typename A2>
      Delegate(const Object& object, Result(Object::*member)(A1, A2) const) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2)));
      }

      template<typename Object, typename A1, typename A2>
      Delegate(const Object& object, Result(Object::*member)(A1, A2)) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2)));
      }

      template<typename Object, typename A1, typename A2, typename A3>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3) const) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)));
      }

      template<typename Object, typename A1, typename A2, typename A3>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3)) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)));
      }

      template<typename Object, typename A1, typename A2, typename A3, typename A4>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3, A4) const) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)));
      }

      template<typename Object, typename A1, typename A2, typename A3, typename A4>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3, A4)) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)));
      }

      template<typename Object, typename A1, typename A2, typename A3, typename A4, typename A5>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3, A4, A5) const) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5)));
      }

      template<typename Object, typename A1, typename A2, typename A3, typename A4, typename A5>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3, A4, A5)) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5)));
      }

      template<typename Object, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3, A4, A5, A6) const) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6)));
      }

      template<typename Object, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3, A4, A5, A6)) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6)));
      }

      template<typename Object, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3, A4, A5, A6, A7) const) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7)));
      }

      template<typename Object, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3, A4, A5, A6, A7)) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7)));
      }

      template<typename Object, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3, A4, A5, A6, A7, A8) const) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8)));
      }

      template<typename Object, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3, A4, A5, A6, A7, A8)) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8)));
      }

      template<typename Object, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3, A4, A5, A6, A7, A8, A9) const) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9)));
      }

      template<typename Object, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3, A4, A5, A6, A7, A8, A9)) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9)));
      }

      template<typename Object, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10) const) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10)));
      }

      template<typename Object, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
      Delegate(const Object& object, Result(Object::*member)(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)) {
        this->functions.push_back(Function(std::bind(member, const_cast<Object*>(&object), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10)));
      }
      /// @endcond

      /// @brief Invokes the method represented by the current delegate.
      /// @param arguments The paramter list.
      /// @return Result The return value.
      Result operator()(Arguments... arguments) const {
        if (this->functions.size() == 0) return Result();
        for (size_t index = 0; index < this->functions.size() - 1; index++) {
          if (this->functions[index] == null)
            throw NullReferenceException(caller_);
          this->functions[index](arguments...);
        }
        if (this->functions.back() == null)
          throw NullReferenceException(caller_);
        return this->functions.back()(arguments...);
      }

      /// @brief Invokes the method represented by the current delegate.
      /// @param arguments The paramter list.
      /// @return Result The return value.
      Result Invoke(Arguments... arguments) const {return this->operator()(arguments...);}

      /// @brief Concatenates the invocation lists of an array of delegates.
      /// @param delagates The array of delegates to combine.
      /// @return Delegte A new delegate with an invocation list that concatenates the invocation lists of the delegates in the delegates array. Returns null if delegates is null, if delegates contains zero elements, or if every entry in delegates is null.
      /// @remarks If the delegates array contains entries that are null, those entries are ignored.
      /// @remarks The invocation list can contain duplicate entries; that is, entries that refer to the same method on the same object.
      static Delegate Combine(const System::Array<Delegate>& delegates) {
        Delegate result;
        for (const Delegate& delegate : delegates)
          for (const Function& function : delegate.functions)
            result.functions.push_back(function);
        return result;
      }

      /// @brief Concatenates the invocation lists of two delegates.
      /// @param a The delegate whose invocation list comes first.
      /// @param b The delegate whose invocation list comes second.
      /// @return DelegateType A new delegate with an invocation list that concatenates the invocation lists of a and b in that order. Returns a if b is null, returns b if a is a null reference, and returns a null reference if both a and b are null references.
      /// @remarks The invocation list can contain duplicate entries; that is, entries that refer to the same method on the same object.
      static Delegate Combine(const Delegate& a, const Delegate& b) {return Combine(System::Array<Delegate> {a, b});}

      /// @brief Return if the delegate is empty.
      /// @return bool Return true if Delegate is empty; otherwhise false.
      bool IsEmpty() const {return this->functions.size() == 0;}

      /// @brief Removes the last occurrence of the invocation list of a delegate from the invocation list of another delegate.
      /// @param source The delegate from which to remove the invocation list of value.
      /// @param value The delegate that supplies the invocation list to remove from the invocation list of source.
      /// @return Delegate A new delegate with an invocation list formed by taking the invocation list of source and removing the last occurrence of the invocation list of value, if the invocation list of value is found within the invocation list of source. Returns source if value is null or if the invocation list of value is ! found within the invocation list of source. Returns a null reference if the invocation list of value is equal to the invocation list of source or if source is a null reference.
      /// @remarks If the invocation list of value matches a contiguous set of elements in the invocation list of source, then the invocation list of value is said to occur within the invocation list of source. If the invocation list of value occurs more than once in the invocation list of source, the last occurrence is removed.
      static Delegate Remove(const Delegate& source, const Delegate& value) {
        Delegate result = source;
        for (const Function& function : value.functions) {
          if (Find(result.functions.begin(), result.functions.end(), function) != result.functions.end()) {
            for (typename std::vector<Function>::reverse_iterator iterator = result.functions.rbegin(); iterator != result.functions.rend(); ++iterator) {
              if (AreEquals(*iterator, function)) {
                result.functions.erase((iterator + 1).base());
                break;
              }
            }
          }
        }
        return result;
      }

      /// @brief Removes all occurrences of the invocation list of a delegate from the invocation list of another delegate.
      /// @param source The delegate from which to remove the invocation list of value.
      /// @param value The delegate that supplies the invocation list to remove from the invocation list of source.
      /// @return Delegate A new delegate with an invocation list formed by taking the invocation list of source and removing all occurrences of the invocation list of value, if the invocation list of value is found within the invocation list of source. Returns source if value is null or if the invocation list of value is ! found within the invocation list of source. Returns a null reference if the invocation list of value is equal to the invocation list of source, if source contains only a series of invocation lists that are equal to the invocation list of value, or if source is a null reference.
      /// @remarks If the invocation list of value matches a contiguous set of elements in the invocation list of source, then the invocation list of value is said to occur within the invocation list of source. If the invocation list of value occurs more than once in the invocation list of source, all occurrences are removed.
      static Delegate RemoveAll(const Delegate& source, const Delegate& value) {
        Delegate result = source;
        for (const Function& function : value.functions) {
          if (Find(result.functions.begin(), result.functions.end(), function) != result.functions.end()) {
            for (typename std::vector<Function>::reverse_iterator iterator = result.functions.rbegin(); iterator != result.functions.rend(); ++iterator) {
              if (AreEquals(*iterator, function))
                result.functions.erase((iterator + 1).base());
            }
          }
        }
        return result;
      }

      /// @brief Determines whether this instance and another specified DelegateType object have the same value.
      /// @param value The DelegateType to compare.
      /// @return bool true if the value of this instance is the same as the value of value; otherwise, false.
      bool operator==(const Delegate& delegate) const {
        if (this->functions.size() != delegate.functions.size())
          return false;

        for (size_t index = 0; index < this->functions.size(); index++)
          if (!AreEquals(this->functions[index], delegate.functions[index]))
            return false;

        return true;
      }

      /// @brief Determines whether this instance and another specified DelegateType object have the same value.
      /// @param value The DelegateType to compare.
      /// @return bool true if the value of this instance is the same as the value of value; otherwise, false.
      bool operator !=(const Delegate& delegate) const {return !this->operator==(delegate);}

      Delegate& operator=(const Delegate& delegate) {
        this->functions = delegate.functions;
        return *this;
      }

      Delegate& operator+=(const Delegate& delegate) {
        *this = Delegate::Combine(*this, delegate);
        return *this;
      }

      template<typename Fn>
      Delegate& operator+=(Fn function) {
        *this = Delegate::Combine(*this, Delegate(function));
        return *this;
      }

      Delegate& operator-=(const Delegate& delegate) {
        *this = Delegate::Remove(*this, delegate);
        return *this;
      }

      template<typename Fn>
      Delegate& operator-=(Fn function) {
        *this = Delegate::Remove(*this, Delegate(function));
        return *this;
      }

    private:
      static bool AreEquals(const std::function<Result(Arguments...)>& fct1, const std::function<Result(Arguments...)>& fct2) {
        return fct1.target_type() == fct2.target_type() && (fct1.template target<Result(*)(Arguments...)>() == fct2.template target<Result(*)(Arguments...)>() || *fct1.template target<Result(*)(Arguments...)>() == *fct2.template target<Result(*)(Arguments...)>());
      }

      static typename std::vector<Function>::const_iterator Find(typename std::vector<Function>::const_iterator begin, typename std::vector<Function>::const_iterator end, const Function& function) {
        for (typename std::vector<Function>::const_iterator iterator = begin; iterator != end; ++iterator)
          if (AreEquals(*iterator, function))
            return iterator;
        return end;
      }

      std::vector<Function> functions;
    };
  }

  /// @brief Represents a delegate, which is a data structure that refers to a static method or to a class instance and an instance method of that class.
  /// @par Examples
  /// The following example shows how to define a delegate named myMethodDelegate. Instances of this delegate are created for an instance method and a static method of the nested mySampleClass class. The delegate for the instance method requires an instance of mySampleClass. The mySampleClass instance is saved in a variable named mySC.
  /// @include Delegate.cpp
  /// @ingroup Types
  template<typename Result, typename... Arguments>
  using delegate = System::Delegate<Result, Arguments...>;

  /// @brief The declaration of a delegate type is similar to a method signature. It has a return value and any number of parameters of any type
  /// @par Examples
  /// @code
  /// button.Click += delegate_(const object& sender, const EventArgs& e) {
  ///   MessageBox::Show("Button click!", "Message", MessageBoxButtons::OK);
  /// };
  /// @endcode
  /// @ingroup Keywords
#define delegate_ \
  [&]
}

using namespace Switch;

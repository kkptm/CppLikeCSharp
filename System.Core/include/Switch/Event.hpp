/// @file
/// @brief Contains #lock_ keyword.
#pragma once

/// @cond
template<typename TParent, typename TDelegate>
class __event__ : public TDelegate {
public:
  __event__() {}
  __event__(const TDelegate& delegate) : TDelegate(delegate) {}
  template<typename Function> __event__(Function function) : TDelegate(function) {}
  template<typename Object, typename Function> __event__(const Object& object, Function function) : TDelegate(object, function) {}

  __event__& operator +=(const TDelegate& event) {
    this->TDelegate::operator +=(event);
    return *this;
  }

  template<typename Fn>
  __event__& operator +=(Fn function) {
    this->TDelegate::operator +=(function);
    return *this;
  }

  __event__& operator -=(const TDelegate& event) {
    this->TDelegate::operator -=(event);
    return *this;
  }

  template<typename Fn>
  __event__& operator -=(Fn function) {
    this->TDelegate::operator -=(function);
    return *this;
  }

private:
  friend TParent;
  template<typename ... TArguments> void operator()(const object& sender, TArguments... args) const {this->TDelegate(sender, args...);}
  template<typename ... TArguments> void Invoke(const object& sender, TArguments... args) const {this->TDelegate::Invoke(sender, args...);}
};
/// @endcond

namespace Switch {
  /// @brief The #event_ keyword is used to declare an event in a publisher class.
  /// @remarks
  /// Events are a special kind of multicast delegate that can only be invoked from within the class or struct where they are declared (the publisher class). If other classes or structs subscribe to the event, their event handler methods will be called when the publisher class raises the event.
  /// @par Examples
  /// The following example shows how to declare and raise an event that uses EventHandler as the underlying delegate type.
  /// @include Event.cpp
  /// @ingroup Keywords
#define event_ \
  __event__
}

using namespace Switch;

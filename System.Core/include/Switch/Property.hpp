/// @file
/// @brief Contains #property_, #get_ and #set_ keywords.
#pragma once

//#include <functional>
#include "__opaque_function_pointer__.hpp"

/// @cond
struct readonly_ {};
struct writeonly_ {};
struct readwrite_ {};

template <class T, class Attribute = readwrite_>
class property_;

template <class T, class Attribute>
class property_ : public Attribute {
  // Don't use std::function<> because the build became very slow
  //using Getter = std::function<T()>;
  //using Setter = std::function<void(T)>;
  using Getter = __opaque_function_pointer__<T>;
  using Setter = __opaque_function_pointer__<void, T>;

public:
  template<typename TGetter, typename TSetter>
  property_(TGetter getter, TSetter setter) : getter(getter), setter(setter) {}

  T Get() const {return this->getter();}
  T operator()() const {return this->getter();}

  operator T() const {return this->getter();}
  property_& operator=(const property_& property_) {this->setter(property_.getter()); return *this;}
  bool operator==(T value) const {return this->getter() == value;}
  bool operator !=(T value) const {return this->getter() != value;}

  T Set(T value) {this->setter(value); return this->getter();}
  T operator()(T value) {this->setter(value); return this->getter();}

  property_& operator=(T value) {this->setter(value); return *this;}
  void operator+=(T value) {this->setter(this->getter() + value);}
  void operator-=(T value) {this->setter(this->getter() - value);}
  void operator*=(T value) {this->setter(this->getter() * value);}
  void operator /=(T value) {this->setter(this->getter() / value);}
  void operator %=(T value) {this->setter(this->getter() % value);}
  void operator &=(T value) {this->setter(this->getter() & value);}
  void operator |=(T value) {this->setter(this->getter() | value);}
  void operator ^=(T value) {this->setter(this->getter() ^ value);}
  void operator<<=(T value) {this->setter(this->getter() << value);}
  void operator>>=(T value) {this->setter(this->getter() >> value);}

private:
  property_(const property_& property_)  = delete;
  Getter getter;
  Setter setter;
};

template <class T>
class property_<T, readonly_> : public readonly_ {
  // Don't use std::function<> because the build became very slow
  //using Getter = std::function<T()>;
  using Getter = __opaque_function_pointer__<T>;

public:
  template<typename TGetter>
  explicit property_(TGetter getter) : getter(getter) {}
  property_& operator=(const property_& property_) {return *this;}

  T Get() const {return this->getter();}
  T operator()() const {return this->getter();}
  operator T() const { return this->getter(); }
  operator T() { return this->getter(); }
  bool operator==(T value) const {return this->getter() == value;}
  bool operator !=(T value) const {return this->getter() != value;}

private:
  property_(const property_& property_)  = delete;
  Getter getter;
};

template <class T>
class property_<T, writeonly_> : public writeonly_ {
  // Don't use std::function<> because the build became very slow
  //using Setter = std::function<void(T)>;
  using Setter = __opaque_function_pointer__<void, T>;

public:
  template<typename TSetter>
  explicit property_(TSetter setter) : setter(setter) {}
  property_& operator=(const property_& property_) {return *this;}

  void Set(T value) {this->setter(value);}
  void operator()(T value) {this->setter(value);}
  void operator=(T value) {this->setter(value);}

private:
  property_(const property_& property_)  = delete;
  Setter setter;
};
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief #readonly_ keyword represent a #property_ read only attribute.
  /// @ingroup Keywords
#define readonly_ \
  readonly_

  /// @brief #readwrite_ keyword represent a #property_ read write attribute.
  /// @ingroup Keywords
#define readwrite_ \
  readwrite_

  /// @brief #writeonly_ keyword represent a #property_ write only attribute.
  /// @ingroup Keywords
#define writeonly_ \
  writeonly_

  /// @brief A #property_ is a member that provides a flexible mechanism to read, write, or compute the value of a private field. Properties can be used as if they are public data members, but they are actually special methods called accessors. This enables data to be accessed easily and still helps promote the safety and flexibility of methods.
  /// @remarks The copy constructor is deleted. So the copy constructor of the owner class must be specified (the implicit or default copy contructor doesn't build).
  /// @par Examples
  /// This sample shows a Person class that has two properties: Name (string) and Age (int). Both properties are read/write.
  /// @include Properties.cpp
  /// @ingroup Keywords
#define property_ \
  property_

  /// @brief The get keyword defines an accessor method in a #property_ or indexer that retrieves the value of the #property_ or the indexer element.
  /// @par Examples
  /// @code
  /// class Person {
  /// public:
  ///   Person() {}
  ///   Person(const Person& person) : name(person.name) {}
  ///
  ///   property_<string> Name {
  ///     get_ {return this->name},
  ///     set_ {this->name = value.ToUpper();}
  ///   };
  ///
  /// private:
  ///   string name;
  /// };
  /// @endcode
  /// @ingroup Keywords
#define get_ \
  [&]()

  /// @brief The set keyword defines an accessor method in a #property_ or indexer that assigns the value of the #property_ or the indexer element.
  /// @par Examples
  /// @code
  /// class Person {
  /// public:
  ///   Person() {}
  ///   Person(const Person& person) : name(person.name) {}
  ///
  ///   property_<string> Name {
  ///     get_ {return this->name},
  ///     set_ {this->name = value.ToUpper();}
  ///   };
  ///
  /// private:
  ///   string name;
  /// };
  /// @endcode
  /// @ingroup Keywords
#define set_ \
  [&](const auto& value)
}

using namespace Switch;


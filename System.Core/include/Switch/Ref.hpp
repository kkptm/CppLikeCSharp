/// @file
/// @brief Contains Switch::Reference class and Switch::Ref <> operator.
#pragma once

#include <exception>
#include <typeinfo>
#include <string>
#include <sstream>

#include "NullPtr.hpp"
#include "Types.hpp"

namespace Switch {
  /// @brief Represent a reference.
  template<typename T>
  class Ref {
  public:
    /// @brief Represent a Null Reference.
    static const T& Null() { static T* nullPtr = null; return *nullPtr; }

    /// @brief Represent an Empty Reference.
    static const Ref<T>& Empty() { static Ref<T> emptyPointer; return emptyPointer; }

    /// @brief Create a null Reference.
    Ref() {}

    /// @brief Create a Reference with specified pointer.
    /// @param ref Reference to store.
    Ref(const T& ref) { Reset(ref); }

    /// @brief Copy a Reference specified
    /// @param ref Reference to copy.
    Ref(const Ref& ref) : ptr(ref.ptr) {}

    Ref(NullPtr) : ptr(null) {}

    /// @brief Return true if this instance is null.
    /// @return true if this instance is null; otherwise false.
    static bool IsNullOrInvalid(const Ref<T>& ref) { return &ref == null || ref == null; }

    /// @brief Set to null.
    void Reset() { this->ptr = null; }

    /// @brief Set to new specified pointer.
    /// @param ref new ref to store.
    void Reset(const T& ref) { this->ptr = const_cast<T*>(&ref); }

    /// @brief Exchanges the contents of the Reference object with those of p, transferring ownership of any managed object between them without destroying either.
    /// @param ref Another Reference object of the same type.
    void Swap(Ref<T>& ref) {
      T* p = ref.ptr;
      ref.ptr = this->ptr;
      this->Reset(*p);
    }

    /// @brief Get the value stored in Reference.
    /// @return the value stored in Reference.
    /// @exception NullPointerException the Reference is null
    T& ToObject() {
      return *this->ToPointer();
    }

    /// @brief Get the value stored in Reference.
    /// @return the value stored in Reference.
    /// @exception NullPointerException the Reference is null
    const T& ToObject() const {
      return *this->ToPointer();
    }

    /// @brief Get the value stored in Reference with specified type.
    /// @return the value stored in Reference.
    /// @exception NullPointerException the Reference is null
    template<typename TT>
    TT& ToObject() {
      return *this->ToPointer<TT>();
    }

    /// @brief Get the value stored in Reference with specified type.
    /// @return the value stored in Reference.
    /// @exception NullPointerException the Reference is null
    template<typename TT>
    const TT& ToObject() const {
      return *this->ToPointer<TT>();
    }

    /// @brief Get the pointer stored in Reference.
    /// @return the pointer stored in Reference.
    /// @exception NullPointerException the Reference is null
    T* ToPointer() {
      if (this->ptr == null)
        throw std::exception();

      return this->ptr;
    }

    /// @brief Get the pointer stored in Reference.
    /// @return the pointer stored in Reference.
    /// @exception NullPointerException the Reference is null
    const T* ToPointer() const {
      if (this->ptr == null)
        throw std::exception();

      return this->ptr;
    }

    /// @brief Get the pointer stored in Reference with specified type.
    /// @return the pointer stored in Reference.
    /// @exception NullPointerException the Reference is null
    template<typename TT>
    TT* ToPointer() {
      if (this->ptr == null)
        throw std::exception();

      TT* cast = dynamic_cast<TT*>(this->ptr);
      if (cast == null)
        throw std::exception();
      return cast;
    }

    /// @brief Get the pointer stored in Reference with specified type.
    /// @return the pointer stored in Reference.
    /// @exception NullPointerException the Reference is null
    template<typename TT>
    const TT* ToPointer() const {
      if (this->ptr == null)
        throw std::exception();

      TT* cast = dynamic_cast<const TT*>(this->ptr);
      if (cast == null)
        throw std::exception();
      return cast;
    }

    /// @brief Dynamic cast this type to another specified type.
    /// @par Examples
    /// @code
    /// string str = "Test string";
    /// ...
    /// Ref<string> s = str;
    /// Ref<IComparable> comparable = s.ChangeType<IComparable>();
    /// @endcode
    template<typename TT>
    Ref<TT> As() const {
      try {
        if (this->ptr == null)
          return Ref<TT>::Null();

        const TT* ptr = dynamic_cast<const TT*>(this->ptr);
        return Ref<TT>(*ptr);
      } catch (const std::bad_cast&) {
        return Ref<TT>::Null();
      }
    }

    /// @brief Dynamic cast specified pointer to another specified type.
    /// @par Examples
    /// @code
    /// string str = "Test string";
    /// ...
    /// Ref<string> s = str;
    /// Ref<IComparable> comparable = Ref<string>::ChangeType<IComparable>(s);
    /// @endcode
    template<typename TT>
    static Ref<TT> As(const Ref<T>& p) { return p.As<TT>(); }

    /// @brief Dynamic cast this type to another specified type.
    /// @par Examples
    /// @code
    /// string str = "Test string";
    /// ...
    /// Ref<string> s = str;
    /// Ref<IComparable> comparable = s.ChangeType<IComparable>();
    /// @endcode
    template<typename TT>
    bool Is() const {
      try {
        if (this->ptr == null)
          return false;

        return dynamic_cast<const TT*>(this->ptr) != null;
      } catch (const std::bad_cast&) {
        return false;
      }
    }

    /// @brief Dynamic cast specified pointer to another specified type.
    /// @par Examples
    /// @code
    /// string str = "Test string";
    /// ...
    /// Ref<string> s = str;
    /// Ref<IComparable> comparable = Ref<string>::ChangeType<IComparable>(s);
    /// @endcode
    template<typename TT>
    static bool Is(const Ref<T>& p) { return p.Is<TT>(); }

    /// @brief Dynamic cast this type to another specified type.
    /// @par Examples
    /// @code
    /// string str = "Test string";
    /// ...
    /// Ref<string> s = str;
    /// Ref<IComparable> comparable = s.ChangeType<IComparable>();
    /// @endcode
    template<typename TT>
    Ref<TT> ChangeType() const { return Ref<TT>(this->ToPointer<TT>()); }

    /// @brief Dynamic cast specified pointer to another specified type.
    /// @par Examples
    /// @code
    /// string str = "Test string";
    /// ...
    /// Ref<string> s = str;
    /// Ref<IComparable> comparable = Ref<string>::ChangeType<IComparable>(s);
    /// @endcode
    template<typename TT>
    static Ref<TT> ChangeType(const Ref<T>& p) { return p.ChangeType<TT>(); }

    /// @brief Returns a string that represents the current Reference.
    /// @return string A string that represents the current object.
    std::string ToString() const {
      if (this->ptr == null)
        return "Switch::Ref [Reference=null]";
      std::stringstream s;
      s << "Switch::Ref [Reference=" << this->ptr << "]";
      return s.str();
    }

    /// @cond
    virtual ~Ref() { }

    const T& operator*() const { return ToObject(); }
    T& operator*() { return ToObject(); }

    const T& operator()() const { return ToObject(); }
    T& operator()() { return ToObject(); }

    const T* operator&() const { return ToPointer(); }
    T* operator&() { return ToPointer(); }

    const T* operator->() const { return ToPointer(); }
    T* operator->() { return ToPointer(); }

    operator const T& () const { return ToObject(); }
    operator T& () { return ToObject(); }

    Ref<T>& operator=(const T& ref) {
      Reset(ref);
      return *this;
    }

    Ref<T>& operator=(const Ref<T>& ref) {
      Reset(*ref.ptr);
      return *this;
    }

    bool operator==(NullPtr) const { return this->ptr == null; }

    bool operator==(const T& ref) const { return this->ptr == &ref; }

    bool operator==(const Ref<T>& ref) const { return this->ptr == ref.ptr; }

    bool operator!=(NullPtr) const { return this->ptr != null; }

    bool operator!=(const T& ref) const { return this->ptr != &ref; }

    bool operator!=(const Ref<T>& ref) const { return this->ptr != ref.ptr; }

    operator bool() const { return this->ptr != null; }

    bool operator!() const { return this->ptr == null; }
    /// @endcond

  protected:
    /// @cond
    T* ptr = null;
    /// @endcond
  };

  template<typename T>
  using ref = Ref<T>;
}

using namespace Switch;

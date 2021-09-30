/// @file
/// @brief Contains Switch::__opaque_function_pointer__ <TResult, ...Arguments> class.
#pragma once

#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <functional>

#include "NullPtr.hpp"
#include "Types.hpp"

/// @cond
template<typename TResult = void, typename T1 = NullPtr, typename T2 = NullPtr, typename T3 = NullPtr, typename T4 = NullPtr, typename T5 = NullPtr, typename T6 = NullPtr, typename T7 = NullPtr, typename T8 = NullPtr, typename T9 = NullPtr, typename T10 = NullPtr, typename T11 = NullPtr, typename T12 = NullPtr, typename T13 = NullPtr, typename T14 = NullPtr, typename T15 = NullPtr, typename T16 = NullPtr>
class __opaque_function_pointer__;

class core_export_ __opaque_inner_function_ptr__ {
private:
  template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16>
  friend class __opaque_function_pointer__;

  __opaque_inner_function_ptr__() {}

  __opaque_inner_function_ptr__(const __opaque_inner_function_ptr__& rhs) {
    this->size = rhs.size;
    if (this->size != 0) {
      this->value = malloc(this->size);
      memcpy(this->value, rhs.value, this->size);
    }
  }

  explicit __opaque_inner_function_ptr__(NullPtr) : value(null), size(0) {}

  template<typename T>
  explicit __opaque_inner_function_ptr__(T* value) {
    if (value == null) {
      this->value = null;
      this->size = 0;
      return;
    }
    this->size = sizeof(T*);
    this->value = malloc(this->size);
    memcpy(this->value, &value, this->size);
  }

  template<typename T>
  explicit __opaque_inner_function_ptr__(const T* value) {
    if (value == null) {
      this->value = null;
      this->size = 0;
      return;
    }
    this->size = sizeof(T*);
    this->value = malloc(this->size);
    memcpy(this->value, &value, this->size);
  }

  template<typename T>
  explicit __opaque_inner_function_ptr__(T& value) {
    this->size = sizeof(T);
    this->value = malloc(this->size);
    new (this->value) T(value);
  }

  template<typename T>
  explicit __opaque_inner_function_ptr__(const T& value) {
    this->size = sizeof(T);
    this->value = malloc(this->size);
    new (this->value) T(value);
  }

  ~__opaque_inner_function_ptr__() {
    if (this->value != null && this->size != 0)
      free(this->value);
  }

  __opaque_inner_function_ptr__& operator=(const __opaque_inner_function_ptr__& rhs) {
    if (this->value != null && this->size != 0)
      free(this->value);

    this->size = rhs.size;
    if (this->size != 0) {
      this->value = malloc(this->size);
      memcpy(this->value, rhs.value, this->size);
    }
    return *this;
  }

  bool operator==(const __opaque_inner_function_ptr__& rhs) const {
    if (this->size != rhs.size)
      return false;
    return memcmp(this->value, rhs.value, this->size) == 0;
  }

  bool operator !=(const __opaque_inner_function_ptr__& rhs) const {
    if (this->size != rhs.size)
      return true;
    return memcmp(this->value, rhs.value, this->size) != 0;
  }

  template<typename T>
  operator T& () const {
    return *(reinterpret_cast<T*>(this->value));
  }

  template<typename T>
  operator T* () const {
    return *reinterpret_cast<T**>(this->value);
  }

  bool IsNull() const {return this->value == null;}

  void* value = null;
  int size = 0;
};

// __opaque_function_pointer__<...> 16 arguments
template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, typename T16>
class __opaque_function_pointer__ {
public:
  using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16);
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16); }

  TResult operator()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15, T16 a16) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 15 arguments
template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15>
class __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15> {
public:
  using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15);
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); }

  TResult operator()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15);
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14, T15 a15) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 14 arguments
template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14>
class __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14> {
public:
  using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14);
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14); }

  TResult operator()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13, T14 a14) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 13 arguments
template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13>
class __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13> {
public:
  using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13);
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); }

  TResult operator()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13)>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12, T13 a13) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 12 arguments
template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12>
class __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12> {
public:
  using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12);
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); }

  TResult operator()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11, T12 a12) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 11 arguments
template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11>
class __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11> {
public:
  using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11);
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); }

  TResult operator()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10, T11 a11) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 10 arguments
template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
class __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> {
public:
  using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10);
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); }

  TResult operator()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9, T10 a10) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 9 arguments
template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
class __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9> {
public:
  using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8, T9);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9);
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9); }

  TResult operator()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8, a9); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8, T9 a9) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8, T9) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 8 arguments
template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
class __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8> {
public:
  using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7, T8);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7, T8>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8);
  };

  template<typename T> struct ConstMember {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7, T8) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8); }

  TResult operator()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7, a8); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7, a8);
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7, a8);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7, T8 a8) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7, a8);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2, T3, T4, T5, T6, T7, T8) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 7 arguments
template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
class __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7> {
public:
  using Function = TResult(*)(T1, T2, T3, T4, T5, T6, T7);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6, T7>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7);
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6, T7) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7); }

  TResult operator()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6, a7); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6, a7);
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6, a7);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6, T7 a7) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2, a3, a4, a5, a6, a7);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2, T3, T4, T5, T6, T7) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 6 arguments
template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6> {
public:
  using Function = TResult(*)(T1, T2, T3, T4, T5, T6);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5, T6>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6);
  };

  template<typename T> struct ConstMember {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5, T6) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method), invoker(StaticFunctionInvoker::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6); }

  TResult operator()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5, a6); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2, a3, a4, a5, a6);
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5, a6);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5, a6);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5, T6 a6) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2, a3, a4, a5, a6);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2, T3, T4, T5, T6) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 5 arguments
template<typename TResult, typename T1, typename T2, typename T3, typename T4, typename T5>
class __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5> {
public:
  using Function = TResult(*)(T1, T2, T3, T4, T5);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2, T3, T4, T5>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5);
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)(T1, T2, T3, T4, T5) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5); }

  TResult operator()(T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) const { return this->invoker(this->target, this->method, a1, a2, a3, a4, a5); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2, a3, a4, a5);
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4, a5);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4, a5);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4, T5 a5) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2, a3, a4, a5);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2, T3, T4, T5) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 4 arguments
template<typename TResult, typename T1, typename T2, typename T3, typename T4>
class __opaque_function_pointer__<TResult, T1, T2, T3, T4> {
public:
  using Function = TResult(*)(T1, T2, T3, T4);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2, T3, T4>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2, T3, T4);
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)(T1, T2, T3, T4) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2, T3 a3, T4 a4) const { return this->invoker(this->target, this->method, a1, a2, a3, a4); }

  TResult operator()(T1 a1, T2 a2, T3 a3, T4 a4) const { return this->invoker(this->target, this->method, a1, a2, a3, a4); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2, a3, a4);
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3, a4);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3, a4);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3, T4 a4) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2, a3, a4);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2, T3, T4) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 3 arguments
template<typename TResult, typename T1, typename T2, typename T3>
class __opaque_function_pointer__<TResult, T1, T2, T3> {
public:
  using Function = TResult(*)(T1, T2, T3);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2, T3>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2, T3);
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)(T1, T2, T3) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2, T3 a3) const { return this->invoker(this->target, this->method, a1, a2, a3); }

  TResult operator()(T1 a1, T2 a2, T3 a3) const { return this->invoker(this->target, this->method, a1, a2, a3); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2, a3);
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2, a3);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2, a3);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2, T3 a3) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2, a3);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2, T3) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 2 arguments
template<typename TResult, typename T1, typename T2>
class __opaque_function_pointer__<TResult, T1, T2> {
public:
  using Function = TResult(*)(T1, T2);

  using FunctionType = __opaque_function_pointer__<TResult, T1, T2>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1, T2);
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)(T1, T2) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1, T2 a2) const { return this->invoker(this->target, this->method, a1, a2); }

  TResult operator()(T1 a1, T2 a2) const { return this->invoker(this->target, this->method, a1, a2); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1, a2);
    }
  };

  template<typename T> struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1, a2);
    }
  };

  template<typename T> struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1, a2);
    }
  };

  template<typename T> struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1, T2 a2) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1, a2);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1, T2) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 1 argument
template<typename TResult, typename T1>
class __opaque_function_pointer__<TResult, T1> {
public:
  using Function = TResult(*)(T1);

  using FunctionType = __opaque_function_pointer__<TResult, T1>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)(T1);
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)(T1) const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit  __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke(T1 a1) const { return this->invoker(this->target, this->method, a1); }

  TResult operator()(T1 a1) const { return this->invoker(this->target, this->method, a1); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))(a1);
    }
  };

  template<typename T> struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))(a1);
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))(a1);
    }
  };

  template<typename T>
  struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function, T1 a1) {
      if (target.IsNull())
        throw std::exception();
      return static_cast<T>(target)(a1);
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&, T1) = StaticFunctionInvoker::Invoke;
};

// __opaque_function_pointer__<...> 0 argument
template<typename TResult>
class __opaque_function_pointer__<TResult> {
public:
  using Function = TResult(*)();

  using FunctionType = __opaque_function_pointer__<TResult>;

  template<typename T>
  struct Member {
    using Type = TResult(T::*)();
  };

  template<typename T>
  struct ConstMember {
    using Type = TResult(T::*)() const;
  };

  __opaque_function_pointer__() {}

  explicit __opaque_function_pointer__(NullPtr) {}

  explicit __opaque_function_pointer__(const FunctionType& function) : target(function.target), method(function.method), invoker(function.invoker) {}

  explicit __opaque_function_pointer__(Function method) : method(method) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename Member<T>::Type method) : target(&target), method(method), invoker(MemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  __opaque_function_pointer__(const T& target, typename ConstMember<T>::Type method) : target(&target), method(method), invoker(ConstMemberFunctionInvoker<T>::Invoke) {}

  template<typename T>
  explicit __opaque_function_pointer__(const T& target) : target(target), invoker(FunctorInvoker<T>::Invoke) {}

  FunctionType& operator=(const FunctionType& function) {
    this->target = function.target;
    this->method = function.method;
    this->invoker = function.invoker;
    return *this;
  }

  TResult Invoke() const { return this->invoker(this->target, this->method); }

  TResult operator()() const { return this->invoker(this->target, this->method); }

  bool operator==(const FunctionType& other) const { return this->target == other.target && this->method == other.method; }

  bool operator !=(const FunctionType& other) const { return this->target != other.target || this->method != other.method; }

  template<typename T>
  T Target() const {
    return static_cast<T>(this->target);
  }

  Function Method() const {
    return static_cast<Function>(this->method);
  }

  template<typename T>
  typename ConstMember<T>::Type ConstMethod() const {
    return static_cast<typename ConstMember<T>::Type>(this->method);
  }

  template<typename T>
  typename Member<T>::Type Method() const {
    return static_cast<typename Member<T>::Type>(this->method);
  }

  bool IsEmpty() const { return target.IsNull() && method.IsNull(); }

  bool IsNull() const { return target.IsNull() && method.IsNull(); }

private:
  struct StaticFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function) {
      if (function.IsNull())
        throw std::exception();
      return (static_cast<Function>(function))();
    }
  };

  template<typename T>
  struct MemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename Member<T>::Type>(function))();
    }
  };

  template<typename T>
  struct ConstMemberFunctionInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function) {
      if (target.IsNull() || function.IsNull())
        throw std::exception();
      return (static_cast<T*>(target)->*static_cast<typename ConstMember<T>::Type>(function))();
    }
  };

  template<typename T> struct FunctorInvoker {
    static TResult Invoke(const __opaque_inner_function_ptr__& target, const __opaque_inner_function_ptr__& function) {
      if (target.IsNull())
        throw std::exception();
      return (static_cast<T>(target))();
    }
  };

  __opaque_inner_function_ptr__ target {null};
  __opaque_inner_function_ptr__ method {null};
  TResult(*invoker)(const __opaque_inner_function_ptr__&, const __opaque_inner_function_ptr__&) = StaticFunctionInvoker::Invoke;
};
/// @endcond

using namespace Switch;

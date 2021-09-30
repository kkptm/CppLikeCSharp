/// @file
/// @brief Contains Switch::ExceptionPtr class.
#pragma once

#include <exception>
#include "CoreExport.hpp"
#include "NullPtr.hpp"

/// @cond
namespace Switch {
  namespace System {
    class Exception;
  }
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Smart pointer type that can refer to exception objects.
  /// @remarks It is a shared pointer-like type: The pointed exception is guaranteed to remain valid for as long as at least one exception_ptr points to it, potentially extending its lifetime beyond the scope of a catch statement or across threads.
  /// @remarks Different libraries may implement this type differently, but it shall at least support the following operations without throwing:
  /// * Being default-constructed (acquiring a null-pointer value).
  /// * Being copied, including being copied a null-pointer value (or null).
  /// * Being compared against another exception_ptr object (or null) using either operator== or operator!=, where two null-pointers are always considered equivalent, and two non-null pointers are considered equivalent only if they refer to the same exception object.
  /// * Being contextually convertible to bool, as false if having null-pointer value, and as true otherwise.
  /// * Being swapped, and being destructed.
  /// @remarks The type is also required to not be implicitly convertible to an arithmetic, enumeration, or pointer type.
  /// @remarks Performing any other operation on the object (such as dereferencing it), if at all supported by the library implementation, causes undefined behavior.
  /// @par Examples
  /// This example show how to use ExceptionPtr, ExceptionPtr::CurrentExeption and Rethrow() :
  /// @include ExceptionPtr.Cpp
  class core_export_ ExceptionPtr {
  public:
    /// @cond
    ExceptionPtr();
    ExceptionPtr(NullPtr);
    ExceptionPtr(const ExceptionPtr& eptr);
    ExceptionPtr& operator=(const ExceptionPtr& eptr);
    ExceptionPtr(const std::exception_ptr& eptr);
    ~ExceptionPtr();
    operator bool() const;
    bool operator!() const;
    bool operator==(NullPtr) const;
    bool operator==(const ExceptionPtr& eptr) const;
    bool operator!=(NullPtr) const;
    bool operator!=(const ExceptionPtr& eptr) const;
    /// @endcond

    /// @brief Get a ExceptionPtr object to current exception.
    /// @return An ExceptionPtr object pointing to the currently handled exception, or some other exception if the internal process of the function would raise a new exception.
    /// @remarks If no exception is being handled, the ExceptionPtr contains a null-pointer value.
    /// @remarks ExceptionPtr is a shared smart pointer type: The pointed exception is guaranteed to remain valid for as long as at least one exception_ptr points to it, potentially extending the lifetime of the pointed exception object beyond its scope or across threads.
    static ExceptionPtr CurrentException();

    /// @brief Create an ExceptionPtr object that points to a copy of specified Excpetion.
    /// @param excpetion exception The exception that copyied.
    /// @return ExceptionPtr The new ExceptinPointer object create
    template<class T>
    static ExceptionPtr Create(T exception) {
      try {
        throw exception;
      } catch (...) {
        return std::current_exception();
      }
    }

    /// @brief Create an ExceptionPtr object that points to a copy of specified Excpetion.
    /// @param excpetion exception The exception that copyied.
    /// @return ExceptionPtr The new ExceptinPointer object create
    static ExceptionPtr Create(const System::Exception& exception);

    /// @brief Throw the current ExceptionPtr.
    /// @remarks If is null, it throws nothing.
    void Rethrow() const;

  private:
    std::exception_ptr exception;
  };

  /// @brief Smart pointer type that can refer to exception objects.
  using excptr = ExceptionPtr;
}

using namespace Switch;

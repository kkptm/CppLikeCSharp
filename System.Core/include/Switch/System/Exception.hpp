/// @file
/// @brief Contains Switch::System::Exception exception.
#pragma once

#include "Runtime/CompilerServices/Caller.hpp"
#include "../Property.hpp"
#include "../RefPtr.hpp"
#include "../Types.hpp"
#include "Object.hpp"
#include "_String.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents errors that occur during application execution.
    /// @remarks This class is the base class for all exceptions. When an error occurs, either the system or the currently executing application reports it by throwing an exception that contains information about the error. After an exception is thrown, it is handled by the application or by the default exception handler.
    /// @section ErrorsAndExceptionsSection Errors and exceptions
    /// Run-time errors can occur for a variety of reasons. However, not all errors should be handled as exceptions in your code. Here are some categories of errors that can occur at run time and the appropriate ways to respond to them.
    /// * <b>Usage errors</b>. A usage error represents an error in program logic that can result in an exception. However, the error should be addressed not through exception handling but by modifying the faulty code. For example, the override of the Object.Equals(Object) method in the following example assumes that the obj argument must always be non-null.
    class core_export_ Exception: public Object, public std::exception {
    public:
      /// @brief Create a new instance of class Exception
      /// @remarks Message is set with the default message associate to the error.
      Exception();

      /// @brief Create a new instance of class Exception
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      explicit Exception(const System::Runtime::CompilerServices::Caller& information);

      /// @brief Create a new instance of class Exception
      /// @param message Message string associate to the error.
      explicit Exception(const String& message);

      /// @brief Create a new instance of class Exception
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      Exception(const String& message, const System::Runtime::CompilerServices::Caller& information);

      /// @brief Create a new instance of class Exception
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      Exception(const String& message, const Exception& innerException);

      /// @brief Create a new instance of class Exception
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      Exception(const String& message, const Exception& innerException, const System::Runtime::CompilerServices::Caller& information);

      /// @cond
      Exception(const Exception& value);
      const char* what() const noexcept override;
      /// @endcond

      /// @brief Get file path where Exception occurred
      /// @return string A string represent file path where Exception occurred
      property_<const String&, readonly_> FilePath {
        get_->const string& {return this->caller.FilePath();}
      };

      /// @brief Gets a link to the help file associated with this exception.
      /// @return string A string represent a link to Help file associated with Exception
      property_<const String&, readonly_> HelpLink {
        get_->const string& {return this->helpLink;}
      };

      /// @brief Get Error associate to the Exception
      /// @return Error A ErrorCode represent a Error associate to the Exception
      property_<int32, readonly_> HResult {
        get_ {return this->hresult;}
      };

      /// @brief Gets If other Exception instance that caused the current exception.
      /// @return Exception An instance of Exception that describes the error that caused the current exception. The InnerException property returns the same value as was passed into the constructor, or a null reference if the inner exception value was not supplied to the constructor.
      property_<bool, readonly_> HasInnerException {
        get_ {return this->innerException != null;}
      };

      /// @brief Gets the Exception instance that caused the current exception.
      /// @return Exception An instance of Exception that describes the error that caused the current exception. The InnerException property returns the same value as was passed into the constructor, or a null reference if the inner exception value was not supplied to the constructor.
      property_<const Exception&, readonly_> InnerException {
        get_->const Exception& {return this->innerException();}
      };

      /// @brief Get Line number where the Exception occurred
      /// @return Int32 the line number where Exception occurred
      property_<int32, readonly_> LineNumber {
        get_ {return this->caller.LineNumber();}
      };

      /// @brief Get message associate to the Exception
      /// @return string A string represent a massage associate to the Exception
      property_<const String&, readonly_> Message {
        get_->const string& {return this->GetMessage();}
      };

      /// @brief Gets a string representation of the immediate frames on the call stack.
      /// @return string A string that describes the immediate frames of the call stack.
      property_<String, readonly_> StackTrace {
        get_ {return this->GetStackTrace();}
      };

      /// @brief Gets or sets if the generation of the stack trace is enabled.
      static property_<bool> StackTraceEnabled;

      /// @brief Determines whether this instance of Exception and a specified object, which must also be a DelegateItem object, have the same value.
      /// @param value The Exception to compare with the current object.
      /// @return bool true if the specified value is equal to the current object. otherwise, false.
      bool Equals(const Exception& value) const;

      /// @brief Determines whether this instance of Exception and a specified object, which must also be a Exception object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const Object& obj) const override;

      /// @brief Returns a string that represents the current DelegateItem.
      /// @return string A string that represents the current DelegateItem.
      String ToString() const override;

      /// @brief Explicit operator equal between Exception
      /// @param value Value to assign this instance.
      /// @return Exception& This instance assigned
      Exception& operator=(const Exception& value);

    protected:
      /// @cond
      virtual String GetDefaultMessage() const;
      const String& GetMessage() const;
      String GetStackTrace() const;
      String GetStackTrace(const String& filter) const;
      void SetHResult(int32 hresult) {this->hresult = hresult;}
      void SetInnerException(ref<Exception> innerException) {this->innerException = innerException;}
      void SetStackTrace(const Exception& exception);

      //private:
      String message;
      String helpLink;
      System::Runtime::CompilerServices::Caller caller;
      ref<Exception> innerException;
      int32 hresult = 0;
      refptr<Array<String>> stackTrace;
      mutable String whatMessage;
      /// @endcond
    };
  }
}

using namespace Switch;

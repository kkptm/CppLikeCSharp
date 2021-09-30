#include "../../include/Switch/ExceptionPtr.hpp"
#include "../../include/Switch/System/Exception.hpp"
#include "../../include/Switch/System/Collections/Generic/List.hpp"
#include "../../include/Switch/System/AccessViolationException.hpp"
//#include "../../include/Switch/System/AggregateException.hpp"
#include "../../include/Switch/System/AppDomainUnloadedException.hpp"
#include "../../include/Switch/System/ArgumentNullException.hpp"
#include "../../include/Switch/System/ArrayTypeMismatchException.hpp"
#include "../../include/Switch/System/BadImageFormatException.hpp"
#include "../../include/Switch/System/CannotUnloadAppDomainException.hpp"
#include "../../include/Switch/System/ContextMarshalException.hpp"
#include "../../include/Switch/System/DataMisalignedException.hpp"
#include "../../include/Switch/System/DivideByZeroException.hpp"
#include "../../include/Switch/System/DllNotFoundException.hpp"
#include "../../include/Switch/System/DuplicateWaitObjectException.hpp"
#include "../../include/Switch/System/EntryPointNotFoundException.hpp"
#include "../../include/Switch/System/ExecutionEngineException.hpp"
#include "../../include/Switch/System/Exception.hpp"
#include "../../include/Switch/System/FieldAccessException.hpp"
#include "../../include/Switch/System/InsufficientExecutionStackException.hpp"
#include "../../include/Switch/System/InsufficientMemoryException.hpp"
#include "../../include/Switch/System/InvalidCastException.hpp"
#include "../../include/Switch/System/InvalidProgramException.hpp"
#include "../../include/Switch/System/InvalidTimeZoneException.hpp"
#include "../../include/Switch/System/MemberAccessException.hpp"
#include "../../include/Switch/System/MethodAccessException.hpp"
#include "../../include/Switch/System/MissingFieldException.hpp"
#include "../../include/Switch/System/MissingMemberException.hpp"
#include "../../include/Switch/System/MissingMethodException.hpp"
#include "../../include/Switch/System/MulticastNotSupportedException.hpp"
#include "../../include/Switch/System/NotFiniteNumberException.hpp"
#include "../../include/Switch/System/NotImplementedException.hpp"
#include "../../include/Switch/System/NullPointerException.hpp"
#include "../../include/Switch/System/NullReferenceException.hpp"
#include "../../include/Switch/System/ObjectDisposedException.hpp"
#include "../../include/Switch/System/ObjectDisposedException.hpp"
#include "../../include/Switch/System/OperationCanceledException.hpp"
#include "../../include/Switch/System/OverflowException.hpp"
#include "../../include/Switch/System/PlatformNotSupportedException.hpp"
#include "../../include/Switch/System/StackOverflowException.hpp"
#include "../../include/Switch/System/SystemException.hpp"
#include "../../include/Switch/System/TimeoutException.hpp"
#include "../../include/Switch/System/TimeZoneNotFoundException.hpp"
#include "../../include/Switch/System/TypeAccessException.hpp"
#include "../../include/Switch/System/TypeInitializationException.hpp"
#include "../../include/Switch/System/TypeUnloadedException.hpp"
#include "../../include/Switch/System/UnauthorizedAccessException.hpp"
#include "../../include/Switch/System/IO/DirectoryNotFoundException.hpp"
#include "../../include/Switch/System/IO/DriveNotFoundException.hpp"
#include "../../include/Switch/System/IO/EndOfStreamException.hpp"
#include "../../include/Switch/System/IO/FileFormatException.hpp"
#include "../../include/Switch/System/IO/FileLoadException.hpp"
#include "../../include/Switch/System/IO/FileNotFoundException.hpp"
#include "../../include/Switch/System/IO/IOException.hpp"
#include "../../include/Switch/System/IO/PathTooLongException.hpp"
#include "../../include/Switch/System/Security/HostProtectionException.hpp"
#include "../../include/Switch/System/Security/SecurityException.hpp"
#include "../../include/Switch/System/Security/VerificationException.hpp"
#include "../../include/Switch/System/Security/XmlSyntaxException.hpp"
#include "../../include/Switch/System/Threading/AbandonedMutexException.hpp"
#include "../../include/Switch/System/Threading/LockRecursionException.hpp"
#include "../../include/Switch/System/Threading/SynchronizationLockException.hpp"
#include "../../include/Switch/System/Threading/ThreadAbortException.hpp"
#include "../../include/Switch/System/Threading/ThreadInterruptedException.hpp"
#include "../../include/Switch/System/Threading/ThreadStartException.hpp"
#include "../../include/Switch/System/Threading/ThreadStateException.hpp"
#include "../../include/Switch/System/Threading/WaitHandleCannotBeOpenedException.hpp"
#include "../../include/Switch/System/Runtime/Serialization/SerializationException.hpp"

using namespace System;

ExceptionPtr::ExceptionPtr() {}

ExceptionPtr::ExceptionPtr(NullPtr) : exception(nullptr) {
}

ExceptionPtr::ExceptionPtr(const ExceptionPtr& eptr) : exception(eptr.exception) {
}

ExceptionPtr& ExceptionPtr::operator=(const ExceptionPtr& eptr) {
  this->exception = eptr.exception; return *this;
}

ExceptionPtr::ExceptionPtr(const std::exception_ptr& eptr) : exception(eptr) {
}

ExceptionPtr::~ExceptionPtr() {
}

ExceptionPtr::operator bool() const {
  return this->exception.operator bool();
}

bool ExceptionPtr::operator!() const {
  return !this->operator bool();
}

bool ExceptionPtr::operator==(NullPtr) const {
  return this->operator!();
}

bool ExceptionPtr::operator==(const ExceptionPtr& eptr) const {
  return this->exception == eptr.exception;
}

bool ExceptionPtr::operator!=(NullPtr) const {
  return !this->operator!();
}

bool ExceptionPtr::operator!=(const ExceptionPtr& eptr) const {
  return !this->operator==(eptr);
}

ExceptionPtr ExceptionPtr::CurrentException() {
  return std::current_exception();
}

ExceptionPtr ExceptionPtr::Create(const System::Exception& exception) {
  using namespace System;
  if (is<System::Threading::WaitHandleCannotBeOpenedException>(exception)) return ExceptionPtr::Create(as<System::Threading::WaitHandleCannotBeOpenedException>(exception));

  if (is<AccessViolationException>(exception)) return ExceptionPtr::Create(as<AccessViolationException>(exception));
  if (is<AppDomainUnloadedException>(exception)) return ExceptionPtr::Create(as<AppDomainUnloadedException>(exception));

  if (is<ArgumentNullException>(exception)) return ExceptionPtr::Create(as<ArgumentNullException>(exception));
  if (is<ArgumentOutOfRangeException>(exception)) return ExceptionPtr::Create(as<ArgumentOutOfRangeException>(exception));
  if (is<DuplicateWaitObjectException>(exception)) return ExceptionPtr::Create(as<DuplicateWaitObjectException>(exception));
  if (is<ArgumentException>(exception)) return ExceptionPtr::Create(as<ArgumentException>(exception));

  if (is<DivideByZeroException>(exception)) return ExceptionPtr::Create(as<DivideByZeroException>(exception));
  if (is<NotFiniteNumberException>(exception)) return ExceptionPtr::Create(as<NotFiniteNumberException>(exception));
  if (is<OverflowException>(exception)) return ExceptionPtr::Create(as<OverflowException>(exception));
  if (is<ArithmeticException>(exception)) return ExceptionPtr::Create(as<ArithmeticException>(exception));

  if (is<ArrayTypeMismatchException>(exception)) return ExceptionPtr::Create(as<ArrayTypeMismatchException>(exception));
  if (is<BadImageFormatException>(exception)) return ExceptionPtr::Create(as<BadImageFormatException>(exception));
  if (is<BadImageFormatException>(exception)) return ExceptionPtr::Create(as<BadImageFormatException>(exception));
  if (is<System::Collections::Generic::KeyNotFoundException>(exception)) return ExceptionPtr::Create(as<System::Collections::Generic::KeyNotFoundException>(exception));
  if (is<ContextMarshalException>(exception)) return ExceptionPtr::Create(as<ContextMarshalException>(exception));
  if (is<ExecutionEngineException>(exception)) return ExceptionPtr::Create(as<ExecutionEngineException>(exception));
  if (is<DataMisalignedException>(exception)) return ExceptionPtr::Create(as<DataMisalignedException>(exception));

  if (is<System::IO::FileFormatException>(exception)) return ExceptionPtr::Create(as<System::IO::FileFormatException>(exception));
  if (is<FormatException>(exception)) return ExceptionPtr::Create(as<FormatException>(exception));

  if (is<IndexOutOfRangeException>(exception)) return ExceptionPtr::Create(as<IndexOutOfRangeException>(exception));
  if (is<InsufficientExecutionStackException>(exception)) return ExceptionPtr::Create(as<InsufficientExecutionStackException>(exception));
  if (is<InvalidCastException>(exception)) return ExceptionPtr::Create(as<InvalidCastException>(exception));

  if (is<ObjectDisposedException>(exception)) return ExceptionPtr::Create(as<ObjectDisposedException>(exception));
  if (is<ObjectDisposedException>(exception)) return ExceptionPtr::Create(as<ObjectDisposedException>(exception));
  if (is<InvalidOperationException>(exception)) return ExceptionPtr::Create(as<InvalidOperationException>(exception));

  if (is<InvalidProgramException>(exception)) return ExceptionPtr::Create(as<InvalidProgramException>(exception));
  if (is<System::IO::IOException>(exception)) return ExceptionPtr::Create(as<System::IO::IOException>(exception));

  if (is<FieldAccessException>(exception)) return ExceptionPtr::Create(as<FieldAccessException>(exception));
  if (is<MethodAccessException>(exception)) return ExceptionPtr::Create(as<MethodAccessException>(exception));
  if (is<MissingFieldException>(exception)) return ExceptionPtr::Create(as<MissingFieldException>(exception));
  if (is<MissingMethodException>(exception)) return ExceptionPtr::Create(as<MissingMethodException>(exception));
  if (is<MissingMemberException>(exception)) return ExceptionPtr::Create(as<MissingMemberException>(exception));
  if (is<MemberAccessException>(exception)) return ExceptionPtr::Create(as<MemberAccessException>(exception));

  if (is<MulticastNotSupportedException>(exception)) return ExceptionPtr::Create(as<MulticastNotSupportedException>(exception));
  if (is<NotImplementedException>(exception)) return ExceptionPtr::Create(as<NotImplementedException>(exception));

  if (is<PlatformNotSupportedException>(exception)) return ExceptionPtr::Create(as<PlatformNotSupportedException>(exception));
  if (is<NotSupportedException>(exception)) return ExceptionPtr::Create(as<NotSupportedException>(exception));

  if (is<NullPointerException>(exception)) return ExceptionPtr::Create(as<NullPointerException>(exception));
  if (is<NullReferenceException>(exception)) return ExceptionPtr::Create(as<NullReferenceException>(exception));
  if (is<OperationCanceledException>(exception)) return ExceptionPtr::Create(as<OperationCanceledException>(exception));

  if (is<InsufficientMemoryException>(exception)) return ExceptionPtr::Create(as<InsufficientMemoryException>(exception));
  if (is<OutOfMemoryException>(exception)) return ExceptionPtr::Create(as<OutOfMemoryException>(exception));

  if (is<RankException>(exception)) return ExceptionPtr::Create(as<RankException>(exception));
  if (is<System::Runtime::Serialization::SerializationException>(exception)) return ExceptionPtr::Create(as<System::Runtime::Serialization::SerializationException>(exception));
  if (is<System::Security::HostProtectionException>(exception)) return ExceptionPtr::Create(as<System::Security::HostProtectionException>(exception));
  if (is<System::Security::SecurityException>(exception)) return ExceptionPtr::Create(as<System::Security::SecurityException>(exception));
  if (is<System::Security::VerificationException>(exception)) return ExceptionPtr::Create(as<System::Security::VerificationException>(exception));
  if (is<System::Security::XmlSyntaxException>(exception)) return ExceptionPtr::Create(as<System::Security::XmlSyntaxException>(exception));
  if (is<StackOverflowException>(exception)) return ExceptionPtr::Create(as<StackOverflowException>(exception));
  if (is<System::Threading::AbandonedMutexException>(exception)) return ExceptionPtr::Create(as<System::Threading::AbandonedMutexException>(exception));
  if (is<System::Threading::SynchronizationLockException>(exception)) return ExceptionPtr::Create(as<System::Threading::SynchronizationLockException>(exception));
  if (is<System::Threading::ThreadAbortException>(exception)) return ExceptionPtr::Create(as<System::Threading::ThreadAbortException>(exception));
  if (is<System::Threading::ThreadInterruptedException>(exception)) return ExceptionPtr::Create(as<System::Threading::ThreadInterruptedException>(exception));
  if (is<System::Threading::ThreadStartException>(exception)) return ExceptionPtr::Create(as<System::Threading::ThreadStartException>(exception));
  if (is<System::Threading::ThreadStateException>(exception)) return ExceptionPtr::Create(as<System::Threading::ThreadStateException>(exception));
  if (is<TimeoutException>(exception)) return ExceptionPtr::Create(as<TimeoutException>(exception));
  if (is<TimeZoneNotFoundException>(exception)) return ExceptionPtr::Create(as<TimeZoneNotFoundException>(exception));
  if (is<TypeInitializationException>(exception)) return ExceptionPtr::Create(as<TypeInitializationException>(exception));

  if (is<DllNotFoundException>(exception)) return ExceptionPtr::Create(as<DllNotFoundException>(exception));
  if (is<EntryPointNotFoundException>(exception)) return ExceptionPtr::Create(as<EntryPointNotFoundException>(exception));
  if (is<TypeAccessException>(exception)) return ExceptionPtr::Create(as<TypeAccessException>(exception));
  if (is<TypeLoadException>(exception)) return ExceptionPtr::Create(as<TypeLoadException>(exception));

  if (is<TypeUnloadedException>(exception)) return ExceptionPtr::Create(as<TypeUnloadedException>(exception));
  if (is<UnauthorizedAccessException>(exception)) return ExceptionPtr::Create(as<UnauthorizedAccessException>(exception));

  //if (is<AggregateException>(exception)) return ExceptionPtr::Create(as<AggregateException>(exception));
  if (is<ApplicationException>(exception)) return ExceptionPtr::Create(as<ApplicationException>(exception));
  if (is<InvalidTimeZoneException>(exception)) return ExceptionPtr::Create(as<InvalidTimeZoneException>(exception));
  if (is<SystemException>(exception)) return ExceptionPtr::Create(as<SystemException>(exception));
  if (is<System::Threading::LockRecursionException>(exception)) return ExceptionPtr::Create(as<System::Threading::LockRecursionException>(exception));

  return ExceptionPtr::Create(as<Exception>(exception));
}

void ExceptionPtr::Rethrow() const {
  if (this->exception)
    std::rethrow_exception(this->exception);
}


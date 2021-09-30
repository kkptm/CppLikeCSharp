#include "../../../../include/Switch/System/Security/SecureString.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Security;

SecureString::SecureString(const char32 value[], int32 length) : data(System::Collections::Generic::List<char32>(Native::SecurityApi::ToSecureString(string(value, length)))) {
}

void SecureString::AppendChar(char32 c) {
  if (this->readOnly)
    throw InvalidOperationException(caller_);
  System::Collections::Generic::List<char32> unsecureString = System::Collections::Generic::List<char32>(Native::SecurityApi::ToUnsecureString(string(this->data.ToArray())));
  unsecureString.Add(c);
  this->data = System::Collections::Generic::List<char32>(Native::SecurityApi::ToSecureString(string(unsecureString.ToArray())));
}

void SecureString::Clear() {
  if (this->readOnly)
    throw InvalidOperationException(caller_);
  for (auto& c : this->data)
    c = 0;
  this->data.Clear();
}

void SecureString::InsertAt(int32 index, char32 c) {
  if (this->readOnly)
    throw InvalidOperationException(caller_);
  System::Collections::Generic::List<char32> unsecureString = System::Collections::Generic::List<char32>(Native::SecurityApi::ToUnsecureString(string(this->data.ToArray())));
  unsecureString.Insert(index, c);
  this->data = System::Collections::Generic::List<char32>(Native::SecurityApi::ToSecureString(string(unsecureString.ToArray())));
}

void SecureString::RemoveAt(int32 index) {
  if (this->readOnly)
    throw InvalidOperationException(caller_);
  System::Collections::Generic::List<char32> unsecureString = System::Collections::Generic::List<char32>(Native::SecurityApi::ToUnsecureString(string(this->data.ToArray())));
  unsecureString.RemoveAt(index);
  this->data = System::Collections::Generic::List<char32>(Native::SecurityApi::ToSecureString(string(unsecureString.ToArray())));
}

void SecureString::SetAt(int32 index, char32 c) {
  if (this->readOnly)
    throw InvalidOperationException(caller_);
  System::Collections::Generic::List<char32> unsecureString = System::Collections::Generic::List<char32>(Native::SecurityApi::ToUnsecureString(string(this->data.ToArray())));
  unsecureString[index] = c;
  this->data = System::Collections::Generic::List<char32>(Native::SecurityApi::ToSecureString(string(unsecureString.ToArray())));
}

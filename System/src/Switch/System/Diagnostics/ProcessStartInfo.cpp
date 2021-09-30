#include <cstdarg>
#include <cstdlib>
#include <ctime>

#include "../../../../include/Switch/System/Diagnostics/ProcessStartInfo.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Diagnostics;

string ProcessStartInfo::GetPasswordInClearText() const {
  return Native::SecurityApi::ToUnsecureString(this->data->password);
}

void ProcessStartInfo::SetPasswordInClearText(const string& password) {
  this->data->password = Native::SecurityApi::ToSecureSecureString(password);
}

Array<string> ProcessStartInfo::GetVerbs(const string& fileName) {
  return {};
}

#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Message.hpp"
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Windows::Forms;

int32 System::Windows::Forms::Message::counter = 0;

string Message::ToString() const {
  return string::Format("msg=0x{0:X} ({1}) hwnd=0x{2:X} wparam=0x{3:X} lparam=0x{4:X} result=0x{5:X}", this->msg, Native::ControlApi::MessageToString(this->msg), this->hwnd, this->WParam, this->lParam, this->result);
}

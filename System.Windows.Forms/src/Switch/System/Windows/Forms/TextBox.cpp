#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/TextBox.hpp"
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void TextBox::CreateHandle() {
    this->handle = Native::TextBoxApi::Create(*this);
    this->Control::CreateHandle();
}

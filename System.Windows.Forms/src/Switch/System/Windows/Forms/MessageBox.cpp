#include "../../../../../include/Switch/System/Windows/Forms/MessageBox.hpp"
#include <Switch/System/Media/SystemSounds.hpp>
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Windows::Forms;

DialogResult MessageBox::Show(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  System::Collections::Generic::Dictionary<MessageBoxIcon, Action<>> messageBeep = {{MessageBoxIcon::None, delegate_ {}}, {MessageBoxIcon::Hand, {System::Media::SystemSounds::Hand(), &System::Media::SystemSound::Play}}, {MessageBoxIcon::Question, {System::Media::SystemSounds::Question(), &System::Media::SystemSound::Play}}, {MessageBoxIcon::Exclamation, {System::Media::SystemSounds::Exclamation(), &System::Media::SystemSound::Play}}, {MessageBoxIcon::Asterisk, {System::Media::SystemSounds::Asterisk(), &System::Media::SystemSound::Play}}};
  messageBeep[icon]();
  return Native::ApplicationApi::ShowMessageBox(message, caption, buttons, icon, defaultButton, options, displayHelpButton);
}

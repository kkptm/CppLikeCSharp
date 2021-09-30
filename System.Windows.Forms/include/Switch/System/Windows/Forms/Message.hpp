/// @file
/// @brief Contains Switch::System::Windows::Forms::MessageBoxButtons enum.
#pragma once

#include <Switch/System/Object.hpp>
#include "../../../SystemWindowsFormsExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        struct system_windows_forms_export_ Message : public object {
        public:
          /// @cond
          Message() {}
          Message(const Message& message) : hwnd(message.hwnd), msg(message.msg), wParam(message.wParam), lParam(message.lParam), result(message.result) {}
          /// @cond

          property_<intptr> HWnd {
            get_ {return this->hwnd;},
            set_ {this->hwnd = value;}
          };

          property_<intptr> LParam {
            get_{return this->lParam;},
            set_{this->lParam = value;}
          };

          property_<int32> Msg {
            get_{return this->msg;},
            set_{this->msg = value;}
          };

          property_<intptr> Result {
            get_{return this->result;},
            set_{this->result = value;}
          };

          property_<intptr> WParam {
            get_{return this->wParam;},
            set_{this->wParam = value;}
          };

          /// @cond
          property_<intptr> Handle {
            get_{return this->handle;},
            set_{this->handle = value;}
          };
          /// @endcond

          static Message Create(intptr hwnd, int32 msg, intptr wParam, intptr lParam, intptr result) { return Message(hwnd, msg, wParam, lParam, result); }

          /// @cond
          static Message Create(intptr hwnd, int32 msg, intptr wParam, intptr lParam, intptr result, intptr handle) { return Message(hwnd, msg, wParam, lParam, result, handle); }
          /// @endcond

          template<typename Type>
          refptr<Type> GetLParam() { return (refptr<Type>)this->lParam; }

          String ToString() const override;

        private:
          Message(intptr hwnd, int32 msg, intptr wParam, intptr lParam, intptr result) : hwnd(hwnd), msg(msg), wParam(wParam), lParam(lParam), result(result) { counter++; }
          Message(intptr hwnd, int32 msg, intptr wParam, intptr lParam, intptr result, intptr handle) : hwnd(hwnd), msg(msg), wParam(wParam), lParam(lParam), result(result), handle(handle) { counter++; }
          intptr hwnd = 0;
          int32 msg = 0;
          intptr wParam = 0;
          intptr lParam = 0;
          intptr result = 0;
          intptr handle = 0;
          static int32 counter;
        };
      }
    }
  }
}

using namespace Switch;

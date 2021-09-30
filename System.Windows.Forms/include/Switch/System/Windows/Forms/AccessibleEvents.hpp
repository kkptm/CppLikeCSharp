/// @file
/// @brief Contains Switch::System::Windows::Forms::AccessibleEvents enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Enumeration.
        /// Specifie the AccessibleEvents values
        enum class AccessibleEvents {
          SystemSound = 1,
          SystemAlert = 2,
          SystemForeground = 3,
          SystemMenuStart = 4,
          SystemMenuEnd = 5,
          SystemMenuPopupStart = 6,
          SystemMenuPopupEnd = 7,
          SystemCaptureStart = 8,
          SystemCaptureEnd = 9,
          SystemMoveSizeStart = 10,
          SystemMoveSizeEnd = 11,
          SystemContextHelpStart = 12,
          SystemContextHelpEnd = 13,
          SystemDragDropStart = 14,
          SystemDragDropEnd = 15,
          SystemDialogStart = 16,
          SystemDialogEnd = 17,
          SystemScrollingStart = 18,
          SystemScrollingEnd = 19,
          SystemSwitchStart = 20,
          SystemSwitchEnd = 21,
          SystemMinimizeStart = 22,
          SystemMinimizeEnd = 23,
          Create = 32768,
          Destroy = 32769,
          Show = 32770,
          Hide = 32771,
          Reorder = 32772,
          Focus = 32773,
          Selection = 32774,
          SelectionAdd = 32775,
          SelectionRemove = 32776,
          SelectionWithin = 32777,
          StateChange = 32778,
          LocationChange = 32779,
          NameChange = 32780,
          DescriptionChange = 32781,
          ValueChange = 32782,
          ParentChange = 32783,
          HelpChange = 32784,
          DefaultActionChange = 32785,
          AcceleratorChange = 32786,
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::AccessibleEvents> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::AccessibleEvents, string>& values, bool& flags) {
    values[System::Windows::Forms::AccessibleEvents::SystemSound] = "SystemSound";
    values[System::Windows::Forms::AccessibleEvents::SystemAlert] = "SystemAlert";
    values[System::Windows::Forms::AccessibleEvents::SystemForeground] = "SystemForeground";
    values[System::Windows::Forms::AccessibleEvents::SystemMenuStart] = "SystemMenuStart";
    values[System::Windows::Forms::AccessibleEvents::SystemMenuEnd] = "SystemMenuEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemMenuPopupStart] = "SystemMenuPopupStart";
    values[System::Windows::Forms::AccessibleEvents::SystemMenuPopupEnd] = "SystemMenuPopupEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemCaptureStart] = "SystemCaptureStart";
    values[System::Windows::Forms::AccessibleEvents::SystemCaptureEnd] = "SystemCaptureEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemMoveSizeStart] = "SystemMoveSizeStart";
    values[System::Windows::Forms::AccessibleEvents::SystemMoveSizeEnd] = "SystemMoveSizeEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemContextHelpStart] = "SystemContextHelpStart";
    values[System::Windows::Forms::AccessibleEvents::SystemContextHelpEnd] = "SystemContextHelpEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemDragDropStart] = "SystemDragDropStart";
    values[System::Windows::Forms::AccessibleEvents::SystemDragDropEnd] = "SystemDragDropEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemDialogStart] = "SystemDialogStart";
    values[System::Windows::Forms::AccessibleEvents::SystemDialogEnd] = "SystemDialogEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemScrollingStart] = "SystemScrollingStart";
    values[System::Windows::Forms::AccessibleEvents::SystemScrollingEnd] = "SystemScrollingEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemSwitchStart] = "SystemSwitchStart";
    values[System::Windows::Forms::AccessibleEvents::SystemSwitchEnd] = "SystemSwitchEnd";
    values[System::Windows::Forms::AccessibleEvents::SystemMinimizeStart] = "SystemMinimizeStart";
    values[System::Windows::Forms::AccessibleEvents::SystemMinimizeEnd] = "SystemMinimizeEnd";
    values[System::Windows::Forms::AccessibleEvents::Create] = "Create";
    values[System::Windows::Forms::AccessibleEvents::Destroy] = "Destroy";
    values[System::Windows::Forms::AccessibleEvents::Show] = "Show";
    values[System::Windows::Forms::AccessibleEvents::Hide] = "Hide";
    values[System::Windows::Forms::AccessibleEvents::Reorder] = "Reorder";
    values[System::Windows::Forms::AccessibleEvents::Focus] = "Focus";
    values[System::Windows::Forms::AccessibleEvents::Selection] = "Selection";
    values[System::Windows::Forms::AccessibleEvents::SelectionAdd] = "SelectionAdd";
    values[System::Windows::Forms::AccessibleEvents::SelectionRemove] = "SelectionRemove";
    values[System::Windows::Forms::AccessibleEvents::SelectionWithin] = "SelectionWithin";
    values[System::Windows::Forms::AccessibleEvents::StateChange] = "StateChange";
    values[System::Windows::Forms::AccessibleEvents::LocationChange] = "LocationChange";
    values[System::Windows::Forms::AccessibleEvents::NameChange] = "NameChange";
    values[System::Windows::Forms::AccessibleEvents::DescriptionChange] = "DescriptionChange";
    values[System::Windows::Forms::AccessibleEvents::ValueChange] = "ValueChange";
    values[System::Windows::Forms::AccessibleEvents::ParentChange] = "ParentChange";
    values[System::Windows::Forms::AccessibleEvents::HelpChange] = "HelpChange";
    values[System::Windows::Forms::AccessibleEvents::DefaultActionChange] = "DefaultActionChange";
    values[System::Windows::Forms::AccessibleEvents::AcceleratorChange] = "AcceleratorChange";
    flags = false;
  }
};
/// @endcond

using namespace Switch;

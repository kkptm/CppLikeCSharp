/// @file
/// @brief Contains Switch::System::Windows::Forms::AccessibleRole enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifie the AccessibleNavigation values
        enum class AccessibleRole {
          None,
          TitleBar,
          MenuBar,
          ScrollBar,
          Grip,
          Sound,
          Cursor,
          Caret,
          Alert,
          Window,
          Client,
          MenuPopup,
          MenuItem,
          ToolTip,
          Application,
          Document,
          Pane,
          Chart,
          Dialog,
          Border,
          Grouping,
          Separator,
          ToolBar,
          StatusBar,
          Table,
          ColumnHeader,
          RowHeader,
          Column,
          Row,
          Cell,
          Link,
          HelpBalloon,
          Character,
          List,
          ListItem,
          Outline,
          OutlineItem,
          PageTab,
          PropertyPage,
          Indicator,
          Graphic,
          StaticText,
          Text,
          PushButton,
          CheckButton,
          RadioButton,
          ComboBox,
          DropList,
          ProgressBar,
          Dial,
          HotkeyField,
          Slider,
          SpinButton,
          Diagram,
          Animation,
          Equation,
          ButtonDropDown,
          ButtonMenu,
          ButtonDropDownGrid,
          WhiteSpace,
          PageTabList,
          Clock,
          Default = -1,
          SplitButton = 62,
          IpAddress,
          OutlineButton
        };
      }
    }
  }
}

/// @cond
template<>
struct EnumRegister<System::Windows::Forms::AccessibleRole> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::AccessibleRole, string>& values, bool& flags) {
    values[System::Windows::Forms::AccessibleRole::None] = "None";
    values[System::Windows::Forms::AccessibleRole::TitleBar] = "TitleBar";
    values[System::Windows::Forms::AccessibleRole::MenuBar] = "MenuBar";
    values[System::Windows::Forms::AccessibleRole::ScrollBar] = "ScrollBar";
    values[System::Windows::Forms::AccessibleRole::Grip] = "Grip";
    values[System::Windows::Forms::AccessibleRole::Sound] = "Sound";
    values[System::Windows::Forms::AccessibleRole::Cursor] = "Cursor";
    values[System::Windows::Forms::AccessibleRole::Caret] = "Caret";
    values[System::Windows::Forms::AccessibleRole::Alert] = "Alert";
    values[System::Windows::Forms::AccessibleRole::Window] = "Window";
    values[System::Windows::Forms::AccessibleRole::Client] = "Client";
    values[System::Windows::Forms::AccessibleRole::MenuPopup] = "MenuPopup";
    values[System::Windows::Forms::AccessibleRole::MenuItem] = "MenuItem";
    values[System::Windows::Forms::AccessibleRole::ToolTip] = "ToolTip";
    values[System::Windows::Forms::AccessibleRole::Application] = "Application";
    values[System::Windows::Forms::AccessibleRole::Document] = "Document";
    values[System::Windows::Forms::AccessibleRole::Pane] = "Pane";
    values[System::Windows::Forms::AccessibleRole::Chart] = "Chart";
    values[System::Windows::Forms::AccessibleRole::Dialog] = "Dialog";
    values[System::Windows::Forms::AccessibleRole::Border] = "Border";
    values[System::Windows::Forms::AccessibleRole::Grouping] = "Grouping";
    values[System::Windows::Forms::AccessibleRole::Separator] = "Separator";
    values[System::Windows::Forms::AccessibleRole::ToolBar] = "ToolBar";
    values[System::Windows::Forms::AccessibleRole::StatusBar] = "StatusBar";
    values[System::Windows::Forms::AccessibleRole::Table] = "Table";
    values[System::Windows::Forms::AccessibleRole::ColumnHeader] = "ColumnHeader";
    values[System::Windows::Forms::AccessibleRole::RowHeader] = "RowHeader";
    values[System::Windows::Forms::AccessibleRole::Column] = "Column";
    values[System::Windows::Forms::AccessibleRole::Row] = "Row";
    values[System::Windows::Forms::AccessibleRole::Cell] = "Cell";
    values[System::Windows::Forms::AccessibleRole::Link] = "Link";
    values[System::Windows::Forms::AccessibleRole::HelpBalloon] = "HelpBalloon";
    values[System::Windows::Forms::AccessibleRole::Character] = "Character";
    values[System::Windows::Forms::AccessibleRole::List] = "List";
    values[System::Windows::Forms::AccessibleRole::ListItem] = "ListItem";
    values[System::Windows::Forms::AccessibleRole::Outline] = "Outline";
    values[System::Windows::Forms::AccessibleRole::OutlineItem] = "OutlineItem";
    values[System::Windows::Forms::AccessibleRole::PageTab] = "PageTab";
    values[System::Windows::Forms::AccessibleRole::PropertyPage] = "PropertyPage";
    values[System::Windows::Forms::AccessibleRole::Indicator] = "Indicator";
    values[System::Windows::Forms::AccessibleRole::Graphic] = "Graphic";
    values[System::Windows::Forms::AccessibleRole::StaticText] = "StaticText";
    values[System::Windows::Forms::AccessibleRole::PushButton] = "PushButton";
    values[System::Windows::Forms::AccessibleRole::CheckButton] = "CheckButton";
    values[System::Windows::Forms::AccessibleRole::RadioButton] = "RadioButton";
    values[System::Windows::Forms::AccessibleRole::ComboBox] = "ComboBox";
    values[System::Windows::Forms::AccessibleRole::DropList] = "DropList";
    values[System::Windows::Forms::AccessibleRole::ProgressBar] = "ProgressBar";
    values[System::Windows::Forms::AccessibleRole::Dial] = "Dial";
    values[System::Windows::Forms::AccessibleRole::HotkeyField] = "HotkeyField";
    values[System::Windows::Forms::AccessibleRole::Slider] = "Slider";
    values[System::Windows::Forms::AccessibleRole::SpinButton] = "SpinButton";
    values[System::Windows::Forms::AccessibleRole::Diagram] = "Diagram";
    values[System::Windows::Forms::AccessibleRole::Animation] = "Animation";
    values[System::Windows::Forms::AccessibleRole::Equation] = "Equation";
    values[System::Windows::Forms::AccessibleRole::ButtonDropDown] = "ButtonDropDown";
    values[System::Windows::Forms::AccessibleRole::ButtonMenu] = "ButtonMenu";
    values[System::Windows::Forms::AccessibleRole::ButtonDropDownGrid] = "ButtonDropDownGrid";
    values[System::Windows::Forms::AccessibleRole::WhiteSpace] = "WhiteSpace";
    values[System::Windows::Forms::AccessibleRole::PageTabList] = "PageTabList";
    values[System::Windows::Forms::AccessibleRole::Clock] = "Clock";
    values[System::Windows::Forms::AccessibleRole::Default] = "Default";
    values[System::Windows::Forms::AccessibleRole::SplitButton] = "SplitButton";
    values[System::Windows::Forms::AccessibleRole::IpAddress] = "IpAddress";
    values[System::Windows::Forms::AccessibleRole::OutlineButton] = "OutlineButton";
    flags = false;
  }
};
/// @endcond

using namespace Switch;

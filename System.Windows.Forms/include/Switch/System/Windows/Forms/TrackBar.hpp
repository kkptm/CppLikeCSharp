/// @file
/// @brief Contains Switch::System::Windows::Forms::Button class.
#pragma once

#include <Switch/System/Environment.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "Control.hpp"
#include "Orientation.hpp"
#include "TickStyle.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a standard Windows track bar.
        /// @remarks The TrackBar is a scrollable control similar to the ScrollBar control. You can configure ranges through which the value of the Value property of a track bar scrolls by setting the Minimum property to specify the lower end of the range and the Maximum property to specify the upper end of the range.
        /// @remarks The LargeChange property defines the increment to add or subtract from the Value property when clicks occur on either side of the scroll box. The track bar can be displayed horizontally or vertically.
        /// @remarks You can use this control to input numeric data obtained through the Value property. You can display this numeric data in a control or use it in code.
        class system_windows_forms_export_ TrackBar : public Control {
        public:
          TrackBar() : Control("", 0, 0, 104, 45) {
            this->SetStyle(ControlStyles::UserPaint, false);
            this->TabStop = false;
          }

          /// @cond
          TrackBar(const TrackBar& trackBar) : Control(trackBar), largeChange(trackBar.largeChange), maximum(trackBar.maximum), minimum(trackBar.minimum), smallChange(trackBar.smallChange), tickStyle(trackBar.tickStyle), tickFrequency(trackBar.tickFrequency), value(trackBar.value) {}
          /// @endcond

          property_<int32> LargeChange {
            get_{ return this->largeChange; },
            set_{ this->SetLargeChange(value); },
          };

          property_<Forms::Orientation> Orientation {
            get_{ return this->orientation; },
            set_{ this->SetOrientation(value); },
          };

          property_<int32> Maximum {
            get_{ return this->maximum; },
            set_{ this->SetMaximum(value); },
          };

          property_<int32> Minimum {
            get_{ return this->minimum; },
            set_{ this->SetMinimum(value); },
          };

          property_<int32> SmallChange{
            get_{ return this->smallChange; },
            set_{ this->SetSmallChange(value); },
          };

          property_<Forms::TickStyle> TickStyle {
            get_{ return this->tickStyle; },
            set_{ this->SetTickStyle(value); },
          };

          property_<int32> TickFrequency {
            get_{ return this->tickFrequency; },
            set_{ this->SetTickFrequency(value); },
          };

          property_<int32> Value {
            get_ {
              this->value = this->GetValue();
              return this->value;
            },
            set_{ this->SetValue(value); },
          };

          EventHandler Scroll;
          EventHandler ValueChanged;

          void WndProc(Message& message) override;

        protected:
          void OnScroll(const EventArgs& e) { this->Scroll(*this, e); }
          void OnValueChanged(const EventArgs& e) { this->ValueChanged(*this, e); }

          void CreateHandle() override;
          System::Drawing::Size GetDefaultSize() const override {
            if (this->orientation == Forms::Orientation::Horizontal)
              return System::Drawing::Size(104, 45);
            return System::Drawing::Size(45, 104);
          }
          void SetLargeChange(int32 largeChange);
          void SetMaximum(int32 maximum);
          void SetMinimum(int32 minimum);
          void SetOrientation(Forms::Orientation orientation);
          void SetSmallChange(int32 smallChange);
          void SetTickFrequency(int32 tickFrequency);
          void SetTickStyle(Forms::TickStyle style);
          int32 GetValue() const;
          void SetValue(int32 value);

          /// @cond
          int32 largeChange = 5;
          int32 maximum = 10;
          int32 minimum = 0;
          Forms::Orientation orientation = Forms::Orientation::Horizontal;
          int32 smallChange = 1;
          Forms::TickStyle tickStyle = Forms::TickStyle::BottomRight;
          int32 tickFrequency = 1;
          int32 value = 0;
          /// @endcond
        };
      }
    }
  }
}

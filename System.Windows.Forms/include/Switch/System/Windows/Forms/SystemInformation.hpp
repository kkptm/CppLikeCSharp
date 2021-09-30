/// @file
/// @brief Contains Switch::System::Windows::Forms::SystemInformation class.
#pragma once

#include <Switch/Property.hpp>
#include <Switch/Static.hpp>
#include <Switch/Types.hpp>
#include <Switch/System/Drawing/Font.hpp>
#include <Switch/System/Drawing/Size.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "ArrangeDirection.hpp"
#include "ArrangeStartingPosition.hpp"
#include "BootMode.hpp"

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Provides information about the current system environment.
        /// @remarks The SystemInformation class provides static properties that can be used to get information about the current system environment. The class provides access to information such as Windows display element sizes, operating system settings, network availability, and the capabilities of hardware installed on the system. This class cannot be instantiated.
        /// @remarks For more information about system-wide parameters, see "SystemParametersInfo" in the Platform SDK documentation at http://msdn.microsoft.com.
        class system_windows_forms_export_ SystemInformation static_ {
        public:
          /// @brief Gets the active window tracking delay.
          /// @return int32 The active window tracking delay, in milliseconds.
          static property_<int32, readonly_> ActiveWindowTrackingDelay;

          /// @brief Gets a value that indicates the direction in which the operating system arranges minimized windows.
          /// @return ArrangeDirection One of the ArrangeDirection values that indicates the direction in which the operating system arranges minimized windows.
          /// @remarks The ArrangeDirection property indicates the direction in which minimized windows are arranged on the desktop or in a Multiple Document Interface (MDI) container.
          static property_<System::Windows::Forms::ArrangeDirection, readonly_> ArrangeDirection;

          /// @brief Gets an ArrangeStartingPosition value that indicates the starting position from which the operating system arranges minimized windows.
          /// @return ArrangeStartingPosition One of the ArrangeStartingPosition values that indicates the starting position from which the operating system arranges minimized windows.
          /// @remarks The ArrangeStartingPosition property indicates the corner of a screen or window in which the operating system begins to arrange minimized windows.
          static property_<System::Windows::Forms::ArrangeStartingPosition, readonly_> ArrangeStartingPosition;

          /// @brief Gets a BootMode value that indicates the boot mode the system was started in.
          /// @return BootMode One of the BootMode values that indicates the boot mode the system was started in.
          /// @remarks The BootMode property indicates whether the operating system was started in a normal or safe boot mode.
          static property_<System::Windows::Forms::BootMode, readonly_> BootMode;

          /// @brief Gets the thickness, in pixels, of a three-dimensional (3-D) style window or system control border.
          /// @return System::Drawing::Size A Size that indicates the width, in pixels, of a 3-D style vertical border, and the height, in pixels, of a 3-D style horizontal border.
          /// @remarks The Border3DSize property indicates the thickness, in pixels, of a three-dimensional (3-D) style system control border.
          /// @remarks The Width property of the Border3DSize property indicates the width of a vertical 3-D border. The Height property of the Border3DSize property indicates the height of a horizontal 3-D border.
          /// @remarks The BorderSize property indicates the thickness of a window or system control border that is not a 3-D style border.
          static property_<System::Drawing::Size, readonly_> Border3DSize;

          /// @brief Gets the border multiplier factor that is used when determining the thickness of a window's sizing border.
          /// @return int32 The multiplier used to determine the thickness of a window's sizing border.
          static property_<int32, readonly_> BorderMultiplierFactor;

          /// @brief Gets the thickness, in pixels, of a flat-style window or system control border.
          /// @return System::Drawing::Size A Size that indicates the width, in pixels, of a vertical border, and the height, in pixels, of a horizontal border.
          /// @remarks The BorderSize property indicates the thickness of a flat-style system control border in pixels.
          /// @remarks The Width property of the BorderSize property indicates the width of a vertical flat-style border. The Height property of the BorderSize property indicates the height of a horizontal flat-style border.
          /// @remarks The Border3DSize property of the SystemInformation class indicates the thickness of a three-dimensional (3-D) style window or system control border.
          static property_<System::Drawing::Size, readonly_> BorderSize;

          /// @brief Gets the standard size, in pixels, of a button in a window's title bar.
          /// @return System::Drawing::Size A Size that indicates the standard dimensions, in pixels, of a button in a window's title bar.
          /// @remarks The CaptionButtonSize property indicates the standard dimensions of a button in the title bar of a window.
          /// @remarks The value of this property can be used to ensure that a button is properly sized to fit within the title bar of a window. Window caption buttons should be sized less than or equal to the standard dimensions for window caption buttons to ensure that they can be displayed in view correctly.
          static property_<System::Drawing::Size, readonly_> CaptionButtonSize;

          /// @brief Gets the height, in pixels, of the standard title bar area of a window.
          /// @return int32 The height, in pixels, of the standard title bar area of a window.
          /// @remarks The CaptionHeight property indicates the height of the standard window title bar area, in pixels.
          static property_<int32, readonly_> CaptionHeight;

          /// @brief Gets the caret blink time
          /// @return int32 The caret blink time.
          static property_<int32, readonly_> CaretBlinkTime;

          /// @brief Gets the width, in pixels, of the caret in edit controls.
          /// @return int32 The width, in pixels, of the caret in edit controls.
          static property_<int32, readonly_> CaretWidth;

          /// @brief Gets the NetBIOS computer name of the local computer.
          /// @return string The name of this computer.
          /// @remarks The ComputerName property retrieves the NetBIOS name of the local computer. This is accomplished with a call into the native System Information function GetComputerName. This name is established at system startup_, when the system reads it from the registry. If the local computer is a node in a cluster, ComputerName returns the name of the cluster virtual server.
          /// @remarks You can use the ComputerName method to determine the name of the computer that is displayed to other users on a network.
          static property_<string, readonly_> ComputerName;

          /// @brief Gets the maximum size, in pixels, that a cursor can occupy.
          /// @return System::Drawing::Size A Size that indicates the maximum dimensions of a cursor in pixels.
          /// @remarks The system cannot create cursors of other sizes.
          static property_<System::Drawing::Size, readonly_> CursorSize;

          /// @brief Gets a value indicating whether the operating system is capable of handling double-byte character set (DBCS) characters.
          /// @return bool true if the operating system supports DBCS; otherwise, false.
          /// @remarks The DbcsEnabled property indicates whether the current operating system supports DBCS.
          static property_<bool, readonly_> DbcsEnabled;

          /// @brief Gets a value indicating whether the debug version of USER.EXE is installed.
          /// @return bool true if the debugging version of USER.EXE is installed; otherwise, false.
          static property_<bool, readonly_> DebugOS;

          /// @brief Gets the dimensions, in pixels, of the area within which the user must click twice for the operating system to consider the two clicks a double-click.
          /// @return System::Drawing::Size A Size that indicates the dimensions, in pixels, of the area within which the user must click twice for the operating system to consider the two clicks a double-click.
          /// @remarks The DoubleClickSize property indicates the size of a rectangular area centered around the point at which the last click occurred. To cause a double-click, a second click must occur within the area of the rectangle before the double-click time elapses.
          /// @remarks The DoubleClickTime property indicates the maximum number of milliseconds that can elapse before a second click for the second click to cause a double-click.
          static property_<System::Drawing::Size, readonly_> DoubleClickSize;

          /// @brief Gets the maximum number of milliseconds that can elapse between a first click and a second click for the OS to consider the mouse action a double-click.
          /// @return int32 The maximum amount of time, in milliseconds, that can elapse between a first click and a second click for the OS to consider the mouse action a double-click.
          /// @remarks A double-click is a series of two clicks of the mouse button, the second occurring within a specified length of time after, and within a specified distance from, the first. The double-click time is the maximum number of milliseconds that can elapse between the first and second click of a double-click.
          /// @remarks The DoubleClickSize property indicates the size of a rectangular area centered around the point at which the last click occurred. To cause a double-click, a second click must occur within the area of the rectangle before the double-click time elapses.
          static property_<int32, readonly_> DoubleClickTime;

          /// @brief Gets a value indicating whether the user has enabled full window drag.
          /// @return bool true if the user has enabled full window drag; otherwise, false.
          /// @remarks When this property is true, the content of a window is refreshed during a window move or resize drag, using the current position and size as they are updated.
          static property_<bool, readonly_> DragFullWindows;

          /// @brief Gets the width and height of a rectangle centered on the point the mouse button was pressed, within which a drag operation will not begin.
          /// @return System::Drawing::Size A Size that specifies the area of a rectangle, in pixels, centered on the point the mouse button was pressed, within which a drag operation will not begin.
          /// @remarks The DragSize property indicates the size, in pixels, of a rectangle centered around the point at which the mouse button was pressed. Windows uses the rectangle as a boundary within which it does not start a drag operation.
          /// @remarks A user can hold a mouse button down and move the mouse within this area before a drag operation begins, which enables the user to click and release the mouse button easily without unintentionally starting a drag operation.
          static property_<System::Drawing::Size, readonly_> DragSize;

          /// @brief Gets the thickness, in pixels, of the frame border of a window that has a caption and is not resizable.
          /// @return System::Drawing::Size A Size that specifies the thickness, in pixels, of a fixed sized window border.
          /// @remarks The FixedFrameBorderSize property indicates the thickness of the frame, in pixels, around the perimeter of a window that has a caption but is not sizable.
          /// @remarks The Width property of FixedFrameBorderSize is the height of the horizontal border and the Height property of FixedFrameBorderSize is the width of the vertical border.
          static property_<System::Drawing::Size, readonly_> FixedFrameBorderSize;

          /// @brief Gets the font smoothing contrast value used in ClearType smoothing.
          /// @return int32 The ClearType font smoothing contrast value.
          static property_<int32, readonly_> FontSmoothingContrast;

          /// @brief Gets the current type of font smoothing.
          /// @return int32 A value that indicates the current type of font smoothing.
          static property_<int32, readonly_> FontSmoothingType;

          /// @brief Gets the thickness, in pixels, of the resizing border that is drawn around the perimeter of a window that is being drag resized.
          /// @return System::Drawing::Size A Size that indicates the thickness, in pixels, of the width of a vertical resizing border and the height of a horizontal resizing border.
          /// @remarks The FrameBorderSize property indicates the width and height of the resizing border for a window.
          /// @remarks The Width value of this property is the width of a vertical resizing border. The Height value of this property is the height of a horizontal resizing border.
          static property_<System::Drawing::Size, readonly_> FrameBorderSize;

          /// @brief Gets a value indicating whether the user has enabled the high-contrast mode accessibility feature.
          /// @return bool true if the user has enabled high-contrast mode; otherwise, false.
          /// @remarks The high-contrast accessibility feature can make the screen easier for some users to view by enabling a color scheme that can heighten screen contrast with alternative color combinations. Some of the schemes also change font sizes for easier reading.
          /// @remarks The high-contrast mode feature can be enabled or disabled through the Accessibility Options control panel.
          static property_<bool, readonly_> HighContrast;

          /// @brief Gets the thickness of the left and right edges of the system focus rectangle, in pixels.
          /// @return int32 The thickness of the left and right edges of the system focus rectangle, in pixels.
          /// @exception NotSupportedException The operating system does not support this feature.
          /// @remarks The HorizontalFocusThickness property indicates the width of the left and right edges of the system focus rectangle, in pixels. The system focus rectangle is used to draw user's attention to a window or area by displaying a rectangular highlighted outline.
          static property_<int32, readonly_> HorizontalFocusThickness;

          /// @brief Gets the thickness of the left and right edges of the sizing border around the perimeter of a window being resized, in pixels.
          /// @return int32 The width of the left and right edges of the sizing border around the perimeter of a window being resized, in pixels.
          /// @remarks The HorizontalResizeBorderThickness property indicates the width of the vertical sizing border around the perimeter of a window being resized.
          static property_<int32, readonly_> HorizontalResizeBorderThickness;

          /// @brief Gets the width, in pixels, of the arrow bitmap on the horizontal scroll bar.
          /// @return int32 The width, in pixels, of the arrow bitmap on the horizontal scroll bar.
          static property_<int32, readonly_> HorizontalScrollBarArrowWidth;

          /// @brief Gets the default height, in pixels, of the horizontal scroll bar.
          /// @return int32 The default height, in pixels, of the horizontal scroll bar.
          static property_<int32, readonly_> HorizontalScrollBarHeight;

          /// @brief Gets the width, in pixels, of the scroll box in a horizontal scroll bar.
          /// @return int32 The width, in pixels, of the scroll box in a horizontal scroll bar.
          static property_<int32, readonly_> HorizontalScrollBarThumbWidth;

          /// @brief Gets the width, in pixels, of an icon arrangement cell in large icon view.
          /// @return int32 The width, in pixels, of an icon arrangement cell in large icon view.
          /// @remarks The IconHorizontalSpacing property indicates the width of the space for an icon in large icon view. The system uses this distance to arrange icons in large icon view.
          static property_<int32, readonly_> IconHorizontalSpacing;

          /// @brief Gets the dimensions, in pixels, of the Windows default program icon size.
          /// @return System::Drawing::Size A Size that indicates the default dimensions, in pixels, for a program icon.
          static property_<System::Drawing::Size, readonly_> IconSize;

          /// @brief Gets the size, in pixels, of the grid square used to arrange icons in a large-icon view.
          /// @return System::Drawing::Size A Size that specifies the dimensions, in pixels, of the grid square used to arrange icons in a large-icon view.
          /// @remarks The IconSpacingSize property indicates the size of the grid rectangle that each icon fits into when the system arranges them in a large-icon view. This value is always greater than or equal to IconSize.
          static property_<System::Drawing::Size, readonly_> IconSpacingSize;

          /// @brief Gets the height, in pixels, of an icon arrangement cell in large icon view.
          /// @return int32 The height, in pixels, of an icon arrangement cell in large icon view.
          /// @remarks The IconVerticalSpacing property indicates the width of the space for an icon in large icon view. The system uses this distance to arrange icons in large icon view.
          static property_<int32, readonly_> IconVerticalSpacing;

          /// @brief Gets a value indicating whether active window tracking is enabled.
          /// @return bool true if active window tracking is enabled; otherwise, false.
          /// @remarks The IsActiveWindowTrackingEnabled property indicates whether active window tracking is enabled. Active window tracking causes any window the mouse is directly over to become the active window.
          static property_<bool, readonly_> IsActiveWindowTrackingEnabled;

          /// @brief Gets a value indicating whether the slide-open effect for combo boxes is enabled.
          /// @return bool true if the slide-open effect for combo boxes is enabled; otherwise, false.
          /// @remarks The IsComboBoxAnimationEnabled property indicates whether the slide-open effect for system control combo boxes is enabled.
          /// @remarks When the slide-open effect for system control combo boxes is enabled, the drop down menu of a combo box slides into view when it is displayed, instead of being immediately fully drawn in view.
          static property_<bool, readonly_> IsComboBoxAnimationEnabled;

          /// @brief Gets a value indicating whether the drop shadow effect is enabled.
          /// @return bool true if the drop shadow effect is enabled; otherwise, false.
          static property_<bool, readonly_> IsDropShadowEnabled;

          /// @brief Gets a value indicating whether native user menus have a flat menu appearance.
          /// @return bool true if native user menus have a flat menu appearance; otherwise, false.
          static property_<bool, readonly_> IsFlatMenuEnabled;

          /// @brief Gets a value indicating whether font smoothing is enabled.
          /// @return bool true if the font smoothing feature is enabled; otherwise, false.
          /// @remarks This font smoothing feature uses font antialiasing to make font curves appear smoother by painting pixels at different gray levels.
          static property_<bool, readonly_> IsFontSmoothingEnabled;

          /// @brief Gets a value indicating whether hot tracking of user-interface elements, such as menu names on menu bars, is enabled.
          /// @return bool true if hot tracking of user-interface elements is enabled; otherwise, false.
          /// @remarks The IsHotTrackingEnabled property indicates whether hot tracking of user-interface elements is enabled. Hot tracking means that when the cursor moves over an item, it is highlighted but not selected.
          static property_<bool, readonly_> IsHotTrackingEnabled;

          /// @brief Gets a value indicating whether icon-title wrapping is enabled.
          /// @return bool true if the icon-title wrapping feature is enabled; otherwise, false.
          static property_<bool, readonly_> IsIconTitleWrappingEnabled;

          /// @brief Gets a value indicating whether the user relies on the keyboard instead of the mouse, and prefers applications to display keyboard interfaces that would otherwise be hidden.
          /// @return bool true if keyboard preferred mode is enabled; otherwise, false.
          /// @remarks The IsKeyboardPreferred property indicates whether the user has indicated a preference for keyboard-based input interfaces.
          static property_<bool, readonly_> IsKeyboardPreferred;

          /// @brief Gets a value indicating whether the smooth-scrolling effect for list boxes is enabled.
          /// @return bool true if smooth-scrolling is enabled; otherwise, false.
          /// @remarks The IsListBoxSmoothScrollingEnabled property indicates whether the smooth-scrolling effect for system control list boxes is enabled.
          static property_<bool, readonly_> IsListBoxSmoothScrollingEnabled;

          /// @brief Gets a value indicating whether menu fade or slide animation features are enabled.
          /// @return bool true if menu fade or slide animation is enabled; otherwise, false.
          /// @remarks The IsMenuAnimationEnabled property indicates whether either of the fade or slide animation features of system control menus is enabled.
          /// @remarks If the value of this property is true, the IsMenuFadeEnabled property indicates whether menus use fade or slide animation.
          static property_<bool, readonly_> IsMenuAnimationEnabled;

          /// @brief Gets a value indicating whether menu fade animation is enabled.
          /// @return bool true if fade animation is enabled; false if it is disabled.
          /// @remarks The IsMenuFadeEnabled property indicates whether a menu uses fade animation, if menu animation is enabled. The IsMenuAnimationEnabled property indicates whether menu animation is enabled.
          /// @remarks If menu animation is enabled and the value of this property is true, menus use fade animation. If menu animation is enabled and the value of this property is false, menus use slide animation. If menu animation is disabled, the value of this property is meaningless.
          static property_<bool, readonly_> IsMenuFadeEnabled;

          /// @brief Gets a value indicating whether window minimize and restore animation is enabled.
          /// @return bool true if window minimize and restore animation is enabled; otherwise, false.
          /// @remarks The IsMinimizeRestoreAnimationEnabled property indicates whether the window minimize and restore sequence is animated.
          static property_<bool, readonly_> IsMinimizeRestoreAnimationEnabled;

          /// @brief Gets a value indicating whether the selection fade effect is enabled.
          /// @return bool true if the selection fade effect is enabled; otherwise, false.
          /// @remarks The IsSelectionFadeEnabled property indicates whether the selection fade effect is enabled. The selection fade effect causes a menu item selected by the user to remain on the screen briefly while fading out after the menu is dismissed.
          static property_<bool, readonly_> IsSelectionFadeEnabled;

          /// @brief Gets a value indicating whether the selection fade effect is enabled.
          /// @return bool true if the selection fade effect is enabled; otherwise, false.
          /// @remarks The IsSelectionFadeEnabled property indicates whether the selection fade effect is enabled. The selection fade effect causes a menu item selected by the user to remain on the screen briefly while fading out after the menu is dismissed.
          static property_<bool, readonly_> IsSnapToDefaultEnabled;

          /// @brief Gets a value indicating whether the selection fade effect is enabled.
          /// @return bool true if the selection fade effect is enabled; otherwise, false.
          /// @remarks The IsSelectionFadeEnabled property indicates whether the selection fade effect is enabled. The selection fade effect causes a menu item selected by the user to remain on the screen briefly while fading out after the menu is dismissed.
          static property_<bool, readonly_> IsTitleBarGradientEnabled;

          /// @brief Gets a value indicating whether the selection fade effect is enabled.
          /// @return bool true if the selection fade effect is enabled; otherwise, false.
          /// @remarks The IsSelectionFadeEnabled property indicates whether the selection fade effect is enabled. The selection fade effect causes a menu item selected by the user to remain on the screen briefly while fading out after the menu is dismissed.
          static property_<bool, readonly_> IsToolTipAnimationEnabled;

          /// @brief Gets the height, in pixels, of the Kanji window at the bottom of the screen for double-byte character set (DBCS) versions of Windows.
          /// @return int32 The height, in pixels, of the Kanji window.
          /// @remarks The KanjiWindowHeight property indicates the height of the Kanji window on operating systems that support DBCS. The DbcsEnabled property indicates whether the operating system supports DBCS.
          static property_<int32, readonly_> KanjiWindowHeight;

          /// @brief Gets the keyboard repeat-delay setting.
          /// @return int32 The keyboard repeat-delay setting, from 0 (approximately 250 millisecond delay) through 3 (approximately 1 second delay).
          /// @remarks This property indicates the amount of time that elapses after a key is pressed and held down until keystroke repeat messages are sent by the operating system. This value is in the range from 0 (approximately 250 millisecond delay) through 3 (approximately 1 second delay). The actual delay associated with each value may vary depending on the hardware.
          /// @remarks The KeyboardSpeed property indicates the repeat speed setting that determines the length of time between each keystroke repeat message sent by the operating system.
          static property_<int32, readonly_> KeyboardDelay;

          /// @brief Gets the keyboard repeat-speed setting.
          /// @return int32 The keyboard repeat-speed setting, from 0 (approximately 2.5 repetitions per second) through 31 (approximately 30 repetitions per second).
          /// @remarks This property indicates the time between each keystroke repeat message that is sent when a user presses and holds a key down. This is a value in the range from 0 (approximately 2.5 repetitions per second) through 31 (approximately 30 repetitions per second). The actual repeat rates are hardware-dependent and may vary from a linear scale by as much as 20%.
          /// @remarks The KeyboardDelay property indicates the length of time after a key is pressed and held down before keystroke repeat messages are sent by the operating system.
          static property_<int32, readonly_> KeyboardSpeed;

          /// @brief Gets the default maximum dimensions, in pixels, of a window that has a caption and sizing borders.
          /// @return System::Drawing::Size A Size that specifies the maximum dimensions, in pixels, to which a window can be sized.
          /// @remarks The MaxWindowTrackSize property indicates the maximum dimensions to which a user can drag resize a window. The value returned by MaxWindowTrackSize refers to the dimensions of the entire desktop.
          static property_<System::Drawing::Size, readonly_> MaxWindowTrackSize;

          /// @brief Gets a value indicating whether menu access keys are always underlined.
          /// @return bool true if menu access keys are always underlined; false if they are underlined only when the menu is activated or receives focus.
          /// @remarks The MenuAccessKeysUnderlined property indicates whether the menu shortcut keys are underlined in menu text even when the menu has not been activated or received focus.
          static property_<bool, readonly_> MenuAccessKeysUnderlined;

          /// @brief Gets the default width, in pixels, for menu-bar buttons and the height, in pixels, of a menu bar.
          /// @return System::Drawing::Size A Size that indicates the default width for menu-bar buttons, in pixels, and the height of a menu bar, in pixels.
          /// @remarks The Size.Width value of this property indicates the default width for a button on a menu-bar, in pixels. The Size.Height value of this property indicates the height of a menu bar, in pixels.
          static property_<System::Drawing::Size, readonly_> MenuBarButtonSize;

          /// @brief Gets the default dimensions, in pixels, of menu-bar buttons.
          /// @return System::Drawing::Size A Size that indicates the default dimensions, in pixels, of menu-bar buttons.
          /// @remarks This property indicates the default dimensions, in pixels, for menu-bar buttons, such as the child window close button used in the multiple document interface.
          static property_<System::Drawing::Size, readonly_> MenuButtonSize;

          /// @brief Gets the dimensions, in pixels, of the default size of a menu check mark area.
          /// @return System::Drawing::Size A Size that indicates the default size, in pixels, of a menu check mark area.
          /// @remarks The MenuCheckSize property indicates the size of the image used by Windows to display a check mark area next to a selected menu item.
          static property_<System::Drawing::Size, readonly_> MenuCheckSize;

          /// @brief Gets the dimensions, in pixels, of the default size of a menu check mark area.
          /// @return System::Drawing::Size A Size that indicates the default size, in pixels, of a menu check mark area.
          /// @remarks The MenuCheckSize property indicates the size of the image used by Windows to display a check mark area next to a selected menu item.
          static property_<System::Drawing::Font, readonly_> MenuFont;

          /// @brief Gets the height, in pixels, of one line of a menu.
          /// @return int32 The height, in pixels, of one line of a menu.
          /// @remarks The MenuHeight property indicates the height that is currently defined by Windows for a menu bar.
          static property_<int32, readonly_> MenuHeight;
        };
      }
    }
  }
}

using namespace Switch;

/// @file
/// @brief Contains Switch::System::Console class.
#pragma once

#include "../Property.hpp"
#include "../Types.hpp"
#include "../RefPtr.hpp"
#include "../Static.hpp"
#include "Array.hpp"
#include "Char.hpp"
#include "ConsoleCancelEventHandler.hpp"
#include "ConsoleColor.hpp"
#include "ConsoleKeyInfo.hpp"
#include "IO/TextReader.hpp"
#include "IO/TextWriter.hpp"
#include "Text/Encoding.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents the standard input, output, and error streams for console applications.
    /// This class cannot be inherited.
    /// @par Examples
    /// The following example demonstrates how to read data from, and write data to, the standard input and output streams. Note that these streams can be redirected by using the SetIn and SetOut methods.
    /// @include Console.cpp
    /// @include ConsoleOut.cpp
    class core_export_ Console static_ {
    public:
      // @cond
      class StandardInput : public System::IO::TextReader {
      public:
        StandardInput() {}
        StandardInput(const StandardInput& in) { *this = in; }
        StandardInput& operator =(const StandardInput&) { return *this; }
      private:
        int32 Peek() const override {return std::cin.peek();}
        int32 Read() override {return std::cin.get();}
      };

      class StandardErrorOutput : public System::IO::TextWriter {
      public:
        StandardErrorOutput() {}
        StandardErrorOutput(const StandardErrorOutput& error) { *this = error; }
        StandardErrorOutput& operator =(const StandardErrorOutput&) { return *this; }
        void Flush() override {std::cerr.flush();}
      private:
        using TextWriter::Write;
        void Write(const System::String& s) override;
      };

      class StandardOutput : public System::IO::TextWriter {
      public:
        StandardOutput() {}
        StandardOutput(const StandardOutput& out) { *this = out; }
        StandardOutput& operator =(const StandardOutput&) { return *this; }
        void Flush() override {std::cout.flush();}
      private:
        using TextWriter::Write;
        void Write(const System::String& s) override;
      };
      /// @endcond

      /// @brief Gets or sets the background color of the console.
      /// @param A ConsoleColor that specifies the background color of the console; that is, the color that appears behind each character.
      /// @exception ArgumentException The color specified in a set operation is not a valid member of System::ConsoleColor.
      /// @exception IOException An I/O error occurred.
      /// @remarks A change to the BackgroundColor property affects only output that is written to individual character cells after the background color is changed. To change the background color of the console window as a whole, set the BackgroundColor property and call the Clear method. The following example provides an illustration.
      /// @include
      /// A get operation for a Windows-based application, in which a console does not exist, returns ConsoleColor.Black.
      /// @par Example
      /// The following example saves the values of the ConsoleColor enumeration to an array and stores the current values of the BackgroundColor and ForegroundColor properties to variables. It then changes the foreground color to each color in the ConsoleColor enumeration except to the color that matches the current background, and it changes the background color to each color in the ConsoleColor enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the ResetColor method to restore the original console colors.
      /// @include ConsoleColor4.cpp
      static property_<ConsoleColor> BackgroundColor;

      /// @brief Gets or sets the height of the buffer area.
      /// @param The current height, in rows, of the buffer area.
      /// @par Example
      /// This example demonstrates the BufferHeight and BufferWidth properties. The example reports the dimensions of an operating system window set to a buffer size of 300 rows and 85 columns.
      /// @include ConsoleBuffer.cpp
      static property_<int32> BufferHeight;

      /// @brief Gets or sets the width of the buffer area.
      /// @param The current width, in columns, of the buffer area.
      /// @par Example
      /// This example demonstrates the BufferHeight and BufferWidth properties. The example reports the dimensions of an operating system window set to a buffer size of 300 rows and 85 columns.
      /// @include ConsoleBuffer.cpp
      static property_<int32> BufferWidth;

      /// @brief Gets a value indicating whether the CAPS LOCK keyboard toggle is turned on or turned off.
      /// @param true if CAPS LOCK is turned on; false if CAPS LOCK is turned off.
      static property_<bool, readonly_> CapsLock;

      /// @brief Gets or sets the column position of the cursor within the buffer area.
      /// @param The current position, in columns, of the cursor.
      /// @exception ArgumentOutOfRangeException left less than 1 or greater than 80.
      /// @par Example
      /// This example demonstrates the CursorLeft and CursorTop properties, and the SetCursorPosition and Clear methods. The example positions the cursor, which determines where the next write will occur, to draw a 5 character by 5 character rectangle using a combination of "+", "|", and "-" strings. Note that the rectangle could be drawn with fewer steps using a combination of other strings.
      /// @include ConsoleCursor.cpp
      static property_<int32> CursorLeft;

      /// @brief Gets or sets the height of the cursor within a character cell.
      /// @param size The size of the cursor expressed as a percentage of the height of a character cell. The property value ranges from 1 to 100.
      /// @exception ArgumentOutOfRangeException size less than 1 or greater than 100.
      /// @par Example
      /// This example demonstrates the CursorSize property. The example increases the size of the cursor each time any console key is pressed, then restores the cursor to its original size before terminating.
      /// @include ConsoleCursorSize.cpp
      static property_<int32> CursorSize;

      /// @brief Gets or sets the row position of the cursor within the buffer area.
      /// @param int32 The current position, in rows, of the cursor.
      /// @exception ArgumentOutOfRangeException top less than 1 or greater than 25.
      /// @par Example
      /// This example demonstrates the CursorLeft and CursorTop properties, and the SetCursorPosition and Clear methods. The example positions the cursor, which determines where the next write will occur, to draw a 5 character by 5 character rectangle using a combination of "+", "|", and "-" strings. Note that the rectangle could be drawn with fewer steps using a combination of other strings.
      /// @include ConsoleCursor.cpp
      static property_<int32> CursorTop;

      /// @brief Gets or sets a value indicating whether the cursor is visible.
      /// @param true if the cursor is visible; otherwise, false.
      /// @par Example
      /// This example demonstrates the CursorVisible property. The example makes the cursor visible if the first column of input is a '+' character or invisible if the input is a '-' character.
      /// @include ConsoleCursorVisible.cpp
      static property_<bool> CursorVisible;

      /// @brief Gets the standard error outpout stream.
      /// @param A TextWriter that represents the standard error output stream.
      static property_<StandardErrorOutput&, readonly_> Error;

      /// @brief Gets or sets the foreground color of the console.
      /// @param A ConsoleColor that specifies the foreground color of the console; that is, the color of each character that is displayed.
      /// @par Example
      /// The following example saves the values of the ConsoleColor enumeration to an array and stores the current values of the BackgroundColor and ForegroundColor properties to variables. It then changes the foreground color to each color in the ConsoleColor enumeration except to the color that matches the current background, and it changes the background color to each color in the ConsoleColor enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the ResetColor method to restore the original console colors.
      /// @include ConsoleColor4.cpp
      static property_<ConsoleColor> ForegroundColor;

      /// @brief Gets the standard input stream.
      /// @param A TextReader that represents the standard input stream.
      /// @par Example
      /// The following sample illustrates the use of the In property.
      /// @include ConsoleInOut.cpp
      static property_<StandardInput&, readonly_> In;

      /// @brief Gets or sets the encoding the console uses to read input.
      /// @param The encoding used to read console input.
      static property_<const refptr<System::Text::Encoding>&> InputEncoding;

      /// @brief Gets a value that indicates whether the error output stream has been redirected from the standard error stream.
      /// @param true if error output is redirected; otherwise, false.
      static property_<bool, readonly_> IsErrorRedirected;

      /// @brief  Gets a value that indicates whether the input stream has been redirected from the standard input stream.
      /// @param true if input is redirected; otherwise, false.
      static property_<bool, readonly_> IsInputRedirected;

      /// @brief  Gets a value that indicates whether the output stream has been redirected from the standard output stream.
      /// @param true if output is redirected; otherwise, false.
      static property_<bool, readonly_> IsOutputRedirected;

      /// @brief Gets a value indicating whether a key press is available in the input stream.
      /// @param true if a key press is available; otherwise, false
      /// @remarks The KeyAvailable method is returned immediately; that is, the KeyAvailable method does not block input until a key press is available.
      /// @remarks Use the KeyAvailable method in conjunction with only the ReadKey method, not the Read or ReadLine methods
      /// @par Example
      /// The following example demonstrates how to use the KeyAvailable property to create a loop that runs until a key is pressed.
      /// @include ConsoleKeyAvaible.cpp
      static property_<bool, readonly_> KeyAvailable;

      /// @brief Gets the largest possible number of console window rows, based on the current font and screen resolution.
      /// @param The height of the largest possible console window measured in rows.
      static property_<int32, readonly_> LargestWindowHeight;

      /// @brief Gets the largest possible number of console window columns, based on the current font and screen resolution.
      /// @param The width of the largest possible console window measured in colomns.
      static property_<int32, readonly_> LargestWindowWidth;

      /// @brief Gets a value indicating whether the NUM LOCK keyboard toggle is turned on or turned off.
      /// @param true if NUM LOCK is turned on; false if NUM LOCK is turned off.
      static property_<bool, readonly_> NumberLock;

      /// @brief Gets the standard output stream.
      /// @param A TextWriter that represents the standard output stream.
      static property_<StandardOutput&, readonly_> Out;

      /// @brief Gets the encoding the console uses to write output.
      /// @param The encoding used to write console output.
      static property_<const refptr<System::Text::Encoding>&> OutputEncoding;

      /// @brief Gets or sets the title to display in the console title bar.
      /// @param The string to be displayed in the title bar of the console. The maximum length of the title string is 24500 characters.
      /// @par Example
      /// This example demonstrates the Title property. The example displays the current title of the operating system window, waits for a key press, then displays a new title.
      /// @include ConsoleTitle.cpp
      static property_<string> Title;

      /// @brief Gets or sets a value indicating whether the combination of the Control modifier key and C console key (Ctrl+C) is treated as ordinary input or as an interruption that is handled by the operating system.
      /// @param bool true if Ctrl+C is treated as ordinary input; otherwise, false.
      /// @remarks If the value of the TreatControlCAsInput property is false and Ctrl+C is pressed, the pressed keys are not stored in the input buffer and the operating system terminates the currently executing process. This is the default value.
      /// @warning Use this property judiciously because setting it to true has such a dramatic effect. Most users expect Ctrl+C to terminate a console application. If you disable the effect of Ctrl+C, the user must remember to use Ctrl+Break to terminate the application, which is a less familiar key combination.
      static property_<bool> TreatControlCAsInput;

      /// @brief Gets or sets the height of the console window area.
      /// @param The height of the console window measured in rows.
      /// @par Example
      /// This example demonstrates the SetWindowSize method, and the WindowWidth and WindowHeight properties. You must run the example to see the full effect of changing the console window size.
      /// The example reports the dimensions of a console window set to 85 columns and 43 rows, then waits for a key press. When any key is pressed, the dimensions of the console window are halved, the new dimensions are reported, and the example waits for another key press. Finally, when any key is pressed the console window is restored to its original dimensions and the example terminates.
      /// @include ConsoleWindowSize.cpp
      static property_<int32> WindowHeight;

      /// @brief Gets or sets the leftmost position of the console window area relative to the screen buffer.
      /// @param The leftmost console window position measured in columns.
      static property_<int32> WindowLeft;

      /// @brief Gets or sets the top position of the console window area relative to the screen buffer.
      /// @param The uppermost console window position measured in rows.
      static property_<int32> WindowTop;

      /// @brief Gets or sets the width of the console window.
      /// @param The width of the console window measured in columns.
      /// @par Example
      /// This example demonstrates the SetWindowSize method, and the WindowWidth and WindowHeight properties. You must run the example to see the full effect of changing the console window size.
      /// The example reports the dimensions of a console window set to 85 columns and 43 rows, then waits for a key press. When any key is pressed, the dimensions of the console window are halved, the new dimensions are reported, and the example waits for another key press. Finally, when any key is pressed the console window is restored to its original dimensions and the example terminates.
      /// @include ConsoleWindowSize.cpp
      static property_<int32> WindowWidth;

      /// @brief Plays the sound of a beep through the console speaker.
      /// @remarks By default, the beep plays at a frequency of 800 hertz for a duration of 200 milliseconds
      static void Beep() {Beep(800, 200);}

      /// @brief Plays the sound of a beep of a specified frequency and duration through the console speaker.
      /// @param frequency The frequency of the beep, ranging from 37 to 32767 hertz
      /// @param duration The duration of the beep measured in milliseconds
      static void Beep(int32 frequency, int32 duration);

      /// @brief Clears the console buffer and corresponding console window of display information.
      /// @remarks Using the Clear method is equivalent invoking the MS-DOS cls command in the command prompt window.
      /// @remarks When the Clear method is called, the cursor automatically scrolls to the top-left corner of the window and the contents of the screen buffer are set to blanks using the current foreground background colors.
      /// @par Example
      /// The following example uses the Clear method to clear the console before it executes a loop, prompts the user to select a foreground and background color and to enter a string to display. If the user chooses not to exit the program, the console's original foreground and background colors are restored and the Clear method is called again before re-executing the loop.
      /// @include ConsoleClear.cpp
      /// The example relies on a GetKeyPress method to validate the user's selection of a foreground and background color.
      ///
      /// This example demonstrates the CursorLeft and CursorTop properties, and the SetCursorPosition and Clear methods. The example positions the cursor, which determines where the next write will occur, to draw a 5 character by 5 character rectangle using a combination of "+", "|", and "-" strings. Note that the rectangle could be drawn with fewer steps using a combination of other strings.
      /// @include ConsoleCursor.cpp
      static void Clear();

      static void MoveBufferArea(int32 sourceLeft, int32 sourceTop, int32 sourceWidth, int32 sourceHeight, int32 targetLeft, int32 targetTop) {
        MoveBufferArea(sourceLeft, sourceTop, sourceWidth, sourceHeight, targetLeft, targetTop, ' ', Console::BackgroundColor, Console::ForegroundColor);
      }

      static void MoveBufferArea(int32 sourceLeft, int32 sourceTop, int32 sourceWidth, int32 sourceHeight, int32 targetLeft, int32 targetTop, char32 sourceChar, ConsoleColor sourceForeColor, ConsoleColor sourceBackColor);

      /// @brief Reads the next character from the standard input stream.
      /// @return int32 The next character from the input stream, or negative one (-1) if there are currently no more characters to be read
      /// @remarks The Read method blocks its return while you type input characters; it terminates when you press the Enter key.
      /// @remarks Pressing Enter appends a platform-dependent line termination sequence to your input (for example, Windows appends a carriage return-linefeed sequence).
      /// @remarks Subsequent calls to the Read method retrieve your input one character at a time. After the final character is retrieved, Read blocks its return again and the cycle repeats.
      /// @remarks Note that you will not get a property value of -1 unless you perform one of the following actions: simultaneously press the Control modifier key and Z console key (CTRL+Z),
      /// @remarks which signals the end-of-file condition; press an equivalent key that signals the end-of-file condition, such as the F6 function key in Windows; or redirect the input stream to a source,
      /// @remarks such as a text file, that has an actual end-of-file character.
      /// @par Example
      /// The following example demonstrates the Read method.
      /// @include ConsoleRead.cpp
      static int32 Read();

      /// @brief Reads the next line of characters from the standard input stream.
      static String ReadLine();

      /// @brief Obtains the next character or function key pressed by the user. The pressed key is displayed in the console window.
      /// @return ConsoleKeyInfo A ConsoleKeyInfo object that describes the ConsoleKey constant and Unicode character, if any, that correspond to the pressed console key.
      /// The ConsoleKeyInfo object also describes, in a bitwise combination of ConsoleModifiers values, whether one or more SHIFT, ALT, or CTRL modifier keys was pressed simultaneously with the console key.
      static ConsoleKeyInfo ReadKey();

      /// @brief Obtains the next character or function key pressed by the user. The pressed key is optionally displayed in the console window.
      /// @param intercept Determines whether to display the pressed key in the console window. true to not display the pressed key; otherwise, false
      /// @return ConsoleKeyInfo A ConsoleKeyInfo object that describes the ConsoleKey constant and Unicode character, if any, that correspond to the pressed console key.
      /// The ConsoleKeyInfo object also describes, in a bitwise combination of ConsoleModifiers values, whether one or more SHIFT, ALT, or CTRL modifier keys was pressed simultaneously with the console key.
      static ConsoleKeyInfo ReadKey(bool intercept);

      /// @brief Sets the foreground and background console colors to their defaults.
      /// @remarks The foreground and background colors are restored to the colors that existed when the current process began.
      /// @remarks For more information, see the GetForegroundColor() and GetBackgroundColor() properties
      /// @par Example
      /// The following example saves the values of the ConsoleColor enumeration to an array and stores the current values of the BackgroundColor and ForegroundColor properties to variables. It then changes the foreground color to each color in the ConsoleColor enumeration except to the color that matches the current background, and it changes the background color to each color in the ConsoleColor enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the ResetColor method to restore the original console colors.
      /// @include ConsoleColor4.cpp
      static void ResetColor();

      /// @brief Sets the position of the cursor.
      /// @param left The column position of the cursor.
      /// @param top The row position of the cursor.
      /// @exception ArgumentOutOfRangeException left less than 0 or greater than WindowWidth  - or -  top less than 1 or greater than WindowHeighr.
      /// @par Example
      /// This example demonstrates the CursorLeft and CursorTop properties, and the SetCursorPosition and Clear methods. The example positions the cursor, which determines where the next write will occur, to draw a 5 character by 5 character rectangle using a combination of "+", "|", and "-" strings. Note that the rectangle could be drawn with fewer steps using a combination of other strings.
      /// @include ConsoleCursor.cpp
      static void SetCursorPosition(int32 left, int32 top);

      /// @brief Sets the position of the console window relative to the screen buffer.
      /// @param left The column position of the upper left corner of the console window.
      /// @param top The row position of the upper left corner of the console window.
      static void SetWindowPosition(int32 left, int32 top) {
        Console::WindowLeft = left;
        Console::WindowTop = top;
      }

      /// @brief Sets the height and width of the console window to the specified values.
      /// @param width The width of the console window measured in columns.
      /// @param height The height of the console window measured in rows.
      /// @exception ArgumentOutOfRangeException width or height is less than or equal to zero.  -or-  width plus WindowLeft or height plus WindowTop is greater than or equal to Int16.MaxValue.  -or-  width or height is greater than the largest possible window width or height for the current screen resolution and console font.
      /// @par Example
      /// This example demonstrates the SetWindowSize method, and the WindowWidth and WindowHeight properties. You must run the example to see the full effect of changing the console window size.
      /// The example reports the dimensions of a console window set to 85 columns and 43 rows, then waits for a key press. When any key is pressed, the dimensions of the console window are halved, the new dimensions are reported, and the example waits for another key press. Finally, when any key is pressed the console window is restored to its original dimensions and the example terminates.
      /// @include ConsoleWindowSize.cpp
      static void SetWindowSize(int32 width, int32 height) {
        Console::WindowWidth = width;
        Console::WindowHeight = height;
      }

      /// @brief Writes the specified bool value to the standard output stream.
      /// @param value The value to write
      static void Write(bool value);

      /// @brief Writes the specified char value to the standard output stream.
      /// @param value The value to write
      static void Write(char value);

      /// @brief Writes the specified char32 value to the standard output stream.
      /// @param value The value to write
      static void Write(char32 value);

      /// @brief Writes the specified double value to the standard output stream.
      /// @param value The value to write
      static void Write(double value);

      /// @brief Writes the specified int32 value to the standard output stream.
      /// @param value The value to write
      static void Write(int32 value);

      /// @brief Writes the specified int64 value to the standard output stream.
      /// @param value The value to write
      static void Write(int64 value);

      /// @brief Writes the specified object value to the standard output stream.
      /// @param value The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void Write(const object& value);

      /// @brief Writes the specified single value to the standard output stream.
      /// @param value The value to write
      static void Write(float value);

      /// @brief Writes the specified String value to the standard output stream.
      /// @param value The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void Write(const String& value);

      /// @brief Writes the specified Uint32 value to the standard output stream.
      /// @param value The value to write
      static void Write(uint32 value);

      /// @brief Writes the specified UInt64 value to the standard output stream.
      /// @param value The value to write
      static void Write(uint64 value);

      static void Write(const String& format, const Array<ref<Object>>& array) {
        Write(String::Format(format, array));
      }

      /// @cond
      static void Write(char16 value);
      static void Write(wchar value);
      static void Write(const char value[]);
      static void Write(const char16 value[]);
      static void Write(const char32 value[]);
      static void Write(const wchar value[]);
      static void Write(unsigned char* value);
      static void Write(llong value);
      static void Write(ullong value);
      template<typename ...Args>
      static void Write(const String& format, const Args& ...args) {
        Write(String::Format(format, args...));
      }
      /// @endcond

      /// @brief Writes the current line terminator to the standard output stream.
      static void WriteLine();

      /// @brief Writes the specified bool value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(bool value);

      /// @brief Writes the specified char value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(char value);

      /// @brief Writes the specified char32 value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(char32 value);

      /// @brief Writes the specified double value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(double value);

      /// @brief Writes the specified int32 value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(int32 value);

      /// @brief Writes the specified int64 value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(int64 value);

      /// @brief Writes the specified object value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void WriteLine(const object& value);

      /// @brief Writes the specified single value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(float value);

      /// @brief Writes the specified String value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      /// @exception ArgumentNullException The parameters value is null.
      static void WriteLine(const String& value);

      /// @brief Writes the specified uint32 value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(uint32 value);

      /// @brief Writes the specified UInt64 value, followed by the current line terminator, to the standard output stream.
      /// @param value The value to write
      static void WriteLine(uint64 value);


      static void WriteLine(const String& format, const Array<ref<Object>>& array) {
        WriteLine(String::Format(format, array));
      }

      /// @cond
      static void WriteLine(char16 value);
      static void WriteLine(wchar value);
      static void WriteLine(const char value[]);
      static void WriteLine(const char16 value[]);
      static void WriteLine(const char32 value[]);
      static void WriteLine(const wchar value[]);
      static void WriteLine(llong value);
      static void WriteLine(ullong value);
      template<typename ...Args>
      static void WriteLine(const String& format, const Args& ...args) {
        WriteLine(String::Format(format, args...));
      }
      /// @endcond

      static void SetError(System::IO::TextWriter& error);

      static void SetInt(System::IO::TextReader& in);

      static void SetOut(System::IO::TextWriter& out);

      /// @brief Occurs when the Control modifier key (Ctrl) and either the ConsoleKey.C console key (C) or the Break key are pressed simultaneously (Ctrl+C or Ctrl+Break).
      /// @remarks This event is used in conjunction with System::ConsoleCancelEventHandler and System::ConsoleCancelEventArgs. The CancelKeyPress event enables a console application to intercept the Ctrl+C signal so the event handler can decide whether to continue executing or terminate. For more information about handling events, see Handling and Raising Events.
      /// When the user presses either Ctrl+C or Ctrl+Break, the CancelKeyPress event is fired and the application's ConsoleCancelEventHandler event handler is executed. The event handler is passed a ConsoleCancelEventArgs object that has two useful properties:
      /// * SpecialKey, which allows you to determine whether the handler was invoked as a result of the user pressing Ctrl+C (the property value is ConsoleSpecialKey.ControlC) or Ctrl+Break (the property value is ConsoleSpecialKey.ControlBreak).
      /// * Cancel, which allows you to determine how to your application should respond to the user pressing Ctrl+C or Ctrl+Break. By default, the Cancel property is false, which causes program execution to terminate when the event handler exits. Changing its property to true specifies that the application should continue to execute.
      /// @note If your application has simple requirements, you can use the TreatControlCAsInput property instead of this event. By setting this property to false, you can ensure that your application always exits if the user presses Ctrl+C. By setting it to true, you can ensure that pressing Ctrl+C will not terminate the application.
      static ConsoleCancelEventHandler CancelKeyPress;

      /// @cond
      static void __f();
      /// @endcond
    };
  }
}

using namespace Switch;

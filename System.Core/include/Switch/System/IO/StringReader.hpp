/// @file
/// @brief Contains Switch::System::IO::StringReader class.
#pragma once

#include "../../Types.hpp"
#include "../String.hpp"
#include "TextReader.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Implements a TextReader that reads from a string.
      /// @remarks StringReader enables you to read a string synchronously or asynchronously. You can read a character at a time with the Read or the ReadAsync method, a line at a time using the ReadLine or the ReadLineAsync method and an entire string using the ReadToEnd or the ReadToEndAsync method.
      /// @par Examples
      /// The following code example demonstrates the creation of a continuous paragraph from a group of double-spaced sentences, and then the conversion of the paragraph back to the original text.
      /// @include StringReader.cpp
      class core_export_ StringReader: public TextReader {
      public:
        static StringReader& Null() {
          static StringReader nullStringReader("");
          return nullStringReader;
        }

        /// @brief Initializes a new instance of the StringReader class that reads from the specified string.
        /// @param s The string to which the StringReader should be initialized.
        StringReader(const String& s);

        /// @cond
        StringReader(const StringReader& sr);
        StringReader& operator =(const StringReader& sr);
        /// @endcond

        /// @brief Closes the StringReader.(Overrides TextReader.Close().)
        /// @remarks For an example of creating a file and writing text to a file, see How to: Write Text to a File. For an example of reading text from a file, see How to: Read Text from a File. For an example of reading from and writing to a binary file, see How to: Read and Write to a Newly Created Data File.
        /// @remarks This method overrides the Stream.Close method.
        /// @remarks This implementation of Close calls the Dispose method passing a true value.
        /// @remarks Flushing the stream will not flush its underlying encoder unless you explicitly call Close. Setting AutoFlush to true means that data will be flushed from the buffer to the stream, but the encoder state will not be flushed. This allows the encoder to keep its state (partial characters) so that it can encode the next block of characters correctly. This scenario affects UTF8 and UTF7 where certain characters can only be encoded after the encoder receives the adjacent character or characters.
        /// @remarks Following a call to Close, other methods might throw an exception.
        void Close() override;

        /// @brief Returns the next available character but does not consume it.(Overrides TextReader.Peek().)
        /// @return int32 An integer representing the next character to be read, or -1 if no more characters are available or the stream does not support seeking.
        /// @remarks The Peek method returns an integer value in order to determine whether the end of the file, or another error has occurred. This allows a user to first check if the returned value is -1 before casting it to a Char type.
        /// @remarks This method overrides the TextReader.Peek method.
        /// @remarks The current position of the StringReader is not changed by this operation.
        /// @remarks The following table lists examples of other typical or related I/O tasks.
        int32 Peek() const override;

        /// @brief Reads the next character from the input string and advances the character position by one character.(Overrides TextReader.Read().)
        /// @return int32 The next character from the underlying string, or -1 if no more characters are available.
        /// @remarks This method overrides the TextReader.Read method.
        /// @par Examples
        /// This code example is part of a larger example provided for the StringReader class.
        /// @code
        /// convertedCharacter = Convert.ToChar(intCharacter);
        /// if(convertedCharacter == '.') {
        ///   strWriter.Write(".\n\n");
        ///
        ///   // Bypass the spaces between sentences.
        ///   strReader.Read();
        ///   strReader.Read();
        /// }
        /// @endcode
        int32 Read() override;

        /// @brief Reads a line of characters from the current string and returns the data as a string.(Overrides TextReader.ReadLine().)
        /// @return string The next line from the current string, or null if the end of the string is reached.
        /// @remarks This method overrides the TextReader.ReadLine method.
        /// @remarks A line is defined as a sequence of characters followed by a line feed ("\n"), a carriage return ("\r"), or a carriage return immediately followed by a line feed ("\r\n"). The string that is returned does not contain the terminating carriage return or line feed. The returned value is null if the end of the string has been reached.
        /// @remarks If the current method throws an OutOfMemoryException, the reader's position in the underlying string is advanced by the number of characters the method was able to read, but the characters already read into the internal ReadLine buffer are discarded. Because the position of the reader in the string cannot be changed, the characters already read are unrecoverable, and can be accessed only by reinitializing the StringReader. To avoid such a situation, use the Read method and store the read characters in a preallocated buffer.
        /// @par Examples
        /// This code example is part of a larger example provided for the StringReader class.
        /// @code
        /// // From textReaderText, create a continuous paragraph
        /// // with two spaces between each sentence.
        /// string line, paragraph;
        /// StringReader strReader(textReaderText);
        /// while (strReader.Peek() != -1) {
        ///   line = strReader.ReadLine();
        ///   if (line != "") {
        ///     paragraph = paragraph + line + " ";
        ///   } else {
        ///     paragraph = paragraph + "\n";
        ///   }
        /// }
        /// Console::WriteLine("Modified text:\n\n{0}", paragraph);
        /// @endcode
        String ReadLine() override;

        /// @brief Reads all characters from the current position to the end of the string and returns them as a single string.(Overrides TextReader.ReadToEnd().)
        /// @return string The content from the current position to the end of the underlying string.
        /// @remarks This method overrides the TextReader.ReadToEnd method.
        /// @remarks If the current method throws an OutOfMemoryException, the reader's position in the underlying string is advanced by the number of characters the method was able to read, but the characters already read into the internal ReadToEnd buffer are discarded. Because the position of the reader in the string cannot be changed, the characters already read are unrecoverable, and can be accessed only by reinitializing the StringReader. To avoid such a situation, use the Read method and store the read characters in a preallocated buffer
        /// @par Examples
        /// This code example is part of a larger example provided for the TextReader class.
        /// @code
        /// static void ReadText(TextReader textReader) {
        ///   Console.WriteLine("From {0} - {1}", textReader.GetType().Name, textReader.ReadToEnd());
        /// }
        /// @endcode
        String ReadToEnd() override;

      protected:
        /// @cond
        bool closed = false;
        String input;
        System::Collections::Generic::Enumerator<char32> enumerator;
        bool finished = false;
        int32 position = 0;
        /// @endcond
      };
    }
  }
}

using namespace Switch;

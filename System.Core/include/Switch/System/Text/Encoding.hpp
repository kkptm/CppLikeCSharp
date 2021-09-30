/// @file
/// @brief Contains Switch::System::Text::Encoding class.
#pragma once

#include "../../Types.hpp"
#include "../../Abstract.hpp"
#include "../../RefPtr.hpp"
#include "../Array.hpp"
#include "../Object.hpp"
#include "../String.hpp"
#include "../Collections/Generic/Dictionary.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Text namespace contains classes that represent ASCII and Unicode character encodings; abstract base classes for converting blocks of characters to and from blocks of bytes; and a helper class that manipulates and formats String objects without creating intermediate instances of String.
    namespace Text {
      /// @brief Represents a character encoding
      class core_export_ Encoding abstract_ {
      public:
        static char Unknown() { return '?'; }

        /// @brief Creates an encoding for the ASCII (7-bit) character set.
        /// @return An encoding for the ASCII (7-bit) character set.
        static const refptr<Encoding> ASCII;

        /// @brief Creates an encoding for the UTF-8 format.
        /// @return An encoding for the UTF-8 format.
        static const refptr<Encoding> UTF8;

        /// @brief Creates an encoding for the UTF-16 format using the little endian byte order.
        /// @return An encoding for the UTF-16 format using the little endian byte order.
        static const refptr<Encoding> Unicode;

        /// @brief Creates an encoding for the UTF-16 format that uses the big endian byte order.
        /// @return An encoding object for the UTF-16 format that uses the big endian byte order.
        static const refptr<Encoding> BigEndianUnicode;

        /// @brief Creates an encoding for the UTF-16 format using the little endian byte order.
        /// @return An encoding for the UTF-16 format using the little endian byte order.
        static const refptr<Encoding> UTF16LE;

        /// @brief Creates an encoding for the UTF-16 format that uses the big endian byte order.
        /// @return An encoding object for the UTF-16 format that uses the big endian byte order.
        static const refptr<Encoding> UTF16BE;

        /// @brief Creates an encoding for the UTF-32 format using the little endian byte order.
        /// @return An encoding object for the UTF-32 format using the little endian byte order.
        static const refptr<Encoding> UTF32;

        /// @brief Gets an encoding for the operating system's current ANSI code page.
        /// @return An encoding for the operating system's current ANSI code page (currently 437).
        static const refptr<Encoding> Default;

        /// @brief Returns the encoding associated with the specified code page name.
        /// @param name The code page name of the preferred encoding. Possible values are listed in the Name column of the table that appears in the System::Text::Encoding class topic.
        /// @return The encoding associated with the specified code page.
        /// @exception System::ArgumentException name is not a valid code page name. or  The code page indicated by name is not supported by the underlying platform.
        static refptr<Encoding> CreateEncoding(int32 codePage);

        /// @brief Returns the encoding associated with the specified code page name.
        /// @param name The code page name of the preferred encoding. Possible values are listed in the Name column of the table that appears in the System::Text::Encoding class topic.
        /// @return The encoding associated with the specified code page.
        /// @exception System::ArgumentException name is not a valid code page name. or  The code page indicated by name is not supported by the underlying platform.
        static refptr<Encoding> CreateEncoding(const String& codePageName);

        /// @brief When overridden in a derived class, gets the code page identifier of the current System::Text::Encoding.
        /// @return The code page identifier of the current System::Text::Encoding.
        virtual int32 GetCodePage() const;

        /// @brief When overridden in a derived class, gets the human-readable description of the current encoding.
        /// @return The human-readable description of the current System::Text::Encoding.
        virtual String GetEncodingName() const;

        /// @brief When overridden in a derived class, gets a value indicating whether the current encoding is read-only.
        /// @return true if the current System::Text::Encoding is read-only; otherwise, false.
        ///         The default is true.
        bool IsReadOnly() const { return true; }

        /// @brief When overridden in a derived class, gets a value indicating whether the current encoding uses single-byte code points.
        /// @return true if the current System::Text::Encoding uses single-byte code points; otherwise,
        ///         false.
        virtual bool IsSingleByte() const = 0;

        /// @brief Converts an entire byte array from one encoding to another.
        /// @param srcEncoding The encoding format of bytes.
        /// @param dstEncoding The target encoding format.
        /// @param bytes The bytes to convert.
        /// @return An array of type System::Byte containing the results of converting bytes from srcEncoding to dstEncoding.
        /// @exception System::ArgumentNullException srcEncoding is null. -or- dstEncoding is null. -or- bytes is null.
        static Array<byte> Convert(const Encoding& srcEncoding, const Encoding& dstEncoding, const byte bytes[], int32 bytesSize);

        /// @brief Converts a range of bytes in a byte array from one encoding to another.
        /// @param srcEncoding The encoding of the source array, bytes.
        /// @param dstEncoding The encoding of the output array.
        /// @param bytes The array of bytes to convert.
        /// @param index The index of the first element of bytes to convert.
        /// @param count The number of bytes to convert.
        /// @return An array of type System::Byte containing the result of converting a range of bytes in bytes from srcEncoding to dstEncoding.
        /// @exception System::ArgumentNullException srcEncoding is null. -or- dstEncoding is null. -or- bytes is null.
        /// @exception System::ArgumentOutOfRangeException index and count do not specify a valid range in the byte array.
        static Array<byte> Convert(const Encoding& srcEncoding, const Encoding& dstEncoding, const byte bytes[], int32 bytesSize, int32 index, int32 count);

        /// @brief Determines whether the specified System::Object is equal to the current instance.
        /// @param value The System::Object to compare with the current instance.
        /// @return true if value is an instance of System::Text::Encoding and is equal to the current instance; otherwise, false.
        bool Equals(const object& obj) const override;

        /// @brief When overridden in a derived class, calculates the number of bytes produced
        /// by encoding all the characters in the specified character array.
        /// @param chars The character array containing the characters to encode.
        /// @return The number of bytes produced by encoding all the characters in the specified character array.
        /// @exception System::ArgumentNullException chars is null.
        int32 GetByteCount(const char32 chars[], int32 charsSize) const;

        /// @brief When overridden in a derived class, calculates the number of bytes produced by encoding a set of characters from the specified character array.
        /// @param chars The character array containing the set of characters to encode.
        /// @param index The index of the first character to encode.
        /// @param count The number of characters to encode.
        /// @return The number of bytes produced by encoding the specified characters.
        /// @exception System::ArgumentNullException chars is null.
        int32 GetByteCount(const char32 chars[], int32 charsSize, int32 index, int32 count) const;

        /// @brief When overridden in a derived class, calculates the number of bytes produced by encoding the characters in the specified String.
        /// @param s The String containing the set of characters to encode.
        /// @return The number of bytes produced by encoding the specified characters.
        /// @exception System::ArgumentNullException s is null.
        int32 GetByteCount(const String& s) const;

        /// @brief When overridden in a derived class, calculates the number of bytes produced
        /// by encoding the character in the specified String.
        /// @param c The character to encode.
        /// @return The number of bytes produced by encoding the specified character.
        /// @exception System::ArgumentNullException s is null.
        virtual int32 GetByteCount(char32 c) const = 0;

        /// @brief When overridden in a derived class, encodes a character into a sequence of bytes.
        /// @param c The character to encode.
        /// @param index The index of the first character to encode.
        /// @param count The number of characters to encode.
        /// @return A byte array containing the results of encoding the specified character.
        /// @exception System::ArgumentNullException bytes is null.
        /// @exception System::ArgumentOutOfRangeException byteIndex is less than zero. -or- byteIndex is not a valid index in bytes.
        /// @exception System::ArgumentException bytes does not have enough capacity from byteIndex to the end of the array to accommodate the resulting bytes.
        virtual int32 GetBytes(char32 c, byte bytes[], int32 bytesSize, int32 byteIndex) const = 0;

        /// @brief When overridden in a derived class, encodes all the characters in the specified String into a sequence of bytes.
        /// @param s The String containing the characters to encode.
        /// @return A byte array containing the results of encoding the specified set of characters.
        /// @exception System::ArgumentNullException s is null.
        int32 GetBytes(const String& s, byte bytes[], int32 bytesSize) const;
        Array<byte> GetBytes(const String& s) const;

        /// @brief When overridden in a derived class, encodes all the characters in the specified character array into a sequence of bytes.
        /// @param chars The character array containing the characters to encode.
        /// @return A byte array containing the results of encoding the specified set of characters.
        /// @exception System::ArgumentNullException chars is null.
        int32 GetBytes(const char32 chars[], int32 charsSize, byte bytes[], int32 bytesSize) const;
        Array<byte> GetBytes(const char32 chars[], int32 charsSize) const;

        /// @brief When overridden in a derived class, encodes a set of characters from the specified character array into a sequence of bytes.
        /// @param chars The character array containing the set of characters to encode.
        /// @param index The index of the first character to encode.
        /// @param count The number of characters to encode.
        /// @return A byte array containing the results of encoding the specified set of characters.
        /// @exception System::ArgumentNullException chars is null.
        /// @exception System::ArgumentOutOfRangeException index or count is less than zero. or  index and count do not denote a valid range in chars.
        int32 GetBytes(const char32 chars[], int32 charsSize, int32 index, int32 count, byte bytes[], int32 bytesSize) const;
        Array<byte> GetBytes(const char32 chars[], int32 charsSize, int32 index, int32 count) const;

        /// @brief When overridden in a derived class, encodes a set of characters from the specified character array into the specified byte array.
        /// @param chars The character array containing the set of characters to encode.
        /// @param charIndex The index of the first character to encode.
        /// @param charCount The number of characters to encode.
        /// @param bytes The byte array to contain the resulting sequence of bytes.
        /// @param byteIndex The index at which to start writing the resulting sequence of bytes.
        /// @return The actual number of bytes written into bytes.
        /// @exception System::ArgumentNullException chars is null. or  bytes is null.
        /// @exception System::ArgumentOutOfRangeException charIndex or charCount or byteIndex is less than zero. or  charIndex and charCount do not denote a valid range in chars. or  byteIndex is not a valid index in bytes.
        /// @exception System::ArgumentException bytes does not have enough capacity from byteIndex to the end of the array to accommodate the resulting bytes.
        int32 GetBytes(const char32 chars[], int32 charsSize, int32 charIndex, int32 charCount, byte bytes[], int32 bytesSize, int32 byteIndex) const;

        /// @brief When overridden in a derived class, encodes a set of characters from the specified String into the specified byte array.
        /// @param s The String containing the set of characters to encode.
        /// @param charIndex The index of the first character to encode.
        /// @param charCount The number of characters to encode.
        /// @param bytes The byte array to contain the resulting sequence of bytes.
        /// @param byteIndex The index at which to start writing the resulting sequence of bytes.
        /// @return The actual number of bytes written into bytes.
        /// @exception System::ArgumentNullException s is null. -or- bytes is null.
        /// @exception System::ArgumentOutOfRangeException charIndex or charCount or byteIndex is less than zero. -or- charIndex and charCount do not denote a valid range in chars. -or- byteIndex is not a valid index in bytes.
        /// @exception System::ArgumentException bytes does not have enough capacity from byteIndex to the end of the array to accommodate the resulting bytes.
        int32 GetBytes(const String& s, int32 charIndex, int32 charCount, byte bytes[], int32 bytesLength, int32 byteIndex) const;
        Array<byte> GetBytes(const String& s, int32 index, int32 count) const;

        /// @brief When overridden in a derived class, calculates the number of characters produced by decoding all the bytes in the specified byte array.
        /// @param bytes The byte array containing the sequence of bytes to decode.
        /// @return The number of characters produced by decoding the specified sequence of bytes.
        /// @exception System::ArgumentNullException bytes is null.
        int32 GetCharCount(const byte bytes[], int32 bytesSize) const;

        /// @brief When overridden in a derived class, calculates the number of characters produced by decoding a sequence of bytes from the specified byte array.
        /// @param bytes The byte array containing the sequence of bytes to decode.
        /// @param index The index of the first byte to decode.
        /// @param count The number of bytes to decode.
        /// @return The number of characters produced by decoding the specified sequence of bytes.
        /// @exception System::ArgumentNullException bytes is null.
        /// @exception System::ArgumentOutOfRangeException index or count is less than zero. -or- index and count do not denote a valid range in bytes.
        virtual int32 GetCharCount(const byte bytes[], int32 bytesSize, int32 index, int32 count) const = 0;

        /// @brief When overridden in a derived class, decodes all the bytes in the specified byte array into a set of characters.
        /// @param bytes The byte array containing the sequence of bytes to decode.
        /// @return A character array containing the results of decoding the specified sequence of bytes.
        /// @exception System::ArgumentNullException bytes is null.
        Array<char32> GetChars(const byte bytes[], int32 bytesSize) const;
        int32 GetChars(const byte bytes[], int32 bytesSize, char32 chars[], int32 charsSize) const;

        /// @brief When overridden in a derived class, decodes a sequence of bytes from the specified byte array into a set of characters.
        /// @param bytes The byte array containing the sequence of bytes to decode.
        /// @param index The index of the first byte to decode.
        /// @param count The number of bytes to decode.
        /// @return A character array containing the results of decoding the specified sequence of bytes.
        /// @exception System::ArgumentNullException bytes is null.
        /// @exception System::ArgumentOutOfRangeException index or count is less than zero. -or- index and count do not denote a valid range in bytes.
        int32 GetChars(const byte bytes[], int32 bytesSize, int32 index, int32 count, char32 chars[], int32 charsSize) const;
        Array<char32> GetChars(const byte bytes[], int32 bytesSize, int32 index, int32 count) const;


        /// @brief When overridden in a derived class, decodes a sequence of bytes starting at the specified byte pointer into a set of characters that are stored starting at the specified character pointer.
        /// @param bytes A pointer to the first byte to decode.
        /// @param byteCount The number of bytes to decode.
        /// @param chars A pointer to the location at which to start writing the resulting set of characters.
        /// @param charCount The maximum number of characters to write.
        /// @return The actual number of characters written at the location indicated by the chars parameter.
        /// @exception System::ArgumentNullException bytes is null. or  chars is null.
        /// @exception System::ArgumentOutOfRangeException byteCount or charCount is less than zero.
        /// @exception System::ArgumentException charCount is less than the resulting number of characters.
        int32 GetChars(const byte bytes[], int32 bytesLength, int32 byteIndex, int32 byteCount, char32 chars[], int32 charsLength, int32 charIndex) const;

        /// @brief When overridden in a derived class, calculates the maximum number of bytes produced by encoding the specified number of characters.
        /// @param charCount The number of characters to encode.
        /// @return The maximum number of bytes produced by encoding the specified number of characters.
        /// @exception System::ArgumentOutOfRangeException charCount is less than zero.
        virtual int32 GetMaxByteCount(int32 charCount) const = 0;

        /// @brief When overridden in a derived class, calculates the maximum number of characters produced by decoding the specified number of bytes.
        /// @param byteCount The number of bytes to decode.
        /// @return The maximum number of characters produced by decoding the specified number of bytes.
        /// @exception System::ArgumentOutOfRangeException byteCount is less than zero.
        virtual int32 GetMaxCharCount(int32 byteCount) const = 0;

        /// @brief When overridden in a derived class, returns a sequence of bytes that specifies the encoding used.
        /// @return A byte array containing a sequence of bytes that specifies the encoding used. -or- A byte array of length zero, if a preamble is not required.
        virtual Array<byte> GetPreamble() const;

        /// @brief When overridden in a derived class, decodes all the bytes in the specified byte array into a String.
        /// @param bytes The byte array containing the sequence of bytes to decode.
        /// @return A String that contains the results of decoding the specified sequence of bytes.
        /// @exception System::ArgumentException The byte array contains invalid Unicode code points.
        /// @exception System::ArgumentNullException bytes is null.
        String GetString(const Array<byte>& bytes) const;

        /// @brief When overridden in a derived class, decodes all the bytes in the specified byte array into a String.
        /// @param bytes The byte array containing the sequence of bytes to decode.
        /// @return A String that contains the results of decoding the specified sequence of bytes.
        /// @exception System::ArgumentException The byte array contains invalid Unicode code points.
        /// @exception System::ArgumentNullException bytes is null.
        String GetString(const byte bytes[], int32 bytesSize) const;

        /// @brief When overridden in a derived class, decodes a sequence of bytes from the specified byte array into a String.
        /// @param bytes The byte array containing the sequence of bytes to decode.
        /// @param index The index of the first byte to decode.
        /// @param count The number of bytes to decode.
        /// @return A String that contains the results of decoding the specified sequence of bytes.
        /// @exception System::ArgumentException The byte array contains invalid Unicode code points.
        /// @exception System::ArgumentNullException bytes is null.
        /// @exception System::ArgumentOutOfRangeException index or count is less than zero. -or- index and count do not denote a valid range in bytes.
        String GetString(const byte bytes[], int32 bytesSize, int32 index, int32 count) const;

        /// @brief Gets a value indicating whether the current encoding is always normalized, using the default normalization form.
        /// @return true if the current System::Text::Encoding is always normalized; otherwise, false. The default is false.
        bool IsAlwaysNormalized() const;

        /// @brief Returns a String that represents the current object.
        /// @return a String that represents the current object.
        virtual String ToString() const override;

        /// @brief Initializes a new instance of the System::Text::Encoding class that corresponds to a copy of the specified encoding.
        /// @param encoding The encoding from which the copy is created.
        /// @exception System::ArgumentNullException encoding is null.
        Encoding(const Encoding& encoding);

        class Encoder abstract_ {
        public:
          Encoder() { }
          Encoder(const Encoder&) { }
          virtual ~Encoder() { }
          Encoder& operator=(const Encoder&);

          /// @brief Calculates the number of bytes needed to encode a given code point.
          /// @param c The given code point.
          /// @return The number of bytes needed to encode this code point.
          virtual int32 GetNbBytes(char32 c) const = 0;

          /// @brief Encodes the given code point into a sequence of bytes.
          /// @param c The given code point.
          /// @param bytes The destination buffer receiving the encoded bytes.
          virtual void Encode(char32 c, byte* bytes) const = 0;
          virtual String ToString() const = 0;
        };

        class Decoder abstract_ {
        public:
          Decoder();
          Decoder(const Decoder& cpb);
          virtual ~Decoder();
          Decoder& operator=(const Decoder& b);

          /// @brief Adds a new byte to the current sequence of encoded bytes.
          /// @param b The byte to add.
          virtual void Add(byte b);

          /// @brief Clears the current sequence of encoded bytes.
          virtual void Reset();

          /// @brief Tells if the current sequence of encoded bytes defines a code point.
          /// @return True if the code point is defined, false otherwise.
          bool CodePointDefined() { return finished; };

          /// @brief Gets the code point defined by the current sequence of encoded bytes.
          /// @return The defined code point.
          char32 CodePoint() const { return codePoint; }

          virtual String ToString() const = 0;

        protected:
          byte bytes[4];
          int32 count;
          bool finished;
          char32 codePoint;
        };

        //todo
        virtual refptr<Decoder> CreateDecoder() const = 0;
        virtual refptr<Encoder> CreateEncoder() const = 0;

      protected:
        /// @brief Initializes a new instance of the System::Text::Encoding class.
        Encoding();

        /// @brief Initializes a new instance of the System::Text::Encoding class that corresponds to the specified code page.
        /// @param codePage The code page identifier of the preferred encoding.
        /// @exception System::ArgumentOutOfRangeException codePage is less than zero.
        Encoding(int32 codePage);

        /// @brief Changes the current instance to match the one given as argument.
        /// @param encoding The source encoding.
        /// @exception System::ArgumentNullException encoding is null.
        virtual Encoding& operator=(const Encoding& encoding);

        /// @cond
        void ValidateGBC(int32 charsLength, int32 index, int32 count) const;
        void ValidateGCC(int32 bytesLength, int32 index, int32 count) const;
        void ValidateGC(int32 bytesLength, int32 byteIndex, int32 byteCount, int32 charsLength, int32 charIndex) const;
        int32 codePage;

      private:
        static void InitCodePages();
        static refptr< System::Collections::Generic::Dictionary<int32, String>> names;
        static refptr< System::Collections::Generic::Dictionary<String, int32>> codePagesFromName;
        static refptr< System::Collections::Generic::Dictionary<int32, String>> displayNames;
        /// @endcond
      };
    }
  }
}

using namespace Switch;

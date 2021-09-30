/// @file
/// @brief Contains Switch::System::Text::UTF8Encoding class.
#pragma once

#include "Encoding.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Text namespace contains classes that represent ASCII and Unicode character encodings; abstract base classes for converting blocks of characters to and from blocks of bytes; and a helper class that manipulates and formats string objects without creating intermediate instances of string.
    namespace Text {
      /// @brief Represents an UTF8 character encoding of Unicode characters.
      class core_export_ UTF8Encoding : public Encoding {
      public:
        /// @brief Initializes a new instance of the System::Text::UTF8Encoding class.
        UTF8Encoding();

        /// @brief Initializes a new instance of the System::Text::UTF8Encoding class. Parameter specify whether to provide a Unicode byte order mark.
        /// @param shouldEmitPreamble true to specify that a Unicode byte order mark is provided; otherwise, false.
        UTF8Encoding(bool shouldEmitPreamble);

        /// @brief Initializes a new copy of an instance of the System::Text::UTF8Encoding class.
        /// @param encoding The source encoding.
        /// @exception System::ArgumentNullException encoding is null.
        UTF8Encoding(const UTF8Encoding& encoding);

        /// @brief Changes the current instance to match an instance of the System::Text::UTF8Encoding class.
        /// @param encoding The source encoding.
        /// @exception System::ArgumentNullException encoding is null.
        virtual UTF8Encoding& operator=(const UTF8Encoding& encoding);

        /// @brief Gets a value indicating whether the current encoding uses single-byte code points.
        /// @return This property is always false.
        bool IsSingleByte() const override { return false; }

        using Encoding::GetByteCount;

        /// @brief Calculates the number of bytes produced by encoding a character.
        /// @param c The character to encode.
        /// @return The number of bytes produced by encoding the specified character.
        int32 GetByteCount(char32 c) const override;

        using Encoding::GetBytes;

        int32 GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 byteIndex) const override;

        using Encoding::GetCharCount;

        /// @brief Calculates the number of characters produced by decoding a sequence of bytes from the specified byte array.
        /// @param bytes The byte array containing the sequence of bytes to decode.
        /// @param index The index of the first byte to decode.
        /// @param count The number of bytes to decode.
        /// @return The number of characters produced by decoding the specified sequence of bytes.
        /// @exception System::ArgumentNullException bytes is null.
        /// @exception System::ArgumentOutOfRangeException index or count is less than zero. -or- index and count do not denote a valid range in bytes. -or- The resulting number of bytes is greater than the maximum number that can be returned as an integer.
        int32 GetCharCount(const byte bytes[], int32 bytesSize, int32 index, int32 count) const override;

        using Encoding::GetChars;

        /// @brief Calculates the maximum number of bytes produced by encoding the specified number of characters.
        /// @param charCount The number of characters to encode.
        /// @return The maximum number of bytes produced by encoding the specified number of characters.
        /// @exception System::ArgumentOutOfRangeException charCount is less than zero. -or- The resulting number of bytes is greater than the maximum number that can be returned as an integer.
        int32 GetMaxByteCount(int32 charCount) const override;

        /// @brief Calculates the maximum number of characters produced by decoding the specified number of bytes.
        /// @param byteCount The number of bytes to decode.
        /// @return The maximum number of characters produced by decoding the specified number of bytes.
        /// @exception System::ArgumentOutOfRangeException byteCount is less than zero. -or- The resulting number of bytes is greater than the maximum number that can be returned as an integer.
        int32 GetMaxCharCount(int32 byteCount) const override;

        /// @brief Returns a Unicode byte order mark encoded in UTF-8 format, if the constructor for this instance requests a byte order mark.
        /// @return A byte array containing the Unicode byte order mark, if the constructor for this instance requests a byte order mark. Otherwise, this method returns a byte array of length zero.
        Array<byte> GetPreamble() const override;

        /// @brief Determines whether the specified System::Object is equal to the current instance.
        /// @param value The System::Object to compare with the current instance.
        /// @return true if value is an instance of System::Text::Encoding and is equal to the current instance; otherwise, false.
        bool Equals(const object& obj) const override;

        refptr<Encoding::Decoder> CreateDecoder() const override;
        refptr<Encoding::Encoder> CreateEncoder() const override;

        class Encoder : public Encoding::Encoder {
        public:
          Encoder() : Encoding::Encoder() { }
          Encoder(const Encoder& e) : Encoding::Encoder(e) { }

          Encoder& operator=(const Encoder& b);
          int32 GetNbBytes(char32 c) const override;
          void Encode(char32 c, byte bytes[]) const override;
          String ToString() const override;
          /// @cond
        private:
          //bool shouldEmitPreamble;
          /// @endcond
        };

        class Decoder : public Encoding::Decoder {
        public:
          Decoder() : Encoding::Decoder() { format = 0; }
          Decoder(const Decoder& b) : Encoding::Decoder(b) { format = b.format; }

          Decoder& operator=(const Decoder& b);

          void Add(byte b) override;
          void Reset() override;
          virtual char32 GetCodePoint() const { return codePoint; }
          String ToString() const override;

        private:
          byte format;
        };

        bool shouldEmitPreamble;
      };
    }
  }
}

using namespace Switch;

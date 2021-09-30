/// @file
/// @brief Contains Switch::System::Text::ANSIEncoding class.
#pragma once

#include "Encoding.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Text namespace contains classes that represent ASCII and Unicode character encodings; abstract base classes for converting blocks of characters to and from blocks of bytes; and a helper class that manipulates and formats string objects without creating intermediate instances of string.
    namespace Text {
      /// @brief Represents an ANSI character encoding of Unicode characters (This is a generic class representing various code pages).
      class core_export_ ANSIEncoding : public Encoding {
      public:
        /// @brief Initializes a new instance of the System::Text::ANSIEncoding class.
        /// @param codePage The code page of the desired Unicode code page.
        ANSIEncoding(int32 codePage);

        /// @brief Gets a value indicating whether the current encoding uses single-byte code points.
        /// @return This property is always true.
        bool IsSingleByte() const override { return true; }

        using Encoding::GetByteCount;

        /// @brief Calculates the number of bytes produced by encoding a character.
        /// @param c The character to encode.
        /// @return The number of bytes produced by encoding the specified character.
        int32 GetByteCount(char32 c) const override;

        using Encoding::GetBytes;
        using Encoding::GetCharCount;

        /// @brief Calculates the number of characters produced by decoding a sequence of bytes from the specified byte array.
        /// @param bytes The byte array containing the sequence of bytes to decode.
        /// @param index The index of the first byte to decode.
        /// @param count The number of bytes to decode.
        /// @return The number of characters produced by decoding the specified sequence of bytes.
        /// @exception System::ArgumentNullException bytes is null.
        /// @exception System::ArgumentOutOfRangeException index or count is less than zero. -or-  index and count do not denote a valid range in bytes. -or-  The resulting number of bytes is greater than the maximum number that can be returned as an integer.
        int32 GetCharCount(const byte bytes[], int32 bytesSize, int32 index, int32 count) const override;

        using Encoding::GetChars;

        /// @brief Calculates the maximum number of bytes produced by encoding the specified number of characters.
        /// @param charCount The number of characters to encode.
        /// @return The maximum number of bytes produced by encoding the specified number of characters.
        /// @exception System::ArgumentOutOfRangeException charCount is less than zero. -or-  The resulting number of bytes is greater than the maximum number that can be returned as an integer.
        int32 GetMaxByteCount(int32 charCount) const override;

        /// @brief Calculates the maximum number of characters produced by decoding the specified number of bytes.
        /// @param byteCount The number of bytes to decode.
        /// @return The maximum number of characters produced by decoding the specified number of bytes.
        /// @exception System::ArgumentOutOfRangeException byteCount is less than zero. -or- The resulting number of bytes is greater than the maximum number that can be returned as an integer.
        int32 GetMaxCharCount(int32 byteCount) const override;

        bool Equals(const object& obj) const override;

        /// @brief Converts the given code point into its representing byte.
        /// @param codePoint The codePoint to encode.
        /// @return The byte encoding the given codePoint or the value of Unknown().
        byte GetByte(uint32 codePoint) const;

        /// @brief Converts the given byte into its corresponding code point.
        /// @param b The byte to decode.
        /// @return The code point corresponding to the byte.
        uint32 GetCodePoint(byte b) const;

        class core_export_ Decoder : public Encoding::Decoder {
        public:
          Decoder(int32 cp) : Encoding::Decoder(), codePage(cp) { }
          Decoder(const Decoder& b);
          Decoder& operator=(const Decoder& b);
          void Add(byte b) override;
          void Reset() override;
          String ToString() const override;
          virtual char32 GetCodePoint(byte b) = 0;

        protected:
          static char32 GetCodePoint(byte b, const std::vector<char32>& codePoints, uint32 unchanged);

        private:
          int32 codePage;
        };

        class Encoder : public Encoding::Encoder {
        public:
          Encoder(int32 cp);
          Encoder(const Encoder& e);
          Encoder& operator=(const Encoder& b);
          int32 GetNbBytes(char32) const override;
          void Encode(char32 codePoint, byte* bytes) const override;
          String ToString() const override;
          virtual byte GetByte(char32 cp) = 0;

        private:
          int32 codePage;
        };

        /// @cond
      private:
        ANSIEncoding();
        ANSIEncoding(const ANSIEncoding& encoding);
        virtual ANSIEncoding& operator=(const ANSIEncoding& encoding);
        Encoding& operator=(const Encoding& encoding) override;
        /// @endcond
      };

      class core_export_ CodePage437Encoding : public ANSIEncoding {
      public:
        CodePage437Encoding();
        refptr<Encoding::Decoder> CreateDecoder() const override;
        refptr<Encoding::Encoder> CreateEncoder() const override;
        using ANSIEncoding::GetBytes;
        int32 GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 byteIndex) const override;

        class Decoder : public ANSIEncoding::Decoder {
        public:
          Decoder() : ANSIEncoding::Decoder(437) { }
          char32 GetCodePoint(byte b) override;
        };

        class Encoder : public ANSIEncoding::Encoder {
        public:
          Encoder() : ANSIEncoding::Encoder(437) { }
          byte GetByte(char32 cp) override;
        };
      };

      class core_export_ CodePage28591Encoding : public ANSIEncoding {
      public:
        CodePage28591Encoding();
        refptr<Encoding::Decoder> CreateDecoder() const override;
        refptr<Encoding::Encoder> CreateEncoder() const override;
        using ANSIEncoding::GetBytes;
        int32 GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 byteIndex) const override;

        class Decoder : public ANSIEncoding::Decoder {
        public:
          Decoder() : ANSIEncoding::Decoder(28591) { }
          char32 GetCodePoint(byte b) override;
        };

        class Encoder : public ANSIEncoding::Encoder {
        public:
          Encoder() : ANSIEncoding::Encoder(28591) { }
          byte GetByte(char32 cp) override;
        };
      };

      class core_export_ CodePage28592Encoding : public ANSIEncoding {
      public:
        CodePage28592Encoding();
        refptr<Encoding::Decoder> CreateDecoder() const override;
        refptr<Encoding::Encoder> CreateEncoder() const override;
        using ANSIEncoding::GetBytes;
        int32 GetBytes(char32 c, byte bytes[], int32 bytesLength, int32 byteIndex) const override;

        class Decoder : public ANSIEncoding::Decoder {
        public:
          Decoder() : ANSIEncoding::Decoder(28592) { }
          char32 GetCodePoint(byte b) override;
        };

        class Encoder : public ANSIEncoding::Encoder {
        public:
          Encoder() : ANSIEncoding::Encoder(28592) { }
          byte GetByte(char32 cp) override;
        };
      };
    }
  }
}

using namespace Switch;

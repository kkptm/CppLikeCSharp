/// @file
/// @brief Contains Switch::System::Guid struct.
#pragma once

#include "../Property.hpp"
#include "../Types.hpp"
#include "Array.hpp"
#include "Buffer.hpp"
#include "String.hpp"
#include "SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents a globally unique identifier (GUID). A GUID is a 128-bit integer (16 bytes) that can be used across all computers and networks wherever a unique identifier is required. Such an identifier has a very low probability of being duplicated.
    struct core_export_ Guid : public object, public IComparable {
    public:
      /// @brief Initializes a new instance of the Guid structure.
      Guid() {}

      /// @brief Initializes a new instance of the Guid structure.
      Guid(const Guid& guid) : data(guid.data) {}

      /// @brief Initializes a new instance of the Guid structure by using the specified array of bytes.
      /// @param bytes A 16-element byte array containing values with which to initialize the GUID.
      /// @exception System::ArgumentNullException bytes is null.
      /// @exception System::ArgumentException bytes is not 16 bytes long.
      explicit Guid(const Array<byte>& bytes) {
        if (bytes.Length != this->data.Length)
          throw ArgumentException(caller_);
        this->data = bytes;
      }

      /// @brief Initializes a new instance of the Guid structure by using the specified array of bytes.
      /// @param bytes A 16-element byte array containing values with which to initialize the GUID.
      /// @exception System::ArgumentNullException bytes is null.
      template<int32 dataSize>
      Guid(const byte bytes[dataSize]) {
        if (bytes == null)
          throw ArgumentNullException(caller_);
        if (dataSize != this->data.Length)
          throw ArgumentException(caller_);
        this->data = Array<byte>(bytes);
      }

      /// @brief Initializes a new instance of the Guid structure by using the specified array of bytes.
      /// @param bytes A 16-element byte array containing values with which to initialize the GUID.
      /// @exception System::ArgumentNullException bytes is null.
      Guid(const byte bytes[16]) {
        if (bytes == null)
          throw ArgumentNullException(caller_);
        this->data = Array<byte>(bytes, 16);
      }

      /// @brief Initializes a new instance of the Guid structure by using the specified array of bytes.
      /// @param bytes A 16-element byte array containing values with which to initialize the GUID.
      /// @exception System::ArgumentNullException bytes is null.
      Guid(const byte* bytes, int32 dataSize) {
        if (bytes == null)
          throw ArgumentNullException(caller_);
        if (dataSize != this->data.Length)
          throw ArgumentException(caller_);
        this->data = Array<byte>(bytes, dataSize);
      }

      /// @brief Initializes a new instance of the Guid structure by using the specified integers and byte array.
      /// @param a The first 4 bytes of the GUID.
      /// @param b The next 2 bytes of the GUID.
      /// @param c The next 2 bytes of the GUID.
      /// @param d The remaining 8 bytes of the GUID.
      /// @exception ArgumentException bytes is not 16 bytes long.
      Guid(int32 a, int16 b, int16 c, const Array<byte>& d) {
        if (d.Length != 8)
          throw ArgumentException(caller_);

        this->data[0] = (byte)((a & 0xFF000000) >> 24);
        this->data[1] = (byte)((a & 0x00FF0000) >> 16);
        this->data[2] = (byte)((a & 0x0000FF00) >> 8);
        this->data[3] = (byte)((a & 0x000000FF) >> 0);
        this->data[4] = (byte)((b & 0xFF00) >> 8);
        this->data[5] = (byte)((b & 0x00FF) >> 0);
        this->data[6] = (byte)((c & 0xFF00) >> 8);
        this->data[7] = (byte)((c & 0x00FF) >> 0);

        for (int32 i = 0; i < 8; i++)
          this->data[8 + i] = d[i];
      }

      /// @brief Initializes a new instance of the Guid structure by using the specified integers and byte array.
      /// @param a The first 4 bytes of the GUID.
      /// @param b The next 2 bytes of the GUID.
      /// @param c The next 2 bytes of the GUID.
      /// @param d The remaining 8 bytes of the GUID.
      /// @exception Pf::System::ArgumentNullException  bytes is null.
      /// @exception Pf::System::ArgumentException bytes is not 8 bytes long.
      template<int32 dataSize>
      Guid(int32 a, int16 b, int16 c, const byte d[dataSize]) {
        if (d == null)
          throw ArgumentNullException(caller_);
        if (dataSize != 8)
          throw ArgumentException(caller_);

        this->data[0] = (byte)((a & 0xFF000000) >> 24);
        this->data[1] = (byte)((a & 0x00FF0000) >> 16);
        this->data[2] = (byte)((a & 0x0000FF00) >> 8);
        this->data[3] = (byte)((a & 0x000000FF) >> 0);
        this->data[4] = (byte)((b & 0xFF00) >> 8);
        this->data[5] = (byte)((b & 0x00FF) >> 0);
        this->data[6] = (byte)((c & 0xFF00) >> 8);
        this->data[7] = (byte)((c & 0x00FF) >> 0);

        for (int32 i = 0; i < 8; i++)
          this->data[8 + i] = d[i];
      }

      /// @brief Initializes a new instance of the Guid structure by using the specified integers and byte array.
      /// @param a The first 4 bytes of the GUID.
      /// @param b The next 2 bytes of the GUID.
      /// @param c The next 2 bytes of the GUID.
      /// @param d The remaining 8 bytes of the GUID.
      /// @exception Pf::System::ArgumentNullException  bytes is null.
      /// @exception Pf::System::ArgumentException bytes is not 8 bytes long.
      Guid(int32 a, int16 b, int16 c, const byte d[8]) {
        if (d == null)
          throw ArgumentNullException(caller_);

        this->data[0] = (byte)((a & 0xFF000000) >> 24);
        this->data[1] = (byte)((a & 0x00FF0000) >> 16);
        this->data[2] = (byte)((a & 0x0000FF00) >> 8);
        this->data[3] = (byte)((a & 0x000000FF) >> 0);
        this->data[4] = (byte)((b & 0xFF00) >> 8);
        this->data[5] = (byte)((b & 0x00FF) >> 0);
        this->data[6] = (byte)((c & 0xFF00) >> 8);
        this->data[7] = (byte)((c & 0x00FF) >> 0);

        for (int32 i = 0; i < 8; i++)
          this->data[8 + i] = d[i];
      }

      /// @brief Initializes a new instance of the Guid structure by using the specified integers and bytes.
      /// @param a The first 4 bytes of the GUID.
      /// @param b The next 2 bytes of the GUID.
      /// @param c The next 2 bytes of the GUID.
      /// @param d The next byte of the GUID.
      /// @param e The next byte of the GUID.
      /// @param f The next byte of the GUID.
      /// @param g The next byte of the GUID.
      /// @param h The next byte of the GUID.
      /// @param i The next byte of the GUID.
      /// @param j The next byte of the GUID.
      /// @param k The next byte of the GUID.
      Guid(int32 a, int16 b, int16 c, byte d, byte e, byte f, byte g, byte h, byte i, byte j, byte k) {
        this->data[0] = (byte)((a & 0xFF000000) >> 24);
        this->data[1] = (byte)((a & 0x00FF0000) >> 16);
        this->data[2] = (byte)((a & 0x0000FF00) >> 8);
        this->data[3] = (byte)((a & 0x000000FF) >> 0);
        this->data[4] = (byte)((b & 0xFF00) >> 8);
        this->data[5] = (byte)((b & 0x00FF) >> 0);
        this->data[6] = (byte)((c & 0xFF00) >> 8);
        this->data[7] = (byte)((c & 0x00FF) >> 0);
        this->data[8] = d;
        this->data[9] = e;
        this->data[10] = f;
        this->data[11] = g;
        this->data[12] = h;
        this->data[13] = i;
        this->data[14] = j;
        this->data[15] = k;
      }

      /// @brief Initializes a new instance of the Guid structure by using the specified unsigned integers and bytes.
      /// @param a The first 4 bytes of the GUID.
      /// @param b The next 2 bytes of the GUID.
      /// @param c The next 2 bytes of the GUID.
      /// @param d The next byte of the GUID.
      /// @param e The next byte of the GUID.
      /// @param f The next byte of the GUID.
      /// @param g The next byte of the GUID.
      /// @param h The next byte of the GUID.
      /// @param i The next byte of the GUID.
      /// @param j The next byte of the GUID.
      /// @param k The next byte of the GUID.
      Guid(uint32 a, uint16 b, uint16 c, byte d, byte e, byte f, byte g, byte h, byte i, byte j, byte k) {
        this->data[0] = (byte)((a & 0xFF000000) >> 24);
        this->data[1] = (byte)((a & 0x00FF0000) >> 16);
        this->data[2] = (byte)((a & 0x0000FF00) >> 8);
        this->data[3] = (byte)((a & 0x000000FF) >> 0);
        this->data[4] = (byte)((b & 0xFF00) >> 8);
        this->data[5] = (byte)((b & 0x00FF) >> 0);
        this->data[6] = (byte)((c & 0xFF00) >> 8);
        this->data[7] = (byte)((c & 0x00FF) >> 0);
        this->data[8] = d;
        this->data[9] = e;
        this->data[10] = f;
        this->data[11] = g;
        this->data[12] = h;
        this->data[13] = i;
        this->data[14] = j;
        this->data[15] = k;
      }

      /// @brief Initializes a new instance of the Guid structure by using the value represented by the specified string.
      /// @param guid A string that contains a GUID in one of the following formats ("d" represents a hexadecimal digit whose case is ignored):
      /// 32 contiguous digits:
      /// dddddddddddddddddddddddddddddddd
      /// -or-
      /// Groups of 8, 4, 4, 4, and 12 digits with hyphens between the groups. The entire GUID can optionally be enclosed in matching braces or parentheses:
      /// dddddddd-dddd-dddd-dddd-dddddddddddd
      /// -or-
      /// {dddddddd-dddd-dddd-dddd-dddddddddddd}
      /// -or-
      /// (dddddddd-dddd-dddd-dddd-dddddddddddd)
      /// -or-
      /// Groups of 8, 4, and 4 digits, and a subset of eight groups of 2 digits, with each group prefixed by "0x" or "0X", and separated by commas. The entire GUID, as well as the subset, is enclosed in matching braces:
      /// {0xdddddddd, 0xdddd, 0xdddd,{0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd}}
      /// All braces, commas, and "0x" prefixes are required. All embedded spaces are ignored. All leading zeros in a group are ignored.
      /// The digits shown in a group are the maximum number of meaningful digits that can appear in that group. You can specify from 1 to the number of digits shown for a group. The specified digits are assumed to be the low-order digits of the group.
      /// @exception ArgumentNullException guid is null.
      /// @exception FormatException The format of gui is invalid.
      /// @exception OverflowException The format of gui is invalid.
      /// @remarks The alphabetic hexadecimal digits in the g parameter can be uppercase or lowercase. For example, the following strings represent the same GUID:
      /// @remarks "ca761232ed4211cebacd00aa0057b223"
      /// @remarks "CA761232-ED42-11CE-BACD-00AA0057B223"
      /// @remarks "{CA761232-ED42-11CE-BACD-00AA0057B223}"
      /// @remarks "(CA761232-ED42-11CE-BACD-00AA0057B223)"
      /// @remarks "{0xCA761232, 0xED42, 0x11CE, {0xBA, 0xCD, 0x00, 0xAA, 0x00, 0x57, 0xB2, 0x23}}"
      Guid(const string& guid) {
        string simple = guid.Replace("0x", "").Replace(",", "").Replace("-", "").Replace("(", "").Replace(")", "").Replace("{", "").Replace("}", "");
        for (int32 i = 0; i < this->data.Length; i ++) {
          this->data[i] = Byte::Parse(simple.Substring(0, 2), 16);
          simple = simple.Remove(0, 2);
        }
      }

      int32 CompareTo(const Guid& value) const {
        for (int32 i = 0; i < this->data.Length; i++)
          if (this->data[i] > value.data[i]) return 1;
          else if (this->data[i] < value.data[i]) return -1;
        return 0;
      }

      int32 CompareTo(const IComparable& obj) const override {
        if (!is<Guid>(obj)) return 1;
        return CompareTo(static_cast<const Guid&>(obj));
      }

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current object.
      int32 GetHashCode() const override {
        int32 hashCode = 0;
        for (int32 i = 0; i < this->data.Length; i++)
          hashCode ^= this->data[i];
        return hashCode;
      }

      bool Equals(const Guid& value) const {return this->data == value.data;}

      bool Equals(const object& obj) const override {return is<Guid>(obj) && Equals(static_cast<const Guid&>(obj));}

      /// @brief Initializes a new instance of the Guid structure.
      /// @return Guid A new GUID object.
      /// @remarks This is a convenient static method that you can call to get a new Guid.
      /// @remarks The chance that the value of the new Guid will be all zeros or equal to any other Guid is very low. You can determine whether a GUID consists of all zeros by comparing it to Guid.Empty.
      static Guid NewGuid();

      /// @brief Returns a 16-element byte array that contains the value of this instance.
      /// @return Array<Byte> A 16-element byte array.
      Array<byte> ToByteArray() const {return this->data;}

      /// @brief Returns a string representation of the value of this instance in registry format.
      /// @return string The value of this Guid, formatted by using the "D" format specifier as follows:
      /// xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
      /// where the value of the GUID is represented as a series of lowercase hexadecimal digits in groups of 8, 4, 4, 4, and 12 digits and separated by hyphens. An example of a return value is "382c74c3-721d-4f34-80e5-57657b6cbc27". To convert the hexadecimal digits from a through f to uppercase, call the string.ToString method on the returned string.
      /// @remarks This method provides a default GUID format that is sufficient for typical use; however, other versions of this method that take a format parameter provide a few common format variations.
      String ToString() const override { return ToString("D"); }

      /// @brief Returns a string representation of the value of this Guid instance, according to the provided format specifier.
      /// @param format A single format specifier that indicates how to format the value of this Guid. The format parameter can be "N", "D", "B", "P", or "X". If format is null or an empty string (""), "D" is used.
      /// @return The value of this Guid, represented as a series of lowercase hexadecimal digits in the specified format.
      /// @exception FormatException The value of format is not null, an empty string (""), "N", "D", "B", "P", or "X".
      /// @remarks The following table shows the accepted format specifiers for the format parameter. "0" represents a digit; hyphens ("-"), braces ("{", "}"), and parentheses ("(", ")") appear as shown.
      /// | Specifier | Format of return value                                                                                                                      |
      /// |-----------|---------------------------------------------------------------------------------------------------------------------------------------------|
      /// | N         | 32 digits:                                                                                                                                  |
      /// |           | 00000000000000000000000000000000                                                                                                            |
      /// | D         | 32 digits separated by hyphens:                                                                                                             |
      /// |           | 00000000-0000-0000-0000-000000000000                                                                                                        |
      /// | B         | 32 digits separated by hyphens, enclosed in braces:                                                                                         |
      /// |           | {00000000-0000-0000-0000-000000000000}                                                                                                      |
      /// | P         | 32 digits separated by hyphens, enclosed in parentheses:                                                                                    |
      /// |           | (00000000-0000-0000-0000-000000000000)                                                                                                      |
      /// | X         | Four hexadecimal values enclosed in braces, where the fourth value is a subset of eight hexadecimal values that is also enclosed in braces: |
      /// |           | {0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}                                                                         |
      string ToString(const string& format) const {
        string formats = "ndbpx";
        string fmt = (string::IsNullOrEmpty(format) ? "d" : format.ToLower());
        string result;

        if (fmt.Length() != 1 || formats.IndexOf(fmt) == -1)
          throw FormatException(caller_);

        bool hyphens = fmt != "n" && fmt != "x";
        bool braces = fmt == "b";
        bool parentheses = fmt == "p";
        bool hexadecimal = fmt == "x";

        for (int32 index = 0; index < this->data.Length; index++) {
          if (hexadecimal && (index == 4 || index == 6 || (index >= 8 && index <= 15)))
            result += ",";
          if (hexadecimal && (index == 0 || index == 8))
            result += "{";
          if (hexadecimal && (index == 0 || index == 4 || index == 6 || (index >= 8 && index <= 15)))
            result += "0x";
          result += Byte(this->data[index]).ToString("x2");
          if (hexadecimal && index == 15)
            result += "}}";
          if (hyphens && (index == 3 || index == 5 || index == 7 || index == 9))
            result += "-";
        }

        if (braces)
          result = "{" + result + "}";
        if (parentheses)
          result = "(" + result + ")";

        return result;
      }

      /// @brief Get A read-only instance of the Guid structure whose value is all zeros.
      /// @return Guid A read-only instance of the Guid structure whose value is all zeros.
      /// @remarks You can compare a GUID with the value of the Guid.Empty field to determine whether a GUID is non-zero. The following example uses the Equality operator to compare two GUID values with Guid.Empty to determine whether they consist exclusively of zeros.
      static Guid Empty() {
        return Guid();
      }

    private :
      Array<byte> data = Array<byte>(16);
    };
  }
}

using namespace Switch;

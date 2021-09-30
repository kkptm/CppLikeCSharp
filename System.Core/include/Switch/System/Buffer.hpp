/// @file
/// @brief Contains Switch::System::Buffer class.
#pragma once

#include <cstring>

#include "../Static.hpp"
#include "../Types.hpp"
#include "Array.hpp"
#include "Convert.hpp"
#include "SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Manipulates arrays of primitive types.
    /// This class cannot be inherited.
    /// Buffer only affects arrays of primitive types; this class does ! apply to objects. Each primitive type is treated as a series of bytes without regard to any behavior or limitation associated with the primitive type.
    /// Buffer provides methods to copy bytes from one array of primitive types to another array of primitive types, get a byte from an array, set a byte in an array, and obtain the length of an array. This class provides better performance for manipulating primitive types than similar methods in the System::Array class.
    /// Buffer is applicable to the following primitive types: #bool, #char, #char32, #sbyte, #byte, #int16, #uint16, #int32, #uint32, #int64, #uint64, #void*, #uintptr, #float, and #double.
    class core_export_ Buffer static_ {
    public:
      /// @brief Compare a specified number of bytes from a first buffer starting at a particular offset to a second buffer starting at a particular offset.
      /// @param blk1 First buffer
      /// @param blk1Offset The zero-based byte offset into blk1.
      /// @param blk2 Second buffer
      /// @param blk2Offset The zero-based byte offset into blk2.
      /// @param count Number of byte to compare
      /// @return int32 A 32-bit signed integer that indicates the relative order of the pointer being compared. The return value has these meanings:
      /// | Value             | Description                |
      /// |-------------------|----------------------------|
      /// | Less than zero    | blk1 is less than blk2.    |
      /// | Zero              | blk1 is equal to blk2.     |
      /// | Greater than zero | blk1 is greater than blk2. |
      /// @exception ArgumentOutOfRangeException blk1Length, blk1Offset, blk2Length, blk2Offset, or count is less than 0.
      /// @exception ArgumentException blk1 or blk2 is ! primitive. - or - The number of bytes in blk1 is less than blk1Offset plus count -or- The number of bytes in blk2 is less than blk2Offset plus count.
      template<typename TSource, typename TDestination>
      static int32 BlockCompare(const Array<TSource>& blk1, int32 blk1Offset, const Array<TDestination>& blk2, int32 blk2Offset, int32 count) {
        if (blk1Offset < 0 || blk2Offset < 0 || count < 0)
          throw ArgumentOutOfRangeException(caller_);
        if (!IsPrimitive<TSource>() || !IsPrimitive<TDestination>() || blk1Offset + count > Buffer::ByteLength(blk1) || blk2Offset + count > Buffer::ByteLength(blk2))
          throw ArgumentException(caller_);

        const byte* blk1Ptr = (const byte*)blk1.GetData();
        const byte* blk2Ptr = (const byte*)blk2.GetData();
        return memcmp(&blk1Ptr[blk1Offset], &blk2Ptr[blk2Offset], count);
      }

      /// @brief Compare a specified number of bytes from a first pointer starting at a particular offset to a second pointer starting at a particular offset.
      /// @param blk1 First pointer
      /// @param blk1Length First pointer size
      /// @param blk1Offset The zero-based byte offset into blk1.
      /// @param blk2 Second pointer
      /// @param blk2Length Second pointer size
      /// @param blk2Offset The zero-based byte offset into blk2.
      /// @param count Number of byte to compare
      /// @return int32 A 32-bit signed integer that indicates the relative order of the pointer being compared. The return value has these meanings:
      /// | Value             | Description                |
      /// |-------------------|----------------------------|
      /// | Less than zero    | blk1 is less than blk2.    |
      /// | Zero              | blk1 is equal to blk2.     |
      /// | Greater than zero | blk1 is greater than blk2. |
      /// @exception ArgumentNullException blk1 or blk2 is null
      /// @exception ArgumentOutOfRangeException blk1Length, blk1Offset, blk2Length, blk2Offset, or count is less than 0.
      /// @exception ArgumentException The number of bytes in blk1 is less than blk1Offset plus count -or- The number of bytes in blk2 is less than blk2Offset plus count.
      template<typename T1, typename T2>
      static int32 BlockCompare(const T1* blk1, int64 blk1Length, int64 blk1Offset, const T2* blk2, int64 blk2Length, int64 blk2Offset, int64 count) {return BlockCompare((const void*)blk1, blk1Length, blk1Offset, (const void*)blk2, blk2Length, blk2Offset, count);}

      /// @cond
      static int32 BlockCompare(const void* blk1, int64 blk1Length, int64 blk1Offset, const void* blk2, int64 blk2Length, int64 blk2Offset, int64 count);
      /// @endcond

      /// @brief Copies a specified number of bytes from a source array starting at a particular offset to a destination array starting at a particular offset.
      /// @param src The source buffer.
      /// @param srcOffset The zero-based byte offset into src.
      /// @param dst The destination buffer.
      /// @param dstOffset The zero-based byte offset into dst.
      /// @param count The number of bytes to copy.
      /// @exception ArgumentException src or dst is ! primitive. - or - The number of bytes in src is less than srcOffset plus count. -or - The number of bytes in dst is less than dstOffset plus count.
      /// @exception ArgumentOutOfRangeException srcOffset, dstOffset, or count is less than 0.
      template<typename TSource, typename TDestination>
      static void BlockCopy(const Array<TSource>& src, int32 srcOffset, Array<TDestination>& dst, int32 dstOffset, int32 count) {
        if (srcOffset < 0 || dstOffset < 0 || count < 0)
          throw ArgumentOutOfRangeException(caller_);
        if (!IsPrimitive<TSource>() || !IsPrimitive<TDestination>() || srcOffset + count > Buffer::ByteLength(src) || dstOffset + count > Buffer::ByteLength(dst))
          throw ArgumentException(caller_);

        const byte* srcPtr = (const byte*)src.Data();
        byte* dstPtr = const_cast<byte*>((const byte*)dst.Data());
        memmove(&dstPtr[dstOffset], &srcPtr[srcOffset], count);
      }

      /// @brief Copies a specified number of bytes from a src pointer starting at a particular offset to a destination pointer starting at a particular offset.
      /// @param src Source pointer
      /// @param srcLength Source size
      /// @param srcOffset The zero-based byte offset into src.
      /// @param dst Target pointer
      /// @param dstLenth Target size
      /// @param dstOffset The zero-based byte offset into dst.
      /// @param count Number of byte to copy
      /// @exception ArgumentNullException src or dst is null
      /// @exception ArgumentOutOfRangeException srcLength, srcOffset, dstLenth, dstOffset, or count is less than 0.
      /// @exception ArgumentException The number of bytes in src is less than srcOffset plus count -or- The number of bytes in dst is less than dstOffset plus count.
      static void BlockCopy(const void* src, int64 srcLength, int64 srcOffset, void* dst, int64 dstLenth, int64 dstOffset, int64 count);

      /// @brief Fill a specified number of bytes to a destination buffer starting at a particular offset whith a specified value.
      /// @param filler The filler byte
      /// @param dst Target pointer
      /// @param dstOffset The zero-based byte offset into dst.
      /// @param count Number of byte to filler
      /// @exception ArgumentOutOfRangeException dstLenth, dstOffset, or count is less than 0.
      /// @exception ArgumentException dst is ! primitive. - or - The number of bytes in dst is less than dstOffset plus count.
      template<typename TDestination>
      static void BlockFill(byte filler, Array<TDestination>& dst, int32 dstOffset, int32 count) {
        if (dstOffset < 0 || count < 0)
          throw ArgumentOutOfRangeException(caller_);
        if (!IsPrimitive<TDestination>() || dstOffset + count > Buffer::ByteLength(dst))
          throw ArgumentException(caller_);

        byte* dstPtr = const_cast<byte*>((const byte*)dst.Data());
        memset(&dstPtr[dstOffset], filler, count);
      }

      /// @brief Fill a specified number of bytes to a destination pointer starting at a particular offset whith a specified value.
      /// @param filler The filler byte
      /// @param dst Target pointer
      /// @param dstLenth Target size
      /// @param dstOffset The zero-based byte offset into dst.
      /// @param count Number of byte to filler
      /// @exception ArgumentNullException dst is null
      /// @exception ArgumentOutOfRangeException dstLenth, dstOffset, or count is less than 0.
      /// @exception ArgumentException The number of bytes in dst is less than dstOffset plus count.
      static void BlockFill(byte filler, void* dst, int64 dstLenth, int64 dstOffset, int64 count);

      /// @brief Clear to 0 a specified number of bytes to a destination buffer starting at a particular offset.
      /// @param dst Target buffer.
      /// @param dstOffset The zero-based byte offset into dst.
      /// @param count Number of byte to clear.
      /// @exception ArgumentOutOfRangeException dstLenth, dstOffset, or count is less than 0.
      /// @exception ArgumentException st is ! primitive. - or - The number of bytes in dst is less than dstOffset plus count.
      template<typename TDestination>
      static void BlockZero(Array<TDestination>& dst, int32 dstOffset, int32 count) { BlockFill<TDestination>(0, dst, dstOffset, count); }

      /// @brief Clear to 0 a specified number of bytes to a destination pointer starting at a particular offset.
      /// @param dst Target pointer.
      /// @param dstLenth Target size.
      /// @param dstOffset The zero-based byte offset into dst.
      /// @param count Number of byte to clear.
      /// @exception ArgumentOutOfRangeException dstLenth, dstOffset, or count is less than 0.
      /// @exception ArgumentException The number of bytes in dst is less than dstOffset plus count.
      static void BlockZero(void* dst, int64 dstLenth, int64 dstOffset, int64 count) { BlockFill(0, dst, dstLenth, dstOffset, count); }

      /// @brief Returns the number of bytes in the specified array.
      /// @param array An array.
      /// @return The number of bytes in the array.
      /// @exception ArgumentException array is ! primitive.
      /// @exception OverflowException array is larger than 2 gigabytes(GB).
      template<typename T>
      static int32 ByteLength(const Array<T>& array) {
        if (!IsPrimitive<T>())
          throw ArgumentException(caller_);

        return Convert::ToInt32((int64)sizeof(T) * array.Length);
      }

      /// @brief Retrieves the byte at a specified location in a specified array.
      /// @param array An array.
      /// @param index A location in the array.
      /// @return Returns the index byte in the array.
      /// @exception ArgumentException array is ! primitive.
      /// @exception ArgumentOutOfRangeException index is negative or greater than the length of array.
      /// @exception OverflowException array is larger than 2 gigabytes(GB).
      template<typename T>
      static byte GetByte(const Array<T>& array, int32 index) {
        if (!IsPrimitive<T>())
          throw ArgumentException(caller_);
        if (0 < index && index >= Buffer::ByteLength(array))
          throw ArgumentOutOfRangeException(caller_);

        const byte* bytePtr = (const byte*)array.Data();
        return (byte)(bytePtr[index]);
      }

      /// @brief Assigns a specified value to a byte at a particular location in a specified array.
      /// @param array An array.
      /// @param index A location in the array.
      /// @param value A value to assign.
      /// @exception ArgumentException array is ! primitive.
      /// @exception ArgumentOutOfRangeException index is negative or greater than the length of array.
      /// @exception OverflowException array is larger than 2 gigabytes(GB).
      template<typename T>
      static void SetByte(const Array<T>& array, int32 index, byte value) {
        if (!IsPrimitive<T>())
          throw ArgumentException(caller_);
        if (0 < index && index >= Buffer::ByteLength(array))
          throw ArgumentOutOfRangeException(caller_);

        byte* bytePtr = const_cast<byte*>((const byte*)array.Data());
        bytePtr[index] = value;
      }

    private:
      template<typename T>
      static bool IsPrimitive() {return (typeid(T) == typeid(bool)) || (typeid(T) == typeid(byte)) || (typeid(T) == typeid(char)) || (typeid(T) == typeid(double)) || (typeid(T) == typeid(int16)) || (typeid(T) == typeid(int32)) || (typeid(T) == typeid(void*)) | (typeid(T) == typeid(int64)) || (typeid(T) == typeid(sbyte)) || (typeid(T) == typeid(float)) || (typeid(T) == typeid(char32)) || (typeid(T) == typeid(uint16)) || (typeid(T) == typeid(uint32)) || (typeid(T) == typeid(uint64)) || (typeid(T) == typeid(void*));}
    };
  }
}

using namespace Switch;

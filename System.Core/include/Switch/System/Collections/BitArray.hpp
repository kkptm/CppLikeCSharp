/// @file
/// @brief Contains Switch::System::Collections::BitArray class.
#pragma once

#include "../../InitializerList.hpp"
#include "../../Property.hpp"
#include "../../Types.hpp"
#include "../ICloneable.hpp"
#include "../Array.hpp"
#include "../Boolean.hpp"
#include "../Object.hpp"
#include "../SystemException.hpp"
#include "Generic/ICollection.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Manages a compact array of bit values, which are represented as Booleans, where true indicates that the bit is on (1) and false indicates the bit is off (0).
      /// @par Examples
      /// The following code example shows how to create and initialize a BitArray and how to print out its values.
      /// @include BitArray.cpp
      class core_export_ BitArray : public Object, public Generic::ICollection<bool>, public System::ICloneable {
      public:
        /// @brief Initializes a new instance of the BitArray class that contains bit values copied from the specified array of bytes.
        /// @param values An array of bytes containing the values to copy, where each byte represents eight consecutive bits.
        /// @exception ArgumentNullException values is null.
        /// @remarks The first byte in the array represents bits 0 through 7, the second byte represents bits 8 through 15, and so on. The Least Significant Bit of each byte represents the lowest index value: " bytes [0] & 1" represents bit 0, " bytes [0] & 2" represents bit 1, " bytes [0] & 4" represents bit 2, and so on.
        /// @remarks This constructor is an O(n) operation, where n is the number of elements in values.
        BitArray(const Array<byte>& values) {
          this->length = values.Length * BitsPerByte;
          int32 position = 0;
          while (this->bitArray.Count < GetListLength(this->length))
            this->bitArray.Add(0);

          for (int32 index = 0; index < values.Length; index++) {
            for (int32 indexBits = 0; indexBits < BitsPerByte; indexBits++)
              Set(position++, (values[index] & (1 << indexBits)) == (1 << indexBits));
          }
        }

        /// @brief Initializes a new instance of the BitArray class that contains bit values copied from the specified array of Booleans.
        /// @param values An array of Booleans to copy.
        /// @exception ArgumentNullException values is null.
        /// @remarks This constructor is an O(n) operation, where n is the number of elements in values.
        BitArray(const Array<bool>& values) {
          this->length = values.Length;
          while (this->bitArray.Count < GetListLength(this->length)) this->bitArray.Add(0);

          for (int32 index = 0; index < values.Length; index++)
            Set(index, values[index]);
        }

        /// @brief Initializes a new instance of the BitArray class that contains bit values copied from the specified array of 32-bit integers.
        /// @param values An array of integers containing the values to copy, where each integer represents 32 consecutive bits.
        /// @exception ArgumentNullException values is null.
        /// @remarks The number in the first values array element represents bits 0 through 31, the second number in the array represents bits 32 through 63, and so on. The Least Significant Bit of each integer represents the lowest index value: " values [0] & 1" represents bit 0, " values [0] & 2" represents bit 1, " values [0] & 4" represents bit 2, and so on.
        /// @remarks This constructor is an O(n) operation, where n is the number of elements in values.
        BitArray(const Array<int32>& values) {
          this->length = values.Length * BitsPerInt32;
          int32 position = 0;
          while (this->bitArray.Count < GetListLength(this->length))
            this->bitArray.Add(0);
          for (int32 index = 0; index < values.Length; index++) {
            for (int32 indexBits = 0; indexBits < BitsPerInt32; indexBits++)
              Set(position++, (values[index] & (1 << indexBits)) == (1 << indexBits));
          }
        }

        /// @brief Initializes a new instance of the BitArray class that contains bit values copied from the specified BitArray.
        /// @param This constructor is an O(n) operation, where n is the number of elements in bits. The BitArray to copy.
        /// @remarks This constructor is an O(n) operation, where n is the number of elements in bits.
        BitArray(const BitArray& bits) : bitArray(bits.bitArray), length(bits.length) {}

        /// @cond
        BitArray(BitArray&& bits) : bitArray(Move(bits.bitArray)), length(bits.length) {bits.length = 0;}
        /// @endcond

        /// @brief Initializes a new instance of the BitArray class that can hold the specified number of bit values, which are initially set to false.
        /// @param length The number of bit values in the new BitArray.
        /// @exception ArgumentOutOfRangeException length is less than 0.
        /// @remarks This constructor is an O(n) operation, where n is length.
        BitArray(int32 length) {
          if (length < 0)
            throw ArgumentOutOfRangeException(caller_);

          this->length = length;
          while (this->bitArray.Count < GetListLength(this->length))
            this->bitArray.Add(0);
        }

        /// @brief Initializes a new instance of the BitArray class that can hold the specified number of bit values, which are initially set to the specified value.
        /// @param length The number of bit values in the new BitArray.
        /// @param defaultValueThe bool value to assign to each bit.
        /// @exception ArgumentOutOfRangeException length is less than 0.
        /// @remarks This constructor is an O(n) operation, where n is length.
        BitArray(int32 length, bool defaultValue) {
          if (length < 0)
            throw ArgumentOutOfRangeException(caller_);

          this->length = length;
          while (this->bitArray.Count < GetListLength(this->length))
            this->bitArray.Add(defaultValue ? 0xFFFFFFFFL : 0);
        }

        /// @cond
        BitArray(InitializerList<bool> il) {
          this->length = (int32)il.size();
          while (this->bitArray.Count < GetListLength(this->length)) this->bitArray.Add(0);

          int32 index = 0;
          for (InitializerList<bool>::const_iterator iterator = il.begin(); iterator != il.end(); ++iterator)
            Set(index++, *iterator);
        }
        /// @endcond

        /// @brief Gets the number of elements contained in the BitArray.
        /// @return int32 The number of elements contained in the BitArray.
        /// @remarks Length and Count return the same value. Length can be set to a specific value.
        property_<int32, readonly_> Length {
          get_ {return this->length;}
        };

        /// @brief Performs the bitwise AND operation on the elements in the current BitArray against the corresponding elements in the specified BitArray.
        /// @param value The BitArray with which to perform the bitwise AND operation.
        /// @return BitArray The current instance containing the result of the bitwise AND operation on the elements in the current BitArray against the corresponding elements in the specified BitArray.
        /// @exception ArgumentNullException value is null.
        /// @exception ArgumentException value and the current BitArray do not have the same number of elements.
        /// @remarks The bitwise AND operation returns true if both operands are true, and returns false if one or both operands are false.
        /// @remarks This method is an O(n) operation, where n is Count.
        const BitArray& And(const BitArray& value) {

          if (this->Count != value.Count)
            throw System::ArgumentException(caller_);

          for (int32 index = 0; index < this->Count; index++)
            (*this)[index] = (*this)[index] & value[index];

          return *this;
        }

        /// @brief Creates a new object that is a copy of the current instance.
        /// @return object A new object that is a copy of this instance.
        /// @return @see object
        refptr<object> Clone() const override {
          return ref_new<BitArray>(*this);
        }

        /// @brief Determines whether this instance of BitArray and a specified object, which must also be a BitArray object, have the same value.
        /// @param value The BitArray to compare with the current object.
        /// @return bool true if the specified value is equal to the current object. otherwise, false.
        /// @exception ArgumentNullException The parameters value is null.
        /// @return @see object
        /// @return @see bool
        bool Equals(const BitArray& value) const {
          if (Length != value.Length)
            return false;

          for (int32 index = 0; index < Length; index++)
            if (Get(index) != value.Get(index))
              return false;

          return true;
        }

        /// @brief Determines whether this instance of BitArray and a specified object, which must also be a BitArray object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        /// @exception ArgumentNullException The parameters obj is null.
        /// @return @see object
        /// @return @see bool
        bool Equals(const object& obj) const override {
          return is<BitArray>(obj) && Equals(static_cast<const BitArray&>(obj));
        }

        /// @brief Gets the value of the bit at a specific position in the BitArray.
        /// @param index The zero-based index of the value to get.
        /// @return the value of the bit at position index.
        /// @exception ArgumentOutOfRangeException index is less than zero. -or- index is greater than or equal to the number of elements in the BitArray.
        /// @remarks This method is an O(1) operation.
        bool Get(int32 index) const {
          if (index >= this->length || index < 0)
            throw ArgumentOutOfRangeException(caller_);

          const_cast<BooleanRef&>(this->valueRef).FromBoolean(const_cast<BitArray*>(this));

          return const_cast<BooleanRef&>(this->valueRef).GetBooleanRef(GetBitValue(index), index);
        }

        /// @brief Gets the value of the bit at a specific position in the BitArray.
        /// @param index The zero-based index of the value to get.
        /// @return the value of the bit at position index.
        /// @exception ArgumentOutOfRangeException index is less than zero. -or- index is greater than or equal to the number of elements in the BitArray.
        /// @remarks This method is an O(1) operation.

        bool& Get(int32 index) {
          if (index >= this->length || index < 0)
            throw ArgumentOutOfRangeException(caller_);

          this->valueRef.FromBoolean(this);
          return this->valueRef.GetBooleanRef(GetBitValue(index), index);
        }

        /// @brief Returns an enumerator that iterates through a collection.
        /// @return IEnumerator An IEnumerator object that can be used to iterate through the collection.
        /// @return @see object
        Generic::Enumerator<bool> GetEnumerator() const override {
          return Generic::Enumerator<bool>(new BitArray::Enumerator(const_cast<BitArray*>(this)));
        }

        /// @brief Copies the elements of the BitArray to an Array, starting at a particular Array index.
        /// @param array The one-dimensional Array that is the destination of the elements copied from BitArray. The Array must have zero-based indexing.
        /// @param index The zero-based index in array at which copying begins;
        /// @return int32 Number of elements copied.
        /// @return @see object
        void CopyTo(Array<bool>& array, int32 index) const override {
          //return this->bitArray.CopyTo(array, index);
          throw NotSupportedException(caller_);
        }

        /// @brief Inverts all the bit values in the current BitArray, so that elements set to true are changed to false, and elements set to false are changed to true.
        /// @return BitArray The current instance with inverted bit values.
        /// @remarks This method is an O(n) operation, where n is Count.
        const BitArray& Not() {
          for (int32 index = 0; index < this->Count; index++)
            (*this)[index] = !((*this)[index]);

          return *this;
        }

        /// @brief Performs the bitwise OR operation on the elements in the current BitArray against the corresponding elements in the specified BitArray.
        /// @param value The BitArray with which to perform the bitwise OR operation.
        /// @return BitArray The current instance containing the result of the bitwise OR operation on the elements in the current BitArray against the corresponding elements in the specified BitArray.
        /// @exception ArgumentNullException value is null.
        /// @exception ArgumentException value and the current BitArray do not have the same number of elements.
        /// @remarks The bitwise OR operation returns true if one or both operands are true, and returns false if both operands are false.
        /// @remarks This method is an O(n) operation, where n is Count.
        const BitArray& Or(const BitArray& value) {
          if (this->Count != value.Count)
            throw ArgumentException(caller_);

          for (int32 index = 0; index < this->Count; index++)
            (*this)[index] = (*this)[index] | value[index];

          return *this;
        }

        /// @brief Sets the value of the bit at a specific position in the BitArray.
        /// @param index The zero-based index of the value to get.
        /// @param value The bool value to assign to the bit.
        /// @exception ArgumentOutOfRangeException index is less than zero. -or- index is greater than or equal to the number of elements in the BitArray.
        /// @remarks This method is an O(1) operation.
        void Set(int32 index, bool value) {
          (*this)[index] = value;
        }

        /// @brief Sets all bits in the BitArray to the specified value.
        /// @param value The bool value to assign to all bits.
        /// @remarks This method is an O(n) operation, where n is Count.
        void SetAll(bool value) {
          for (int32 index = 0; index < Length; index++)
            (*this)[index] = value;
        }

        /// @brief Performs the bitwise exclusive OR operation on the elements in the current BitArray against the corresponding elements in the specified BitArray.
        /// @param value The BitArray with which to perform the bitwise exclusive OR operation.
        /// @return BitArray The current instance containing the result of the bitwise exclusive OR operation on the elements in the current BitArray against the corresponding elements in the specified BitArray.
        /// @exception ArgumentNullException value is null.
        /// @exception ArgumentException value and the current BitArray do not have the same number of elements.
        /// @remarks The bitwise exclusive OR operation returns true if exactly one operand is true, and returns false if both operands have the same bool value.
        /// @remarks This method is an O(n) operation, where n is Count.
        const BitArray& Xor(const BitArray& value) {
          if (this->Count != value.Count)
            throw ArgumentException(caller_);

          for (int32 index = 0; index < this->Count; index++)
            (*this)[index] = (*this)[index] ^ value[index];

          return *this;
        }

        /// @brief Gets the element at the specified index.
        /// @param index The zero-based index of the element to get.
        /// @return bool The element at the specified index.
        /// @exception ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
        const bool& operator[](int32 index) const {
          if (index >= this->length || index < 0)
            throw ArgumentOutOfRangeException(caller_);

          const_cast<BooleanRef&>(this->valueRef).FromBoolean(const_cast<BitArray*>(this));

          return this->valueRef.GetBooleanRef(GetBitValue(index), index);
        }

        /// @brief Gets or Sets the element at the specified index.
        /// @param index The zero-based index of the element to get.
        /// @return bool The element at the specified index.
        /// @exception ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
        bool& operator[](int32 index) {
          if (index >= this->length || index < 0)
            throw ArgumentOutOfRangeException(caller_);

          this->valueRef.FromBoolean(this);
          return this->valueRef.GetBooleanRef(GetBitValue(index), index);
        }

      private:
        int32 GetCount() const override {return this->length;}
        bool GetIsReadOnly() const override {return this->bitArray.IsReadOnly;}
        bool GetIsSynchronized() const override {return this->bitArray.IsSynchronized;}
        const object& GetSyncRoot() const override {return this->bitArray.SyncRoot;}

        class Enumerator : public Object, public Generic::IEnumerator<bool> {
        public:
          Enumerator(BitArray* bitArray) : bitArray(bitArray) {}
          virtual bool MoveNext() {return ++this->pos < this->bitArray->Length;}
          void Reset() {this->pos = -1;}

        protected:
          const bool& GetCurrent() const {
            if (this->pos == -1 || this->pos >= this->bitArray->Length)
              throw InvalidOperationException(caller_);

            return (*this->bitArray)[this->pos];
          }

          int32 pos = -1;
          BitArray* bitArray = null;
        };

        static constexpr int32 BitsPerByte   = 8;
        static constexpr int32 BitsPerInt32  = 32;
        static constexpr int32 BytesPerInt32 = 4;

        inline int32 GetListPosition(int32 index) const {return index / BitsPerInt32;}

        inline int32 GetBitPosition(int32 index) const {return index % BitsPerInt32;}

        inline int32 GetListLength(int32 length) const {return this->GetListPosition(length) + (this->GetBitPosition(length) ? 1 : 0);}

        bool GetBitValue(int32 index) const {return (this->bitArray[GetListPosition(index)] & (1 << this->GetBitPosition(index))) == (1 << this->GetBitPosition(index));}

        void SetBitValue(int32 index, bool value) {
          if (value)
            this->bitArray[this->GetListPosition(index)] = this->bitArray[this->GetListPosition(index)] | (1 << (this->GetBitPosition(index)));
          else
            this->bitArray[this->GetListPosition(index)] = this->bitArray[this->GetListPosition(index)] & ~(1 << (this->GetBitPosition(index)));
        }

        class BooleanRef {
        public:
          BooleanRef() {}

          bool& GetBooleanRef(bool value, int32 index) {
            this->index = index;
            this->value = value;
            return this->value;
          }

          const bool& GetBooleanRef(bool value, int32 index) const {
            const_cast<BooleanRef*>(this)->index = index;
            const_cast<BooleanRef*>(this)->value = value;
            return this->value;
          }

          void FromBoolean(BitArray* parent) {
            if (this->index != -1)
              parent->SetBitValue(this->index, this->value);
            this->index = -1;
          }

          bool value = false;
          int32 index = -1;
        } valueRef;

        System::Collections::Generic::List<int32> bitArray;
        int32 length = 0;

        void Add(const bool&) override {throw InvalidOperationException(caller_);}
        void Clear() override {throw InvalidOperationException(caller_);}
        bool Contains(const bool&) const override {throw InvalidOperationException(caller_);}
        bool Remove(const bool&) override {throw InvalidOperationException(caller_);}
      };
    }
  }
}

using namespace Switch;

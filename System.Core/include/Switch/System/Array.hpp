/// @file
/// @brief Contains Switch::System::Array <T, int32 rank> class.
#pragma once

#include <array>
#include <tuple>

#include "../Allocator.hpp"
#include "../Interface.hpp"
#include "../InitializerList.hpp"
#include "../Move.hpp"
#include "../NullPtr.hpp"
#include "../Property.hpp"
#include "../Types.hpp"
#include "ArrayTypeMismatchException.hpp"
#include "Comparison.hpp"
#include "Converter.hpp"
#include "IndexOutOfRangeException.hpp"
#include "InvalidOperationException.hpp"
#include "Object.hpp"
#include "Predicate.hpp"
#include "RankException.hpp"
#include "_String.hpp"
#include "Tuple.hpp"
#include "Collections/Generic/IList.hpp"
#include "Collections/Generic/List.hpp"
#include "Linq/Enumerable.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    // defined in file ../Interface.hpp
    //template<typename T = NullPtr, int32 Rank = 1, typename TAllocator = Allocator<typename std::conditional<std::is_same<bool, T>::value, char, T>::type>>
    //class Array;

    template<>
    class Array<>;

    template<typename T, typename TAllocator>
    class GenericArrayObject;
    /// @endcond

    /// @brief Base object that represent Array.
    class ArrayObject : public object {
      template<typename T, typename TAllocator>
      friend class GenericArrayObject;
    public:
      ArrayObject() = default;
    };

    /// @brief Generic Base object that represent Array.
    template<typename T, typename TAllocator = Allocator<typename std::conditional<std::is_same<bool, T>::value, char, T>::type>>
    class GenericArrayObject : public ArrayObject, public Linq::Extension::Enumerable<GenericArrayObject<T, TAllocator>, T>, public Collections::Generic::IList<T> {
    public:
      /// @cond
      GenericArrayObject(const GenericArrayObject& array) : length(array.length), operationNumber(array.operationNumber), array(array.array), lowerBound(array.lowerBound), upperBound(array.upperBound) {}

      GenericArrayObject(GenericArrayObject&& array) : length(array.length), operationNumber(array.operationNumber), array(Move(array.array)), lowerBound(Move(array.lowerBound)), upperBound(Move(array.upperBound)) {
        array.length = 0;
        array.operationNumber = 0;
      }

      GenericArrayObject& operator=(const GenericArrayObject& array) {
        this->length = array.length;
        this->operationNumber = array.operationNumber;
        this->array = array.array;
        this->lowerBound = array.lowerBound;
        this->upperBound = array.upperBound;
        return *this;
      }

      friend core_export_ std::ostream& operator<<(std::ostream& output, const GenericArrayObject& value) {
        if (value.Length == 0)
          return output << "{empty}";

        output << "{";
        for (int index = 0; index < value.Length; index++)
          output << (index != 0 ? ", " : "") << value[index];
        return output << "}";
      }
      /// @endcond

      /// @brief Get access to raw data of the Array.
      /// @return A pointer to raw data of the array.
      property_<const T*, readonly_> Data {
        get_ {return (const T*)this->array.data();}
      };

      /// @brief Gets a 32-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @return int32 A 32-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @remarks Retrieving the value of this property is an O(1) operation.
      /// @par Examples
      /// The following code example demonstrates methods to get the length of an array.
      /// @include ArrayGetLength.cpp
      property_<int32, readonly_> Length {
        get_ {return (int32)this->array.size();}
      };

      /// @brief Gets a 64-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @return int64 A 64-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @remarks Retrieving the value of this property is an O(1) operation.
      property_<int64, readonly_> LongLength {
        get_ {return (int64)this->array.size();}
      };

      /// @brief Gets the rank (number of dimensions) of the Array.
      /// @return int32 The rank (number of dimensions) of the Array.
      /// @par Examples
      /// The following code example demonstrates methods to get the rank of an array.
      /// @include ArrayGetLength.cpp
      property_<int32, readonly_> Rank {
        get_ {return this->GetRank();}
      };

      /// @brief Returns an IEnumerator for the Array.
      /// @return IEnumerator An IEnumerator for the Array.
      /// @par Examples
      /// The following code example shows how to use GetEnumerator to list the elements of an array.
      /// @include ArrayGetEnumerator.cpp
      Collections::Generic::Enumerator<T> GetEnumerator() const override {
        class Enumerator : public object, public Collections::Generic::IEnumerator<T> {
        public:
          explicit Enumerator(const GenericArrayObject& array) : array(array), operationNumber(array.operationNumber), iterator(array.array.begin()) {}
          void Reset() override {this->beforeFirst = true; this->operationNumber = this->array.operationNumber; this->iterator = this->array.array.begin();}

          bool MoveNext() override {
            if (this->operationNumber != this->array.operationNumber) throw System::InvalidOperationException(caller_);
            if (this->iterator == this->array.array.end()) return false;
            if (this->beforeFirst) {
              this->beforeFirst = false;
              return this->iterator != this->array.array.end();
            }
            return ++this->iterator != this->array.array.end();
          }

        protected:
          #if defined(_WIN32)
#pragma warning(push)
#pragma warning(disable:4172)
#pragma warning(disable:4800)
          #endif
          const T& GetCurrent() const override {
            if (this->beforeFirst || this->iterator == this->array.array.end()) throw System::InvalidOperationException(caller_);
            return (const T&) * this->iterator;
          }
          #if defined(_WIN32)
#pragma warning(pop)
          #endif

          const GenericArrayObject& array;
          bool beforeFirst = true;
          int64 operationNumber;
          typename std::vector<typename std::conditional<std::is_same<bool, T>::value, char, T>::type, TAllocator>::const_iterator iterator;
        };

        return System::Collections::Generic::Enumerator<T>(new Enumerator(*this));
      }

      /// @brief Determines whether an element is in the Array.
      /// @param value The object to be added to the end of the Array. The value can ! be null for reference types.
      bool Contains(const T& value) const override { return this->IndexOf(value) != -1; }

      bool Equals(const object& obj) const override {return (is<GenericArrayObject>(obj)) && this->Equals((const GenericArrayObject<T, TAllocator>&)obj);}

      bool Equals(const GenericArrayObject& array) const {return this->length == array.length && this->array == array.array && this->lowerBound == array.lowerBound && this->upperBound == array.upperBound && this->GetRank() == array.GetRank();}

      /// @brief Gets a 32-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @param dimension A zero-based dimension of the Array whose length needs to be determined.
      /// @return int32 A 32-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @exception ArgumentOutOfRangeException dimension is less than zero. -or- dimension is equal to or greater than rank.
      /// @par Examples
      /// The following code example demonstrates methods to get the length of an array.
      /// @include ArrayGetLength.cpp
      int32 GetLength(int32 dimension) const {return this->GetUpperBound(dimension) + 1;}

      /// @brief Gets the lower bound of the specified dimension in the Array.
      /// @param dimension A zero-based dimension of the Array whose lower bound needs to be determined.
      /// @return int32 The lower bound of the specified dimension in the Array.
      /// @exception ArgumentOutOfRangeException dimension is less than zero. -or- dimension is equal to or greater than rank.
      /// @par Examples
      /// The following code example uses GetLowerBound and GetUpperBound to initialize a one-dimensional array and a multidimensional array.
      /// @include ArrayGetLowerBound.cpp
      int32 GetLowerBound(int32 dimension) const {
        if (dimension < 0 || dimension >= this->Rank) throw System::ArgumentOutOfRangeException(caller_);

        return this->lowerBound[dimension];
      }

      /// @brief Gets the upper bound of the specified dimension in the Array.
      /// @param dimension A zero-based dimension of the Array whose upper bound needs to be determined.
      /// @return int32 The upper bound of the specified dimension in the Array.
      /// @exception ArgumentOutOfRangeException dimension is less than zero. -or- dimension is equal to or greater than rank.
      /// @par Examples
      /// The following code example uses GetLowerBound and GetUpperBound to initialize a one-dimensional array and a multidimensional array.
      /// @include ArrayGetLowerBound.cpp
      int32 GetUpperBound(int32 dimension) const {
        if (dimension < 0 || dimension >= this->Rank) throw System::ArgumentOutOfRangeException(caller_);

        return this->upperBound[dimension];
      }

      /// @brief Determines the index of a specific item in the Array.
      /// @param value The object to locate in the Array.
      /// @return int32 The index of value if found in the Array; otherwise, -1.
      int32 IndexOf(const T& value) const override { return IndexOf(*this, value); }

      /// @brief Determines the index of a specific item in the array specified.
      /// @param array The object to locate in the Array.
      /// @param value The object to locate in the Array.
      /// @return int32 The index of value if found in the Array; otherwise, -1.
      /// @par Examples
      /// The following code example shows how to determine the index of the first occurrence of a specified element.
      /// @include ArrayIndexOf.cpp
      static int32 IndexOf(const GenericArrayObject& array, const T& value) { return IndexOf(array, value, 0, array.Length); }

      /// @brief Determines the index of a specific item in the array specified.
      /// @param array The object to locate in the Array.
      /// @param value The object to locate in the Array.
      /// @param index The zero-based starting index of the search.
      /// @return int32 The index of value if found in the Array; otherwise, -1.
      /// @exception ArgumentOutOfRangeException The parameters index is less than 0.
      /// @par Examples
      /// The following code example shows how to determine the index of the first occurrence of a specified element.
      /// @include ArrayIndexOf.cpp
      static int32 IndexOf(const GenericArrayObject& array, const T& value, int32 index) { return IndexOf(array, value, index, array.Length - index); }

      /// @brief Determines the index of a specific item in the array specified.
      /// @param array The object to locate in the Array.
      /// @param value The object to locate in the Array.
      /// @param index The zero-based starting index of the search.
      /// @param count The number of elements in the section to search
      /// @return int32 The index of value if found in the list; otherwise, -1.
      /// @exception ArgumentOutOfRangeException The parameters index is less than 0 or The parameters count is less than 0 or index and count do ! specify a valid section in the Array.
      /// @par Examples
      /// The following code example shows how to determine the index of the first occurrence of a specified element.
      /// @include ArrayIndexOf.cpp
      static int32 IndexOf(const GenericArrayObject& array, const T& value, int32 index, int32 count) {
        if (index < 0 || count < 0)
          throw System::ArgumentOutOfRangeException(caller_);
        if (index + count > array.Length)
          throw System::ArgumentException(caller_);

        for (int32 increment = 0; increment < count; increment++) {
          if (array[index + increment] == value)
            return index + increment;
        }
        return -1;
      }

      /// @cond
      using const_iterator = typename std::vector<typename std::conditional<std::is_same<bool, T>::value, char, T>::type, TAllocator>::const_iterator;
      using iterator = typename std::vector<typename std::conditional<std::is_same<bool, T>::value, char, T>::type, TAllocator>::iterator;

      const_iterator cbegin() const {return this->array.begin();}
      const_iterator cend() const {return this->array.end();}
      iterator begin() {return this->array.begin();}
      const_iterator begin() const {return this->array.begin();}
      iterator end() {return this->array.end();}
      const_iterator end() const {return this->array.end();}
      /// @endcond

      void Resize(int32 newSize) {
        if (newSize < 0) throw System::ArgumentOutOfRangeException(caller_);
        if (newSize == this->length) return;

        this->operationNumber += 1;
        if (newSize < this->length)
          this->array.resize(newSize);
        else
          for (int32 i = this->length; i < newSize; ++i)
            this->array.push_back(T());
        this->length = newSize;
        this->upperBound[0] = newSize - 1;
      }

    protected:
      /// @cond
      T& operator[](int32 index) override {
        if (index >= this->Length || index < 0) throw System::ArgumentOutOfRangeException(caller_);

        return (T&)this->array[index];
      }

      const T& operator[](int32 index) const override {
        if (index >= this->Length || index < 0) throw System::ArgumentOutOfRangeException(caller_);

        return (T&)this->array[index];
      }

      void CopyTo(Array<T>& array, int32 index) const override {
        if (index < 0) throw System::ArgumentOutOfRangeException(caller_);
        if (index + this->Length > array.Length) throw System::ArgumentException(caller_);

        for (int32 increment = 0; increment < this->Length; increment++)
          array[index + increment] = (*this)[increment];
      }

      void Reverse() {
        this->operationNumber++;
        std::reverse(this->array.begin(), this->array.end());
      }

      void Reverse(int32 index, int32 count) {
        if (index < 0 || count < 0) throw ArgumentOutOfRangeException(caller_);
        if (index + count > this->Count) throw ArgumentException(caller_);

        this->operationNumber++;
        int pos1 = index, pos2 = (index + count) - 1;
        typename std::vector<T, TAllocator>::iterator it1 = this->array.begin() + pos1, it2 = this->array.begin() + pos2;

        while (pos1++ < pos2--)
          std::iter_swap(it1++, it2--);
      }
      /// @endcond

    private:
      template<typename TArray, int32 RankArray, typename TAllocatorArray>
      friend class Array;

      GenericArrayObject() {
        this->lowerBound.push_back(0);
        this->upperBound.push_back(-1);
      }

      GenericArrayObject(const Array<int32, 1>& lengths);

      GenericArrayObject(const T* array, int32 length) : length(length), array(length) {
        if (array == null) throw System::ArgumentNullException(caller_);
        if (length < 0) throw System::ArgumentOutOfRangeException(caller_);

        for (int32 index = 0; index < length; index++)
          this->array[index] = array[index];
        this->lowerBound.push_back(0);
        this->upperBound.push_back(length - 1);
      }

      explicit GenericArrayObject(const Collections::Generic::IEnumerable<T>& enumerable) {
        for (const auto& value : enumerable)
          this->array.push_back(value);
        this->length = (int32)this->array.size();
        this->lowerBound.push_back(0);
        this->upperBound.push_back(this->length - 1);
      }

      explicit GenericArrayObject(const std::vector<T>& array) : length((int32)array.size()) {
        for (T value : array)
          this->array.push_back(value);
        this->lowerBound.push_back(0);
        this->upperBound.push_back(length - 1);
      }


      GenericArrayObject(InitializerList<T> il) : length((int32)il.size()) {
        for (T value : il)
          this->array.push_back(value);
        this->lowerBound.push_back(0);
        this->upperBound.push_back((int32)il.size() - 1);
      }

      GenericArrayObject(InitializerList<InitializerList<T>> il)  {
        for (const InitializerList<T>& il1 : il)
          for (T value : il1)
            this->array.push_back(value);
        this->lowerBound.push_back(0);
        this->upperBound.push_back((int32)il.size() - 1);
        this->lowerBound.push_back(0);
        this->upperBound.push_back((int32)(*il.begin()).size() - 1);
      }

      GenericArrayObject(InitializerList<InitializerList<InitializerList<T>>> il)  {
        for (const InitializerList<InitializerList<T>>& il1 : il)
          for (const InitializerList<T>& il2 : il1)
            for (T value : il2)
              this->array.push_back(value);
        this->lowerBound.push_back(0);
        this->upperBound.push_back((int32)il.size() - 1);
        this->lowerBound.push_back(0);
        this->upperBound.push_back((int32)(*il.begin()).size() - 1);
        this->lowerBound.push_back(0);
        this->upperBound.push_back((int32)(*(*il.begin()).begin()).size() - 1);
      }

      class Comparer : public std::binary_function<T, T, bool> {
      public:
        Comparer(const System::Collections::Generic::IComparer<T>* comparer) : comparer(comparer) { }
        Comparer(const Comparer& comparer) { *this = comparer; }
        Comparer& operator=(const Comparer& comparer) {this->comparer = comparer.comparer; return *this;}
        bool operator()(const T& e1, const T& e2) const { return this->comparer->Compare(e1, e2) < 0; }
      private:
        const System::Collections::Generic::IComparer<T>* comparer;
      };

      class ComparisonComparer : public std::binary_function<T, T, bool> {
      private:
        Comparison<const T&> comparer;

      public:
        ComparisonComparer(Comparison<const T&> c) : comparer(c) { }
        ComparisonComparer(const ComparisonComparer& mc) { *this = mc; }
        ~ComparisonComparer() { }

        ComparisonComparer& operator=(const ComparisonComparer& mc) { comparer = mc.comparer; return *this; }
        bool operator()(const T& e1, const T& e2) const { return comparer(e1, e2) < 0; }
      };

      virtual int32 GetRank() const = 0;

      bool GetIsFixedSize() const override { return true; }
      bool GetIsReadOnly() const override { return true; }
      bool GetIsSynchronized() const override { return false; }
      const object& GetSyncRoot() const override { return this->syncRoot; }

      int32 GetCount() const override {return static_cast<int32>(this->array.size());}
      void Insert(int32, const T&) override { throw InvalidOperationException(caller_); }
      void RemoveAt(int32) override { throw InvalidOperationException(caller_); }
      void Add(const T&) override { throw InvalidOperationException(caller_); }
      void Clear() override { throw InvalidOperationException(caller_); }
      bool Remove(const T&) override { throw InvalidOperationException(caller_); }

      int32 length = 0;
      int64 operationNumber = 0;
      //std::vector<T, TAllocator> array;
      std::vector<typename std::conditional<std::is_same<bool, T>::value, char, T>::type, TAllocator> array;
      std::vector<int32> lowerBound;
      std::vector<int32> upperBound;
      object syncRoot;
    };

    /// @brief Provides methods for creating, manipulating, searching, and sorting arrays, thereby serving as the base class for all arrays.
    /// @remarks The Array class is not part of the System.Collections namespaces. However, it is still considered a collection because it is based on the IList interface.
    /// @remarks An element is a value in an Array. The length of an Array is the total number of elements it can contain. The lower bound of an Array is the index of its first element. An Array can have any lower bound, but it has a lower bound of zero by default. A different lower bound can be defined when creating an instance of the Array class using CreateInstance.A multidimensional Array can have different bounds for each dimension. An array can have a maximum of 32 dimensions.
    /// @remarks Unlike the classes in the System.Collections namespaces, Array has a fixed capacity. To increase the capacity, you must create a new Array object with the required capacity, copy the elements from the old Array object to the new one, and delete the old Array.
    /// @remarks The Array class implements the System.Collections.Generic.IList<T>, System.Collections.Generic.ICollection<T>, and System.Collections.Generic.IEnumerable<T> generic interfaces. The implementations are provided to arrays at run time, and as a result, the generic interfaces do not appear in the declaration syntax for the Array class. In addition, there are no reference topics for interface members that are accessible only by casting an array to the generic interface type (explicit interface implementations). The key thing to be aware of when you cast an array to one of these interfaces is that members which add, insert, or remove elements throw NotSupportedException.
    /// @remarks The Array.Copy method copies elements not only between arrays of the same type but also between standard arrays of different types; it handles type casting automatically.
    /// @remarks Some methods, such as CreateInstance, Copy, CopyTo, GetValue, and SetValue, provide overloads that accept 64-bit integers as parameters to accommodate large capacity arrays. LongLength and GetLongLength return 64-bit integers indicating the length of the array.
    /// @remarks The Array is not guaranteed to be sorted. You must sort the Array prior to performing operations (such as BinarySearch) that require the Array to be sorted.
    /// @par Examples
    /// The following code example demonstrates different methods to create an array.
    /// @include Array1.cpp
    /// @par Examples
    /// The following code example creates and initializes an Array and displays its properties and its elements.
    /// @include Array2.cpp
    template<typename T, int32 rank, typename TAllocator>
    class Array : public GenericArrayObject<T, TAllocator>, public ICloneable {
    public:
      /// @brief Initializes a new instance of the Array class that is empty.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      Array() {}

      /// @brief Initializes a new instance of the Array class with lengths for each rank specified.
      /// @param lengths the lengths for each rank.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      Array(const Array<int32>& lengths) : GenericArrayObject<T, TAllocator>(lengths) {}

      /// @cond
      Array(const Array& array) : GenericArrayObject<T, TAllocator>((GenericArrayObject<T, TAllocator>&)array) {}
      Array(const Array&& array) : GenericArrayObject<T, TAllocator>(Move((GenericArrayObject<T, TAllocator> &&)array)) {}
      Array& operator=(const Array& array) {
        this->GenericArrayObject<T, TAllocator>::operator=(array);
        return *this;
      }

      friend core_export_ std::ostream& operator<<(std::ostream& output, const Array& value) {
        if (value.Length == 0)
          return output << "{empty}";

        output << "{";
        for (int index = 0; index < value.Length; index++)
          output << (index != 0 ? ", " : "") << value(index);
        return output << "}";
      }
      /// @endcond

      /// @brief Get access to raw data of the Array.
      /// @return A pointer to raw data of the array.
      property_<const T*, readonly_> Data {
        get_{return this->GenericArrayObject<T, TAllocator>::Data();}
      };

      /// @brief Gets a 32-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @return int32 A 32-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @remarks Retrieving the value of this property is an O(1) operation.
      /// @par Examples
      /// The following code example demonstrates methods to get the length of an array.
      /// @include ArrayGetLength.cpp
      property_<int32, readonly_> Length {
        get_ {return this->GenericArrayObject<T, TAllocator>::Length();}
      };

      /// @brief Gets a 64-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @return int64 A 64-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @remarks Retrieving the value of this property is an O(1) operation.
      property_<int64, readonly_> LongLength {
        get_ {return this->GenericArrayObject<T, TAllocator>::LongLength();}
      };

      /// @brief Gets the rank (number of dimensions) of the Array.
      /// @return int32 The rank (number of dimensions) of the Array.
      /// @par Examples
      /// The following code example demonstrates methods to get the rank of an array.
      /// @include ArrayGetLength.cpp
      property_<int32, readonly_> Rank {
        get_ {return this->GenericArrayObject<T, TAllocator>::Rank();}
      };

      /// @brief Creates a shallow copy of the Array.
      /// @return object A shallow copy of the Array.
      /// @remarks A shallow copy of an Array copies only the elements of the Array, whether they are reference types or value types, but it does not copy the objects that the references refer to. The references in the new Array point to the same objects that the references in the original Array point to.
      /// @remarks In contrast, a deep copy of an Array copies the elements and everything directly or indirectly referenced by the elements.
      /// @remarks The clone is of the same Type as the original Array.
      /// @remarks This method is an O(n) operation, where n is Length.
      refptr<object> Clone() const override {return ref_new<Array<T, rank, TAllocator>>(*this);}

      bool Equals(const object& obj) const override {return this->GenericArrayObject<T, TAllocator>::Equals(obj);}

    private:
      friend class Array<>;
      Array(const Array<int32>& lengths, bool) : GenericArrayObject<T, TAllocator>(lengths) {}
      int32 GetRank() const override {return rank;}
    };

    /// @brief Provides methods for creating, manipulating, searching, and sorting arrays, thereby serving as the base class for all arrays.
    /// @remarks The Array class is not part of the System.Collections namespaces. However, it is still considered a collection because it is based on the IList interface.
    /// @remarks An element is a value in an Array. The length of an Array is the total number of elements it can contain. The lower bound of an Array is the index of its first element. An Array can have any lower bound, but it has a lower bound of zero by default. A different lower bound can be defined when creating an instance of the Array class using CreateInstance.A multidimensional Array can have different bounds for each dimension. An array can have a maximum of 32 dimensions.
    /// @remarks Unlike the classes in the System.Collections namespaces, Array has a fixed capacity. To increase the capacity, you must create a new Array object with the required capacity, copy the elements from the old Array object to the new one, and delete the old Array.
    /// @remarks The Array class implements the System.Collections.Generic.IList<T>, System.Collections.Generic.ICollection<T>, and System.Collections.Generic.IEnumerable<T> generic interfaces. The implementations are provided to arrays at run time, and as a result, the generic interfaces do not appear in the declaration syntax for the Array class. In addition, there are no reference topics for interface members that are accessible only by casting an array to the generic interface type (explicit interface implementations). The key thing to be aware of when you cast an array to one of these interfaces is that members which add, insert, or remove elements throw NotSupportedException.
    /// @remarks The Array.Copy method copies elements not only between arrays of the same type but also between standard arrays of different types; it handles type casting automatically.
    /// @remarks Some methods, such as CreateInstance, Copy, CopyTo, GetValue, and SetValue, provide overloads that accept 64-bit integers as parameters to accommodate large capacity arrays. LongLength and GetLongLength return 64-bit integers indicating the length of the array.
    /// @remarks The Array is not guaranteed to be sorted. You must sort the Array prior to performing operations (such as BinarySearch) that require the Array to be sorted.
    /// @par Examples
    /// The following code example demonstrates different methods to create an array.
    /// @include Array1.cpp
    /// @par Examples
    /// The following code example creates and initializes an Array and displays its properties and its elements.
    /// @include Array2.cpp
    template<typename T, typename TAllocator>
    class Array<T, 1, TAllocator> : public GenericArrayObject<T, TAllocator>, public ICloneable {
    public:
      /// @brief Initializes a new instance of the Array class that is empty.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      Array() {}

      /// @brief Initializes a new instance of the Array class with lengths for each rank specified.
      /// @param length the length for the first rank.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      Array(int32 length) : GenericArrayObject<T, TAllocator>(Array<int32> {length}) {}

      /// @brief Initializes a new instance of the Array and copy array[] T.
      /// @param array the Array to copy.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      template<int32 length>
      explicit Array(const T(&array)[length]) : GenericArrayObject<T, TAllocator>(array, length) {}

      /// @brief Initializes a new instance of the Array and copy array[] T with length specified.
      /// @param array the Array to copy.
      /// @param length Length of the array.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      Array(const T* array, int32 length) : GenericArrayObject<T, TAllocator>(array, length) {}

      /// @brief Initializes a new instance of the Array and copy array Array specified.
      /// @param array the Array to copy.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      explicit Array(const Collections::Generic::IEnumerable<T>& enumerable) : GenericArrayObject<T, TAllocator>(enumerable) {}

      /// @brief Initializes a new instance of the Array and copy array Array specified.
      /// @param array the Array to copy.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      explicit Array(const Collections::Generic::IList<T>& list) : GenericArrayObject<T, TAllocator>(list) {}

      /// @cond
      Array(const Array& array) : GenericArrayObject<T, TAllocator>((GenericArrayObject<T, TAllocator>&)array) {}
      Array(const Array&& array) : GenericArrayObject<T, TAllocator>(Move((GenericArrayObject<T, TAllocator> &&)array)) {}
      explicit Array(const std::vector<T>& array) : GenericArrayObject<T, TAllocator>(array) {}
      Array(InitializerList<T> il) : GenericArrayObject<T, TAllocator>(il) {}

      Array& operator=(const Array& array) {
        this->GenericArrayObject<T, TAllocator>::operator=(array);
        return *this;
      }

      friend core_export_ std::ostream& operator<<(std::ostream& output, const Array& value) {
        if (value.Length == 0)
          return output << "{empty}";

        output << "{";
        for (int index = 0; index < value.Length; index++)
          output << (index != 0 ? ", " : "") << value(index);
        return output << "}";
      }
      /// @endcond

      /// @brief Sets a value to the element at the specified position in the one-dimensional Array. The index is specified as a 32-bit integer.
      /// @param value The new value for the specified element.
      /// @param index A 32-bit integer that represents the position of the Array element to set.
      /// @exception ArgumentException The current Array does ! have exactly one dimension.
      /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array.
      /// @par Examples
      /// The following code example shows how to use operator () to list the elements of an array.
      /// @include ArrayArrayOperatorFunctor.cpp
      T& operator()(int32 index) {return this->GenericArrayObject<T, TAllocator>::operator[](index);}

      /// @brief Gets the value at the specified position in the one-dimensional Array. The index is specified as a 32-bit integer.
      /// @param index A 32-bit integer that represents the position of the Array element to get.
      /// @return The value at the specified position in the one-dimensional Array.
      /// @exception ArgumentException The current Array does ! have exactly one dimension.
      /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array.
      /// @par Examples
      /// The following code example shows how to use operator () to list the elements of an array.
      /// @include ArrayArrayOperatorFunctor.cpp
      const T& operator()(int32 index) const {return this->GenericArrayObject<T, TAllocator>::operator[](index);}

      /// @brief Sets a value to the element at the specified position in the one-dimensional Array. The index is specified as a 32-bit integer.
      /// @param value The new value for the specified element.
      /// @param index A 32-bit integer that represents the position of the Array element to set.
      /// @exception ArgumentException The current Array does ! have exactly one dimension.
      /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array.
      /// @par Examples
      /// The following code example shows how to use operator [] to list the elements of an array.
      /// @include ArrayArrayOperator.cpp
      T& operator[](int32 index) override {return this->GenericArrayObject<T, TAllocator>::operator[](index);}

      /// @brief Gets the element at the specified index.
      /// @param index The zero-based index of the element to get.
      /// @return The value at the specified position in the one-dimensional Array.
      /// @exception ArgumentException The current Array does ! have exactly one dimension.
      /// @exception IndexOutOfRangeException index is less than 0 or index is equal to or greater than Count.
      /// @par Examples
      /// The following code example shows how to use operator [] to list the elements of an array.
      /// @include ArrayArrayOperator.cpp
      const T& operator[](int32 index) const override {return this->GenericArrayObject<T, TAllocator>::operator[](index);}

      /// @brief Copies all the elements of the current one-dimensional array to the specified one-dimensional array starting at the specified destination array index. The index is specified as a 32-bit integer.
      /// @param array The one-dimensional array that is the destination of the elements copied from the current array.
      /// @param index A 32-bit integer that represents the index in array at which copying begins.
      /// @exception ArgumentOutOfRangeException index is less than the lower bound of array.
      /// @exception ArgumentException array is multidimensional.  -or-  The number of elements in the source array is greater than the available number of elements from index to the end of the destination array.
      /// @exception ArrayTypeMismatchException The type of the source Array cannot be cast automatically to the type of the destination array.
      /// @exception RankException The source array is multidimensional.
      /// @exception InvalidCastException At least one element in the source Array cannot be cast to the type of destination array.
      /// @remarks This method copies all the elements of the current array instance to the array destination array, starting at index index. The array destination array must already have been dimensioned and must have a sufficient number of elements to accommodate the copied elements. Otherwise, the method throws an exception.
      /// @remarks This method supports the System.Collections.ICollection interface. If implementing System.Collections.ICollection is not explicitly required, use Copy to avoid an extra indirection.
      /// @remarks If this method throws an exception while copying, the state of array is undefined.
      /// @remarks This method is an O(n) operation, where n is Length.It performs a shallow copy only.
      /// @par Examples
      /// The following code example shows how to copy an Array to another native Array.
      /// @include ArrayCopyTo.cpp
      void CopyTo(Array<T>& array, int32 index) const override {this->GenericArrayObject<T, TAllocator>::CopyTo(array, index);}

      /// @brief Copies all the elements of the current one-dimensional array to the specified one-dimensional array starting at the specified destination array index. The index is specified as a 64-bit integer.
      /// @param array The one-dimensional array that is the destination of the elements copied from the current array.
      /// @param ibdex A 64-bit integer that represents the index in array at which copying begins.
      /// @exception ArgumentOutOfRangeException index is less than the lower bound of array.
      /// @exception ArgumentException array is multidimensional.  -or-  The number of elements in the source array is greater than the available number of elements from index to the end of the destination array.
      /// @exception ArrayTypeMismatchException The type of the source Array cannot be cast automatically to the type of the destination array.
      /// @exception RankException The source array is multidimensional.
      /// @exception InvalidCastException At least one element in the source Array cannot be cast to the type of destination array.
      /// @remarks This method copies all the elements of the current array instance to the array destination array, starting at index index. The array destination array must already have been dimensioned and must have a sufficient number of elements to accommodate the copied elements. Otherwise, the method throws an exception.
      /// @remarks This method supports the System.Collections.ICollection interface. If implementing System.Collections.ICollection is not explicitly required, use Copy to avoid an extra indirection.
      /// @remarks If this method throws an exception while copying, the state of array is undefined.
      /// @remarks This method is an O(n) operation, where n is Length.It performs a shallow copy only.
      void CopyTo(Array<T>& array, int64 index) const {
        if (index < 0) throw System::ArgumentOutOfRangeException(caller_);
        if (index + this->Length > array.Length) throw System::ArgumentException(caller_);

        for (int32 increment = 0; increment < this->Length; increment++)
          array[index + increment] = (*this)[increment];
      }

      /// @brief Creates a shallow copy of the Array.
      /// @return object A shallow copy of the Array.
      /// @remarks A shallow copy of an Array copies only the elements of the Array, whether they are reference types or value types, but it does not copy the objects that the references refer to. The references in the new Array point to the same objects that the references in the original Array point to.
      /// @remarks In contrast, a deep copy of an Array copies the elements and everything directly or indirectly referenced by the elements.
      /// @remarks The clone is of the same Type as the original Array.
      /// @remarks This method is an O(n) operation, where n is Length.
      refptr<object> Clone() const override {return ref_new<Array<T, 1, TAllocator>>(*this);}

      bool Equals(const object& obj) const override {return this->GenericArrayObject<T, TAllocator>::Equals(obj);}

      /// @brief Gets the value at the specified position in the one-dimensional Array. The index is specified as a 32-bit integer.
      /// @param index A 32-bit integer that represents the position of the Array element to get.
      /// @return The value at the specified position in the one-dimensional Array.
      /// @exception ArgumentException The current Array does ! have exactly one dimension.
      /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array.
      const T& GetValue(int32 index) const { return this->operator()(index); }

      /// @brief Sets a value to the element at the specified position in the one-dimensional Array. The index is specified as a 32-bit integer.
      /// @param value The new value for the specified element.
      /// @param index A 32-bit integer that represents the position of the Array element to set.
      /// @exception ArgumentException The current Array does ! have exactly one dimension.
      /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array.
      void SetValue(const T& value, int32 index) { this->operator()(index) = value; }

    private:
      friend class Array<>;
      Array(const Array<int32>& lengths, bool) : GenericArrayObject<T, TAllocator>(lengths) {}
      int32 GetRank() const override {return 1;}
    };

    /// @brief Provides methods for creating, manipulating, searching, and sorting arrays, thereby serving as the base class for all arrays.
    /// @remarks The Array class is not part of the System.Collections namespaces. However, it is still considered a collection because it is based on the IList interface.
    /// @remarks An element is a value in an Array. The length of an Array is the total number of elements it can contain. The lower bound of an Array is the index of its first element. An Array can have any lower bound, but it has a lower bound of zero by default. A different lower bound can be defined when creating an instance of the Array class using CreateInstance.A multidimensional Array can have different bounds for each dimension. An array can have a maximum of 32 dimensions.
    /// @remarks Unlike the classes in the System.Collections namespaces, Array has a fixed capacity. To increase the capacity, you must create a new Array object with the required capacity, copy the elements from the old Array object to the new one, and delete the old Array.
    /// @remarks The Array class implements the System.Collections.Generic.IList<T>, System.Collections.Generic.ICollection<T>, and System.Collections.Generic.IEnumerable<T> generic interfaces. The implementations are provided to arrays at run time, and as a result, the generic interfaces do not appear in the declaration syntax for the Array class. In addition, there are no reference topics for interface members that are accessible only by casting an array to the generic interface type (explicit interface implementations). The key thing to be aware of when you cast an array to one of these interfaces is that members which add, insert, or remove elements throw NotSupportedException.
    /// @remarks The Array.Copy method copies elements not only between arrays of the same type but also between standard arrays of different types; it handles type casting automatically.
    /// @remarks Some methods, such as CreateInstance, Copy, CopyTo, GetValue, and SetValue, provide overloads that accept 64-bit integers as parameters to accommodate large capacity arrays. LongLength and GetLongLength return 64-bit integers indicating the length of the array.
    /// @remarks The Array is not guaranteed to be sorted. You must sort the Array prior to performing operations (such as BinarySearch) that require the Array to be sorted.
    /// @par Examples
    /// The following code example demonstrates different methods to create an array.
    /// @include Array1.cpp
    /// @par Examples
    /// The following code example creates and initializes an Array and displays its properties and its elements.
    /// @include Array2.cpp
    template<typename T, typename TAllocator>
    class Array<T, 2, TAllocator> : public GenericArrayObject<T, TAllocator>, public ICloneable {
    public:
      /// @brief Initializes a new instance of the Array class that is empty.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      Array() {}

      /// @brief Initializes a new instance of the Array class with lengths for each rank specified.
      /// @param length1 the length for the first rank.
      /// @param length2 the length for the second rank.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      Array(int32 length1, int32 length2) : GenericArrayObject<T, TAllocator>(Array<int32> {length1, length2}) {}

      /// @cond
      Array(const Array& array) : GenericArrayObject<T, TAllocator>((GenericArrayObject<T, TAllocator>&)array) {}
      Array(const Array&& array) : GenericArrayObject<T, TAllocator>(Move((GenericArrayObject<T, TAllocator> &&)array)) {}
      Array(InitializerList<InitializerList<T>> il) : GenericArrayObject<T, TAllocator>(il) {}
      Array(const Array<int32>& lengths) : GenericArrayObject<T, TAllocator>(lengths) {}
      Array& operator=(const Array& array) {
        this->GenericArrayObject<T, TAllocator>::operator=(array);
        return *this;
      }

      friend core_export_ std::ostream& operator<<(std::ostream& output, const Array& value) {
        if (value.Length == 0)
          return output << "{empty}";

        output << "{";
        for (int index1 = 0; index1 < value.GetLength(0); index1++) {
          output << (index1 == 0 ? "{" : ", {");
          for (int index2 = 0; index2 < value.GetLength(1); index2++)
            output << (index2 != 0 ? ", " : "") << value(index1, index2);
          output << "}";
        }
        return output << "}";
      }
      /// @endcond

      /// @brief Sets the element at in multidimension array the specified index.
      /// @param index The zero-based index of the element to set.
      /// @return T The modified element at the specified index.
      /// @exception ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
      /// @par Examples
      /// The following code example shows how to use operator [] to list the elements of an array.
      /// @include ArrayArrayOperatorFunctor.cpp
      T& operator()(int32 index1, int32 index2) {
        if (index2 >= this->GetLength(1) || index2 < 0) throw System::IndexOutOfRangeException(caller_);
        if (index1 >= this->GetLength(0) || index1 < 0) throw System::IndexOutOfRangeException(caller_);

        return this->array[index2 + (index1 * this->GetLength(1))];
      }

      /// @brief Gets the value at the specified position in the two-dimensional Array. The index is specified as a 32-bit integer.
      /// @param index1 A 32-bit integer that represents the first-dimension index of the Array element to get.
      /// @param index2 A 32-bit integer that represents the second-dimension index of the Array element to get.
      /// @return The value at the specified position in the two-dimensional Array.
      /// @exception ArgumentException The current Array does ! have exactly two dimension.
      /// @exception IndexOutOfRangeException Either index1 or index2 is outside the range of valid indexes for the corresponding dimension of the current Array.
      /// @par Examples
      /// The following code example shows how to use operator [] to list the elements of an array.
      /// @include ArrayArrayOperatorFunctor.cpp
      const T& operator()(int32 index1, int32 index2) const {
        if (index2 >= this->GetLength(1) || index2 < 0) throw System::ArgumentOutOfRangeException(caller_);
        if (index1 >= this->GetLength(0) || index1 < 0) throw System::ArgumentOutOfRangeException(caller_);

        return this->array[index2 + (index1 * this->GetLength(1))];
      }

      /// @brief Creates a shallow copy of the Array.
      /// @return object A shallow copy of the Array.
      /// @remarks A shallow copy of an Array copies only the elements of the Array, whether they are reference types or value types, but it does not copy the objects that the references refer to. The references in the new Array point to the same objects that the references in the original Array point to.
      /// @remarks In contrast, a deep copy of an Array copies the elements and everything directly or indirectly referenced by the elements.
      /// @remarks The clone is of the same Type as the original Array.
      /// @remarks This method is an O(n) operation, where n is Length.
      refptr<object> Clone() const override {return ref_new<Array<T, 2, TAllocator>>(*this);}

      bool Equals(const object& obj) const override {return this->GenericArrayObject<T, TAllocator>::Equals(obj);}

      /// @brief Gets the value at the specified position in the two-dimensional Array. The indexes are specified as 32-bit integers.
      /// @param index1 A 32-bit integer that represents the first-dimension index of the Array element to get.
      /// @param index2 A 32-bit integer that represents the second-dimension index of the Array element to get.
      /// @return The value at the specified position in the two-dimensional Array.
      /// @exception ArgumentException The current Array does ! have exactly two dimension.
      /// @exception IndexOutOfRangeException Either index1 or index2 is outside the range of valid indexes for the corresponding dimension of the current Array.
      const T& GetValue(int32 index1, int32 index2) const { return this->operator()(index1, index2); }

      /// @brief Sets a value to the element at the specified position in the two-dimensional Array.
      /// @param value The new value for the specified element.
      /// @param index1 A 32-bit integer that represents the position of the first dimension Array element to set.
      /// @param index2 A 32-bit integer that represents the position of the second dimension of the Array element to set.
      /// @exception ArgumentException The current Array does ! have exactly two dimension.
      /// @exception IndexOutOfRangeException index1 or index2 is outside the range of valid indexes for the current Array.
      void SetValue(const T& value, int32 index1, int32 index2) { this->operator()(index1, index2) = value; }

    private:
      friend class Array<>;
      Array(const Array<int32>& lengths, bool) : GenericArrayObject<T, TAllocator>(lengths) {}
      int32 GetRank() const override {return 2;}
    };

    /// @brief Provides methods for creating, manipulating, searching, and sorting arrays, thereby serving as the base class for all arrays.
    /// @remarks The Array class is not part of the System.Collections namespaces. However, it is still considered a collection because it is based on the IList interface.
    /// @remarks An element is a value in an Array. The length of an Array is the total number of elements it can contain. The lower bound of an Array is the index of its first element. An Array can have any lower bound, but it has a lower bound of zero by default. A different lower bound can be defined when creating an instance of the Array class using CreateInstance.A multidimensional Array can have different bounds for each dimension. An array can have a maximum of 32 dimensions.
    /// @remarks Unlike the classes in the System.Collections namespaces, Array has a fixed capacity. To increase the capacity, you must create a new Array object with the required capacity, copy the elements from the old Array object to the new one, and delete the old Array.
    /// @remarks The Array class implements the System.Collections.Generic.IList<T>, System.Collections.Generic.ICollection<T>, and System.Collections.Generic.IEnumerable<T> generic interfaces. The implementations are provided to arrays at run time, and as a result, the generic interfaces do not appear in the declaration syntax for the Array class. In addition, there are no reference topics for interface members that are accessible only by casting an array to the generic interface type (explicit interface implementations). The key thing to be aware of when you cast an array to one of these interfaces is that members which add, insert, or remove elements throw NotSupportedException.
    /// @remarks The Array.Copy method copies elements not only between arrays of the same type but also between standard arrays of different types; it handles type casting automatically.
    /// @remarks Some methods, such as CreateInstance, Copy, CopyTo, GetValue, and SetValue, provide overloads that accept 64-bit integers as parameters to accommodate large capacity arrays. LongLength and GetLongLength return 64-bit integers indicating the length of the array.
    /// @remarks The Array is not guaranteed to be sorted. You must sort the Array prior to performing operations (such as BinarySearch) that require the Array to be sorted.
    /// @par Examples
    /// The following code example demonstrates different methods to create an array.
    /// @include Array1.cpp
    /// @par Examples
    /// The following code example creates and initializes an Array and displays its properties and its elements.
    /// @include Array2.cpp
    template<typename T, typename TAllocator>
    class Array<T, 3, TAllocator> : public GenericArrayObject<T, TAllocator>, public ICloneable {
    public:
      /// @brief Initializes a new instance of the Array class that is empty.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      Array() {}

      /// @brief Initializes a new instance of the Array class with lengths for each rank specified.
      /// @param length1 the length for the first rank.
      /// @param length2 the length for the second rank.
      /// @param length3 the length for the third rank.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      Array(int32 length1, int32 length2, int32 length3) : GenericArrayObject<T, TAllocator>(Array<int32> {length1, length2, length3}) {}

      /// @cond
      Array(const Array& array) : GenericArrayObject<T, TAllocator>((GenericArrayObject<T, TAllocator>&)array) {}
      Array(const Array&& array) : GenericArrayObject<T, TAllocator>(Move((GenericArrayObject<T, TAllocator> &&)array)) {}
      Array(InitializerList<InitializerList<InitializerList<T>>> il) : GenericArrayObject<T, TAllocator>(il) {}
      Array(const Array<int32>& lengths) : GenericArrayObject<T, TAllocator>(lengths) {}
      Array& operator=(const Array& array) {
        this->GenericArrayObject<T, TAllocator>::operator=(array);
        return *this;
      }

      friend core_export_ std::ostream& operator<<(std::ostream& output, const Array& value) {
        if (value.Length == 0)
          return output << "{empty}";

        output << "{";
        for (int index1 = 0; index1 < value.GetLength(0); index1++) {
          output << (index1 == 0 ? "{" : ", {");
          for (int index2 = 0; index2 < value.GetLength(1); index2++) {
            output << (index2 == 0 ? "{" : ", {");
            for (int index3 = 0; index3 < value.GetLength(2); index3++)
              output << (index3 != 0 ? ", " : "") << value(index1, index2, index3);
            output << "}";
          }
          output << "}";
        }
        return output << "}";
      }
      /// @endcond

      /// @brief Sets the element at in multidimension array the specified index.
      /// @param index The zero-based index of the element to set.
      /// @return T The modified element at the specified index.
      /// @exception ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
      /// @par Examples
      /// The following code example shows how to use operator [] to list the elements of an array.
      /// @include ArrayArrayOperatorFunctor.cpp
      T& operator()(int32 index1, int32 index2, int32 index3) {
        if (index3 >= this->GetLength(2) || index3 < 0) throw System::IndexOutOfRangeException(caller_);
        if (index2 >= this->GetLength(1) || index2 < 0) throw System::IndexOutOfRangeException(caller_);
        if (index1 >= this->GetLength(0) || index1 < 0) throw System::IndexOutOfRangeException(caller_);

        return this->array[index3 + (index2 * this->GetLength(2)) + (index1 * this->GetLength(2) * this->GetLength(1))];
      }

      /// @brief Gets the value at the specified position in the three-dimensional Array. The index is specified as a 32-bit integer.
      /// @param index1 A 32-bit integer that represents the first-dimension index of the Array element to get.
      /// @param index2 A 32-bit integer that represents the second-dimension index of the Array element to get.
      /// @param index3 A 32-bit integer that represents the third-dimension index of the Array element to get.
      /// @return The value at the specified position in the three-dimensional Array.
      /// @exception ArgumentException The current Array does ! have exactly three dimension.
      /// @exception IndexOutOfRangeException Either index1 or index2 or index3 is outside the range of valid indexes for the corresponding dimension of the current Array.
      /// @par Examples
      /// The following code example shows how to use operator [] to list the elements of an array.
      /// @include ArrayArrayOperatorFunctor.cpp
      const T& operator()(int32 index1, int32 index2, int32 index3) const {
        if (index3 >= this->GetLength(2) || index3 < 0) throw System::IndexOutOfRangeException(caller_);
        if (index2 >= this->GetLength(1) || index2 < 0) throw System::IndexOutOfRangeException(caller_);
        if (index1 >= this->GetLength(0) || index1 < 0) throw System::IndexOutOfRangeException(caller_);

        return this->array[index3 + (index2 * this->GetLength(2)) + (index1 * this->GetLength(2) * this->GetLength(1))];
      }

      /// @brief Creates a shallow copy of the Array.
      /// @return object A shallow copy of the Array.
      /// @remarks A shallow copy of an Array copies only the elements of the Array, whether they are reference types or value types, but it does not copy the objects that the references refer to. The references in the new Array point to the same objects that the references in the original Array point to.
      /// @remarks In contrast, a deep copy of an Array copies the elements and everything directly or indirectly referenced by the elements.
      /// @remarks The clone is of the same Type as the original Array.
      /// @remarks This method is an O(n) operation, where n is Length.
      refptr<object> Clone() const override {return ref_new<Array<T, 3, TAllocator>>(*this);}

      bool Equals(const object& obj) const override {return this->GenericArrayObject<T, TAllocator>::Equals(obj);}

      /// @brief Gets the value at the specified position in the three-dimensional Array. The indexes are specified as 32-bit integers.
      /// @param index1 A 32-bit integer that represents the first-dimension index of the Array element to get.
      /// @param index2 A 32-bit integer that represents the second-dimension index of the Array element to get.
      /// @param index3 A 32-bit integer that represents the third-dimension index of the Array element to get.
      /// @return The value at the specified position in the three-dimensional Array.
      /// @exception ArgumentException The current Array does ! have exactly three dimension.
      /// @exception IndexOutOfRangeException Either index1 or index2 or index3 is outside the range of valid indexes for the corresponding dimension of the current Array.
      const T& GetValue(int32 index1, int32 index2, int32 index3) const { return this->operator()(index1, index2, index3); }

      /// @brief Sets a value to the element at the specified position in the three-dimensional Array.
      /// @param value The new value for the specified element.
      /// @param index1 A 32-bit integer that represents the position of the first dimension Array element to set.
      /// @param index2 A 32-bit integer that represents the position of the second dimension of the Array element to set.
      /// @param index2 A 32-bit integer that represents the position of the third dimension of the Array element to set.
      /// @exception ArgumentException The current Array does ! have exactly three dimension.
      /// @exception IndexOutOfRangeException index1 or index2 or index3 is outside the range of valid indexes for the current Array.
      void SetValue(const T& value, int32 index1, int32 index2, int32 index3)  { this->operator()(index1, index2, index3) = value; }

    private:
      friend class Array<>;
      Array(const Array<int32>& lengths, bool) : GenericArrayObject<T, TAllocator>(lengths) {}
      int32 GetRank() const override {return 3;}
    };

    /// @brief Provides methods for creating, manipulating, searching, and sorting arrays, thereby serving as the base class for all arrays.
    /// @remarks The Array class is not part of the System.Collections namespaces. However, it is still considered a collection because it is based on the IList interface.
    /// @remarks An element is a value in an Array. The length of an Array is the total number of elements it can contain. The lower bound of an Array is the index of its first element. An Array can have any lower bound, but it has a lower bound of zero by default. A different lower bound can be defined when creating an instance of the Array class using CreateInstance.A multidimensional Array can have different bounds for each dimension. An array can have a maximum of 32 dimensions.
    /// @remarks Unlike the classes in the System.Collections namespaces, Array has a fixed capacity. To increase the capacity, you must create a new Array object with the required capacity, copy the elements from the old Array object to the new one, and delete the old Array.
    /// @remarks The Array class implements the System.Collections.Generic.IList<T>, System.Collections.Generic.ICollection<T>, and System.Collections.Generic.IEnumerable<T> generic interfaces. The implementations are provided to arrays at run time, and as a result, the generic interfaces do not appear in the declaration syntax for the Array class. In addition, there are no reference topics for interface members that are accessible only by casting an array to the generic interface type (explicit interface implementations). The key thing to be aware of when you cast an array to one of these interfaces is that members which add, insert, or remove elements throw NotSupportedException.
    /// @remarks The Array.Copy method copies elements not only between arrays of the same type but also between standard arrays of different types; it handles type casting automatically.
    /// @remarks Some methods, such as CreateInstance, Copy, CopyTo, GetValue, and SetValue, provide overloads that accept 64-bit integers as parameters to accommodate large capacity arrays. LongLength and GetLongLength return 64-bit integers indicating the length of the array.
    /// @remarks The Array is not guaranteed to be sorted. You must sort the Array prior to performing operations (such as BinarySearch) that require the Array to be sorted.
    /// @par Examples
    /// The following code example demonstrates different methods to create an array.
    /// @include Array1.cpp
    /// @par Examples
    /// The following code example creates and initializes an Array and displays its properties and its elements.
    /// @include Array2.cpp
    template<>
    class Array<> static_ {
    public:
      /// @brief Returns a read-only wrapper for the specified array.
      /// @param array The one-dimensional, zero-based array to wrap in a read-only ReadOnlyCollection<T> wrapper.
      /// @return A read-only ReadOnlyCollection<T> wrapper for the specified array.
      /// @remarks To prevent any modifications to the array, expose the array only through this wrapper.
      /// @remarks A collection that is read-only is simply a collection with a wrapper that prevents modifying the collection; therefore, if changes are made to the underlying collection, the read-only collection reflects those changes.
      /// @remarks This method is an O(n) operation.
      /// @par Examples
      /// The following example wraps an array in a read-only ReadOnlyCollection<T>.
      /// @include ArrayAsReadOnly.cpp
      template<typename T, typename TAllocator>
      static System::Collections::ObjectModel::ReadOnlyCollection<T> AsReadOnly(const Array<T, 1, TAllocator>& array) { return System::Collections::ObjectModel::ReadOnlyCollection<T>(array); }

      /// @brief Searches a range of elements in a one-dimensional sorted array for a value, using the IComparable interface implemented by each element of the array and by the specified value.
      /// @param array The sorted one-dimensional Array to search.
      /// @param index The starting index of the range to search.
      /// @param length The length of the range to search.
      /// @param value The object to search for.
      /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
      /// @exception RankException array is multidimensional.
      /// @exception ArgumentOutOfRangeException index is less than the lower bound of array.  -or-  length is less than zero.
      /// @exception ArgumentException index and length do not specify a valid range in array.  -or-  value is of a type that is not compatible with the elements of array.
      /// @exception InvalidOperationException value does not implement the IComparable interface, and the search encounters an element that does not implement the IComparable interface.
      /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
      /// @remarks If the Array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
      /// @remarks Either value or every element of array must implement the IComparable interface, which is used for comparisons. The elements of array must already be sorted in increasing value according to the sort order defined by the IComparable implementation; otherwise, the result might be incorrect.
      /// @note If value does not implement the IComparable interface, the elements of array are not tested for IComparable before the search begins. An exception is thrown if the search encounters an element that does not implement IComparable.
      /// @remarks Duplicate elements are allowed. If the Array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
      /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception.
      /// @note For every element tested, value is passed to the appropriate IComparable implementation, even if value is null. That is, the IComparable implementation determines how a given element compares to null.
      /// @remarks This method is an O(log n) operation, where n is length.
      template<typename T, typename TAllocator>
      static int32 BinarySearch(const Array<T, 1, TAllocator>& array, int32 index, int32 length, const T& value) {return BinarySearch(array, index, length, value, System::Collections::Generic::Comparer<T>::Default);}

      /// @brief Searches a range of elements in a one-dimensional sorted array for a value, using the specified IComparer interface.
      /// @param array The sorted one-dimensional Array to search.
      /// @param index The starting index of the range to search.
      /// @param length The length of the range to search.
      /// @param value The object to search for.
      /// @param comparer The IComparer implementation to use when comparing elements.  -or-  null to use the IComparable implementation of each element.
      /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
      /// @exception RankException array is multidimensional.
      /// @exception ArgumentOutOfRangeException index is less than the lower bound of array.  -or-  length is less than zero.
      /// @exception ArgumentException index and length do not specify a valid range in array.  -or-  value is of a type that is not compatible with the elements of array.
      /// @exception InvalidOperationException value does not implement the IComparable interface, and the search encounters an element that does not implement the IComparable interface.
      /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
      /// @remarks If the Array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
      /// @remarks The comparer customizes how the elements are compared. For example, you can use a System.Collections.CaseInsensitiveComparer as the comparer to perform case-insensitive string searches.
      /// @remarks If comparer is not null, the elements of array are compared to the specified value using the specified IComparer implementation. The elements of array must already be sorted in increasing value according to the sort order defined by comparer; otherwise, the result might be incorrect.
      /// @remarks If comparer is null, the comparison is done using the IComparable implementation provided by the element itself or by the specified value. The elements of array must already be sorted in increasing value according to the sort order defined by the IComparable implementation; otherwise, the result might be incorrect.
      /// @note If comparer is null and value does not implement the IComparable interface, the elements of array are not tested for IComparable before the search begins. An exception is thrown if the search encounters an element that does not implement IComparable.
      /// @remarks Duplicate elements are allowed. If the Array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
      /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception when using IComparable.
      /// @note For every element tested, value is passed to the appropriate IComparable implementation, even if value is null. That is, the IComparable implementation determines how a given element compares to null.
      /// @remarks This method is an O(log n) operation, where n is length.
      template<typename T, typename TAllocator>
      static int32 BinarySearch(const Array<T, 1, TAllocator>& array, int32 index, int32 count, const T& value, const System::Collections::Generic::IComparer<T>& comparer) {
        if (index < 0 || count < 0) throw ArgumentOutOfRangeException(caller_);
        if (index + count > array->Length) throw ArgumentException(caller_);

        typename std::vector<T>::const_iterator first = array.array.begin();
        typename std::vector<T>::const_iterator last = array.array.begin();
        std::advance(first, index);
        std::advance(last, index + count);
        typename std::vector<T>::const_iterator position = std::lower_bound(first, last, value, Array<T>::Comparer(&comparer));

        if (position != array.array.end() && !comparer->Compare(value, *position))
          return (int32)std::distance(array.array.begin(), position);
        return (int32)~std::distance(array.array.begin(), position);
      }

      /// @brief Searches an entire one-dimensional sorted array for a specific element, using the IComparable interface implemented by each element of the array and by the specified object.
      /// @param array The sorted one-dimensional Array to search.
      /// @param value The object to search for.
      /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
      /// @exception RankException array is multidimensional.
      /// @exception ArgumentException value is of a type that is not compatible with the elements of array.
      /// @exception InvalidOperationException value does not implement the IComparable interface, and the search encounters an element that does not implement the IComparable interface.
      /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
      /// @remarks If the Array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
      /// @remarks Either value or every element of array must implement the IComparable interface, which is used for comparisons. The elements of array must already be sorted in increasing value according to the sort order defined by the IComparable implementation; otherwise, the result might be incorrect.
      /// @note Ifvalue does not implement the IComparable interface, the elements of array are not tested for IComparable before the search begins. An exception is thrown if the search encounters an element that does not implement IComparable.
      /// @remarks Duplicate elements are allowed. If the Array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
      /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception.
      /// @note For every element tested, value is passed to the appropriate IComparable implementation, even if value is null. That is, the IComparable implementation determines how a given element compares to null.
      /// @remarks This method is an O(log n) operation, where n is the Length of array.
      template<typename T, typename TAllocator>
      static int32 BinarySearch(const Array<T, 1, TAllocator>& array, const T& value) {return BinarySearch(array, 0, array.Length, value, System::Collections::Generic::Comparer<T>::Default.Release());}

      /// @brief Searches a range of elements in a one-dimensional sorted array for a value, using the specified IComparer interface.
      /// @param array The sorted one-dimensional Array to search.
      /// @param value The object to search for.
      /// @param comparer The IComparer implementation to use when comparing elements.  -or-  null to use the IComparable implementation of each element.
      /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
      /// @exception RankException array is multidimensional.
      /// @exception ArgumentOutOfRangeException index is less than the lower bound of array.  -or-  length is less than zero.
      /// @exception ArgumentException index and length do not specify a valid range in array.  -or-  value is of a type that is not compatible with the elements of array.
      /// @exception InvalidOperationException value does not implement the IComparable interface, and the search encounters an element that does not implement the IComparable interface.
      /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
      /// @remarks If the Array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
      /// @remarks The comparer customizes how the elements are compared. For example, you can use a System.Collections.CaseInsensitiveComparer as the comparer to perform case-insensitive string searches.
      /// @remarks If comparer is not null, the elements of array are compared to the specified value using the specified IComparer implementation. The elements of array must already be sorted in increasing value according to the sort order defined by comparer; otherwise, the result might be incorrect.
      /// @remarks If comparer is null, the comparison is done using the IComparable implementation provided by the element itself or by the specified value. The elements of array must already be sorted in increasing value according to the sort order defined by the IComparable implementation; otherwise, the result might be incorrect.
      /// @note If comparer is null and value does not implement the IComparable interface, the elements of array are not tested for IComparable before the search begins. An exception is thrown if the search encounters an element that does not implement IComparable.
      /// @remarks Duplicate elements are allowed. If the Array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
      /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception when using IComparable.
      /// @note For every element tested, value is passed to the appropriate IComparable implementation, even if value is null. That is, the IComparable implementation determines how a given element compares to null.
      /// @remarks This method is an O(log n) operation, where n is length.
      template<typename T, typename TAllocator>
      static int32 BinarySearch(const Array<T, 1, TAllocator>& array, const T& value, const System::Collections::Generic::IComparer<T>& comparer) {return BinarySearch(array, 0, array.Length, value, comparer);}

      /// @brief Sets a range of elements in an array to the default value of each element type.
      /// @param array The array whose elements need to be cleared.
      /// @param index The starting index of the range of elements to clear.
      /// @param length The number of elements to clear.
      /// @exception ArgumentOutOfRangeException index is less than the lower bound of array.  -or-  length is less than zero.
      /// @exception ArgumentException index and length do not specify a valid range in array.  -or-  value is of a type that is not compatible with the elements of array.
      /// @remarks This method resets each element in an array to the element type's default value. It sets elements of reference types (including String elements) to null, and sets elements of value types to the default values shown in the following table.
      /// | Type                                          | Value                              |
      /// |-----------------------------------------------|------------------------------------|
      /// | Boolean                                       | false                              |
      /// | All integral and floating point numeric types | 0 (zero)                           |
      /// | DateTime                                      | DateTime::MinValue                 |
      /// | Other value types                             | Default value of the type's fields |
      /// @remarks The range of cleared elements wrap from row to row in a multi-dimensional array.
      /// @remarks This method only clears the values of the elements; it does not delete the elements themselves. An array has a fixed size; therefore, elements cannot be added or removed.
      /// @remarks This method is an O(n) operation, where n is length.
      template<typename T, typename TAllocator>
      static void Clear(GenericArrayObject<T, TAllocator>& array, int32 index, int32 length) {
        if (index < 0 || length < 0 || index + length > array.Length) throw ArgumentOutOfRangeException(caller_);
        if (index + length > array.Length) throw ArgumentException(caller_);

        for (int32 increment = 0; increment < length; increment++)
          array[index + increment] = T();
      }

      /// @brief Copies a range of elements from an Array starting at the specified source index and pastes them to another Array starting at the specified destination index. Guarantees that all changes are undone if the copy does not succeed completely.
      /// @param sourceArray The Array that contains the data to copy.
      /// @param sourceIndex A 32-bit integer that represents the index in the sourceArray at which copying begins.
      /// @param destinationArray The Array that receives the data.
      /// @param destinationIndex A 32-bit integer that represents the index in the destinationArray at which storing begins.
      /// @param length A 32-bit integer that represents the number of elements to copy.
      /// @exception RankException sourceArray and destinationArray have different ranks.
      /// @exception ArrayTypeMismatchException The sourceArray type is neither the same as nor derived from the destinationArray type.
      /// @exception InvalidCastException At least one element in sourceArray cannot be cast to the type of destinationArray.
      /// @exception ArgumentOutOfRangeException sourceIndex is less than the lower bound of the first dimension of sourceArray.  -or-  destinationIndex is less than the lower bound of the first dimension of destinationArray.  -or-  length is less than zero.
      /// @exception ArgumentException length is greater than the number of elements from sourceIndex to the end of sourceArray.  -or-  length is greater than the number of elements from destinationIndex to the end of destinationArray.
      /// @remarks The sourceArray and destinationArray parameters must have the same number of dimensions. The sourceArray type must be the same as or derived from the destinationArray type; otherwise, an ArrayTypeMismatchException is thrown. Unlike Copy, ConstrainedCopy verifies the compatibility of the array types before performing any operation.
      /// @remarks When copying between multidimensional arrays, the array behaves like a long one-dimensional array, where the rows (or columns) are conceptually laid end-to-end. For example, if an array has three rows (or columns) with four elements each, copying six elements from the beginning of the array would copy all four elements of the first row (or column) and the first two elements of the second row (or column). To start copying from the second element of the third row (or column), sourceIndex must be the upper bound of the first row (or column) plus the length of the second row (or column) plus two.
      /// @remarks If sourceArray and destinationArray overlap, this method behaves as if the original values of sourceArray were preserved in a temporary location before destinationArray is overwritten.
      /// @remarks The arrays can be reference-type arrays or value-type arrays. If sourceArray and destinationArray are both reference-type arrays or are both arrays of type Object, a shallow copy is performed. A shallow copy of an Array is a new Array containing references to the same elements as the original Array. The elements themselves or anything referenced by the elements are not copied. In contrast, a deep copy of an Array copies the elements and everything directly or indirectly referenced by the elements.
      /// @remarks If this method throws an exception while copying, the destinationArray remains unchanged; therefore, ConstrainedCopy can be used within a constrained execution region (Cer).
      /// @remarks This method is an O(n) operation, where n is length.
      template<typename T1, typename TAllocator1 = Allocator<T1>, typename T2, typename TAllocator2 = Allocator<T2>>
      static void ConstrainedCopy(const GenericArrayObject<T1, TAllocator1>& sourceArray, int32 sourceIndex, GenericArrayObject<T2, TAllocator2>& destinationArray, int32 destinationIndex, int32 length) {
        if (sourceArray.Rank != destinationArray.Rank) throw RankException(caller_);
        if (!std::is_base_of<T1, T2>::value) throw ArrayTypeMismatchException(caller_);
        if (sourceIndex < 0 || destinationArray < 0 || length < 0) throw ArgumentOutOfRangeException(caller_);
        if (sourceIndex + length > sourceArray.Length || destinationIndex + length > destinationArray.Length) throw ArgumentException(caller_);

        for (int32 increment = 0; increment < length; increment++)
          destinationArray[destinationIndex + increment] = as<T2>(sourceArray[sourceIndex + increment]);
      }

      /// @brief Converts an array of one type to an array of another type.
      /// @param array The one-dimensional, zero-based Array to convert to a target type.
      /// @param converter A Converter<TInput, TOutput> that converts each element from one type to another type.
      /// @return An array of the target type containing the converted elements from the source array.
      /// @remarks The Converter<TInput, TOutput> is a delegate to a method that converts an object to the target type. The elements of array are individually passed to the Converter<TInput, TOutput>, and the converted elements are saved in the new array.
      /// @remarks The source array remains unchanged.
      /// @remarks This method is an O(n) operation, where n is the Length of array.
      template<typename TInput, typename TOutput, typename TAllocatorOutput = Allocator<TOutput>, int32 Rank = 1, typename TAllocatorInput = Allocator<TInput>>
      static Array<TOutput, Rank, TAllocatorOutput> ConvertAll(const Array<TInput, Rank, TAllocatorInput>& array, Converter<TInput, TOutput> converter) {
        //Array<int32, 1, TAllocatorOutput> lengths(Rank);
        Array<int32> lengths(Rank);
        for (int32 index = 0; index < Rank; index++)
          lengths[index] = array.GetLength(index);
        Array<TOutput, Rank, TAllocatorOutput> result = CreateInstance<TOutput, Rank, TAllocatorOutput>(lengths);
        for (int32 index = 0; index < array.Length; index++)
          result[index] = converter(array[index]);
        return result;
      }

      /// @brief Creates a one-dimensional Array of the specified Type and length, with zero-based indexing.
      /// @param length The size of the Array to create.
      /// @return A new one-dimensional Array of the specified Type with the specified length, using zero-based indexing.
      /// @exception ArgumentException elementType is not a valid Type.
      /// @exception NotSupportedException elementType is not supported. For example, Void is not supported.  -or-  elementType is an open generic type.
      /// @exception ArgumentOutOfRangeException length is less than zero.
      /// @remarks Unlike most classes, Array provides the CreateInstance method, instead of public constructors, to allow for late bound access.
      /// @remarks Pointer-type elements are initialized to null. Value-type elements are initialized to zero.
      /// @remarks This method is an O(n) operation, where n is length.
      template<typename T, typename TAllocator = Allocator<T>>
      static Array<T, 1, TAllocator> CreateInstance(int32 length) {return Array<T, 1, TAllocator>(length);}

      /// @brief Creates a two-dimensional Array of the specified Type and dimension lengths, with zero-based indexing.
      /// @param length1 The size of the first dimension of the Array to create.
      /// @param length2 The size of the second dimension of the Array to create.
      /// @return A new two-dimensional Array of the specified Type with the specified length for each dimension, using zero-based indexing.
      /// @exception ArgumentException elementType is not a valid Type.
      /// @exception NotSupportedException elementType is not supported. For example, Void is not supported.  -or-  elementType is an open generic type.
      /// @exception ArgumentOutOfRangeException length1 is less than zero.  -or-  ArgumentOutOfRangeException length2 is less than zero.
      /// @remarks Unlike most classes, Array provides the CreateInstance method, instead of public constructors, to allow for late bound access.
      /// @remarks Pointer-type elements are initialized to null. Value-type elements are initialized to zero.
      /// @remarks This method is an O(n) operation, where n is length.
      template<typename T, typename TAllocator = Allocator<T>>
      static Array<T, 2, TAllocator> CreateInstance(int32 length1, int32 length2) {return Array<T, 2, TAllocator>(length1, length2);}

      /// @brief Creates a three-dimensional Array of the specified Type and dimension lengths, with zero-based indexing.
      /// @param length1 The size of the first dimension of the Array to create.
      /// @param length2 The size of the second dimension of the Array to create.
      /// @param length3 The size of the third dimension of the Array to create.
      /// @return A new three-dimensional Array of the specified Type with the specified length for each dimension, using zero-based indexing.
      /// @exception ArgumentException elementType is not a valid Type.
      /// @exception NotSupportedException elementType is not supported. For example, Void is not supported.  -or-  elementType is an open generic type.
      /// @exception ArgumentOutOfRangeException length1 is less than zero.  -or-  ArgumentOutOfRangeException length2 is less than zero.  -or-  ArgumentOutOfRangeException length3 is less than zero.
      /// @remarks Unlike most classes, Array provides the CreateInstance method, instead of public constructors, to allow for late bound access.
      /// @remarks Pointer-type elements are initialized to null. Value-type elements are initialized to zero.
      /// @remarks This method is an O(n) operation, where n is length.
      template<typename T, typename TAllocator = Allocator<T>>
      static Array<T, 3, TAllocator> CreateInstance(int32 length1, int32 length2, int32 length3) {return Array<T, 3, TAllocator>(length1, length2, length3);}

      /// @brief Creates a multidimensional Array of the specified Type and dimension lengths, with zero-based indexing. The dimension lengths are specified in an array of 32-bit integers.
      /// @param An array of 32-bit integers that represent the size of each dimension of the Array to create.
      /// @return A new multidimensional Array of the specified Type with the specified length for each dimension, using zero-based indexing.
      /// @exception ArgumentException elementType is not a valid Type.
      /// @exception NotSupportedException elementType is not supported. For example, Void is not supported.  -or-  elementType is an open generic type.
      /// @exception ArgumentOutOfRangeException length1 is less than zero.  -or-  ArgumentOutOfRangeException length2 is less than zero.  -or-  ArgumentOutOfRangeException length3 is less than zero.
      /// @remarks Unlike most classes, Array provides the CreateInstance method, instead of public constructors, to allow for late bound access.
      /// @remarks The number of elements in the lengths array must equal the number of dimensions in the new Array. Each element of the lengths array must specify the length of the corresponding dimension in the new Array.
      /// @remarks Pointer-type elements are initialized to null. Value-type elements are initialized to zero.
      /// @remarks This method is an O(n) operation, where n is length.
      template<typename T, int32 Rank, typename TAllocator = Allocator<T>>
      static Array<T, Rank, TAllocator> CreateInstance(const Array<int32>& lengths) {return Array<T, Rank, TAllocator>(lengths, true);}

      /// @brief Determines whether the List<T> contains elements that match the conditions defined by the specified predicate..
      /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
      /// @return Boolean true if the List<T> contains one or more elements that match the conditions defined by the specified predicate; otherwise, false.
      /// @exception ArgumentNUllException The parameters match is null.
      /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current List<T> are individually passed to the Predicate pointer function, and processing is stopped when a match is found.
      /// @remarks This method is an O(n) operation, where n is Count.
      /// @remarks The following code example demonstrates the RemoveAll method and several other methods that use the Predicate<T> generic delegate.
      /// @remarks A List<T> of strings is created, containing 8 dinosaur names, two of which (at positions 1 and 5) end with "saurus". The code example also defines a search predicate method named EndsWithSaurus, which accepts a string parameter and returns a Boolean value indicating whether the input string ends in "saurus".
      /// @remarks The Find, FindLast, and FindAll methods are used to search the list with the search predicate method.
      /// @par Examples
      /// The RemoveAll method is used to remove all entries ending with "saurus". It traverses the list from the beginning, passing each element in turn to the EndsWithSaurus method. The element is removed if the EndsWithSaurus method returns true.
      /// @include ListExists.cpp
      template<typename T, typename TAllocator = Allocator<T>>
      static bool Exists(const GenericArrayObject<T, TAllocator>& array, Predicate<T> match) {
        for (const T& elem : array)
          if (match(elem))
            return true;

        return false;
      }

      /// @brief Changes the number of elements of a one-dimensional array to the specified new size.
      /// @param array The one-dimensional, zero-based array to resize, or null to create a new array with the specified size.
      /// @param newSize The size of the new array.
      /// @exception ArgumentOutOfRangeException newSize is less than zero.
      /// @remarks This method allocates a new array with the specified size, copies elements from the old array to the new one, and then replaces the old array with the new one. array must be a one-dimensional array.
      /// @remarks If newSize is greater than the Length of the old array, a new array is allocated and all the elements are copied from the old array to the new one. If newSize is less than the Length of the old array, a new array is allocated and elements are copied from the old array to the new one until the new one is filled; the rest of the elements in the old array are ignored. If newSize is equal to the Length of the old array, this method does nothing.
      /// @remarks This method is an O(n) operation, where n is old size.
      template<typename T, typename TAllocator = Allocator<T>>
      static void Resize(Array<T, 1, TAllocator>& array, int32 newSize) {array.Resize(newSize);}

      /// @brief Reverses the order of the elements in the entire List<T>.
      /// @remarks This method uses Array.Reverse to reverse the order of the elements, such that the element at List<T>[i], where i is any index within the range, moves to List<T>[j], where j equals index plus index plus count minus i minus 1.
      /// @remarks This method is an O(n) operation, where n is Count.
      /// @par Examples
      /// The following code example demonstrates both overloads of the Reverse method. The code example creates a List<T> of strings and adds six strings. The Reverse() method overload is used to reverse the list, and then the Reverse(Int32, Int32) method overload is used to reverse the middle of the list, beginning with element 1 and encompassing four elements.
      /// @include ListReverse.cpp
      template<typename T, typename TAllocator = Allocator<T>>
      static void Reverse(Array<T, 1, TAllocator>& array) {array.Reverse();}

      /// @brief Reverses the order of the elements in the specified range.
      /// @param index The zero-based starting index of the range to reverse.
      /// @param count The number of elements in the range to reverse.
      /// @exception ArgumentOutOfRangeException index is less than 0. -or- count is less than 0.
      /// @exception ArgumentException ndex and count do ! denote a valid range of elements in the List<T>.
      /// @remarks This method uses Array.Reverse to reverse the order of the elements, such that the element at List<T>[i], where i is any index within the range, moves to List<T>[j], where j equals index plus index plus count minus i minus 1.
      /// @remarks This method is an O(n) operation, where n is Count.
      /// @par Examples
      /// The following code example demonstrates both overloads of the Reverse method. The code example creates a List<T> of strings and adds six strings. The Reverse() method overload is used to reverse the list, and then the Reverse(Int32, Int32) method overload is used to reverse the middle of the list, beginning with element 1 and encompassing four elements.
      /// @include ListReverse.cpp
      template<typename T, typename TAllocator = Allocator<T>>
      static void Reverse(Array<T, 1, TAllocator>& array, int32 index, int32 count) {array.Reverse(index, count);}
    };

    template<typename T, typename TAllocator>
    inline GenericArrayObject<T, TAllocator>::GenericArrayObject(const Array<int32, 1>& lengths) {
      this->length = lengths.Agregate(delegate_(const int32 & accumulator, const int32 & value) {return accumulator * value;});
      this->array = std::vector<T, TAllocator>(this->length);
      for (int32 length : lengths) {
        this->lowerBound.push_back(0);
        this->upperBound.push_back(length - 1);
      }
    }
  }
}

using namespace Switch;

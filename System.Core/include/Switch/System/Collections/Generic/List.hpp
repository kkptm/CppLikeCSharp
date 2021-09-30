/// @file
/// @brief Contains Switch::System::Collections::Generic::List <T> class.
#pragma once

#include <algorithm>
#include <functional>
#include <iterator>

#include "Comparer.hpp"
#include "IComparer.hpp"
#include "IList.hpp"
#include "GenericException.hpp"
#include "../../../Allocator.hpp"
#include "../../../InitializerList.hpp"
#include "../../../Move.hpp"
#include "../ObjectModel/ReadOnlyCollection.hpp"
#include "../../Action.hpp"
#include "../../ArgumentOutOfRangeException.hpp"
#include "../../Array.hpp"
#include "../../Comparison.hpp"
#include "../../Int32.hpp"
#include "../../InvalidOperationException.hpp"
#include "../../Predicate.hpp"
#include "../../Linq/Enumerable.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @brief Represents a strongly typed list of objects that can be accessed by index. Provides methods to search, sort, and manipulate lists.
        /// @remarks The List<T> class is the generic equivalent of the ArrayList class. It implements the IList<T> generic interface using an array whose size is dynamically increased as required.
        /// @remarks The List<T> class uses both an equality comparer and an ordering comparer.
        /// @remarks Methods such as Contains, IndexOf, LastIndexOf, and Remove use an equality comparer for the list elements. The default equality comparer for type T is determined as follows. If type T implements the IEquatable<T> generic interface, then the equality comparer is the Equals(T) method of that interface; otherwise, the default equality comparer is object.Equals(object).
        /// @remarks Methods such as BinarySearch and Sort use an ordering comparer for the list elements. The default comparer for type T is determined as follows. If type T implements the IComparable<T> generic interface, then the default comparer is the CompareTo(T) method of that interface; otherwise, if type T implements the nongeneric IComparable interface, then the default comparer is the CompareTo(object) method of that interface. If type T implements neither interface, then there is no default comparer, and a comparer or comparison delegate must be provided explicitly.
        /// @remarks The List<T> is ! guaranteed to be sorted. You must sort the List<T> before performing operations (such as BinarySearch) that require the List<T> to be sorted.
        /// @remarks Elements in this collection can be accessed using an integer index. Indexes in this collection are zero-based.
        /// @remarks For very large List<T> objects, you can increase the maximum capacity to 2 billion elements on a 64-bit system by setting the enabled attribute of the gcAllowVeryLargeObjects configuration element to true in the run-time environment.
        /// @remarks List<T> accepts null as a valid value for reference types and allows duplicate elements.
        /// @par Examples
        /// The following code example demonstrates the TrimExcess method. Several properties and methods of the List<T> class are used to add, insert, and remove items from a list of strings. Then the TrimExcess method is used to reduce the capacity to match the count, and the Capacity and Count properties are displayed. If the unused capacity had been less than 10 percent of total capacity, the list would ! have been resized. Finally, the contents of the list are cleared.
        /// @include List.cpp
        template<typename T, typename TAllocator>
        class List : public Object, public System::Linq::Extension::Enumerable<List<T, TAllocator>, T>, public IList<T> {
          using Item = T;
        public:
          /// @brief Initializes a new instance of the List<T> class that is empty.
          /// @remarks The capacity of a List<T> is the number of elements that the List<T> can hold. As elements are added to a List<T>, the capacity is automatically increased as required by reallocating the internal array.
          /// @remarks If the size of the collection can be estimated, using the List<T>(Int32) constructor and specifying the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the List<T>.
          /// @remarks The capacity can be decreased by calling the TrimExcess method or by setting the Capacity property explicitly. Decreasing the capacity reallocates memory and copies all the elements in the List<T>.
          /// @remarks This constructor is an O(1) operation.
          /// @remarks The following code example demonstrates the default constructor of the List<T> generic class. The default constructor creates a list with the default capacity, as demonstrated by displaying the Capacity property.
          /// @par Examples
          /// The code example adds, inserts, and removes items, showing how the capacity changes as these methods are used.
          /// @include List.cpp
          List() {}

          /// @brief Default copy constructor
          /// @param list the List<T> which elements will be inserted from
          List(const List& list) : list(list.list), operationNumber(list.operationNumber) {}

          /// @cond
          List(List&& list) : list(Move(list.list)) {list.operationNumber = 0;}
          /// @endcond

          /// @brief Initializes a new instance of the List<T> class that contains elements copied from the specified collection and has sufficient capacity to accommodate the number of elements copied.
          /// @param collection The collection whose elements are copied to the new list.
          /// @exception ArgumentNullException The parameters collection is null or element reference null in collection.
          /// @remarks The elements are copied onto the List<T> in the same order they are read by the enumerator of the collection.
          /// @remarks This constructor is an O(n) operation, where n is the number of elements in collection.
          /// @par Examples
          /// The following code example demonstrates the List<T> constructor and various methods of the List<T> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The Capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
          /// @include List2.cpp
          List(const IEnumerable<T>& collection) : operationNumber(0) {
            for (const T& value : collection)
              Add(value);
          }

          /// @brief Initializes a new instance of the List<T> class that is empty and has the specified initial capacity.
          /// @param capacity The number of elements that the new list can initially store.
          /// @exception ArgumentOutOfRangeException capacity is less than 0.
          /// @remarks The capacity of a List<T> is the number of elements that the List<T> can hold. As elements are added to a List<T>, the capacity is automatically increased as required by reallocating the internal array.
          /// @remarks If the size of the collection can be estimated, specifying the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the List<T>.
          /// @remarks The capacity can be decreased by calling the TrimExcess method or by setting the Capacity property explicitly. Decreasing the capacity reallocates memory and copies all the elements in the List<T>.
          /// @remarks This constructor is an O(n) operation, where n is capacity.
          /// @remarks The following code example demonstrates the AsReadOnly method. A List<T> of strings with a capacity of 4 is created, because the ultimate size of the list is known to be exactly 4. The list is populated with four strings, and the AsReadOnly method is used to get a read-only IList<T> generic interface implementation that wraps the original list.
          /// @par Examples
          /// An element of the original list is set to "Coelophysis" using the Item property, and the contents of the read-only list are displayed again to demonstrate that it is just a wrapper for the original list.
          /// @include List3.cpp
          List(int32 capacity) : operationNumber(0) {
            if (capacity < 0)
              throw System::ArgumentOutOfRangeException(caller_);

            this->list.reserve(capacity);
          }

          /// @brief Initializes a new instance of the List and copy array[] T.
          /// @param array the Array to copy.
          /// @remarks The List class is ! thread safe.
          template<int32 len>
          List(const T(&array)[len]) : operationNumber(0) {
            for (int32 index = 0; index < len; index++)
              this->Add(array[index]);
          }

          /// @cond
          List(InitializerList<T> il) : operationNumber(0) {
            for (const T& item : il)
              this->Add(item);
          }

          ~List() { this->Clear(); }
          /// @endcond

          /// @brief Gets or sets the total number of elements the internal data structure.
          /// @return The number of elements that the List<T> can contain.
          /// @exception System::ArgumentOutOfRangeException System::Collections::Generic::List<T>.Capacity is set to a value that is less than System::Collections::Generic::List<T>.Count.
          property_<int32> Capacity {
            get_ {return static_cast<int32>(this->list.capacity());},
            set_ {
              if (value < this->Count)
                throw ArgumentOutOfRangeException(caller_);
              return this->list.reserve(value);
            }
          };

          /// @brief Get access to raw data of the Array.
          /// @return A pointer to raw data of the array.
          property_<const T*, readonly_> Data {
            get_->const T* {return this->list.data();}
          };

          /// @brief Adds an object to the end of the List<T>.
          /// @param value The object to be added to the end of the List<T>. The value can be null for reference types.
          /// @remarks List<T> accepts null as a valid value for reference types and allows duplicate elements.
          /// @remarks If Count already equals Capacity, the capacity of the List<T> is increased by automatically reallocating the internal array, and the existing elements are copied to the new array before the new element is added.
          /// @remarks If Count is less than Capacity, this method is an O(1) operation. If the capacity needs to be increased to accommodate the new element, this method becomes an O(n) operation, where n is Count.
          /// @remarks The following code example demonstrates several properties and methods of the List<T> generic class, including the Add method. The default constructor is used to create a list of strings with a capacity of 0. The Capacity property is displayed, and then the Add method is used to add several items. The items are listed, and the Capacity property is displayed again, along with the Count property, to show that the capacity has been increased as needed.
          /// @par Examples
          /// Other properties and methods are used to search for, insert, and remove elements from the list, and finally to clear the list.
          /// @include List.cpp
          void Add(const T& value) override {
            this->list.push_back(value);
          }

          /// @brief Adds copy of elements from the specified collection to the end of the List<T>.
          /// @param collection The collection whose elements should be added to the end of the List<T>. The value can ! be null and can contains reference element null.
          /// @exception ArgumentNullException The parameters collection is null or element reference null in collection.
          /// @remarks The order of the elements in the collection is preserved in the List<T>.
          /// @remarks If the new Count (the current Count plus the size of the collection) will be greater than Capacity, the capacity of the List<T> is increased by automatically reallocating the internal array to accommodate the new elements, and the existing elements are copied to the new array before the new elements are added.
          /// @remarks If the List<T> can accommodate the new elements without increasing the Capacity, this method is an O(n) operation, where n is the number of elements to be added. If the capacity needs to be increased to accommodate the new elements, this method becomes an O(n + m) operation, where n is the number of elements to be added and m is Count.
          /// @par Examples
          /// The following code example demonstrates the List<T> constructor and various methods of the List<T> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The Capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
          /// @include List2.cpp
          void AddRange(const IEnumerable<T>& enumerable) {
            if (&enumerable == this) { // if enumerable is the same object : infinite loop
              Array<T> a(enumerable);
              for (const T& value : a)
                this->Add(value);
              return;
            }

            for (const T& value : enumerable)
              this->Add(value);
          }

          /// @brief Adds copy of elements from the specified collection to the end of the List<T>.
          /// @param collection The collection whose elements should be added to the end of the List<T>. The value can ! be null and can contains reference element null.
          /// @exception ArgumentNullException The parameters collection is null or element reference null in collection.
          /// @remarks The order of the elements in the collection is preserved in the List<T>.
          /// @remarks If the new Count (the current Count plus the size of the collection) will be greater than Capacity, the capacity of the List<T> is increased by automatically reallocating the internal array to accommodate the new elements, and the existing elements are copied to the new array before the new elements are added.
          /// @remarks If the List<T> can accommodate the new elements without increasing the Capacity, this method is an O(n) operation, where n is the number of elements to be added. If the capacity needs to be increased to accommodate the new elements, this method becomes an O(n + m) operation, where n is the number of elements to be added and m is Count.
          /// @par Examples
          /// The following code example demonstrates the List<T> constructor and various methods of the List<T> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The Capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
          /// @include List2.cpp
          void AddRange(InitializerList<T> il) {
            for (const T& item : il)
              this->Add(item);
          }

          /// @brief Returns a read-only IList<T> wrapper for the current collection.
          /// @return A ReadOnlyCollection<T> that acts as a read-only wrapper around the current List<T>.
          /// @remarks To prevent any modifications to List<T>, expose List<T> only through this wrapper.
          /// @remarks A collection that is read-only is simply a collection with a wrapper that prevents modifying the collection; therefore, if changes are made to the underlying collection, the read-only collection reflects those changes.
          /// @remarks This method is an O(1) operation.
          /// @remarks The following code example demonstrates the AsReadOnly method. A List<T> of strings with a capacity of 4 is created, because the ultimate size of the list is known to be exactly 4. The list is populated with four strings, and the AsReadOnly method is used to get a read-only IList<T> generic interface implementation that wraps the original list.
          /// @par Examples
          /// An element of the original list is set to "Coelophysis" using the Item property, and the contents of the read-only list are displayed again to demonstrate that it is just a wrapper for the original list.
          /// @include List3.cpp
          ObjectModel::ReadOnlyCollection<T> AsReadOnly() {return ObjectModel::ReadOnlyCollection<T>(*this);}

          /// @brief Searches the entire sorted List<T> for an element using the default comparer and returns the zero-based index of the element.
          /// @param item The object to locate. The value can be null for reference types.
          /// @return int32 The zero-based index of item in the sorted List<T>, if item is found; otherwise, a negative number that is the bitwise complement of the index of the next element that is larger than item or, if there is no larger element, the bitwise complement of Count.
          /// @exception InvalidOperationException The default comparer Comparer<T>.Default cannot find an implementation of the IComparable<T> generic interface or the IComparable interface for type T.
          /// @remarks This method uses the default comparer Comparer<T>.Default for type T to determine the order of list elements. The Comparer<T>.Default property checks whether type T implements the IComparable<T> generic interface and uses that implementation, if available. If !, Comparer<T>.Default checks whether type T implements the IComparable interface. If type T does ! implement either interface, Comparer<T>.Default throws an InvalidOperationException.
          /// @remarks The List<T> must already be sorted according to the comparer implementation; otherwise, the result is incorrect.
          /// @remarks Comparing null with any reference type is allowed and does ! generate an exception when using the IComparable<T> generic interface. When sorting, null is considered to be less than any other object.
          /// @remarks If the List<T> contains more than one element with the same value, the method returns only one of the occurrences, and it might return any one of the occurrences, not necessarily the first one.
          /// @remarks If the List<T> does ! contain the specified value, the method returns a negative integer. You can apply the bitwise complement operation (~) to this negative integer to get the index of the first element that is larger than the search value. When inserting the value into the List<T>, this index should be used as the insertion point to maintain the sort order.
          /// @remarks This method is an O(log n) operation, where n is the number of elements in the range.
          /// @remarks The following code example demonstrates the Sort() method overload and the BinarySearch(T) method overload. A List<T> of strings is created and populated with four strings, in no particular order. The list is displayed, sorted, and displayed again.
          /// @par Examples
          /// The BinarySearch(T) method overload is then used to search for two strings that are ! in the list, and the Insert method is used to insert them. The return value of the BinarySearch(T) method is negative in each case, because the strings are ! in the list. Taking the bitwise complement of this negative number produces the index of the first element in the list that is larger than the search string, and inserting at this location preserves the sort order. The second search string is larger than any element in the list, so the insertion position is at the end of the list.
          /// @include ListBinarySearch.cpp
          int32 BinarySearch(const T& item) const {return BinarySearch(0, this->Count, item, System::Collections::Generic::Comparer<T>::Default);}

          /// @brief Searches the entire sorted List<T> for an element using the specified comparer and returns the zero-based index of the element.
          /// @param item The object to locate. The value can be null for reference types.
          /// @param comparer The IComparer<T> implementation to use when comparing elements. -or- null to use the default comparer Comparer<T>.Default.
          /// @return int32 The zero-based index of item in the sorted List<T>, if item is found; otherwise, a negative number that is the bitwise complement of the index of the next element that is larger than item or, if there is no larger element, the bitwise complement of Count.
          /// @exception InvalidOperationException comparer is null, and the default comparer Comparer<T>.Default cannot find an implementation of the IComparable<T> generic interface or the IComparable interface for type T.
          /// @remarks The comparer customizes how the elements are compared. For example, you can use a CaseInsensitiveComparer instance as the comparer to perform case-insensitive string searches.
          /// @remarks If comparer is provided, the elements of the List<T> are compared to the specified value using the specified IComparer<T> implementation.
          /// @remarks If comparer is null, the default comparer Comparer<T>.Default checks whether type T implements the IComparable<T> generic interface and uses that implementation, if available. If !, Comparer<T>.Default checks whether type T implements the IComparable interface. If type T does ! implement either interface, Comparer<T>.Default throws InvalidOperationException.
          /// @remarks The List<T> must already be sorted according to the comparer implementation; otherwise, the result is incorrect.
          /// @remarks Comparing null with any reference type is allowed and does ! generate an exception when using the IComparable<T> generic interface. When sorting, null is considered to be less than any other object.
          /// @remarks If the List<T> contains more than one element with the same value, the method returns only one of the occurrences, and it might return any one of the occurrences, not necessarily the first one.
          /// @remarks If the List<T> does ! contain the specified value, the method returns a negative integer. You can apply the bitwise complement operation (~) to this negative integer to get the index of the first element that is larger than the search value. When inserting the value into the List<T>, this index should be used as the insertion point to maintain the sort order.
          /// @remarks This method is an O(log n) operation, where n is the number of elements in the range.
          int32 BinarySearch(const T& item, const IComparer<T>& comparer) const {return BinarySearch(0, this->Count, item, comparer);}

          /// @brief Searches a range of elements in the sorted List<T> for an element using the specified comparer and returns the zero-based index of the element.
          /// @param index The zero-based starting index of the range to search.
          /// @param count The length of the range to search.
          /// @param item The object to locate. The value can be null for reference types.
          /// @param comparer The IComparer<T> implementation to use when comparing elements, or null to use the default comparer Comparer<T>.Default.
          /// @return int32 The zero-based index of item in the sorted List<T>, if item is found; otherwise, a negative number that is the bitwise complement of the index of the next element that is larger than item or, if there is no larger element, the bitwise complement of Count.
          /// @exception ArgumentOutOfRangeException index is less than 0. -or- count is less than 0.
          /// @exception ArgumentException index and count do not denote a valid range in the List<T>.
          /// @exception InvalidOperationException comparer is null, and the default comparer Comparer<T>.Default cannot find an implementation of the IComparable<T> generic interface or the IComparable interface for type T.
          /// @remarks The comparer customizes how the elements are compared. For example, you can use a CaseInsensitiveComparer instance as the comparer to perform case-insensitive string searches.
          /// @remarks If comparer is provided, the elements of the List<T> are compared to the specified value using the specified IComparer<T> implementation.
          /// @remarks If comparer is null, the default comparer Comparer<T>.Default checks whether type T implements the IComparable<T> generic interface and uses that implementation, if available. If not, Comparer<T>.Default checks whether type T implements the IComparable interface. If type T does not implement either interface, Comparer<T>.Default throws InvalidOperationException.
          /// @remarks The List<T> must already be sorted according to the comparer implementation; otherwise, the result is incorrect.
          /// @remarks Comparing null with any reference type is allowed and does not generate an exception when using the IComparable<T> generic interface. When sorting, null is considered to be less than any other object.
          /// @remarks If the List<T> contains more than one element with the same value, the method returns only one of the occurrences, and it might return any one of the occurrences, not necessarily the first one.
          /// @remarks If the List<T> does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operation (~) to this negative integer to get the index of the first element that is larger than the search value. When inserting the value into the List<T>, this index should be used as the insertion point to maintain the sort order.
          /// @remarks This method is an O(log n) operation, where n is the number of elements in the range.
          int32 BinarySearch(int32 index, int32 count, const T& item, const IComparer<T>& comparer) const {
            if (index < 0 || count < 0)
              throw ArgumentOutOfRangeException(caller_);
            if (index + count > this->Count)
              throw ArgumentException(caller_);
            typename std::vector<T, TAllocator>::iterator first = const_cast<List*>(this)->list.begin();
            typename std::vector<T, TAllocator>::iterator last = const_cast<List*>(this)->list.begin();
            std::advance(first, index);
            std::advance(last, index + count);
            typename std::vector<T, TAllocator>::iterator position = std::lower_bound(first, last, item, List::Comparer(&comparer));

            if (position != this->list.end() && !comparer.Compare(item, *position))
              return static_cast<int32>(std::distance(const_cast<List*>(this)->list.begin(), position));

            return static_cast<int32>(~std::distance(const_cast<List*>(this)->list.begin(), position));
          }

          /// @brief Removes all elements from the List<T>.
          /// @remarks Count is set to 0, and references to other objects from elements of the collection are also released.
          /// @remarks Capacity remains unchanged. To reset the capacity of the List<T>, call the TrimExcess method or set the Capacity property directly. Decreasing the capacity reallocates memory and copies all the elements in the List<T>. Trimming an empty List<T> sets the capacity of the List<T> to the default capacity.
          /// @remarks This method is an O(n) operation, where n is Count.
          /// @remarks The following code example demonstrates several properties and methods of the List<T> generic class, including the Add method. The default constructor is used to create a list of strings with a capacity of 0. The Capacity property is displayed, and then the Add method is used to add several items. The items are listed, and the Capacity property is displayed again, along with the Count property, to show that the capacity has been increased as needed.
          /// @par Examples
          /// Other properties and methods are used to search for, insert, and remove elements from the list, and finally to clear the list.
          /// @include List.cpp
          void Clear() override {
            while (this->Count)
              this->RemoveAt(this->Count - 1);
          }

          /// @brief Determines whether an element is in the List<T>.
          /// @param value The object to locate in the List<T>. The value can be null for reference types.
          /// @return true if item is found in the List<T>; otherwise, false.
          /// @remarks This method determines equality by using the default equality comparer, as defined by the object's implementation of the IEquatable<T>.Equals method for T (the type of values in the list).
          /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is Count.
          virtual bool Contains(const T& value) const override {
            for (const T& elem : *this)
              if (elem == value)
                return true;

            return false;
          }

          /// @brief Copies the entire List<T> to a compatible one-dimensional array.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @exception ArgumentNullException array is null.
          /// @exception ArgumentException The number of elements in the source List<T> is greater than the number of elements that the destination array can contain.
          /// @remarks TThis method uses Array.Copy to copy the elements.
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the List<T>.
          /// @remarks This method is an O(n) operation, where n is Count.
          /// @par Examples
          /// The following code example demonstrates all three overloads of the CopyTo method. A List<T> of strings is created and populated with 5 strings. An empty string array of 15 elements is created, and the CopyTo(T[]) method overload is used to copy all the elements of the list to the array beginning at the first element of the array. The CopyTo(T[], Int32) method overload is used to copy all the elements of the list to the array beginning at array index 6 (leaving index 5 empty). Finally, the CopyTo(Int32, T[], Int32, Int32) method overload is used to copy 3 elements from the list, beginning with index 2, to the array beginning at array index 12 (leaving index 11 empty). The contents of the array are then displayed.
          /// @include ListCopyTo.cpp
          void CopyTo(Array<T>& array) const {this->CopyTo(0, array, 0, this->Count);}

          /// @brief Copies the entire List<T> to a compatible one-dimensional array, starting at the specified index of the target array.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @param arrayIndex The zero-based index in array at which copying begins;
          /// @exception ArgumentNullException array is null.
          /// @exception ArgumentOutOfRangeException The arrayIndex is less than 0.
          /// @exception ArgumentException The number of elements in the source List<T> is greater than the number of elements that the destination array can contain.
          /// @remarks TThis method uses Array.Copy to copy the elements.
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the List<T>.
          /// @remarks This method is an O(n) operation, where n is Count.
          /// @par Examples
          /// The following code example demonstrates all three overloads of the CopyTo method. A List<T> of strings is created and populated with 5 strings. An empty string array of 15 elements is created, and the CopyTo(T[]) method overload is used to copy all the elements of the list to the array beginning at the first element of the array. The CopyTo(T[], Int32) method overload is used to copy all the elements of the list to the array beginning at array index 6 (leaving index 5 empty). Finally, the CopyTo(Int32, T[], Int32, Int32) method overload is used to copy 3 elements from the list, beginning with index 2, to the array beginning at array index 12 (leaving index 11 empty). The contents of the array are then displayed.
          /// @include ListCopyTo.cpp
          virtual void CopyTo(Array<T>& array, int32 arrayIndex) const override {this->CopyTo(0, array, arrayIndex, this->Count);}

          /// @brief Copies the entire List<T> to a compatible one-dimensional array, starting at the specified index of the target array.
          /// @param index The zero-based index in the source List<T> at which copying begins.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @param arrayIndex The zero-based index in array at which copying begins;
          /// @param count The number of elements to copy.
          /// @exception ArgumentNullException array is null.
          /// @exception ArgumentOutOfRangeException The arrayIndex or count is less than 0.
          /// @exception ArgumentException The number of elements in the source List<T> is greater than the number of elements that the destination array can contain.
          /// @remarks TThis method uses Array.Copy to copy the elements.
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the List<T>.
          /// @remarks This method is an O(n) operation, where n is Count.
          /// @par Examples
          /// The following code example demonstrates all three overloads of the CopyTo method. A List<T> of strings is created and populated with 5 strings. An empty string array of 15 elements is created, and the CopyTo(T[]) method overload is used to copy all the elements of the list to the array beginning at the first element of the array. The CopyTo(T[], Int32) method overload is used to copy all the elements of the list to the array beginning at array index 6 (leaving index 5 empty). Finally, the CopyTo(Int32, T[], Int32, Int32) method overload is used to copy 3 elements from the list, beginning with index 2, to the array beginning at array index 12 (leaving index 11 empty). The contents of the array are then displayed.
          /// @include ListCopyTo.cpp
          void CopyTo(int32 index, Array<T>& array, int32 arrayIndex, int32 count) const {
            if (index < 0 || array.Length < 0 || arrayIndex < 0 || count < 0)
              throw ArgumentOutOfRangeException(caller_);

            if (index + count > this->Count || arrayIndex + count > array.Length)
              throw ArgumentException(caller_);

            int32 i = 0, c = 0;
            for (const T& item : *this) {
              if (i >= index + count)
                return;
              if (i >= index) {
                array[arrayIndex + c] = item;
                c += 1;
              }
              i += 1;
            }
          }

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
          bool Exists(const Predicate<const T&>& match) const {
            for (const T& elem : *this)
              if (match(elem))
                return true;

            return false;
          }

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the first occurrence within the entire List<T>.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return The first element that matches the conditions defined by the specified predicate, if found; otherwise, the default value for type T.
          /// @exception ArgumentNUllException match is null.
          /// @remarks The Predicate<T> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current List<T> are individually passed to the Predicate<T> delegate, moving forward in the List<T>, starting with the first element and ending with the last element. Processing is stopped when a match is found.
          /// @note When searching a list containing value types, make sure the default value for the type does ! satisfy the search predicate. Otherwise, there is no way to distinguish between a default value indicating that no match was found and a list element that happens to have the default value for the type. If the default value satisfies the search predicate, use the FindIndex method instead.
          /// @note This method performs a linear search; therefore, this method is an O(n) operation, where n is Count.
          /// @note The following example demonstrates the find methods for the List<T> class. The example for the List<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
          /// @note The following table describes the examples provided for the find methods.
          /// | Method                                   | Example                                                                                                                 |
          /// |------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
          /// |Find(Predicate<T>)                        | Finds a book by an ID using the IDToFind predicate delegate.                                                            |
          /// |FindAll(Predicate<T>)                     | Find all books that whose Genre property is "Computer" using the FindComputer predicate delegate.                       |
          /// |FindLast(Predicate<T>)                    | Finds the last book in the collection that has a publish date before 2001, using the PubBefore2001 predicate delegate.  |
          /// |FindIndex(Predicate<T>)                   | Finds the index of first computer book using the FindComputer predicate delegate.                                       |
          /// |FindLastIndex(Predicate<T>)               | Finds the index of the last computer book using the FindComputer predicate delegate.                                    |
          /// |FindIndex(Int32, Int32, Predicate<T>)     | Finds the index of first computer book in the second half of the collection, using the FindComputer predicate delegate. |
          /// |FindLastIndex(Int32, Int32, Predicate<T>) | Finds the index of last computer book in the second half of the collection, using the FindComputer predicate delegate.  |
          /// @par Examples
          /// @include ListFind.cpp
          const T Find(const Predicate<const T&>& match) const {
            for (const T& elem : *this)
              if (match(elem))
                return elem;

            return T();
          }

          /// @brief Retrieves all the elements that match the conditions defined by the specified predicate.
          /// @param match The Predicate<T> delegate that defines the conditions of the elements to search for.
          /// @return A List<T> containing all the elements that match the conditions defined by the specified predicate, if found; otherwise, an empty List<T>.
          /// @exception ArgumentNUllException match is null.
          /// @remarks The Predicate<T> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current List<T> are individually passed to the Predicate<T> delegate, and the elements that match the conditions are saved in the returned List<T>.
          /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is Count.
          /// @remarks The following example demonstrates the find methods for the List<T> class. The example for the List<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
          /// @remarks The following table describes the examples provided for the find methods.
          /// | Method                                   | Example                                                                                                                 |
          /// |------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
          /// |Find(Predicate<T>)                        | Finds a book by an ID using the IDToFind predicate delegate.                                                            |
          /// |FindAll(Predicate<T>)                     | Find all books that whose Genre property is "Computer" using the FindComputer predicate delegate.                       |
          /// |FindLast(Predicate<T>)                    | Finds the last book in the collection that has a publish date before 2001, using the PubBefore2001 predicate delegate.  |
          /// |FindIndex(Predicate<T>)                   | Finds the index of first computer book using the FindComputer predicate delegate.                                       |
          /// |FindLastIndex(Predicate<T>)               | Finds the index of the last computer book using the FindComputer predicate delegate.                                    |
          /// |FindIndex(Int32, Int32, Predicate<T>)     | Finds the index of first computer book in the second half of the collection, using the FindComputer predicate delegate. |
          /// |FindLastIndex(Int32, Int32, Predicate<T>) | Finds the index of last computer book in the second half of the collection, using the FindComputer predicate delegate.  |
          /// @par Examples
          /// @include ListFind.cpp
          List FindAll(const Predicate<const T&>& match) const {
            List list;

            for (const T& elem : *this)
              if (match(elem))
                list.Add(elem);

            return list;
          }

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of first occurrence within the entire List<T>.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return Int32 The first zero-based index of the first occurrence of an element that matches the conditions defined by match, if found; otherwise, -1.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current List<T> are individually passed to the Predicate pointer function, moving forward in the List<T>, starting with the first element and ending with the last element. Processing is stopped when a match is found.
          /// @remarks The following example demonstrates the find methods for the List<T> class. The example for the List<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
          /// @remarks The following table describes the examples provided for the find methods.
          /// | Method                                   | Example                                                                                                                 |
          /// |------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
          /// |Find(Predicate<T>)                        | Finds a book by an ID using the IDToFind predicate delegate.                                                            |
          /// |FindAll(Predicate<T>)                     | Find all books that whose Genre property is "Computer" using the FindComputer predicate delegate.                       |
          /// |FindLast(Predicate<T>)                    | Finds the last book in the collection that has a publish date before 2001, using the PubBefore2001 predicate delegate.  |
          /// |FindIndex(Predicate<T>)                   | Finds the index of first computer book using the FindComputer predicate delegate.                                       |
          /// |FindLastIndex(Predicate<T>)               | Finds the index of the last computer book using the FindComputer predicate delegate.                                    |
          /// |FindIndex(Int32, Int32, Predicate<T>)     | Finds the index of first computer book in the second half of the collection, using the FindComputer predicate delegate. |
          /// |FindLastIndex(Int32, Int32, Predicate<T>) | Finds the index of last computer book in the second half of the collection, using the FindComputer predicate delegate.  |
          /// @par Examples
          /// @include ListFind.cpp
          int32 FindIndex(const Predicate<const T&>& match) const {return this->FindIndex(0, this->Count, match);}

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of first occurrence within the entire List<T>.
          /// @param sratIndex The zero-based starting index of the search.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return Int32 The first zero-based index of the first occurrence of an element that matches the conditions defined by match, if found; otherwise, -1.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current List<T> are individually passed to the Predicate pointer function, moving forward in the List<T>, starting with the first element and ending with the last element. Processing is stopped when a match is found.
          /// @remarks The following example demonstrates the find methods for the List<T> class. The example for the List<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
          /// @remarks The following table describes the examples provided for the find methods.
          /// | Method                                   | Example                                                                                                                 |
          /// |------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
          /// |Find(Predicate<T>)                        | Finds a book by an ID using the IDToFind predicate delegate.                                                            |
          /// |FindAll(Predicate<T>)                     | Find all books that whose Genre property is "Computer" using the FindComputer predicate delegate.                       |
          /// |FindLast(Predicate<T>)                    | Finds the last book in the collection that has a publish date before 2001, using the PubBefore2001 predicate delegate.  |
          /// |FindIndex(Predicate<T>)                   | Finds the index of first computer book using the FindComputer predicate delegate.                                       |
          /// |FindLastIndex(Predicate<T>)               | Finds the index of the last computer book using the FindComputer predicate delegate.                                    |
          /// |FindIndex(Int32, Int32, Predicate<T>)     | Finds the index of first computer book in the second half of the collection, using the FindComputer predicate delegate. |
          /// |FindLastIndex(Int32, Int32, Predicate<T>) | Finds the index of last computer book in the second half of the collection, using the FindComputer predicate delegate.  |
          /// @par Examples
          /// @include ListFind.cpp
          int32 FindIndex(int32 startIndex, const Predicate<const T&>& match) const {return this->FindIndex(startIndex, this->Count - startIndex, match);}

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of first occurrence within the entire List<T>.
          /// @param startIndex The zero-based starting index of the search.
          /// @param count The number of elements in the section to search.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return Int32 The first zero-based index of the first occurrence of an element that matches the conditions defined by match, if found; otherwise, -1.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current List<T> are individually passed to the Predicate pointer function, moving forward in the List<T>, starting with the first element and ending with the last element. Processing is stopped when a match is found.
          /// @remarks The following example demonstrates the find methods for the List<T> class. The example for the List<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
          /// @remarks The following table describes the examples provided for the find methods.
          /// | Method                                   | Example                                                                                                                 |
          /// |------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
          /// |Find(Predicate<T>)                        | Finds a book by an ID using the IDToFind predicate delegate.                                                            |
          /// |FindAll(Predicate<T>)                     | Find all books that whose Genre property is "Computer" using the FindComputer predicate delegate.                       |
          /// |FindLast(Predicate<T>)                    | Finds the last book in the collection that has a publish date before 2001, using the PubBefore2001 predicate delegate.  |
          /// |FindIndex(Predicate<T>)                   | Finds the index of first computer book using the FindComputer predicate delegate.                                       |
          /// |FindLastIndex(Predicate<T>)               | Finds the index of the last computer book using the FindComputer predicate delegate.                                    |
          /// |FindIndex(Int32, Int32, Predicate<T>)     | Finds the index of first computer book in the second half of the collection, using the FindComputer predicate delegate. |
          /// |FindLastIndex(Int32, Int32, Predicate<T>) | Finds the index of last computer book in the second half of the collection, using the FindComputer predicate delegate.  |
          /// @par Examples
          /// @include ListFind.cpp
          int32 FindIndex(int32 startIndex, int32 count, const Predicate<const T&>& match) const {
            if (startIndex < 0 || count < 0)
              throw ArgumentOutOfRangeException(caller_);
            if (startIndex + count > this->Count)
              throw ArgumentException(caller_);

            for (int32 i = 0; i < count; i += 1)
              if (match(this->list[i + startIndex]))
                return startIndex + i;

            return -1;
          }

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the last occurrence within the entire List<T>.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return T The last element that matches the conditions defined by the specified predicate, if found; otherwise, the default value for type T.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current List<T> are individually passed to the Predicate pointer function, moving forward in the List<T>, starting with the first element and ending with the last element.
          /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is Count.
          /// @remarks The following example demonstrates the find methods for the List<T> class. The example for the List<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
          /// @remarks The following table describes the examples provided for the find methods.
          /// | Method                                   | Example                                                                                                                 |
          /// |------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
          /// |Find(Predicate<T>)                        | Finds a book by an ID using the IDToFind predicate delegate.                                                            |
          /// |FindAll(Predicate<T>)                     | Find all books that whose Genre property is "Computer" using the FindComputer predicate delegate.                       |
          /// |FindLast(Predicate<T>)                    | Finds the last book in the collection that has a publish date before 2001, using the PubBefore2001 predicate delegate.  |
          /// |FindIndex(Predicate<T>)                   | Finds the index of first computer book using the FindComputer predicate delegate.                                       |
          /// |FindLastIndex(Predicate<T>)               | Finds the index of the last computer book using the FindComputer predicate delegate.                                    |
          /// |FindIndex(Int32, Int32, Predicate<T>)     | Finds the index of first computer book in the second half of the collection, using the FindComputer predicate delegate. |
          /// |FindLastIndex(Int32, Int32, Predicate<T>) | Finds the index of last computer book in the second half of the collection, using the FindComputer predicate delegate.  |
          /// @par Examples
          /// @include ListFind.cpp
          const T FindLast(const Predicate<const T&>& match) const {
            if (this->list.size() > 0) {
              for (size_t index = this->list.size() - 1; index > 0; index--)
                if (match(this->list[index]))
                  return this->list[index];
            }
            /*
            for (typename std::vector<T>::const_reverse_iterator it = this->list.crbegin(); it < this->list.crend(); ++it)
              if (match(*it))
                return *it;
            */
            return T();
          }

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of last occurrence within the entire List<T>.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return Int32 The first zero-based index of the last occurrence of an element that matches the conditions defined by match, if found; otherwise, -1.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current List<T> are individually passed to the Predicate pointer function, moving forward in the List<T>, starting with the first element and ending with the last element. Processing is stopped when a match is found.
          /// @remarks The following example demonstrates the find methods for the List<T> class. The example for the List<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
          /// @remarks The following table describes the examples provided for the find methods.
          /// | Method                                   | Example                                                                                                                 |
          /// |------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
          /// |Find(Predicate<T>)                        | Finds a book by an ID using the IDToFind predicate delegate.                                                            |
          /// |FindAll(Predicate<T>)                     | Find all books that whose Genre property is "Computer" using the FindComputer predicate delegate.                       |
          /// |FindLast(Predicate<T>)                    | Finds the last book in the collection that has a publish date before 2001, using the PubBefore2001 predicate delegate.  |
          /// |FindIndex(Predicate<T>)                   | Finds the index of first computer book using the FindComputer predicate delegate.                                       |
          /// |FindLastIndex(Predicate<T>)               | Finds the index of the last computer book using the FindComputer predicate delegate.                                    |
          /// |FindIndex(Int32, Int32, Predicate<T>)     | Finds the index of first computer book in the second half of the collection, using the FindComputer predicate delegate. |
          /// |FindLastIndex(Int32, Int32, Predicate<T>) | Finds the index of last computer book in the second half of the collection, using the FindComputer predicate delegate.  |
          /// @par Examples
          /// @include ListFind.cpp
          int32 FindLastIndex(const Predicate<const T&>& match) const {return this->FindLastIndex(this->Count - 1, this->Count, match);}

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of the last occurrence within the range of elements in the List<T> that extends from the first element to the specified index.
          /// @param startIndex The zero-based starting index of the search.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return Int32 The first zero-based index of the last occurrence of an element that matches the conditions defined by match, if found; otherwise, -1.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current List<T> are individually passed to the Predicate pointer function, moving forward in the List<T>, starting with the first element and ending with the last element. Processing is stopped when a match is found.
          /// @remarks The following example demonstrates the find methods for the List<T> class. The example for the List<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
          /// @remarks The following table describes the examples provided for the find methods.
          /// | Method                                   | Example                                                                                                                 |
          /// |------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
          /// |Find(Predicate<T>)                        | Finds a book by an ID using the IDToFind predicate delegate.                                                            |
          /// |FindAll(Predicate<T>)                     | Find all books that whose Genre property is "Computer" using the FindComputer predicate delegate.                       |
          /// |FindLast(Predicate<T>)                    | Finds the last book in the collection that has a publish date before 2001, using the PubBefore2001 predicate delegate.  |
          /// |FindIndex(Predicate<T>)                   | Finds the index of first computer book using the FindComputer predicate delegate.                                       |
          /// |FindLastIndex(Predicate<T>)               | Finds the index of the last computer book using the FindComputer predicate delegate.                                    |
          /// |FindIndex(Int32, Int32, Predicate<T>)     | Finds the index of first computer book in the second half of the collection, using the FindComputer predicate delegate. |
          /// |FindLastIndex(Int32, Int32, Predicate<T>) | Finds the index of last computer book in the second half of the collection, using the FindComputer predicate delegate.  |
          /// @par Examples
          /// @include ListFind.cpp
          int32 FindLastIndex(int32 startIndex, const Predicate<const T&>& match) const {return this->FindLastIndex(startIndex, startIndex + 1, match);}

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of the last occurrence within the range of elements in the List<T> that contains the specified number of elements and ends at the specified index.
          /// @param startIndex The zero-based starting index of the search.
          /// @param count The number of elements in the section to search.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return Int32 The first zero-based index of the last occurrence of an element that matches the conditions defined by match, if found; otherwise, -1.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current List<T> are individually passed to the Predicate pointer function, moving forward in the List<T>, starting with the first element and ending with the last element. Processing is stopped when a match is found.
          /// @remarks The following example demonstrates the find methods for the List<T> class. The example for the List<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
          /// @remarks The following table describes the examples provided for the find methods.
          /// | Method                                   | Example                                                                                                                 |
          /// |------------------------------------------|-------------------------------------------------------------------------------------------------------------------------|
          /// |Find(Predicate<T>)                        | Finds a book by an ID using the IDToFind predicate delegate.                                                            |
          /// |FindAll(Predicate<T>)                     | Find all books that whose Genre property is "Computer" using the FindComputer predicate delegate.                       |
          /// |FindLast(Predicate<T>)                    | Finds the last book in the collection that has a publish date before 2001, using the PubBefore2001 predicate delegate.  |
          /// |FindIndex(Predicate<T>)                   | Finds the index of first computer book using the FindComputer predicate delegate.                                       |
          /// |FindLastIndex(Predicate<T>)               | Finds the index of the last computer book using the FindComputer predicate delegate.                                    |
          /// |FindIndex(Int32, Int32, Predicate<T>)     | Finds the index of first computer book in the second half of the collection, using the FindComputer predicate delegate. |
          /// |FindLastIndex(Int32, Int32, Predicate<T>) | Finds the index of last computer book in the second half of the collection, using the FindComputer predicate delegate.  |
          /// @par Examples
          /// @include ListFind.cpp
          int32 FindLastIndex(int32 startIndex, int32 count, const Predicate<const T&>& match) const {
            if (startIndex < 0 || count < 0)
              throw ArgumentOutOfRangeException(caller_);
            if (startIndex >= this->Count)
              throw ArgumentOutOfRangeException(caller_);
            if (startIndex - count < -1)
              throw ArgumentException(caller_);

            for (int32 i = startIndex ; i >= startIndex - (count - 1) ; i -= 1)
              if (match(this->list[i]) == true)
                return i;

            return -1;
          }

          /// @brief Performs the specified action on each element of the List<T>.
          /// @param action The action pointer function to perform on each element of the List<T>.
          /// @return None.
          /// @exception ArgumentNullException The parameters action is null.
          /// @remarks The action is a pointer to a method that performs an action on the object passed to it. The elements of the current List<T> are individually passed to the pointer function.
          /// @remarks This method is an O(n) operation, where n is Count.
          void ForEach(const Action<const T&>& action) {
            for (const T& elem : *this)
              action(elem);
          }

          /// @brief Returns an enumerator that iterates through the List<T>.
          /// @return Int32 A List<T>::Enumerator for the List<T>.
          System::Collections::Generic::Enumerator<T> GetEnumerator() const override {
            class Enumerator : public object, public Collections::Generic::IEnumerator<T> {
            public:
              explicit Enumerator(const List& list) : list(list), operationNumber(list.operationNumber), iterator(list.list.begin()) {}
              void Reset() override {this->beforeFirst = true; this->operationNumber = this->list.operationNumber; this->iterator = this->list.list.begin();}

              bool MoveNext() override {
                if (this->operationNumber != this->list.operationNumber) throw System::InvalidOperationException(caller_);
                if (this->iterator == this->list.list.end()) return false;
                if (this->beforeFirst) {
                  this->beforeFirst = false;
                  return this->iterator != this->list.list.end();
                }
                return ++this->iterator != this->list.list.end();
              }

            protected:
              const T& GetCurrent() const override {
                if (this->beforeFirst || this->iterator == this->list.list.end()) throw System::InvalidOperationException(caller_);
                return *this->iterator;
              }

              const List& list;
              bool beforeFirst = true;
              int64 operationNumber;
              typename std::vector<T, TAllocator>::const_iterator iterator;
            };

            return System::Collections::Generic::Enumerator<T>(new Enumerator(*this));
          }

          /// @brief Creates a shallow copy of a range of elements in the source List<T>.
          /// @param index The zero-based List<T> index at which the range starts.
          /// @param count The number of elements in the range.
          /// @return A shallow copy of a range of elements in the source List<T>.
          /// @exception ArgumentOutOfRangeException index is less than 0. -or- count is less than 0.
          /// @exception ArgumentException index and count do ! denote a valid range of elements in the List<T>.
          /// @remarks A shallow copy of a collection of reference types, or a subset of that collection, contains only the references to the elements of the collection. The objects themselves are ! copied. The references in the new list point to the same objects as the references in the original list.
          /// @remarks A shallow copy of a collection of value types, or a subset of that collection, contains the elements of the collection. However, if the elements of the collection contain references to other objects, those objects are ! copied. The references in the elements of the new collection point to the same objects as the references in the elements of the original collection.
          /// @remarks In contrast, a deep copy of a collection copies the elements and everything directly or indirectly referenced by the elements.
          /// @remarks This method is an O(n) operation, where n is count.
          /// @par Examples
          /// The following code example demonstrates the GetRange method and other methods of the List<T> class that act on ranges. At the end of the code example, the GetRange method is used to get three items from the list, beginning with index location 2. The ToArray method is called on the resulting List<T>, creating an array of three elements. The elements of the array are displayed.
          /// @include List2.cpp
          List GetRange(int32 index, int32 count) {
            if (index < 0 || count < 0)
              throw ArgumentOutOfRangeException(caller_);

            if (index + count > this->Count)
              throw ArgumentException(caller_);

            List list;
            for (int32 i = index ; i < index + count ; i += 1)
              list.Add(this->list[i]);
            return list;
          }

          /// @brief Determines the index of a specific item in the List.
          /// @param value The object to locate in the List.
          /// @return Int32 The index of value if found in the list; otherwise, -1.
          virtual int32 IndexOf(const T& value) const override {
            if (this->Count == 0)
              return -1;
            return this->IndexOf(value, 0, this->Count);
          }

          /// @brief Determines the index of a specific item in the List.
          /// @param value The object to locate in the List.
          /// @param index The zero-based starting index of the search.
          /// @return Int32 The index of value if found in the list; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0.
          virtual int32 IndexOf(const T& value, int32 index) const {
            return this->IndexOf(value, index, this->Count - index);
          }

          /// @brief Determines the index of a specific item in the List.
          /// @param value The object to locate in the List.
          /// @param index The zero-based starting index of the search.
          /// @param count The number of elements in the section to search
          /// @return Int32 The index of value if found in the list; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0 or The parameters count is less than 0 or index and count do ! specify a valid section in the List<T>.
          virtual int32 IndexOf(const T& value, int32 index, int32 count) const {
            if (index < 0 || count < 0 || index >= this->Count)
              throw ArgumentOutOfRangeException(caller_);

            if (index + count > this->Count)
              throw ArgumentOutOfRangeException(caller_);

            for (int32 i = index; i < index + count; i++)
              if (this->list[i] == value)
                return i;

            return -1;
          }

          /// @brief Inserts an element into the List<T> at the specified index.
          /// @param index The zero-based index at which the new element should be inserted.
          /// @param value The element should be inserted into the List<T>. The value can ! be null.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is greater than Count.
          /// @remarks List<T> allows duplicate elements.
          virtual void Insert(int32 index, const T& value) override {
            if (index < 0)
              throw ArgumentOutOfRangeException(caller_);

            this->operationNumber++;
            this->list.insert(this->list.begin() + index, value);
          }

          /// @brief Inserts copy of elements from a collection into the List<T> at the specified index.
          /// @param index The zero-based index at which the new elements should be inserted.
          /// @param collection The collection whose elements should be inserted into the List<T>. The value can ! be null and cannot contains reference element null.
          /// @exception ArgumentNullException The parameters collection is null or element reference null in collection.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is greater than Count.
          /// @remarks List<T> allows duplicate elements.
          /// @remarks The order of the elements in the collection is preserved in the List<T>.
          void InsertRange(int32 index, const IEnumerable<T>& enumerable) {
            if (index < 0)
              throw ArgumentOutOfRangeException(caller_);

            this->operationNumber++;

            typename std::vector<T, TAllocator>::iterator position = this->list.begin() + index;
            for (const T& value : enumerable)
              position = this->list.insert(position, value) + 1;
          }

          /// @brief Determines the last index of a specific item in the List.
          /// @param value The object to locate in the List.
          /// @return Int32 The last index of value if found in the list; otherwise, -1.
          int32 LastIndexOf(const T& value) const {
            if (this->Count == 0)
              return -1;
            return this->LastIndexOf(value, this->Count - 1, this->Count);
          }

          /// @brief Determines the last index of a specific item in the List.
          /// @param value The object to locate in the List.
          /// @param index The zero-based starting index of the search.
          /// @return Int32 The last index of value if found in the list; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0.
          int32 LastIndexOf(const T& value, int32 index) const {
            return this->LastIndexOf(value, index, index + 1);
          }

          /// @brief Determines the last index of a specific item in the List.
          /// @param value The object to locate in the List.
          /// @param index The zero-based starting index of the search.
          /// @param count The number of elements in the section to search
          /// @return Int32 The last index of value if found in the list; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0 or The parameters count is less than 0 or index and count do ! specify a valid section in the List<T>.
          int32 LastIndexOf(const T& value, int32 index, int32 count) const {
            if (index < 0 || count < 0 || index >= this->Count)
              throw ArgumentOutOfRangeException(caller_);

            if (index - count < -1)
              throw System::ArgumentException(caller_);

            for (int32 i = index; i >= index - (count - 1); i -= 1)
              if (value == this->list[i])
                return i;

            return -1;
          }

          /// @brief Removes the first occurrence of a specific object from the List<T>.
          /// @param item The object to remove from the List<(Of <(T>)>). The value can ! be null.
          /// @return Boolean true if item is successfully removed; otherwise, false. This method also returns false if item was ! found in the List<T>.
          virtual bool Remove(const T& item) override {
            if (this->Count == 0)
              return false;

            for (typename std::vector<T, TAllocator>::iterator it = this->list.begin(); it != this->list.end() ; it++) {
              if (*it == item) {
                this->list.erase(it);
                return true;
              }
            }

            return false;
          }

          /// @brief Removes all the elements that match the conditions defined by the specified predicate.
          /// @param match The Predicate<T> delegate that defines the conditions of the elements to remove.
          /// @return The number of elements removed from the List<T> .
          /// @exception ArgumentNullException match is null
          /// @remarks The Predicate<T> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current List<T> are individually passed to the Predicate<T> delegate, and the elements that match the conditions are removed from the List<T>.
          /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is Count.
          /// @remarks The following code example demonstrates the RemoveAll method and several other methods that use the Predicate<T> generic delegate.
          /// @remarks A List<T> of strings is created, containing 8 dinosaur names, two of which (at positions 1 and 5) end with "saurus". The code example also defines a search predicate method named EndsWithSaurus, which accepts a string parameter and returns a Boolean value indicating whether the input string ends in "saurus".
          /// @remarks The Find, FindLast, and FindAll methods are used to search the list with the search predicate method.
          /// @par Examples
          /// The RemoveAll method is used to remove all entries ending with "saurus". It traverses the list from the beginning, passing each element in turn to the EndsWithSaurus method. The element is removed if the EndsWithSaurus method returns true.
          /// @include ListExists.cpp
          virtual int32 RemoveAll(const Predicate<const T&>& match) {
            int32 count = 0;
            typename std::vector<T, TAllocator>::const_iterator iterator = this->list.begin();
            while (iterator != this->list.end())
              if (!match(*iterator))
                iterator++;
              else {
                iterator = this->list.erase(iterator);
                count += 1;
              }

            if (count)
              this->operationNumber++;
            return count;
          }

          /// @brief Removes the element at the specified index of the List<T>.
          /// @param index The zero-based index of the item to remove
          /// @return None.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is greater than Count.
          virtual void RemoveAt(int32 index) override {
            if (index < 0 || index >= this->Count)
              throw ArgumentOutOfRangeException(caller_);

            this->operationNumber++;
            if (index == static_cast<int32>(this->list.size() - 1))
              this->list.pop_back();
            else
              this->list.erase(this->list.begin() + index);
          }

          /// @brief Removes a range of elements from the List<T>.
          /// @param index The zero-based index of the item to remove
          /// @param count The number of elements to remove
          /// @return None.
          /// @exception ArgumentOutOfRangeException index or count is less than 0 or index + count is greater than Count.
          /// @remarks The items are removed and all the elements following them in the List<T> have their indexes reduced by count.
          virtual void RemoveRange(int32 index, int32 count) {
            if (index < 0 || index + count > this->Count)
              throw ArgumentOutOfRangeException(caller_);

            this->operationNumber++;
            typename std::vector<T, TAllocator>::iterator begin = this->list.begin() + index;
            typename std::vector<T, TAllocator>::iterator end = this->list.begin() + index + count;
            this->list.erase(begin, end);
          }

          /// @brief Reverses the order of the elements in the entire List<T>.
          /// @remarks This method uses Array.Reverse to reverse the order of the elements, such that the element at List<T>[i], where i is any index within the range, moves to List<T>[j], where j equals index plus index plus count minus i minus 1.
          /// @remarks This method is an O(n) operation, where n is Count.
          /// @par Examples
          /// The following code example demonstrates both overloads of the Reverse method. The code example creates a List<T> of strings and adds six strings. The Reverse() method overload is used to reverse the list, and then the Reverse(Int32, Int32) method overload is used to reverse the middle of the list, beginning with element 1 and encompassing four elements.
          /// @include ListReverse.cpp
          void Reverse() {
            this->operationNumber++;
            std::reverse(this->list.begin(), this->list.end());
          }

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
          void Reverse(int32 index, int32 count) {
            if (index < 0 || count < 0)
              throw ArgumentOutOfRangeException(caller_);

            if (index + count > this->Count)
              throw ArgumentException(caller_);

            this->operationNumber++;
            int pos1 = index, pos2 = (index + count) - 1;
            typename std::vector<T, TAllocator>::iterator it1 = this->list.begin() + pos1, it2 = this->list.begin() + pos2;

            while (pos1++ < pos2--)
              std::iter_swap(it1++, it2--);
          }

          /// @brief Sorts the elements in the entire List<T> using the default comparer.
          /// @exception InvalidOperationException The default comparer Comparer<T>.Default cannot find an implementation of the IComparable<T> generic interface or the IComparable interface for type T.
          /// @remarks This method uses the default comparer Comparer<T>.Default for type T to determine the order of list elements. The Comparer<T>.Default property checks whether type T implements the IComparable<T> generic interface and uses that implementation, if available. If !, Comparer<T>.Default checks whether type T implements the IComparable interface. If type T does ! implement either interface, Comparer<T>.Default throws an InvalidOperationException.
          /// @remarks This method uses Array.Sort, which uses the QuickSort algorithm. This implementation performs an unstable sort; that is, if two elements are equal, their order might ! be preserved. In contrast, a stable sort preserves the order of elements that are equal.
          /// @remarks On average, this method is an O(n log n) operation, where n is Count; in the worst case it is an O(n ^ 2) operation.
          /// @remarks The following code example demonstrates the Sort() method overload and the BinarySearch(T) method overload. A List<T> of strings is created and populated with four strings, in no particular order. The list is displayed, sorted, and displayed again.
          /// @par Examples
          /// The BinarySearch(T) method overload is then used to search for two strings that are ! in the list, and the Insert method is used to insert them. The return value of the BinarySearch(T) method is negative in each case, because the strings are ! in the list. Taking the bitwise complement of this negative number produces the index of the first element in the list that is larger than the search string, and inserting at this location preserves the sort order. The second search string is larger than any element in the list, so the insertion position is at the end of the list.
          /// @include ListBinarySearch.cpp
          void Sort() {this->Sort(System::Collections::Generic::Comparer<T>::Default);}

          void Sort(Comparison<const T&> comparison) {
            this->operationNumber++;
            std::sort(this->list.begin(), this->list.end(), List::ComparisonComparer(comparison));
          }

          /// @brief Sorts the elements in the entire List<T> using the specified comparer.
          /// @param comparer The IComparer<T> implementation to use when comparing elements, or null to use the default comparer Comparer<T>::Default.
          /// @exception InvalidOperationException comparer is null, and the default comparer Comparer<T>.Default cannot find implementation of the IComparable<T> generic interface or the IComparable interface for type T.
          /// @remarks If comparer is provided, the elements of the List<T> are sorted using the specified IComparer<T> implementation.
          /// @remarks If comparer is null, an exception ArgumentNullException is thrown;
          /// @remarks This method uses Array.Sort, which uses the QuickSort algorithm. This implementation performs an unstable sort; that is, if two elements are equal, their order might ! be preserved. In contrast, a stable sort preserves the order of elements that are equal.
          /// @remarks On average, this method is an O(n log n) operation, where n is Count; in the worst case it is an O(n ^ 2) operation.
          void Sort(const IComparer<T>& comparer) {
            this->operationNumber++;
            std::sort(this->list.begin(), this->list.end(), List::Comparer(&comparer));
          }

          /// @brief Copies the elements of the List<T> to a new array.
          /// @return An array containing copies of the elements of the List<T>.
          /// @remarks The elements are copied using Array.Copy, which is an O(n) operation, where n is Count.
          /// @remarks This method is an O(n) operation, where n is Count.
          /// @par Examples
          /// The following code example demonstrates the ToArray method and other methods of the List<T> class that act on ranges. At the end of the code example, the GetRange method is used to get three items from the list, beginning with index location 2. The ToArray method is called on the resulting List<T>, creating an array of three elements. The elements of the array are displayed.
          /// @include List2.cpp
          Array<T> ToArray() const {
            return Array<T>(this->list);
          }

          /// @brief Sets the capacity to the actual number of elements in the List<T>, if that number is less than a threshold value.
          /// @remarks This method can be used to minimize a collection's memory overhead if no new elements will be added to the collection. The cost of reallocating and copying a large List<T> can be considerable, however, so the TrimExcess method does nothing if the list is at more than 90 percent of capacity. This avoids incurring a large reallocation cost for a relatively small gain.
          /// @note The current threshold of 90 percent might change in future releases.
          /// @note This method is an O(n) operation, where n is Count.
          /// @note To reset a List<T> to its initial state, call the Clear method before calling the TrimExcess method. Trimming an empty List<T> sets the capacity of the List<T> to the default capacity.
          /// @note The capacity can also be set using the Capacity property.
          void TrimExcess() {this->list.shrink_to_fit();}

          /// @brief Determines whether the List<T> contains elements that match the conditions defined by the specified predicate..
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return Boolean true if the List<T> contains one or more elements that match the conditions defined by the specified predicate; otherwise, false.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current List<T> are individually passed to the Predicate pointer function, and processing is stopped when a match is found.
          /// @remarks This method is an O(n) operation, where n is Count.
          bool TrueForAll(const Predicate<const T&>& match) {
            for (const T& elem : *this)
              if (!match(elem))
                return false;

            return true;
          }

          /// @brief Gets the element at the specified index.
          /// @param index The zero-based index of the element to get.
          /// @return T The element at the specified index.
          /// @remarks This function is O(n) ! Prefer the use of an enumerator.
          /// @exception
          /// @remarks ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
          const T& operator[](int32 index) const override {
            if (index < 0 || index > this->Count)
              throw ArgumentOutOfRangeException(caller_);

            return this->list[index];
          }

          /// @brief Gets the element at the specified index.
          /// @param index The zero-based index of the element to get.
          /// @return T The element at the specified index.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is equal to or greater than Count.
          T& operator[](int32 index) override {
            if (index < 0 || index > this->Count)
              throw ArgumentOutOfRangeException(caller_);

            return this->list[index];
          }

          /// @brief Clear the list and insert the element of the list given in argument.
          /// @param list the List<T> which elements will be inserted from
          /// @return List<T> the list
          /// @exception ArgumentNullException list argument is null
          List& operator=(const List& list) {
            this->operationNumber++;
            this->list = list.list;
            return *this;
          }

          bool Equals(const List& list) const {return this->list == list.list;}

          bool Equals(const Object& obj) const override {return is<List>(obj) && Equals(static_cast<const List&>(obj));}

          /// @cond
          using const_iterator = typename std::vector<T, TAllocator>::const_iterator;
          using iterator = typename std::vector<T, TAllocator>::iterator;

          const_iterator cbegin() const {return this->list.begin();}
          const_iterator cend() const {return this->list.end();}
          iterator begin() {return this->list.begin();}
          const_iterator begin() const {return this->list.begin();}
          iterator end() {return this->list.end();}
          const_iterator end() const {return this->list.end();}
          /// @endcond

        private:
          class Comparer : public std::binary_function<T, T, bool> {
          public:
            Comparer(const IComparer<T>* comparer) : comparer(comparer) {}
            Comparer(const Comparer& comparer) {*this = comparer;}
            Comparer& operator=(const Comparer& comparer) {this->comparer = comparer.comparer; return *this;}
            bool operator()(const T& e1, const T& e2) const {return this->comparer->Compare(e1, e2) < 0;}
          private:
            const IComparer<T>* comparer;
          };


          class ComparisonComparer : public std::binary_function<T, T, bool> {
          private:
            Comparison<const T&> comparer;

          public:
            ComparisonComparer(Comparison<const T&> c) : comparer(c) {}
            ComparisonComparer(const ComparisonComparer& lc) {*this = lc;}
            ~ComparisonComparer() {}

            ComparisonComparer& operator=(const ComparisonComparer& lc) {comparer = lc.comparer; return *this;}
            bool operator()(const T& e1, const T& e2) const {return comparer(e1, e2) < 0;}
          };

          virtual int32 GetCount() const override {return static_cast<int32>(this->list.size());}
          virtual bool GetIsFixedSize() const override {return false;}
          virtual bool GetIsReadOnly() const override {return false;}
          virtual bool GetIsSynchronized() const override {return false;}
          virtual const object& GetSyncRoot() const override {return this->syncRoot;}

          std::vector<T, TAllocator> list;
          int64 operationNumber = 0;
          object syncRoot;
        };
      }
    }
  }
}

using namespace Switch;

/// @file
/// @brief Contains Switch::System::Collections::Generic::LinkedList <T> class.
#pragma once

#include <list>

#include <Switch/System/Collections/Generic/Comparer.hpp>
#include <Switch/System/Collections/Generic/IComparer.hpp>
#include <Switch/System/Collections/Generic/ICollection.hpp>
#include <Switch/System/Collections/Generic/GenericException.hpp>
#include <Switch/Allocator.hpp>
#include <Switch/InitializerList.hpp>
#include <Switch/System/Action.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/Comparison.hpp>
#include <Switch/System/Int32.hpp>
#include <Switch/System/Predicate.hpp>
#include <Switch/System/Linq/Enumerable.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @brief Represents a doubly linked list.
        /// @remarks LinkedList<T> is a general-purpose linked list. It supports enumerators and implements the ICollection interface, consistent with other collection classes in the .NET Framework.
        /// @remarks LinkedList<T> provides separate nodes of type LinkedListNode<T>, so insertion and removal are O(1) operations.
        /// @remarks You can remove nodes and reinsert them, either in the same list or in another list, which results in no additional objects allocated on the heap. Because the list also maintains an internal count, getting the Count property is an O(1) operation.
        /// @remarks Each node in a LinkedList<T> object is of the type LinkedListNode<T>. Because the LinkedList<T> is doubly linked, each node points forward to the Next node and backward to the Previous node.
        /// @remarks Lists that contain reference types perform better when a node and its value are created at the same time. LinkedList<T> accepts null as a valid Value property for reference types and allows duplicate values.
        /// @remarks If the LinkedList<T> is empty, the First and Last properties contain null.
        /// @remarks The LinkedList<T> class does not support chaining, splitting, cycles, or other features that can leave the list in an inconsistent state. The list remains consistent on a single thread. The only multithreaded scenario supported by LinkedList<T> is multithreaded read operations.
        /// @par Library
        /// Switch.System
        template<typename T, typename TAllocator = Allocator<T>>
        class LinkedList : public Object, public System::Linq::Extension::Enumerable<LinkedList<T, TAllocator>, T>, public ICollection<T> {
          using Item = T;
        public:
          /// @brief Initializes a new instance of the LinkedList<T> class that is empty.
          /// @remarks The capacity of a LinkedList<T> is the number of elements that the LinkedList<T> can hold. As elements are added to a LinkedList<T>, the capacity is automatically increased as required by reallocating the internal array.
          /// @remarks If the size of the collection can be estimated, using the LinkedList<T>(Int32) constructor and specifying the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the LinkedList<T>.
          /// @remarks The capacity can be decreased by calling the TrimExcess method or by setting the Capacity property explicitly. Decreasing the capacity reallocates memory and copies all the elements in the LinkedList<T>.
          /// @remarks This constructor is an O(1) operation.
          /// @remarks The following code example demonstrates the default constructor of the LinkedList<T> generic class. The default constructor creates a list with the default capacity, as demonstrated by displaying the Capacity property.
          /// @par Examples
          /// The code example adds, inserts, and removes items, showing how the capacity changes as these methods are used.
          /// @include LinkedList.cpp
          LinkedList() : operationNumber(0) {}

          /// @brief Initializes a new instance of the LinkedList<T> class that contains elements copied from the specified collection and has sufficient capacity to accommodate the number of elements copied.
          /// @param collection The collection whose elements are copied to the new list.
          /// @exception ArgumentNullException The parameters collection is null or element reference null in collection.
          /// @remarks The elements are copied onto the LinkedList<T> in the same order they are read by the enumerator of the collection.
          /// @remarks This constructor is an O(n) operation, where n is the number of elements in collection.
          /// @par Examples
          /// The following code example demonstrates the LinkedList<T> constructor and various methods of the LinkedList<T> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The Capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
          /// @include List2.cpp
          LinkedList(const IEnumerable<T>& collection) : operationNumber(0) {
            for (T value : collection)
              this->Add(value);
          }

          /// @brief Default copy constructor
          /// @param list the LinkedList<T> which elements will be inserted from
          LinkedList(const LinkedList& list) : list(list.list), operationNumber(list.operationNumber) {}

          /// @cond
          LinkedList(LinkedList&& list) : list(Move(list.list)), operationNumber(list.operationNumber) {list.operationNumber = 0;}
          /// @endcond

          /// @brief Initializes a new instance of the LinkedList and copy array[] T.
          /// @param array the Array to copy.
          /// @remarks The LinkedList class is not thread safe.
          template<int32 len>
          LinkedList(const T(&array)[len]) : operationNumber(0) {
            for (int32 index = 0; index < len; index++)
              this->Add(array[index]);
          }

          /// @cond
          LinkedList(InitializerList<T> il) : operationNumber(0) {
            for (T item : il)
              this->Add(item);
          }
          /// @endcond

          /// @brief Adds an object to the end of the LinkedList<T>.
          /// @param value The object to be added to the end of the LinkedList<T>. The value can be null for reference types.
          /// @remarks LinkedList<T> accepts null as a valid value for reference types and allows duplicate elements.
          /// @remarks If Count already equals Capacity, the capacity of the LinkedList<T> is increased by automatically reallocating the internal array, and the existing elements are copied to the new array before the new element is added.
          /// @remarks If Count is less than Capacity, this method is an O(1) operation. If the capacity needs to be increased to accommodate the new element, this method becomes an O(n) operation, where n is Count.
          /// @remarks The following code example demonstrates several properties and methods of the LinkedList<T> generic class, including the Add method. The default constructor is used to create a list of strings with a capacity of 0. The Capacity property is displayed, and then the Add method is used to add several items. The items are listed, and the Capacity property is displayed again, along with the Count property, to show that the capacity has been increased as needed.
          /// @par Examples
          /// Other properties and methods are used to search for, insert, and remove elements from the list, and finally to clear the list.
          /// @include LinkedList.cpp
          void Add(const T& value) override {
            this->list.push_back(value);
          }

          /// @brief Adds copy of elements from the specified collection to the end of the LinkedList<T>.
          /// @param collection The collection whose elements should be added to the end of the LinkedList<T>. The value can not be null and can contains reference element null.
          /// @exception ArgumentNullException The parameters collection is null or element reference null in collection.
          /// @remarks The order of the elements in the collection is preserved in the LinkedList<T>.
          /// @remarks If the new Count (the current Count plus the size of the collection) will be greater than Capacity, the capacity of the LinkedList<T> is increased by automatically reallocating the internal array to accommodate the new elements, and the existing elements are copied to the new array before the new elements are added.
          /// @remarks If the LinkedList<T> can accommodate the new elements without increasing the Capacity, this method is an O(n) operation, where n is the number of elements to be added. If the capacity needs to be increased to accommodate the new elements, this method becomes an O(n + m) operation, where n is the number of elements to be added and m is Count.
          /// @par Examples
          /// The following code example demonstrates the LinkedList<T> constructor and various methods of the LinkedList<T> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The Capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
          /// @include List2.cpp
          void AddRange(const IEnumerable<T>& enumerable) {
            for (T value : enumerable)
              this->list.push_back(value);
          }

          /// @brief Adds copy of elements from the specified collection to the end of the LinkedList<T>.
          /// @param collection The collection whose elements should be added to the end of the LinkedList<T>. The value can not be null and can contains reference element null.
          /// @exception ArgumentNullException The parameters collection is null or element reference null in collection.
          /// @remarks The order of the elements in the collection is preserved in the LinkedList<T>.
          /// @remarks If the new Count (the current Count plus the size of the collection) will be greater than Capacity, the capacity of the LinkedList<T> is increased by automatically reallocating the internal array to accommodate the new elements, and the existing elements are copied to the new array before the new elements are added.
          /// @remarks If the LinkedList<T> can accommodate the new elements without increasing the Capacity, this method is an O(n) operation, where n is the number of elements to be added. If the capacity needs to be increased to accommodate the new elements, this method becomes an O(n + m) operation, where n is the number of elements to be added and m is Count.
          /// @par Examples
          /// The following code example demonstrates the LinkedList<T> constructor and various methods of the LinkedList<T> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The Capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
          /// @include List2.cpp
          void AddRange(InitializerList<T> il) {
            for (T item : il)
              this->Add(item);
          }

          /// @brief Removes all elements from the LinkedList<T>.
          /// @remarks Count is set to 0, and references to other objects from elements of the collection are also released.
          /// @remarks Capacity remains unchanged. To reset the capacity of the LinkedList<T>, call the TrimExcess method or set the Capacity property directly. Decreasing the capacity reallocates memory and copies all the elements in the LinkedList<T>. Trimming an empty LinkedList<T> sets the capacity of the LinkedList<T> to the default capacity.
          /// @remarks This method is an O(n) operation, where n is Count.
          /// @remarks The following code example demonstrates several properties and methods of the LinkedList<T> generic class, including the Add method. The default constructor is used to create a list of strings with a capacity of 0. The Capacity property is displayed, and then the Add method is used to add several items. The items are listed, and the Capacity property is displayed again, along with the Count property, to show that the capacity has been increased as needed.
          /// @par Examples
          /// Other properties and methods are used to search for, insert, and remove elements from the list, and finally to clear the list.
          /// @include LinkedList.cpp
          void Clear() override {
            this->list.clear();
          }

          /// @brief Determines whether an element is in the LinkedList<T>.
          /// @param value The object to locate in the LinkedList<T>. The value can be null for reference types.
          /// @return true if item is found in the LinkedList<T>; otherwise, false.
          /// @remarks This method determines equality by using the default equality comparer, as defined by the object's implementation of the IEquatable<T>.Equals method for T (the type of values in the list).
          /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is Count.
          bool Contains(const T& value) const override {
            for (T elem : *this)
              if (elem == value)
                return true;

            return false;
          }

          /// @brief Copies the entire LinkedList<T> to a compatible one-dimensional array.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @exception ArgumentNullException array is null.
          /// @exception ArgumentException The number of elements in the source LinkedList<T> is greater than the number of elements that the destination array can contain.
          /// @remarks TThis method uses Array.Copy to copy the elements.
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the LinkedList<T>.
          /// @remarks This method is an O(n) operation, where n is Count.
          /// @par Examples
          /// The following code example demonstrates all three overloads of the CopyTo method. A LinkedList<T> of strings is created and populated with 5 strings. An empty string array of 15 elements is created, and the CopyTo(T[]) method overload is used to copy all the elements of the list to the array beginning at the first element of the array. The CopyTo(T[], Int32) method overload is used to copy all the elements of the list to the array beginning at array index 6 (leaving index 5 empty). Finally, the CopyTo(Int32, T[], Int32, Int32) method overload is used to copy 3 elements from the list, beginning with index 2, to the array beginning at array index 12 (leaving index 11 empty). The contents of the array are then displayed.
          /// @include LinkedList.CopyTo.cpp
          void CopyTo(Array<T>& array) const {
            this->CopyTo(0, array, 0, this->Count);
          }

          /// @brief Copies the entire LinkedList<T> to a compatible one-dimensional array, starting at the specified index of the target array.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @param arrayIndex The zero-based index in array at which copying begins;
          /// @exception ArgumentNullException array is null.
          /// @exception ArgumentOutOfRangeException The arrayIndex is less than 0.
          /// @exception ArgumentException The number of elements in the source LinkedList<T> is greater than the number of elements that the destination array can contain.
          /// @remarks TThis method uses Array.Copy to copy the elements.
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the LinkedList<T>.
          /// @remarks This method is an O(n) operation, where n is Count.
          /// @par Examples
          /// The following code example demonstrates all three overloads of the CopyTo method. A LinkedList<T> of strings is created and populated with 5 strings. An empty string array of 15 elements is created, and the CopyTo(T[]) method overload is used to copy all the elements of the list to the array beginning at the first element of the array. The CopyTo(T[], Int32) method overload is used to copy all the elements of the list to the array beginning at array index 6 (leaving index 5 empty). Finally, the CopyTo(Int32, T[], Int32, Int32) method overload is used to copy 3 elements from the list, beginning with index 2, to the array beginning at array index 12 (leaving index 11 empty). The contents of the array are then displayed.
          /// @include LinkedList.CopyTo.cpp
          void CopyTo(Array<T>& array, int32 arrayIndex) const override {
            this->CopyTo(0, array, arrayIndex, this->Count);
          }

          /// @brief Copies the entire LinkedList<T> to a compatible one-dimensional array, starting at the specified index of the target array.
          /// @param index The zero-based index in the source LinkedList<T> at which copying begins.
          /// @param array The one-dimensional Array that is the destination of the elements copied from ICollection. The Array must have zero-based indexing.
          /// @param arrayIndex The zero-based index in array at which copying begins;
          /// @param count The number of elements to copy.
          /// @exception ArgumentNullException array is null.
          /// @exception ArgumentOutOfRangeException The arrayIndex or count is less than 0.
          /// @exception ArgumentException The number of elements in the source LinkedList<T> is greater than the number of elements that the destination array can contain.
          /// @remarks TThis method uses Array.Copy to copy the elements.
          /// @remarks The elements are copied to the Array in the same order in which the enumerator iterates through the LinkedList<T>.
          /// @remarks This method is an O(n) operation, where n is Count.
          /// @par Examples
          /// The following code example demonstrates all three overloads of the CopyTo method. A LinkedList<T> of strings is created and populated with 5 strings. An empty string array of 15 elements is created, and the CopyTo(T[]) method overload is used to copy all the elements of the list to the array beginning at the first element of the array. The CopyTo(T[], Int32) method overload is used to copy all the elements of the list to the array beginning at array index 6 (leaving index 5 empty). Finally, the CopyTo(Int32, T[], Int32, Int32) method overload is used to copy 3 elements from the list, beginning with index 2, to the array beginning at array index 12 (leaving index 11 empty). The contents of the array are then displayed.
          /// @include LinkedList.CopyTo.cpp
          void CopyTo(int32 index, Array<T>& array, int32 arrayIndex, int32 count) const {

            if (index < 0 || array.Length < 0 || arrayIndex < 0 || count < 0)
              throw System::ArgumentOutOfRangeException(caller_);

            if (index + count > this->Count || arrayIndex + count > array.Length)
              throw System::ArgumentException(caller_);

            int32 i = 0, c = 0;
            for (T item : *this) {
              if (i >= index + count)
                return;
              if (i >= index) {
                array[arrayIndex + c] = item;
                c += 1;
              }
              i += 1;
            }
          }

          /// @brief Determines whether the LinkedList<T> contains elements that match the conditions defined by the specified predicate.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return Boolean true if the LinkedList<T> contains one or more elements that match the conditions defined by the specified predicate; otherwise, false.
          /// @exception ArgumentNUllException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current LinkedList<T> are individually passed to the Predicate pointer function, and processing is stopped when a match is found.
          /// @remarks This method is an O(n) operation, where n is Count.
          /// @remarks The following code example demonstrates the RemoveAll method and several other methods that use the Predicate<T> generic delegate.
          /// @remarks A LinkedList<T> of strings is created, containing 8 dinosaur names, two of which (at positions 1 and 5) end with "saurus". The code example also defines a search predicate method named EndsWithSaurus, which accepts a string parameter and returns a Boolean value indicating whether the input string ends in "saurus".
          /// @remarks The Find, FindLast, and FindAll methods are used to search the list with the search predicate method.
          /// @par Examples
          /// The RemoveAll method is used to remove all entries ending with "saurus". It traverses the list from the beginning, passing each element in turn to the EndsWithSaurus method. The element is removed if the EndsWithSaurus method returns true.
          /// @include LinkedList.Exists.cpp
          bool Exists(const Predicate<const T&>& match) const {
            for (T elem : *this)
              if (match(elem))
                return true;

            return false;
          }

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the first occurrence within the entire LinkedList<T>.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return The first element that matches the conditions defined by the specified predicate, if found; otherwise, the default value for type T.
          /// @exception ArgumentNUllException match is null.
          /// @remarks The Predicate<T> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current LinkedList<T> are individually passed to the Predicate<T> delegate, moving forward in the LinkedList<T>, starting with the first element and ending with the last element. Processing is stopped when a match is found.
          /// @note When searching a list containing value types, make sure the default value for the type does not satisfy the search predicate. Otherwise, there is no way to distinguish between a default value indicating that no match was found and a list element that happens to have the default value for the type. If the default value satisfies the search predicate, use the FindIndex method instead.
          /// @note This method performs a linear search; therefore, this method is an O(n) operation, where n is Count.
          /// @note The following example demonstrates the find methods for the LinkedList<T> class. The example for the LinkedList<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
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
          /// @include LinkedList.Find.cpp
          const T Find(const Predicate<const T&>& match) {
            for (T elem : *this)
              if (match(elem))
                return elem;

            return T();
          }

          /// @brief Retrieves all the elements that match the conditions defined by the specified predicate.
          /// @param match The Predicate<T> delegate that defines the conditions of the elements to search for.
          /// @return A LinkedList<T> containing all the elements that match the conditions defined by the specified predicate, if found; otherwise, an empty LinkedList<T>.
          /// @exception ArgumentNUllException match is null.
          /// @remarks The Predicate<T> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current LinkedList<T> are individually passed to the Predicate<T> delegate, and the elements that match the conditions are saved in the returned LinkedList<T>.
          /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is Count.
          /// @remarks The following example demonstrates the find methods for the LinkedList<T> class. The example for the LinkedList<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
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
          /// @include LinkedList.Find.cpp
          LinkedList FindAll(const Predicate<const T&>& match) {
            LinkedList list;
            for (T elem : *this)
              if (match(elem))
                list.Add(elem);

            return list;
          }

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of first occurrence within the entire LinkedList<T>.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return Int32 The first zero-based index of the first occurrence of an element that matches the conditions defined by match, if found; otherwise, -1.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current LinkedList<T> are individually passed to the Predicate pointer function, moving forward in the LinkedList<T>, starting with the first element and ending with the last element. Processing is stopped when a match is found.
          /// @remarks The following example demonstrates the find methods for the LinkedList<T> class. The example for the LinkedList<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
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
          /// @include LinkedList.Find.cpp
          int32 FindIndex(const Predicate<const T&>& match) {
            return this->FindIndex(0, this->Count, match);
          }

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of first occurrence within the entire LinkedList<T>.
          /// @param sratIndex The zero-based starting index of the search.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return Int32 The first zero-based index of the first occurrence of an element that matches the conditions defined by match, if found; otherwise, -1.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current LinkedList<T> are individually passed to the Predicate pointer function, moving forward in the LinkedList<T>, starting with the first element and ending with the last element. Processing is stopped when a match is found.
          /// @remarks The following example demonstrates the find methods for the LinkedList<T> class. The example for the LinkedList<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
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
          /// @include LinkedList.Find.cpp
          int32 FindIndex(int32 startIndex, const Predicate<const T&>& match) {
            return this->FindIndex(startIndex, this->Count - startIndex, match);
          }

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of first occurrence within the entire LinkedList<T>.
          /// @param startIndex The zero-based starting index of the search.
          /// @param count The number of elements in the section to search.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return Int32 The first zero-based index of the first occurrence of an element that matches the conditions defined by match, if found; otherwise, -1.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current LinkedList<T> are individually passed to the Predicate pointer function, moving forward in the LinkedList<T>, starting with the first element and ending with the last element. Processing is stopped when a match is found.
          /// @remarks The following example demonstrates the find methods for the LinkedList<T> class. The example for the LinkedList<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
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
          /// @include LinkedList.Find.cpp
          int32 FindIndex(int32 startIndex, int32 count, const Predicate<const T&>& match) {
            if (startIndex < 0 || count < 0)
              throw ArgumentOutOfRangeException(caller_);

            if (startIndex + count > this->Count)
              throw ArgumentException(caller_);

            Enumerator enumerator(*this);
            for (int32 i = 0; i < startIndex; i += 1)
              enumerator.MoveNext();

            for (int32 i = 0; i < count; i += 1) {
              enumerator.MoveNext();
              if (match(enumerator.Current))
                return startIndex + i;
            }

            return -1;
          }

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the last occurrence within the entire LinkedList<T>.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return T The last element that matches the conditions defined by the specified predicate, if found; otherwise, the default value for type T.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current LinkedList<T> are individually passed to the Predicate pointer function, moving forward in the LinkedList<T>, starting with the first element and ending with the last element.
          /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is Count.
          /// @remarks The following example demonstrates the find methods for the LinkedList<T> class. The example for the LinkedList<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
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
          /// @include LinkedList.Find.cpp
          const T FindLast(const Predicate<const T&>& match) {
            Generic::Enumerator<T> reverseEnumerator(new ReverseEnumerator(*this));
            while (reverseEnumerator.MoveNext())
              if (match(reverseEnumerator.Current))
                return reverseEnumerator.Current;
            return T();
          }

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of last occurrence within the entire LinkedList<T>.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return Int32 The first zero-based index of the last occurrence of an element that matches the conditions defined by match, if found; otherwise, -1.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current LinkedList<T> are individually passed to the Predicate pointer function, moving forward in the LinkedList<T>, starting with the first element and ending with the last element. Processing is stopped when a match is found.
          /// @remarks The following example demonstrates the find methods for the LinkedList<T> class. The example for the LinkedList<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
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
          /// @include LinkedList.Find.cpp
          int32 FindLastIndex(const Predicate<const T&>& match) {
            return this->FindLastIndex(this->Count - 1, this->Count, match);
          }

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of the last occurrence within the range of elements in the LinkedList<T> that extends from the first element to the specified index.
          /// @param startIndex The zero-based starting index of the search.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return Int32 The first zero-based index of the last occurrence of an element that matches the conditions defined by match, if found; otherwise, -1.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current LinkedList<T> are individually passed to the Predicate pointer function, moving forward in the LinkedList<T>, starting with the first element and ending with the last element. Processing is stopped when a match is found.
          /// @remarks The following example demonstrates the find methods for the LinkedList<T> class. The example for the LinkedList<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
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
          /// @include LinkedList.Find.cpp
          int32 FindLastIndex(int32 startIndex, const Predicate<const T&>& match) {
            return this->FindLastIndex(startIndex, startIndex + 1, match);
          }

          /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of the last occurrence within the range of elements in the LinkedList<T> that contains the specified number of elements and ends at the specified index.
          /// @param startIndex The zero-based starting index of the search.
          /// @param count The number of elements in the section to search.
          /// @param match The Predicate pointer function that defines the conditions of the elements to search for.
          /// @return Int32 The first zero-based index of the last occurrence of an element that matches the conditions defined by match, if found; otherwise, -1.
          /// @exception ArgumentNullException The parameters match is null.
          /// @remarks The Predicate is a pointer to a method that returns true if the object passed to it matches the conditions defined in the pointer function. The elements of the current LinkedList<T> are individually passed to the Predicate pointer function, moving forward in the LinkedList<T>, starting with the first element and ending with the last element. Processing is stopped when a match is found.
          /// @remarks The following example demonstrates the find methods for the LinkedList<T> class. The example for the LinkedList<T> class contains book objects, of class Book, using the data from the Sample XML File: Books (LINQ to XML). The FillList method in the example uses LINQ to XML [from BPUEDev11] to parse the values from the XML to property values of the book objects.
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
          /// @include LinkedList.Find.cpp
          int32 FindLastIndex(int32 startIndex, int32 count, const Predicate<const T&>& match) {
            if (startIndex < 0 || count < 0 || startIndex >= this->Count)
              throw ArgumentOutOfRangeException(caller_);

            if (startIndex - count < -1)
              throw ArgumentException(caller_);

            ReverseEnumerator enumerator(*this);
            for (int32 i = this->Count - 1; i > startIndex; i -= 1)
              enumerator.MoveNext();

            for (int32 i = 0; i < count; i += 1) {
              enumerator.MoveNext();
              if (match(enumerator.Current))
                return startIndex - i;
            }

            return -1;
          }

          /// @brief Performs the specified action on each element of the LinkedList<T>.
          /// @param action The action pointer function to perform on each element of the LinkedList<T>.
          /// @return None.
          /// @exception ArgumentNullException The parameters action is null.
          /// @remarks The action is a pointer to a method that performs an action on the object passed to it. The elements of the current LinkedList<T> are individually passed to the pointer function.
          /// @remarks This method is an O(n) operation, where n is Count.
          void ForEach(const Action<const T&>& action) {
            for (T elem : *this)
              action(elem);
          }

          /// @brief Returns an enumerator that iterates through the LinkedList<T>.
          /// @return A LinkedList<T>::Enumerator for the LinkedList<T>.
          System::Collections::Generic::Enumerator<T> GetEnumerator() const override {
            return System::Collections::Generic::Enumerator<T>(new LinkedList::Enumerator(*const_cast<LinkedList*>(this)));
          }

          /// @brief Creates a shallow copy of a range of elements in the source LinkedList<T>.
          /// @param index The zero-based LinkedList<T> index at which the range starts.
          /// @param count The number of elements in the range.
          /// @return A shallow copy of a range of elements in the source LinkedList<T>.
          /// @exception ArgumentOutOfRangeException index is less than 0. -or- count is less than 0.
          /// @exception ArgumentException index and count do not denote a valid range of elements in the LinkedList<T>.
          /// @remarks A shallow copy of a collection of reference types, or a subset of that collection, contains only the references to the elements of the collection. The objects themselves are not copied. The references in the new list point to the same objects as the references in the original list.
          /// @remarks A shallow copy of a collection of value types, or a subset of that collection, contains the elements of the collection. However, if the elements of the collection contain references to other objects, those objects are not copied. The references in the elements of the new collection point to the same objects as the references in the elements of the original collection.
          /// @remarks In contrast, a deep copy of a collection copies the elements and everything directly or indirectly referenced by the elements.
          /// @remarks This method is an O(n) operation, where n is count.
          /// @par Examples
          /// The following code example demonstrates the GetRange method and other methods of the LinkedList<T> class that act on ranges. At the end of the code example, the GetRange method is used to get three items from the list, beginning with index location 2. The ToArray method is called on the resulting LinkedList<T>, creating an array of three elements. The elements of the array are displayed.
          /// @include List2.cpp
          LinkedList GetRange(int32 index, int32 count) {

            if (index < 0 || count < 0)
              throw ArgumentOutOfRangeException(caller_);

            if (index + count > this->Count)
              throw ArgumentException(caller_);

            LinkedList list;

            typename std::list<T, TAllocator>::iterator position = this->list.begin();
            std::advance(position, index);
            for (int32 i = 0; i < count; i++) {
              list.Add(*position);
              position++;
            }

            return list;
          }

          /// @brief Determines the index of a specific item in the LinkedList.
          /// @param value The object to locate in the LinkedList.
          /// @return int32 The index of value if found in the list; otherwise, -1.
          virtual int32 IndexOf(const T& value) const {
            if (this->Count == 0)
              return -1;
            return this->IndexOf(value, 0, this->Count);
          }

          /// @brief Determines the index of a specific item in the LinkedList.
          /// @param value The object to locate in the LinkedList.
          /// @param index The zero-based starting index of the search.
          /// @return Int32 The index of value if found in the list; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0.
          virtual int32 IndexOf(const T& value, int32 index) const {
            return this->IndexOf(value, index, this->Count - index);
          }

          /// @brief Determines the index of a specific item in the LinkedList.
          /// @param value The object to locate in the LinkedList.
          /// @param index The zero-based starting index of the search.
          /// @param count The number of elements in the section to search
          /// @return The index of value if found in the list; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0 or The parameters count is
          /// less than 0 or index and count do not specify a valid section in the LinkedList<T>.
          virtual int32 IndexOf(const T& value, int32 index, int32 count) const {
            if (index < 0 || count < 0 || index >= this->Count || index + count > this->Count)
              throw ArgumentOutOfRangeException(caller_);

            Enumerator enumerator(*const_cast<LinkedList*>(this));
            for (int32 i = 0; i < index ; i += 1)
              enumerator.MoveNext();

            for (int32 i = 0; i < count; i++) {
              enumerator.MoveNext();
              if (enumerator.Current() == value)
                return index + i;
            }

            return -1;
          }

          /// @brief Inserts an element into the LinkedList<T> at the specified index.
          /// @param index The zero-based index at which the new element should be inserted.
          /// @param value The element should be inserted into the LinkedList<T>. The value can not be null.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is greater than Count.
          /// @remarks LinkedList<T> allows duplicate elements.
          virtual void Insert(int32 index, const T& value) {
            if (index < 0 || index > this->Count())
              throw ArgumentOutOfRangeException(caller_);

            this->operationNumber++;
            typename std::list<T, TAllocator>::iterator position = this->list.begin();
            std::advance(position, index);
            this->list.insert(position, value);
          }

          /// @brief Inserts copy of elements from a collection into the LinkedList<T> at the specified index.
          /// @param index The zero-based index at which the new elements should be inserted.
          /// @param collection The collection whose elements should be inserted into the LinkedList<T>. The value can not be null and cannot contains reference element null.
          /// @exception ArgumentNullException The parameters collection is null or element reference null in collection.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is greater than Count.
          /// @remarks LinkedList<T> allows duplicate elements.
          /// @remarks The order of the elements in the collection is preserved in the LinkedList<T>.
          void InsertRange(int32 index, const IEnumerable<T>& enumerable) {
            if (index < 0)
              throw ArgumentOutOfRangeException(caller_);

            this->operationNumber++;
            int32 i = index;
            for (T value : enumerable) {
              typename std::list<T, TAllocator>::iterator position = this->list.begin();
              std::advance(position, i++);
              this->list.insert(position, value);
            }
          }

          /// @brief Determines the last index of a specific item in the LinkedList.
          /// @param value The object to locate in the LinkedList.
          /// @return Int32 The last index of value if found in the list; otherwise, -1.
          int32 LastIndexOf(const T& value) const {
            if (this->Count == 0)
              return -1;
            return this->LastIndexOf(value, this->Count - 1, this->Count);
          }

          /// @brief Determines the last index of a specific item in the LinkedList.
          /// @param value The object to locate in the LinkedList.
          /// @param index The zero-based starting index of the search.
          /// @return Int32 The last index of value if found in the list; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0.
          int32 LastIndexOf(const T& value, int32 index) const {
            return this->LastIndexOf(value, index, index + 1);
          }

          /// @brief Determines the last index of a specific item in the LinkedList.
          /// @param value The object to locate in the LinkedList.
          /// @param index The zero-based starting index of the search.
          /// @param count The number of elements in the section to search
          /// @return Int32 The last index of value if found in the list; otherwise, -1.
          /// @exception ArgumentOutOfRangeException The parameters index is less than 0 or The parameters count is less than 0 or index and count do not specify a valid section in the LinkedList<T>.
          int32 LastIndexOf(const T& value, int32 index, int32 count) const {
            if (index < 0 || count < 0 || index >= this->Count)
              throw ArgumentOutOfRangeException(caller_);

            if (index - count < -1)
              throw System::ArgumentException(caller_);

            ReverseEnumerator enumerator(*this);
            for (int32 i = this->Count - 1; i > index; i -= 1)
              enumerator.MoveNext();

            for (int32 i = 0; i < count; i += 1) {
              enumerator.MoveNext();
              if (value == enumerator.Current)
                return index - i;
            }

            return -1;
          }

          /// @brief Removes the first occurrence of a specific object from the LinkedList<T>.
          /// @param item The object to remove from the LinkedList<(Of <(T>)>). The value can not be null.
          /// @return Boolean true if item is successfully removed; otherwise, false. This method also returns false if item was not found in the LinkedList<T>.
          bool Remove(const T& item) override {
            if (this->Count == 0)
              return false;

            int32 index = this->IndexOf(item);
            if (index != -1) {
              this->RemoveAt(index);
              return true;
            }

            return false;
          }

          /// @brief Removes all the elements that match the conditions defined by the specified predicate.
          /// @param match The Predicate<T> delegate that defines the conditions of the elements to remove.
          /// @return The number of elements removed from the LinkedList<T> .
          /// @exception ArgumentNullException match is null
          /// @remarks The Predicate<T> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current LinkedList<T> are individually passed to the Predicate<T> delegate, and the elements that match the conditions are removed from the LinkedList<T>.
          /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is Count.
          /// @remarks The following code example demonstrates the RemoveAll method and several other methods that use the Predicate<T> generic delegate.
          /// @remarks A LinkedList<T> of strings is created, containing 8 dinosaur names, two of which (at positions 1 and 5) end with "saurus". The code example also defines a search predicate method named EndsWithSaurus, which accepts a string parameter and returns a Boolean value indicating whether the input string ends in "saurus".
          /// @remarks The Find, FindLast, and FindAll methods are used to search the list with the search predicate method.
          /// @par Examples
          /// The RemoveAll method is used to remove all entries ending with "saurus". It traverses the list from the beginning, passing each element in turn to the EndsWithSaurus method. The element is removed if the EndsWithSaurus method returns true.
          /// @include LinkedList.Exists.cpp
          int32 RemoveAll(const Predicate<const T&>& match) {
            int32 count = 0;
            typename std::list<T, TAllocator>::iterator it = this->list.begin();
            while (it != this->list.end()) {
              if (match(*it)) {
                it = this->list.erase(it);
                count += 1;
              } else
                it++;
            }

            if (count) this->operationNumber++;
            return count;
          }

          /// @brief Removes the element at the specified index of the LinkedList<T>.
          /// @param index The zero-based index of the item to remove
          /// @return None.
          /// @exception ArgumentOutOfRangeException index is less than 0 or index is greater than Count.
          virtual void RemoveAt(int32 index) {
            if (index < 0 || index >= this->Count)
              throw ArgumentOutOfRangeException(caller_);

            this->operationNumber++;
            typename std::list<T, TAllocator>::iterator position = this->list.begin();
            std::advance(position, index);
            this->list.erase(position);
          }

          /// @brief Removes a range of elements from the LinkedList<T>.
          /// @param index The zero-based index of the item to remove
          /// @param count The number of elements to remove
          /// @return None.
          /// @exception ArgumentOutOfRangeException index or count is less than 0 or index + count is greater than Count.
          /// @remarks The items are removed and all the elements following them in the LinkedList<T> have their indexes reduced by count.
          void RemoveRange(int32 index, int32 count) {
            if (index < 0 || index + count > this->Count)
              throw ArgumentOutOfRangeException(caller_);

            this->operationNumber++;
            typename std::list<T, TAllocator>::iterator begin = this->list.begin();
            typename std::list<T, TAllocator>::iterator end = this->list.begin();
            std::advance(begin, index);
            std::advance(end, index + count);
            this->list.erase(begin, end);
          }

          /// @brief Reverses the order of the elements in the entire LinkedList<T>.
          /// @remarks This method uses Array.Reverse to reverse the order of the elements, such that the element at LinkedList<T>[i], where i is any index within the range, moves to LinkedList<T>[j], where j equals index plus index plus count minus i minus 1.
          /// @remarks This method is an O(n) operation, where n is Count.
          /// @par Examples
          /// The following code example demonstrates both overloads of the Reverse method. The code example creates a LinkedList<T> of strings and adds six strings. The Reverse() method overload is used to reverse the list, and then the Reverse(Int32, Int32) method overload is used to reverse the middle of the list, beginning with element 1 and encompassing four elements.
          /// @include LinkedList.Reverse.cpp
          void Reverse() {
            this->operationNumber++;
            this->list.reverse();
          }

          /// @brief Reverses the order of the elements in the specified range.
          /// @param index The zero-based starting index of the range to reverse.
          /// @param count The number of elements in the range to reverse.
          /// @exception ArgumentOutOfRangeException index is less than 0. -or- count is less than 0.
          /// @exception ArgumentException ndex and count do not denote a valid range of elements in the LinkedList<T>.
          /// @remarks This method uses Array.Reverse to reverse the order of the elements, such that the element at LinkedList<T>[i], where i is any index within the range, moves to LinkedList<T>[j], where j equals index plus index plus count minus i minus 1.
          /// @remarks This method is an O(n) operation, where n is Count.
          /// @par Examples
          /// The following code example demonstrates both overloads of the Reverse method. The code example creates a LinkedList<T> of strings and adds six strings. The Reverse() method overload is used to reverse the list, and then the Reverse(int32, int32) method overload is used to reverse the middle of the list, beginning with element 1 and encompassing four elements.
          /// @include LinkedList.Reverse.cpp
          void Reverse(int32 index, int32 count) {
            if (index < 0 || count < 0)
              throw ArgumentOutOfRangeException(caller_);

            if (index + count > this->Count)
              throw ArgumentException(caller_);

            int pos1 = index, pos2 = (index + count) - 1;
            typename std::list<T, TAllocator>::iterator it1 = this->list.begin(), it2 = this->list.begin();

            std::advance(it1, pos1);
            std::advance(it2, pos2);

            while (pos1++ < pos2--)
              std::iter_swap(it1++, it2--);
          }

          /// @brief Copies the elements of the LinkedList<T> to a new array.
          /// @return An array containing copies of the elements of the LinkedList<T>.
          /// @remarks The elements are copied using Array.Copy, which is an O(n) operation, where n is Count.
          /// @remarks This method is an O(n) operation, where n is Count.
          /// @par Examples
          /// The following code example demonstrates the ToArray method and other methods of the LinkedList<T> class that act on ranges. At the end of the code example, the GetRange method is used to get three items from the list, beginning with index location 2. The ToArray method is called on the resulting LinkedList<T>, creating an array of three elements. The elements of the array are displayed.
          /// @include List2.cpp
          Array<T> ToArray() const {
            Array<T> array(this->Count);
            this->CopyTo(array);
            return array;
          }

          /// @brief Clear the list and insert the element of the list given in argument.
          /// @param list the LinkedList<T> which elements will be inserted from
          /// @return LinkedList<T> the list
          /// @exception ArgumentNullException list argument is null
          LinkedList& operator =(const LinkedList& list) {
            this->operationNumber++;
            this->list = list.list;
            return *this;
          }

          class Enumerator : public object, public IEnumerator<T> {
          public:
            Enumerator(LinkedList& list) : list(list) {Reset();}
            Enumerator(const Enumerator& e) : operationNumber(e.operationNumber), beforeFirst(e.beforeFirst), list(e.list), iterator(e.iterator) {}

            void Reset() {
              this->beforeFirst = true;
              this->operationNumber = this->list.operationNumber;
              this->iterator = this->list.list.begin();
            }

            virtual bool MoveNext() {
              if (this->operationNumber != this->list.operationNumber)
                throw InvalidOperationException(caller_);

              if (IsFinished())
                return false;

              if (this->beforeFirst)
                this->beforeFirst = false;
              else
                this->iterator++;

              return !IsFinished();
            }

          private:
            const T& GetCurrent() const {
              if (this->beforeFirst || IsFinished())
                throw InvalidOperationException(caller_);

              return *this->iterator;
            }

            bool IsFinished() const {return this->iterator == this->list.list.end();}
            int64 operationNumber;
            bool beforeFirst;
            LinkedList& list;
            typename std::list<T, TAllocator>::iterator iterator;
          };

          class ReverseEnumerator : public object, public IEnumerator<T> {
          public:
            ReverseEnumerator(LinkedList& list) : list(list) {Reset();}
            ReverseEnumerator(const ReverseEnumerator& e) : operationNumber(e.operationNumber), beforeFirst(e.beforeFirst), list(e.list), iterator(e.iterator) {}

            void Reset() {
              this->beforeFirst = true;
              this->operationNumber = this->list.operationNumber;
              this->iterator = this->list.list.rbegin();
            }

            virtual bool MoveNext() {
              if (this->operationNumber != this->list.operationNumber)
                throw InvalidOperationException(caller_);

              if (IsFinished())
                return false;

              if (this->beforeFirst)
                this->beforeFirst = false;
              else
                this->iterator++;

              return !IsFinished();
            }

          private:
            const T& GetCurrent() const {
              if (this->beforeFirst || IsFinished())
                throw InvalidOperationException(caller_);

              return *this->iterator;
            }

            bool IsFinished() const {return this->iterator == this->list.list.rend();}
            int64 operationNumber;
            bool beforeFirst;
            LinkedList& list;
            typename std::list<T, TAllocator>::reverse_iterator iterator;
          };

          /// @cond
          using const_iterator = typename std::list<T, TAllocator>::const_iterator;
          using iterator = typename std::list<T, TAllocator>::iterator;

          const_iterator cbegin() const {return this->list.begin();}
          const_iterator cend() const {return this->list.end();}
          iterator begin() {return this->list.begin();}
          const_iterator begin() const {return this->list.begin();}
          iterator end() {return this->list.end();}
          const_iterator end() const {return this->list.end();}
          /// @endcond

        protected:
          /// @cond
          std::list<T, TAllocator> list;
          int64 operationNumber;
          object syncRoot;

        private:
          int32 GetCount() const override {return static_cast<int32>(this->list.size());}
          bool GetIsReadOnly() const override {return false;}
          bool GetIsSynchronized() const override { return false; }
          const object& GetSyncRoot() const override {return this->syncRoot;}

          class ListComparer : public std::binary_function<T, T, bool> {
          private:
            const IComparer<T>* comparer;

          public:
            ListComparer(const IComparer<T>* c) : comparer(c) { }
            ListComparer(const ListComparer& mc) { *this = mc; }
            ~ListComparer() { }

            ListComparer& operator =(const ListComparer& mc) { comparer = mc.comparer; return *this; }
            bool operator()(const T& e1, const T& e2) const { return comparer->Compare(e1, e2) < 0; }
          };
          /// @endcond
        };
      }
    }
  }
}

using namespace Switch;

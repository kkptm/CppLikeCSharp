/// @file
/// @brief Contains Switch::System::Linq::Enumerable class.
#pragma once

#include <iostream>

#include "../../As.hpp"
#include "../../Static.hpp"
#include "../../Types.hpp"
#include "../Func.hpp"
#include "../Object.hpp"
#include "../_String.hpp"
#include "../Collections/Generic/IEnumerable.hpp"
#include "../Collections/Generic/List.hpp"
#include "../Func.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Linq namespace provides classes and interfaces that support queries that use Language-Integrated Query (LINQ).
    namespace Linq {
      template<typename T>
      using EnumerableCollection = System::Collections::Generic::List<T>;

      template<typename T>
      using IOrderedEnumerable = System::Collections::Generic::IEnumerable<T>;

      /// @brief Provides a set of static methods for querying objects that implement IEnumerable<T>.
      class core_export_ Enumerable static_ {
      public:
        /// @brief Applies an accumulator function over a sequence.
        /// @param source An IEnumerable<T> to aggregate over.
        /// @param func An accumulator function to be invoked on each element.
        /// @return The final accumulator value.
        /// @par Examples
        /// The following code example demonstrates how to reverse the order of words in a string by using Aggregate.
        /// @include EnumerableAgregate.cpp
        template<typename TSource>
        static TSource Agregate(const Collections::Generic::IEnumerable<TSource>& source, const System::Func<const TSource&, const TSource&, TSource>& func)  {
          int nb = 0;
          TSource agregated {};
          for (TSource item : source) {
            if (nb++ == 0)
              agregated = item;
            else
              agregated = func(agregated, item);
          }
          return agregated;
        }

        /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
        /// @param source An IEnumerable<T> to aggregate over.
        /// @param seed The initial accumulator value.
        /// @param func An accumulator function to be invoked on each element.
        /// @return The final accumulator value.
        /// @par Examples
        /// The following code example demonstrates how to use Aggregate to apply an accumulator function and use a seed value.
        /// @include EnumerableAgregate2.cpp
        template<typename TSource, typename TAccumulate>
        static TAccumulate Agregate(const Collections::Generic::IEnumerable<TSource>& source, const TAccumulate& seed, const System::Func<const TAccumulate&, const TSource&, TAccumulate>& func)  {
          TAccumulate agregated = seed;
          for (TSource item : source)
            agregated = func(agregated, item);
          return agregated;
        }

        /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
        /// @param source An IEnumerable<T> to aggregate over.
        /// @param seed The initial accumulator value.
        /// @param objFunc An accumulator obj to be invoked on each element.
        /// @param func An accumulator function to be invoked on each element.
        /// @param objResultSelector A obj to transform the final accumulator value into the result value.
        /// @param resultSelector A function to transform the final accumulator value into the result value.
        /// @return The transformed final accumulator value.
        /// @par Examples
        /// The following code example demonstrates how to use Aggregate to apply an accumulator function and use a seed value.
        /// @include EnumerableAgregate3.cpp
        template<typename TSource, typename TAccumulate, typename TResult>
        static TResult Agregate(const Collections::Generic::IEnumerable<TSource>& source, const TAccumulate& seed, const System::Func<const TAccumulate&, const TSource&, TAccumulate>& func, const System::Func<const TAccumulate&, TResult>& resultSelector) {
          TAccumulate agregated = seed;
          for (TSource item : source)
            agregated = func(agregated, item);
          return resultSelector(agregated);
        }

        /// @brief Determines whether all elements of a sequence satisfy a condition.
        /// @param source An IEnumerable<T> that contains the elements to apply the predicate to.
        /// @param func A function to test each element for a condition.
        /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
        /// @par Examples
        /// The following code example demonstrates how to use All<TSource> to determine whether all the elements in a sequence satisfy a condition. Variable allStartWithB is true if all the pet names start with "B" or if the pets array is empty.
        /// @include EnumerableAll.cpp
        template<typename TSource>
        static bool All(const Collections::Generic::IEnumerable<TSource>& source, const System::Func<const TSource&, bool>& func) {
          for (TSource item : source)
            if (func(item) == false)
              return false;
          return true;
        }

        /// @brief Determines whether a sequence contains any elements.
        /// @param source The IEnumerable<T> to check for emptiness.
        /// @return true if the source sequence contains any elements; otherwise, false.
        /// @par Examples
        /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
        /// @include EnumerableAny.cpp
        template<typename TSource>
        static bool Any(const Collections::Generic::IEnumerable<TSource>& source) {
          return source.GetEnumerator().MoveNext();
        }

        /// @brief Determines whether any element of a sequence satisfies a condition.
        /// @param source An IEnumerable<T> whose elements to apply the predicate to.
        /// @param predicate A function to test each element for a condition.
        /// @return true if any elements in the source sequence pass the test in the specified predicate; otherwise, false.
        /// @par Examples
        /// The following code example demonstrates how to use Any to determine whether any element in a sequence satisfies a condition.
        /// @include EnumerableAny2.cpp
        template<typename TSource>
        static bool Any(const Collections::Generic::IEnumerable<TSource>& source, const System::Func<const TSource&, bool>& predicate) {
          for (TSource item : source)
            if (predicate(item) == true)
              return true;
          return false;
        }

        /// @brief Returns the input typed as IEnumerable<T>.
        /// @param source The sequence to type as IEnumerable<T>.
        /// @return The input sequence typed as IEnumerable<T>.
        /// @remarks The AsEnumerable<TSource>(IEnumerable<TSource>) method has no effect other than to change the compile-time type of source from a type that implements IEnumerable<T> to IEnumerable<T> itself.
        /// @remarks AsEnumerable<TSource>(IEnumerable<TSource>) can be used to choose between query implementations when a sequence implements IEnumerable<T> but also has a different set of public query methods available. For example, given a generic class Table that implements IEnumerable<T> and has its own methods such as Where, Select, and SelectMany, a call to Where would invoke the public Where method of Table. A Table type that represents a database table could have a Wheremethod that takes the predicate argument as an expression tree and converts the tree to SQL for remote execution. If remote execution is not desired, for example because the predicate invokes a local method, the AsEnumerable<TSource> method can be used to hide the custom methods and instead make the standard query operators available.
        /// @par Examples
        /// The following code example demonstrates how to use AsEnumerable<TSource>(IEnumerable<TSource>) to hide a type's custom Where method when the standard query operator implementation is desired.
        /// @include EnumerableAsEnumerable.cpp
        template<typename TSource>
        static refptr<EnumerableCollection<TSource>> AsEnumerable(const Collections::Generic::IEnumerable<TSource>& source) {return ref_new<EnumerableCollection<TSource>>(source);}

        /// @brief Returns the input typed as IEnumerable<T>.
        /// @param source The sequence to type as IEnumerable<T>.
        /// @return The input sequence typed as IEnumerable<T>.
        /// @remarks The AsEnumerable<TSource>(IEnumerable<TSource>) method has no effect other than to change the compile-time type of source from a type that implements IEnumerable<T> to IEnumerable<T> itself.
        /// @remarks AsEnumerable<TSource>(IEnumerable<TSource>) can be used to choose between query implementations when a sequence implements IEnumerable<T> but also has a different set of public query methods available. For example, given a generic class Table that implements IEnumerable<T> and has its own methods such as Where, Select, and SelectMany, a call to Where would invoke the public Where method of Table. A Table type that represents a database table could have a Wheremethod that takes the predicate argument as an expression tree and converts the tree to SQL for remote execution. If remote execution is not desired, for example because the predicate invokes a local method, the AsEnumerable<TSource> method can be used to hide the custom methods and instead make the standard query operators available.
        /// @par Examples
        /// The following code example demonstrates how to use AsEnumerable<TSource>(IEnumerable<TSource>) to hide a type's custom Where method when the standard query operator implementation is desired.
        /// @include EnumerableAsEnumerable.cpp
        template<typename TSource>
        static refptr<EnumerableCollection<TSource>> AsEnumerable(const InitializerList<TSource>& source) {return ref_new<EnumerableCollection<TSource>>(source);}

        /// @brief Returns the input typed as IEnumerable<T>.
        /// @param source The sequence to type as IEnumerable<T>.
        /// @return The input sequence typed as IEnumerable<T>.
        /// @remarks The AsEnumerable<TSource>(IEnumerable<TSource>) method has no effect other than to change the compile-time type of source from a type that implements IEnumerable<T> to IEnumerable<T> itself.
        /// @remarks AsEnumerable<TSource>(IEnumerable<TSource>) can be used to choose between query implementations when a sequence implements IEnumerable<T> but also has a different set of public query methods available. For example, given a generic class Table that implements IEnumerable<T> and has its own methods such as Where, Select, and SelectMany, a call to Where would invoke the public Where method of Table. A Table type that represents a database table could have a Wheremethod that takes the predicate argument as an expression tree and converts the tree to SQL for remote execution. If remote execution is not desired, for example because the predicate invokes a local method, the AsEnumerable<TSource> method can be used to hide the custom methods and instead make the standard query operators available.
        /// @par Examples
        /// The following code example demonstrates how to use AsEnumerable<TSource>(IEnumerable<TSource>) with native c++ array.
        /// @include EnumerableAsEnumerable2.cpp
        template<typename TSource, int32 len>
        static refptr<EnumerableCollection<TSource>> AsEnumerable(const TSource(&source)[len]) {return ref_new<EnumerableCollection<TSource>>(source);}

        /// @brief Computes the average of a sequence of Double values.
        /// @param source A sequence of Double values to calculate the average of.
        /// @return The average of the sequence of values.
        /// @exception InvalidOperationException source contains no elements.
        /// @par Examples
        /// The following code example demonstrates how to use Average(IEnumerable<Int32>) to calculate an average.
        /// @include EnumerableAverageInt32.cpp
        static double Average(const Collections::Generic::IEnumerable<double>& source) {
          double average = 0;
          int32 count = 0;
          for (double item : source) {
            average += item;
            ++count;
          }
          if (count == 0)
            throw InvalidOperationException(caller_);
          return average / count;
        }

        /// @brief Computes the average of a sequence of Single values.
        /// @param source A sequence of Single values to calculate the average of.
        /// @return The average of the sequence of values.
        /// @exception InvalidOperationException source contains no elements.
        /// @par Examples
        /// The following code example demonstrates how to use Average(IEnumerable<Int32>) to calculate an average.
        /// @include EnumerableAverageInt32.cpp
        static double Average(const Collections::Generic::IEnumerable<float>& source) {
          double average = 0;
          int32 count = 0;
          for (float item : source) {
            average += item;
            ++count;
          }
          if (count == 0)
            throw InvalidOperationException(caller_);
          return average / count;
        }

        /// @brief Computes the average of a sequence of Int32 values.
        /// @param source A sequence of Int32 values to calculate the average of.
        /// @return The average of the sequence of values.
        /// @exception InvalidOperationException source contains no elements.
        /// @par Examples
        /// The following code example demonstrates how to use Average(IEnumerable<Int32>) to calculate an average.
        /// @include EnumerableAverageInt32.cpp
        static double Average(const Collections::Generic::IEnumerable<int32>& source) {
          double average = 0;
          int32 count = 0;
          for (int32 item : source) {
            average += item;
            ++count;
          }
          if (count == 0)
            throw InvalidOperationException(caller_);
          return average / count;
        }

        /// @brief Computes the average of a sequence of Int64 values.
        /// @param source A sequence of Int64 values to calculate the average of.
        /// @return The average of the sequence of values.
        /// @exception InvalidOperationException source contains no elements.
        /// @par Examples
        /// The following code example demonstrates how to use Average(IEnumerable<Int32>) to calculate an average.
        /// @include EnumerableAverageInt32.cpp
        static double Average(const Collections::Generic::IEnumerable<int64>& source) {
          double average = 0;
          int32 count = 0;
          for (int64 item : source) {
            average += item;
            ++count;
          }
          if (count == 0)
            throw InvalidOperationException(caller_);
          return average / count;
        }

        /// @brief Casts the elements of an IEnumerable to the specified type.
        /// @par Examples
        /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
        /// @include EnumerableCast.cpp
        template<typename TSource, typename TResult>
        static refptr<EnumerableCollection<TResult>> Cast(const Collections::Generic::IEnumerable<TSource>& source) {
          refptr<EnumerableCollection<TResult>> list = ref_new<EnumerableCollection<TResult>>();
          for (TSource item : source)
            list->Add(as<TResult>(item));
          return list;
        }

        /// @brief Concatenates two sequences.
        /// @param first The first sequence to concatenate.
        /// @param second The sequence to concatenate to the first sequence.
        /// @return refptr<Collections::Generic::IEnumerable<TSource>> An IEnumerable<T> that contains the concatenated elements of the two input sequences.
        /// @par Examples
        /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
        /// @include EnumerableConcat.cpp
        template<typename TSource>
        static refptr<EnumerableCollection<TSource>> Concat(const Collections::Generic::IEnumerable<TSource>& first, const Collections::Generic::IEnumerable<TSource>& second) {
          refptr<EnumerableCollection<TSource>> list = ref_new<EnumerableCollection<TSource>>();
          for (TSource item : first)
            list->Add(item);
          for (TSource item : second)
            list->Add(item);
          return list;
        }

        /// @brief Concatenates two sequences.
        /// @param first The first sequence to concatenate.
        /// @param second The sequence to concatenate to the first sequence.
        /// @return refptr<Collections::Generic::IEnumerable<TSource>> An IEnumerable<T> that contains the concatenated elements of the two input sequences.
        /// @par Examples
        /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
        /// @include EnumerableConcat.cpp
        template<typename TSource>
        static refptr<EnumerableCollection<TSource>> Concat(const Collections::Generic::IEnumerable<TSource>& first, const InitializerList<TSource>& second) {
          refptr<EnumerableCollection<TSource>> list = ref_new<EnumerableCollection<TSource>>();
          for (TSource item : first)
            list->Add(item);
          for (TSource item : second)
            list->Add(item);
          return list;
        }

        /// @brief Concatenates two sequences.
        /// @param first The first sequence to concatenate.
        /// @param second The sequence to concatenate to the first sequence.
        /// @return refptr<Collections::Generic::IEnumerable<TSource>> An IEnumerable<T> that contains the concatenated elements of the two input sequences.
        /// @par Examples
        /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
        /// @include EnumerableConcat.cpp
        template<typename TSource, int32 len>
        static refptr<EnumerableCollection<TSource>> Concat(const Collections::Generic::IEnumerable<TSource>& first, const TSource(&second)[len]) {
          refptr<EnumerableCollection<TSource>> list = ref_new<EnumerableCollection<TSource>>();
          for (TSource item : first)
            list->Add(item);
          for (TSource item : second)
            list->Add(item);
          return list;
        }

        /// @brief Concatenates two sequences.
        /// @param first The first sequence to concatenate.
        /// @param second The sequence to concatenate to the first sequence.
        /// @return refptr<Collections::Generic::IEnumerable<TSource>> An IEnumerable<T> that contains the concatenated elements of the two input sequences.
        /// @par Examples
        /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
        /// @include EnumerableIntersect.cpp
        template<typename TSource>
        static refptr<EnumerableCollection<TSource>> Intersect(const Collections::Generic::IEnumerable<TSource>& first, const Collections::Generic::IEnumerable<TSource>& second) {
          refptr<EnumerableCollection<TSource>> list = ref_new<EnumerableCollection<TSource>>();
          for (TSource item : first)
            if (second.Contains(item))
              list->Add(item);
          return list;
        }

        /// @brief Concatenates two sequences.
        /// @param first The first sequence to concatenate.
        /// @param second The sequence to concatenate to the first sequence.
        /// @return refptr<Collections::Generic::IEnumerable<TSource>> An IEnumerable<T> that contains the concatenated elements of the two input sequences.
        /// @par Examples
        /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
        /// @include EnumerableIntersect.cpp
        template<typename TSource>
        static refptr<EnumerableCollection<TSource>> Intersect(const InitializerList<TSource>& first, const Collections::Generic::IEnumerable<TSource>& second) {
          refptr<EnumerableCollection<TSource>> list = ref_new<EnumerableCollection<TSource>>();
          for (TSource item : first)
            if (second.Contains(item))
              list->Add(item);
          return list;
        }

        /// @brief Concatenates two sequences.
        /// @param first The first sequence to concatenate.
        /// @param second The sequence to concatenate to the first sequence.
        /// @return refptr<Collections::Generic::IEnumerable<TSource>> An IEnumerable<T> that contains the concatenated elements of the two input sequences.
        /// @par Examples
        /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
        /// @include EnumerableIntersect.cpp
        template<typename TSource, int32 len>
        static refptr<EnumerableCollection<TSource>> Intersect(const Collections::Generic::IEnumerable<TSource>& first, const TSource(&second)[len]) {
          refptr<EnumerableCollection<TSource>> list = ref_new<EnumerableCollection<TSource>>();
          Array<TSource> array(second);
          for (TSource item : first)
            if (array.Contains(item))
              list->Add(item);
          return list;
        }

        /// @brief Returns the maximum value in a generic sequence.
        /// @param source The IEnumerable that contains the elements to be cast to type TResult.
        /// @return An IEnumerable<T> that contains each element of the source sequence cast to the specified type.
        /// @par Examples
        /// The following code example demonstrates how to use Max<TSource>(IEnumerable<TSource>) to determine the maximum value in a sequence of IComparable<T> objects.
        /// @include EnumerableMax.cpp
        template<typename TSource>
        static const TSource& Max(const Collections::Generic::IEnumerable<TSource>& source) {
          const TSource* max = null;
          System::Collections::Generic::Enumerator<TSource> enumerator = source.GetEnumerator();
          while (enumerator.MoveNext())
            if (max == null || enumerator.Current() > *max)
              max = &enumerator.Current();
          return *max;
        }

        /// @brief Returns the minimum value in a generic sequence.
        /// @param source The IEnumerable that contains the elements to be cast to type TResult.
        /// @par Examples
        /// The following code example demonstrates how to use Min<TSource>(IEnumerable<TSource>) to determine the minimum value in a sequence of IComparable<T> objects.
        /// @include EnumerableMin.cpp
        template<typename TSource>
        static const TSource& Min(const Collections::Generic::IEnumerable<TSource>& source) {
          const TSource* min = null;
          System::Collections::Generic::Enumerator<TSource> enumerator = source.GetEnumerator();
          while (enumerator.MoveNext())
            if (min == null || enumerator.Current() < *min)
              min = &enumerator.Current();
          return *min;
        }

        /// @brief Sorts the elements of a sequence in ascending order according to a key.
        /// @param source A sequence of values to order.
        /// @param keySelector A function to extract a key from an element.
        /// @par Examples
        /// The following code example demonstrates how to use OrderBy<TSource, TKey>(IEnumerable<TSource>, Func<TSource, TKey>) to sort the elements of a sequence.
        /// @include EnumerableOrderBy.cpp
        template<typename TSource, typename TKey>
        static refptr<EnumerableCollection<TSource>> OrderBy(const Collections::Generic::IEnumerable<TSource>& source, const System::Func<const TSource&, TKey>& keySelector) {
          refptr<EnumerableCollection<TSource>> list = ref_new<EnumerableCollection<TSource>>(source);
          System::Comparison<const TSource&> comparer = delegate_(const TSource & x, const TSource & y) {
            if (keySelector(x) < keySelector(y)) return -1;
            if (keySelector(x) == keySelector(y)) return 0;
            return 1;
          };

          list->Sort(comparer);
          return list;
        }

        /// @brief Projects each element of a sequence into a new form.
        /// @include EnumerableCast.cpp
        template<typename TSource, typename TKey>
        static refptr<EnumerableCollection<TSource>> OrderByDescending(const Collections::Generic::IEnumerable<TSource>& source, const System::Func<const TSource&, TKey>& keySelector) {
          refptr<EnumerableCollection<TSource>> list = ref_new<EnumerableCollection<TSource>>(source);
          System::Comparison<const TSource&> comparer = delegate_(const TSource & x, const TSource & y) {
            if (keySelector(x) < keySelector(y)) return 1;
            if (keySelector(x) == keySelector(y)) return 0;
            return -1;
          };
          list->Sort(comparer);
          return list;
        }

        /// @brief Inverts the order of the elements in a sequence.
        /// @par Examples
        /// The following code example demonstrates how to use Reverse<TSource> to reverse the order of elements in an array.
        /// @include EnumerableReverse.cpp
        template<typename TSource>
        static refptr<EnumerableCollection<TSource>> Reverse(const Collections::Generic::IEnumerable<TSource>& source) {
          refptr<EnumerableCollection<TSource>> list = ref_new<EnumerableCollection<TSource>>();
          for (TSource item : source)
            list->Insert(0, item);
          return list;
        }

        /// @brief Projects each element of a sequence into a new form.
        /// @include EnumerableCast.cpp
        template<typename TSource, typename TResult>
        static refptr<EnumerableCollection<TResult>> Select(const Collections::Generic::IEnumerable<TSource>& source, const System::Func<const TSource&, TResult>& selector) {
          refptr<EnumerableCollection<TResult>> list = ref_new<EnumerableCollection<TResult>>();
          for (TSource item : source)
            list->Add(selector(item));
          return list;
        }

        /// @brief Creates an array from a IEnumerable<T>
        /// @par Examples
        /// The following code example demonstrates how to use ToArray<TSource> to force immediate query evaluation and return an array of results.
        /// @include EnumerableToArray.cpp
        template<typename TSource>
        static System::Array<TSource> ToArray(const Collections::Generic::IEnumerable<TSource>& source) {
          System::Array<TSource> array;
          for (TSource item : source) {
            array.Resize(array.Length + 1);
            array[array.Length - 1] = item;
          }
          return array;
        }

        /// @brief Projects each element of a sequence into a new form.
        /// @include EnumerableCast.cpp
        template<typename TSource>
        static refptr<EnumerableCollection<TSource>> Where(const Collections::Generic::IEnumerable<TSource>& source, const System::Func<const TSource&, bool>& predicate) {
          refptr<EnumerableCollection<TSource>> list = ref_new<EnumerableCollection<TSource>>();
          for (TSource item : source)
            if (predicate(item))
              list->Add(item);
          return list;
        }
      };

      namespace Extension {
        /// @brief Provides a set of methods for querying objects that implement IEnumerable<T>.
        template<typename T, typename TSource>
        class Enumerable {
        public:
          //class EnumerablePtr : public refptr<Collections::Generic::IEnumerable<T>>, public Enumerable<EnumerablePtr, T> {};

          /// @brief Applies an accumulator function over a sequence.
          /// @param func An accumulator function to be invoked on each element.
          /// @return The final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to reverse the order of words in a string by using Aggregate.
          /// @include EnumerableAgregate.cpp
          TSource Agregate(const System::Func<const TSource&, const TSource&, TSource>& func) const {return System::Linq::Enumerable::Agregate<TSource>(static_cast<const T&>(*this), func);}

          /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
          /// @param seed The initial accumulator value.
          /// @param func An accumulator function to be invoked on each element.
          /// @return The final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to use Aggregate to apply an accumulator function and use a seed value.
          /// @include EnumerableAgregate2.cpp
          template<typename TAccumulate>
          TAccumulate Agregate(const TAccumulate& seed, const System::Func<const TAccumulate&, const TSource&, TAccumulate>& func) const {return System::Linq::Enumerable::Agregate<TSource, TAccumulate>(static_cast<const T&>(*this), seed, func);}

          /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
          /// @param seed The initial accumulator value.
          /// @param objFunc An accumulator obj to be invoked on each element.
          /// @param func An accumulator function to be invoked on each element.
          /// @param objResultSelector A obj to transform the final accumulator value into the result value.
          /// @param resultSelector A function to transform the final accumulator value into the result value.
          /// @return The transformed final accumulator value.
          /// @par Examples
          /// The following code example demonstrates how to use Aggregate to apply an accumulator function and use a seed value.
          /// @include EnumerableAgregate3.cpp
          template<typename TAccumulate, typename TResult>
          TResult Agregate(const TAccumulate& seed, const System::Func<const TAccumulate&, const TSource&, TAccumulate>& func, const System::Func<const TAccumulate&, TResult>& resultSelector) const {return System::Linq::Enumerable::Agregate<TSource, TAccumulate, TResult>(static_cast<const T&>(*this), seed, func, resultSelector);}

          /// @brief Determines whether all elements of a sequence satisfy a condition.
          /// @param func A function to test each element for a condition.
          /// @return true if every element of the source sequence passes the test in the specified predicate, or if the sequence is empty; otherwise, false.
          /// @par Examples
          /// The following code example demonstrates how to use All<TSource> to determine whether all the elements in a sequence satisfy a condition. Variable allStartWithB is true if all the pet names start with "B" or if the pets array is empty.
          /// @include EnumerableAll.cpp
          bool All(const System::Func<const TSource&, bool>& func) const {return System::Linq::Enumerable::All<TSource>(static_cast<const T&>(*this), func);}

          /// @brief Determines whether a sequence contains any elements.
          /// @return true if the source sequence contains any elements; otherwise, false.
          /// @par Examples
          /// The following code example demonstrates how to use Any to determine whether a sequence contains any elements.
          /// @include EnumerableAny.cpp
          bool Any() const {return System::Linq::Enumerable::Any<TSource>(static_cast<const T&>(*this));}

          /// @brief Determines whether any element of a sequence satisfies a condition.
          /// @param predicate A function to test each element for a condition.
          /// @return true if any elements in the source sequence pass the test in the specified predicate; otherwise, false.
          /// @par Examples
          /// The following code example demonstrates how to use Any to determine whether any element in a sequence satisfies a condition.
          /// @include EnumerableAny2.cpp
          bool Any(const System::Func<const TSource&, bool>& predicate) const {return System::Linq::Enumerable::Any<TSource>(static_cast<const T&>(*this), predicate);}

          /// @brief Returns the input typed as IEnumerable<T>.
          /// @return The input sequence typed as IEnumerable<T>.
          /// @remarks The AsEnumerable<TSource>(IEnumerable<TSource>) method has no effect other than to change the compile-time type of source from a type that implements IEnumerable<T> to IEnumerable<T> itself.
          /// @remarks AsEnumerable<TSource>(IEnumerable<TSource>) can be used to choose between query implementations when a sequence implements IEnumerable<T> but also has a different set of public query methods available. For example, given a generic class Table that implements IEnumerable<T> and has its own methods such as Where, Select, and SelectMany, a call to Where would invoke the public Where method of Table. A Table type that represents a database table could have a Wheremethod that takes the predicate argument as an expression tree and converts the tree to SQL for remote execution. If remote execution is not desired, for example because the predicate invokes a local method, the AsEnumerable<TSource> method can be used to hide the custom methods and instead make the standard query operators available.
          /// @par Examples
          /// The following code example demonstrates how to use AsEnumerable<TSource>(IEnumerable<TSource>) to hide a type's custom Where method when the standard query operator implementation is desired.
          /// @include EnumerableAsEnumerable.cpp
          refptr<System::Linq::EnumerableCollection<TSource>> AsEnumerable() const {return System::Linq::Enumerable::AsEnumerable<TSource>(static_cast<const T&>(*this));}

          /// @brief Computes the average of a sequence of Double values.
          /// @param source A sequence of Double values to calculate the average of.
          /// @return The average of the sequence of values.
          /// @exception InvalidOperationException source contains no elements.
          /// The following code example demonstrates how to use Average(IEnumerable<Int32>) to calculate an average.
          /// @include EnumerableAverageInt32.cpp
          double Average() const {return System::Linq::Enumerable::Average(static_cast<const T&>(*this));}

          /// @brief Casts the elements of an IEnumerable to the specified type.
          /// @par Examples
          /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
          /// @include EnumerableCast.cpp
          template<typename TResult>
          refptr<System::Linq::EnumerableCollection<TResult>> Cast() const {return System::Linq::Enumerable::Cast<TSource, TResult>(static_cast<const T&>(*this));}

          /// @brief Concatenates two sequences.
          /// @param second The sequence to concatenate to this sequence.
          /// @return refptr<Collections::Generic::IEnumerable<TSource>> An IEnumerable<T> that contains the concatenated elements of the two input sequences.
          /// @par Examples
          /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
          /// @include EnumerableConcat.cpp
          refptr<System::Linq::EnumerableCollection<TSource>> Concat(const Collections::Generic::IEnumerable<TSource>& second) const {return System::Linq::Enumerable::Concat<TSource>(static_cast<const T&>(*this), second);}

          /// @brief Concatenates two sequences.
          /// @param second The sequence to concatenate to this sequence.
          /// @return refptr<Collections::Generic::IEnumerable<TSource>> An IEnumerable<T> that contains the concatenated elements of the two input sequences.
          /// @par Examples
          /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
          /// @include EnumerableConcat.cpp
          refptr<System::Linq::EnumerableCollection<TSource>> Concat(const InitializerList<TSource>& second) const {return System::Linq::Enumerable::Concat<TSource>(static_cast<const T&>(*this), second);}

          /// @brief Concatenates two sequences.
          /// @param second The sequence to concatenate to this sequence.
          /// @return refptr<Collections::Generic::IEnumerable<TSource>> An IEnumerable<T> that contains the concatenated elements of the two input sequences.
          /// @par Examples
          /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
          /// @include EnumerableConcat.cpp
          template<int32 len>
          refptr<System::Linq::EnumerableCollection<TSource>> Concat(const TSource(&second)[len]) const {return System::Linq::Enumerable::Concat<TSource>(static_cast<const T&>(*this), second);}

          /// @brief Concatenates two sequences.
          /// @param second The sequence to concatenate to this sequence.
          /// @return refptr<Collections::Generic::IEnumerable<TSource>> An IEnumerable<T> that contains the concatenated elements of the two input sequences.
          /// @par Examples
          /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
          /// @include EnumerableIntersect.cpp
          refptr<System::Linq::EnumerableCollection<TSource>> Intersect(const Collections::Generic::IEnumerable<TSource>& second) const {return System::Linq::Enumerable::Intersect<TSource>(static_cast<const T&>(*this), second);}

          /// @brief Concatenates two sequences.
          /// @param second The sequence to concatenate to this sequence.
          /// @return refptr<Collections::Generic::IEnumerable<TSource>> An IEnumerable<T> that contains the concatenated elements of the two input sequences.
          /// @par Examples
          /// The following code example demonstrates how to use Cast<TResult>(IEnumerable) to enable the use of the standard query operators on an ArrayList.
          /// @include EnumerableIntersect.cpp
          template<int32 len>
          refptr<System::Linq::EnumerableCollection<TSource>> Intersect(const TSource(&second)[len]) const {return System::Linq::Enumerable::Intersect<TSource>(static_cast<const T&>(*this), second);}

          /// @brief Returns the maximum value in a generic sequence.
          /// @return An IEnumerable<T> that contains each element of the source sequence cast to the specified type.
          /// @par Examples
          /// The following code example demonstrates how to use Max<TSource>(IEnumerable<TSource>) to determine the maximum value in a sequence of IComparable<T> objects.
          /// @include EnumerableMax.cpp
          const TSource& Max() const {return System::Linq::Enumerable::Max<TSource>(static_cast<const T&>(*this));}

          /// @brief Returns the minimum value in a generic sequence.
          /// @par Examples
          /// The following code example demonstrates how to use Min<TSource>(IEnumerable<TSource>) to determine the minimum value in a sequence of IComparable<T> objects.
          /// @include EnumerableMin.cpp
          const TSource& Min() const {return System::Linq::Enumerable::Min<TSource>(static_cast<const T&>(*this));}

          /// @brief Sorts the elements of a sequence in ascending order according to a key.
          /// @param keySelector A function to extract a key from an element.
          /// @par Examples
          /// The following code example demonstrates how to use OrderBy<TSource, TKey>(IEnumerable<TSource>, Func<TSource, TKey>) to sort the elements of a sequence.
          /// @include EnumerableOrderBy.cpp
          template<typename TKey>
          refptr<System::Linq::EnumerableCollection<TSource>> OrderBy(const System::Func<const TSource&, TKey>& keySelector) const {return System::Linq::Enumerable::OrderBy<TSource, TKey>(static_cast<const T&>(*this), keySelector);}

          /// @brief Projects each element of a sequence into a new form.
          /// @include EnumerableCast.cpp
          template<typename TKey>
          refptr<System::Linq::EnumerableCollection<TSource>> OrderByDescending(const System::Func<const TSource&, TKey>& keySelector) const {return System::Linq::Enumerable::OrderByDescending<TSource, TKey>(static_cast<const T&>(*this), keySelector);}

          /// @brief Projects each element of a sequence into a new form.
          /// @include EnumerableCast.cpp
          template<typename TResult>
          refptr<System::Linq::EnumerableCollection<TResult>> Select(const System::Func<const TSource&, TResult>& selector) const {return System::Linq::Enumerable::Select<TSource, TResult>(static_cast<const T&>(*this), selector);}

          /// @brief Inverts the order of the elements in a sequence.
          /// @par Examples
          /// The following code example demonstrates how to use Reverse<TSource> to reverse the order of elements in an array.
          /// @include EnumerableReverse.cpp
          refptr<System::Linq::EnumerableCollection<TSource>> Reverse() const {return System::Linq::Enumerable::Reverse<TSource>(static_cast<const T&>(*this));}

          /// @brief Creates an array from a IEnumerable<T>
          /// @par Examples
          /// The following code example demonstrates how to use ToArray<TSource> to force immediate query evaluation and return an array of results.
          /// @include EnumerableToArray.cpp
          System::Array<TSource> ToArray() const {return System::Linq::Enumerable::ToArray<TSource>(static_cast<const T&>(*this));}

          /// @brief Projects each element of a sequence into a new form.
          /// @include EnumerableCast.cpp
          refptr<System::Linq::EnumerableCollection<TSource>> Where(const System::Func<const TSource&, bool>& predicate) const {return System::Linq::Enumerable::Where<TSource>(static_cast<const T&>(*this), predicate);}

        protected:
          Enumerable() {}
        };
      }
    }
  }
}

using namespace Switch;


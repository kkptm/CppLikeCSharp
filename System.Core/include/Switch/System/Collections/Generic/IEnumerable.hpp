/// @file
/// @brief Contains Switch::System::Collections::Generic::IEnumerable <T> interface.
#pragma once

#include "../../../Interface.hpp"
#include "../../../RefPtr.hpp"
#include "IEnumerator.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @interface IEnumerable
        /// @brief Exposes the enumerator, which supports a simple iteration over a generic collection.
        template<typename T>
        class IEnumerable interface_ {
        public:
          /// @brief Returns an enumerator that iterates through a collection.
          /// @return IEnumerator An IEnumerator object that can be used to iterate through the collection.
          virtual Enumerator<T> GetEnumerator() const = 0;

          // Not correct for an interface but necessary for C++ language.
        private:
          class Iterator : public std::iterator<std::input_iterator_tag, T> {
          public:
            Iterator(const Iterator& value) : enumerator(value.enumerator), pos(value.pos) {}
            Iterator& operator=(const Iterator& value) {
              this->enumerator = value.enumerator;
              this->pos = value.pos;
              return *this;
            }

            explicit Iterator(const Enumerator<T>& enumerator) : enumerator(enumerator) {
              this->enumerator.Reset();
              if (this->enumerator.MoveNext() == false)
                this->pos = -1;
            }

            Iterator(const Enumerator<T>& enumerator, bool end) : enumerator(enumerator) {
              this->enumerator.Reset();
              if (this->enumerator.MoveNext() == false || end == true)
                this->pos = -1;
            }

            Iterator& operator++() {
              if (this->pos != -1) {
                ++this->pos;
                if (this->enumerator.MoveNext() == false)
                  this->pos = -1;
              }
              return *this;
            }

            Iterator operator++(int) {
              Iterator iterator(*this);
              if (this->pos != -1) {
                ++this->pos;
                if (this->enumerator.MoveNext() == false)
                  this->pos = -1;
              }
              return iterator;
            }

            bool operator==(const Iterator& rhs) const {return this->pos == rhs.pos;}
            bool operator!=(const Iterator& rhs) const {return this->pos != rhs.pos;}

            const T& operator*() const {return this->enumerator.Current();}
            T& operator*() {return const_cast<T&>(this->enumerator.Current());}

          private:
            Enumerator<T> enumerator;
            int32 pos = 0;
          };

        public:
          /// @cond
          using const_iterator = const Iterator;
          using iterator = Iterator;

          const_iterator cbegin() const {return const_iterator(GetEnumerator());}
          const_iterator cend() const  {return const_iterator(GetEnumerator(), true);}
          const_iterator begin() const {return const_iterator(GetEnumerator());}
          iterator begin() {return iterator(GetEnumerator());}
          const_iterator end() const {return const_iterator(GetEnumerator(), true);}
          iterator end() {return iterator(GetEnumerator(), true);}
          /// @endcond
        };
      }
    }
  }
}

using namespace Switch;

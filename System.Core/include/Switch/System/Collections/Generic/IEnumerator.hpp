/// @file
/// @brief Contains Switch::System::Collections::Generic::IEnumerator <T> interface.
#pragma once

#include "../../../Interface.hpp"
#include "../../../Property.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief The System::Collections::Generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
      namespace Generic {
        /// @interface IEnumerator
        /// @brief Supports a simple iteration over a generic collection.
        template<typename T>
        class IEnumerator interface_ {
        public:
          /// @cond
          IEnumerator() {}
          /// @endcond

          /// @brief Gets the element in the collection at the current position of the enumerator.
          /// After an enumerator is created or after a Reset, MoveNext must be called to advance the enumerator to the first element of the collection before calling GetCurrent; otherwise it throws System::InvalidOperationException.
          /// @return T The current element in the collection.
          property_<const T&, readonly_> Current {
            get_->const T& {return this->GetCurrent();}
          };

          /// @brief Advances the enumerator to the next element of the collection.
          /// @return Boolean true if the enumerator was successfully advanced to the next element; false if the enumerator has passed the end of the collection.
          /// @return @see object
          virtual bool MoveNext() = 0;

          /// @brief Sets the enumerator to its initial position, which is before the first element in the collection.
          /// @return None.
          /// @return @see object
          virtual void Reset() = 0;

        protected:
          /// @brief Gets the element in the collection at the current position of the enumerator.
          /// After an enumerator is created or after a Reset, MoveNext must be called to advance the enumerator to the first element of the collection before calling GetCurrent; otherwise it throws System::InvalidOperationException.
          /// @return T The current element in the collection.
          virtual const T& GetCurrent() const = 0;

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

            explicit Iterator(IEnumerator<T>* enumerator) : enumerator(enumerator), pos(0) {
              this->enumerator->Reset();
              if (this->enumerator->MoveNext() == false)
                this->pos = -1;
            }

            Iterator(IEnumerator<T>* enumerator, bool end) : enumerator(enumerator), pos(0) {
              this->enumerator->Reset();
              if (this->enumerator->MoveNext() == false || end == true)
                this->pos = -1;
            }

            Iterator& operator++() {
              if (this->pos != -1) {
                ++this->pos;
                if (this->enumerator->MoveNext() == false)
                  this->pos = -1;
              }
              return *this;
            }

            Iterator operator++(int) {
              Iterator iterator(*this);
              if (this->pos != -1) {
                ++this->pos;
                if (this->enumerator->MoveNext() == false)
                  this->pos = -1;
              }
              return iterator;
            }

            bool operator==(const Iterator& rhs) const {return this->pos == rhs.pos;}
            bool operator !=(const Iterator& rhs) const {return !this->operator==(rhs);}

            const T& operator*() const  {
              return this->enumerator->Current();
            }

            T& operator*()  {
              return const_cast<T&>(this->enumerator->Current());
            }

          private:
            IEnumerator<T>* enumerator;
            int32 pos;
          };

        public:
          /// @cond
          using const_iterator = const Iterator;
          using iterator = Iterator;

          const_iterator cbegin() const {return const_iterator(this);}
          const_iterator cend() const  {return const_iterator(this, true);}
          const_iterator begin() const {return const_iterator(this);}
          iterator begin() {return iterator(this);}
          const_iterator end() const {return const_iterator(this, true);}
          iterator end() {return iterator(this, true);}
          /// @endcond
        };

        /// @brief Supports a simple iteration over a generic collection.
        template<typename T>
        class Enumerator : public object, public IEnumerator<T> {
        public:
          /// @cond
          explicit Enumerator(refptr<IEnumerator<T>> enumerator) : enumerator(enumerator) {}
          Enumerator(const Enumerator& enumerator) : enumerator(enumerator.enumerator) {}
          Enumerator& operator=(const Enumerator& enumerator) {
            this->enumerator = enumerator.enumerator;
            return *this;
          }
          /// @endcond

          /// @brief Advances the enumerator to the next element of the collection.
          /// @return Boolean true if the enumerator was successfully advanced to the next element; false if the enumerator has passed the end of the collection.
          /// @return @see object
          bool MoveNext() override {return this->enumerator->MoveNext();}

          /// @brief Sets the enumerator to its initial position, which is before the first element in the collection.
          /// @return None.
          /// @return @see object
          void Reset() override {this->enumerator->Reset();}

          /// @cond
          operator refptr<IEnumerator<T>>() const {return this->enumerator;}
          operator refptr<IEnumerator<T>>() {return this->enumerator;}
          /// @endcond

        protected:
          const T& GetCurrent() const override {return this->enumerator->Current();}

        private:
          refptr<IEnumerator<T>> enumerator;
        };
      }
    }
  }
}

using namespace Switch;

/// @file
/// @brief Contains Switch::System::ValueTuple <> class.
#pragma once
#include <tuple>

#include "../Property.hpp"
#include "../Static.hpp"
#include "../Types.hpp"
#include "_String.hpp"
#include "Collections/Generic/Comparer.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    template<typename T1 = NullPtr, typename T2 = NullPtr, typename T3 = NullPtr, typename T4 = NullPtr, typename T5 = NullPtr, typename T6 = NullPtr, typename T7 = NullPtr, typename TRest = NullPtr>
    class ValueTuple;
    /// @endcond

    /// @brief Base object that represent ValueTuple.
    class ValueTupleObject : public object {
      template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename TRest>
      friend class ValueTuple;
      ValueTupleObject() = default;
    };

    /// @brief Represents an n-tuple, where n is 8 or greater.
    /// @see System::ValueTuple
    /// @see System::ValueTuple <T1>
    /// @see System::ValueTuple <T1, T2>
    /// @see System::ValueTuple <T1, T2, T3>
    /// @see System::ValueTuple <T1, T2, T3, T4>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7>
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename TRest>
    class ValueTuple : public ValueTupleObject, public IComparable {
    public:
      /// @brief Initializes a new instance of the ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> class.
      /// @param item1 The value of the tuple's first component.
      /// @param item2 The value of the tuple's second component.
      /// @param item3 The value of the tuple's third component.
      /// @param item4 The value of the tuple's fourth component.
      /// @param item5 The value of the tuple's fifth component.
      /// @param item6 The value of the tuple's sixth component.
      /// @param item7 The value of the tuple's seventh component.
      /// @param itemRest Any generic ValueTuple object that contains the values of the tuple's remaining components.
      /// @remarks You can also use the static ValueTuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      ValueTuple(const T1& item1, const T2& item2, const T3& item3, const T4& item4, const T5& item5, const T6& item6, const T7& item7, const TRest& itemRest) : tuple(std::make_tuple(item1, item2, item3, item4, item5, item6, item7, itemRest)) {}
      /// @cond
      ValueTuple() {}
      ValueTuple(const ValueTuple& tuple) : tuple(tuple.tuple) {}
      ValueTuple(const std::tuple<T1, T2, T3, T4, T5, T6, T7, TRest>& tuple) : tuple(tuple) {}
      /// @endcond

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's first component.
      /// @param T1 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's first component.
      property_<T1> Item1 {
        get_ {return std::get<0>(this->tuple);},
        set_ {std::get<0>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's second component.
      /// @param T2 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's second component.
      property_<T2> Item2 {
        get_ {return std::get<1>(this->tuple);},
        set_ {std::get<1>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's third component.
      /// @param T3 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's third component.
      property_<T3> Item3 {
        get_ {return std::get<2>(this->tuple);},
        set_ {std::get<2>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's fourth component.
      /// @param T4 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's fourth component.
      property_<T4> Item4 {
        get_ {return std::get<3>(this->tuple);},
        set_ {std::get<3>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's fifth component.
      /// @param T5 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's fifth component.
      property_<T5> Item5 {
        get_ {return std::get<4>(this->tuple);},
        set_ {std::get<4>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's sixth component.
      /// @param T6 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's sixth component.
      property_<T6> Item6 {
        get_ {return std::get<5>(this->tuple);},
        set_ {std::get<5>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's seventh component.
      /// @param T7 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's seventh component.
      property_<T7> Item7 {
        get_ {return std::get<6>(this->tuple);},
        set_ {std::get<6>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's remaining component.
      /// @param TRest The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's remaining component.
      property_<TRest> Rest {
        get_ {return std::get<7>(this->tuple);},
        set_ {std::get<7>(this->tuple) = value;}
      };

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const IComparable& obj) const override {return !is<ValueTuple>(obj) ? 1 : this->CompareTo((const ValueTuple&)obj);}

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const ValueTuple& tuple) const {
        int32 result = 0;
        if ((result = System::Collections::Generic::Comparer<T1>::Default.Compare(this->Item1, tuple.Item1)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T2>::Default.Compare(this->Item2, tuple.Item2)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T3>::Default.Compare(this->Item3, tuple.Item3)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T4>::Default.Compare(this->Item4, tuple.Item4)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T5>::Default.Compare(this->Item5, tuple.Item5)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T6>::Default.Compare(this->Item6, tuple.Item6)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T7>::Default.Compare(this->Item7, tuple.Item7)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<TRest>::Default.Compare(this->Rest, tuple.Rest)) != 0) return result;
        return result;
      }

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const Object& obj) const override {return is<ValueTuple>(obj) && this->Equals((const ValueTuple&)obj);}

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const ValueTuple& tuple) const {return this->Item1 == tuple.Item1 && this->Item2 == tuple.Item2 && this->Item3 == tuple.Item3 && this->Item4 == tuple.Item4 && this->Item5 == tuple.Item5 && this->Item6 == tuple.Item6 && this->Item7 == tuple.Item7 && this->Rest == tuple.Rest;}

      /// @brief Returns a string that represents the current object.
      /// @return string A string that represents the current object.
      string ToString() const override {return string::Format("({0}, {1}, {2}, {3}, {4}, {5}, {6}, {7})", this->Item1, this->Item2, this->Item3, this->Item4, this->Item5, this->Item6, this->Item7, is<ValueTupleObject>(this->Rest()) ? this->Rest().ToString().Substring(1, this->Rest().ToString().Length - 2) : this->Rest().ToString());}

    private:
      std::tuple<T1, T2, T3, T4, T5, T6, T7, TRest> tuple;
    };

    /// @brief Represents a 7-tuple, or septuple.
    /// @see System::ValueTuple
    /// @see System::ValueTuple <T1>
    /// @see System::ValueTuple <T1, T2>
    /// @see System::ValueTuple <T1, T2, T3>
    /// @see System::ValueTuple <T1, T2, T3, T4>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    class ValueTuple<T1, T2, T3, T4, T5, T6, T7> : public ValueTupleObject, public IComparable {
    public:
      /// @brief Initializes a new instance of the ValueTuple <T1, T2, T3, T4, T5, T6, T7> class.
      /// @param item1 The value of the tuple's first component.
      /// @param item2 The value of the tuple's second component.
      /// @param item3 The value of the tuple's third component.
      /// @param item4 The value of the tuple's fourth component.
      /// @param item5 The value of the tuple's fifth component.
      /// @param item6 The value of the tuple's sixth component.
      /// @param item7 The value of the tuple's seventh component.
      /// @remarks You can also use the static ValueTuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      ValueTuple(const T1& item1, const T2& item2, const T3& item3, const T4& item4, const T5& item5, const T6& item6, const T7& item7) : tuple(std::make_tuple(item1, item2, item3, item4, item5, item6, item7)) {}
      /// @cond
      ValueTuple() {}
      ValueTuple(const ValueTuple& tuple) : tuple(tuple.tuple) {}
      ValueTuple(const std::tuple<T1, T2, T3, T4, T5, T6, T7>& tuple) : tuple(tuple) {}
      /// @endcond

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7> object's first component.
      /// @param T1 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7> object's first component.
      property_<T1> Item1 {
        get_ {return std::get<0>(this->tuple);},
        set_ {std::get<0>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7> object's second component.
      /// @param T2 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7> object's second component.
      property_<T2> Item2 {
        get_ {return std::get<1>(this->tuple);},
        set_ {std::get<1>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7> object's third component.
      /// @param T3 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7> object's third component.
      property_<T3> Item3 {
        get_ {return std::get<2>(this->tuple);},
        set_ {std::get<2>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7> object's fourth component.
      /// @param T4 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7> object's fourth component.
      property_<T4> Item4 {
        get_ {return std::get<3>(this->tuple);},
        set_ {std::get<3>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7> object's fifth component.
      /// @param T5 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7> object's fifth component.
      property_<T5> Item5 {
        get_ {return std::get<4>(this->tuple);},
        set_ {std::get<4>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7> object's sixth component.
      /// @param T6 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7> object's sixth component.
      property_<T6> Item6 {
        get_ {return std::get<5>(this->tuple);},
        set_ {std::get<5>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7> object's seventh component.
      /// @param T7 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6, T7> object's seventh component.
      property_<T7> Item7 {
        get_ {return std::get<6>(this->tuple);},
        set_ {std::get<6>(this->tuple) = value;}
      };

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const IComparable& obj) const override {return !is<ValueTuple>(obj) ? 1 : this->CompareTo((const ValueTuple&)obj);}

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const ValueTuple& tuple) const {
        int32 result = 0;
        if ((result = System::Collections::Generic::Comparer<T1>::Default.Compare(this->Item1, tuple.Item1)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T2>::Default.Compare(this->Item2, tuple.Item2)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T3>::Default.Compare(this->Item3, tuple.Item3)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T4>::Default.Compare(this->Item4, tuple.Item4)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T5>::Default.Compare(this->Item5, tuple.Item5)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T6>::Default.Compare(this->Item6, tuple.Item6)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T7>::Default.Compare(this->Item7, tuple.Item7)) != 0) return result;
        return result;
      }

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const Object& obj) const override {return is<ValueTuple>(obj) && this->Equals((const ValueTuple&)obj);}

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const ValueTuple& tuple) const {return this->Item1 == tuple.Item1 && this->Item2 == tuple.Item2 && this->Item3 == tuple.Item3 && this->Item4 == tuple.Item4 && this->Item5 == tuple.Item5 && this->Item6 == tuple.Item6 && this->Item7 == tuple.Item7;}

      /// @brief Returns a string that represents the current object.
      /// @return string A string that represents the current object.
      string ToString() const override {return string::Format("({0}, {1}, {2}, {3}, {4}, {5}, {6})", this->Item1, this->Item2, this->Item3, this->Item4, this->Item5, this->Item6, this->Item7);}

    private:
      std::tuple<T1, T2, T3, T4, T5, T6, T7> tuple;
    };

    /// @brief Represents a 6-tuple, or sextuple.
    /// @see System::ValueTuple
    /// @see System::ValueTuple <T1>
    /// @see System::ValueTuple <T1, T2>
    /// @see System::ValueTuple <T1, T2, T3>
    /// @see System::ValueTuple <T1, T2, T3, T4>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    class ValueTuple<T1, T2, T3, T4, T5, T6> : public ValueTupleObject, public IComparable {
    public:
      /// @brief Initializes a new instance of the ValueTuple <T1, T2, T3, T4, T5, T6> class.
      /// @param item1 The value of the tuple's first component.
      /// @param item2 The value of the tuple's second component.
      /// @param item3 The value of the tuple's third component.
      /// @param item4 The value of the tuple's fourth component.
      /// @param item5 The value of the tuple's fifth component.
      /// @param item6 The value of the tuple's sixth component.
      /// @remarks You can also use the static ValueTuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      ValueTuple(const T1& item1, const T2& item2, const T3& item3, const T4& item4, const T5& item5, const T6& item6) : tuple(std::make_tuple(item1, item2, item3, item4, item5, item6)) {}
      /// @cond
      ValueTuple() {}
      ValueTuple(const ValueTuple& tuple) : tuple(tuple.tuple) {}
      ValueTuple(const std::tuple<T1, T2, T3, T4, T5, T6>& tuple) : tuple(tuple) {}
      /// @endcond

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6> object's first component.
      /// @param T1 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6> object's first component.
      property_<T1> Item1 {
        get_ {return std::get<0>(this->tuple);},
        set_ {std::get<0>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6> object's second component.
      /// @param T2 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6> object's second component.
      property_<T2> Item2 {
        get_ {return std::get<1>(this->tuple);},
        set_ {std::get<1>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6> object's third component.
      /// @param T3 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6> object's third component.
      property_<T3> Item3 {
        get_ {return std::get<2>(this->tuple);},
        set_ {std::get<2>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6> object's fourth component.
      /// @param T4 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6> object's fourth component.
      property_<T4> Item4 {
        get_ {return std::get<3>(this->tuple);},
        set_ {std::get<3>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6> object's fifth component.
      /// @param T5 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6> object's fifth component.
      property_<T5> Item5 {
        get_ {return std::get<4>(this->tuple);},
        set_ {std::get<4>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5, T6> object's sixth component.
      /// @param T6 The value of the current ValueTuple <T1, T2, T3, T4, T5, T6> object's sixth component.
      property_<T6> Item6 {
        get_ {return std::get<5>(this->tuple);},
        set_ {std::get<5>(this->tuple) = value;}
      };

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const IComparable& obj) const override {return !is<ValueTuple>(obj) ? 1 : this->CompareTo((const ValueTuple&)obj);}

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const ValueTuple& tuple) const {
        int32 result = 0;
        if ((result = System::Collections::Generic::Comparer<T1>::Default.Compare(this->Item1, tuple.Item1)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T2>::Default.Compare(this->Item2, tuple.Item2)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T3>::Default.Compare(this->Item3, tuple.Item3)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T4>::Default.Compare(this->Item4, tuple.Item4)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T5>::Default.Compare(this->Item5, tuple.Item5)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T6>::Default.Compare(this->Item6, tuple.Item6)) != 0) return result;
        return result;
      }

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const Object& obj) const override {return is<ValueTuple>(obj) && this->Equals((const ValueTuple&)obj);}

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const ValueTuple& tuple) const {return this->Item1 == tuple.Item1 && this->Item2 == tuple.Item2 && this->Item3 == tuple.Item3 && this->Item4 == tuple.Item4 && this->Item5 == tuple.Item5 && this->Item6 == tuple.Item6;}

      /// @brief Returns a string that represents the current object.
      /// @return string A string that represents the current object.
      string ToString() const override {return string::Format("({0}, {1}, {2}, {3}, {4}, {5})", this->Item1, this->Item2, this->Item3, this->Item4, this->Item5, this->Item6);}

    private:
      std::tuple<T1, T2, T3, T4, T5, T6> tuple;
    };

    /// @brief Represents a 5-tuple, or quintuple.
    /// @see System::ValueTuple
    /// @see System::ValueTuple <T1>
    /// @see System::ValueTuple <T1, T2>
    /// @see System::ValueTuple <T1, T2, T3>
    /// @see System::ValueTuple <T1, T2, T3, T4>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    template<typename T1, typename T2, typename T3, typename T4, typename T5>
    class ValueTuple<T1, T2, T3, T4, T5> : public ValueTupleObject, public IComparable {
    public:
      /// @brief Initializes a new instance of the ValueTuple <T1, T2, T3, T4, T5> class.
      /// @param item1 The value of the tuple's first component.
      /// @param item2 The value of the tuple's second component.
      /// @param item3 The value of the tuple's third component.
      /// @param item4 The value of the tuple's fourth component.
      /// @param item5 The value of the tuple's fifth component.
      /// @remarks You can also use the static ValueTuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      ValueTuple(const T1& item1, const T2& item2, const T3& item3, const T4& item4, const T5& item5) : tuple(std::make_tuple(item1, item2, item3, item4, item5)) {}
      /// @cond
      ValueTuple() {}
      ValueTuple(const ValueTuple& tuple) : tuple(tuple.tuple) {}
      ValueTuple(const std::tuple<T1, T2, T3, T4, T5>& tuple) : tuple(tuple) {}
      /// @endcond

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5> object's first component.
      /// @param T1 The value of the current ValueTuple <T1, T2, T3, T4, T5> object's first component.
      property_<T1> Item1 {
        get_ {return std::get<0>(this->tuple);},
        set_ {std::get<0>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5> object's second component.
      /// @param T2 The value of the current ValueTuple <T1, T2, T3, T4, T5> object's second component.
      property_<T2> Item2 {
        get_ {return std::get<1>(this->tuple);},
        set_ {std::get<1>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5> object's third component.
      /// @param T3 The value of the current ValueTuple <T1, T2, T3, T4, T5> object's third component.
      property_<T3> Item3 {
        get_ {return std::get<2>(this->tuple);},
        set_ {std::get<2>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5> object's fourth component.
      /// @param T4 The value of the current ValueTuple <T1, T2, T3, T4, T5> object's fourth component.
      property_<T4> Item4 {
        get_ {return std::get<3>(this->tuple);},
        set_ {std::get<3>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4, T5> object's fifth component.
      /// @param T5 The value of the current ValueTuple <T1, T2, T3, T4, T5> object's fifth component.
      property_<T5> Item5 {
        get_ {return std::get<4>(this->tuple);},
        set_ {std::get<4>(this->tuple) = value;}
      };

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const IComparable& obj) const override {return !is<ValueTuple>(obj) ? 1 : this->CompareTo((const ValueTuple&)obj);}

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const ValueTuple& tuple) const {
        int32 result = 0;
        if ((result = System::Collections::Generic::Comparer<T1>::Default.Compare(this->Item1, tuple.Item1)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T2>::Default.Compare(this->Item2, tuple.Item2)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T3>::Default.Compare(this->Item3, tuple.Item3)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T4>::Default.Compare(this->Item4, tuple.Item4)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T5>::Default.Compare(this->Item5, tuple.Item5)) != 0) return result;
        return result;
      }

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const Object& obj) const override {return is<ValueTuple>(obj) && this->Equals((const ValueTuple&)obj);}

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const ValueTuple& tuple) const {return this->Item1 == tuple.Item1 && this->Item2 == tuple.Item2 && this->Item3 == tuple.Item3 && this->Item4 == tuple.Item4 && this->Item5 == tuple.Item5;}

      /// @brief Returns a string that represents the current object.
      /// @return string A string that represents the current object.
      string ToString() const override {return string::Format("({0}, {1}, {2}, {3}, {4})", this->Item1, this->Item2, this->Item3, this->Item4, this->Item5);}

    private:
      std::tuple<T1, T2, T3, T4, T5> tuple;
    };

    /// @brief Represents a 4-tuple, or quadruple.
    /// @see System::ValueTuple
    /// @see System::ValueTuple <T1>
    /// @see System::ValueTuple <T1, T2>
    /// @see System::ValueTuple <T1, T2, T3>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    template<typename T1, typename T2, typename T3, typename T4>
    class ValueTuple<T1, T2, T3, T4> : public ValueTupleObject, public IComparable {
    public:
      /// @brief Initializes a new instance of the ValueTuple <T1, T2, T3, T4> class.
      /// @param item1 The value of the tuple's first component.
      /// @param item2 The value of the tuple's second component.
      /// @param item3 The value of the tuple's third component.
      /// @param item4 The value of the tuple's fourth component.
      /// @remarks You can also use the static ValueTuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      ValueTuple(const T1& item1, const T2& item2, const T3& item3, const T4& item4) : tuple(std::make_tuple(item1, item2, item3, item4)) {}
      /// @cond
      ValueTuple() {}
      ValueTuple(const ValueTuple& tuple) : tuple(tuple.tuple) {}
      ValueTuple(const std::tuple<T1, T2, T3, T4>& tuple) : tuple(tuple) {}
      /// @endcond

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4> object's first component.
      /// @param T1 The value of the current ValueTuple <T1, T2, T3, T4> object's first component.
      property_<T1> Item1 {
        get_ {return std::get<0>(this->tuple);},
        set_ {std::get<0>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4> object's second component.
      /// @param T2 The value of the current ValueTuple <T1, T2, T3, T4> object's second component.
      property_<T2> Item2 {
        get_ {return std::get<1>(this->tuple);},
        set_ {std::get<1>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4> object's third component.
      /// @param T3 The value of the current ValueTuple <T1, T2, T3, T4> object's third component.
      property_<T3> Item3 {
        get_ {return std::get<2>(this->tuple);},
        set_ {std::get<2>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3, T4> object's fourth component.
      /// @param T4 The value of the current ValueTuple <T1, T2, T3, T4> object's fourth component.
      property_<T4> Item4 {
        get_ {return std::get<3>(this->tuple);},
        set_ {std::get<3>(this->tuple) = value;}
      };

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const IComparable& obj) const override {return !is<ValueTuple>(obj) ? 1 : this->CompareTo((const ValueTuple&)obj);}

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const ValueTuple& tuple) const {
        int32 result = 0;
        if ((result = System::Collections::Generic::Comparer<T1>::Default.Compare(this->Item1, tuple.Item1)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T2>::Default.Compare(this->Item2, tuple.Item2)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T3>::Default.Compare(this->Item3, tuple.Item3)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T4>::Default.Compare(this->Item4, tuple.Item4)) != 0) return result;
        return result;
      }

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const Object& obj) const override {return is<ValueTuple>(obj) && this->Equals((const ValueTuple&)obj);}

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const ValueTuple& tuple) const {return this->Item1 == tuple.Item1 && this->Item2 == tuple.Item2 && this->Item3 == tuple.Item3 && this->Item4 == tuple.Item4;}

      /// @brief Returns a string that represents the current object.
      /// @return string A string that represents the current object.
      string ToString() const override {return string::Format("({0}, {1}, {2}, {3})", this->Item1, this->Item2, this->Item3, this->Item4);}

    private:
      std::tuple<T1, T2, T3, T4> tuple;
    };

    /// @brief Represents a 3-tuple, or triple.
    /// @see System::ValueTuple
    /// @see System::ValueTuple <T1>
    /// @see System::ValueTuple <T1, T2>
    /// @see System::ValueTuple <T1, T2, T3, T4>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    template<typename T1, typename T2, typename T3>
    class ValueTuple<T1, T2, T3> : public ValueTupleObject, public IComparable {
    public:
      /// @brief Initializes a new instance of the ValueTuple <T1, T2, T3> class.
      /// @param item1 The value of the tuple's first component.
      /// @param item2 The value of the tuple's second component.
      /// @param item3 The value of the tuple's third component.
      /// @remarks You can also use the static ValueTuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      ValueTuple(const T1& item1, const T2& item2, const T3& item3) : tuple(std::make_tuple(item1, item2, item3)) {}
      /// @cond
      ValueTuple() {}
      ValueTuple(const ValueTuple& tuple) : tuple(tuple.tuple) {}
      ValueTuple(const std::tuple<T1, T2, T3>& tuple) : tuple(tuple) {}
      /// @endcond

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3> object's first component.
      /// @param T1 The value of the current ValueTuple <T1, T2, T3> object's first component.
      property_<T1> Item1 {
        get_ {return std::get<0>(this->tuple);},
        set_ {std::get<0>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3> object's second component.
      /// @param T2 The value of the current ValueTuple <T1, T2, T3> object's second component.
      property_<T2> Item2 {
        get_ {return std::get<1>(this->tuple);},
        set_ {std::get<1>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2, T3> object's third component.
      /// @param T3 The value of the current ValueTuple <T1, T2, T3> object's third component.
      property_<T3> Item3 {
        get_ {return std::get<2>(this->tuple);},
        set_ {std::get<2>(this->tuple) = value;}
      };

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const IComparable& obj) const override {return !is<ValueTuple>(obj) ? 1 : this->CompareTo((const ValueTuple&)obj);}

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const ValueTuple& tuple) const {
        int32 result = 0;
        if ((result = System::Collections::Generic::Comparer<T1>::Default.Compare(this->Item1, tuple.Item1)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T2>::Default.Compare(this->Item2, tuple.Item2)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T3>::Default.Compare(this->Item3, tuple.Item3)) != 0) return result;
        return result;
      }

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const Object& obj) const override {return is<ValueTuple>(obj) && this->Equals((const ValueTuple&)obj);}

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const ValueTuple& tuple) const {return this->Item1 == tuple.Item1 && this->Item2 == tuple.Item2 && this->Item3 == tuple.Item3;}

      /// @brief Returns a string that represents the current object.
      /// @return string A string that represents the current object.
      string ToString() const override {return string::Format("({0}, {1}, {2})", this->Item1, this->Item2, this->Item3);}

    private:
      std::tuple<T1, T2, T3> tuple;
    };

    /// @brief Represents a 2-tuple, or pair.
    /// @see System::ValueTuple
    /// @see System::ValueTuple <T1>
    /// @see System::ValueTuple <T1, T2, T3>
    /// @see System::ValueTuple <T1, T2, T3, T4>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    /// @remarks A tuple is a data structure that has a specific number and sequence of values. The ValueTuple<T1, T2> class represents a 2-tuple, or pair, which is a tuple that has two components. A 2-tuple is similar to a KeyValuePair<TKey, TValue> structure.
    /// @remarks You can instantiate a ValueTuple<T1, T2> object by calling either the ValueTuple<T1, T2> constructor or the static ValueTuple.Create<T1, T2>(T1, T2) method. You can retrieve the values of the tuple's components by using the read-only Item1 and Item2 instance properties.
    /// @remarks ValueTuples are commonly used in four different ways:
    /// @remarks To represent a single set of data. For example, a tuple can represent a record in a database, and its components can represent that record's fields.
    /// @remarks To provide easy access to, and manipulation of, a data set. The following example defines an array of ValueTuple<T1, T2> objects that contain the names of students and their corresponding test scores. It then iterates the array to calculate the mean test score.
    /// @include ValueTuple2.cpp
    /// @remarks To return multiple values from a method without the use of out parameters. For example, the following example uses a ValueTuple<T1, T2> object to return the quotient and the remainder that result from integer division.
    /// @remarks To pass multiple values to a method through a single parameter. For example, the Thread.Start(object) method has a single parameter that lets you supply one value to the method that the thread executes at startup_. If you supply a ValueTuple<T1, T2> object as the method argument, you can supply the thread’s startup_ routine with two items of data.
    template<typename T1, typename T2>
    class ValueTuple<T1, T2> : public ValueTupleObject, public IComparable {
    public:
      /// @brief Initializes a new instance of the ValueTuple <T1, T2> class.
      /// @param item1 The value of the tuple's first component.
      /// @param item2 The value of the tuple's second component.
      /// @remarks You can also use the static ValueTuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      ValueTuple(const T1& item1, const T2& item2) : tuple(std::make_tuple(item1, item2)) {}
      /// @cond
      ValueTuple() {}
      ValueTuple(const ValueTuple& tuple) : tuple(tuple.tuple) {}
      ValueTuple(const std::tuple<T1, T2>& tuple) : tuple(tuple) {}
      /// @endcond

      /// @brief Gets the value of the current ValueTuple <T1, T2> object's first component.
      /// @param T1 The value of the current ValueTuple <T1, T2> object's first component.
      property_<T1> Item1 {
        get_ {return std::get<0>(this->tuple);},
        set_ {std::get<0>(this->tuple) = value;}
      };

      /// @brief Gets the value of the current ValueTuple <T1, T2> object's second component.
      /// @param T2 The value of the current ValueTuple <T1, T2> object's second component.
      property_<T2> Item2 {
        get_ {return std::get<1>(this->tuple);},
        set_ {std::get<1>(this->tuple) = value;}
      };

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const IComparable& obj) const override {return !is<ValueTuple>(obj) ? 1 : this->CompareTo((const ValueTuple&)obj);}

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const ValueTuple& tuple) const {
        int32 result = 0;
        if ((result = System::Collections::Generic::Comparer<T1>::Default.Compare(this->Item1, tuple.Item1)) != 0) return result;
        if ((result = System::Collections::Generic::Comparer<T2>::Default.Compare(this->Item2, tuple.Item2)) != 0) return result;
        return result;
      }

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const Object& obj) const override {return is<ValueTuple>(obj) && this->Equals((const ValueTuple&)obj);}

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const ValueTuple& tuple) const {return this->Item1 == tuple.Item1 && this->Item2 == tuple.Item2;}

      /// @brief Returns a string that represents the current object.
      /// @return string A string that represents the current object.
      string ToString() const override {return string::Format("({0}, {1})", this->Item1, this->Item2);}

    private:
      std::tuple<T1, T2> tuple;
    };

    /// @brief Represents a 1-tuple, or singleton.
    /// @see System::ValueTuple
    /// @see System::ValueTuple <T1, T2>
    /// @see System::ValueTuple <T1, T2, T3>
    /// @see System::ValueTuple <T1, T2, T3, T4>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    template<typename T1>
    class ValueTuple<T1> : public ValueTupleObject, public IComparable {
    public:
      /// @brief Initializes a new instance of the ValueTuple <T1> class.
      /// @param item1 The value of the tuple's first component.
      /// @remarks You can also use the static ValueTuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      ValueTuple(const T1& item1) : tuple(std::make_tuple(item1)) {}
      /// @cond
      ValueTuple() {}
      ValueTuple(const ValueTuple& tuple) : tuple(tuple.tuple) {}
      ValueTuple(const std::tuple<T1>& tuple) : tuple(tuple) {}
      /// @endcond

      /// @brief Gets the value of the current ValueTuple <T1> object's first component.
      /// @param T1 The value of the current ValueTuple <T1> object's first component.
      property_<T1> Item1 {
        get_ {return std::get<0>(this->tuple);},
        set_ {std::get<0>(this->tuple) = value;}
      };

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const IComparable& obj) const override {return !is<ValueTuple>(obj) ? 1 : this->CompareTo((const ValueTuple&)obj);}

      /// @brief Compares the current Version object to a specified object and returns an indication of their relative values.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      ///  - Less than zero      This instance is less than obj.
      ///  - Zero                This instance is equal to obj.
      ///  - Greater than zero   This instance is greater than obj.
      int32 CompareTo(const ValueTuple& tuple) const {return System::Collections::Generic::Comparer<T1>::Default.Compare(this->Item1, tuple.Item1);}

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const Object& obj) const override {return is<ValueTuple>(obj) && this->Equals((const ValueTuple&)obj);}

      /// @brief Determines whether this instance of Version and a specified object, which must also be a Version object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const ValueTuple& tuple) const {return this->Item1 == tuple.Item1;}

      /// @brief Returns a string that represents the current object.
      /// @return string A string that represents the current object.
      string ToString() const override {return string::Format("({0})", this->Item1);}

    private:
      std::tuple<T1> tuple;
    };

    /// @brief Provides static methods for creating tuple objects.
    /// @see System::ValueTuple <T1>
    /// @see System::ValueTuple <T1, T2>
    /// @see System::ValueTuple <T1, T2, T3>
    /// @see System::ValueTuple <T1, T2, T3, T4>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7>
    /// @see System::ValueTuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    template<>
    class ValueTuple<> static_ {
    public:
      /// @brief Creates a new 8-tuple, or octuple.
      /// @param item1 The value of the first component of the tuple.
      /// @param item2 The value of the second component of the tuple.
      /// @param item3 The value of the third component of the tuple.
      /// @param item4 The value of the fourth component of the tuple.
      /// @param item5 The value of the fifth component of the tuple.
      /// @param item6 The value of the sixth component of the tuple.
      /// @param item7 The value of the seventh component of the tuple.
      /// @param item8 The value of the eighth component of the tuple.
      /// @return A 8-tuple whose value is (item1, item2, item3, item4, item5, item6, item7, item8).
      template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
      static ValueTuple<T1, T2, T3, T4, T5, T6, T7, T8> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7, T8 item8) {return ValueTuple<T1, T2, T3, T4, T5, T6, T7, T8>(item1, item2, item3, item4, item5, item6, item7, item8);}

      /// @brief Creates a new 7-tuple, or septuple.
      /// @param item1 The value of the first component of the tuple.
      /// @param item2 The value of the second component of the tuple.
      /// @param item3 The value of the third component of the tuple.
      /// @param item4 The value of the fourth component of the tuple.
      /// @param item5 The value of the fifth component of the tuple.
      /// @param item6 The value of the sixth component of the tuple.
      /// @param item7 The value of the seventh component of the tuple.
      /// @return A 7-tuple whose value is (item1, item2, item3, item4, item5, item6, item7).
      template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
      static ValueTuple<T1, T2, T3, T4, T5, T6, T7> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7) {return ValueTuple<T1, T2, T3, T4, T5, T6, T7>(item1, item2, item3, item4, item5, item6, item7);}

      /// @brief Creates a new 6-tuple, or sextuple.
      /// @param item1 The value of the first component of the tuple.
      /// @param item2 The value of the second component of the tuple.
      /// @param item3 The value of the third component of the tuple.
      /// @param item4 The value of the fourth component of the tuple.
      /// @param item5 The value of the fifth component of the tuple.
      /// @param item6 The value of the sixth component of the tuple.
      /// @return A 6-tuple whose value is (item1, item2, item3, item4, item5, item6).
      template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
      static ValueTuple<T1, T2, T3, T4, T5, T6> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6) {return ValueTuple<T1, T2, T3, T4, T5, T6>(item1, item2, item3, item4, item5, item6);}

      /// @brief Creates a new 5-tuple, or quintuple.
      /// @param item1 The value of the first component of the tuple.
      /// @param item2 The value of the second component of the tuple.
      /// @param item3 The value of the third component of the tuple.
      /// @param item4 The value of the fourth component of the tuple.
      /// @param item5 The value of the fifth component of the tuple.
      /// @return A 5-tuple whose value is (item1, item2, item3, item4, item5).
      template<typename T1, typename T2, typename T3, typename T4, typename T5>
      static ValueTuple<T1, T2, T3, T4, T5> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5) {return ValueTuple<T1, T2, T3, T4, T5>(item1, item2, item3, item4, item5);}

      /// @brief Creates a new 4-tuple, or quadruple.
      /// @param item1 The value of the first component of the tuple.
      /// @param item2 The value of the second component of the tuple.
      /// @param item3 The value of the third component of the tuple.
      /// @param item4 The value of the fourth component of the tuple.
      /// @return A 4-tuple whose value is (item1, item2, item3, item4).
      template<typename T1, typename T2, typename T3, typename T4>
      static ValueTuple<T1, T2, T3, T4> Create(T1 item1, T2 item2, T3 item3, T4 item4) {return ValueTuple<T1, T2, T3, T4>(item1, item2, item3, item4);}

      /// @brief Creates a new 3-tuple, or triple.
      /// @param item1 The value of the first component of the tuple.
      /// @param item2 The value of the second component of the tuple.
      /// @param item3 The value of the third component of the tuple.
      /// @return A 4-tuple whose value is (item1, item2, item3).
      template<typename T1, typename T2, typename T3>
      static ValueTuple<T1, T2, T3> Create(T1 item1, T2 item2, T3 item3) {return ValueTuple<T1, T2, T3>(item1, item2, item3);}

      /// @brief Creates a new 2-tuple, or pair.
      /// @param item1 The value of the first component of the tuple.
      /// @param item2 The value of the second component of the tuple.
      /// @return A 2-tuple whose value is (item1, item2).
      template<typename T1, typename T2>
      static ValueTuple<T1, T2> Create(T1 item1, T2 item2) {return ValueTuple<T1, T2>(item1, item2);}

      /// @brief Creates a new 1-tuple, or singleton.
      /// @param item1 The value of the only component of the tuple.
      /// @return A tuple whose value is (item1).
      template<typename T1>
      static ValueTuple<T1> Create(T1 item1) {return ValueTuple<T1>(item1);}
    };
  }
}

using namespace Switch;

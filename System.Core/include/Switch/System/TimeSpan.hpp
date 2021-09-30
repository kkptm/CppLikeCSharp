/// @file
/// @brief Contains Switch::System::TimeSpan struct.
#pragma once

#include "../Property.hpp"
#include "Object.hpp"
#include "../Property.hpp"
#include "../Types.hpp"
#include "_String.hpp"
#include "IComparable.hpp"
#include "Int64.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents a time interval.
    struct core_export_ TimeSpan : public object, public IComparable {
    public:
      /// @brief Represents the maximum TimeSpan value. This field is constant.
      /// @remarks The value of this field is equivalent to Int64::MaxValue ticks. The String representation of this value is positive 106751990248054775807
      static TimeSpan MaxValue;

      /// @brief Represents the minimum TimeSpan value. This field is constant.
      /// @remarks The value of this field is equivalent to Int64::MinValue ticks. The String representation of this value is negative 106751990248054775808
      static TimeSpan MinValue;

      /// @brief Represents the number of ticks in 1 day. This field is constant.
      /// @remarks The value of this constant is 864 billion; that is 864000000000.
      static constexpr int64 TicksPerDay = 864000000000LL;

      /// @brief Represents the number of ticks in 1 hour. This field is constant.
      /// @remarks The value of this constant is 36 billion; that is 36000000000.
      static constexpr int64 TicksPerHour = 36000000000LL;

      /// @brief Represents the number of ticks in 1 millisecond. This field is constant.
      /// @remarks The value of this constant is 10 thousand; that is 10000.
      static constexpr int64 TicksPerMillisecond = 10000LL;

      /// @brief Represents the number of ticks in 1 minute. This field is constant.
      /// @remarks The value of this constant is 600 million; that is 600000000.
      static constexpr int64 TicksPerMinute = 600000000LL;

      /// @brief Represents the number of ticks in 1 second. This field is constant.
      /// @remarks The value of this constant is 10 million; that is 10000000.
      static constexpr int64 TicksPerSecond = 10000000LL;

      /// @brief Represents the zero TimeSpan value. This field is constant.
      /// @remarks Because it returns a TimeSpan object that represents a zero time value, the Zero constant can be compared with other TimeSpan objects to determine whether the latter represent positive, non-zero, or negative time spans.
      static TimeSpan Zero();

      /// @brief Create a new instance of struct TimeSpan
      /// @remarks TimeSpan is initialized with default value 0.
      TimeSpan() {}

      /// @brief Create a new instance of struct TimeSpan from specified TimeSpan
      /// @param timeSpan TimeSpan to copy
      /// @exception ArgumentNullException timeSpan is null.
      TimeSpan(const TimeSpan& timeSpan);

      /// @brief Create a new instance of struct TimeSpan
      /// @param ticks A time period expressed in 100-nanosecond units
      explicit TimeSpan(int64 ticks) : value(ticks) {}

      /// @brief Create a new instance of struct TimeSpan
      /// @param hours Number of hours
      /// @param minutes Number of minutes
      /// @param seconds Number of seconds
      TimeSpan(int32 hours, int32 minutes, int32 seconds) : value((int64)hours * TicksPerHour + (int64)minutes * TicksPerMinute + (int64)seconds * TicksPerSecond) {}

      /// @brief Create a new instance of struct TimeSpan
      /// @param days Number of days
      /// @param hours Number of hours
      /// @param minutes Number of minutes
      /// @param seconds Number of seconds
      TimeSpan(int32 days, int32 hours, int32 minutes, int32 seconds) : value((int64)days * TicksPerDay + (int64)hours * TicksPerHour + (int64)minutes * TicksPerMinute + (int64)seconds * TicksPerSecond) {}

      /// @brief Create a new instance of struct TimeSpan
      /// @param days Number of days
      /// @param hours Number of hours
      /// @param minutes Number of minutes
      /// @param seconds Number of seconds
      /// @param milliseconds Number of milliseconds
      TimeSpan(int32 days, int32 hours, int32 minutes, int32 seconds, int32 milliseconds) : value((int64)days * TicksPerDay + (int64)hours * TicksPerHour + (int64)minutes * TicksPerMinute + (int64)seconds * TicksPerSecond + (int64)milliseconds * TicksPerMillisecond) {}

      /// @brief Gets the number of whole days represented by the current TimeSpan class.
      /// @return int32 The total number of days represented by this instance
      property_<int32, readonly_> Days {
        get_ {return static_cast<int32>(this->value / TimeSpan::TicksPerDay);}
      };

      /// @brief Gets the number of whole hours represented by the current TimeSpan class.
      /// @return int32 The total number of hours represented by this instance
      property_<int32, readonly_> Hours {
        get_ {return static_cast<int32>((this->value % TimeSpan::TicksPerDay) / TimeSpan::TicksPerHour);}
      };

      /// @brief Gets the number of whole milliseconds represented by the current TimeSpan class.
      /// @return int32 The total number of millisecond represented by this instance
      property_<int32, readonly_> Milliseconds {
        get_ {return static_cast<int32>(((((this->value % TimeSpan::TicksPerDay) % TimeSpan::TicksPerHour) % TicksPerMinute) % TimeSpan::TicksPerSecond) / TimeSpan::TicksPerMillisecond);}
      };

      /// @brief Gets the number of whole minutes represented by the current TimeSpan class.
      /// @return int32 The total number of minutes represented by this instance
      property_<int32, readonly_> Minutes {
        get_ {return static_cast<int32>(((this->value % TimeSpan::TicksPerDay) % TimeSpan::TicksPerHour) / TimeSpan::TicksPerMinute); }
      };

      /// @brief Gets the number of whole seconds represented by the current TimeSpan class.
      /// @return int32 The total number of seconds represented by this instance
      property_<int32, readonly_> Seconds {
        get_ {return static_cast<int32>((((this->value % TimeSpan::TicksPerDay) % TimeSpan::TicksPerHour) % TimeSpan::TicksPerMinute) / TimeSpan::TicksPerSecond);}
      };

      /// @brief Gets the number of whole tisks represented by the current TimeSpan class.
      /// @return int64 The tick component of this instance. The return value can be positive or negative
      property_<int64, readonly_> Ticks {
        get_ {return this->value;}
      };

      /// @brief Gets the value of the current TimeSpan class expressed in whole and fractional days.
      /// @return double The day component of this instance. The return value can be positive or negative
      property_<double, readonly_> TotalDays {
        get_ {return static_cast<double>(this->value) / TimeSpan::TicksPerDay;}
      };

      /// @brief Gets the value of the current TimeSpan class expressed in whole and fractional hours.
      /// @return double The hour component of this instance. The return value can be positive or negative
      property_<double, readonly_> TotalHours {
        get_ {return static_cast<double>(this->value) / TimeSpan::TicksPerHour;}
      };

      /// @brief Gets the value of the current TimeSpan class expressed in whole and fractional millisecond.
      /// @return double The millisecond component of this instance. The return value can be positive or negative
      property_<double, readonly_> TotalMilliseconds {
        get_ {return static_cast<double>(this->value) / TimeSpan::TicksPerMillisecond;}
      };

      /// @brief Gets the value of the current TimeSpan class expressed in whole and fractional minutes.
      /// @return double The minute component of this instance. The return value can be positive or negative
      property_<double, readonly_> TotalMinutes {
        get_ {return static_cast<double>(this->value) / TimeSpan::TicksPerMinute;}
      };

      /// @brief Gets the value of the current TimeSpan class expressed in whole and fractional seconds.
      /// @return double The second component of this instance. The return value can be positive or negative
      property_<double, readonly_> TotalSeconds {
        get_ {return static_cast<double>(this->value) / TimeSpan::TicksPerSecond;}
      };

      /// @brief Adds the specified TimeSpan to this instance
      /// @param value A TimeSpan to add.
      /// @return TimeSpan A TimeSpan that represents the value of this instance plus the value of value
      /// @exception ArgumentNullException value is null.
      TimeSpan Add(const TimeSpan& value) const;

      /// @brief Compares two TimeSpan values and returns an integer that indicates their relationship
      /// @param timeSpanA the first TimeSpan.
      /// @param timeSpanB the second TimeSpan.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero      timeSpanA is less than timeSpanB.
      /// Zero                timeSpanA is equal to timeSpanB.
      /// Greater than zero   timeSpanA is greater than timeSpanB.
      static int32 Compare(const TimeSpan& timeSpanA, const TimeSpan& timeSpanB);

      /// @brief Returns a new TimeSpan object whose value is the absolute value of the current TimeSpan object.
      /// @return TimeSpan A new TimeSpan whose value is the absolute value of the current TimeSpan object.
      TimeSpan Duration() const;

      /// @brief Determines whether this instance and another specified TimeSpan object have the same value.
      /// @param value The TimeSpan to compare.
      /// @return bool true if the value of this instance is the same as the value of value; otherwise, false.
      /// @exception ArgumentNullException The parameters value is null.
      bool Equals(const TimeSpan& value) const;

      /// @brief Determines whether two specified TimeSpan objects have the same value.
      /// @param timeSpanA The first TimeSpan to compare.
      /// @param timeSpanB The second TimeSpan to compare.
      /// @return bool true if the value of timeSpanA is the same as the value of timeSpanB; otherwise, false.
      /// @exception ArgumentNullException The parameters timeSpanA or timeSpanB is null.
      static bool Equals(const TimeSpan& timeSpanA, const TimeSpan& timeSpanB);

      /// @brief Returns a TimeSpan that represents a specified number of days, where the specification is accurate to the nearest millisecond.
      /// @param days A number of days, accurate to the nearest millisecond.
      /// @return TimeSpan A TimeSpan that represents days.
      static TimeSpan FromDays(double days) { return TimeSpan((int64)(days * TicksPerDay)); }

      /// @brief Returns a TimeSpan that represents a specified number of hours, where the specification is accurate to the nearest millisecond.
      /// @param hours A number of hours, accurate to the nearest millisecond.
      /// @return TimeSpan A TimeSpan that represents hours.
      static TimeSpan FromHours(double hours) { return TimeSpan((int64)(hours * TicksPerHour)); }

      /// @brief Returns a TimeSpan that represents a specified number of milliseconds, where the specification is accurate to the nearest millisecond.
      /// @param milliseconds A number of milliseconds, accurate to the nearest millisecond.
      /// @return TimeSpan A TimeSpan that represents milliseconds.
      static TimeSpan FromMilliseconds(double milliseconds);

      /// @brief Returns a TimeSpan that represents a specified number of minutes, where the specification is accurate to the nearest millisecond.
      /// @param minutes A number of minutes, accurate to the nearest millisecond.
      /// @return TimeSpan A TimeSpan that represents minutes.
      static TimeSpan FromMinutes(double minutes) { return TimeSpan((int64)(minutes * TicksPerMinute)); }

      /// @brief Returns a TimeSpan that represents a specified number of seconds, where the specification is accurate to the nearest millisecond.
      /// @param seconds A number of seconds, accurate to the nearest millisecond.
      /// @return TimeSpan A TimeSpan that represents seconds.
      static TimeSpan FromSeconds(double seconds) { return TimeSpan((int64)(seconds * TicksPerSecond)); }

      /// @brief Returns a TimeSpan that represents a specified time, where the specification is in units of ticks.
      /// @param ticks A number of ticks that represent a time.
      /// @return TimeSpan A TimeSpan with a value of ticks.
      static TimeSpan FromTicks(int64 ticks) { return TimeSpan(ticks); }

      /// @brief Returns a new TimeSpan whose value is the negated value of this instance.
      /// @return TimeSpan The same numeric value as this instance, but with the opposite sign.
      TimeSpan Negative() const { return TimeSpan(-this->value); }

      /// @brief Converts the specified String representation of a logical value to its 64-bit signed integer equivalent.
      /// @param str A String containing the value to convert.
      /// @return A TimeSpan equivalent to the number contained in str.
      /// @exception ArgumentNullException The String str is null.
      /// @exception ArgumentFormatException str is not a valid format.
      /// @remarks !!! NOT YET ENDED !!!
      static TimeSpan Parse(const String& str);

      /// @brief Subtract the specified TimeSpan to this instance
      /// @param value A TimeSpan to subtract.
      /// @return TimeSpan A TimeSpan that represents the value of this instance minus the value of value
      TimeSpan Subtract(TimeSpan value) const { return TimeSpan(this->value - value.value); }

      /// @brief Converts the specified String representation of a logical value to its 64-bit signed integer equivalent.
      /// @param str A String containing the value to convert.
      /// @param value When this method returns, contains an object that represents the time interval specified by s, or Zero if the conversion failed. This parameter is passed uninitialized.
      /// @return bool true if s was converted successfully; otherwise, false.
      /// This operation returns false if the str parameter is null, has an invalid format, represents a time interval less than MinValue() or greater than MaxValue(), or has at least one days, hours, minutes, or seconds component outside its valid range.
      static bool TryParse(const String& str, TimeSpan& value);

      /// @brief Determines whether this instance of Int64 and a specified object, which must also be a Int64 object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      /// @exception ArgumentNullException The parameters obj is null.
      bool Equals(const object& obj) const override;

      /// @brief Serves as a hash function for a particular type.
      /// @return int32 A hash code for the current object.
      int32 GetHashCode() const override;

      /// @brief Returns a String that represents the current MyObj.
      /// @return String A String that represents the current MyObj.
      String ToString() const override;

      /// @brief Compares this instance to a specified Int16 object and returns an indication of their relative values.
      /// @param value An TimeSpan object to compare with this instance.
      /// @return Int16 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      int32 CompareTo(const IComparable& obj) const override;

      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// * Less than zero      This instance is less than obj.
      /// * Zero                This instance is equal to obj.
      /// * Greater than zero   This instance is greater than obj.
      int32 CompareTo(const TimeSpan& value) const;

    private :
      int64 value = 0;

    public:
      /// @cond
      TimeSpan& operator=(const TimeSpan& value);
      TimeSpan& operator+=(const TimeSpan& value);
      TimeSpan& operator-=(const TimeSpan& value);
      TimeSpan operator+(const TimeSpan& value);
      TimeSpan operator-(const TimeSpan& value);
      TimeSpan& operator++();
      TimeSpan operator++(int);
      TimeSpan& operator--();
      TimeSpan operator--(int);
      /// @endcond
    };
  }

  inline System::TimeSpan operator"" _h(unsigned long long n) {
    return System::TimeSpan(System::TimeSpan::TicksPerHour * n);
  }

  inline System::TimeSpan operator"" _min(unsigned long long n) {
    return System::TimeSpan(System::TimeSpan::TicksPerMinute * n);
  }

  inline System::TimeSpan operator"" _ms(unsigned long long n) {
    return System::TimeSpan(System::TimeSpan::TicksPerMillisecond * n);
  }

  inline System::TimeSpan operator"" _ns(unsigned long long n) {
    return System::TimeSpan::FromTicks(n / 100);
  }

  inline System::TimeSpan operator"" _s(unsigned long long n) {
    return System::TimeSpan(System::TimeSpan::TicksPerSecond * n);
  }

  inline System::TimeSpan operator"" _us(unsigned long long n) {
    return System::TimeSpan::FromTicks(10 * n);
  }
}

using namespace Switch;

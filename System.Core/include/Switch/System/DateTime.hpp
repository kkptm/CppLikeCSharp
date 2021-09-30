/// @file
/// @brief Contains Switch::System::DateTime struct.
#pragma once

#include <limits>

#include "../Property.hpp"
#include "../Types.hpp"
#include "IComparable.hpp"
#include "IConvertible.hpp"
#include "DateTimeKind.hpp"
#include "DayOfWeek.hpp"
#include "Object.hpp"
#include "_String.hpp"
#include "TimeSpan.hpp"
#include "TypeCode.hpp"
#include "ValueType.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @struct DateTime
    /// @brief Represents an instant in time, typically expressed as a date and time of day.
    ///
    /// The DateTime value type represents dates and times with values ranging from 00:00:00 (midnight), January 1, 0001 Anno Domini (Common Era) through 11:59:59 P.M., December 31, 9999 A.D. (C.E.) in the Gregorian calendar.
    ///
    /// Time values are measured in 100-nanosecond units called ticks, and a particular date is the number of ticks since 12:00 midnight, January 1, 0001 A.D. (C.E.) in the GregorianCalendar calendar (excluding ticks that would be added by leap seconds). For example, a ticks value of 31241376000000000L represents the date, Friday, January 01, 0100 12:00:00 midnight. A DateTime value is always expressed in the context of an explicit or default calendar.
    /// @note If you are working with a ticks value that you want to convert to some other time interval, such as minutes or seconds, you should use the TimeSpan.TicksPerDay, TimeSpan.TicksPerHour, TimeSpan.TicksPerMinute, TimeSpan.TicksPerSecond, or TimeSpan.TicksPerMillisecond constant to perform the conversion. For example, to add the number of seconds represented by a specified number of ticks to the Second component of a DateTime value, you can use the expression dateValue.Second + nTicks/Timespan.TicksPerSecond.
    /// For example, a ticks value of 31241376000000000LL represents the date, Friday, January 01, 0100 12:00:00 midnight. A DateTime value is always expressed in the context of an explicit or default calendar.
    /// <b>Instantiating a DateTime object</b>
    /// You can create a new DateTime value in any of the following ways:
    ///    * By calling any of the overloads of the DateTime constructor that allow you to specify specific elements of the date and time value (such as the year, month, and day, or the number of ticks). The following statement illustrates a call to one of the DateTime constructors to create a date with a specific year, month, day, hour, minute, and second.
    /// @code
    /// DateTime date1(2008, 5, 1, 8, 30, 52);
    /// @endcode
    ///    * By assigning the DateTime object a date and time value returned by a property or method. The following example assigns the current date and time, the current Coordinated Universal Time (UTC) date and time, and the current date to three new DateTime variables.
    /// @code
    /// DateTime date1 = DateTime::Now;
    /// DateTime date2 = DateTime::UtcNow;
    /// DateTime date3 = DateTime::Today;
    /// @endcode
    ///    * By parsing the String representation of a date and time value. The Parse, ParseExact, TryParse, and TryParseExact methods all convert a String to its equivalent date and time value. The following example uses the Parse method to parse a String and convert it to a DateTime value.
    /// @code
    /// String dateString = "5/1/2008 8:30:52";
    /// DateTime date1 = DateTime::Parse(dateString);
    /// @endcode
    /// Note that the TryParse and TryParseExact methods indicate whether a particular String contains a valid representation of a DateTime value in addition to performing the conversion.
    ///    * By calling the DateTime structure's implicit default constructor. The following example illustrates a call to the DateTime implicit default constructor.
    /// @code
    /// DateTime dat1;
    /// // The following method call displays 1/01/0001 00:00:00.
    /// Console::WriteLine(dat1.ToString());
    /// // The following method call displays true.
    /// Console::WriteLine(dat1.Equals(DateTime::MinValue));
    /// @endcode
    /// @par Examples
    /// The following example demonstrates how to compare roughly equivalent DateTime values, accepting a small margin of difference when declaring them equal.
    /// @include DateTime.cpp
    struct core_export_ DateTime : public ValueType, public IComparable, public IConvertible {
    public:
      /// @brief Represents the largest possible value of an DateTime (03:14:07, Janyaury 19, 2038). This field is constant.
      static DateTime MaxValue;

      /// @brief Represents the smallest possible value of DateTime (midnight, January 1, 1). This field is constant.
      static DateTime MinValue;

      /// @brief Create a new instance of struct DateTime
      /// @remarks DateTime is initialized by default to midnight, January 1, 1.
      DateTime(const DateTime& date);

      /// @brief Create a new instance of struct DateTime
      /// @remarks DateTime is initialized by default to midnight, January 1, 1.
      DateTime();

      /// @brief Initializes a new instance of the DateTime structure to a specified number of ticks.
      /// @param ticks A date and time expressed in 100-nanosecond units.
      /// @remarks The Kind() is initialized to DateTimeKindUnspecified
      DateTime(int64 ticks);

      /// @brief Initializes a new instance of the DateTime structure to a specified number of ticks and to Coordinated Universal Time (UTC) or local time.
      /// @param ticks A date and time expressed in 100-nanosecond units.
      /// @param kind One of the DateTimeKind values that indicates whether ticks specifies a local time, Coordinated Universal Time (UTC), or neither
      DateTime(int64 ticks, DateTimeKind kind);

      /// @brief Initializes a new instance of the DateTime class to the specified year, month, and day.
      /// @param year The year (1 through 9999)
      /// @param month The month (1 through 12).
      /// @param day The day (1 through the number of days in month).
      /// @remarks The time of day for the resulting DateTime is midnight (00:00:00).
      /// @remarks The Kind() is initialized to DateTimeKindUnspecified
      DateTime(int32 year, int32 month, int32 day);

      /// @brief Initializes a new instance of the DateTime class to the specified year, month, day, hour, minute and second.
      /// @param year The year (1 through 9999)
      /// @param month The month (1 through 12).
      /// @param day The day (1 through the number of days in month).
      /// @param hour The hours (0 through 23).
      /// @param minute The minutes (0 through 59).
      /// @param second The seconds (0 through 59).
      /// @remarks The Kind() is initialized to DateTimeKindUnspecified
      DateTime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second);

      /// @brief Initializes a new instance of the DateTime class to the specified year, month, day, hour, minute, second and Coordinated Universal Time (UTC) or local time.
      /// @param year The year (1 through 9999)
      /// @param month The month (1 through 12).
      /// @param day The day (1 through the number of days in month).
      /// @param hour The hours (0 through 23).
      /// @param minute The minutes (0 through 59).
      /// @param second The seconds (0 through 59).
      /// @param kind One of the DateTimeKind values that indicates whether year, month, day, hour, minute and second specify a local time, Coordinated Universal Time (UTC), or neither.
      DateTime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, DateTimeKind kind);

      /// @brief Initializes a new instance of the DateTime class to the specified year, month, day, hour, minute, second and millisecond.
      /// @param year The year (1 through 9999)
      /// @param month The month (1 through 12).
      /// @param day The day (1 through the number of days in month).
      /// @param hour The hours (0 through 23).
      /// @param minute The minutes (0 through 59).
      /// @param second The seconds (0 through 59).
      /// @param millisecond The milliseconds (0 through 999).
      /// @remarks The Kind() is initialized to DateTimeKindUnspecified
      DateTime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, int32 millisecond);

      /// @brief Initializes a new instance of the DateTime class to the specified year, month, day, hour, minute, second, millisecond and Coordinated Universal Time (UTC) or local time.
      /// @param year The year (1 through 9999)
      /// @param month The month (1 through 12).
      /// @param day The day (1 through the number of days in month).
      /// @param hour The hours (0 through 23).
      /// @param minute The minutes (0 through 59).
      /// @param second The seconds (0 through 59).
      /// @param millisecond The milliseconds (0 through 999).
      /// @param kind One of the DateTimeKind values that indicates whether year, month, day, hour, minute and second specify a local time, Coordinated Universal Time (UTC), or neither.
      DateTime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, int32 millisecond, DateTimeKind kind);

      /// @brief Gets the date component of this instance.
      /// @param A new DateTime with the same date as this instance, and the time value set to 12:00:00 midnight (00:00:00).
      property_<DateTime, readonly_> Date {
        get_ {return DateTime(Year(), Month(), Day(), 0, 0, 0, 0, this->kind);}
      };

      /// @brief Gets the day of the month represented by this instance.
      /// @param The day component, expressed as a value between 1 and 31.
      property_<int32, readonly_> Day {
        get_ {return this->GetDay();}
      };

      /// @brief Gets the day of the week represented by this instance.
      /// @param DayOfWeek A DayOfWeek enumerated constant that indicates the day of the week. This property value ranges from zero, indicating Sunday, to six, indicating Saturday.
      property_<System::DayOfWeek, readonly_> DayOfWeek {
        get_ {return this->GetDayOfWeek();}
      };

      /// @brief Gets the day of the year represented by this instance.
      /// @param The day of the year, expressed as a value between 1 and 366.
      property_<int32, readonly_> DayOfYear {
        get_ {return this->GetDayOfYear();}
      };

      /// @brief Gets the hour component of the date represented by this instance.
      /// @param The hour component, expressed as a value between 0 and 23.
      property_<int32, readonly_> Hour {
        get_ {return this->GetHour();}
      };

      /// @brief Gets a value that indicates whether the time represented by this instance is based on local time, Coordinated Universal Time (UTC), or neither.
      /// @return DateTimeKind One of the DateTimeKind values. The default is DateTimeKindUnspecified.
      property_<DateTimeKind, readonly_> Kind {
        get_ {return this->GetKind();}
      };

      /// @brief Gets the millisecond component of the date represented by this instance.
      /// @return The millisecond component, expressed as a value between 0 and 999.
      property_<int32, readonly_> Millisecond {
        get_ {return this->GetMillisecond();}
      };

      /// @brief Gets the minute component of the date represented by this instance.
      /// @return The minute component, expressed as a value between 0 and 59.
      property_<int32, readonly_> Minute {
        get_ {return this->GetMinute();}
      };

      /// @brief Gets the month component of the date represented by this instance.
      /// @return The month component, expressed as a value between 1 and 12.
      property_<int32, readonly_> Month {
        get_ {return this->GetMonth();}
      };

      /// @brief Gets a DateTime object that is set to the current date and time on this computer, expressed as the local time.
      /// @return DateTime A DateTime object that is set to the current date and time on this computer
      static DateTime Now();

      /// @brief Gets the second component of the date represented by this instance.
      /// @return The second component, expressed as a value between 0 and 59.
      property_<int32, readonly_> Second {
        get_ {return this->GetSecond();}
      };

      /// @brief Gets the number of ticks component of the date represented by this instance.
      /// @return The number of ticks that represent the date and time of this instance. The value is between DateTime::MinValue and DateTime::MaxValue.
      property_<int64, readonly_> Ticks {
        get_ {return this->GetTicks();}
      };

      /// @brief Gets the time of day for this instance.
      /// @return TimeSpan A TimeSpan that represents the fraction of the day that has elapsed since midnight.
      /// @remarks The return value is a DateTime whose Kind property returns DateTimeKindLocal.
      property_<TimeSpan, readonly_> TimeOfDay {
        get_ {return this->GetTimeOfDay();}
      };

      /// @brief Gets the current date.
      /// @return DateTime A DateTime set to today's date, with the time component set to 00:00:00.
      /// @remarks The return value is a DateTime whose Kind property returns DateTimeKindLocal.
      static DateTime Today();

      /// @brief Gets a DateTime object that is set to the current date and time on this computer, expressed as the universal time.
      /// @return DateTime A DateTime object that is set to the current date and time on this computer
      static DateTime UtcNow();

      /// @brief Gets the year component of the date represented by this instance.
      /// @return The year component, expressed as a value between 1 and 9999.
      property_<int32, readonly_> Year {
        get_ {return this->GetYear();}
      };

      /// @brief Adds the value of the specified TimeSpan to the value of this instance.
      /// @param value A TimeSpan that contains the interval to add
      /// @return DateTime A DateTime whose value is the sum of the date and time represented by this instance and the time interval represented by value.
      /// @remarks This method does not change the value of this DateTime. Instead, a new DateTime is returned whose value is the result of this operation.
      DateTime Add(TimeSpan value) const { return DateTime(this->value + value.Ticks(), this->kind); }

      /// @brief Adds the specified number of days to the value of this instance.
      /// @param value A number of whole and fractional days. The value parameter can be negative or positive.
      /// @return DateTime A DateTime whose value is the sum of the date and time represented by this instance and the number of days represented by value.
      /// @remarks This method does not change the value of this DateTime. Instead, a new DateTime is returned whose value is the result of this operation.
      DateTime AddDays(double value) const { return DateTime(this->value + (int64)(value * TimeSpan::TicksPerDay), this->kind); }

      /// @brief Adds the specified number of hours to the value of this instance.
      /// @param value A number of whole and fractional hours. The value parameter can be negative or positive.
      /// @return DateTime A DateTime whose value is the sum of the date and time represented by this instance and the number of hours represented by value.
      /// @remarks This method does not change the value of this DateTime. Instead, a new DateTime is returned whose value is the result of this operation.
      DateTime AddHours(double value) const { return DateTime(this->value + (int64)(value * TimeSpan::TicksPerHour), this->kind); }

      /// @brief Adds the specified number of milliseconds to the value of this instance.
      /// @param value A number of whole and fractional milliseconds. The value parameter can be negative or positive.
      /// @return DateTime A DateTime whose value is the sum of the date and time represented by this instance and the number of milliseconds represented by value.
      /// @remarks This method does not change the value of this DateTime. Instead, a new DateTime is returned whose value is the result of this operation.
      DateTime AddMilliseconds(double value) const { return DateTime(this->value + (int64)(value * TimeSpan::TicksPerMillisecond), this->kind); }

      /// @brief Adds the specified number of minutes to the value of this instance.
      /// @param value A number of whole and fractional minutes. The value parameter can be negative or positive.
      /// @return DateTime A DateTime whose value is the sum of the date and time represented by this instance and the number of minutes represented by value.
      /// @remarks This method does not change the value of this DateTime. Instead, a new DateTime is returned whose value is the result of this operation.
      DateTime AddMinutes(double value) const { return DateTime(this->value + (int64)(value * TimeSpan::TicksPerMinute), this->kind); }

      /// @brief Adds the specified number of months to the value of this instance.
      /// @param value A number of whole and fractional months. The value parameter can be negative or positive.
      /// @return DateTime A DateTime whose value is the sum of the date and time represented by this instance and the number of months represented by value.
      /// @remarks This method does not change the value of this DateTime. Instead, a new DateTime is returned whose value is the result of this operation.
      /// @remarks !!! NOT YET ENDED !!!
      DateTime AddMonths(double value) const { return DateTime(this->value + (int64)(value * TimeSpan::TicksPerDay * 31), this->kind); }

      /// @brief Adds the specified number of seconds to the value of this instance.
      /// @param value A number of whole and fractional seconds. The value parameter can be negative or positive.
      /// @return DateTime A DateTime whose value is the sum of the date and time represented by this instance and the number of seconds represented by value.
      /// @remarks This method does not change the value of this DateTime. Instead, a new DateTime is returned whose value is the result of this operation.
      DateTime AddSeconds(double value) const { return DateTime(this->value + (int64)(value * TimeSpan::TicksPerSecond), this->kind); }

      /// @brief Adds the specified number of ticks to the value of this instance.
      /// @param value A number of ticks. The value parameter can be negative or positive.
      /// @return DateTime A DateTime whose value is the sum of the date and time represented by this instance and the number of ticks represented by value.
      /// @remarks This method does not change the value of this DateTime. Instead, a new DateTime is returned whose value is the result of this operation.
      DateTime AddTicks(int64 value) const { return DateTime(this->value + value, this->kind); }

      /// @brief Adds the specified number of years to the value of this instance.
      /// @param value A number of whole and fractional years. The value parameter can be negative or positive.
      /// @return DateTime A DateTime whose value is the sum of the date and time represented by this instance and the number of years represented by value.
      /// @remarks This method does not change the value of this DateTime. Instead, a new DateTime is returned whose value is the result of this operation.
      /// @remarks !!! NOT YET ENDED !!!
      DateTime AddYears(double value) const { return DateTime(this->value + (int64)(value * TimeSpan::TicksPerDay * 365), this->kind); }

      /// @brief Compares two instances of DateTime and returns an indication of their relative values
      /// @param dateTimeA The first DateTime.
      /// @param dateTimeB The second DateTime.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero      dateTimeA is less than dateTimeB.
      /// Zero                dateTimeA is equal to dateTimeB.
      /// Greater than zero   dateTimeA is greater than dateTimeB.
      /// @remarks Before comparing DateTime objects, insure that the objects represent times in the same time zone.
      static int32 Compare(const DateTime& dateTimeA, const DateTime& dateTimeB) {
        return dateTimeA.CompareTo(dateTimeB);
      }

      /// @brief Returns the number of days in the specified month and year.
      /// @param year The year.
      /// @param month The month (a number ranging from 1 to 12).
      /// @return Int32 The number of days in month for the specified year.
      /// For example, if month equals 2 for February, the return value is 28 or 29 depending upon whether year is a leap year.
      /// @exception ArgumentOutOfRangeException month is less than 1 or greater than 12.
      static int32 DaysInMonth(int32 year, int32 month);

      /// @brief Determines whether two specified DateTime objects have the same value.
      /// @param dateTimeA The first DateTime to compare.
      /// @param dateTimeB The second DateTime to compare.
      /// @return Boolean true if the value of dateTimenA is the same as the value of dateTimeB; otherwise, false.
      static bool Equals(const DateTime& dateTimeA, const DateTime& dateTimeB) {
        return dateTimeA.Equals(dateTimeB);
      }

      /// @brief Deserializes a 64-bit binary value and recreates an original serialized DateTime object.
      /// @param dateData A 64-bit signed integer that encodes the Kind property in a 2-bit field and the Ticks property in a 62-bit field.
      /// @return DateTime A DateTime object that is equivalent to the DateTime object that was serialized by the ToBinary method.
      static DateTime FromBinary(int64 dateData) {return DateTime(dateData & 0x3FFFFFFFFFFFFFFFLL, (DateTimeKind)(int32)(((dateData & 0xC000000000000000LL) >> 62) & 0x0000000000000003LL));}

      /// @brief Converts the specified Windows file time to an equivalent local time.
      /// @param fileTime A Windows file time expressed in ticks.
      /// @return DateTime A DateTime object that represents a local time equivalent to the date and time represented by the fileTime parameter.
      /// @remarks A Windows file time is a 64-bit value that represents the number of second intervals that have elapsed since 12:00 midnight, January 1, 1 Coordinated Local Time.
      /// @remarks Windows uses a file time to record when an application creates, accesses, or writes to a file.
      /// @remarks The fileTime parameter specifies a file time expressed in seconds.
      /// @remarks The return value is a DateTime whose Kind() function is DateTimeKindLocal.
      static DateTime FromFileTime(int64 fileTime);

      /// @brief Converts the specified Windows file time to an equivalent universal time.
      /// @param fileTime A Windows file time expressed in ticks.
      /// @return DateTime A DateTime object that represents a universal time equivalent to the date and time represented by the fileTime parameter.
      /// @remarks A Windows file time is a 64-bit value that represents the number of 100-nanosecond intervals that have elapsed since 12:00 midnight, January 1, 1601 A.D. (C.E.) Coordinated Universal Time (UTC).
      /// @remarks Windows uses a file time to record when an application creates, accesses, or writes to a file.
      /// @remarks The fileTime parameter specifies a file time expressed in 100-nanosecond ticks.
      /// @remarks The return value is a DateTime whose Kind() function is DateTimeKindUtc.
      static DateTime FromFileTimeUtc(int64 fileTime);

      /// @brief Indicates whether this instance of DateTime is within the Daylight Saving Time range for the current time zone.
      /// @return Boolean true if Kind is Local or Unspecified and the value of this instance of DateTime is within the Daylight Saving Time range for the current time zone. false if Kind is Utc.
      bool IsDaylightSavingTime() const;

      /// @brief Returns an indication whether the specified year is a leap year.
      /// @param year A 4-digit year.
      /// @return Boolean true if year is a leap year; otherwise, false.
      static bool IsLeapYear(int32 year) { return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0); }

      /// @brief Converts the specified String representation of a logical value to its DateTime equivalent.
      /// @param str A String containing the value to convert.
      /// @return A DateTime equivalent to the number contained in str.
      /// @exception ArgumentNullException The parameters str is null.
      /// @remarks !!! NOT YET ENDED !!!
      static DateTime Parse(const String& str);

      /// @brief Creates a new DateTime object that represents the same time as the specified DateTime, but is designated in either local time, Coordinated Universal Time (UTC), or neither, as indicated by the specified DateTimeKind value.
      /// @param value A DateTime object.
      /// @param kind One of the DateTimeKind values.
      /// @return DateTime A new DateTime object consisting of the same time represented by the value parameter and the DateTimeKind value specified by the kind parameter.
      /// @remarks !!! NOT YET ENDED !!!
      /// @remarks A DateTime object consists of a Kind field that indicates whether the time value is based on local time, Coordinated Universal Time (UTC), or neither, and a Ticks field that contains a time value measured in 100-nanosecond ticks. The SpecifyKind method creates a new DateTime object using the specified kind parameter and the original time value.
      /// @remarks The SpecifyKind method is useful in interoperability scenarios where you receive a DateTime object with an unspecified Kind field, but you can determine by independent means that the Ticks field represents local time or UTC.
      /// @par Examples
      /// The following example uses the SpecifyKind method to demonstrate how the Kind property influences the ToLocalTime and ToUniversalTime conversion methods.
      /// @include DateTimeSpecifyKind.cpp
      static DateTime SpecifyKind(DateTime value, DateTimeKind kind);

      /// @brief Subtracts the specified date and time from this instance.
      /// @param value An instance of DateTime.
      /// @return TimeSpan A TimeSpan interval equal to the date and time represented by this instance minus the date and time represented by value.
      /// @remarks This method does not change the value of this DateTime object. Instead, a new TimeSpan is returned whose value is the result of this operation.
      /// @remarks Before subtracting DateTime objects, insure that the objects represent times in the same time zone. Otherwise, the result will include the difference between time zones.
      const TimeSpan Subtract(const DateTime& value) const { return TimeSpan(this->value - value.value); }

      /// @brief Subtracts the specified duration from this instance.
      /// @param value An instance of TimeSpan.
      /// @return DateTime A DateTime equal to the date and time represented by this instance minus the time interval represented by value.
      /// @remarks This method does not change the value of this DateTime. Instead, a new DateTime is returned whose value is the result of this operation.
      DateTime Subtract(const TimeSpan& value) const { return DateTime(this->value - value.Ticks()); }

      /// @brief Serializes the current DateTime object to a 64-bit binary value that subsequently can be used to recreate the DateTime object.
      /// @return Int64 A 64-bit signed integer that encodes the Kind and Ticks properties.
      /// @remarks Use the ToBinary method to convert the value of the current DateTime object to a binary value. Subsequently, use the binary value and the FromBinary method to recreate the original DateTime object.
      int64 ToBinary() const {return (this->value & 0x3FFFFFFFFFFFFFFFLL) + (((int64)this->kind << 62) & 0xC000000000000000LL);}

      /// @brief Converts the value of the current DateTime object to local time.
      /// @return DateTime A DateTime object whose Kind() property is DateTimeKindLocal, and whose value is the local time equivalent
      /// to the value of the current DateTime object, or MaxValue if the converted value is too large to be represented by a DateTime object,
      /// or MinValue if the converted value is too small to be represented as a DateTime object.
      /// @remarks The value returned by the ToLocalTime method is determined by the Kind property of the current DateTime object.
      /// @remarks The following table describes the possible results.
      /// @remarks Kind                      Results
      /// @remarks DateTimeKindUtc           This instance of DateTime is converted to local time.
      /// @remarks DateTimeKindLocal         No conversion is performed.
      /// @remarks DateTimeKindUnspecified   This instance of DateTime is assumed to be a UTC time, and the conversion is performed as if Kind were Utc.
      /// @par Examples
      /// The following example uses the SpecifyKind method to demonstrate how the Kind property influences the ToLocalTime and ToUniversalTime conversion methods.
      /// @include DateTimeSpecifyKind.cpp
      DateTime ToLocalTime() const;

      /// @brief Converts the value of the current DateTime object to its equivalent long date String representation.
      /// @return String A String that contains the long date String representation of the current DateTime object.
      const String ToLongDateString() const;

      /// @brief Converts the value of the current DateTime object to its equivalent long time String representation.
      /// @return String A String that contains the long time String representation of the current DateTime object.
      const String ToLongTimeString() const;

      /// @brief Converts the value of the current DateTime object to its equivalent short date String representation.
      /// @return String A String that contains the short date String representation of the current DateTime object.
      const String ToShortDateString() const;

      /// @brief Converts the value of the current DateTime object to its equivalent short time String representation.
      /// @return String A String that contains the short time String representation of the current DateTime object.
      const String ToShortTimeString() const;

      /// @brief Converts the value of the current DateTime object to universal time.
      /// @return DateTime A DateTime object whose Kind() property is DateTimeKindUtc, and whose value is the universal time equivalent
      /// to the value of the current DateTime object, or MaxValue if the converted value is too large to be represented by a DateTime object,
      /// or MinValue if the converted value is too small to be represented as a DateTime object.
      /// @remarks The value returned by the ToUniversalTime method is determined by the Kind property of the current DateTime object.
      /// @remarks The following table describes the possible results.
      /// @remarks Kind                      Results
      /// @remarks DateTimeKindUtc           No conversion is performed.
      /// @remarks DateTimeKindLocal         This instance of DateTime is converted to universal time.
      /// @remarks DateTimeKindUnspecified   The current DateTime object is assumed to be a local time, and the conversion is performed as if Kind were Local.
      /// @par Examples
      /// The following example uses the SpecifyKind method to demonstrate how the Kind property influences the ToLocalTime and ToUniversalTime conversion methods.
      /// @include DateTimeSpecifyKind.cpp
      DateTime ToUniversalTime() const;

      /// @brief Determines whether this instance and another specified DateTime object have the same value.
      /// @param value The DateTime to compare.
      /// @return bool true if the value of this instance is the same as the value of value; otherwise, false.
      /// @exception ArgumentNullException The parameters value is null.
      bool Equals(const DateTime& value) const;

      /// @brief Determines whether this instance of DateTime and a specified object, which must also be a DateTime object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      /// @exception ArgumentNullException The parameters obj is null.
      bool Equals(const object& obj) const override;

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current object.
      int32 GetHashCode() const override;

      /// @brief Returns a String that represents the current DateTime.
      /// @return String A String that represents the current DateTime.
      String ToString() const override;

      /// @brief Returns a String that represents the current DateTime.
      /// @param format Format-control String.
      /// @return String A String that represents the current DateTime.
      /// @remarks The formatting codes for strftime are listed below:
      /// | Format | Print                                                                                                                       |
      /// |--------|-----------------------------------------------------------------------------------------------------------------------------|
      /// | %a     | Abbreviated weekday name.                                                                                                   |
      /// | %A     | Full weekday name.                                                                                                          |
      /// | %b     | Abbreviated month name.                                                                                                     |
      /// | %B     | Full month name.                                                                                                            |
      /// | %c     | Date and time representation appropriate for locale.                                                                        |
      /// | %d     | Day of month as decimal number (01 -> 31).                                                                                  |
      /// | %H     | Hour in 24-hour format (00 -> 23).                                                                                          |
      /// | %I     | Hour in 12-hour format (01 -> 12).                                                                                          |
      /// | %j     | Day of year as decimal number (001 -> 366).                                                                                 |
      /// | %m     | Month as decimal number (01 -> 12).                                                                                         |
      /// | %M     | Minute as decimal number (00 -> 59).                                                                                        |
      /// | %p     | Current locale's A.M./P.M. indicator for 12-hour clock.                                                                     |
      /// | %S     | Second as decimal number (00 -> 59).                                                                                        |
      /// | %U     | Week of year as decimal number, with Sunday as first day of week (00 -> 53).                                                |
      /// | %w     | Weekday as decimal number (0 -> 6; Sunday is 0).                                                                            |
      /// | %W     | Week of year as decimal number, with Monday as first day of week (00 -> 53).                                                |
      /// | %x     | Date representation for current locale.                                                                                     |
      /// | %X     | Time representation for current locale.                                                                                     |
      /// | %y     | Year without century, as decimal number (00 -> 99).                                                                         |
      /// | %Y     | Year with century, as decimal number.                                                                                       |
      /// | %z, %Z | Either the time-zone name or time zone abbreviation, depending on registry settings; no characters if time zone is unknown. |
      /// | %%     | Percent sign.                                                                                                               |
      String ToString(const String& format) const;

      /// @brief Compares this instance to a specified DateTime object and returns an indication of their relative values.
      /// @param value An DateTime object to compare with this instance.
      /// @return DateTime A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      /// @remarks Before comparing DateTime objects, make sure that the objects represent times in the same time zone. You can do this by comparing the values of their Kind() Function.
      int32 CompareTo(const DateTime& value) const;

      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return DateTime A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// @return Less than zero      This instance is less than value.
      /// @return Zero                This instance is equal to value.
      /// @return Greater than zero   This instance is greater than value.
      /// -or-
      /// @return obj is nullNothingnullptra null reference.
      /// @remarks Before comparing DateTime objects, make sure that the objects represent times in the same time zone. You can do this by comparing the values of their Kind() function.
      int32 CompareTo(const IComparable& obj) const override;

      /// @brief Returns the TypeCode for this instance.
      /// @return TypeCode The enumerated constant that is the TypeCode of the class or value type that implements this interface.
      /// @return @see TypeCode
      TypeCode GetTypeCode() const override;

    private:
      friend class Convert;
      int32 GetDay() const;
      System::DayOfWeek GetDayOfWeek() const;
      int32 GetDayOfYear() const;
      int32 GetHour() const;
      DateTimeKind GetKind() const;
      int32 GetMillisecond() const;
      int32 GetMinute() const ;
      int32 GetMonth() const;
      int32 GetSecond() const;
      int64 GetTicks() const;
      TimeSpan GetTimeOfDay() const;
      int32 GetYear() const;

      void SetDateTime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, int32 millisecond, DateTimeKind kind);
      void GetDateTime(int32& year, int32& month, int32& day, int32& hour, int32& minute, int32& second, int32& dayOfYear, int32& dayOfWeek) const;
      bool ToBoolean(const IFormatProvider& provider) const override;
      byte ToByte(const IFormatProvider& provider) const override;
      char32 ToChar(const IFormatProvider& provider) const override;
      DateTime ToDateTime(const IFormatProvider& provider) const override;
      double ToDouble(const IFormatProvider& provider) const override;
      int16 ToInt16(const IFormatProvider& provider) const override;
      int32 ToInt32(const IFormatProvider& provider) const override;
      int64 ToInt64(const IFormatProvider& provider) const override;
      uint16 ToUInt16(const IFormatProvider& provider) const override;
      uint32 ToUInt32(const IFormatProvider& provider) const override;
      uint64 ToUInt64(const IFormatProvider& provider) const override;
      sbyte ToSByte(const IFormatProvider& provider) const override;
      float ToSingle(const IFormatProvider& provider) const override;
      String ToString(const IFormatProvider& provider) const override;

      int64 value = 0;
      DateTimeKind kind = DateTimeKind::Unspecified;

    public:
      /// @cond
      operator TimeSpan() const {return TimeSpan(this->value);}

      DateTime& operator =(const DateTime& value) {
        this->value = value.value;
        this->kind = value.kind;
        return *this;
      }

      DateTime& operator+=(DateTime value) {
        this->value += value.value;
        return *this;
      }

      DateTime& operator-=(DateTime value) {
        this->value -= value.value;
        return *this;
      }

      DateTime operator+() { return DateTime(+this->value, this->kind); }

      DateTime operator-() { return DateTime(-this->value, this->kind); }

      DateTime operator+(const DateTime& value) const {
        DateTime result = *this;
        result.value += value.value;
        return result;
      }

      DateTime operator-(const DateTime& value) const {
        DateTime result = *this;
        result.value -= value.value;
        return result;
      }

      DateTime& operator++() {
        ++this->value;
        return *this;
      }

      DateTime operator++(int) { return DateTime(this->value++, this->kind); }

      DateTime& operator--() {
        --this->value;
        return *this;
      }

      DateTime operator--(int) { return DateTime(this->value--, this->kind); }
      /// @endcond
    };

  }
}

using namespace Switch;

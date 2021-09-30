/// @file
/// @brief Contains Switch::System::Random class.
#pragma once

#include "../Types.hpp"
#include "Array.hpp"
#include "Object.hpp"
#include "Convert.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents a pseudo-random number generator, a device that produces a sequence of numbers that meet certain statistical requirements for randomness.
    /// @remarks Pseudo-random numbers are chosen with equal probability from a finite set of numbers. The chosen numbers are not completely random because a definite mathematical algorithm is used to select them, but they are sufficiently random for practical purposes. The current implementation of the Random class is based on Donald E. Knuth's subtractive random number generator algorithm. For more information, see D. E. Knuth. "The Art of Computer Programming, volume 2: Seminumerical Algorithms". Addison-Wesley, Reading, MA, second edition, 1981.
    /// @remarks The random number generation starts from a seed value. If the same seed is used repeatedly, the same series of numbers is generated. One way to produce different sequences is to make the seed value time-dependent, thereby producing a different series with each new instance of Random. By default, the parameterless constructor of the Random class uses the system clock to generate its seed value, while its parameterized constructor can take an Int32 value based on the number of ticks in the current time. However, because the clock has finite resolution, using the parameterless constructor to create different Random objects in close succession creates random number generators that produce identical sequences of random numbers. The following example illustrates that two Random objects that are instantiated in close succession generate an identical series of random numbers.
    /// @include Random1.cpp
    /// @remarks This problem can be avoided by creating a single Random object rather than multiple ones.
    /// @remarks To improve performance, create one Random object to generate many random numbers over time, instead of repeatedly creating a new Random objects to generate one random number.
    /// @remarks To generate a cryptographically secure random number suitable for creating a random password, for example, use a class derived from System::Security::Cryptography.RandomNumberGenerator such as System::Security::Cryptography.RNGCryptoServiceProvider.
    /// @par Notes to Callers
    /// The implementation of the random number generator in the Random class is not guaranteed to remain the same across major versions of the Switch. As a result, your application code should not assume that the same seed will result in the same pseudo-random sequence in different versions of the Switch.
    /// @par Notes to Inheritors
    /// In Switch, the behavior of the Random.Next(), Random::Next(int32, int32), and NextBytes methods have changed so that these methods do not necessarily call the derived class implementation of the Sample method. As a result, classes derived from Random that target the Switch should also virtual these three methods.
    /// @par Examples
    /// The following example creates a single random number generator and calls its NextBytes, Next, and NextDouble methods to generate sequences of random numbers within different ranges.
    /// @include Random2.cpp
    /// @par Examples
    /// The following example generates a random integer that it uses as an index to retrieve a string value from an array.
    /// @include Random3.cpp
    class core_export_ Random : public Object {
    public:
      /// @brief Initializes a new instance of the Random class, using a time-dependent default seed value
      Random();

      /// @brief Initializes a new instance of the Random class, using a time-dependent default seed value.
      /// @param seed A number used to calculate a starting value for the pseudo-random number sequence. If a negative number is specified, the absolute value of the number is used.
      /// @exception OverflowException seed is Int32::MinValue, which causes an overflow when its absolute value is calculated.
      Random(int32 seed);

      /// @brief Returns a nonnegative random number.
      /// @return Int32 A 32-bit signed integer greater than or equal to zero and less than Int32::MaxValue
      virtual int32 Next() const {return Next(0, Int32::MaxValue);}

      /// @brief Returns a nonnegative random number less than the specified maximum.
      /// @param maxValue The exclusive upper bound of the random number to be generated. maxValue must be greater than or equal to zero.
      /// @return Int32 A 32-bit signed integer greater than or equal to zero and less than maxValue
      /// @exception ArgumentOutOfRangeException maxValue is less than zero.
      /// @remarks The Next(Int32) overload returns random integers that range from 0 to maxValue – 1. However, if maxValue is 0, the method returns 0.
      virtual int32 Next(int32 maxValue) const {return Next(0, maxValue);}

      /// @brief Returns a random number within a specified range.
      /// @param minValue The inclusive lower bound of the random number returned
      /// @param maxValue The exclusive upper bound of the random number returned. maxValue must be greater than or equal to minValue.
      /// @return Int32 A 32-bit signed integer greater than or equal to minValue and less than maxValue
      /// @exception ArgumentOutOfRangeException minValue is greater than maxValue.
      /// @remarks The Next(iInt32, int32) overload returns random integers that range from minValue to maxValue – 1. However, if maxValue equals minValue, the method returns minValue.
      /// @remarks Unlike the other overloads of the Next method, which return only non-negative values, this method can return a negative random integer.
      virtual int32 Next(int32 minValue, int32 maxValue) const;

      /// @brief Fills the elements of a specified array of bytes with random numbers.
      /// @param buffer An array of bytes to contain random numbers.
      /// @exception ArgumentNullException buffer is null.
      /// @remarks Each element of the array of bytes is set to a random number greater than or equal to zero, and less than or equal to Byte::MaxValue.
      virtual void NextBytes(Array<byte>& buffer) const {
        for (int32 i = 0; i < buffer.Length; i++)
          buffer[i] = Convert::ToByte(Next(0, Byte::MaxValue + 1));
      }

      /// @brief Returns a random number between 0.0 and 1.0
      /// @return Double A double-precision floating point number greater than or equal to 0.0, and less than 1.0.
      /// @remarks This method is the public version of the protected method, Sample
      virtual double NextDouble() const {return Sample();}

    protected:
      /// @brief Returns a random number between 0.0 and 1.0
      /// @return Double A double-precision floating point number greater than or equal to 0.0, and less than 1.0.
      /// @remarks To produce a different random distribution or a different random number generator principle, derive a class from the Random class and virtual the Sample method.
      virtual double Sample() const;
    };
  }
}

using namespace Switch;

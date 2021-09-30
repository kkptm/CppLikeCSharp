#if defined(_WIN32)

#include <windows.h>
#include "../../include/Switch/Undef.hpp"

#include "Api.hpp"

int32 Native::InterlockedApi::Add(int32& location, int32 value) {
  InterlockedExchange((long*)&location, location + value);
  return location;
}

int64 Native::InterlockedApi::Add(int64& location, int64 value) {
  InterlockedExchange64((long long*)&location, location + value);
  return location;
}

int32 Native::InterlockedApi::CompareExchange(int32& location, int32 value, int32 comparand) {
  return InterlockedCompareExchange((long*)&location, value, comparand);
}

int64 Native::InterlockedApi::CompareExchange(int64& location, int64 value, int64 comparand) {
  return InterlockedCompareExchange64((long long*)&location, value, comparand);
}

llong Native::InterlockedApi::CompareExchange(llong& location, llong value, llong comparand) {
  return InterlockedCompareExchange((llong*)&location, value, comparand);
}

#pragma warning(push)
#pragma warning(disable:4302)
#pragma warning(disable:4311)
#pragma warning(disable:4312)
void* Native::InterlockedApi::CompareExchange(void*& location, void* value, void* comparand) {
  if (sizeof(void*) == 4)
    return (void*)InterlockedCompareExchange((long*)&location, (long)value, (long)comparand);
  return (void*)InterlockedCompareExchange64((long long*)&location, (long long)value, (long long)comparand);
}
#pragma warning(pop)

int32 Native::InterlockedApi::Decrement(int32& location) {
  return InterlockedDecrement((long*)&location);
}

int64 Native::InterlockedApi::Decrement(int64& location) {
  return InterlockedDecrement64((long long*)&location);
}

int32 Native::InterlockedApi::Exchange(int32& location, int32 value) {
  return InterlockedExchange((long*)&location, value);
}

int64 Native::InterlockedApi::Exchange(int64& location, int64 value) {
  return InterlockedExchange64((long long*)&location, value);
}

llong Native::InterlockedApi::Exchange(llong& location, llong value) {
  return InterlockedExchange((llong*)&location, value);
}

#pragma warning(push)
#pragma warning(disable:4302)
#pragma warning(disable:4311)
#pragma warning(disable:4312)
void* Native::InterlockedApi::Exchange(void*& location, void* value) {
  if (sizeof(void*) == 4)
    return (void*)InterlockedExchange((long*)&location, (long)value);
  return (void*)InterlockedExchange64((long long*)&location, (long long)value);
}
#pragma warning(pop)

int32 Native::InterlockedApi::Increment(int32& location) {
  return InterlockedIncrement((long*)&location);
}

int64 Native::InterlockedApi::Increment(int64& location) {
  return InterlockedIncrement64((long long*)&location);
}

#endif

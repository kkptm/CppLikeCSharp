#if defined(__linux__) || defined(__APPLE__)

#include "Api.hpp"

int32 Native::InterlockedApi::Add(int32& location, int32 value) {
  __sync_fetch_and_add(&location, value);
  return location;
}

int64 Native::InterlockedApi::Add(int64& location, int64 value) {
  __sync_fetch_and_add(&location, value);
  return location;
}

int32 Native::InterlockedApi::CompareExchange(int32& location, int32 value, int32 comparand) {
  return __sync_val_compare_and_swap(&location, comparand, value);
}

int64 Native::InterlockedApi::CompareExchange(int64& location, int64 value, int64 comparand) {
  return __sync_val_compare_and_swap(&location, comparand, value);
}

llong Native::InterlockedApi::CompareExchange(llong& location, llong value, llong comparand) {
  return __sync_val_compare_and_swap(&location, comparand, value);
}

void* Native::InterlockedApi::CompareExchange(void*& location, void* value, void* comparand) {
  return __sync_val_compare_and_swap(&location, comparand, value);
}

int32 Native::InterlockedApi::Decrement(int32& location) {
  __sync_fetch_and_sub(&location, 1);
  return location;
}

int64 Native::InterlockedApi::Decrement(int64& location) {
  __sync_fetch_and_sub(&location, 1);
  return location;
}

int32 Native::InterlockedApi::Exchange(int32& location, int32 value) {
  return __sync_val_compare_and_swap(&location, location, value);
}

int64 Native::InterlockedApi::Exchange(int64& location, int64 value) {
  return __sync_val_compare_and_swap(&location, location, value);
}

llong Native::InterlockedApi::Exchange(llong& location, llong value) {
  return __sync_val_compare_and_swap(&location, location, value);
}

void* Native::InterlockedApi::Exchange(void*& location, void* value) {
  return __sync_val_compare_and_swap(&location, location, value);
}

int32 Native::InterlockedApi::Increment(int32& location) {
  __sync_fetch_and_add(&location, 1);
  return location;
}

int64 Native::InterlockedApi::Increment(int64& location) {
  __sync_fetch_and_add(&location, 1);
  return location;
}

#endif

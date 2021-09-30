#include "../../../../include/Switch/System/Threading/Mutex.hpp"
#include "NamedHandleCollection.hpp"

using namespace System;
using namespace System::Threading;

namespace {
  NamedHandleCollection<Mutex> mutexes;
}

Mutex::Mutex(bool initiallyOwned, const string& name) {
  bool createdNew = true;
  if (name != "")
    this->operator=(mutexes.AddOrCreate(name, createdNew));
  if (createdNew) {
    *this->name = name;
    if (initiallyOwned)
      this->WaitOne();
  }
}

Mutex::Mutex(bool initiallyOwned, const string& name, bool& createdNew) {
  createdNew = true;
  if (name != "")
    this->operator=(mutexes.AddOrCreate(name, createdNew));
  if (createdNew) {
    *this->name = name;
    if (initiallyOwned)
      this->WaitOne();
  }
}

void Mutex::Close() {
  if (this->mutex == null)
    return;
  if (*this->name != "")
    mutexes.Remove(*this->name);
  this->name.Reset();
  this->mutex.Reset();
}

Mutex Mutex::OpenExisting(const string& name) {
  if (!mutexes.Conatains(name))
    throw WaitHandleCannotBeOpenedException(caller_);
  bool createNew;
  Mutex value = mutexes.AddOrCreate(name, createNew);
  return value;
}

bool Mutex::TryOpenExisting(const string& name, Mutex& result) {
  if (!mutexes.Conatains(name))
    return false;
  bool createNew;
  result = mutexes.AddOrCreate(name, createNew);
  return true;
}

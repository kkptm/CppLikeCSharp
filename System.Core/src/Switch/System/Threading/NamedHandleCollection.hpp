#pragma once
#include <map>
#include "../../../../include/Switch/System/String.hpp"

namespace {
  template<typename T>
  class NamedHandleCollection {
    struct NamedHandleCountPair {
      NamedHandleCountPair() : handle(T()), count(1) {}
      T handle;
      int32 count = 0;
    };
  public:
    NamedHandleCollection() {}

    bool Conatains(const string& name) {return this->handles.find(name) != this->handles.end();}

    const T& AddOrCreate(const string& name, bool& createNew) {
      std::lock_guard<std::recursive_mutex> lock(this->guard);
      typename std::map<string, NamedHandleCountPair>::iterator iterator = this->handles.find(name);
      createNew = iterator == this->handles.end();
      if (createNew)
        this->handles[name] = NamedHandleCountPair();
      else
        this->handles[name].count++;
      return this->handles[name].handle;
    }

    bool Remove(const string& name) {
      std::lock_guard<std::recursive_mutex> lock(this->guard);
      typename std::map<string, NamedHandleCountPair>::iterator iterator = this->handles.find(name);
      if (iterator == this->handles.end())
        return false;
      if (--this->handles[name].count != 0)
        return false;
      this->handles.erase(name);
      return true;
    }

  private:
    std::map<string, NamedHandleCountPair> handles;
    std::recursive_mutex guard;
  };
}

#include "../../../../include/Switch/System/Net/IPHostEntry.hpp"

using namespace System;
using namespace System::Net;

const Array<IPAddress>& IPHostEntry::GetAddressList() const {
  return this->addresses;
}

const Array<string>& IPHostEntry::GetAliases() const {
  return this->aliases;
}

const string& IPHostEntry::GetHostName() const {
  return this->hostName;
}


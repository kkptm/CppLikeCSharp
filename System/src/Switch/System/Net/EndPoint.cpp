#include "../../../../include/Switch/System/Net/EndPoint.hpp"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

refptr<EndPoint> EndPoint::Create(const SocketAddress&) const {
  throw NotSupportedException(caller_);
}

string EndPoint::ToString() const {
  return Enum<Sockets::AddressFamily>(this->addressFamily).ToString();
}

SocketAddress EndPoint::Serialize() const {
  return SocketAddress(this->addressFamily, 2);
}


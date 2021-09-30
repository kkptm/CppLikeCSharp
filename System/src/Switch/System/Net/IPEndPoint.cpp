#include "../../../../include/Switch/System/Net/IPEndPoint.hpp"

#include <Switch/System/BitConverter.hpp>
#include <Switch/System/Convert.hpp>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

property_<int32, readonly_> IPEndPoint::MinPort {
  [] {return 0;}
};

property_<int32, readonly_> IPEndPoint::MaxPort {
  [] {return 0xFFFF;}
};

IPEndPoint::IPEndPoint(int64 address, int32 port) {
  SetAddress(IPAddress(address));
  SetPort(port);
}

IPEndPoint::IPEndPoint(const IPAddress& address, int32 port) {
  SetAddress(address);
  SetPort(port);
}

refptr<EndPoint> IPEndPoint::Create(const SocketAddress& socketAddress) const {
  refptr<IPEndPoint> endPoint = ref_new<IPEndPoint>(0, 0);

  endPoint->addressFamily = socketAddress.GetAddressFamily();
  endPoint->port = IPAddress::NetworkToHostOrder(BitConverter::ToUInt16(socketAddress.bytes, 2));
  endPoint->address = IPAddress(socketAddress[4], socketAddress[5], socketAddress[6], socketAddress[7]);
  if (endPoint->addressFamily != Sockets::AddressFamily::InterNetwork)
    endPoint->address.ScopeId = IPAddress::NetworkToHostOrder(BitConverter::ToInt64(socketAddress.bytes, 8));
  return endPoint;
}

SocketAddress IPEndPoint::Serialize() const {
  Array<byte> addressBytes = this->Address().GetAddressBytes();
  Array<byte> portByes =  BitConverter::GetBytes(IPAddress::HostToNetworkOrder(Convert::ToUInt16(this->port)));
  SocketAddress socketAddress(this->addressFamily, addressBytes.Length + 8 + 4);
  int32 index = 2;
  for (byte b : portByes)
    socketAddress[index++] = b;
  for (byte b : addressBytes)
    socketAddress[index++] = b;

  if (AddressFamily != Sockets::AddressFamily::InterNetwork) {
    Array<byte> scopeIdBytes = BitConverter::GetBytes(IPAddress::HostToNetworkOrder(this->address.ScopeId));
    for (byte b : scopeIdBytes)
      socketAddress[index++] = b;
  }
  return socketAddress;
}

void IPEndPoint::SetAddress(const IPAddress& address) {
  this->addressFamily = address.AddressFamily;
  this->address = address;
}

void IPEndPoint::SetPort(int32 port) {
  if (port < MinPort || port > MaxPort)
    throw ArgumentOutOfRangeException(caller_);

  this->port = port;
}

string IPEndPoint::ToString() const {
  return string::Format("{0}:{1}", this->address, this->port);
}


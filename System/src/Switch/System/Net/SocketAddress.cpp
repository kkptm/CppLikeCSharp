#include "../../../../include/Switch/System/Net/SocketAddress.hpp"

#include "../../../../include/Switch/System/Net/IPAddress.hpp"
#include <Switch/System/BitConverter.hpp>
#include <Switch/System/Convert.hpp>
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

SocketAddress::SocketAddress(Sockets::AddressFamily addressFamily, int32 bufferSize) : bytes(bufferSize) {
  this->bytes[0] = (byte)Native::SocketApi::AddressFamilyToNative(addressFamily);
  this->bytes[1] = 0;
}

SocketAddress::SocketAddress(const Array<byte>& buffer) : bytes(buffer) {}

Sockets::AddressFamily SocketAddress::GetAddressFamily() const {
  return Native::SocketApi::NativeToAddressFamily(this->bytes[0]);
}

string SocketAddress::ToString() const {
  return string::Format("{0}:{1}:{{{2}}}", this->GetAddressFamily(), this->Size, string::Join(",", this->bytes, 2, this->Size - 2));
}


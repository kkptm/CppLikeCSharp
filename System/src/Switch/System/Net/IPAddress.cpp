#include <cstring>

#include "../../../../include/Switch/System/Net/IPAddress.hpp"

#include <Switch/RefPtr.hpp>
#include <Switch/Using.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/BitConverter.hpp>
#include <Switch/System/Buffer.hpp>
#include "../../../../include/Switch/System/Net/Sockets/SocketException.hpp"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

property_<IPAddress, readonly_> IPAddress::Any {
  [] {return IPAddress(0x0000000000000000LL);}
};

property_<IPAddress, readonly_> IPAddress::Broadcast {
  [] {return IPAddress(0x00000000FFFFFFFFLL);}
};

property_<IPAddress, readonly_> IPAddress::IPv6Any {
  [] {return IPAddress(Array<byte> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});}
};

property_<IPAddress, readonly_> IPAddress::IPv6Loopback {
  [] {return IPAddress(Array<byte> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1});}
};

property_<IPAddress, readonly_> IPAddress::IPv6None {
  [] {return IPAddress(Array<byte> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});}
};

property_<IPAddress, readonly_> IPAddress::Loopback {
  [] {return IPAddress(0x000000000100007FLL);}
};

property_<IPAddress, readonly_> IPAddress::None {
  [] {return IPAddress(0x00000000FFFFFFFFLL);}
};

IPAddress::IPAddress() {
}

IPAddress::IPAddress(int64 address) {
  if (address < 0 || address > 0x0000000FFFFFFFFLL)
    throw ArgumentOutOfRangeException(caller_);

  this->address = Convert::ToUInt32(address);
}

IPAddress::IPAddress(const IPAddress& address) {
  this->address = address.address;
  this->numbers = address.numbers;
  this->scopeId = address.scopeId;
  this->family = address.family;
}

IPAddress& IPAddress::operator =(const IPAddress& address) {
  this->address = address.address;
  this->numbers = address.numbers;
  this->scopeId = address.scopeId;
  this->family = address.family;
  return *this;
}

IPAddress::IPAddress(const Array<byte>& address) {
  if (address.Length != 4 && address.Length != 16)
    throw ArgumentException(caller_);

  if (address.Length == 4) {
    this->family = Sockets::AddressFamily::InterNetwork;
    this->address = BitConverter::ToUInt32(address, 0);
  }

  if (address.Length == 16) {
    this->family = Sockets::AddressFamily::InterNetworkV6;
    Buffer::BlockCopy(address, 0, this->numbers, 0, 16);
  }
}

IPAddress::IPAddress(const std::vector<byte>& address) {
  if (address.size() != 4 && address.size() != 16)
    throw ArgumentException(caller_);

  if (address.size() == 4) {
    this->family = Sockets::AddressFamily::InterNetwork;
    this->address = Convert::ToInt32(address[0]) + (Convert::ToInt32(address[1]) << 8) + (Convert::ToInt32(address[2]) << 16) + (Convert::ToInt32(address[3]) << 24);
  }

  if (address.size() == 16) {
    this->family = Sockets::AddressFamily::InterNetworkV6;
    for (int i = 0; i < 8; i++)
      this->numbers[i] = Convert::ToUInt16(address[i * 2]) + (Convert::ToUInt16(address[(i * 2) + 1]) << 8);
  }
}

IPAddress::IPAddress(const Array<byte>& address, int64 scopeId) : family(Sockets::AddressFamily::InterNetworkV6) {
  if (address.Length != 16)
    throw ArgumentException(caller_);

  if (scopeId < 0 || scopeId > 0x00000000FFFFFFFFLL)
    throw ArgumentOutOfRangeException(caller_);

  this->scopeId = Convert::ToUInt32(scopeId);
  Buffer::BlockCopy(address, 0, this->numbers, 0, 16);
}

IPAddress::IPAddress(byte quadPartAddress1, byte quadPartAddress2, byte quadPartAddress3, byte quadPartAddress4) : address(BitConverter::ToInt32( {quadPartAddress1, quadPartAddress2, quadPartAddress3, quadPartAddress4}, 0)) {
}

bool IPAddress::Equals(const IPAddress& value) const {
  if (!(this->address == value.address && this->scopeId == value.scopeId && this->family == value.family))
    return false;

  for (int32 i = 0; i < this->numbers.Length; i++)
    if (this->numbers[i] != value.numbers[i])
      return false;

  return true;
}

bool IPAddress::Equals(const object& obj) const {
  return is<IPAddress>(obj) && Equals(static_cast<const IPAddress&>(obj));
}

Array<byte> IPAddress::GetAddressBytes() const {
  if (this->family == Sockets::AddressFamily::InterNetwork)
    return BitConverter::GetBytes(this->address);

  //Array<byte> addressBytes(16);
  //Buffer::BlockCopy(this->numbers, 0, addressBytes, 0, 16);
  //return addressBytes;

  System::Collections::Generic::List<byte> bytes;
  for (auto number : this->numbers)
    bytes.AddRange(BitConverter::GetBytes(number));
  return bytes.ToArray();
}

void IPAddress::GetAddressBytes(byte& quadPartAddress1, byte& quadPartAddress2, byte& quadPartAddress3, byte& quadPartAddress4) const {
  Array<byte> addressBytes = BitConverter::GetBytes(int32(this->address));
  quadPartAddress1 = addressBytes[0];
  quadPartAddress2 = addressBytes[1];
  quadPartAddress3 = addressBytes[2];
  quadPartAddress4 = addressBytes[3];
}

AddressFamily IPAddress::GetAddressFamily() const {
  return this->family;
}

int32 IPAddress::GetHashCode() const {
  if (this->family == Sockets::AddressFamily::InterNetwork)
    return Int64(this->address).GetHashCode();

  int32 hash = 0;
  for (uint16 item : this->numbers)
    hash ^= int32(item);
  return hash;
}

int64 IPAddress::GetScopeId() const {
  if (this->family == Sockets::AddressFamily::InterNetwork)
    throw SocketException(caller_);

  return this->scopeId;
}

double IPAddress::HostToNetworkOrder(double host) {
  return BitConverter::Int64BitsToDouble(HostToNetworkOrder(BitConverter::DoubleToInt64Bits(host)));
}

int16 IPAddress::HostToNetworkOrder(int16 host) {
  return int16(HostToNetworkOrder(uint16(host)));
}

int32 IPAddress::HostToNetworkOrder(int32 host) {
  return int32(HostToNetworkOrder(uint32(host)));
}

int64 IPAddress::HostToNetworkOrder(int64 host) {
  return int64(HostToNetworkOrder(uint64(host)));
}

float IPAddress::HostToNetworkOrder(float host) {
  return BitConverter::Int32BitsToSingle(HostToNetworkOrder(BitConverter::SingleToInt32Bits(host)));
}

uint16 IPAddress::HostToNetworkOrder(uint16 host) {
  if (BitConverter::IsLittleEndian == false)
    return host;

  return (host >> 8) | (host << 8);
}

uint32 IPAddress::HostToNetworkOrder(uint32 host) {
  if (BitConverter::IsLittleEndian == false)
    return host;

  return (host >> 24) | ((host << 8) & 0x00FF0000L) | ((host >> 8) & 0x0000FF00L) | (host << 24);
}

uint64 IPAddress::HostToNetworkOrder(uint64 host) {
  if (BitConverter::IsLittleEndian == false)
    return host;

  return (host >> 56) | ((host << 40) & 0x00FF000000000000LL) | ((host << 24) & 0x0000FF0000000000LL) | ((host << 8) & 0x000000FF00000000LL) | ((host >> 8) & 0x00000000FF000000LL) | ((host >> 24) & 0x0000000000FF0000LL) | ((host >> 40) & 0x000000000000FF00LL) | (host << 56);
}

bool IPAddress::GetIsIPv6LinkLocal() const {
  if (this->family == Sockets::AddressFamily::InterNetwork)
    return false;
  int32 num = int32(NetworkToHostOrder(int16(this->numbers[0]))) & 0xFFF0;
  return 0xFE80 <= num && num <= 0xFEC0;
}

bool IPAddress::GetIsIPv6Multicast() const {
  return this->family != Sockets::AddressFamily::InterNetwork && (NetworkToHostOrder(int16(this->numbers[0])) & 0xFF00) == 0xFF00;
}

bool IPAddress::GetIsIPv6SiteLocal() const {
  if (this->family == Sockets::AddressFamily::InterNetwork)
    return false;
  int32 num = int32(NetworkToHostOrder(int16(this->numbers[0]))) & 0xFFF0;
  return 0xFEC0 <= num && num <= 0xFF00;
}

bool IPAddress::IsLoopback(const IPAddress& address) {
  if (address.family == Sockets::AddressFamily::InterNetwork)
    return byte(address.address & 0x00000000000000FF) == 0x7F;

  for (int32 i = 0; i < 6; i++) {
    if (address.numbers[i] != 0)
      return false;
  }
  return NetworkToHostOrder(int16(address.numbers[7])) == 1;
}

double IPAddress::NetworkToHostOrder(double network) {
  return HostToNetworkOrder(network);
}

int16 IPAddress::NetworkToHostOrder(int16 network) {
  return HostToNetworkOrder(network);
}

int32 IPAddress::NetworkToHostOrder(int32 network) {
  return HostToNetworkOrder(network);
}

int64 IPAddress::NetworkToHostOrder(int64 network) {
  return int64(NetworkToHostOrder(uint64(network)));
}

float IPAddress::NetworkToHostOrder(float network) {
  return HostToNetworkOrder(network);
}

uint16 IPAddress::NetworkToHostOrder(uint16 network) {
  return HostToNetworkOrder(network);
}

uint32 IPAddress::NetworkToHostOrder(uint32 network) {
  return HostToNetworkOrder(network);
}

uint64 IPAddress::NetworkToHostOrder(uint64 network) {
  return HostToNetworkOrder(network);
}

IPAddress IPAddress::Parse(const string& str) {
  string workIpString = ((str[0] == '[' && str[str.Length() - 1] == ']') ? str.Substring(1, str.Length() - 2) : str);

  // Parse IP v4 Address
  using_(Array<String> addressParts = workIpString.Split('.')) {
    if (addressParts.Length == 4) {
      Array<byte> addresses(4);
      for (int32 index = 0; index < addressParts.Length; index++)
        addresses[index] = Byte::Parse(addressParts[index]);
      return IPAddress(addresses);
    }
  }

  // Parse Scope Id
  IPAddress value;
  if (workIpString.IndexOf('%') != -1) {
    value.scopeId = UInt32::Parse(workIpString.Substring(workIpString.IndexOf('%') + 1));
    workIpString = workIpString.Remove(workIpString.IndexOf('%'));
  };

  // Parse IP v6 Address
  using_(Array<String> addressParts = workIpString.Split(':')) {
    if (addressParts.Length == 8) {
      for (int32 index = 0; index < addressParts.Length; index++)
        value.numbers[index] = UInt16::Parse(addressParts[index]);
      return value;
    }
  }

  throw ArgumentException(caller_);
}

void IPAddress::SetScopeId(int64 scopeId) {
  if (this->family == Sockets::AddressFamily::InterNetwork)
    throw SocketException(caller_);

  if (scopeId < 0 || scopeId > 0xFFFFFFFF)
    throw ArgumentOutOfRangeException(caller_);

  this->scopeId = Convert::ToUInt32(scopeId);
}

string IPAddress::ToString() const {
  if (this->family == Sockets::AddressFamily::InterNetwork)
    return String::Join(".", GetAddressBytes());

  string str = "[";
  for (uint16 number : this->numbers)
    str += string::Format("{0:x}:", NetworkToHostOrder(number));
  str = str.Remove(str.Length() - 1, 1);
  if (this->scopeId != 0)
    str += string::Format("%{0}", this->scopeId);
  str += "]";
  return str;
}

bool IPAddress::TryParse(const string& str, IPAddress& address) {
  try {
    address = Parse(str);
  } catch (...) {
    return false;
  }

  return true;
}


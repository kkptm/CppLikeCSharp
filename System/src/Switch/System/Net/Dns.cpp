#include "../../../../include/Switch/System/Net/Dns.hpp"
#include "../../../Native/Api.hpp"

using namespace System::Net;
using namespace System::Net::Sockets;

namespace {
  class Hostent {
  public:
    Hostent() {Native::DnsApi::SetHostent(true);}
    ~Hostent() {Native::DnsApi::EndHostent();}
  };
}

System::Array<IPAddress> Dns::GetHostAddresses(const string& hostNameOrAddress) {
  IPHostEntry hostEntry = GetHostEntry(hostNameOrAddress);
  return hostEntry.addresses;
}

IPHostEntry Dns::GetHostEntry(const IPAddress& address) {
  return GetHostEntry(address.ToString());
}

IPHostEntry Dns::GetHostEntry(const string& hostNameOrAddress) {
  Hostent hostent;
  IPAddress address;
  intptr host;
  if (IPAddress::TryParse(hostNameOrAddress, address) == false) {
    host = Native::DnsApi::GetHostByName(hostNameOrAddress);
    if (host == 0)
      throw InvalidOperationException(caller_);
  } else {
    host = Native::DnsApi::GetHostByAddress(address.ToString(), address.AddressFamily());
    if (host == 0)
      throw InvalidOperationException(caller_);
  }
  IPHostEntry hostEntry(Native::DnsApi::GetAddresses(host), Native::DnsApi::GetAliases(host), Native::DnsApi::GetHostName(host));
  Native::DnsApi::Destroy(host);
  return hostEntry;
}

string Dns::GetHostName() {
  Hostent hotent;
  string hostName;
  if (Native::DnsApi::GetHostName(hostName) != 0)
    throw InvalidOperationException(caller_);
  return hostName;
}

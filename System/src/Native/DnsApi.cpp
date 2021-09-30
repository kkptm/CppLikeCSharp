#if defined(_WIN32)
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <ws2tcpip.h>
#include <mutex>
#include <Switch/Undef.hpp>
#else
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#endif
#include "Api.hpp"

namespace {
  std::mutex mutex;
  using Hostent = hostent;
  #if defined(_WIN32) || defined(__ANDROID__)
  void sethostent(int) {}
  void endhostent() {}
  #endif
}

void Native::DnsApi::Destroy(intptr host) {
  delete (Hostent*)host;
}

void Native::DnsApi::EndHostent() {
  endhostent();
}

intptr Native::DnsApi::GetHostByAddress(const string& hostAddress, System::Net::Sockets::AddressFamily hostAddressType) {
  std::lock_guard<std::mutex> lock(mutex);
  int64 internetAddress;
  inet_pton((int)hostAddressType, hostAddress.Data(), &internetAddress);
  Hostent* host = gethostbyaddr((char*)&internetAddress, hostAddressType == System::Net::Sockets::AddressFamily::InterNetwork ? 4 : 16, (int)hostAddressType);
  if (host == null)
    return 0;
  return (intptr)new Hostent(*host);
}

intptr Native::DnsApi::GetHostByName(const string& hostName) {
  std::lock_guard<std::mutex> lock(mutex);
  Hostent* host = gethostbyname(hostName.Data());
  if (host == null)
    return 0;
  return (intptr)new Hostent(*host);
}

System::Array<string> Native::DnsApi::GetAliases(intptr host) {
  int32 index = 0;
  System::Collections::Generic::List<string> aliases;
  while (((Hostent*)host)->h_aliases[index] != null)
    aliases.Add(((Hostent*)host)->h_aliases[index++]);
  return aliases.ToArray();
}

System::Array<System::Net::IPAddress> Native::DnsApi::GetAddresses(intptr host) {
  int32 index = 0;
  System::Collections::Generic::List<System::Net::IPAddress> addresses;
  while (((Hostent*)host)->h_addr_list[index] != null)
    addresses.Add(System::Net::IPAddress(System::Array<byte>((const byte*)((Hostent*)host)->h_addr_list[index++], (System::Net::Sockets::AddressFamily)((Hostent*)host)->h_addrtype == System::Net::Sockets::AddressFamily::InterNetwork ? 4 : 16)));
  return addresses.ToArray();
}

string Native::DnsApi::GetHostName(intptr host) {
  return ((Hostent*)host)->h_name;
}

int Native::DnsApi::GetHostName(string& hostName) {
  char host[1024];
  int result =  gethostname(host, 1024);
  hostName = host;
  return result;
}

void Native::DnsApi::SetHostent(bool stayOpen) {
  sethostent(stayOpen);
}

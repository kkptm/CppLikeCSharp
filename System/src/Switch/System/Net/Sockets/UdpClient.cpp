#include "../../../../../include/Switch/System/Net/Sockets/UdpClient.hpp"

#include <Switch/System/Convert.hpp>
#include <Switch/System/NullReferenceException.hpp>
#include "../../../../../include/Switch/System/Net/Dns.hpp"
#include "../../../../../include/Switch/System/Net/Sockets/IPv6MulticastOption.hpp"
#include "../../../../../include/Switch/System/Net/Sockets/MulticastOption.hpp"

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

UdpClient::UdpClient() {
  this->client = ref_new<Socket>(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);
}

UdpClient::UdpClient(AddressFamily addressFamily) {
  this->client = ref_new<Socket>(addressFamily, SocketType::Dgram, ProtocolType::Udp);
}

UdpClient::UdpClient(int32 port) {
  this->client = ref_new<Socket>(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);
  this->client->Bind(IPEndPoint(IPAddress::Any, port));
}

UdpClient::UdpClient(const IPEndPoint& endPoint) {
  this->client = ref_new<Socket>(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);
  this->client->Bind(endPoint);
}

UdpClient::UdpClient(int32 port, AddressFamily addressFamily) {
  this->client = ref_new<Socket>(addressFamily, SocketType::Dgram, ProtocolType::Udp);

  // Retrieve local IPAddress and use the 1st one
  this->client->Bind(IPEndPoint(Dns::GetHostAddresses(Dns::GetHostName())[0], port));
}

UdpClient::UdpClient(const string& hostname, int32 port) {
  this->client = ref_new<Socket>(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);
  Connect(hostname, port);
}

int32 UdpClient::GetAvailable() const {
  if (this->client == null)
    throw NullReferenceException(caller_);

  return this->client->Available();
}

refptr<Socket> UdpClient::GetClient() {
  return this->client;
}

const refptr<Socket> UdpClient::GetClient() const {
  return this->client;
}

bool UdpClient::GetConnected() const {
  if (this->client == null)
    throw NullReferenceException(caller_);

  return this->client->Connected();
}

void UdpClient::SetClient(const refptr<Socket>& client) {
  this->client = client;
}

bool UdpClient::GetDontFragment() const {
  if (this->client == null)
    throw NullReferenceException(caller_);

  return this->client->DontFragment();
}

void UdpClient::SetDontFragment(bool dontFragment) {
  if (this->client == null)
    throw NullReferenceException(caller_);

  this->client->DontFragment = dontFragment;
}

bool UdpClient::GetEnableBroadcast() const {
  if (this->client == null)
    throw NullReferenceException(caller_);

  return this->client->EnableBroadcast();
}

void UdpClient::SetEnableBroadcast(bool enableBroadcast) {
  if (this->client == null)
    throw NullReferenceException(caller_);

  this->client->EnableBroadcast = enableBroadcast;
}

bool UdpClient::GetExclusiveAddressUse() const {
  if (this->client == null)
    throw NullReferenceException(caller_);

  return this->client->ExclusiveAddressUse();
}

void UdpClient::SetExclusiveAddressUse(bool exclusiveAddressUse) {
  if (this->client == null)
    throw NullReferenceException(caller_);

  this->client->ExclusiveAddressUse = exclusiveAddressUse;
}

bool UdpClient::GetMulticastLoopback() const {
  if (this->client == null)
    throw NullReferenceException(caller_);

  return this->client->MulticastLoopback();
}

void UdpClient::SetMulticastLoopback(bool multicastLoopback) {
  if (this->client == null)
    throw NullReferenceException(caller_);

  this->client->MulticastLoopback = multicastLoopback;
}

int32 UdpClient::GetTtl() const {
  if (this->client == null)
    throw NullReferenceException(caller_);

  return this->client->Ttl();
}

void UdpClient::SetTtl(int32 ttl) {
  if (this->client == null)
    throw NullReferenceException(caller_);

  this->client->Ttl = ttl;
}

void UdpClient::Close() {
  if (this->client == null)
    throw NullReferenceException(caller_);

  this->client->Close();
}

void UdpClient::Connect(const IPEndPoint& endPoint) {
  if (this->client == null)
    throw NullReferenceException(caller_);

  this->client->Connect(endPoint);
}

void UdpClient::Connect(const IPAddress& ipAddress, int32 port) {
  if (this->client == null)
    throw NullReferenceException(caller_);

  this->client->Connect(ipAddress, port);
}

void UdpClient::Connect(const string& hostname, int32 port) {
  if (this->client == null)
    throw NullReferenceException(caller_);

  // Use the 1st IPAddress corresponding to the hostname
  this->client->Connect(Dns::GetHostAddresses(hostname)[0], port);
}

void UdpClient::JoinMulticastGroup(const IPAddress& multicastAddress) {
  if (this->client->AddressFamily() == AddressFamily::InterNetwork)
    this->client->SetSocketOption(SocketOptionLevel::IP, SocketOptionName::AddMembership, MulticastOption(multicastAddress));
  else
    this->client->SetSocketOption(SocketOptionLevel::IPv6, SocketOptionName::AddMembership, IPv6MulticastOption(multicastAddress));
}

void UdpClient::JoinMulticastGroup(int32 ifIndex, const IPAddress& multicastAddress) {
  if (this->client->AddressFamily() == AddressFamily::InterNetworkV6)
    this->client->SetSocketOption(SocketOptionLevel::IPv6, SocketOptionName::AddMembership, IPv6MulticastOption(multicastAddress, Convert::ToInt64(ifIndex)));
  else
    throw SocketException((int32)SocketError::OperationNotSupported, caller_);
}

void UdpClient::JoinMulticastGroup(const IPAddress& multicastAddress, int32 /*ttl*/) {

}

void UdpClient::JoinMulticastGroup(const IPAddress& multicastAddress, const IPAddress& localAddress) {

}

int32 UdpClient::Receive(Array<byte>& buffer, IPEndPoint& endPoint) {
  if (this->client == null)
    throw NullReferenceException(caller_);

  return this->client->ReceiveFrom(buffer, endPoint);
}

int32 UdpClient::Send(const Array<byte>& data) {
  if (this->client == null)
    throw NullReferenceException(caller_);
  if (!GetConnected())
    throw SocketException((int32)SocketError::NotConnected, caller_);

  return this->client->Send(data);
}

int32 UdpClient::Send(const Array<byte>& data, const IPEndPoint& endPoint) {
  if (this->client == null)
    throw NullReferenceException(caller_);
  if (GetConnected())
    throw InvalidOperationException(caller_);

  if (endPoint.Address() == IPAddress::Broadcast)
    this->client->EnableBroadcast = true;

  return this->client->SendTo(data, endPoint);
}

int32 UdpClient::Send(const Array<byte>& data, const string& hostname, int32 port) {
  if (this->client == null)
    throw NullReferenceException(caller_);
  if (GetConnected())
    throw InvalidOperationException(caller_);

  if (hostname == IPAddress::Broadcast().ToString()) {
    // hostname can be 255.255.255.255
    this->client->EnableBroadcast = true;
    return this->client->SendTo(data, IPEndPoint(IPAddress::Broadcast, port));
  } else {
    // Use the 1st IPAddress corresponding to the hostname
    return this->client->SendTo(data, IPEndPoint(Dns::GetHostAddresses(hostname)[0], port));
  }
}


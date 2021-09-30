#if defined(_WIN32)

#include <cstring>
#include <cstdlib>

#include <Winsock2.h>
#include <Switch/Undef.hpp>

#include "Api.hpp"
#include <Switch/System/Collections/Generic/SortedDictionary.hpp>

namespace {
  static int32 ProtocolTypeToNative(System::Net::Sockets::ProtocolType protocolType) {
    static System::Collections::Generic::SortedDictionary<System::Net::Sockets::ProtocolType, int32> protocolTypes = { { System::Net::Sockets::ProtocolType::Unknown, IPPROTO_IP }, { System::Net::Sockets::ProtocolType::IP, IPPROTO_IP }, { System::Net::Sockets::ProtocolType::Icmp, IPPROTO_ICMP }, { System::Net::Sockets::ProtocolType::Igmp, IPPROTO_IGMP }, { System::Net::Sockets::ProtocolType::Ggp, IPPROTO_GGP }, { System::Net::Sockets::ProtocolType::IPv4, IPPROTO_IPV4 }, { System::Net::Sockets::ProtocolType::Tcp, IPPROTO_TCP }, { System::Net::Sockets::ProtocolType::Pup, IPPROTO_PUP }, { System::Net::Sockets::ProtocolType::Udp, IPPROTO_UDP }, { System::Net::Sockets::ProtocolType::Idp, IPPROTO_IDP }, { System::Net::Sockets::ProtocolType::IPv6, IPPROTO_IPV6 }, { System::Net::Sockets::ProtocolType::IPv6RoutingHeader, IPPROTO_ROUTING }, { System::Net::Sockets::ProtocolType::IPv6FragmentHeader, IPPROTO_FRAGMENT }, { System::Net::Sockets::ProtocolType::IPSecEncapsulatingSecurityPayload, IPPROTO_ESP }, { System::Net::Sockets::ProtocolType::IPSecAuthenticationHeader, IPPROTO_AH }, { System::Net::Sockets::ProtocolType::IcmpV6, IPPROTO_ICMPV6 }, { System::Net::Sockets::ProtocolType::IPv6NoNextHeader, IPPROTO_NONE }, { System::Net::Sockets::ProtocolType::IPv6DestinationOptions, IPPROTO_DSTOPTS }, { System::Net::Sockets::ProtocolType::ND, IPPROTO_ND }, { System::Net::Sockets::ProtocolType::Raw, IPPROTO_RAW }, { System::Net::Sockets::ProtocolType::Spx, IPPROTO_IP }, { System::Net::Sockets::ProtocolType::SpxII, IPPROTO_IP } };

    if (!protocolTypes.ContainsKey(protocolType))
      return (int32)protocolType;
    return protocolTypes[protocolType];
  }

  static int32 SocketOptionNameToNative(System::Net::Sockets::SocketOptionName socketOptionName) {
    static System::Collections::Generic::SortedDictionary<System::Net::Sockets::SocketOptionName, int32> socketOptionNames = {{System::Net::Sockets::SocketOptionName::Debug, SO_DEBUG}, {System::Net::Sockets::SocketOptionName::AcceptConnection, SO_ACCEPTCONN}, {System::Net::Sockets::SocketOptionName::ReuseAddress, SO_REUSEADDR}, {System::Net::Sockets::SocketOptionName::KeepAlive, SO_KEEPALIVE}, {System::Net::Sockets::SocketOptionName::DontRoute, SO_DONTROUTE}, {System::Net::Sockets::SocketOptionName::Broadcast, SO_BROADCAST}, {System::Net::Sockets::SocketOptionName::UseLoopback, SO_USELOOPBACK}, {System::Net::Sockets::SocketOptionName::Linger, SO_LINGER}, {System::Net::Sockets::SocketOptionName::OutOfBandInline, SO_OOBINLINE}, {System::Net::Sockets::SocketOptionName::SendBuffer, SO_SNDBUF}, {System::Net::Sockets::SocketOptionName::ReceiveBuffer, SO_RCVBUF}, {System::Net::Sockets::SocketOptionName::SendLowWater, SO_SNDLOWAT}, {System::Net::Sockets::SocketOptionName::ReceiveLowWater, SO_RCVLOWAT}, {System::Net::Sockets::SocketOptionName::SendTimeout, SO_SNDTIMEO}, {System::Net::Sockets::SocketOptionName::ReceiveTimeout, SO_RCVTIMEO}, {System::Net::Sockets::SocketOptionName::Error, SO_ERROR}, {System::Net::Sockets::SocketOptionName::Type, SO_TYPE}};

    if (!socketOptionNames.ContainsKey(socketOptionName))
      return (int32)socketOptionName;
    return socketOptionNames[socketOptionName];
  }

  static int32 SocketOptionLevelToNative(System::Net::Sockets::SocketOptionLevel socketOptionLevel) {
    static System::Collections::Generic::SortedDictionary<System::Net::Sockets::SocketOptionLevel, int32> socketOptionLevels = {{System::Net::Sockets::SocketOptionLevel::Socket, SOL_SOCKET}, {System::Net::Sockets::SocketOptionLevel::IP, SOL_SOCKET}, {System::Net::Sockets::SocketOptionLevel::IPv6, SOL_SOCKET}, {System::Net::Sockets::SocketOptionLevel::Tcp, SOL_SOCKET}, {System::Net::Sockets::SocketOptionLevel::Udp, SOL_SOCKET}};

    if (!socketOptionLevels.ContainsKey(socketOptionLevel))
      return (int32)socketOptionLevel;
    return socketOptionLevels[socketOptionLevel];
  }

  static int32 SocketTypeToNative(System::Net::Sockets::SocketType socketType) {
    static System::Collections::Generic::SortedDictionary<System::Net::Sockets::SocketType, int32> socketTypes = {{System::Net::Sockets::SocketType::Unknown, SOCK_STREAM}, {System::Net::Sockets::SocketType::Stream, SOCK_STREAM}, {System::Net::Sockets::SocketType::Dgram, SOCK_DGRAM}, {System::Net::Sockets::SocketType::Raw, SOCK_RAW}, {System::Net::Sockets::SocketType::Rdm, SOCK_RDM}, {System::Net::Sockets::SocketType::Seqpacket, SOCK_SEQPACKET}};

    if (!socketTypes.ContainsKey(socketType))
      return (int32)socketType;
    return socketTypes[socketType];
  }
}

int32 Native::SocketApi::AddressFamilyToNative(System::Net::Sockets::AddressFamily addressFamily) {
  static System::Collections::Generic::SortedDictionary<System::Net::Sockets::AddressFamily, int32> addressFamilies = {{System::Net::Sockets::AddressFamily::Unknown, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Unspecified, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Unix, AF_UNIX}, {System::Net::Sockets::AddressFamily::InterNetwork, AF_INET}, {System::Net::Sockets::AddressFamily::ImpLink, AF_IMPLINK}, {System::Net::Sockets::AddressFamily::Pup, AF_PUP}, {System::Net::Sockets::AddressFamily::Chaos, AF_CHAOS}, {System::Net::Sockets::AddressFamily::NS, AF_NS}, {System::Net::Sockets::AddressFamily::Iso, AF_ISO}, {System::Net::Sockets::AddressFamily::Ecma, AF_ECMA}, {System::Net::Sockets::AddressFamily::DataKit, AF_DATAKIT}, {System::Net::Sockets::AddressFamily::Ccitt, AF_CCITT}, {System::Net::Sockets::AddressFamily::Sna, AF_SNA}, {System::Net::Sockets::AddressFamily::DecNet, AF_DECnet}, {System::Net::Sockets::AddressFamily::DataLink, AF_DLI}, {System::Net::Sockets::AddressFamily::Lat, AF_LAT}, {System::Net::Sockets::AddressFamily::HyperChannel, AF_HYLINK}, {System::Net::Sockets::AddressFamily::AppleTalk, AF_APPLETALK}, {System::Net::Sockets::AddressFamily::NetBios, AF_NETBIOS}, {System::Net::Sockets::AddressFamily::VoiceView, AF_VOICEVIEW}, {System::Net::Sockets::AddressFamily::FireFox, AF_FIREFOX}, {System::Net::Sockets::AddressFamily::Banyan, AF_BAN}, {System::Net::Sockets::AddressFamily::Atm, AF_ATM}, {System::Net::Sockets::AddressFamily::InterNetworkV6, AF_INET6}, {System::Net::Sockets::AddressFamily::Cluster, AF_CLUSTER}, {System::Net::Sockets::AddressFamily::Ieee12844, AF_12844}, {System::Net::Sockets::AddressFamily::Irda, AF_IRDA}, {System::Net::Sockets::AddressFamily::NetworkDesigners, AF_NETDES}, {System::Net::Sockets::AddressFamily::Max, AF_MAX}};

  if (!addressFamilies.ContainsKey(addressFamily))
    return (int32)addressFamily;
  return addressFamilies[addressFamily];
}

System::Net::Sockets::AddressFamily Native::SocketApi::NativeToAddressFamily(int32 addressFamily) {
  static System::Collections::Generic::SortedDictionary<int32, System::Net::Sockets::AddressFamily> addressFamilies = {{AF_UNSPEC, System::Net::Sockets::AddressFamily::Unspecified}, {AF_UNIX, System::Net::Sockets::AddressFamily::Unix}, {AF_INET, System::Net::Sockets::AddressFamily::InterNetwork}, {AF_IMPLINK, System::Net::Sockets::AddressFamily::ImpLink}, {AF_PUP, System::Net::Sockets::AddressFamily::Pup}, {AF_CHAOS, System::Net::Sockets::AddressFamily::Chaos}, {AF_NS, System::Net::Sockets::AddressFamily::NS}, {AF_ISO, System::Net::Sockets::AddressFamily::Iso}, {AF_ECMA, System::Net::Sockets::AddressFamily::Ecma}, {AF_DATAKIT, System::Net::Sockets::AddressFamily::DataKit}, {AF_CCITT, System::Net::Sockets::AddressFamily::Ccitt}, {AF_SNA, System::Net::Sockets::AddressFamily::Sna}, {AF_DECnet, System::Net::Sockets::AddressFamily::DecNet}, {AF_DLI, System::Net::Sockets::AddressFamily::DataLink}, {AF_LAT, System::Net::Sockets::AddressFamily::Lat}, {AF_HYLINK, System::Net::Sockets::AddressFamily::HyperChannel}, {AF_APPLETALK, System::Net::Sockets::AddressFamily::AppleTalk}, {AF_NETBIOS, System::Net::Sockets::AddressFamily::NetBios}, {AF_VOICEVIEW, System::Net::Sockets::AddressFamily::VoiceView}, {AF_FIREFOX, System::Net::Sockets::AddressFamily::FireFox}, {AF_BAN, System::Net::Sockets::AddressFamily::Banyan}, {AF_ATM, System::Net::Sockets::AddressFamily::Atm}, {AF_INET6, System::Net::Sockets::AddressFamily::InterNetworkV6}, {AF_CLUSTER, System::Net::Sockets::AddressFamily::Cluster}, {AF_12844, System::Net::Sockets::AddressFamily::Ieee12844}, {AF_IRDA, System::Net::Sockets::AddressFamily::Irda}, {AF_NETDES, System::Net::Sockets::AddressFamily::NetworkDesigners}, {AF_MAX, System::Net::Sockets::AddressFamily::Max}};

  if (!addressFamilies.ContainsKey(addressFamily))
    return (System::Net::Sockets::AddressFamily)addressFamily;
  return addressFamilies[addressFamily];
}

int32 Native::SocketApi::Accept(intptr handle, byte* socketAddress, int32 addressLength, intptr* handleResult) {
  *handleResult = (intptr)::accept(*(int32*)&handle, (SOCKADDR*)socketAddress, &addressLength);

  if (*handleResult == (intptr) - 1)
    return -1;

  return 0;
}

int32 Native::SocketApi::Bind(intptr handle, byte* socketAddress, int32 addressLength) {
  return ::bind(*(int32*)&handle, (SOCKADDR*)socketAddress, (int)addressLength);
}

int32 Native::SocketApi::Close(intptr handle) {
  return ::closesocket(*(int32*)&handle);
}

int32 Native::SocketApi::Connect(intptr handle, byte* socketAddress, int32 addressLength) {
  return ::connect(*(SOCKET*)&handle, (SOCKADDR*)socketAddress, addressLength);
}

int32 Native::SocketApi::GetAvailable(intptr handle, int32* nbrBytesAvailable) {
  return ioctlsocket(*(int32*)&handle, FIONREAD, (u_long*)nbrBytesAvailable);
}

int32 Native::SocketApi::GetLastError() {
  return WSAGetLastError();
}

bool Native::SocketApi::GetOSSupportsIPv4() {
  return true;
}

bool Native::SocketApi::GetOSSupportsIPv6() {
  return true;
}

int32 Native::SocketApi::GetSocketOption(intptr handle, System::Net::Sockets::SocketOptionLevel socketLevel, System::Net::Sockets::SocketOptionName socketOptionName, void* option, int32* optionLength) {
  return ::getsockopt(*(int32*)&handle, SocketOptionLevelToNative(socketLevel), SocketOptionNameToNative(socketOptionName), (char*)option, (int*)optionLength);
}

int32 Native::SocketApi::IoCtl(intptr handle, int32 ioControl, byte* optionInValue, int32 optionInValueSize, byte* optionOutValue, int32 optionOutValueSize, int32* optionOutValueSizeReturned) {
  return WSAIoctl(*(int32*)&handle, ioControl, optionInValue, optionInValueSize, optionOutValue, optionOutValueSize, (LPDWORD)optionOutValueSizeReturned, null, null);
}

int32 Native::SocketApi::Listen(intptr handle, int32 backLog) {
  return ::listen(*(int32*)&handle, backLog);
}

int32 Native::SocketApi::Open(System::Net::Sockets::AddressFamily addrFamily, System::Net::Sockets::SocketType socketType, System::Net::Sockets::ProtocolType protocolType, intptr* handle) {
  if (handle == null)
    return -1;

  *handle = (intptr)::socket(AddressFamilyToNative(addrFamily), SocketTypeToNative(socketType), ProtocolTypeToNative(protocolType));
  if ((*handle) != (intptr) - 1)
    return 0;

  return -1;
}

int32 Native::SocketApi::Poll(intptr handle, int32 microSec, int32 mode) {
  /* The call to WSAPoll is removed to ensure compatibility with Windows XP.
   The Poll action can be executed by the "select(...)" function.*/

  SOCKET socket = (SOCKET)handle;

  fd_set fdset = { 0 };
  memset(&fdset, 0, sizeof(fd_set));
  fdset.fd_count = 1;
  fdset.fd_array[0] = socket;
  for (int i = 1; i < 64; i++)
    fdset.fd_array[i] = 0;

  timeval timeout = { 0 };
  memset(&timeout, 0, sizeof(timeval));
  timeout.tv_sec = microSec / 1000000;
  timeout.tv_usec = microSec % 1000000;

  if (mode == 0)
    return ::select(0, &fdset, null, null, microSec == -1 ? null : &timeout);
  if (mode == 1)
    return ::select(0, null, &fdset, null, microSec == -1 ? null : &timeout);
  if (mode == 2)
    return ::select(0, null, null, &fdset, microSec == -1 ? null : &timeout);

  return -1;
  /*
   int32 retValue = -1;
   if (handle != null && microSec > 0 && mode >= 1 && mode <= 3) {
   WSAPOLLFD pollFd;
   ::memset(&pollFd, 0, sizeof(struct pollfd));

   pollFd.fd = (int32)handle;
   switch (mode) {
   case 1: pollFd.events = POLLRDNORM+POLLRDBAND; break;
   case 2: pollFd.events = POLLWRNORM; break;
   case 3: pollFd.events = POLLERR; break;
   }

   retValue = ::WSAPoll(&pollFd, 1, microSec) == 1;
   retValue = 1;
   }
   return retValue;*/
}

#pragma warning(push)
#pragma warning(disable:4127)
int32 Native::SocketApi::Select(intptr* checkRead, int32 nbCheckRead, intptr* checkWrite, int32 nbCheckWrite, intptr* checkError, int32 nbCheckError, int32 microseconds) {
  SOCKET nfds = 0;

  fd_set readfds;
  FD_ZERO(&readfds);
  for (int32 i = 0; i < nbCheckRead && i < FD_SETSIZE; i++) {
    FD_SET(reinterpret_cast<SOCKET*>(checkRead)[i], &readfds);
    if (reinterpret_cast<SOCKET*>(checkRead)[i] > nfds)
      nfds = reinterpret_cast<SOCKET*>(checkRead)[i];
  }

  fd_set writefds;
  FD_ZERO(&writefds);
  for (int32 i = 0; i < nbCheckWrite && i < FD_SETSIZE; i++) {
    FD_SET(reinterpret_cast<SOCKET*>(checkWrite)[i], &writefds);
    if (reinterpret_cast<SOCKET*>(checkWrite)[i] > nfds)
      nfds = reinterpret_cast<SOCKET*>(checkWrite)[i];
  }

  fd_set errorfds;
  FD_ZERO(&errorfds);
  for (int32 i = 0; i < nbCheckError && i < FD_SETSIZE; i++) {
    FD_SET(reinterpret_cast<SOCKET*>(checkError)[i], &errorfds);
    if (reinterpret_cast<SOCKET*>(checkError)[i] > nfds)
      nfds = reinterpret_cast<SOCKET*>(checkError)[i];
  }

  struct timeval* tvp = null;
  struct timeval tv;

  if (microseconds != -1) {
    tv.tv_sec = microseconds / 1000000;
    tv.tv_usec = microseconds % 1000000;

    tvp = &tv;
  }

  int32 result = ::select((int)nfds + 1, &readfds, &writefds, &errorfds, tvp);

  for (int32 i = 0; i < nbCheckRead; i++) {
    // If not set, we remove it from the list.
    if (FD_ISSET(reinterpret_cast<SOCKET*>(checkRead)[i], &readfds) == 0) {
      FD_CLR(reinterpret_cast<SOCKET*>(checkRead)[i], &readfds);
      reinterpret_cast<SOCKET*>(checkRead)[i] = 0;
    } else
      FD_CLR(reinterpret_cast<SOCKET*>(checkRead)[i], &readfds);
  }

  for (int32 i = 0; i < nbCheckWrite; i++) {
    // If not set, we remove it from the list.
    if (FD_ISSET(reinterpret_cast<SOCKET*>(checkWrite)[i], &readfds) == 0) {
      FD_CLR(reinterpret_cast<SOCKET*>(checkWrite)[i], &writefds);
      reinterpret_cast<SOCKET*>(checkWrite)[i] = 0;
    } else
      FD_CLR(reinterpret_cast<SOCKET*>(checkWrite)[i], &writefds);
  }

  for (int32 i = 0; i < nbCheckError; i++) {
    // If not set, we remove it from the list.
    if (FD_ISSET(reinterpret_cast<SOCKET*>(checkError)[i], &errorfds) == 0) {
      FD_CLR(reinterpret_cast<SOCKET*>(checkError)[i], &errorfds);
      reinterpret_cast<SOCKET*>(checkError)[i] = 0;
    } else
      FD_CLR(reinterpret_cast<SOCKET*>(checkError)[i], &errorfds);
  }

  return result;
}
#pragma warning(pop)

int32 Native::SocketApi::Receive(intptr handle, byte* buffer, int32 bufferLength, int32 flags) {
  return ::recv(*(int32*)&handle, (char*)buffer, bufferLength, flags);
}

int32 Native::SocketApi::ReceiveFrom(intptr handle, byte* buffer, int32 bufferLength, int32 flags, byte* socketAddress, int32 addressLength) {
  return ::recvfrom(*(int32*)&handle, (char*)buffer, bufferLength, flags, (sockaddr*)socketAddress, &addressLength);
}

int32 Native::SocketApi::Send(intptr handle, byte* buffer, int32 bufferLength, int32 flags) {
  return ::send(*(int32*)&handle, (char*)buffer, bufferLength, flags);
}

int32 Native::SocketApi::SendTo(intptr handle, byte* buffer, int32 bufferLength, int32 flags, byte* socketAddress, int32 addressLength) {
  return ::sendto(*(int32*)&handle, (char*)buffer, bufferLength, flags, (sockaddr*)socketAddress, addressLength);
}

int32 Native::SocketApi::SetBlocking(intptr handle, bool blocking) {
  uint32 mode = blocking ? 0 : 1;
  return ::ioctlsocket((SOCKET)handle, FIONBIO, (u_long*)&mode);
}

int32 Native::SocketApi::SetSocketOption(intptr handle, System::Net::Sockets::SocketOptionLevel socketLevel, System::Net::Sockets::SocketOptionName socketOptionName, void* option, int32 optionLength) {
  return ::setsockopt(*(int32*)&handle, SocketOptionLevelToNative(socketLevel), SocketOptionNameToNative(socketOptionName), (const char*)option, (int)optionLength);
}

int32 Native::SocketApi::Shutdown(intptr handle, int32 how) {
  return ::shutdown((SOCKET)handle, how);
}

#endif

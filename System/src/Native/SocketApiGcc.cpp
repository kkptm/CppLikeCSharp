#if defined(__linux__) || defined(__APPLE__)

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <poll.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include "Api.hpp"
#include <Switch/System/BitConverter.hpp>
#include <Switch/System/Diagnostics/Debug.hpp>

namespace {
  static int32 ProtocolTypeToNative(System::Net::Sockets::ProtocolType protocolType) {
    #if defined(__APPLE__)
    static System::Collections::Generic::SortedDictionary<System::Net::Sockets::ProtocolType, int32> protocolTypes = { { System::Net::Sockets::ProtocolType::Unknown, IPPROTO_IP }, { System::Net::Sockets::ProtocolType::IP, IPPROTO_IP }, { System::Net::Sockets::ProtocolType::Icmp, IPPROTO_ICMP }, { System::Net::Sockets::ProtocolType::Igmp, IPPROTO_IGMP }, { System::Net::Sockets::ProtocolType::Ggp, IPPROTO_GGP }, { System::Net::Sockets::ProtocolType::IPv4, IPPROTO_IPV4 }, { System::Net::Sockets::ProtocolType::Tcp, IPPROTO_TCP }, { System::Net::Sockets::ProtocolType::Pup, IPPROTO_PUP }, { System::Net::Sockets::ProtocolType::Udp, IPPROTO_UDP }, { System::Net::Sockets::ProtocolType::Idp, IPPROTO_IDP }, { System::Net::Sockets::ProtocolType::IPv6, IPPROTO_IPV6 }, { System::Net::Sockets::ProtocolType::IPv6RoutingHeader, IPPROTO_ROUTING }, { System::Net::Sockets::ProtocolType::IPv6FragmentHeader, IPPROTO_FRAGMENT }, { System::Net::Sockets::ProtocolType::IPSecEncapsulatingSecurityPayload, IPPROTO_ESP }, { System::Net::Sockets::ProtocolType::IPSecAuthenticationHeader, IPPROTO_AH }, { System::Net::Sockets::ProtocolType::IcmpV6, IPPROTO_ICMPV6 }, { System::Net::Sockets::ProtocolType::IPv6NoNextHeader, IPPROTO_NONE }, { System::Net::Sockets::ProtocolType::IPv6DestinationOptions, IPPROTO_DSTOPTS }, { System::Net::Sockets::ProtocolType::ND, IPPROTO_ND }, { System::Net::Sockets::ProtocolType::Raw, IPPROTO_RAW }, { System::Net::Sockets::ProtocolType::Spx, IPPROTO_IP }, { System::Net::Sockets::ProtocolType::SpxII, IPPROTO_IP } };
    #else
    static System::Collections::Generic::SortedDictionary<System::Net::Sockets::ProtocolType, int32> protocolTypes = { { System::Net::Sockets::ProtocolType::Unknown, IPPROTO_IP }, { System::Net::Sockets::ProtocolType::IP, IPPROTO_IP }, { System::Net::Sockets::ProtocolType::Icmp, IPPROTO_ICMP }, { System::Net::Sockets::ProtocolType::Igmp, IPPROTO_IGMP }, { System::Net::Sockets::ProtocolType::Ggp, IPPROTO_IP }, { System::Net::Sockets::ProtocolType::IPv4, IPPROTO_IPIP }, { System::Net::Sockets::ProtocolType::Tcp, IPPROTO_TCP }, { System::Net::Sockets::ProtocolType::Pup, IPPROTO_PUP }, { System::Net::Sockets::ProtocolType::Udp, IPPROTO_UDP }, { System::Net::Sockets::ProtocolType::Idp, IPPROTO_IDP }, { System::Net::Sockets::ProtocolType::IPv6, IPPROTO_IPV6 }, { System::Net::Sockets::ProtocolType::IPv6RoutingHeader, IPPROTO_ROUTING }, { System::Net::Sockets::ProtocolType::IPv6FragmentHeader, IPPROTO_FRAGMENT }, { System::Net::Sockets::ProtocolType::IPSecEncapsulatingSecurityPayload, IPPROTO_ESP }, { System::Net::Sockets::ProtocolType::IPSecAuthenticationHeader, IPPROTO_AH }, { System::Net::Sockets::ProtocolType::IcmpV6, IPPROTO_ICMPV6 }, { System::Net::Sockets::ProtocolType::IPv6NoNextHeader, IPPROTO_NONE }, { System::Net::Sockets::ProtocolType::IPv6DestinationOptions, IPPROTO_DSTOPTS }, { System::Net::Sockets::ProtocolType::ND, IPPROTO_IP }, { System::Net::Sockets::ProtocolType::Raw, IPPROTO_RAW }, { System::Net::Sockets::ProtocolType::Spx, IPPROTO_IP }, { System::Net::Sockets::ProtocolType::SpxII, IPPROTO_IP } };
    #endif

    if (!protocolTypes.ContainsKey(protocolType))
      return (int32)protocolType;
    return protocolTypes[protocolType];
  }

  static int32 SocketOptionNameToNative(System::Net::Sockets::SocketOptionName socketOptionName) {
    #if defined(__APPLE__)
    static System::Collections::Generic::SortedDictionary<System::Net::Sockets::SocketOptionName, int32> socketOptionNames = {{System::Net::Sockets::SocketOptionName::Debug, SO_DEBUG}, {System::Net::Sockets::SocketOptionName::AcceptConnection, SO_ACCEPTCONN}, {System::Net::Sockets::SocketOptionName::ReuseAddress, SO_REUSEADDR}, {System::Net::Sockets::SocketOptionName::KeepAlive, SO_KEEPALIVE}, {System::Net::Sockets::SocketOptionName::DontRoute, SO_DONTROUTE}, {System::Net::Sockets::SocketOptionName::Broadcast, SO_BROADCAST}, {System::Net::Sockets::SocketOptionName::UseLoopback, SO_USELOOPBACK}, {System::Net::Sockets::SocketOptionName::Linger, SO_LINGER}, {System::Net::Sockets::SocketOptionName::OutOfBandInline, SO_OOBINLINE}, {System::Net::Sockets::SocketOptionName::SendBuffer, SO_SNDBUF}, {System::Net::Sockets::SocketOptionName::ReceiveBuffer, SO_RCVBUF}, {System::Net::Sockets::SocketOptionName::SendLowWater, SO_SNDLOWAT}, {System::Net::Sockets::SocketOptionName::ReceiveLowWater, SO_RCVLOWAT}, {System::Net::Sockets::SocketOptionName::SendTimeout, SO_SNDTIMEO}, {System::Net::Sockets::SocketOptionName::ReceiveTimeout, SO_RCVTIMEO}, {System::Net::Sockets::SocketOptionName::Error, SO_ERROR}, {System::Net::Sockets::SocketOptionName::Type, SO_TYPE}};
    #else
    static System::Collections::Generic::SortedDictionary<System::Net::Sockets::SocketOptionName, int32> socketOptionNames = {{System::Net::Sockets::SocketOptionName::Debug, SO_DEBUG}, {System::Net::Sockets::SocketOptionName::AcceptConnection, SO_ACCEPTCONN}, {System::Net::Sockets::SocketOptionName::ReuseAddress, SO_REUSEADDR}, {System::Net::Sockets::SocketOptionName::KeepAlive, SO_KEEPALIVE}, {System::Net::Sockets::SocketOptionName::DontRoute, SO_DONTROUTE}, {System::Net::Sockets::SocketOptionName::Broadcast, SO_BROADCAST}, {System::Net::Sockets::SocketOptionName::UseLoopback, SO_OOBINLINE}, {System::Net::Sockets::SocketOptionName::Linger, SO_LINGER}, {System::Net::Sockets::SocketOptionName::OutOfBandInline, SO_OOBINLINE}, {System::Net::Sockets::SocketOptionName::SendBuffer, SO_SNDBUF}, {System::Net::Sockets::SocketOptionName::ReceiveBuffer, SO_RCVBUF}, {System::Net::Sockets::SocketOptionName::SendLowWater, SO_SNDLOWAT}, {System::Net::Sockets::SocketOptionName::ReceiveLowWater, SO_RCVLOWAT}, {System::Net::Sockets::SocketOptionName::SendTimeout, SO_SNDTIMEO}, {System::Net::Sockets::SocketOptionName::ReceiveTimeout, SO_RCVTIMEO}, {System::Net::Sockets::SocketOptionName::Error, SO_ERROR}, {System::Net::Sockets::SocketOptionName::Type, SO_TYPE}};
    #endif

    if (!socketOptionNames.ContainsKey(socketOptionName))
      return (int32)socketOptionName;
    return socketOptionNames[socketOptionName];
  }

  static int32 SocketOptionLevelToNative(System::Net::Sockets::SocketOptionLevel socketOptionLevel) {
    #if defined(__APPLE__)
    static System::Collections::Generic::SortedDictionary<System::Net::Sockets::SocketOptionLevel, int32> socketOptionLevels = {{System::Net::Sockets::SocketOptionLevel::Socket, SOL_SOCKET}, {System::Net::Sockets::SocketOptionLevel::IP, SOL_SOCKET}, {System::Net::Sockets::SocketOptionLevel::IPv6, SOL_SOCKET}, {System::Net::Sockets::SocketOptionLevel::Tcp, SOL_SOCKET}, {System::Net::Sockets::SocketOptionLevel::Udp, SOL_SOCKET}};
    #else
    static System::Collections::Generic::SortedDictionary<System::Net::Sockets::SocketOptionLevel, int32> socketOptionLevels = {{System::Net::Sockets::SocketOptionLevel::Socket, SOL_SOCKET}, {System::Net::Sockets::SocketOptionLevel::IP, SOL_SOCKET}, {System::Net::Sockets::SocketOptionLevel::IPv6, SOL_SOCKET}, {System::Net::Sockets::SocketOptionLevel::Tcp, SOL_SOCKET}, {System::Net::Sockets::SocketOptionLevel::Udp, SOL_SOCKET}};
    #endif

    if (!socketOptionLevels.ContainsKey(socketOptionLevel))
      return (int32)socketOptionLevel;
    return socketOptionLevels[socketOptionLevel];
  }

  static int32 SocketTypeToNative(System::Net::Sockets::SocketType socketType) {
    #if defined(__APPLE__)
    static System::Collections::Generic::SortedDictionary<System::Net::Sockets::SocketType, int32> socketTypes = {{System::Net::Sockets::SocketType::Unknown, SOCK_STREAM}, {System::Net::Sockets::SocketType::Stream, SOCK_STREAM}, {System::Net::Sockets::SocketType::Dgram, SOCK_DGRAM}, {System::Net::Sockets::SocketType::Raw, SOCK_RAW}, {System::Net::Sockets::SocketType::Rdm, SOCK_RDM}, {System::Net::Sockets::SocketType::Seqpacket, SOCK_SEQPACKET}};
    #else
    static System::Collections::Generic::SortedDictionary<System::Net::Sockets::SocketType, int32> socketTypes = {{System::Net::Sockets::SocketType::Unknown, SOCK_STREAM | SOCK_CLOEXEC}, {System::Net::Sockets::SocketType::Stream, SOCK_STREAM | SOCK_CLOEXEC}, {System::Net::Sockets::SocketType::Dgram, SOCK_DGRAM | SOCK_CLOEXEC}, {System::Net::Sockets::SocketType::Raw, SOCK_RAW | SOCK_CLOEXEC}, {System::Net::Sockets::SocketType::Rdm, SOCK_RDM | SOCK_CLOEXEC}, {System::Net::Sockets::SocketType::Seqpacket, SOCK_SEQPACKET | SOCK_CLOEXEC}};
    #endif

    if (!socketTypes.ContainsKey(socketType))
      return (int32)socketType;
    return socketTypes[socketType];
  }

  static int32 NativeToSocketError(int32 error) {
    #if defined(__APPLE__)
    static System::Collections::Generic::SortedDictionary<int32, int32> socketErrors {{EINTR, 1004}, {EACCES, 10013}, {EFAULT, 10014}, {EINVAL, 10022}, {EMFILE, 10024}, {EAGAIN, 10035}, {EINPROGRESS, 10036}, {EALREADY, 10037}, {ENOTSOCK, 10038}, {EDESTADDRREQ, 10039}, {EMSGSIZE, 10040}, {EPROTOTYPE, 10041}, {ENOPROTOOPT, 10042}, {EPROTONOSUPPORT, 10043}, {ESOCKTNOSUPPORT, 10044}, {ENOTSUP, 10045}, {EPFNOSUPPORT, 10046}, {EAFNOSUPPORT, 10047}, {EADDRINUSE, 10048}, {EADDRNOTAVAIL, 10049}, {ENETDOWN, 10050}, {ENETUNREACH, 10051}, {ENETRESET, 10052}, {ECONNABORTED, 10053}, {ECONNRESET, 10054}, {ENOBUFS, 10055}, {EISCONN, 10056}, {ENOTCONN, 10057}, {ESHUTDOWN, 10058}, {ETIMEDOUT, 10060}, {ECONNREFUSED, 10061}, {EHOSTDOWN, 10064}, {EHOSTUNREACH, 10065}, {EPROCLIM, 10067}, {ERPCMISMATCH, 10092}};
    #else
    static System::Collections::Generic::SortedDictionary<int32, int32> socketErrors {{EINTR, 1004}, {EACCES, 10013}, {EFAULT, 10014}, {EINVAL, 10022}, {EMFILE, 10024}, {EAGAIN, 10035}, {EINPROGRESS, 10036}, {EALREADY, 10037}, {ENOTSOCK, 10038}, {EDESTADDRREQ, 10039}, {EMSGSIZE, 10040}, {EPROTOTYPE, 10041}, {ENOPROTOOPT, 10042}, {EPROTONOSUPPORT, 10043}, {ESOCKTNOSUPPORT, 10044}, {ENOTSUP, 10045}, {EPFNOSUPPORT, 10046}, {EAFNOSUPPORT, 10047}, {EADDRINUSE, 10048}, {EADDRNOTAVAIL, 10049}, {ENETDOWN, 10050}, {ENETUNREACH, 10051}, {ENETRESET, 10052}, {ECONNABORTED, 10053}, {ECONNRESET, 10054}, {ENOBUFS, 10055}, {EISCONN, 10056}, {ENOTCONN, 10057}, {ESHUTDOWN, 10058}, {ETIMEDOUT, 10060}, {ECONNREFUSED, 10061}, {EHOSTDOWN, 10064}, {EHOSTUNREACH, 10065}};
    #endif

    if (!socketErrors.ContainsKey(error))
      return error;
    return socketErrors[error];
  }
}

int32 Native::SocketApi::AddressFamilyToNative(System::Net::Sockets::AddressFamily addressFamily) {
  #if defined(__APPLE__)
  static System::Collections::Generic::SortedDictionary<System::Net::Sockets::AddressFamily, int32> addressFamilies = {{System::Net::Sockets::AddressFamily::Unknown, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Unspecified, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Unix, AF_UNIX}, {System::Net::Sockets::AddressFamily::InterNetwork, AF_INET}, {System::Net::Sockets::AddressFamily::ImpLink, AF_IMPLINK}, {System::Net::Sockets::AddressFamily::Pup, AF_PUP}, {System::Net::Sockets::AddressFamily::Chaos, AF_CHAOS}, {System::Net::Sockets::AddressFamily::NS, AF_NS}, {System::Net::Sockets::AddressFamily::Iso, AF_ISO}, {System::Net::Sockets::AddressFamily::Ecma, AF_ECMA}, {System::Net::Sockets::AddressFamily::DataKit, AF_DATAKIT}, {System::Net::Sockets::AddressFamily::Ccitt, AF_CCITT}, {System::Net::Sockets::AddressFamily::Sna, AF_SNA}, {System::Net::Sockets::AddressFamily::DecNet, AF_DECnet}, {System::Net::Sockets::AddressFamily::DataLink, AF_DLI}, {System::Net::Sockets::AddressFamily::Lat, AF_LAT}, {System::Net::Sockets::AddressFamily::HyperChannel, AF_HYLINK}, {System::Net::Sockets::AddressFamily::AppleTalk, AF_APPLETALK}, {System::Net::Sockets::AddressFamily::NetBios, AF_NETBIOS}, {System::Net::Sockets::AddressFamily::VoiceView, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::FireFox, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Banyan, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Atm, AF_NATM}, {System::Net::Sockets::AddressFamily::InterNetworkV6, AF_INET6}, {System::Net::Sockets::AddressFamily::Cluster, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Ieee12844, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Irda, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::NetworkDesigners, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Max, AF_MAX}};
  #else
  static System::Collections::Generic::SortedDictionary<System::Net::Sockets::AddressFamily, int32> addressFamilies = {{System::Net::Sockets::AddressFamily::Unknown, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Unspecified, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Unix, AF_UNIX}, {System::Net::Sockets::AddressFamily::InterNetwork, AF_INET}, {System::Net::Sockets::AddressFamily::ImpLink, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Pup, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Chaos, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::NS, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Iso, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Ecma, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::DataKit, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Ccitt, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Sna, AF_SNA}, {System::Net::Sockets::AddressFamily::DecNet, AF_DECnet}, {System::Net::Sockets::AddressFamily::DataLink, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Lat, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::HyperChannel, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::AppleTalk, AF_APPLETALK}, {System::Net::Sockets::AddressFamily::NetBios, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::VoiceView, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::FireFox, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Banyan, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Atm, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::InterNetworkV6, AF_INET6}, {System::Net::Sockets::AddressFamily::Cluster, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Ieee12844, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Irda, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::NetworkDesigners, AF_UNSPEC}, {System::Net::Sockets::AddressFamily::Max, AF_MAX}};
  #endif

  if (!addressFamilies.ContainsKey(addressFamily))
    return (int32)addressFamily;
  return addressFamilies[addressFamily];
}

System::Net::Sockets::AddressFamily Native::SocketApi::NativeToAddressFamily(int32 addressFamily) {
  #if defined(__APPLE__)
  static System::Collections::Generic::SortedDictionary<int32, System::Net::Sockets::AddressFamily> addressFamilies = {{AF_UNSPEC, System::Net::Sockets::AddressFamily::Unspecified}, {AF_UNIX, System::Net::Sockets::AddressFamily::Unix}, {AF_INET, System::Net::Sockets::AddressFamily::InterNetwork}, {AF_IMPLINK, System::Net::Sockets::AddressFamily::ImpLink}, {AF_PUP, System::Net::Sockets::AddressFamily::Pup}, {AF_CHAOS, System::Net::Sockets::AddressFamily::Chaos}, {AF_NS, System::Net::Sockets::AddressFamily::NS}, {AF_ISO, System::Net::Sockets::AddressFamily::Iso}, {AF_ECMA, System::Net::Sockets::AddressFamily::Ecma}, {AF_DATAKIT, System::Net::Sockets::AddressFamily::DataKit}, {AF_CCITT, System::Net::Sockets::AddressFamily::Ccitt}, {AF_SNA, System::Net::Sockets::AddressFamily::Sna}, {AF_DECnet, System::Net::Sockets::AddressFamily::DecNet}, {AF_DLI, System::Net::Sockets::AddressFamily::DataLink}, {AF_LAT, System::Net::Sockets::AddressFamily::Lat}, {AF_HYLINK, System::Net::Sockets::AddressFamily::HyperChannel}, {AF_APPLETALK, System::Net::Sockets::AddressFamily::AppleTalk}, {AF_NETBIOS, System::Net::Sockets::AddressFamily::NetBios}, {AF_NATM, System::Net::Sockets::AddressFamily::Atm}, {AF_INET6, System::Net::Sockets::AddressFamily::InterNetworkV6}, {AF_MAX, System::Net::Sockets::AddressFamily::Max}};
  #else
  static System::Collections::Generic::SortedDictionary<int32, System::Net::Sockets::AddressFamily> addressFamilies = {{AF_UNSPEC, System::Net::Sockets::AddressFamily::Unspecified}, {AF_UNIX, System::Net::Sockets::AddressFamily::Unix}, {AF_INET, System::Net::Sockets::AddressFamily::InterNetwork}, {AF_SNA, System::Net::Sockets::AddressFamily::Sna}, {AF_DECnet, System::Net::Sockets::AddressFamily::DecNet}, {AF_APPLETALK, System::Net::Sockets::AddressFamily::AppleTalk}, {AF_INET6, System::Net::Sockets::AddressFamily::InterNetworkV6}, {AF_MAX, System::Net::Sockets::AddressFamily::Max}};
  #endif

  if (!addressFamilies.ContainsKey(addressFamily))
    return (System::Net::Sockets::AddressFamily)addressFamily;
  return addressFamilies[addressFamily];
}

int32 Native::SocketApi::Accept(intptr handle, byte* socketAddress, int32 addressLength, intptr* socket) {
  *socket = (intptr)accept(*(int32*)&handle, (struct sockaddr*)socketAddress, (socklen_t*)&addressLength);
  if (*socket == (intptr) - 1)
    return -1;

  #if defined(__APPLE__)
  socketAddress[0] = socketAddress[1];
  socketAddress[1] = 0;
  #endif

  return 0;
}

int32 Native::SocketApi::Bind(intptr handle, byte* socketAddress, int32 addressLength) {
  int32 result = bind(*(int32*)&handle, (struct sockaddr*)socketAddress, (socklen_t)addressLength);
  return result;
}

int32 Native::SocketApi::Close(intptr handle) {
  return close(*(int32*)&handle);
}

int32 Native::SocketApi::Connect(intptr handle, byte* socketAddress, int32 addressLength) {
  return ::connect(*(int32*)&handle, (struct sockaddr*)socketAddress, addressLength);
}

int32 Native::SocketApi::GetAvailable(intptr handle, int32* nbrBytesAvailable) {
  return ioctl(*(int32*)&handle, FIONREAD, nbrBytesAvailable);
}

int32 Native::SocketApi::GetLastError() {
  return NativeToSocketError(errno);
}

bool Native::SocketApi::GetOSSupportsIPv4() {
  return true;
}

bool Native::SocketApi::GetOSSupportsIPv6() {
  return true;
}

int32 Native::SocketApi::GetSocketOption(intptr handle, System::Net::Sockets::SocketOptionLevel socketLevel, System::Net::Sockets::SocketOptionName socketOptionName, void* option, int32* optionLength) {
  if (socketLevel == System::Net::Sockets::SocketOptionLevel::Socket && (socketOptionName == System::Net::Sockets::SocketOptionName::SendTimeout || socketOptionName == System::Net::Sockets::SocketOptionName::ReceiveTimeout)) {
    struct timeval tv = {0, 0};
    int32 retValue = getsockopt(*(int32*)&handle, SocketOptionLevelToNative(socketLevel), SocketOptionNameToNative(socketOptionName), &tv, (socklen_t*)optionLength);
    *(int32*)option = int32(tv.tv_sec * 1000 + tv.tv_usec / 1000);
    return retValue;
  }

  return getsockopt(*(int32*)&handle, SocketOptionLevelToNative(socketLevel), SocketOptionNameToNative(socketOptionName), option, (socklen_t*)optionLength);
}

int32 Native::SocketApi::IoCtl(intptr handle, int32 ioControl, byte* optionInValue, int32 optionInValueSize, byte* optionOutValue, int32 optionOutValueSize, int32* optionOutValueSizeReturned) {
  return -1;
}

int32 Native::SocketApi::Listen(intptr handle, int32 backLog) {
  return listen(*(int32*)&handle, backLog);
}

int32 Native::SocketApi::Open(System::Net::Sockets::AddressFamily addressFamily, System::Net::Sockets::SocketType socketType, System::Net::Sockets::ProtocolType protocolType, intptr* socket) {
  if (socket != null && (*socket = (intptr)::socket(AddressFamilyToNative(addressFamily), SocketTypeToNative(socketType), ProtocolTypeToNative(protocolType))) != (intptr) - 1)
    return 0;

  return -1;
}

int32 Native::SocketApi::Poll(intptr handle, int32 microseconds, int32 mode) {
  if (handle == 0 || microseconds < 0 || mode < 0 || mode > 2)
    return -1;

  struct pollfd pollFd;
  memset(&pollFd, 0, sizeof(struct pollfd));

  pollFd.fd = *(int32*)&handle;
  switch (mode) {
  case 0: pollFd.events = POLLIN; break;
  case 1: pollFd.events = POLLOUT; break;
  case 2: pollFd.events = POLLERR; break;
  }
  return poll(&pollFd, 1, microseconds);
}

int32 Native::SocketApi::Select(intptr* checkRead, int32 nbCheckRead, intptr* checkWrite, int32 nbCheckWrite, intptr* checkError, int32 nbCheckError, int32 microseconds) {
  int nfds = 0;

  fd_set readfds;
  FD_ZERO(&readfds);
  for (int32 i = 0; i < nbCheckRead && i < FD_SETSIZE; i++) {
    FD_SET(reinterpret_cast<int32*>(checkRead)[i], &readfds);
    if (reinterpret_cast<int32*>(checkRead)[i] > nfds)
      nfds = reinterpret_cast<int32*>(checkRead)[i];
  }

  fd_set writefds;
  FD_ZERO(&writefds);
  for (int32 i = 0; i < nbCheckWrite && i < FD_SETSIZE; i++) {
    FD_SET(reinterpret_cast<int32*>(checkWrite)[i], &writefds);
    if (reinterpret_cast<int32*>(checkWrite)[i] > nfds)
      nfds = reinterpret_cast<int32*>(checkWrite)[i];
  }

  fd_set errorfds;
  FD_ZERO(&errorfds);
  for (int32 i = 0; i < nbCheckError && i < FD_SETSIZE; i++) {
    FD_SET(reinterpret_cast<int32*>(checkError)[i], &errorfds);
    if (reinterpret_cast<int32*>(checkError)[i] > nfds)
      nfds = reinterpret_cast<int32*>(checkError)[i];
  }

  struct timeval* tvp = null;
  struct timeval tv;

  if (microseconds != -1) {
    tv.tv_sec = microseconds / 1000000;
    tv.tv_usec = microseconds % 1000000;

    tvp = &tv;
  }

  int32 result = ::select(nfds + 1, &readfds, &writefds, &errorfds, tvp);

  for (int32 i = 0; i < nbCheckRead; i++) {
    // If not set, we remove it from the list.
    if (FD_ISSET(reinterpret_cast<int32*>(checkRead)[i], &readfds) == 0) {
      FD_CLR(reinterpret_cast<int32*>(checkRead)[i], &readfds);
      reinterpret_cast<int32*>(checkRead)[i] = 0;
    } else
      FD_CLR(reinterpret_cast<int32*>(checkRead)[i], &readfds);
  }

  for (int32 i = 0; i < nbCheckWrite; i++) {
    // If not set, we remove it from the list.
    if (FD_ISSET(reinterpret_cast<int32*>(checkWrite)[i], &readfds) == 0) {
      FD_CLR(reinterpret_cast<int32*>(checkWrite)[i], &writefds);
      reinterpret_cast<int32*>(checkWrite)[i] = 0;
    } else
      FD_CLR(reinterpret_cast<int32*>(checkWrite)[i], &writefds);
  }

  for (int32 i = 0; i < nbCheckError; i++) {
    // If not set, we remove it from the list.
    if (FD_ISSET(reinterpret_cast<int32*>(checkError)[i], &errorfds) == 0) {
      FD_CLR(reinterpret_cast<int32*>(checkError)[i], &errorfds);
      reinterpret_cast<int32*>(checkError)[i] = 0;
    } else
      FD_CLR(reinterpret_cast<int32*>(checkError)[i], &errorfds);
  }

  return result;
}

int32 Native::SocketApi::Receive(intptr handle,  byte* buffer, int32 bufferLength, int32 flags) {
  int32 retValue = (int32)recv(*(int32*)&handle, buffer, bufferLength, flags);

  if (retValue == -1 && errno == EBADF)
    errno = EINTR;
  if (retValue == -1 && errno == EAGAIN)
    errno = ETIMEDOUT;

  return retValue;
}

int32 Native::SocketApi::ReceiveFrom(intptr handle, byte* buffer, int32 bufferLength, int32 flags, byte* socketAddress, int32 addressLength) {
  int32 retValue = (int32)recvfrom(*(int32*)&handle, (char*)buffer, bufferLength, flags, reinterpret_cast<sockaddr*>(socketAddress), reinterpret_cast<socklen_t*>(&addressLength));

  #if defined(__APPLE__)
  socketAddress[0] = socketAddress[1];
  socketAddress[1] = 0;
  #endif

  if (retValue == -1 && errno == EBADF)
    errno = EINTR;
  if (retValue == -1 && errno == EAGAIN)
    errno = ETIMEDOUT;

  return retValue;
}

int32 Native::SocketApi::Send(intptr handle,  byte* buffer, int32 bufferLength, int32 flags) {
  return (int32)send(*(int32*)&handle, buffer, bufferLength, flags);
}

int32 Native::SocketApi::SendTo(intptr handle, byte* buffer, int32 bufferLength, int32 flags, byte* socketAddress, int32 addressLength) {
  return (int32)sendto(*(int32*)&handle, (char*)buffer, bufferLength, flags, reinterpret_cast<sockaddr*>(socketAddress), addressLength);
}

int32 Native::SocketApi::SetBlocking(intptr handle, bool blocking) {
  int32 retValue = -1;

  if ((retValue = fcntl(*(int32*)&handle, F_GETFL, 0)) != -1) {
    int32 flags = retValue;
    if (blocking == true)
      flags &= ~O_NONBLOCK;
    else
      flags |= O_NONBLOCK;

    retValue = fcntl(*(int32*)&handle, F_SETFL, flags)  == -1 ? -1 : 0;
  }

  return retValue;
}

int32 Native::SocketApi::SetSocketOption(intptr handle, System::Net::Sockets::SocketOptionLevel socketLevel, System::Net::Sockets::SocketOptionName socketOptionName, void* option, int32 optionLength) {
  if (socketLevel == System::Net::Sockets::SocketOptionLevel::Socket && (socketOptionName == System::Net::Sockets::SocketOptionName::SendTimeout || socketOptionName == System::Net::Sockets::SocketOptionName::ReceiveTimeout)) {
    struct timeval tv = {*(int32*)option / 1000, *(int32*)option % 1000 * 1000};
    return ::setsockopt(*(int32*)&handle, SocketOptionLevelToNative(socketLevel), SocketOptionNameToNative(socketOptionName), &tv, sizeof(struct timeval));
  }

  return setsockopt(*(int32*)&handle, SocketOptionLevelToNative(socketLevel), SocketOptionNameToNative(socketOptionName), option, (socklen_t)optionLength);
}

int32 Native::SocketApi::Shutdown(intptr handle, int32 how) {
  int32 retValue = shutdown(*(int32*)&handle, how);

  if (how == 2 && retValue == -1 && errno == ENOTCONN) {
    errno = 0;
    retValue = 0;
  }

  return retValue;
}

#endif

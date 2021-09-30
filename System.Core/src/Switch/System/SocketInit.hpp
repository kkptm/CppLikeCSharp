#if _WIN32

#include <winsock2.h>
#include "../include/Switch/Undef.hpp"

namespace {
  struct SocketInit {
    SocketInit() noexcept {WSAStartup(versionRequested, &wsaData);}
    ~SocketInit() noexcept {WSACleanup();}
    WORD versionRequested = MAKEWORD(2, 2);
    WSADATA wsaData = {0};
  };
}

#else

namespace {
  struct SocketInit {
    SocketInit() noexcept = default;
    ~SocketInit() noexcept = default;
  };
}

#endif

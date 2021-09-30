#pragma once

#include <Switch/Static.hpp>
#include <Switch/Types.hpp>
#include "../../include/Switch/System/Diagnostics/ProcessStartInfo.hpp"
#include "../../include/Switch/System/Net/Sockets/AddressFamily.hpp"
#include "../../include/Switch/System/Net/Sockets/ProtocolType.hpp"
#include "../../include/Switch/System/Net/Sockets/SocketOptionName.hpp"
#include "../../include/Switch/System/Net/Sockets/SocketOptionLevel.hpp"
#include "../../include/Switch/System/Net/Sockets/SocketType.hpp"
#include "../../include/Switch/System/Net/IPAddress.hpp"

namespace Native {
  class CurlApi static_ {
  public:
    static int32 Cleanup(intptr request);

    static bool GetOSSupportsWebOperations();
    static int32 GetContentDownloadLength(intptr request, double& value);
    static int32 GetContentType(intptr request, string& value);
    static int32 GetResponseCode(intptr request, int64& value);

    static int32 GlobalCleanup();
    static int32 GlobalInit();
    static int32 Init(intptr& request);
    static int32 Perform(intptr request);

    static int32 SetCarriageReturnLinefeed(intptr request, int32 value);
    static int32 SetCreateDirectoryIfDirectoryMissing(intptr request);
    static int32 SetDirectoryListOnly(intptr request, int32 value);
    static int32 SetInFileSize(intptr request, int64 value);
    static int32 SetPostFieldSize(intptr request, int64 value);
    static int32 SetUrl(intptr request, const string& value);
    static int32 SetUserName(intptr request, const string& value);
    static int32 SetPassword(intptr request, const string& value);
    static int32 SetReadData(intptr request, void* value);
    static int32 SetReadFunction(intptr request, size_t value(void* buffer, size_t size, size_t nmemb, void* stream));
    static int32 SetTransfertText(intptr request, int32 value);
    static int32 SetTimeout(intptr request, int32 value);
    static int32 SetUpload(intptr request, int32 value);
    static int32 SetVerbose(intptr request, int32 value);
    static int32 SetWriteData(intptr request, void* value);
    static int32 SetWriteFunction(intptr request, size_t value(void* buffer, size_t size, size_t nmemb, void* stream));
    static int32 SetAllowRedirection(intptr request, int32 value);
    static int32 SetHttpPut(intptr request, int32 value);
    static int32 SetHttpPost(intptr request, int32 value);
    static intptr AppendToList(intptr list, const string& value);
    static void FreeList(intptr list);
    static int32 SetHttpHeader(intptr request, intptr list);
  };

  struct DebuggerApi static_ {
  public:
    static void Log(int32 level, const string& category, const string& message);
  };

  class DnsApi static_ {
  public:
    static void Destroy(intptr host);
    static void EndHostent();
    static intptr GetHostByAddress(const string& hostAddress, System::Net::Sockets::AddressFamily hostAddressType);
    static intptr GetHostByName(const string& hostName);
    static System::Array<string> GetAliases(intptr host);
    static System::Array<System::Net::IPAddress> GetAddresses(intptr host);
    static string GetHostName(intptr host);
    static int GetHostName(string& hostName);
    static void SetHostent(bool stayOpen);
  };

  class ProcessApi static_ {
  public:
    static intptr Start(const System::Diagnostics::ProcessStartInfo& processStartInfo);
    static bool Close(intptr handle);
    static bool Kill(intptr handle);
    static intptr GetCurrent();
    static intptr GetParent();
    static string GetName(intptr handle);
    static string GetPath(intptr handle);
    static System::Array<intptr> GetProcesses();
    static void WaitForExit(intptr handle, int32& exitCode);
    static bool WaitForExit(intptr handle, int32 timeout, int32& exitCode);
  };

  class SecurityApi static_ {
  public:
    static System::Security::SecureString ToSecureSecureString(const string& unsecureString);
    static string ToSecureString(const string& unsecureString);
    static string ToUnsecureString(const System::Security::SecureString& secureString);
    static string ToUnsecureString(const string& secureString);
  };

  class SocketApi static_ {
  public:
    static int32 AddressFamilyToNative(System::Net::Sockets::AddressFamily addressFamily);
    static System::Net::Sockets::AddressFamily NativeToAddressFamily(int32 addressFamily);
    static int32 Accept(intptr handle, byte* socketAddress, int32 addressLength, intptr* socket);
    static int32 Bind(intptr handle, byte* socketAddress, int32 addressLength);
    static int32 Close(intptr handle);
    static int32 Connect(intptr handle, byte* socketAddress, int32 addressLength);
    static int32 GetLastError();
    static int32 GetAvailable(intptr handle, int32* nbrBytesAvailable);
    static int32 GetSocketOption(intptr handle, System::Net::Sockets::SocketOptionLevel socketLevel, System::Net::Sockets::SocketOptionName socketOptionName, void* option, int32* optionLength);
    static bool GetOSSupportsIPv4();
    static bool GetOSSupportsIPv6();
    static int32 IoCtl(intptr handle, int32 ioControl, byte* optionInValue, int32 optionInValueSize, byte* optionOutValue, int32 optionOutValueSize, int32* optionOutValueSizeReturned);
    static int32 Listen(intptr handle, int32 backLog);
    static int32 Open(System::Net::Sockets::AddressFamily addressFamily, System::Net::Sockets::SocketType socketType, System::Net::Sockets::ProtocolType protocolType, intptr* socket);
    static int32 Poll(intptr handle, int32 microseconds, int32 mode);
    static int32 Select(intptr* checkRead, int32 nbCheckRead, intptr* checkWrite, int32 nbCheckWrite, intptr* checkError, int32 nbCheckError, int32 microseconds);
    static int32 Send(intptr handle, byte* buffer, int32 bufferLength, int32 flags);
    static int32 SendTo(intptr handle, byte* buffer, int32 bufferLength, int32 flags, byte* socketAddress, int32 addressLength);
    static int32 SetBlocking(intptr handle, bool blocking);
    static int32 SetSocketOption(intptr handle, System::Net::Sockets::SocketOptionLevel socketLevel, System::Net::Sockets::SocketOptionName socketOptionName, void* option, int32 optionLength);
    static int32 Receive(intptr handle, byte* buffer, int32 bufferLength, int32 flags);
    static int32 ReceiveFrom(intptr handle, byte* buffer, int32 bufferLength, int32 flags, byte* socketAddress, int32 addressLength);
    static int32 Shutdown(intptr handle, int32 how);
  };

  enum class SoundType {
    Beep = 0,
    Hand = 0x00000010,
    Question = 0x00000020,
    Exclamation = 0x00000030,
    Asterisk = 0x00000040,
  };

  class SystemSoundApi static_ {
  public:
    static void Play(SoundType type);
  };
}


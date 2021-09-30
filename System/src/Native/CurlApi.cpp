#include "Api.hpp"

#include <Switch/Types.hpp>
#include <Switch/System/IntPtr.hpp>

#if defined(__APPLE__)
#include "TargetConditionals.h"
#endif

#if TARGET_OS_IPHONE == 0 && !defined(__ANDROID__)
#include <curl/curl.h>

int32 Native::CurlApi::Cleanup(intptr request) {
  curl_easy_cleanup((CURL*)request);
  return 0;
}

bool Native::CurlApi::GetOSSupportsWebOperations() {
  return true;
}

int32 Native::CurlApi::GetContentDownloadLength(intptr request, double& value) {
  return curl_easy_getinfo((CURL*)request, CURLINFO_CONTENT_LENGTH_DOWNLOAD, value);
}

int32 Native::CurlApi::GetContentType(intptr request, string& value) {
  char* str;
  int32 result = curl_easy_getinfo((CURL*)request, CURLINFO_CONTENT_TYPE, &str);
  if (result == 0 && str != null)
    value = str;
  return result;
}

int32 Native::CurlApi::GetResponseCode(intptr request, int64& value) {
  return curl_easy_getinfo((CURL*)request, CURLINFO_RESPONSE_CODE, &value);
}

int32 Native::CurlApi::GlobalCleanup() {
  curl_global_cleanup();
  return 0;
}

int32 Native::CurlApi::GlobalInit() {
  return curl_global_init(CURL_GLOBAL_DEFAULT);
}

int32 Native::CurlApi::Init(intptr& request) {
  request = (intptr)curl_easy_init();
  return 0;
}

int32 Native::CurlApi::Perform(intptr request) {
  return curl_easy_perform((CURL*)request);
}

int32 Native::CurlApi::SetCarriageReturnLinefeed(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_CRLF, value);
}

int32 Native::CurlApi::SetCreateDirectoryIfDirectoryMissing(intptr request) {
  return curl_easy_setopt((CURL*)request, CURLOPT_FTP_CREATE_MISSING_DIRS, CURLFTP_CREATE_DIR);
}

int32 Native::CurlApi::SetDirectoryListOnly(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_DIRLISTONLY, value);
}

int32 Native::CurlApi::SetInFileSize(intptr request, int64 value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_INFILESIZE, value);
}

int32 Native::CurlApi::SetPostFieldSize(intptr request, int64 value) {
  //force using read function to get post data
  curl_easy_setopt((CURL*)request, CURLOPT_POSTFIELDS, null);
  return curl_easy_setopt((CURL*)request, CURLOPT_POSTFIELDSIZE, value);
}

int32 Native::CurlApi::SetUrl(intptr request, const string& value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_URL, value.c_str());
}

int32 Native::CurlApi::SetTimeout(intptr request, int32 value) {
  //Convert Infinite timeout -1 to 0 in libcurl
  return curl_easy_setopt((CURL*)request, CURLOPT_TIMEOUT_MS, (value == -1) ? 0 : value);
}

int32 Native::CurlApi::SetPassword(intptr request, const string& value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_PASSWORD, value.c_str());
}

int32 Native::CurlApi::SetReadData(intptr request, void* value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_READDATA, value);
}

int32 Native::CurlApi::SetReadFunction(intptr request, size_t value(void* buffer, size_t size, size_t nmemb, void* stream)) {
  return curl_easy_setopt((CURL*)request, CURLOPT_READFUNCTION, value);
}

int32 Native::CurlApi::SetUserName(intptr request, const string& value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_USERNAME, value.c_str());
}

int32 Native::CurlApi::SetTransfertText(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_TRANSFERTEXT, value);
}

int32 Native::CurlApi::SetUpload(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_UPLOAD, value);
}

int32 Native::CurlApi::SetVerbose(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_VERBOSE, value);
}

int32 Native::CurlApi::SetWriteData(intptr request, void* value) {
  return curl_easy_setopt((CURL*)request, CURLOPT_WRITEDATA, value);
}

int32 Native::CurlApi::SetWriteFunction(intptr request, size_t value(void* buffer, size_t size, size_t nmemb, void* stream)) {
  return curl_easy_setopt((CURL*)request, CURLOPT_WRITEFUNCTION, value);
}

int32 Native::CurlApi::SetAllowRedirection(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request,  CURLOPT_FOLLOWLOCATION, value);
}

int32 Native::CurlApi::SetHttpPut(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request,  CURLOPT_PUT, value);
}

int32 Native::CurlApi::SetHttpPost(intptr request, int32 value) {
  return curl_easy_setopt((CURL*)request,  CURLOPT_POST, value);
}

intptr Native::CurlApi::AppendToList(intptr list, const string& value) {
  return (intptr)curl_slist_append((curl_slist*)list, value.c_str());
}

void Native::CurlApi::FreeList(intptr list) {
  if (list != System::IntPtr::Zero)
    curl_slist_free_all((curl_slist*)list);
}

int32 Native::CurlApi::SetHttpHeader(intptr request, intptr list) {
  return curl_easy_setopt((CURL*)request,  CURLOPT_HTTPHEADER, (curl_slist*)list);
}

#else
int32 Native::CurlApi::Cleanup(intptr request) {
  return 0;
}

bool Native::CurlApi::GetOSSupportsWebOperations() {
  return true;
}

int32 Native::CurlApi::GetContentDownloadLength(intptr request, double& value) {
  return 0;
}

int32 Native::CurlApi::GetContentType(intptr request, string& value) {
  return 0;
}

int32 Native::CurlApi::GetResponseCode(intptr request, int64& value) {
  return 0;
}

int32 Native::CurlApi::GlobalCleanup() {
  return 0;
}

int32 Native::CurlApi::GlobalInit() {
  return 0;
}

int32 Native::CurlApi::Init(intptr& request) {
  return 0;
}

int32 Native::CurlApi::Perform(intptr request) {
  return 0;
}

int32 Native::CurlApi::SetCarriageReturnLinefeed(intptr request, int32 value) {
  return 0;
}

int32 Native::CurlApi::SetCreateDirectoryIfDirectoryMissing(intptr request) {
  return 0;
}

int32 Native::CurlApi::SetDirectoryListOnly(intptr request, int32 value) {
  return 0;
}

int32 Native::CurlApi::SetInFileSize(intptr request, int64 value) {
  return 0;
}

int32 Native::CurlApi::SetPostFieldSize(intptr request, int64 value) {
  return 0;
}

int32 Native::CurlApi::SetUrl(intptr request, const string& value) {
  return 0;
}

int32 Native::CurlApi::SetTimeout(intptr request, int32 value) {
  return 0;
}

int32 Native::CurlApi::SetPassword(intptr request, const string& value) {
  return 0;
}

int32 Native::CurlApi::SetReadData(intptr request, void* value) {
  return 0;
}

int32 Native::CurlApi::SetReadFunction(intptr request, size_t value(void* buffer, size_t size, size_t nmemb, void* stream)) {
  return 0;
}

int32 Native::CurlApi::SetUserName(intptr request, const string& value) {
  return 0;
}

int32 Native::CurlApi::SetTransfertText(intptr request, int32 value) {
  return 0;
}

int32 Native::CurlApi::SetUpload(intptr request, int32 value) {
  return 0;
}

int32 Native::CurlApi::SetVerbose(intptr request, int32 value) {
  return 0;
}

int32 Native::CurlApi::SetWriteData(intptr request, void* value) {
  return 0;
}

int32 Native::CurlApi::SetWriteFunction(intptr request, size_t value(void* buffer, size_t size, size_t nmemb, void* stream)) {
  return 0;
}

int32 Native::CurlApi::SetAllowRedirection(intptr request, int32 value) {
  return 0;
}

int32 Native::CurlApi::SetHttpPut(intptr request, int32 value) {
  return 0;
}

int32 Native::CurlApi::SetHttpPost(intptr request, int32 value) {
  return 0;
}

intptr Native::CurlApi::AppendToList(intptr list, const string& value) {
  return 0;
}

void Native::CurlApi::FreeList(intptr list) {
}

int32 Native::CurlApi::SetHttpHeader(intptr request, intptr list) {
  return 0;
}
#  endif


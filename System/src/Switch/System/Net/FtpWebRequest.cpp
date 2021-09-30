#include "../../../../include/Switch/System/Net/FtpWebRequest.hpp"
#include "../../../../include/Switch/System/Net/WebRequestMethods.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Net;

FtpWebRequest::FtpWebRequest(const string& uri): WebRequest(uri) {
  this->ftpWebResponse.SetWebRequest(*this);
  SetUseBinary(true);
}

FtpWebRequest::FtpWebRequest(const Uri& uri): WebRequest(uri) {
  this->ftpWebResponse.SetWebRequest(*this);
  SetUseBinary(true);
}

WebRequest::WebRequestStream FtpWebRequest::GetRequestStream() {
  if (GetMethod() == WebRequestMethods::Ftp::UploadFile)
    return WebRequest::GetRequestStream();

  throw InvalidOperationException(caller_);
}

void FtpWebRequest::SetUseBinary(bool useBinary) {
  if (Native::CurlApi::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(caller_);

  this->useBinary = useBinary;

  if (useBinary) {
    Native::CurlApi::SetTransfertText(this->requestHandle, 0L);
    Native::CurlApi::SetCarriageReturnLinefeed(this->requestHandle, 0L);
  } else
    Native::CurlApi::SetTransfertText(this->requestHandle, 1L);
}

bool FtpWebRequest::GetUseBinary() {
  return this->useBinary;
}

void FtpWebRequest::ProcessMakeDirectory() {
  if (Native::CurlApi::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(caller_);

  Native::CurlApi::SetCreateDirectoryIfDirectoryMissing(this->requestHandle);
  this->internalError = Native::CurlApi::Perform(this->requestHandle);
}

void FtpWebRequest::ProcessListDirectory() {
  if (Native::CurlApi::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(caller_);

  Native::CurlApi::SetDirectoryListOnly(this->requestHandle, 1L);
}

void FtpWebRequest::ProcessListDirectoryDetails() {
  if (Native::CurlApi::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(caller_);
}

WebResponse& FtpWebRequest::GetInternalResponse() {
  return this->ftpWebResponse;
}

WebResponse& FtpWebRequest::GetResponse() {
  if (GetMethod() == WebRequestMethods::Ftp::MakeDirectory) {
    //No stream needed to process the request
    ProcessMakeDirectory();
  } else if (GetMethod() == WebRequestMethods::Ftp::ListDirectory) {
    //A reponse stream is needed
    ProcessListDirectory();
  } else if (GetMethod() == WebRequestMethods::Ftp::ListDirectoryDetails) {
    //A reponse stream is needed
    ProcessListDirectoryDetails();
  }
  if (IsResponseStreamNeeded())
    this->ftpWebResponse.StartTransfert();
  return this->ftpWebResponse;
}

void FtpWebRequest::Finished(int32 error) {
  WebRequest::Finished(error);
}


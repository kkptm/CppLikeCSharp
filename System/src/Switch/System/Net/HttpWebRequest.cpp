#include "../../../../include/Switch/System/Net/HttpWebRequest.hpp"

#include "../../../../include/Switch/System/Net/WebRequestMethods.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Net;

HttpWebRequest::HttpWebRequest(const string& uri): WebRequest(uri) {
  this->httpWebResponse.SetWebRequest(*this);
  this->method = WebRequestMethods::Http::Get;
}

HttpWebRequest::HttpWebRequest(const Uri& uri): WebRequest(uri) {
  this->httpWebResponse.SetWebRequest(*this);
  this->method = WebRequestMethods::Http::Get;
}

HttpWebRequest::~HttpWebRequest() {
  Native::CurlApi::FreeList(this->header);
}

WebRequest::WebRequestStream HttpWebRequest::GetRequestStream() {
  if (!string::IsNullOrEmpty(this->contentType)) {
    string contentType = string::Format("Content-Type: {0}", this->contentType);
    this->header = Native::CurlApi::AppendToList(this->header, contentType);
    Native::CurlApi::SetHttpHeader(this->requestHandle, this->header);
  }

  if (GetMethod() == WebRequestMethods::Http::Put) {
    Native::CurlApi::SetHttpPut(this->requestHandle, 1L);
    return WebRequest::GetRequestStream();
  }

  if (GetMethod() == WebRequestMethods::Http::Post) {
    Native::CurlApi::SetHttpPost(this->requestHandle, 1L);
    return WebRequest::GetRequestStream();
  }

  throw InvalidOperationException(caller_);
}

WebResponse& HttpWebRequest::GetInternalResponse() {
  return this->httpWebResponse;
}

WebResponse& HttpWebRequest::GetResponse() {
  if (IsResponseStreamNeeded())
    this->httpWebResponse.StartTransfert();

  return this->httpWebResponse;
}

void HttpWebRequest::Finished(int32 error) {
  WebRequest::Finished(error);
}

bool HttpWebRequest::GetAllowAutoRedirect() const {
  if (Native::CurlApi::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(caller_);

  return this->allowAutoRedirect;
}

void HttpWebRequest::SetAllowAutoRedirect(bool autoRedirect) {
  if (Native::CurlApi::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(caller_);

  this->allowAutoRedirect = autoRedirect;
  Native::CurlApi::SetAllowRedirection(this->requestHandle, this->allowAutoRedirect ? 1L : 0L);
}

const string& HttpWebRequest::GetContentType() const {
  if (Native::CurlApi::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(caller_);

  return this->contentType;
}

void HttpWebRequest::SetContentType(const string& contentType) {
  if (Native::CurlApi::GetOSSupportsWebOperations() == false)
    throw NotSupportedException(caller_);

  this->contentType = contentType;
}

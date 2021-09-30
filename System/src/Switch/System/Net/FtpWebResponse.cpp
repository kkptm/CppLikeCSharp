#include "../../../../include/Switch/System/Net/FtpWebResponse.hpp"

#include <Switch/System/Convert.hpp>
#include <Switch/System/Collections/Generic/Dictionary.hpp>
#include "../../../../include/Switch/System/Net/WebRequest.hpp"
#include "../../../../include/Switch/System/Net/WebRequestMethods.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Net;

FtpWebResponse::FtpWebResponse(): WebResponse() {
}

WebResponse::WebResponseStream FtpWebResponse::GetResponseStream() {
  if (this->webRequest->Method() == WebRequestMethods::Ftp::DownloadFile || this->webRequest->Method() == WebRequestMethods::Ftp::ListDirectory || this->webRequest->Method() == WebRequestMethods::Ftp::ListDirectoryDetails)
    return WebResponse::GetResponseStream();

  throw InvalidOperationException(caller_);
}

FtpStatusCode FtpWebResponse::GetStatusCode() const {
  return FtpStatusCode(Convert::ToInt32(WebResponse::GetResponseCode()));
}

const string FtpWebResponse::GetStatusDescription() const {
  string description;
  static Dictionary<int32, string> statusDescriptions;

  if (statusDescriptions.Count == 0) {
    statusDescriptions[(int32)FtpStatusCode::RestartMarker] = "The response contains a restart marker reply.";
    statusDescriptions[(int32)FtpStatusCode::ServiceTemporarilyNotAvailable] = "The service is not available now; try your request later.";
    statusDescriptions[(int32)FtpStatusCode::DataAlreadyOpen] = "The data connection is already open and the requested transfer is starting.";
    statusDescriptions[(int32)FtpStatusCode::OpeningData] = "The server is opening the data connection.";
    statusDescriptions[(int32)FtpStatusCode::CommandOK] = "The command completed successfully.";
    statusDescriptions[(int32)FtpStatusCode::CommandExtraneous] = "The command is not implemented by the server because it is not needed.";
    statusDescriptions[(int32)FtpStatusCode::DirectoryStatus] = "Status of a directory.";
    statusDescriptions[(int32)FtpStatusCode::FileStatus] = "Status of a file.";
    statusDescriptions[(int32)FtpStatusCode::SystemType] = "System type name using the system names published in the Assigned Numbers document published by the Internet Assigned Numbers Authority.";
    statusDescriptions[(int32)FtpStatusCode::SendUserCommand] = "The server is ready for a user login operation.";
    statusDescriptions[(int32)FtpStatusCode::ClosingControl] = "The server is closing the control connection.";
    statusDescriptions[(int32)FtpStatusCode::ClosingData] = "The server is closing the data connection and that the requested file action was successful.";
    statusDescriptions[(int32)FtpStatusCode::EnteringPassive] = "The server is entering passive mode.";
    statusDescriptions[(int32)FtpStatusCode::LoggedInProceed] = "The user is logged in and can send commands.";
    statusDescriptions[(int32)FtpStatusCode::ServerWantsSecureSession] = "The server accepts the authentication mechanism specified by the client, and the exchange of security data is complete.";
    statusDescriptions[(int32)FtpStatusCode::FileActionOK] = "The requested file action completed successfully.";
    statusDescriptions[(int32)FtpStatusCode::PathnameCreated] = "The requested path name was created.";
    statusDescriptions[(int32)FtpStatusCode::SendPasswordCommand] = "The server expects a password to be supplied.";
    statusDescriptions[(int32)FtpStatusCode::NeedLoginAccount] = "The server requires a login account to be supplied.";
    statusDescriptions[(int32)FtpStatusCode::FileCommandPending] = "The requested file action requires additional information.";
    statusDescriptions[(int32)FtpStatusCode::ServiceNotAvailable] = "The service is not available.";
    statusDescriptions[(int32)FtpStatusCode::CantOpenData] = "The data connection cannot be opened.";
    statusDescriptions[(int32)FtpStatusCode::ConnectionClosed] = "The connection has been closed.";
    statusDescriptions[(int32)FtpStatusCode::ActionNotTakenFileUnavailableOrBusy] = "The requested action cannot be performed on the specified file because the file is not available or is being used.";
    statusDescriptions[(int32)FtpStatusCode::ActionAbortedLocalProcessingError] = "An error occurred that prevented the request action from completing.";
    statusDescriptions[(int32)FtpStatusCode::ActionNotTakenInsufficientSpace] = "The requested action cannot be performed because there is not enough space on the server.";
    statusDescriptions[(int32)FtpStatusCode::CommandSyntaxError] = "The command has a syntax error or is not a command recognized by the server.";
    statusDescriptions[(int32)FtpStatusCode::ArgumentSyntaxError] = "One or more command arguments has a syntax error.";
    statusDescriptions[(int32)FtpStatusCode::CommandNotImplemented] = "The command is not implemented by the FTP server.";
    statusDescriptions[(int32)FtpStatusCode::BadCommandSequence] = "The sequence of commands is not in the correct order.";
    statusDescriptions[(int32)FtpStatusCode::NotLoggedIn] = "Login information must be sent to the server.";
    statusDescriptions[(int32)FtpStatusCode::AccountNeeded] = "A user account on the server is required.";
    statusDescriptions[(int32)FtpStatusCode::ActionNotTakenFileUnavailable] = "The requested action cannot be performed on the specified file because the file is not available.";
    statusDescriptions[(int32)FtpStatusCode::ActionAbortedUnknownPageType] = "The requested action cannot be taken because the specified page type is unknown.Page types are described in RFC 959 Section 3.1.2.3.";
    statusDescriptions[(int32)FtpStatusCode::FileActionAborted] = "The requested action cannot be performed.";
    statusDescriptions[(int32)FtpStatusCode::ActionNotTakenFilenameNotAllowed] = "The requested action cannot be performed on the specified file.";
  }

  FtpStatusCode statusCode = GetStatusCode();
  if (statusDescriptions.ContainsKey((int32)statusCode))
    description = statusDescriptions[(int32)statusCode];
  else
    description = "Unknown status code.";

  return description;
}

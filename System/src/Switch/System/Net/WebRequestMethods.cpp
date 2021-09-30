#include "../../../../include/Switch/System/Net/WebRequestMethods.hpp"

using namespace System;
using namespace System::Net;

property_<string, readonly_> WebRequestMethods::File::DownloadFile {
  [] {return "GET";}
};

property_<string, readonly_> WebRequestMethods::File::UploadFile {
  [] {return "PUT";}
};

property_<string, readonly_> WebRequestMethods::Ftp::DownloadFile {
  [] {return "FtpDownloadFile";}
};

property_<string, readonly_> WebRequestMethods::Ftp::UploadFile {
  [] {return "FtpUploadFile";}
};

property_<string, readonly_> WebRequestMethods::Ftp::ListDirectory {
  [] {return "ListDirectory";}
};

property_<string, readonly_> WebRequestMethods::Ftp::ListDirectoryDetails {
  [] {return "ListDirectoryDetails";}
};

property_<string, readonly_> WebRequestMethods::Ftp::MakeDirectory {
  [] {return "MakeDirectory";}
};

property_<string, readonly_> WebRequestMethods::Http::Get {
  [] {return "GET";}
};

property_<string, readonly_> WebRequestMethods::Http::Head {
  [] {return "HEAD";}
};

property_<string, readonly_> WebRequestMethods::Http::Post {
  [] {return "POST";}
};

property_<string, readonly_> WebRequestMethods::Http::Put {
  [] {return "PUT";}
};

property_<string, readonly_> WebRequestMethods::Http::Delete {
  [] {return "DELETE";}
};

property_<string, readonly_> WebRequestMethods::Http::Trace {
  [] {return "TRACE";}
};

property_<string, readonly_> WebRequestMethods::Http::Options {
  [] {return "OPTIONS";}
};

#include "../../../include/Switch/System/Uri.hpp"

using namespace System;

property_<string, readonly_> Uri::SchemeDelimiter {
  [] {return "://";}
};

property_<string, readonly_> Uri::UriSchemeFile {
  [] {return "file";}
};

property_<string, readonly_> Uri::UriSchemeFtp {
  [] {return "ftp";}
};

property_<string, readonly_> Uri::UriSchemeGopher {
  [] {return "gopher";}
};

property_<string, readonly_> Uri::UriSchemeHttp {
  [] {return "http";}
};

property_<string, readonly_> Uri::UriSchemeHttps {
  [] {return "https";}
};

property_<string, readonly_> Uri::UriSchemeMailto {
  [] {return "mailto";}
};

property_<string, readonly_> Uri::UriSchemeNetPipe {
  [] {return "net.pipe";}
};

property_<string, readonly_> Uri::UriSchemeNetTcp {
  [] {return "net.tcp";}
};

property_<string, readonly_> Uri::UriSchemeNews {
  [] {return "news";}
};

property_<string, readonly_> Uri::UriSchemeNntp {
  [] {return "nntp";}
};

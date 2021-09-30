#include "Api.hpp"

namespace {
  string EncryptDecryptString(const string& value) {
    // https://kylewbanks.com/blog/Simple-XOR-Encryption-Decryption-in-Cpp
    static const string key = "\"Ytmhpp$}S);_=!'((D09sx4GQdjl?hMo;}yiE&:q|!y(l\"'x$|u>92v*Dv8sV<XD129/BUT{ruxG&prP=D3XgmTDEw:XU7'@^xxm`H%x]xd1cGv,MZDNO+!^M[5Sq``";
    string result;
    int32 index = 0;
    for (char32 c : value)
      result += c != key[index % key.Length] ? System::Char(c ^ key[index++ % key.Length]).ToString() : System::Char(c).ToString();
    return result;
  }
}

string Native::SecurityApi::ToUnsecureString(const System::Security::SecureString& secureString) {
  return EncryptDecryptString(string(secureString.data.ToArray()));
}

string Native::SecurityApi::ToUnsecureString(const string& secureString) {
  return EncryptDecryptString(secureString);
}

System::Security::SecureString Native::SecurityApi::ToSecureSecureString(const string& unsecureString) {
  return System::Security::SecureString(unsecureString.ToCharArray().Data, unsecureString.Length);
}

string Native::SecurityApi::ToSecureString(const string& unsecureString) {
  return EncryptDecryptString(unsecureString);
}

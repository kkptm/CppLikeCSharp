#include "../../../include/Switch/System/Guid.hpp"
#include "../../Native/Api.hpp"

System::Guid System::Guid::NewGuid() {
  return Native::EnvironmentApi::NewGuid();
}

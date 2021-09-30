#include "../../../../Native/Api.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"

using namespace System;
using namespace System::Windows::Forms;

ref<Form> Application::mainForm;
EventHandler Application::Idle;

void Application::EnableVisualStyles() {
  Native::ApplicationApi::EnableVisualStyles();
}

void Application::Exit() {
  Native::ApplicationApi::Exit();
}

void Application::Start() {
  Native::ApplicationApi::Start();
}

void Application::MessageLoop() {
  Native::ApplicationApi::MessageLoop(mainForm(), Idle);
  Idle = EventHandler();
  Native::ApplicationApi::Stop();
}

#include "../../include/Switch/Await.hpp"

Await::Await() {
}

void Await::operator<<(Async<System::Threading::Tasks::Task<>>& async) {
  async().Wait();
}

void Await::operator<<(System::Threading::Tasks::Task<> task) {
  task.Wait();
}

#include "utility/log_system.h"

using namespace melon::utility;

int main()
{
  LogSystem logSystem;
  logSystem.open("./../main.log");
  logSystem.setMaxSize(1024);
  for (int i = 0; i < 100; ++ i)
    logSystem.log(LogSystem::log_warn, __FILE__, __LINE__, "%s", "welcome");

  
  return 0;
}  

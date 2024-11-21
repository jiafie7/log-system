#include "utility/log_system.h"

using namespace melon::utility;

int main()
{
  LogSystem::getInstance()->open("./../main.log");
  LogSystem::getInstance()->setLevel(LogSystem::log_info);
  LogSystem::getInstance()->setMaxSize(1024);
  // LogSystem::getInstance()->setConsole(true);
  for (int i = 0; i < 50; ++ i)
  {
    log_debug("%s %d", "It is a debug.", 123);
    log_info("%s %d.", "It is a info.", 456);
  }
  
  return 0;
}  

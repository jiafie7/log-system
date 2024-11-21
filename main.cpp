#include "utility/log_system.h"

using namespace melon::utility;

int main()
{
  // Initialize the logger
  LogSystem::getInstance()->open("./../app.log");
  LogSystem::getInstance()->setLevel(LogSystem::log_warn);
  LogSystem::getInstance()->setMaxSize(1024);
  LogSystem::getInstance()->setConsole(true);

  // Write logs
  for (int i = 0; i < 20; ++ i)
  {
    log_debug("%s", "This is a debug message.");
    log_info("%s", "Application started.");
    log_warn("%s", "Potential issue detected.");
    log_error("%s", "An error occurred.");
    log_fatal("%s", "Critical failure!");
  }
  
  return 0;
}  

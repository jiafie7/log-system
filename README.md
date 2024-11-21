# Logging System

A cross-platform, efficient, and customizable logging system implemented in C++. This tool provides robust features for managing and maintaining application logs with support for log size limits, log level filtering, terminal output, and log file rolling.

## Features

- **Customizable Initialization**: Configure the logging system at startup with options for maximum size of log file, enable or disable terminal output, log level.
- **Support Log Levels**: Support five levels of logging: DEBUG, INFO, WARN, ERROR, and FATAL.
- **Log Rolling**: Automatically renames and rotates log files when they exceed the maximum size, ensuring that the latest log entries are always in the current log file.
- **Cross-Platform**: Support both Windows and Linux.
- **Convenient Macros**: Simplifies function calls for each log level, allowing quick and clean integration into your code.

## Getting Started

1. Prerequisites

- C++ 11 or later

2. Clone the Repository

```bash
git clone https://github.com/jiafie7/log-system.git
cd log-system
```

2. Build the Project

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

1. Example code

```c
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
  for (int i = 0; i < 50; ++ i)
  {
    log_debug("%s", "This is a debug message.");
    log_info("%s", "Application started.");
    log_warn("%s", "Potential issue detected.");
    log_error("%s", "An error occurred.");
    log_fatal("%s", "Critical failure!");
  }

  return 0;
}
```

2. Run the Example

```bash
./main
```

3. Output

```bash
[WARN]   2024-01-01 23:59:57     ~/main.cpp:18    Potential issue detected.
[ERROR]  2024-01-01 23:59:58     ~/main.cpp:19    An error occurred.
[FATAL]  2024-01-01 23:59:59     ~/main.cpp:20    Critical failure!
```

## API Reference

- void open(const std::string& filename): Open a log file.
- void setLevel(LogLevel level): Set log level.
- void setMaxSize(int size): Set log file maximum size.
- void setConsole(bool console): Set enable or disable terminal output.
- void log(LogLevel level, const char* filename, int line, const char* format, ...): Write log.

### Macros

- log_debug(message): Write a debug-level log.
- log_info(message): Write an info-level log.
- log_warn(message): Write a warning-level log.
- log_error(message): Write an error-level log.
- log_fatal(message): Write a fatal-level log.

## Design Highlights

### Singleton Pattern

Consistent logging behavior across different parts of the application.

### Cross-Platform Support

Platform-specific operations are implemented using preprocessor directives:

```c
#ifdef WIN32
  localtime_s(time_info, ticks);
#else
  localtime_r(ticks, time_info);
#endif
```

### Logging Macros

```c
#define log_debug(format, ...) \
    LogSystem::getInstance()->log(LogSystem::log_debug, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define log_info(format, ...) \
    LogSystem::getInstance()->log(LogSystem::log_info, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define log_warn(format, ...) \
    LogSystem::getInstance()->log(LogSystem::log_warn, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define log_error(format, ...) \
    LogSystem::getInstance()->log(LogSystem::log_error, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define log_fatal(format, ...) \
    LogSystem::getInstance()->log(LogSystem::log_fatal, __FILE__, __LINE__, format, ##__VA_ARGS__)
```

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature-name`.
3. Commit your changes: `git commit -m "Add feature-name"`.
4. Push to your branch: `git push origin feature-name`.
5. Open a pull request.

## License

This project is licensed under the MIT License. See the LICENSE file for more information.

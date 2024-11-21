#pragma once

#include <ctime>
#include <cstdarg>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

namespace melon
{
  namespace utility
  {
    class LogSystem
    {
      public:
        enum LogLevel
        {
          log_debug = 0,
          log_info,
          log_warn,
          log_error,
          log_fatal,
          log_count,
        };
        
        LogSystem();
        ~LogSystem();

        void open(const std::string& filename);
        void close();
        
        void setLevel(LogLevel level);
        void setMaxSize(int size);
        void log(LogLevel level, const char* filename, int line, const char* format, ...);

      private:
        void rotate();

      private:
        std::string m_filename;
        std::ofstream m_fout; 
        int m_log_level;
        int m_len;
        int m_max_size;
        static const char* s_log_level[log_count];
    };
  }
}

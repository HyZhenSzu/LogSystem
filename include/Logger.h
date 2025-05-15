#pragma once

#include <string>
#include <fstream>

namespace Hyzhen{
namespace Utility{

    // In order to make sure that there is only one log system running to avoid conflicts, 
    // the "Logger" class needs to be in the form of a singleton.
    class Logger
    {
    public:
        enum class LogLevel
        {
            DEBUG = 0,
            INFO,
            WARNING,
            ERROR,
            FATAL,

            LEVEL_COUNT
        };

        // 日志内容：时间、级别、文件名、行号、错误信息
        void log(LogLevel level, const char *filename, int line, const char *format, ...);

        static Logger *getInstance();
        void open(std::string fileName);
        void close();

    private:
        Logger();
        ~Logger();

    private:
        std::string m_fileName;
        std::ofstream m_fOut;
        // when you want to get the log level name, just use s_level[int(level)].
        static const char *s_level[int(LogLevel::LEVEL_COUNT)];

        // the unique instance in the whole program.
        static Logger *m_instance;
    };
    
}
}
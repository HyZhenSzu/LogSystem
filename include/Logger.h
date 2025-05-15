#pragma once

#include <string>
#include <fstream>

namespace Hyzhen{
namespace Utility{

    #define debug(format, ...) \
        Logger::getInstance()->log(Logger::LogLevel::DEBUG, __FILE__, __LINE__, format, ##__VA_ARGS__);

    #define info(format, ...) \
        Logger::getInstance()->log(Logger::LogLevel::INFO, __FILE__, __LINE__, format, ##__VA_ARGS__);

    #define warning(format, ...) \
        Logger::getInstance()->log(Logger::LogLevel::WARNING, __FILE__, __LINE__, format, ##__VA_ARGS__);

    #define error(format, ...) \
        Logger::getInstance()->log(Logger::LogLevel::ERROR, __FILE__, __LINE__, format, ##__VA_ARGS__);

    #define fatal(format, ...) \
        Logger::getInstance()->log(Logger::LogLevel::FATAL, __FILE__, __LINE__, format, ##__VA_ARGS__);

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
        void setLevel(LogLevel level);
        void setMaxLength(int maxLength);
        static Logger *getInstance();
        void open(std::string fileName);
        void close();
        void rotate();

    private:
        Logger();
        ~Logger();

    private:
        std::string m_fileName;
        std::ofstream m_fOut;
        LogLevel m_level;
        int m_maxLength;
        int m_currentLength;

        // when you want to get the log level name, just use s_level[int(level)].
        static const char *s_level[int(LogLevel::LEVEL_COUNT)];

        // the unique instance in the whole program.
        static Logger *m_instance;
    };
    
}
}
#include "Logger.h"

using namespace Hyzhen::Utility;

#include <stdexcept>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include <iostream>


void Logger::log(LogLevel level, const char *filename, int line, const char *format, ...)
{
    if(m_fOut.fail())
    {
        throw std::logic_error("Failed to open file: " + m_fileName);
    }

    // get current time
    time_t ticks = time(NULL);
    struct tm *ptm = localtime(&ticks);

    // format the timestamp
    char timestamp[32];
    memset(timestamp, 0, sizeof(timestamp));
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", ptm);
    // std::cout << timestamp << " " << s_level[int(level)] << " " << filename << ":" << line << "\n" << std::flush;

    // format the log message
    const char* formatStr = "%s %s %s:%d ";
    int size = snprintf(nullptr, 0, formatStr, timestamp, s_level[int(level)], filename, line);
    if(size > 0)
    {
        char *buffer = new char[size + 1];
        snprintf(buffer, size + 1, formatStr, timestamp, s_level[int(level)], filename, line);
        buffer[size] = 0;

        // std::cout << buffer << std::flush;
        m_fOut << buffer;
        delete[] buffer;
    }

    // format the log content
    va_list arg_ptr;
    va_start(arg_ptr, format);
    size = vsnprintf(nullptr, 0, format, arg_ptr);
    va_end(arg_ptr);
    if(size > 0)
    {
        char *content = new char[size + 1];
        va_start(arg_ptr, format);
        vsnprintf(content, size + 1, format, arg_ptr);
        va_end(arg_ptr);
        m_fOut << content;
        delete[] content;
    }

    m_fOut << "\n";
    m_fOut.flush();
}


void Logger::open(std::string fileName)
{
    m_fileName = fileName;
    // Using "append" mode to open the file,
    // all the data will be added to the end of the file.
    m_fOut.open(fileName, std::ios::app);
    if(m_fOut.fail())
    {
        throw std::logic_error("Failed to open file: " + fileName);
    }
}

void Logger::close()
{
    m_fOut.close();
}


Logger *Logger::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new Logger();
    }
    return m_instance;
}

Logger::Logger()
{

}

Logger::~Logger()
{

}



// initialize the log level name
const char* Logger::s_level[int(LogLevel::LEVEL_COUNT)] = {
    "DEBUG",
    "INFO",
    "WARNING", 
    "ERROR", 
    "FATAL"
};

Logger *Logger::m_instance = nullptr;
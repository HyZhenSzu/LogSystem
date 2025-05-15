#include "Logger.h"

using namespace Hyzhen::Utility;

#include <stdexcept>
#include <time.h>
#include <string.h>
#include <stdarg.h>
#include <iostream>

void Logger::rotate()
{
    close();
    time_t ticks = time(nullptr);
    struct tm *ptm = localtime(&ticks);
    char timestamp[32];
    memset(timestamp, 0, sizeof(timestamp));
    strftime(timestamp, sizeof(timestamp), ".%Y-%m-%d_%H-%M-%S", ptm);
    std::string fileName = m_fileName + timestamp;
    std::string base = fileName;
    int suffix = 1;
    while(rename(m_fileName.c_str(), fileName.c_str()) != 0)
    {
        // if the name already exists, add a suffix in the end.
        if (errno == EEXIST || errno == EACCES)
        {
            fileName = base + "." + std::to_string(suffix++);
            continue;
        }
        throw std::logic_error("Failed to rename file: " + std::string(strerror(errno)));
    }
    open(m_fileName);
}


void Logger::setMaxLength(int maxLength)
{
    m_maxLength = maxLength;
}

void Logger::setLevel(LogLevel level)
{
    m_level = level;
}

void Logger::log(LogLevel level, const char *filename, int line, const char *format, ...)
{
    if(level < m_level)
    {
        return;
    }

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
        m_currentLength += size;
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
        m_currentLength += size;
        delete[] content;
    }

    m_fOut << "\n";
    m_fOut.flush();

    // if the log file is full, rotate.
    if(m_currentLength >= m_maxLength && m_maxLength > 0)
    {
        rotate();
    }
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

    // if the system restart, check if the log file is full.
    m_fOut.seekp(0, std::ios::end);
    m_currentLength = m_fOut.tellp();
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

Logger::Logger() : m_level(LogLevel::DEBUG), m_maxLength(0), m_currentLength(0)
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
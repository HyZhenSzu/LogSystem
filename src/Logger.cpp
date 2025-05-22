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
    // get current time as the name of the new file.
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

    // if(m_fOut.fail())
    // {
    //     throw std::logic_error("Failed to open file: " + m_fileName);
    // }

    // store the log message.
    std::string fmtMessage = "";

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
        // m_fOut << buffer;
        // m_currentLength += size;
        // delete[] buffer;

        fmtMessage = buffer;
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
        // m_fOut << content;
        // m_currentLength += size;
        // delete[] content;

        fmtMessage += content;
        delete[] content;
    }

    // m_fOut << "\n";
    // m_fOut.flush();

    fmtMessage += "\n";
    m_queue_.push(fmtMessage);

    // if the log file is full, rotate.
    // if(m_currentLength >= m_maxLength && m_maxLength > 0)
    // {
    //     rotate();
    // }
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
    if(m_fOut.is_open())
    {
        m_fOut.flush();
        m_fOut.close();
    }
}


Logger *Logger::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new Logger();
    }
    return m_instance;
}



void Logger::processQueue()
{
    if(m_fOut.fail())
    {
        throw std::logic_error("Failed to open file: " + m_fileName);
    }
    std::string message;
    while(m_queue_.pop(message))
    {
        m_fOut << message;
        m_currentLength += message.length();

        if(m_currentLength >= m_maxLength && m_maxLength > 0)
        {
            rotate();
        }
    }   
    m_fOut.flush();
}

Logger::Logger() : m_level(LogLevel::DEBUG), m_maxLength(0), m_currentLength(0)
{
    b_is_running_ = true;
    // create a thread to process the log messages in queue, 
    // and bind the Logger::processQueue method to it.
    m_workerThread_ = std::thread(&Logger::processQueue, this);
}

Logger::~Logger()
{
    b_is_running_ = false;
    m_queue_.shutdown();
    if(m_workerThread_.joinable())
    {
        // wait for the thread to finish.
        m_workerThread_.join();
    }
    close();
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
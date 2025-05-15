#include "Logger.h"

using namespace Hyzhen::Utility;

#include <stdexcept>
#include <time.h>
#include <string.h>
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
    std::cout << timestamp << " file: " << filename << " line: " << line << "\n" << std::flush;
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
#include "Logger.h"

using namespace Hyzhen::Utility;


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
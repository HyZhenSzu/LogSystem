#include <iostream>
#include <thread>
#include <chrono>

#include "Logger.h"
using namespace Hyzhen::Utility;

int main()
{
    Logger::getInstance()->open("./test.log");
    // Logger::getInstance()->setLevel(Logger::LogLevel::DEBUG);
    Logger::getInstance()->setMaxLength(200);
    // Logger::getInstance()->log(Logger::LogLevel::DEBUG, __FILE__, __LINE__, "Hello World!");
    // Logger::getInstance()->log(Logger::LogLevel::DEBUG, __FILE__, __LINE__, "My name is Hyzhen!");

    debug("Test 1: Single thread debug logging.")
    Logger::getInstance()->log(Logger::LogLevel::ERROR, __FILE__, __LINE__, "Test 2: Single thread %s logging.", "error");

    std::this_thread::sleep_for(std::chrono::seconds(10));    
    Logger::getInstance()->close();
    return 0;
}
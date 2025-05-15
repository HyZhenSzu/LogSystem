#include <iostream>

#include "Logger.h"
using namespace Hyzhen::Utility;

int main()
{
    Logger::getInstance()->open("./test.log");
    // Logger::getInstance()->setLevel(Logger::LogLevel::DEBUG);
    Logger::getInstance()->setMaxLength(200);
    // Logger::getInstance()->log(Logger::LogLevel::DEBUG, __FILE__, __LINE__, "Hello World!");
    // Logger::getInstance()->log(Logger::LogLevel::DEBUG, __FILE__, __LINE__, "My name is Hyzhen!");

    debug("Hello World! This is a debug message.");
    info("My name is Hyzhen. This is a info.");
    warning("I always see warnings when coding.");
    error("I hate errors, but we can't avoid them.");
    fatal("Fatal errors, I don't want to see them.");

    Logger::getInstance()->close();
    return 0;
}
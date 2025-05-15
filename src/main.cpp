#include <iostream>

#include "Logger.h"
using namespace Hyzhen::Utility;

int main()
{
    Logger::getInstance()->open("./test.log");
    Logger::getInstance()->log(Logger::LogLevel::DEBUG, __FILE__, __LINE__, "Hello World!");
    Logger::getInstance()->close();
    return 0;
}
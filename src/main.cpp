#include <iostream>

#include "Logger.h"
using namespace Hyzhen::Utility;

int main()
{
    Logger::getInstance()->open("./test.log");
    return 0;
}
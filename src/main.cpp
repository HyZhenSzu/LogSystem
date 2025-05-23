#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include "Logger.h"
using namespace Hyzhen::Utility;


void logWorkTest(int threadId, int logCount)
{
    for(int i = 0; i < logCount; i++)
    {
        info("Thread: %d, print log: %d", threadId, i);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}


int main()
{
    Logger::getInstance()->open("./test.log");
    // Logger::getInstance()->setLevel(Logger::LogLevel::DEBUG);
    Logger::getInstance()->setMaxLength(10000);
    // Logger::getInstance()->log(Logger::LogLevel::DEBUG, __FILE__, __LINE__, "Hello World!");
    // Logger::getInstance()->log(Logger::LogLevel::DEBUG, __FILE__, __LINE__, "My name is Hyzhen!");

    // debug("Test 1: Single thread debug logging.")
    // Logger::getInstance()->log(Logger::LogLevel::ERROR, __FILE__, __LINE__, "Test 2: Single thread %s logging.", "error");

    int threadCount = 5;
    int logCount = 100;

    std::vector<std::thread> testThreads;
    for (int i = 0; i < threadCount; i++)
    {
        testThreads.push_back(std::thread(logWorkTest, i, logCount));
    }
    for (auto &t : testThreads)
    {
        t.join();
    }

    std::this_thread::sleep_for(std::chrono::seconds(10));    
    Logger::getInstance()->close();
    return 0;
}
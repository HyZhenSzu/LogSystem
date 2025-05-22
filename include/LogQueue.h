#pragma once

#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>
#include <atomic>

namespace Hyzhen::Utility
{
    class LogQueue
    {
    public:
        LogQueue();
        ~LogQueue();
        LogQueue(const LogQueue&) = delete;
        LogQueue &operator=(const LogQueue &) = delete;

        void push(const std::string& message);
        bool pop(std::string& message);
        void shutdown();

    private:
        std::queue<std::string> m_queue_;
        mutable std::mutex m_mutex_;
        std::condition_variable m_cv_; 
        // bool b_is_shutdown_ = false; // flag to indicate if the queue is shutdown
        std::atomic<bool> b_is_shutdown_{false};
    };
}
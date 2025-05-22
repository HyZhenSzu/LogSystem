#include "LogQueue.h"

using namespace Hyzhen::Utility;

void LogQueue::push(const std::string& message)
{
    //
    // push the message to the queue and notify the consumer.
    //
    std::unique_lock<std::mutex> lock(m_mutex_);
    m_queue_.push(message);
    m_cv_.notify_one();
}

bool LogQueue::pop(std::string& message)
{
    std::unique_lock<std::mutex> lock(m_mutex_);
    // if the queue is empty but not shutdown, wait for a message.
    // while(m_queue_.empty() && !b_is_shutdown_)
    // {
    //     m_cv_.wait(lock);
    // }
    m_cv_.wait(lock, [this](){ 
        return !m_queue_.empty() || b_is_shutdown_;
    });

    // if there is not message and queue is shutdown, return false.
    if(b_is_shutdown_ && m_queue_.empty())
    {
        return false;
    }

    message = m_queue_.front();
    m_queue_.pop();
    return true;
}

void LogQueue::shutdown()
{
    std::unique_lock<std::mutex> lock(m_mutex_);
    b_is_shutdown_ = true;
    m_cv_.notify_all();
}


LogQueue::LogQueue()
{

}

LogQueue::~LogQueue()
{
    shutdown();
}

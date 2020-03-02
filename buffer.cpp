#include "buffer.hpp"
#include <iostream>

buffer::~buffer()
{
    std::unique_lock<std::mutex> lock(mutex);
    while(!isEmpty())
    {
        queue.pop();
    }
    lock.unlock();
    cond.notify_all();
}

void buffer::add(std::pair<int, std::string> msg)
{
    std::unique_lock<std::mutex> lock(mutex);
    cond.wait(lock, [this]() { return !isFull(); });
    queue.push(msg);
    auto time =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << ctime(&time) << "[Buffer " << name << "] Added element "
              << msg.second << " with priority " << msg.first
              << ". Size: " << size() << std::endl;
    lock.unlock();
    cond.notify_all();
}

void buffer::consume(std::pair<int, std::string> &msg)
{
    std::unique_lock<std::mutex> lock(mutex);
    cond.wait(lock, [this]() { return !isEmpty(); });
    msg = queue.top();
    queue.pop();
    auto time =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::cout << ctime(&time) << "[Buffer " << name << "] Taken element "
              << msg.second << " with priority " << msg.first
              << ". Size: " << size() << std::endl;
    lock.unlock();
    cond.notify_all();
}

bool buffer::isFull() const { return queue.size() >= capacity; }

bool buffer::isEmpty() const { return queue.size() == 0; }

int buffer::size() const { return queue.size(); }

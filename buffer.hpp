#ifndef _buffer_
#define _buffer_

#include <condition_variable>
#include <mutex>
#include <queue>

class buffer
{
  private:
    std::mutex mutex;
    std::condition_variable cond;
    std::priority_queue<std::pair<int, std::string>> queue;
    int capacity;

  public:
    const char name;
    buffer(int maxSize, char name) : capacity(maxSize), name(name){};
    ~buffer();
    void add(std::pair<int, std::string> msg);
    void consume(std::pair<int, std::string> &msg);
    bool isFull() const;
    bool isEmpty() const;
    int size() const;
};

#endif // !_buffer_
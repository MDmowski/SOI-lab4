#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>
#include <time.h>

#include "buffer.hpp"
#include "randomString.cpp"
void producer(buffer &buf)
{
    srand(time(NULL));
    while(true)
    {
        auto time = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());
        std::cout << "[Producer " << buf.name << "][Buffer " << buf.name << "] "
                  << ctime(&time) << "Size before insertion " << buf.size()
                  << std::endl;
        std::string text = randomString(3);

        time = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());
        std::cout << "[Producer " << buf.name << "][Buffer " << buf.name << "] "
                  << ctime(&time) << "Trying to add element " << text
                  << std::endl;
                  
        buf.add(std::make_pair(0, text));

        time = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());
        // std::cout << "[Producer " << buf.name << "][Buffer " << buf.name <<
        // "] "
        //           << ctime(&time) << "Added element " << text
        //           << ". Size after insertion " << buf.size() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}
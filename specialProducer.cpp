#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>
#include <time.h>

#include "buffer.hpp"
#include "randomString.cpp"
void specialProducer(buffer &Abuf, buffer &Bbuf, buffer &Cbuf)
{
    srand(time(NULL));
    while(true)
    {
        int whichQueue = rand() % 3;
        if(whichQueue == 0)
        {
            auto time = std::chrono::system_clock::to_time_t(
                std::chrono::system_clock::now());
            std::cout << "[SProducer][Buffer " << Abuf.name << "] "
                      << ctime(&time) << "Size before insertion " << Abuf.size()
                      << std::endl;
            std::string text = randomString(3);

            time = std::chrono::system_clock::to_time_t(
                std::chrono::system_clock::now());
            std::cout << "[SProducer][Buffer " << Abuf.name << "] "
                      << ctime(&time) << "Trying to add element " << text
                      << std::endl;
            Abuf.add(std::make_pair(1, text));

            // time = std::chrono::system_clock::to_time_t(
            //     std::chrono::system_clock::now());
            // std::cout << "[SProducer][Buffer " << Abuf.name << "] "
            //           << ctime(&time) << "Added element " << text
            //           << ". Size after insertion " << Abuf.size() <<
            //           std::endl;
        }
        if(whichQueue == 1)
        {
            auto time = std::chrono::system_clock::to_time_t(
                std::chrono::system_clock::now());
            std::cout << "[SProducer][Buffer " << Bbuf.name << "] "
                      << ctime(&time) << "Size before insertion " << Bbuf.size()
                      << std::endl;
            std::string text = randomString(3);

            time = std::chrono::system_clock::to_time_t(
                std::chrono::system_clock::now());
            std::cout << "[SProducer][Buffer " << Bbuf.name << "] "
                      << ctime(&time) << "Trying to add element " << text
                      << std::endl;
            Bbuf.add(std::make_pair(1, text));

            // time = std::chrono::system_clock::to_time_t(
            //     std::chrono::system_clock::now());
            // std::cout << "[SProducer][Buffer " << Bbuf.name << "] "
            //           << ctime(&time) << "Added element " << text
            //           << ". Size after insertion " << Bbuf.size() <<
            //           std::endl;
        }
        if(whichQueue == 2)
        {
            auto time = std::chrono::system_clock::to_time_t(
                std::chrono::system_clock::now());
            std::cout << "[SProducer][Buffer " << Cbuf.name << "] "
                      << ctime(&time) << "Size before insertion " << Cbuf.size()
                      << std::endl;
            std::string text = randomString(3);

            time = std::chrono::system_clock::to_time_t(
                std::chrono::system_clock::now());
            std::cout << "[SProducer][Buffer " << Cbuf.name << "] "
                      << ctime(&time) << "Trying to add element " << text
                      << std::endl;
            Cbuf.add(std::make_pair(1, text));

            // time = std::chrono::system_clock::to_time_t(
            //     std::chrono::system_clock::now());
            // std::cout << "[SProducer][Buffer " << Cbuf.name << "] "
            //           << ctime(&time) << "Added element " << text
            //           << ". Size after insertion " << Cbuf.size() <<
            //           std::endl;
        }
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}
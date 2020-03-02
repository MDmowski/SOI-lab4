#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>
#include <time.h>

#include "buffer.hpp"
#include "randomString.cpp"
void oProducer(buffer &Abuf, buffer &Bbuf, buffer &Cbuf, int waitTime)
{
    srand(time(NULL));
    while(true)
    {
        if(Abuf.size() > Bbuf.size() && Abuf.size() > Cbuf.size())
        {
            auto time = std::chrono::system_clock::to_time_t(
                std::chrono::system_clock::now());
            std::cout << "[OProducer][Buffer " << Abuf.name << "] "
                      << ctime(&time) << "Size before insertion " << Abuf.size()
                      << std::endl;

            time = std::chrono::system_clock::to_time_t(
                std::chrono::system_clock::now());
            std::cout << "[OProducer][Buffer " << Abuf.name << "] "
                      << ctime(&time) << "Trying to add empty element..."
                      << std::endl;
            Abuf.add(std::make_pair(2, ""));

            // time = std::chrono::system_clock::to_time_t(
            //     std::chrono::system_clock::now());
            // std::cout << "[OProducer][Buffer " << Abuf.name << "] "
            //           << ctime(&time) << "Added empty element"
            //           << ". Size after insertion " << Abuf.size() <<
            //           std::endl;
        }
        if(Bbuf.size() > Abuf.size() && Bbuf.size() > Cbuf.size())
        {
            auto time = std::chrono::system_clock::to_time_t(
                std::chrono::system_clock::now());
            std::cout << "[OProducer][Buffer " << Bbuf.name << "] "
                      << ctime(&time) << "Size before insertion " << Bbuf.size()
                      << std::endl;

            time = std::chrono::system_clock::to_time_t(
                std::chrono::system_clock::now());
            std::cout << "[OProducer][Buffer " << Bbuf.name << "] "
                      << ctime(&time) << "Trying to add empty element..."
                      << std::endl;
            Bbuf.add(std::make_pair(2, ""));

            // time = std::chrono::system_clock::to_time_t(
            //     std::chrono::system_clock::now());
            // std::cout << "[OProducer][Buffer " << Bbuf.name << "] "
            //           << ctime(&time) << "Added empty element"
            //           << ". Size after insertion " << Bbuf.size() <<
            //           std::endl;
        }
        if(Cbuf.size() > Bbuf.size() && Cbuf.size() > Abuf.size())
        {
            auto time = std::chrono::system_clock::to_time_t(
                std::chrono::system_clock::now());
            std::cout << "[OProducer][Buffer " << Cbuf.name << "] "
                      << ctime(&time) << "Size before insertion " << Cbuf.size()
                      << std::endl;

            time = std::chrono::system_clock::to_time_t(
                std::chrono::system_clock::now());
            std::cout << "[OProducer][Buffer " << Cbuf.name << "] "
                      << ctime(&time) << "Trying to add empty element..."
                      << std::endl;
            Cbuf.add(std::make_pair(2, ""));

            // time = std::chrono::system_clock::to_time_t(
            //     std::chrono::system_clock::now());
            // std::cout << "[OProducer][Buffer " << Cbuf.name << "] "
            //           << ctime(&time) << "Added empty element"
            //           << ". Size after insertion " << Cbuf.size() <<
            //           std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    }
}
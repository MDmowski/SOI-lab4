#include "buffer.hpp"
#include "randomString.cpp"
#include <chrono>
#include <iostream>
#include <thread>

void Aconsumer(buffer &Abuf, buffer &Bbuf, buffer &Cbuf, int pr)
{
    int cleaning = 0;
    srand(time(NULL));
    while(true)
    {
        auto time = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());
        std::cout << "[Consumer A][Buffer " << Abuf.name << "] " << ctime(&time)
                  << "Size: " << Abuf.size() << ". Trying to consume element."
                  << std::endl;

        std::pair<int, std::string> msg;
        Abuf.consume(msg);
        if(msg.first == 2)
            cleaning = 5;

        time = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());
        std::cout << "[Consumer A][Buffer " << Abuf.name << "] " << ctime(&time)
                  << "Consumed element " << msg.second
                  << ". Size after consumption " << Abuf.size() << std::endl;
        if(msg.first != 2 && cleaning == 0)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        if(cleaning > 0)
            cleaning--;
        if(msg.second.size() != 0)
        {
            char letter = msg.second.at(0);
            msg.second.erase(0, 1);
            if((rand() % 100) < pr)
            {
                std::string add = randomString(1);
                msg.second.append(add);
            }
            if(letter == 'A')
            {
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer A][Buffer " << Abuf.name << "] "
                          << ctime(&time) << "Size before insertion "
                          << Abuf.size() << std::endl;

                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer A][Buffer " << Abuf.name << "] "
                          << ctime(&time) << "Trying to add element "
                          << msg.second << std::endl;
                Abuf.add(msg);
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer A][Buffer " << Abuf.name << "] "
                          << ctime(&time) << "Added element " << msg.second
                          << ". Size after insertion " << Abuf.size()
                          << std::endl;
            }
            if(letter == 'B')
            {
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer A][Buffer " << Bbuf.name << "] "
                          << ctime(&time) << "Size before insertion "
                          << Bbuf.size() << std::endl;

                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer A][Buffer " << Bbuf.name << "] "
                          << ctime(&time) << "Trying to add element "
                          << msg.second << std::endl;
                Bbuf.add(msg);
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer A][Buffer " << Bbuf.name << "] "
                          << ctime(&time) << "Added element " << msg.second
                          << ". Size after insertion " << Bbuf.size()
                          << std::endl;
            }
            if(letter == 'C')
            {
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer A][Buffer " << Cbuf.name << "] "
                          << ctime(&time) << "Size before insertion "
                          << Cbuf.size() << std::endl;

                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer A][Buffer " << Cbuf.name << "] "
                          << ctime(&time) << "Trying to add element "
                          << msg.second << std::endl;
                Cbuf.add(msg);
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer A][Buffer " << Cbuf.name << "] "
                          << ctime(&time) << "Added element " << msg.second
                          << ". Size after insertion " << Cbuf.size()
                          << std::endl;
            }
        }
    }
}

void Bconsumer(buffer &Abuf, buffer &Bbuf, buffer &Cbuf, int pr)
{
    int cleaning = 0;
    srand(time(NULL));
    while(true)
    {
        auto time = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());
        std::cout << "[Consumer B][Buffer " << Bbuf.name << "] " << ctime(&time)
                  << "Size: " << Bbuf.size() << ". Trying to consume element."
                  << std::endl;

        std::pair<int, std::string> msg;
        Bbuf.consume(msg);
        std::cout << "Priority " << msg.first << " msg: " << msg.second
                  << std::endl;
        if(msg.first == 2)
            cleaning = 5;

        time = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());
        std::cout << "[Consumer B][Buffer " << Bbuf.name << "] " << ctime(&time)
                  << "Consumed element " << msg.second
                  << ". Size after consumption " << Bbuf.size() << std::endl;
        if(msg.first != 2 && cleaning == 0)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        if(cleaning > 0)
        {
            // std::cout<<"HERE\n\n";
            cleaning--;
        }
        if(msg.second.size() != 0)
        {
            char letter = msg.second.at(0);
            msg.second.erase(0, 1);
            if((rand() % 100) < pr)
            {
                std::string add = randomString(1);
                msg.second.append(add);
            }
            if(letter == 'A')
            {
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer B][Buffer " << Abuf.name << "] "
                          << ctime(&time) << "Size before insertion "
                          << Abuf.size() << std::endl;

                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer B][Buffer " << Abuf.name << "] "
                          << ctime(&time) << "Trying to add element "
                          << msg.second << std::endl;
                Abuf.add(msg);
                // time = std::chrono::system_clock::to_time_t(
                //     std::chrono::system_clock::now());
                // std::cout << "[Consumer B][Buffer " << Abuf.name << "] "
                //           << ctime(&time) << "Added element " << msg.second
                //           << ". Size after insertion " << Abuf.size()
                //           << std::endl;
            }
            if(letter == 'B')
            {
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer B][Buffer " << Bbuf.name << "] "
                          << ctime(&time) << "Size before insertion "
                          << Bbuf.size() << std::endl;

                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer B][Buffer " << Bbuf.name << "] "
                          << ctime(&time) << "Trying to add element "
                          << msg.second << std::endl;
                Bbuf.add(msg);
                // time = std::chrono::system_clock::to_time_t(
                //     std::chrono::system_clock::now());
                // std::cout << "[Consumer B][Buffer " << Bbuf.name << "] "
                //           << ctime(&time) << "Added element " << msg.second
                //           << ". Size after insertion " << Bbuf.size()
                //           << std::endl;
            }
            if(letter == 'C')
            {
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer B][Buffer " << Cbuf.name << "] "
                          << ctime(&time) << "Size before insertion "
                          << Cbuf.size() << std::endl;

                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer B][Buffer " << Cbuf.name << "] "
                          << ctime(&time) << "Trying to add element "
                          << msg.second << std::endl;
                Cbuf.add(msg);
                // time = std::chrono::system_clock::to_time_t(
                //     std::chrono::system_clock::now());
                // std::cout << "[Consumer B][Buffer " << Cbuf.name << "] "
                //           << ctime(&time) << "Added element " << msg.second
                //           << ". Size after insertion " << Cbuf.size()
                //           << std::endl;
            }
        }
    }
}

void Cconsumer(buffer &Abuf, buffer &Bbuf, buffer &Cbuf, int pr)
{
    int cleaning = 0;
    srand(time(NULL));
    while(true)
    {
        auto time = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());
        std::cout << "[Consumer C][Buffer " << Cbuf.name << "] " << ctime(&time)
                  << "Size: " << Cbuf.size() << ". Trying to consume element."
                  << std::endl;

        std::pair<int, std::string> msg;
        Cbuf.consume(msg);
        if(msg.first == 2)
            cleaning = 5;

        time = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());
        std::cout << "[Consumer C][Buffer " << Cbuf.name << "] " << ctime(&time)
                  << "Consumed element " << msg.second
                  << ". Size after consumption " << Cbuf.size() << std::endl;
        if(msg.first != 2 && cleaning == 0)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        if(cleaning > 0)
            cleaning--;

        if(msg.second.size() != 0)
        {
            char letter = msg.second.at(0);
            msg.second.erase(0, 1);
            if((rand() % 100) < pr)
            {
                std::string add = randomString(1);
                msg.second.append(add);
            }
            if(letter == 'A')
            {
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer C][Buffer " << Abuf.name << "] "
                          << ctime(&time) << "Size before insertion "
                          << Abuf.size() << std::endl;

                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer C][Buffer " << Abuf.name << "] "
                          << ctime(&time) << "Trying to add element "
                          << msg.second << std::endl;
                Abuf.add(msg);
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer C][Buffer " << Abuf.name << "] "
                          << ctime(&time) << "Added element " << msg.second
                          << ". Size after insertion " << Abuf.size()
                          << std::endl;
            }
            if(letter == 'B')
            {
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer C][Buffer " << Bbuf.name << "] "
                          << ctime(&time) << "Size before insertion "
                          << Bbuf.size() << std::endl;

                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer C][Buffer " << Bbuf.name << "] "
                          << ctime(&time) << "Trying to add element "
                          << msg.second << std::endl;
                Bbuf.add(msg);
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer C][Buffer " << Bbuf.name << "] "
                          << ctime(&time) << "Added element " << msg.second
                          << ". Size after insertion " << Bbuf.size()
                          << std::endl;
            }
            if(letter == 'C')
            {
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer C][Buffer " << Cbuf.name << "] "
                          << ctime(&time) << "Size before insertion "
                          << Cbuf.size() << std::endl;

                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer C][Buffer " << Cbuf.name << "] "
                          << ctime(&time) << "Trying to add element "
                          << msg.second << std::endl;
                Cbuf.add(msg);
                time = std::chrono::system_clock::to_time_t(
                    std::chrono::system_clock::now());
                std::cout << "[Consumer C][Buffer " << Cbuf.name << "] "
                          << ctime(&time) << "Added element " << msg.second
                          << ". Size after insertion " << Cbuf.size()
                          << std::endl;
            }
        }
    }
}
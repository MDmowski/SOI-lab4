#ifndef _randomString_
#define _randomString_

#include <algorithm>
#include <string>

std::string randomString(size_t length)
{
    auto randchar = []() -> char {
        const char charset[] = "ABC";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    std::string str(length, 0);
    std::generate_n(str.begin(), length, randchar);
    return str;
}

#endif
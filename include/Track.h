#pragma once
#include <ctime>

class Track_t
{
public:
    std::string name = "none";
    int length = 0;
    std::time_t creation_time = 0;
};
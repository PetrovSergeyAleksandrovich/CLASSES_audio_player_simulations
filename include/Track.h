#pragma once
#include <ctime>

class Track_t
{
public:
    std::string name = "none";
    std::string length = "0";
    std::time_t creation_time = 0;
};
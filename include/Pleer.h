#pragma once
#include "Track.h"
#include <iostream>
#include <vector>

class Pleer_t
{
public:

    std::vector<Track_t> playlist = {
            {"bla", "180", 912345548},
            {"givemebackmomoney", "150", 91234512},
            {"berezka", "300", 9123456780}
            };

    void play()
    {
        std::string user_input = "none";

        std::cout << "LIST:\n";
        for(int i = 0; i < playlist.size(); i++)
        {
            std::cout << "name: " << playlist[i].name << std::endl << std::endl;
        }

        std::cout << "type song name:";
        std::cin >> user_input;
        for(int i = 0; i < playlist.size(); i++)
        {
            if(user_input == playlist[i].name)
            {
                std::cout << "song length: " << playlist[i].length << " seconds" << std::endl;
                std::cout << "created: " << std::asctime(std::localtime(&(playlist[i].creation_time))) << std::endl;
            }
        }

    }

};
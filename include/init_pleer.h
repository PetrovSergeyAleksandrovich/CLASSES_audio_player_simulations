#pragma once
#include "Pleer.h"
#include "Track.h"

Pleer_t* pleer = new Pleer_t;

void init_pleer()
{
    do {
        Track_t* track = new Track_t;
        std::string answer, user_input_str;
        int user_input_int;

        std::cout << "you want add track? y/n\n:";
        std::cin >> answer;

        while(answer != "y" && answer != "n")
        {
            std::cout << "you want add track? y/n\n:";
            std::cin >> answer;
        }
        if(answer == "y")
        {
            std::cout << "type name: ";
            std::cin >> user_input_str;
            track->name = user_input_str;
            std::cout << "type length seconds: ";
            std::cin >> user_input_int;
            track->length = user_input_int;
            std::time_t t = std::time(nullptr);
            track->creation_time = t;
            pleer->playlist.push_back(*track);
        }

        delete track;
        if(answer == "n") break;

    } while(true);
}

void delete_pleer_heap()
{
    delete pleer;
}

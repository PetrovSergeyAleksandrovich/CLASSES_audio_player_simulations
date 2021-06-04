#pragma once
#include "Pleer.h"
#include "Track.h"

Pleer_t* pleer = new Pleer_t;


void init_playlist()
{
    Track_t* track = new Track_t;
    do {
        std::string answer, user_input;
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
            std::cin >> user_input;
            track->name = user_input;
            std::cout << "type length seconds: ";
            std::cin >> user_input;
            track->length = user_input;
            std::time_t t = std::time(nullptr);
            track->creation_time = t;
            //problem with push_back;
            //pleer->playlist.push_back(track);
        }
        delete track;
        if(answer == "n") break;
    } while(true);
}

void clear_heap()
{
    delete pleer;
}

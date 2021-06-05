#include <iostream>
#include "init_pleer.h"

int main()
{
    init_pleer();

    do {
        std::string command = "none";

        std::cout << "type play/pause/next/stop/exit: ";
        std::cin >> command;

        if(command == "play") pleer->play();
        else if(command == "pause") pleer->pause();
        else if(command == "next") pleer->next();
        else if(command == "stop") pleer->stop();
        else if(command == "exit") break;

    } while(true);

    delete_pleer_heap();

    return 0;
}

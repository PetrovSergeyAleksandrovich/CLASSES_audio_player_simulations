#include <iostream>
#include "init_playlist.h"

int main()
{
    std::string command = "none";

    init_playlist();
    do {
        std::cout << "type play/pause/next/stop/exit: ";
        std::cin >> command;
        if(command == "play") pleer->play();

    } while(command!="exit");
    clear_heap();

    return 0;
}

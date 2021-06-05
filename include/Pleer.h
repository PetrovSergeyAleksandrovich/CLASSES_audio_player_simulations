#pragma once
#include "Track.h"
#include <iostream>
#include <vector>

class Pleer_t
{
private:
    bool isPlaying = false;
    bool isPause = false;
    bool isStop = true;
    int last_playing = 0;

public:

    std::vector<Track_t> playlist = {
            {"song2", 180, 1112345548},
            {"givemebackmymoney", 150, 91234512},
            {"nevermind", 300, 9123456780},
            {"paparoach", 500, 10123456780}
            };

    bool getPlayingInfo()
    {
        return isPlaying;
    }

    int getLastSong(int last_song)
    {
        last_playing = last_song;
        return last_playing;
    }

    int setLastSong()
    {
        return last_playing;
    }

    void setPlayingOn()
    {
        isPlaying = true;
        isPause = false;
        isStop = false;
    }

    void setStopAll()
    {
        isPlaying = false;
        isPause = false;
        isStop = true;
    }

    void setPauseOn()
    {
        isPlaying = false;
        isPause = true;
        isStop = false;
    }

    void setPauseOff()
    {
        isPlaying = true;
        isPause = false;
        isStop = false;
    }

    void play()
    {
        std::string user_input = "none";

        if(!isPause && !isPlaying && isStop)
        {
            std::cout << "\nLIST OF SONGS:\n";
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
                    std::cout << "NOW PLAYING: " << playlist[i].name << std::endl;
                    std::cout << "song length: " << playlist[i].length << " seconds" << std::endl;
                    std::cout << "created: " << std::asctime(std::localtime(&(playlist[i].creation_time))) << std::endl;
                    setPlayingOn();
                    getLastSong(i);
                }
            }
        }
        else if(isPause && !isPlaying && !isStop)
        {
            std::cout << "CONTINUE PLAYING: " << playlist[setLastSong()].name << std::endl;
            std::cout << "song length: " << playlist[setLastSong()].length << " seconds" << std::endl;
            std::cout << "created: " << std::asctime(std::localtime(&(playlist[setLastSong()].creation_time))) << std::endl;
            setPlayingOn();
        }
        else
        {
            std::cout << "none" << std::endl;
        }
    }

    void pause()
    {
        if(getPlayingInfo())
        {
            std::cout << "PAUSED" << std::endl;
            setPauseOn();
        }
    }

    void next()
    {
        std::srand(time(NULL));
        int i = rand() % playlist.size();
        std::cout << "NOW PLAYING: " << playlist[i].name << std::endl;
        std::cout << "song length: " << playlist[i].length << " seconds" << std::endl;
        std::cout << "created: " << std::asctime(std::localtime(&(playlist[i].creation_time))) << std::endl;
        setPlayingOn();
        getLastSong(i);
    }

    void stop()
    {
        if(getPlayingInfo())
        {
            setStopAll();
            std::cout << "NOT PLAYING" << std::endl;
        }
    }
};
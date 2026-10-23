#include <iostream>
#include <string>
#include "circular_ll.h"

int main(){
    CircularList<std::string>* playlist = nullptr;
    CircularList<std::string>* current = nullptr;

    int choice;

    do{
        std::cout << "\n=========================";
        std::cout << "\nSONG PLAYLIST";
        std::cout << "\n=========================\n";
        std::cout << "1. Add Song\n";
        std::cout << "2. Remove Song\n";
        std::cout << "3. Play Playlist\n";
        std::cout << "4. Next Song\n";
        std::cout << "5. Previous Song\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter Choice: ";
        std::cin >> choice;

        switch(choice){

        case 1:{
            char enterRepeat = 'y';
            std::string song;

            while(enterRepeat == 'y'){
                std::cout << "Enter song: ";
                std::cin.ignore();
                getline(std::cin, song);

                addSong(song, &playlist);

                if(current == nullptr)
                    current = playlist;

                std::cout << "Add another? (y/n): ";
                std::cin >> enterRepeat;
            }

            break;
        }

        case 2:{
            std::string song;
            std::cout << "Remove song: ";
            std::cin.ignore();
            getline(std::cin, song);
            removeSong(song, &playlist);
            break;
        }

        case 3:
            playSongs(playlist);
            break;

        case 4:
            nextSong(&current);
            break;

        case 5:
            previousSong(&current);
            break;

        case 6:
            deletePlaylist(&playlist);
            std::cout << "Program End\n";
            break;

        default:
            std::cout << "Invalid choice\n";
        }

    } while(choice != 6);

    return 0;
}
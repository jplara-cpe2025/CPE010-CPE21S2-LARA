#ifndef CIRCULAR_LL_H
#define CIRCULAR_LL_H

#include <iostream>

template <typename T>
class CircularList{
    public:
        T data;
        CircularList<T>* next = nullptr;
        CircularList<T>* prev = nullptr;
};

template <typename T>
CircularList<T>* CreateNewNode(T data){

    CircularList<T>* node = new CircularList<T>;

    node->data = data;
    node->next = node;
    node->prev = node;

    return node;
}

template <typename T>
void addSong(T data, CircularList<T>** head){

    CircularList<T>* node = CreateNewNode(data);

    if(*head == nullptr){
        *head = node;
        return;
    }

    CircularList<T>* tail = (*head)->prev;

    tail->next = node;
    node->prev = tail;
    node->next = *head;
    (*head)->prev = node;
}

template <typename T>
void playSongs(CircularList<T>* head){

    if(head == nullptr){
        std::cout << "Playlist is empty\n";
        return;
    }

    CircularList<T>* temp = head;

    std::cout << "\nPlaylist:\n";

    do{
        std::cout << temp->data << std::endl;
        temp = temp->next;

    }while(temp != head);
}

template <typename T>
void removeSong(T song, CircularList<T>** head){

    if(*head == nullptr)
        return;

    CircularList<T>* temp = *head;

    do{
        if(temp->data == song){

            if(temp->next == temp){
                delete temp;
                *head = nullptr;
                return;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if(temp == *head)
                *head = temp->next;

            delete temp;

            std::cout << "Song removed\n";
            return;
        }

        temp = temp->next;

    }while(temp != *head);

    std::cout << "Song not found\n";
}

template <typename T>
void nextSong(CircularList<T>** current){

    if(*current == nullptr)
        return;

    *current = (*current)->next;

    std::cout << "Current Song: " << (*current)->data << std::endl;
}

template <typename T>
void previousSong(CircularList<T>** current){

    if(*current == nullptr)
        return;

    *current = (*current)->prev;

    std::cout << "Current Song: " << (*current)->data << std::endl;
}

template <typename T>
void deletePlaylist(CircularList<T>** head){

    if(*head == nullptr)
        return;

    CircularList<T>* temp = (*head)->next;

    while(temp != *head){

        CircularList<T>* del = temp;
        temp = temp->next;

        delete del;
    }

    delete *head;
    *head = nullptr;
}

#endif
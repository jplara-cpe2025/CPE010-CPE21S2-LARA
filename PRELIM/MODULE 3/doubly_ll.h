#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

#include <iostream>

template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T>* prev = nullptr;
        DoubleList<T>* next = nullptr;
};

template <typename T>
DoubleList<T>* CreateNewNode(T newData){
    // dynamically allocate a new memory for the node    
    DoubleList<T>* newNode = new DoubleList<T>;

    // store the data in the node
    newNode->data = newData;

    // point next and prev to null
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // return address of newly created node 
    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T>* CurrentNode){
    // temp variable to store the last node visited
    DoubleList<T> *tail;

    // check if the list is empty
    if (CurrentNode == nullptr) {
        std::cout << "The list is empty" << std::endl;
        return;
    }

    std::cout << "Forward:\n";

    // Move forward and print
    while (CurrentNode != nullptr){
        std::cout << CurrentNode->data << " ";
        tail = CurrentNode;
        CurrentNode = CurrentNode->next;
    }

    // add a next line
    std::cout << std::endl;

    // move backward
    std::cout << "Backward:\n";

    while(tail != nullptr){
        std::cout << tail->data << " ";
        tail = tail->prev;
    }

}

// Inserting at the head of the list
template <typename T>
void dllInsertHead(T newData, DoubleList<T> ** CurrentHead){

    // creating a new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    // new node point to the current head
    newNode->next = *CurrentHead;

    // current head point back to newNode
    (*CurrentHead)->prev = newNode;

    // update the pointer head
    *CurrentHead = newNode;

}

template <typename T>
void dllInsertEnd(T newData, DoubleList<T>* CurrentHead){
    // create a new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    // traverse until we reach the last node
    while(CurrentHead->next != nullptr){
        CurrentHead = CurrentHead->next;
    }

    // connect the last node to the new node
    CurrentHead->next = newNode;

    // connect the new node to the last node
    newNode->prev = CurrentHead;

}


// GENERAL INSERT??
template <typename T>
void dllGenInsert(T newData, DoubleList<T>* CurrentNode){

    // create a new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    // new node points to the next node
    newNode->next = CurrentNode->next;

    // new node points back to the current node
    newNode->prev = CurrentNode;

    // if current node is not the last node
    if(CurrentNode->next != nullptr){
        // next node points back to the new node
        CurrentNode->next->prev = newNode;
    }

    // current node points to the new node
    CurrentNode->next = newNode;

}

// DELETE A NODE??
template <typename T>
void dllDeleteNode(DoubleList<T>* DeleteNode, DoubleList<T>** CurrentHead){

    // check if the node is empty
    if(DeleteNode == nullptr){
        return;
    }

    // deleting the head node
    if(DeleteNode->prev == nullptr){
        *CurrentHead = DeleteNode->next;

        if(*CurrentHead != nullptr){
            (*CurrentHead)->prev = nullptr;
        }
    
    } else {
        // previous node points to the next node
        DeleteNode->prev->next = DeleteNode->next;

        // if the deleted node is not the last node
        if(DeleteNode->next != nullptr){
            // next node points back to the previous node
            DeleteNode->next->prev = DeleteNode->prev;
        }
    }
    // free the allocated memory
    delete DeleteNode;

}

#endif

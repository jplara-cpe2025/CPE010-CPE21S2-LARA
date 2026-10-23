#ifndef SINGLY_LL_H
#define SINGLY_LL_H

#include <iostream>

template <typename T>
class SingleList{
    public:
        T data; //this contains the data to be stored in the node
        SingleList<T>* next = nullptr;
};

template <typename T>
void ListTraversal(SingleList<T>* head){

    if (head == nullptr){
        std::cout << "The list is empty";
        return;
    }

    while(head != nullptr){
        // PRINT data OF n
        std::cout<<head->data;

        if(head->next != nullptr){
            std::cout << "->";
        }

        // GO TO NEXT NODE n -> next
        head = head->next;
    }

    std::cout << std::endl;
}

template <typename T>
void sllinsertHead(T newData, SingleList<T>** head){

    // 1. Allocate new memory for the new code
    SingleList<T>* newNode = new SingleList<T>;
    // 2. Put our data into the new node
    newNode->data = newData;
    // 3. Set next to the new node to point to the previous head
    newNode->next = *head;
    // 4. Reset head to the new node
    *head = newNode;
}

template <typename T>
void sllGeneralInsert(T newData, SingleList<T>* prevNode){

    //1. Check if it is the head node (previous node is null)
    if(prevNode == nullptr){
        //2. If null, print "Previous node cannot be null."
        std::cout<<"Previous value cannot be null"<<std::endl;
        return;
    }
    //3. Allocate a new node
    SingleList<T>* newNode = new SingleList<T>;
    //4. Store data in the new node
    newNode->data = newData;
    //5. Point new node to the node previous node was pointing to
    newNode->next = prevNode->next;
    //6. Point previous node to the new node
    prevNode->next = newNode;
}

template <typename T>
void sllinsertEnd(T newData, SingleList<T>** head){
    // 1. Allocate a new node
    SingleList<T>* newNode = new SingleList<T>;
    
    // 3. Store data in new node
    newNode->data = newData;
    // 4. Point to null
    newNode->next = nullptr;

    // 2. Dereference the head node
    SingleList<T>* currentNode = *head;
    
    // 5. Traverse the list
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    
    // 6. Point the next of the current node to the new node
    currentNode->next = newNode;
}

template <typename T>
void sllDeleteNode(T findData, SingleList<T>** head){

    // if there is nothing to delete
    if (*head == nullptr) return;

    SingleList<T>* currNode = *head;
    SingleList<T>* prevNode = nullptr;

    // searching the node: 1. the node does not exist + we found data
    while (currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;

    }

    // if data not found currNode == nullPtr in the while loop
    if(currNode == nullptr){
        std::cout << "the data was not found\n" << std::endl;
        return;
    }

    // if data was found
    if(prevNode == nullptr){
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    delete currNode;
}

template <typename T>
void sllDeleteList(SingleList<T>** head){
    SingleList<T>* current = *head;

    while(current != nullptr){

        SingleList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;

}

#endif

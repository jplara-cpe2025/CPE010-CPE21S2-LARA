#ifndef QUEUELL_H
#define QUEUELL_H

// create a class node
template <typename T>
class qNode{
    public:
        T data;
        qNode* next;
};
// new node creator
template <typename T>
qNode<T>* new_node(T newData){
    // allocate a space for the new node
    qNode<T>* newNode = new qNode<T>;
    // store the newData to the newNode
    newNode -> data = newData;
    // point the newNode next to null
    newNode -> next = nullptr;

    return newNode;
}

// enqueue
template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    // create a new node
    qNode<T>* newNode = new_node(newData);
    // check if the queue is empty
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }
    // if not then inser at the back
    (*backPtr)->next = newNode; // LINKS THE CURRENT BACK TO THE NEW NODE
    (*backPtr) = newNode; // ASSIGNS THE BACKPTR TO THE NEW NODE
}
// dequeue
template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    // check if the queue is empty
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        std::cout << "The queue is empty" << std::endl;
        return;
    }
    // create a temporary variable to store the node to be deleted
    qNode<T>* deleteTemp = nullptr;
    // check if the queue has only 1 item
    deleteTemp = (*frontPtr);

    // assign the current front to deleteTemp
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        // return only 1 item is inside the queue
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteTemp;
        return;
    }

    (*frontPtr) = (*frontPtr)->next;
    deleteTemp->next = nullptr;
    
    // dekete the node
    delete deleteTemp;
}

// display all
template <typename T>
void display(qNode<T>** frontPtr, qNode<T>** backPtr) {
    qNode<T>* temp = *frontPtr;

    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout<<"\n";
}

// isEmpty
template <typename T>
bool isEmpty(qNode<T>* frontPtr, qNode<T>* backPtr){
    if(frontPtr == nullptr && backPtr == nullptr){
        std::cout << "The queue is empty" << std::endl;
        return true;
    }
    return false;
}
#endif
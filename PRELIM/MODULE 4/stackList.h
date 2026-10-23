#ifndef STACK_LIST_H
#define STACK_LIST_H

// class node that contains data and the next
template <typename T>
class Node{
    public:
    T data;     // VALUE THAT WE NEED TO STORE
    Node* next; // POINTER TO THE NEXT NODE
};

// global pointer for the top of the stack
template <typename T>
Node<T> *head = nullptr;

// operations for the stack

// push
template <typename T>
void push(T newData){
    // create a new node and assign the newData
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;

    // new node points to the current top, then becomes the new top
    newNode->next = head<T>;
    head<T> = newNode;
}
// pop
template <typename T>
T pop(){
    //check if the stack is empty:
    if(head<T> == nullptr){
        std::cout << "stack underflow. " << std::endl;
        return T();
    }

    // save the current top node
    Node<T>* temp = head<T>;
    // store its data
    T tempVal = temp->data;

    // move the head to the next node
    head<T> = head<T>->next;
    // free the removed node
    delete temp;
    // return the removed value
    return tempVal;
}

// isEmpty
template <typename T>
bool isEmpty(){
    return head <T> == nullptr;
}

// top
template<typename T>
void Top(){
    // error catching
    if(isEmpty<T>()){
        std::cout << "Stack underflow " << std::endl;
        return;
    }
    // display the Top node
    std::cout << "Top of Stack: " << head<T>->data << std::endl;
}

// display All
template<typename T>
void displayALL(){
    if(head<T> == nullptr){
        std::cout << "Stack underflow\n";
        return;
    }
    std::cout << "Displaying the stack: \n";
    Node<T>* temp = head<T>;
    while(temp != nullptr){
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
    std::cout << "\n";
}

// additional function to match symbols
template<typename T>
bool match(T open, T close){

    if(open == '(' && close == ')'){
        return true;
    }
    if(open == '[' && close == ']'){
        return true;
    }
    if(open == '{' && close == '}'){
        return true;
    }
    return false;
}

#endif
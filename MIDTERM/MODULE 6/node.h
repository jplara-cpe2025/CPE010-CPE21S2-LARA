#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
public:
    T data;
    Node *next;
};

template <typename T>
Node<T> *new_node(T newData){
    Node<T> *newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}


#endif

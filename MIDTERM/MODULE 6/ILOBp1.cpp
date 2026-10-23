#include <iostream>
#include "searchingAlgo.h"
#include "node.h"

int main() {
    // ARRAY
    int newArr[10] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    std::cout << "ARRAY\n";
    linearSearchAR(10, 18, newArr);

    // LINKED LIST
    Node<int> *int1 = new_node(15);
    Node<int> *int2 = new_node(18);
    Node<int> *int3 = new_node(2);
    Node<int> *int4 = new_node(19);
    Node<int> *int5 = new_node(18);
    Node<int> *int6 = new_node(0);
    Node<int> *int7 = new_node(8);
    Node<int> *int8 = new_node(14);
    Node<int> *int9 = new_node(19);
    Node<int> *int10 = new_node(14);

    // CONNECT THE NODES
    int1->next = int2;
    int2->next = int3;
    int3->next = int4;
    int4->next = int5;
    int5->next = int6;
    int6->next = int7;
    int7->next = int8;
    int8->next = int9;
    int9->next = int10;

    std::cout << "\nLINKED LIST\n";
    linearSearchLL(int1, 18);

    return 0;
}
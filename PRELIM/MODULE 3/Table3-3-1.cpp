#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"

int main(){

    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');
    DoubleList<char>* fourth = CreateNewNode('1');
    DoubleList<char>* fifth = CreateNewNode('0');
    DoubleList<char>* sixth = CreateNewNode('1');

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    fifth->next = sixth;
    sixth->prev = fifth;

    std::cout << "Original List: ";
    dllTraverse(head);

    std::cout << "\nInsert G in the head:\n";
    dllInsertHead('G', &head);
    dllTraverse(head);

    std::cout << "\nInsert E after P:\n";
    dllGenInsert('E', second);
    dllTraverse(head);

    std::cout << "\nDelete C:\n";
    dllDeleteNode(head->next, &head);
    dllTraverse(head);

    std::cout << "\nDelete P:\n";
    dllDeleteNode(second, &head);
    dllTraverse(head);

    std::cout << "\nNew List: ";
    dllTraverse(head);

    return 0;
}
#include <iostream>
#include "queuell.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue('J', &front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;

    enqueue('I', &front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;

    enqueue('M', &front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;

    std::cout << "All elements in the queue: \n";
    display(&front, &back);

    std::cout << "Testing the dequeue operator: \n";
    dequeue(&front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;
    dequeue(&front, &back);
    std::cout << "Front: " << front->data << " " << "Back: " << back->data << std::endl;
    dequeue(&front, &back);

    std::cout << "All elements in the queue: \n";
    display(&front, &back);

    std::cout << "Test if the Queue is Empty \n";
    isEmpty(front, back);

    return 0;
}
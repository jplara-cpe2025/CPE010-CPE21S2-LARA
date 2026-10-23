#include <iostream>
#include "queueArr.h"

int main(){

    // creating an object
    queueArr<int> q(5);
    
    // enqueue 10, 20, 30, 40, 50
    q.Enqueue(1);

    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;

    q.Enqueue(2);
    
    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;

    q.Enqueue(3);
    q.Enqueue(4);

    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;

    q.Enqueue(5);
    std::cout << "Front: " << q.Front() << std::endl;
    std::cout << "Back: " << q.Back() << std::endl;
    std::cout << "Size: " << q.Size() << std::endl;
    q.Enqueue(6);

    std::cout << "\nRemoved: " << q.Dequeue() << std::endl;
    std::cout << "Removed: " << q.Dequeue() << std::endl;

    q.Clear();
    std::cout << "Is the queue empty? " << (q.Empty() ? "yes" : "no") << std::endl;
    return 0;
}
#include <iostream>
#include <queue>

void display(std::queue<char> copyQ);

int main(){

    // create an object
    std::queue<char> myQ;
    
    // use the enqueue operation
    myQ.push('J');
    myQ.push('P');
    myQ.push('L');
    std::cout << "current front is: " << myQ.front() << std::endl;
    std::cout << "current back is: " << myQ.back() << std::endl;
    display(myQ);

    // use the dequeue operation
    myQ.pop();
    display(myQ);
    myQ.pop();
    display(myQ);
    myQ.pop();

    // check the queue if it is empty
    std::cout << "Is the queue empty? " << myQ.empty() << std::endl;
    return 0;
}

// note only use the member functions of the queue STL
void display(std::queue<char> copyQ){
    // create a copy of the queue
    std::queue<char> temp = copyQ;

    // loop until empty
    while(!temp.empty()){
        // display the front
        std::cout << temp.front();
        // dequeue the front
        temp.pop();
    }
    // add a new line
    std::cout << std::endl; 
}

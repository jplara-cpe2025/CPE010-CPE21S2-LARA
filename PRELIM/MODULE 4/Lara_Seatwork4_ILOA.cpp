#include <iostream>
#include <stack>

int main(){

    std::stack<int> stack1;
    std::stack<int> stack2;

    std::cout << "Testing the stack STL" << std::endl;

    // isEmpty
    std::cout << "Is the stack empty? " << stack1.empty() << std::endl;

    // push
    stack1.push(10);
    std::cout << "The top of the stack is " << stack1.top() << std::endl;
    stack1.push(9);
    std::cout << "The top of the stack is " << stack1.top() << std::endl;
    stack1.push(8);
    std::cout << "The top of the stack is " << stack1.top() << std::endl;
    stack1.push(7);
    std::cout << "The top of the stack is " << stack1.top() << std::endl;

    // pop
    stack1.pop();
    std::cout << "The top of the stack is " << stack1.top() << std::endl;
    std::cout << "Is the stack empty? " << stack1.empty() << std::endl;
    std::cout << "THe size of the stack is " << stack1.size() << std::endl;    

    // emplace
    stack1.emplace(11);
    std::cout << "The top of the stack is " << stack1.top() << std::endl;
    std::cout << "THe size of the stack is " << stack1.size() << std::endl;    

    // swap
    stack2.push(12);
    stack1.swap(stack2);
    std::cout << "The top of the stack1 is " << stack1.top() << std::endl;
    std::cout << "The top of the stack2 is " << stack2.top() << std::endl;

    return 0;
}
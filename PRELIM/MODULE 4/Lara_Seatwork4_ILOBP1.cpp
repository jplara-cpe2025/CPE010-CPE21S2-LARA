#include <iostream>

// global declaration
#define maxCap 100
int stackArr[maxCap];
int top = -1, newData;

// prototype function
void push();
void pop();
void Top();
bool isEmpty();
bool isFull();


int main(){
    // main driver code
    int choice;

    while (true){
        std::cout << "===============================================" << std::endl;
        std::cout << "Stack Operations\n";
        std::cout << "1. PUSH 2. POP 3. TOP 4. isEmpty 5. isFull" << std::endl;
        std::cout << "===============================================" << std::endl;
        std::cin >> choice;

        switch(choice){
            case 1: push(); 
            break;
            case 2: pop(); 
            break;
            case 3: Top(); 
            break;
            case 4: std::cout << "Is the stack empty? " << isEmpty() << std::endl;
            break;
            case 5: std::cout << "Is the stack full? " << isFull() << std::endl;
            break;
            default: std::cout << "Invalid choice" << std::endl;
            break;
        }
    }

}

// function definition
bool isEmpty(){
    // check the top if it is -1
    if(top == -1) return true;
    return false;
}

bool isFull(){
    // how do we verify if the stack is full
    if(top == maxCap - 1) return true;
    return false;
}

void push(){
    // error checking
    if(isFull()){
        std::cout << "Stack Overflow" << std::endl;
        return;
    }

    // pushing to the stack
    std::cout << "Enter a new value" << std::endl;
    std::cin >> newData;

    // how do we insert the data into the stack?
    stackArr[++top] = newData;
}

void pop(){
    // errpr checking
    if(isEmpty()){
        std::cout << "Stack Underflow" << std::endl;
        return;
    }

    // DIsplay the value that we are going to pop
    std::cout << "Popping: " << stackArr[top] << std::endl;

    // decrement the value from the stack
    top--;

}

void Top(){
    // error catching
    if(isEmpty()){
        std::cout << "The stack is empty" << std::endl;
        return;
    }

    // check the top element
    std::cout << "Top Element: " << stackArr[top] << std::endl;

}

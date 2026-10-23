#include <iostream>
#include <thread>

// a global variable of type integer
int global_var = 0;

// add function to add an int value to the global variable
void add(int value) {
    global_var += value;
}

int main() {
    // create 3 threads to pass the add function to the threads
    std::thread t1(add, 10);
    std::thread t2(add, 20);
    std::thread t3(add, 30);

    // display global var
    std::cout << "Initial Display (Before t1.join): global_var = " << global_var << std::endl;

    // combinations of join() and display
    t1.join();
    std::cout << "Display after t1.join(): global_var = " << global_var << std::endl;
    t2.join();
    std::cout << "Display after t2.join(): global_var = " << global_var << std::endl;
    t3.join();
    std::cout << "Final Display after t3.join(): global_var = " << global_var << std::endl;

    return 0;
}

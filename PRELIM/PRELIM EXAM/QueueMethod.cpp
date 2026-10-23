#include <iostream>
#include <string>
#include "queuell.h"

// Queue Method

bool symmetricTest(std::string expression){
    head<std::string> = nullptr;

    for(int i = 0; i < expression.length(); i++){
        char ch = expression[i];
        
        if(ch == '1'){
            enqueue(ch);
        }
        else if(ch == '5'){
            if(isEmpty<char>()){
                return false;
            }
            char popChar = pop<char>();

            if(!matchEnd(popChar, ch)){
                return true;
            }
        }
    }

    return isEmpty<char>();
}

// main

int main(){
    std::string test[] = {"12321", "12345", "1221", "7", "123321", "1234325"};

    for(int i = 0; i < 6; i++){
        std::cout << test[i] << std::endl;

        if(!symmetricTest(test[i])){
            std::cout << "(Stack LL) SYMMETRIC?: Y\n";
        } else {
            std::cout << "(Stack LL) SYMMETRIC?: N\n";
        }

    }

    return 0;
}
#include <iostream>
#include <string>
#include "stackList.h"

// function to balance sign
bool balanceSign(std::string expression){
    head<char> = nullptr;

    for(int i = 0; i < expression.length(); i++){
        char ch = expression[i];

        if(ch == '(' || ch == '[' || ch == '{'){
            push(ch);
        }
        else if(ch == ')' || ch == ']' || ch == '}'){
            if(isEmpty<char>()){
                return false;
            }
            char popChar = pop<char>();

            if(!match(popChar, ch)){
                return false;
            }
        }
    }

    return isEmpty<char>();
}

// main
int main(){
    std::string test[] = {"(A+B)+(C-D)", "((A+B)+(C-D)", "((A+B)+[C-D])", "((A+B]+[C-D]}"};

    for(int i = 0; i < 4; i++){
        std::cout << test[i] << std::endl;

        if(balanceSign(test[i])){
            std::cout << "Valid: Y\n";
        } else {
            std::cout << "Valid: N\n";
        }
    }

    return 0;
}
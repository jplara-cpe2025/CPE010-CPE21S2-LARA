#include <iostream>
#include <string>

// global declaration
#define maxCap 100
char stackArr[maxCap];
int top = -1;

// prototype function
bool isEmpty();
bool isFull();
void push();
char pop();
bool match();
bool balanceSign(std::string);

// main driver function
int main(){
    std::string test[] = {"(A+B)+(C-D)", "((A+B)+(C-D)", "((A+B)+[C-D])", "((A+B]+[C-D]}"};
    
    for(int i = 0; i < 4; i++){
        top = -1;

        std::cout << "Expression: " << test[i] << std::endl;

        if(balanceSign(test[i])){
            std::cout << "Valid: Y";
        } else {
            std::cout << "Valid: N";
        }
        std::cout << std::endl;
    }

    return 0;
}

// FUNCTION DEFINITION
bool isEmpty(){
    if(top == -1) return true;
    return false;
}

bool isFull(){
    if(top == maxCap - 1) return true;
    return false;
}

void push(char value){
    if(isFull()){
        std::cout << "Stack Overflow\n";
        return;
    }

    stackArr[++top] = value;
}

char pop(){
    if(isEmpty()){
        return ' ';
    }

    return stackArr[top--];
}

bool match(char open, char close){
    if(open == '(' && close == ')'){
        return true;
    }
    if(open == '[' && close == ']'){
        return true;
    }
    if(open == '{' && close == '}'){
        return true;
    }
    return false;
}

bool balanceSign(std::string expression){
    for(int i = 0; i < expression.length(); i++){
        char ch = expression[i];

        if(ch == '(' || ch == '[' || ch == '{'){
            push(ch);
        }
        else if(ch == ')' || ch == ']' || ch == '}'){
            if(isEmpty()){
                return false;
            }
            char popChar = pop();

            if(!match(popChar, ch)){
                return false;
            }
        }
    }

    if(isEmpty()){
        return true;
    }
    return false;
}
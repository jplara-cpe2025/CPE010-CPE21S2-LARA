#include <iostream>
#include <stack>
#include <string>

// function prototype
bool match();
bool balanceSign(std::string);

// main function
int main(){
    std::string test[] = {"(A+B)+(C-D)", "((A+B)+(C-D)", "((A+B)+[C-D])", "((A+B]+[C-D]}"};

    for(int i = 0; i < 4; i++){
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

// function to match symbols
bool match(char open, char close){
    if(open == '(' && close == ')')
        return true;
    if(open == '[' && close == ']')
        return true;
    if(open == '{' && close == '}')
        return true;

    return false;
}

// function to see whether expression is balanced
bool balanceSign(std::string expression){
    std::stack<char> sign;

    for(int i = 0; i < expression.length(); i++){
        char ch = expression[i];

        if(ch == '(' || ch == '[' || ch == '{'){
            sign.push(ch);
        }
        else if(ch == ')' || ch == ']' || ch == '}'){
            if(sign.empty())
                return false;

            char popChar = sign.top();
            sign.pop();

            if(!match(popChar, ch))
                return false;
        }
    }

    if(sign.empty())
        return true;

    return false;
}
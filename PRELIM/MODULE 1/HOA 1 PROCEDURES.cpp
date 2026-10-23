#include <iostream>
// FUNCTION DECLARATION
// ILO A
int sumOfTwoNum(int num1, int num2);
bool isGreaterThan(int a, int b); 
bool logicalOperation(bool x, bool y);

// ILO B
class Triangle {
    private:
        double totalAngle, angleA, angleB, angleC;
    public:
        Triangle(double A, double B, double C);
        void setAngles(double A, double B, double C);
        const bool validateTriangle();
};

// MAIN 
int main(){
    // ILO A #1
    std::cout << "The SUM of all numbers is: " << sumOfTwoNum(10, 22) << std::endl;
    // ILO A #2
    int x = 333;
    int y = 255;

   if (isGreaterThan(x, y)) {
        std::cout << "x is GREATER than y" << std::endl;
    } else {
        std::cout << "x is NOT GREATER than y" << std::endl;
    }

    // ILO A #3
    bool success = logicalOperation(true, false);
    std::cout << "Function status: " << std::boolalpha << success << std::endl;
    // ILO B 
    Triangle set1(40,30,110);
    if(set1.validateTriangle()){
        std::cout << "The shape is a VALID Triangle \n.";
    } else {
        std::cout << "The shape is NOT A VALID Triangle \n.";
    }

    return 0;
}

// FUNCTION DEFINITION
// ILO A #1
int sumOfTwoNum(int num1, int num2){
    int sum = num1 + num2;
    return sum;
}
 // ILO A #2
bool isGreaterThan(int a, int b){
    return a > b;
}

// ILO A #3
bool logicalOperation(bool x, bool y) {
    // CHANGES 1 OR 0 TO TRUE OR FALSE
    std::cout << std::boolalpha;
    std::cout << "Logical Operation " << std::endl;
    std::cout << "Values: X = " << x << ", Y = " << y << std::endl;
    // 1. NOT 
    std::cout << "NOT X: " << (!x) << std::endl;
    std::cout << "NOT Y: " << (!y) << std::endl;
    // 2. AND
    std::cout << "X AND Y: " << (x && y) << std::endl;
    // 3. OR
    std::cout << "X OR Y: " << (x || y) << std::endl;
    // 4. XOR 
    std::cout << "X XOR Y: " << (x ^ y) << std::endl;
    
    return true;
}

// ILO B
Triangle::Triangle(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

const bool Triangle::validateTriangle(){
    return (totalAngle <= 180);
}

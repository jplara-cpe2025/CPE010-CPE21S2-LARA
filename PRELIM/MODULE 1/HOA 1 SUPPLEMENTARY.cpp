#include <iostream>
#include <cmath> // FOR USE IN POW
// FUNCTION DECLARATION
// ILO C #1
void swapTwoNum(int &a, int &b);
// ILO C #2
double kelvinToFahrenheit(double kelvin);
// ILO C #3
double calculateDist(double x1, double y1, double x2, double y2);
// ILO C #4
class Triangle{
    private:
        double sideA, sideB, sideC, angleA, angleB, angleC, totalAngle;

    public:
        Triangle(double sA, double sB, double sC, double A, double B, double C);
        void setValues(double sA, double sB, double sC, double A, double B, double C);

        const bool validateTriangle();
        double getArea();
        double getPerimeter();
        void triangleType();
};

// MAIN
int main(){
    // ILO C #1
    int num1 = 15;
    int num2 = 30;

    std::cout << "Before Swap\n";
    std::cout << "num1 = " << num1 << std::endl;
    std::cout << "num2 = " << num2 << std::endl;
    swapTwoNum(num1, num2);
    std::cout << "\nAfter Swap\n";
    std::cout << "num1 = " << num1 << std::endl;
    std::cout << "num2 = " << num2 << std::endl;

    // ILO C #2
    double kelvin = 451;
    std::cout << "\nK Temperature in Fahrenheit: " << kelvinToFahrenheit(kelvin);
    // ILO C #3
    std::cout << "\nDistance Between Two Points: " << calculateDist(1, 3, 5, 9);
    // ILO C #4
    Triangle set1(10, 10, 10, 60, 60, 60);

    if(set1.validateTriangle()){
        std::cout << "\nThe shape is a valid Triangle." << std::endl;
        std::cout << "Area: " << set1.getArea() << std::endl;
        std::cout << "Perimeter: " << set1.getPerimeter() << std::endl;
        set1.triangleType();
    } else {
        std::cout << "\nThe shape is NOT a valid Triangle.\n";
    }

    return 0;
}

// FUNCTION DEFINITION
// ILO C #1
void swapTwoNum(int &a, int &b){
    int swap = a;
    a = b;
    b = swap;
}

// ILO C #2
double kelvinToFahrenheit(double kelvin){
    return ((kelvin - 273.15) * 9/5) + 32;
}

// ILO C #3
double calculateDist(double x1, double y1, double x2, double y2){
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

// ILO C #4
Triangle::Triangle(double sA, double sB, double sC, double A, double B, double C){
    sideA = sA;
    sideB = sB;
    sideC = sC;
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setValues(double sA, double sB, double sC, double A, double B, double C){
    sideA = sA;
    sideB = sB;
    sideC = sC;
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

const bool Triangle::validateTriangle(){
    return (totalAngle == 180);
}

double Triangle::getPerimeter(){
    return sideA + sideB + sideC;
}

double Triangle::getArea(){
    double s = getPerimeter() / 2;
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

void Triangle::triangleType(){
    if(angleA < 90 && angleB < 90 && angleC < 90){
        std::cout << "Triangle is ACUTE" << std::endl;
    } else if(angleA > 90 || angleB > 90 || angleC > 90){
        std::cout << "Triangle is OBTUSE" << std::endl;
    } else {
        std::cout << "Triangle is OTHER" << std::endl;
    }
}
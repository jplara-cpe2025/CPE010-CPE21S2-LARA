#include <iostream>
#include <string.h>

class Student{
    private:
        std::string studentName;
        int studentAge;
    public:
        // Constructor
        Student(std::string newName = "John Doe", int newAge = 18){
            studentName = std::move(newName);
            studentAge = newAge;
            std::cout << "Constructor Called." << std::endl;
        }
        // Deconstructor
        ~Student(){
            std::cout << "Destructor Called." << std::endl;
        }
        // Copy constructor
        Student(const Student &copyStudent){
            std::cout << "Copy Constructor Called" << std::endl;
            studentName = copyStudent.studentName;
            studentAge = copyStudent.studentAge;
        }
        // Display Attributes
        void printDetails(){
            std::cout << this->studentName << " " << this->studentAge << std::endl;
        }
};

int main(){
    std::cout << "TABLE 2.2\n";
    const size_t j = 5;
    Student studentList[j] = {};
    std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15, 16, 18, 19, 16};

    std::cout << "TABLE 2.3-2.4 - Loop A\n";
    for (int i = 0; i < j; i++){ // Loop A
        Student *ptr = new Student(namesList[i], ageList[i]);
        studentList[i] = *ptr;
    }

    std::cout << "TABLE 2.3-2.4 - Loop B\n";
    for (int i = 0; i < j; i++){ // Loop B
        studentList[i].printDetails();    
    }

    return 0;
}

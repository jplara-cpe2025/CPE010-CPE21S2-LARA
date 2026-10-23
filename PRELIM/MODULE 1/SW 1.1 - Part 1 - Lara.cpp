#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout << "Seatwork 1.1 - Part 1\nComputing the Total & Average of 3 Quizzes\n";
    
    // Declare variables
    double quizScores[3], quizItems[3], quizTotal;
    float quizAvg;
    string name;
    char yesNo; 

    do {
        // reset values
        quizTotal = 0; quizAvg = 0.0;
        
        // Prompt to input the student's name
        cout << "\nEnter the student's name: ";
        cin >> name;

        // Prompt to input the scores of 3 quizzes
        for (int i = 0; i < 3; i++){

            cout << "Enter the # of items of Quiz #" << (i + 1) << ": ";
            cin >> quizItems[i];
            cout << "Enter your score of Quiz #" << (i + 1) << ": ";
            cin >> quizScores[i];

            quizTotal += quizScores[i]; // Add scores to total
            quizAvg = quizTotal / (i + 1.0); // Compute average
        }

        // Display the results
        cout << "\nThe Results:\nStudent Name: " << name << "\nQuiz scores:";

        // Display and process quiz grades
        for (int j = 0; j < 3; j++){
            cout << "\nQuiz #" << (j + 1) << ": " << quizScores[j] << "/" << quizItems[j];
            
            float quizGrade = (quizScores[j] / quizItems[j]) * 50 + 50;
            // if the score meets passing grade
            if (quizGrade >= 75.0) {
                cout << " PASSED (" << fixed << setprecision(2) << quizGrade << "%)";
            } else {
                cout << " FAILED (" << fixed << setprecision(2) << quizGrade << "%)";
            }
        }

        cout << "\nThe total score of the 3 quizzes is: " << quizTotal;
        cout << "\nThe average score of the 3 quizzes is: " << fixed << setprecision(2) << quizAvg;

        // Prompt user to repeat
        cout << "\n\nDo you want to repeat the program? (y/n): ";
        cin >> yesNo;

    } while (yesNo != 'n');

    // when the user chooses not to repeat
    cout << "\nGoodbye!\n";
    return 0;   
}
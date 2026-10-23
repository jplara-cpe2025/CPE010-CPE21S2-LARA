#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    cout << "Seatwork 1.1 - Part 2\nCashiering System\n\n";
    
    // Declare variables
    float itemPrices[3], totalPrice, payment, change;
    char yesNo; 

    do {
        // reset values
        totalPrice = 0.0;

        // Prompt to input the prices of 3 items
        for (int i = 0; i < 3; i++){
        cout << "Enter the price of Item #" << (i + 1) << ": ";
        cin >> itemPrices[i];
        totalPrice += itemPrices[i]; // Add prices to total
        }

        // Compute the total price
        cout << "\nThe total price of the 3 items is: " << fixed << setprecision(2) << totalPrice;

        // Prompt to input the payment
        cout << "\nEnter the payment amount: ";
        cin >> payment;
        cout << "You entered: " << fixed << setprecision(2) << payment << endl;

        // Check if payment is sufficient, repeats if less than total price
        while (payment < totalPrice) {
            cout << "\nInsufficient payment amount. Please enter a valid payment amount: ";
            cin >> payment;
        }
        // Compute change
        change = payment - totalPrice;
        cout << "Your change is: " << fixed << setprecision(2) << change;
        
        cout << "\n\nTRANSACTIONS SUMMARY\nTotal Price: " << totalPrice << "\nAmount Paid: " 
            << payment << "\nChange: " << change;

        // Prompt user to repeat
        cout << "\n\nDo you want to repeat the program? (y/n): ";
        cin >> yesNo;

    } while (yesNo != 'n');

    // when the user chooses not to repeat
    cout << "\nGoodbye!\n";
    return 0;    
}
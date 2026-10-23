#include <iostream>
#include "printerArr.h"

int main(){
    Printer printer(10);
    int choice;
    // program loop
    do{
        std::cout << "\n===== PRINTERS =====\n";
        std::cout << "1. Add Print Job\n";
        std::cout << "2. Process All\n";
        std::cout << "3. Remove Print Job\n";
        std::cout << "4. Show Print Jobs\n";
        std::cout << "5. Clear All\n";
        std::cout << "6. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        // if else if...
        if(choice == 1){
            Job temp;

            std::cout << "Job ID: ";
            std::cin >> temp.id;
            std::cout << "User Name: ";
            std::cin >> temp.user;
            std::cout << "Pages: ";
            std::cin >> temp.pages;

            printer.AddJob(temp);
        }
        
        else if(choice == 2){
            printer.ProcessJobs();
        }

        else if(choice == 3){
            Job temp = printer.RemoveJob();

            if(temp.id != 0){
                std::cout << "Removed Job\n";
                std::cout << "Job ID: " << temp.id << std::endl;
                std::cout << "User: " << temp.user << std::endl;
                std::cout << "Pages: " << temp.pages << std::endl;
            }
        }

        else if(choice == 4){
            printer.ShowJobs();
        }
        
        else if(choice == 5){
            printer.Clear();
            std::cout << "All print jobs cleared.\n";
        }

    } while(choice != 6);

    return 0;
}
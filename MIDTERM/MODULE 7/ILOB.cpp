#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "sortingAlgo.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main(){

    int unsortedArr[maxSize] = {};

    std::string candidates[5] = {
        "Candidate 1",
        "Candidate 2",
        "Candidate 3",
        "Candidate 4",
        "Candidate 5"
    };

    // predetermined seed
    srand(1024);

    // generate random votes with range 1-5
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand()%5 + 1;
    }

    // print generated unsorted
    std::cout<<"unsortedArr: \n";
    displayArr(unsortedArr);

    // sort using selection sort
    std::cout<<"\nSelection sort: \n";
    selectionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    // count votes for each candidate
    int votes[5] = {};
    countVotes(unsortedArr, maxSize, votes);

    //display vote counts
    std::cout<< "\nVote Results: \n";

    for(int i = 0; i < 5; i++){
        std::cout<< candidates[i] << ": " << votes[i] << " votes\n";
    }

    //find the winning candidate
    int winner = 0;

    for(int i = 1; i < 5; i++){
        if(votes[i] > votes[winner]){
            winner = i;
        }
    }

    std::cout << "\nWinner: " << candidates[winner] << ". " << votes[winner] <<" votes\n";

    return 0;
}

void displayArr(int arr[]){
    for(int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
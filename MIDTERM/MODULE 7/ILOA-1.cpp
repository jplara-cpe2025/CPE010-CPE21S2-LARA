#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

// const int maxSize = 100000;
const int maxSize = 100;

void displayArr(int arr[]);

int main(){

    // create an array with unsorted list with 100 max size
    int unsortedArr[maxSize] = {};
    // use time(0) as seed for random value
    // srand(time(0));
    // for procedure analysis, we'll use a predetermined seed
    srand(435);
    //populate the array with random values
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand()%100;
    }
    //display the randomly generated array
    std::cout<<"unsortedArr: \n";
    displayArr(unsortedArr);

    //std::cout<<"\nBubble sort: \n";
    //bubbleSort(unsortedArr, maxSize);
    //displayArr(unsortedArr);

    //std::cout<<"\nSelection sort: \n";
    //selectionSort(unsortedArr, maxSize);
    //displayArr(unsortedArr);

    std::cout<<"\nInsertion sort: \n";
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

}

void displayArr(int arr[]){
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
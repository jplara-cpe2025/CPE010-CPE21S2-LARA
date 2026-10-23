#include <iostream>
#include <ctime>
#include "sortingAlgo2.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main(){

    // unsorted array
    int unsortedArr[maxSize] = {};

    // stores sorted array 
    int shellArr[maxSize] = {};
    int mergeArr[maxSize] = {};
    int quickArr[maxSize] = {};

    // RNG seed
    srand(435);

    // populate unsorted arr
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand()%100;
    }

    std::cout << "Unsorted Array:\n";
    displayArr(unsortedArr);

    // fill unsorted data
    for(int i = 0; i < maxSize; i++){
        shellArr[i] = unsortedArr[i];
        mergeArr[i] = unsortedArr[i];
        quickArr[i] = unsortedArr[i];
    }

    // sorting algorithms
    std::cout << "\nShell Sort:\n";
    shellSort(shellArr, maxSize);
    displayArr(shellArr);

    std::cout << "\nMerge Sort:\n";
    mergeSort(mergeArr, 0, maxSize - 1);
    displayArr(mergeArr);

    std::cout << "\nQuick Sort:\n";
    quickSort(quickArr, 0, maxSize - 1);
    displayArr(quickArr);

    return 0;
}

void displayArr(int arr[]){
    for(int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
        if ((i%20) == 19){
            std::cout << '\n';
        }
    }
}
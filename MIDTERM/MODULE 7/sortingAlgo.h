#include <cstddef>
#include <iostream>
#ifndef SORTINGALGO_H
#define SORTINGALGO_H

template<typename T>
void bubbleSort(T arr[], size_t arrSize){
    //step1: for i =0 to N-1 repeat inner loop
    for(int i =0; i < arrSize; i++){
        //step 2 inner loop that for K = i+1 to N-I repaeat
        for(int j = i+1; j < arrSize; j++){
            //step 3: swap if the arr[j] > arr[i]
            if(arr[i] > arr[j]){
                std::swap(arr[i],arr[j]);
            }
        }
    }
}

template<typename T>
//array, current position, size of array
int routineSmallest(T arr[], int K, const int arrSize){
    int position = K;
    T smallestElem = arr[K];

    for(int j = K+1; j<arrSize; j++){
        if(arr[j] < smallestElem){
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}


template<typename T>
void selectionSort(T arr[], size_t arrSize){
    int POS, temp, pass;
    for(int i=0; i < arrSize; i++){
        POS = routineSmallest(arr, i, arrSize);
        //swapping:
        temp = arr[i];
        arr[i] = arr[POS];
        arr[POS] = temp;

        //for verification and counting of number of passes that was done
        pass++;
    }
}

template<typename T>
void insertionSort(T arr[], size_t arrSize){
    int K = 0, J, temp;

    while(K < arrSize){
        temp = arr[K];
        J=K-1;

        while(J >= 0 && temp <= arr[J]){
            arr[J+1]= arr[J];
            J--;
        }

        arr[J+1] = temp;
        K++;
    }
}

// additonal functions
template<typename T>
void countVotes(T arr[], size_t arrSize, int votes[]){
    //count the occurrences of each candidate vote
    for(int i = 0; i < 5; i++){
        votes[i] = 0;
    }

    for(int i = 0; i < arrSize; i++){
        votes[arr[i] - 1]++;
    }
}

#endif

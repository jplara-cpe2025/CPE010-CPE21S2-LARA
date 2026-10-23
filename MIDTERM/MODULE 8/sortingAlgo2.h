#include <iostream>

#ifndef SORTINGALGO2_H
#define SORTINGALGO2_H

template<typename T>
void shellSort(T arr[], size_t arrSize){
    // divide into a large gap, then divide to reduce it
    for(int gap = arrSize / 2; gap > 0; gap /= 2){
        // insert for the gap size
        for(int i = gap; i < arrSize; i++){
            // place the correct element 
            T temp = arr[i];
            int j = i;
            // move elements greater than temp for space
            while(j >= gap && arr[j - gap] > temp){
                arr[j] = arr[j - gap];
                j -= gap;
            }
 
            arr[j] = temp;
        }
    }
}

template<typename T>
void merge(T arr[], int left, int middle, int right){
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // temp arrays
    T L[n1];
    T R[n2];

    // copy array data to temp arrays
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++){
        R[j] = arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    // merge temp arrays into [left...right]
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy L[] and R[] remaining elements if any remain
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

template<typename T>
void mergeSort(T arr[], int left, int right){
    if(left < right){
        int middle = (left + right) / 2;
        // sort first half recursively
        mergeSort(arr, left, middle);
        // 2nd half
        mergeSort(arr, middle + 1, right);
        // merge
        merge(arr, left, middle, right);
    }
}

template<typename T>
int partition(T arr[], int low, int high){
    // choose pivot
    T pivot = arr[high];
    // right index position of pivot 
    int i = low - 1;
    // traverse low to high, move smaller elements to left
    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    // move pivot after smaller elements
    std::swap(arr[i + 1], arr[high]);
    // return position
    return i + 1;
}

template<typename T>
void quickSort(T arr[], int low, int high){
    if(low < high){
        // partition return index
        int pivot = partition(arr, low, high);
        // recursively call for small
        quickSort(arr, low, pivot - 1);
        // for greater or equal
        quickSort(arr, pivot + 1, high);
    }
}

#endif
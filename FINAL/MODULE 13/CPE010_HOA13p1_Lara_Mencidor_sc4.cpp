#include <iostream>
#include <thread>
#include <chrono>

const int SIZE = 500000;

// merge two sorted sub-arrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // sub-arrays
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1){
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Single-threaded Merge Sort
void mergeSortSequential(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortSequential(arr, left, mid);
        mergeSortSequential(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Multi-threaded Merge Sort
void mergeSortParallel(int arr[], int left, int right, int depth = 0) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        // Limit recursive thread depth
        if (depth < 2) {
            std::thread t1(mergeSortParallel, arr, left, mid, depth + 1);
            std::thread t2(mergeSortParallel, arr, mid + 1, right, depth + 1);
            t1.join();
            t2.join();
        } else {
            mergeSortSequential(arr, left, mid);
            mergeSortSequential(arr, mid + 1, right);
        }
        merge(arr, left, mid, right);
    }
}

int main() {
    int* arr1 = new int[SIZE];
    int* arr2 = new int[SIZE];

    // Populate arr1 and duplicate to arr2
    for (int i = 0; i < SIZE; i++) {
        arr1[i] = SIZE - i;
        arr2[i] = arr1[i];
    }
    // EXECUTION TIME using chrono clock
    // Single-threaded
    auto startSeq = std::chrono::high_resolution_clock::now();
    mergeSortSequential(arr1, 0, SIZE - 1);
    auto endSeq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> seqTime = endSeq - startSeq;
    // Multi-threaded 
    auto startPar = std::chrono::high_resolution_clock::now();
    mergeSortParallel(arr2, 0, SIZE - 1);
    auto endPar = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> parTime = endPar - startPar;

    std::cout << "Data Size:    " << SIZE << " elements\n";
    std::cout << "Single Threaded Merge Sort Time:   " << seqTime.count() << " ms\n";
    std::cout << "Multi Threaded Merge Sort Time:     " << parTime.count() << " ms\n";

    return 0;
}
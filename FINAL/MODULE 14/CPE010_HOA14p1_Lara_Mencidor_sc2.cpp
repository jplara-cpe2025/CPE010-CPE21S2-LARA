#include <iostream>
#include <vector>
#include <chrono>

void merge(int arr[], int left, int middle, int right){
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[middle + 1 + j];
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
    while (j < n2){
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int left, int right){
    if (left < right){
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void testMergeSort(int n){
    // Already sorted array
    std::vector<int> bestArr(n);
    for (int i = 0; i < n; i++){
        bestArr[i] = i;
    }
    // Reverse sorted array
    std::vector<int> worstArr(n);
    for (int i = 0; i < n; i++){
        worstArr[i] = n - i;
    }
    // Best Case
    auto startBest = std::chrono::high_resolution_clock::now();
    mergeSort(bestArr.data(), 0, n - 1);
    auto endBest = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> bestTime = endBest - startBest;

    // Worst Case
    auto startWorst = std::chrono::high_resolution_clock::now();
    mergeSort(worstArr.data(), 0, n - 1);
    auto endWorst = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> worstTime = endWorst - startWorst;

    std::cout << "N = " << n << "\n";
    std::cout << "Best Case: " << bestTime.count() << " ms\n";
    std::cout << "Worst Case: " << worstTime.count() << " ms\n";
}

int main(){
    std::cout << "Merge Sort\n";
    testMergeSort(100);
    testMergeSort(1000);
    testMergeSort(10000);
    return 0;
}
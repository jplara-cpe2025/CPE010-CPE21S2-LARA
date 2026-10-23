#include <iostream>
#include <vector>
#include <chrono>

// Optimized Bubble Sort with early break
void bubbleSort(int arr[], size_t arrSize){
    for (size_t i = 0; i < arrSize - 1; i++){
        bool swapped = false;
        for (size_t j = 0; j < arrSize - i - 1; j++){
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

void testBubbleSort(int n){
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
    bubbleSort(bestArr.data(), n);
    auto endBest = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> bestTime = endBest - startBest;

    // Worst Case
    auto startWorst = std::chrono::high_resolution_clock::now();
    bubbleSort(worstArr.data(), n);
    auto endWorst = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> worstTime = endWorst - startWorst;

    std::cout << "N = " << n << "\n";
    std::cout << "Best Case: " << bestTime.count() << " ms\n";
    std::cout << "Worst Case: " << worstTime.count() << " ms\n";
}

int main(){
    std::cout << "Bubble Sort\n";
    testBubbleSort(100);
    testBubbleSort(1000);
    testBubbleSort(10000);
    return 0;
}
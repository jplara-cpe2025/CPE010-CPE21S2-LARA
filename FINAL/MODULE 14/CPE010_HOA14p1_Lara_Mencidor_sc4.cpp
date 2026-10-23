#include <iostream>
#include <vector>
#include <chrono>

void binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return;
        } else if (target < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
}

void testBinarySearch(int n) {
    std::vector<int> worstArr(n);
    for (int i = 0; i < n; i++) {
        worstArr[i] = i;
    }
    // trigger worst-case traversal (log2(N) + 1)
    int target = -1;

    auto startWorst = std::chrono::high_resolution_clock::now();
    binarySearch(worstArr, target);
    auto endWorst = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> worstTime = endWorst - startWorst;

    std::cout << "N = " << n << "\n";
    std::cout << "Worst Case: " << worstTime.count() << " ms\n";
}

int main() {
    std::cout << "Binary Search\n";
    testBinarySearch(1000);
    testBinarySearch(10000);
    testBinarySearch(100000);
    return 0;
}
#include <iostream>
#include <vector>
#include <chrono>

void linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return;
        }
    }
}

void testLinearSearch(int n) {
    std::vector<int> worstArr(n);
    for (int i = 0; i < n; i++) {
        worstArr[i] = i;
    }
    // trigger worst-case traversal (N)
    int target = -1;

    auto startWorst = std::chrono::high_resolution_clock::now();
    linearSearch(worstArr, target);
    auto endWorst = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> worstTime = endWorst - startWorst;

    std::cout << "N = " << n << "\n";
    std::cout << "Worst Case: " << worstTime.count() << " ms\n";
}

int main() {
    std::cout << "Linear Search\n";
    testLinearSearch(1000);
    testLinearSearch(10000);
    testLinearSearch(100000);
    return 0;
}
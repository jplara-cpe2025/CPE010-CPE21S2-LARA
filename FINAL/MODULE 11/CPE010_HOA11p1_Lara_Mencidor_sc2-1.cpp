#include <iostream>
#include <vector>
#include <chrono>

bool Unique(std::vector<int>& A) {
    int n = A.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                return false;
            }   
        }
    }

    return true;
}

void test_unique(int size) {
    std::vector<int> A;

    // Create an array containing unique elements
    for (int i = 0; i < size; i++) {
        A.push_back(i);
    }

    // Start the clock
    std::chrono::steady_clock::time_point begin =
        std::chrono::steady_clock::now();

    bool result = Unique(A);

    // Stop the clock
    std::chrono::steady_clock::time_point end =
        std::chrono::steady_clock::now();

    std::cout << "Array size = " << size << std::endl;
    std::cout << "Time taken = " 
        << std::chrono::duration_cast<std::chrono::microseconds> 
        (end - begin).count() << " microseconds" << std::endl;

    if (result) {
        std::cout << "All elements are unique." << std::endl;
    } else {
        std::cout << "Duplicate elements found." << std::endl;
    }

    std::cout << std::endl;
}

int main() {
    test_unique(1000);
    test_unique(5000);
    test_unique(10000);
    test_unique(20000);

    return 0;
}

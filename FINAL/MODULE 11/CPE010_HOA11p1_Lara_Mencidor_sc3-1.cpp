#include <iostream>
#include <chrono>

long double rpower(long double x, int n) {
    if (n == 0) {
        return 1;
    }

    return x * rpower(x, n - 1);
}

long double brpower(long double x, int n) {
    if (n == 0) {
        return 1;
    }

    if (n % 2 == 1) {
        long double y = brpower(x, (n - 1) / 2);
        return x * y * y;
    }

    long double y = brpower(x, n / 2);
    return y * y;
}

void test_power(int n) {
    long double x = 1;

    // Start rpower timer
    std::chrono::steady_clock::time_point begin1 =
        std::chrono::steady_clock::now();

    long double result1 = rpower(x, n);

    // Stop rpower timer
    std::chrono::steady_clock::time_point end1 =
        std::chrono::steady_clock::now();

    // Start brpower timer
    std::chrono::steady_clock::time_point begin2 =
        std::chrono::steady_clock::now();

    long double result2 = brpower(x, n);

    // Stop brpower timer
    std::chrono::steady_clock::time_point end2 =
        std::chrono::steady_clock::now();

    std::cout << "n = " << n << std::endl;

    std::cout << "rpower time = " << std::chrono::duration_cast<std::chrono::nanoseconds>
        (end1 - begin1).count() << " nanoseconds" << std::endl;

    std::cout << "brpower time = " << std::chrono::duration_cast<std::chrono::nanoseconds>
        (end2 - begin2).count() << " nanoseconds" << std::endl;

    std::cout << std::endl;
}

int main() {
    test_power(10);
    test_power(100);
    test_power(1000);
    test_power(5000);
    test_power(10000);

    return 0;
}

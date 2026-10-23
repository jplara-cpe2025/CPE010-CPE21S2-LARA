#include <iostream>
#include <algorithm>

int memo[100];

int getMinStepsMemo ( int n )
{
    if ( n == 1 ) return 0; // base case
    if( memo[n] != -1 ) return memo[n]; // we have solved it already :)
    int r = 1 + getMinStepsMemo( n - 1 ); // '-1' step . 'r' will contain the optimal answer finally
    if( n%2 == 0 ) r = std::min( r , 1 + getMinStepsMemo( n / 2 ) ) ; // '/2' step
    if( n%3 == 0 ) r = std::min( r , 1 + getMinStepsMemo( n / 3 ) ) ; // '/3' step
    memo[n] = r ; // save the result. If you forget this step, then its same as plain recursion.
    return r;
}

int main() {
    int testCases[] = {1, 4, 7, 10};

    std::cout << "=== Table 12-2: Memoization ===" << std::endl;
    for (int n : testCases) {
        // Initialize memo array with -1 (-1 means not solved yet)
        for (int i = 0; i <= n; i++) {
            memo[i] = -1;
        }
        
        std::cout << "n = " << n << " -> Minimum Steps: " << getMinStepsMemo(n) << std::endl;
    }

    return 0;
}

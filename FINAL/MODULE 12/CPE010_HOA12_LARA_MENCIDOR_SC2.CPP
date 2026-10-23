#include <iostream>
#include <algorithm>

int getMinStepsBU ( int n )
{
    int dp[100], i;
    dp[1] = 0; // trivial case

    for( i = 2 ; i <= n ; i ++ )
        {
            dp[i] = 1 + dp[i-1];
            if(i%2==0) dp[i] = std::min( dp[i] , 1+ dp[i/2] );
            if(i%3==0) dp[i] = std::min( dp[i] , 1+ dp[i/3] );
        }
    return dp[n];
}

int main() {
    int testCases[] = {1, 4, 7, 10};

    std::cout << "=== Table 12-2: Memoization ===" << std::endl;
    for (int n : testCases) {
        // Initialize memo array with -1 (-1 means not solved yet)        
        std::cout << "n = " << n << " -> Minimum Steps: " << getMinStepsBU(n) << std::endl;
    }

    return 0;
}

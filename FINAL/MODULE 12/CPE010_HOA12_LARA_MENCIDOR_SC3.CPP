#include <iostream>
#include <vector>

int countPaths(const std::vector<std::vector<int>>& mat, int M, int N, int i, int j, int cost) {
    if (i >= M || j >= N) {
        return 0;
    }

    if (i == M - 1 && j == N - 1) {
        if (cost == mat[i][j]) {
            return 1;
        }
        return 0;
    }

    int remainingCost = cost - mat[i][j];

    int rightPaths = countPaths(mat, M, N, i, j + 1, remainingCost);
    int downPaths = countPaths(mat, M, N, i + 1, j, remainingCost);

    return rightPaths + downPaths;
}

int main() {
    std::vector<std::vector<int>> mat = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int M = mat.size();
    int N = mat[0].size();

    int cost1 = 25;
    int cost2 = 26;
    int cost3 = 31;

    int result1 = countPaths(mat, M, N, 0, 0, cost1);
    int result2 = countPaths(mat, M, N, 0, 0, cost2);
    int result3 = countPaths(mat, M, N, 0, 0, cost3);

    std::cout << "Cost: " << cost1 << std::endl;
    std::cout << "Paths: " << result1 << std::endl;

    std::cout << "Cost: " << cost2 << std::endl;
    std::cout << "Paths: " << result2 << std::endl;

    std::cout << "Cost: " << cost3 << std::endl;
    std::cout << "Paths: " << result3 << std::endl;

    return 0;
}


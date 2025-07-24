#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1. Recursive (Brute Force)
    // TC: O(2^(m+n)), SC: O(m+n)
    int solveRec(int i, int j, vector<vector<int>>& obstacleGrid) {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        return solveRec(i - 1, j, obstacleGrid) + solveRec(i, j - 1, obstacleGrid);
    }

    int uniquePathsRec(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return solveRec(m - 1, n - 1, obstacleGrid);
    }

    // 2. Memoization (Top-Down DP)
    // TC: O(m*n), SC: O(m*n) + O(m+n)
    int solveMemo(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solveMemo(i - 1, j, obstacleGrid, dp) + solveMemo(i, j - 1, obstacleGrid, dp);
    }

    int uniquePathsMemo(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solveMemo(m - 1, n - 1, obstacleGrid, dp);
    }

    // 3. Tabulation (Bottom-Up DP)
    // TC: O(m*n), SC: O(m*n)
    int uniquePathsTabu(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m - 1][n - 1];
    }

    // 4. Space Optimization
    // TC: O(m*n), SC: O(n)
    int uniquePathsSpaceOpt(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                } else if (i == 0 && j == 0) {
                    curr[j] = 1;
                } else {
                    int up = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j - 1] : 0;
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};

// Main function to test all approaches
int main() {
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    Solution sol;
    cout << "1. Recursive:           " << sol.uniquePathsRec(obstacleGrid) << endl;
    cout << "2. Memoization:         " << sol.uniquePathsMemo(obstacleGrid) << endl;
    cout << "3. Tabulation:          " << sol.uniquePathsTabu(obstacleGrid) << endl;
    cout << "4. Space Optimized DP:  " << sol.uniquePathsSpaceOpt(obstacleGrid) << endl;

    return 0;
}

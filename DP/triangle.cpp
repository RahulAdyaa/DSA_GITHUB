#include <iostream>
using namespace std;

class Solution {
public:
    // ------------------- 1. MEMOIZATION (Top-Down DP) -------------------
    // TC: O(n^2), SC: O(n^2) + O(n) stack space (recursive depth)
    int solveMemo(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp, int n) {
        if (i == n - 1) return triangle[n - 1][j];
        if (dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + solveMemo(i + 1, j, triangle, dp, n);
        int diagonal = triangle[i][j] + solveMemo(i + 1, j + 1, triangle, dp, n);
        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotalMemo(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solveMemo(0, 0, triangle, dp, n);
    }

    // ------------------- 2. TABULATION (Bottom-Up DP) -------------------
    // TC: O(n^2), SC: O(n^2)
    int minimumTotalTabulation(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Base case: copy last row
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonal);
            }
        }

        return dp[0][0];
    }

    // ------------------- 3. SPACE OPTIMIZATION (Only two 1D arrays) -------------------
    // TC: O(n^2), SC: O(n)
    int minimumTotalSpaceOptimized(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> next(triangle[n - 1]);  // last row

        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(i + 1);
            for (int j = 0; j <= i; j++) {
                int down = triangle[i][j] + next[j];
                int diagonal = triangle[i][j] + next[j + 1];
                curr[j] = min(down, diagonal);
            }
            next = curr;  // move up
        }

        return next[0];
    }

    // ------------------- 4. SPACE OPTIMIZED (Even more memory efficient) -------------------
    // Reuses single array (slightly trickier)
    // TC: O(n^2), SC: O(n)
    int minimumTotalSingleArray(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        return dp[0];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout << "1. Memoization: " << sol.minimumTotalMemo(triangle) << endl;
    cout << "2. Tabulation: " << sol.minimumTotalTabulation(triangle) << endl;
    cout << "3. Space Optimized (2 arrays): " << sol.minimumTotalSpaceOptimized(triangle) << endl;
    cout << "4. Space Optimized (1 array): " << sol.minimumTotalSingleArray(triangle) << endl;

    return 0;
}

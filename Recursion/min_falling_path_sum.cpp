#include <iostream>
using namespace std;

class Solution {
public:

    // ----------------------------------------------------
    // 1️⃣ RECURSIVE (TLE for large n)
    // TC: O(3^n), SC: O(n) stack space
    int solveRecursive(int i, int j, vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (j < 0 || j >= n) return 1e9;
        if (i == 0) return matrix[0][j];

        int up = solveRecursive(i-1, j, matrix);
        int leftDiag = solveRecursive(i-1, j-1, matrix);
        int rightDiag = solveRecursive(i-1, j+1, matrix);

        return matrix[i][j] + min({up, leftDiag, rightDiag});
    }

    int minFallingPathSumRecursive(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, solveRecursive(n-1, j, matrix));
        }
        return ans;
    }

    // ----------------------------------------------------
    // 2️⃣ MEMOIZATION (Top-down DP)
    // TC: O(n^2), SC: O(n^2) + O(n) stack space
    int solveMemo(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        if (j < 0 || j >= n) return 1e9;
        if (i == 0) return matrix[0][j];
        if (dp[i][j] != -1) return dp[i][j];

        int up = solveMemo(i-1, j, matrix, dp);
        int leftDiag = solveMemo(i-1, j-1, matrix, dp);
        int rightDiag = solveMemo(i-1, j+1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min({up, leftDiag, rightDiag});
    }

    int minFallingPathSumMemo(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, solveMemo(n-1, j, matrix, dp));
        }
        return ans;
    }

    // ----------------------------------------------------
    // 3️⃣ TABULATION (Bottom-up DP)
    // TC: O(n^2), SC: O(n^2)
    int minFallingPathSumTabulation(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + dp[i-1][j];
                int leftDiag = (j - 1 >= 0) ? matrix[i][j] + dp[i-1][j-1] : INT_MAX;
                int rightDiag = (j + 1 < n) ? matrix[i][j] + dp[i-1][j+1] : INT_MAX;
                dp[i][j] = min({up, leftDiag, rightDiag});
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }

    // ----------------------------------------------------
    // 4️⃣ SPACE OPTIMIZED TABULATION
    // TC: O(n^2), SC: O(n)
    int minFallingPathSumSpaceOptimized(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(matrix[0]); // First row

        for (int i = 1; i < n; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + prev[j];
                int leftDiag = (j - 1 >= 0) ? matrix[i][j] + prev[j - 1] : INT_MAX;
                int rightDiag = (j + 1 < n) ? matrix[i][j] + prev[j + 1] : INT_MAX;
                curr[j] = min({up, leftDiag, rightDiag});
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};

// ----------------- Driver Code ------------------
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    cout << "Recursive: " << sol.minFallingPathSumRecursive(matrix) << endl;
    cout << "Memoization: " << sol.minFallingPathSumMemo(matrix) << endl;
    cout << "Tabulation: " << sol.minFallingPathSumTabulation(matrix) << endl;
    cout << "Space Optimized: " << sol.minFallingPathSumSpaceOptimized(matrix) << endl;

    return 0;
}

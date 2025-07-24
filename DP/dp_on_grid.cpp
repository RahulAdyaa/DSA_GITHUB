// All Approaches to Unique Paths in One File
// Author: OpenAI ChatGPT
// Problem: https://leetcode.com/problems/unique-paths/

// Time & Space complexities are documented above each function

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // 1. Recursive (Brute Force)
    // TC: O(2^(m+n)), SC: O(m+n)
    int rec(int i, int j) {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        return rec(i - 1, j) + rec(i, j - 1);
    }

    int uniquePathsRecursive(int m, int n) {
        return rec(m - 1, n - 1);
    }

    // 2. Memoization (Top-Down DP)
    // TC: O(m*n), SC: O(m*n) + recursion stack
    int memoRec(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = memoRec(i - 1, j, dp) + memoRec(i, j - 1, dp);
    }

    int uniquePathsMemo(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return memoRec(m - 1, n - 1, dp);
    }

    // 3. Tabulation (Bottom-Up DP)
    // TC: O(m*n), SC: O(m*n)
    int uniquePathsTabu(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else {
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }

    // 4. Space Optimized DP
    // TC: O(m*n), SC: O(n)
    int uniquePathsSpaceOpt(int m, int n) {
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    curr[j] = 1;
                else {
                    int up = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j - 1] : 0;
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }

    // 5. Combinatorics
    // TC: O(min(m, n)), SC: O(1)
    int uniquePathsCombinatorics(int m, int n) {
        int N = m + n - 2;
        int r = min(m - 1, n - 1);
        double res = 1;
        for (int i = 1; i <= r; i++) {
            res *= (N - r + i);
            res /= i;
        }
        return (int)(res + 0.5);
    }
};

int main() {
    Solution sol;
    int m, n, choice;

    cout << "Enter grid size m (rows) and n (cols): ";
    cin >> m >> n;

    cout << "\nChoose approach:\n";
    cout << "1. Recursive (Brute Force)\n";
    cout << "2. Memoization (Top-Down DP)\n";
    cout << "3. Tabulation (Bottom-Up DP)\n";
    cout << "4. Space Optimized DP\n";
    cout << "5. Combinatorics\n";
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    int result = 0;

    switch (choice) {
        case 1:
            result = sol.uniquePathsRecursive(m, n);
            break;
        case 2:
            result = sol.uniquePathsMemo(m, n);
            break;
        case 3:
            result = sol.uniquePathsTabu(m, n);
            break;
        case 4:
            result = sol.uniquePathsSpaceOpt(m, n);
            break;
        case 5:
            result = sol.uniquePathsCombinatorics(m, n);
            break;
        default:
            cout << "Invalid choice!\n";
            return 1;
    }

    cout << "Unique Paths from (0,0) to (" << m - 1 << "," << n - 1 << ") = " << result << endl;
    return 0;
}

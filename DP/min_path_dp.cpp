// Leetcode 64 - Minimum Path Sum
// Problem: Find the path from (0,0) to (m-1,n-1) with minimum sum in a grid, moving only right or down.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // ------------------ MEMOIZATION ------------------
    // Time Complexity: O(m * n)
    // Space Complexity: O(m * n) + O(m + n) stack space
    int solveMemo(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[0][0]; // base case
        if(i<0 || j<0) return 1e9; // return large number for invalid cases
        if(dp[i][j] != -1) return dp[i][j]; // already solved

        int up = grid[i][j] + solveMemo(i-1, j, grid, dp);   // move up
        int left = grid[i][j] + solveMemo(i, j-1, grid, dp); // move left

        return dp[i][j] = min(up, left); // take min path
    }

    int minPathSumMemo(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); // initialize with -1
        return solveMemo(m-1, n-1, grid, dp);
    }


    // ------------------ TABULATION ------------------
    // Time Complexity: O(m * n)
    // Space Complexity: O(m * n)
    int minPathSumTabu(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); // create dp table

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) 
                    dp[i][j] = grid[i][j]; // base case
                else {
                    int up = grid[i][j];
                    if(i > 0) up += dp[i-1][j]; // add top cell
                    else up += 1e9; // simulate INT_MAX to avoid overflow

                    int left = grid[i][j];
                    if(j > 0) left += dp[i][j-1]; // add left cell
                    else left += 1e9;

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1]; // final cell has result
    }


    // ------------------ SPACE OPTIMIZATION ------------------
    // Time Complexity: O(m * n)
    // Space Complexity: O(n)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0); // previous row

        for(int i = 0; i < m; i++){
            vector<int> curr(n, 0); // current row
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) 
                    curr[j] = grid[i][j]; // base case
                else {
                    int up = grid[i][j];
                    if(i > 0) up += prev[j]; // use value from previous row
                    else up += 1e9;

                    int left = grid[i][j];
                    if(j > 0) left += curr[j-1]; // use value from current row's left
                    else left += 1e9;

                    curr[j] = min(up, left);
                }
            }
            prev = curr; // move current row to previous for next iteration
        }

        return prev[n-1]; // result is in last column of last processed row
    }
};

// Example Usage
int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout << "Memoization: " << sol.minPathSumMemo(grid) << endl;
    cout << "Tabulation: " << sol.minPathSumTabu(grid) << endl;
    cout << "Space Optimized: " << sol.minPathSum(grid) << endl;

    return 0;
}

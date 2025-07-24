#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to compute number of unique paths in an m x n grid
    int uniquePaths(int m, int n) {
        // Create a 2D DP table with dimensions m x n, initialized to 0
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Fill the DP table
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    // Base case: starting cell has exactly 1 unique path to itself
                    dp[i][j] = 1;
                } else {
                    // Number of ways to reach current cell = from top + from left
                    int up = (i > 0) ? dp[i-1][j] : 0;     // from the cell above
                    int left = (j > 0) ? dp[i][j-1] : 0;   // from the cell to the left
                    dp[i][j] = up + left;
                }
            }
        }

        // Return the number of unique paths to the bottom-right cell
        return dp[m-1][n-1];
    }
};

int main() {
    Solution sol;

    int m = 3; // number of rows
    int n = 7; // number of columns

    // Call the function and display result
    cout << "Unique paths in a " << m << "x" << n << " grid: "
         << sol.uniquePaths(m, n) << endl;

    return 0;
}

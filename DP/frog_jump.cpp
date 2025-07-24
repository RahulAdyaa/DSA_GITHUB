#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// ✅ RECURSION
// 🧠 Intuition: At each stone, try jumping either 1 or 2 steps back and choose the minimum cost.
// ❌ No memoization = recalculates subproblems multiple times.
// ⏱️ Time: O(2^n), 💾 Space: O(n) (stack space)

// int frog_jump(int ind, vector<int>& heights) {
//     if (ind == 0) return 0;
//     int left = frog_jump(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
//     int right = INT_MAX;
//     if (ind > 1) right = frog_jump(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);
//     return min(left, right);
// }

// int main() {
//     vector<int> heights = {30, 10, 60, 10, 60, 50};
//     int n = heights.size();
//     cout << frog_jump(n - 1, heights) << endl;
// }


// ✅ MEMOIZATION (Top-Down DP)
// 🧠 Intuition: Cache already solved subproblems to avoid recomputation.
// ⏱️ Time: O(n), 💾 Space: O(n) (dp array + recursion stack)

// int frog_jump(int ind, vector<int>& heights, vector<int>& dp) {
//     if (ind == 0) return 0;
//     if (dp[ind] != -1) return dp[ind];
//     int left = frog_jump(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
//     int right = INT_MAX;
//     if (ind > 1) right = frog_jump(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
//     return dp[ind] = min(left, right);
// }

// int main() {
//     vector<int> heights = {30, 10, 60, 10, 60, 50};
//     int n = heights.size();
//     vector<int> dp(n + 1, -1); // Store results for indices 0 to n
//     cout << frog_jump(n - 1, heights, dp) << endl;
// }


// ✅ TABULATION (Bottom-Up DP)
// 🧠 Intuition: Build the solution iteratively starting from base case.
// ⏱️ Time: O(n), 💾 Space: O(n)

// int main() {
//     vector<int> heights = {30, 10, 60, 10, 60, 50};
//     int n = heights.size();
//     vector<int> dp(n, -1);
//     dp[0] = 0;
//     for (int i = 1; i < n; i++) {
//         int first = dp[i - 1] + abs(heights[i] - heights[i - 1]);
//         int second = INT_MAX;
//         if (i > 1) second = dp[i - 2] + abs(heights[i] - heights[i - 2]);
//         dp[i] = min(first, second);
//     }
//     cout << dp[n - 1] << endl;
// }


// ✅ SPACE OPTIMIZATION
// 🧠 Intuition: Since we only use dp[i-1] and dp[i-2], we can reduce space to O(1).
// ⏱️ Time: O(n), 💾 Space: O(1)

int main() {
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    int n = heights.size();

    int prev = 0;   // dp[i-1]
    int prev2 = 0;  // dp[i-2]
    
    for (int i = 1; i < n; i++) {
        int first = prev + abs(heights[i] - heights[i - 1]);
        int second = INT_MAX;
        if (i > 1) second = prev2 + abs(heights[i] - heights[i - 2]);
        int curr = min(first, second);
        prev2 = prev;
        prev = curr;
    }
    cout << prev << endl;
}

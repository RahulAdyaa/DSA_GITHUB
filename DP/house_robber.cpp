#include<iostream>
#include<vector>
using namespace std;

//
// RECURSION + MEMOIZATION
// -----------------------------------
// Intuition:
// At each index, you have two choices:
// 1. Pick the current house → add its value and move to i-2
// 2. Don't pick → move to i-1
// Use memoization (dp) to store results of subproblems to avoid recomputation.
//
// Time Complexity: O(n) [Each index is computed once]
// Space Complexity: O(n) [Recursion stack + dp array]
//
int solve(int ind, vector<int>& nums, vector<int>& dp) {
    if (ind == 0) return nums[ind];     // base case: only one house
    if (ind < 0) return 0;              // invalid case
    if (dp[ind] != -1) return dp[ind];  // return cached result

    int pick = nums[ind] + solve(ind - 2, nums, dp);  // pick current and skip previous
    int not_pick = solve(ind - 1, nums, dp);          // skip current
    return dp[ind] = max(pick, not_pick);             // store and return max
}

//
// TABULATION (Bottom-Up DP)
// -----------------------------------
// Intuition:
// Build the solution from the base up, tracking the max amount you can rob at each house.
// dp[i] stores max money robbed from house 0 to i.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
//
int solve(vector<int>& nums, vector<int> dp, int n) {
    dp[0] = nums[0];  // base case

    for (int i = 1; i < n; i++) {
        int take = nums[i];
        if (i > 1) take += dp[i - 2];   // if possible, add value from i-2
        int not_take = dp[i - 1];       // skip current house
        dp[i] = max(take, not_take);    // store max of pick or not_pick
    }

    return dp[n - 1];
}

//
// SPACE OPTIMIZED DP
// -----------------------------------
// Intuition:
// Only the last two states (i-1 and i-2) are needed at each step.
// Replace dp[] array with just two variables.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
int solve(int n, vector<int>& nums) {
    int prev = nums[0];   // dp[i-1]
    int prev2 = 0;        // dp[i-2]

    for (int i = 1; i < n; i++) {
        int take = nums[i];
        if (i > 1) take += prev2;       // add i-2 value if valid
        int not_take = prev;            // skip current house

        int curr_i = max(take, not_take); // result for current index
        prev2 = prev;                     // update for next iteration
        prev = curr_i;
    }

    return prev; // holds dp[n-1]
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int n = nums.size();
    vector<int> dp(n, -1);

    cout << "Memoized Recursion: " << solve(n - 1, nums, dp) << endl;
    cout << "Tabulation: " << solve(nums, vector<int>(n, -1), n) << endl;
    cout << "Space Optimized: " << solve(n, nums) << endl;

    return 0;
}

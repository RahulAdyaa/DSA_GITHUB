#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//
// SPACE OPTIMIZED DP FUNCTION
// ----------------------------
// Solves the standard House Robber problem on a linear array.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
int solve(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int prev = nums[0];  // dp[i-1]
    int prev2 = 0;       // dp[i-2]

    for (int i = 1; i < n; i++) {
        int take = nums[i];
        if (i > 1) take += prev2;
        int not_take = prev;

        int curr_i = max(take, not_take);
        prev2 = prev;
        prev = curr_i;
    }

    return prev;
}

//
// HOUSE ROBBER II SOLVER (Circular Houses)
// ----------------------------------------
// Since the first and last houses are adjacent, we can't rob both.
// So we compute two cases:
//   1. Exclude first house → rob from 1 to n-1
//   2. Exclude last house  → rob from 0 to n-2
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> temp1(nums.begin() + 1, nums.end());   // exclude first
    vector<int> temp2(nums.begin(), nums.end() - 1);   // exclude last

    return max(solve(temp1), solve(temp2));
}

//
// DRIVER CODE
//
int main() {
    vector<int> nums = {2, 3, 2};  // Example input
    cout << "Maximum amount that can be robbed: " << rob(nums) << endl;
    return 0;
}

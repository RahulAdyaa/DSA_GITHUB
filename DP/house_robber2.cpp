#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//
// ==== MEMOIZATION ====
// ---------------------
// Time Complexity: O(n)
// Space Complexity: O(n) [dp + recursion stack]
//
int memo_solve(int ind, vector<int>& nums, vector<int>& dp) {
    if (ind == 0) return nums[0];
    if (ind < 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + memo_solve(ind - 2, nums, dp);
    int not_pick = memo_solve(ind - 1, nums, dp);

    return dp[ind] = max(pick, not_pick);
}

int rob_with_memo(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> temp1(nums.begin() + 1, nums.end());     // exclude first
    vector<int> temp2(nums.begin(), nums.end() - 1);     // exclude last

    vector<int> dp1(temp1.size(), -1);
    vector<int> dp2(temp2.size(), -1);

    return max(memo_solve(temp1.size() - 1, temp1, dp1),
               memo_solve(temp2.size() - 1, temp2, dp2));
}

//
// ==== TABULATION ====
// ---------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
//
int tab_solve(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++) {
        int pick = nums[i];
        if (i > 1) pick += dp[i - 2];
        int not_pick = dp[i - 1];
        dp[i] = max(pick, not_pick);
    }

    return dp[n - 1];
}

int rob_with_tab(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> temp1(nums.begin() + 1, nums.end());     // exclude first
    vector<int> temp2(nums.begin(), nums.end() - 1);     // exclude last

    return max(tab_solve(temp1), tab_solve(temp2));
}

//
// ==== SPACE OPTIMIZATION ====
// ----------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
//
int space_opt_solve(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int prev = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++) {
        int take = nums[i] + (i > 1 ? prev2 : 0);
        int not_take = prev;
        int curr = max(take, not_take);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int rob_with_space_opt(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];

    vector<int> temp1(nums.begin() + 1, nums.end());     // exclude first
    vector<int> temp2(nums.begin(), nums.end() - 1);     // exclude last

    return max(space_opt_solve(temp1), space_opt_solve(temp2));
}

//
// ==== DRIVER FUNCTION ====
// --------------------------
int main() {
    vector<int> nums = {2, 3, 2};  // Example test case

    cout << "Input: ";
    for (int val : nums) cout << val << " ";
    cout << "\n\n";

    cout << "[Memoization]        Max Robbed Amount: " << rob_with_memo(nums) << endl;
    cout << "[Tabulation]         Max Robbed Amount: " << rob_with_tab(nums) << endl;
    cout << "[Space Optimized]    Max Robbed Amount: " << rob_with_space_opt(nums) << endl;

    return 0;
}

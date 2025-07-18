#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

// ✅ RECURSIVE APPROACH (with K jumps)
// 🧠 Intuition: From index `ind`, try jumping back by 1 to `k` steps.
//     Calculate the cost from each valid step and take the minimum.
// ❌ This leads to overlapping subproblems.
// ⏱️ Time: O(k^n) in worst case (exponential)
// 💾 Space: O(n) (due to recursion stack)

int frog_jump(int ind, vector<int> &heights, int k)
{
    if (ind == 0)
        return 0;

    int minjumps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
        {
            int cost = frog_jump(ind - j, heights, k) + abs(heights[ind] - heights[ind - j]);
            minjumps = min(minjumps, cost);
        }
    }
    return minjumps;
}

// MEMOIZATION ---> Use dp array , check for availability of that ind in dp array  , baaki sab same , and end mein uss index pe dp mein store krdo
int frog_jump(int ind, vector<int> &heights, int k, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int minjumps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
        {
            int cost = frog_jump(ind - j, heights, k, dp) + abs(heights[ind] - heights[ind - j]);
            minjumps = min(minjumps, cost);
        }
    }
    return dp[ind] = minjumps;
}

// TABULATION

int frog_jump(vector<int> &heights, int k, vector<int> &dp, int n)
{

    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minjumps = INT_MAX; // Reset for every i
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int cost = dp[i - j] + abs(heights[i] - heights[i - j]);
                minjumps = min(minjumps, cost);
            }
        }
        dp[i] = minjumps; // Assign after finding min for current i
    }

    return dp[n - 1];
}

int main()
{
    vector<int> heights = {30, 10, 60, 10, 60, 50, 10, 0, 80};
    int n = heights.size();
    int k = 4;
    cout << frog_jump(n - 1, heights, k) << endl;

    // MEMOIZATION
    vector<int> dp(n, -1);
    cout << frog_jump(n - 1, heights, k, dp) << endl;

    // TABULATION
    cout << frog_jump(heights, k, dp, n) << endl;
}

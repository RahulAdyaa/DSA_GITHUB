#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
----------------------------------------------
🧠 Problem Intuition:
To reach the nth stair, you can either:
- Come from (n-1)th stair with a 1-step jump
- Come from (n-2)th stair with a 2-step jump

So:
    climbStairs(n) = climbStairs(n-1) + climbStairs(n-2)

This is identical to the Fibonacci pattern with shifted base cases.
We explore different ways to compute this: recursion, memoization,
tabulation, and space optimization.
----------------------------------------------
*/

// ----------------------------------------------
// ❌ Approach 1: Plain Recursion (Exponential Time)
/*
Intuition:
- Compute from top recursively.
- Huge overlap = redundant recomputation

TC: O(2^n)
SC: O(n) (due to call stack)

int climbStairs(int n) {
    if (n == 0 || n == 1)
        return 1;
    return climbStairs(n - 1) + climbStairs(n - 2);
}
*/

// ----------------------------------------------
// ✅ Approach 2: Memoization (Top-Down DP)
/*
Intuition:
- Use recursion + cache results.
- Avoids redundant calculations by memoizing.

TC: O(n)
SC: O(n) (memo map + recursion stack)

int climbStairsHelper(int n, unordered_map<int, int>& memo) {
    if (n == 0 || n == 1) return 1;
    if (memo.find(n) == memo.end()) {
        memo[n] = climbStairsHelper(n - 1, memo) + climbStairsHelper(n - 2, memo);
    }
    return memo[n];
}

int climbStairs(int n) {
    unordered_map<int, int> memo;
    return climbStairsHelper(n, memo);
}
*/

// ----------------------------------------------
// ✅ Approach 3: Tabulation (Bottom-Up DP)
/*
Intuition:
- Build solution from base up.
- Store all subproblem answers in dp[].

TC: O(n)
SC: O(n)

int climbStairs(int n) {
    if (n == 0 || n == 1) return 1;
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}
*/

// ----------------------------------------------
// ✅✅ Approach 4: Space Optimization (Final Running Version)
/*
Intuition:
- Only previous 2 results are needed.
- Optimize space from O(n) to O(1)

TC: O(n)
SC: O(1)
*/

int climbStairs(int n) {
    if (n == 0 || n == 1) return 1;
    int prev = 1, curr = 1;

    for (int i = 2; i <= n; i++) {
        int temp = curr;
        curr = prev + curr;
        prev = temp;
    }

    return curr;
}

// ----------------------------------------------
// 🔁 Driver Code
int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    cout << "Number of ways to climb " << n << " stairs: " << climbStairs(n) << endl;
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

/*
🔹 Approach 1: MEMOIZATION (Top-Down Dynamic Programming)

🧠 Intuition:
We use recursion to break the Fibonacci problem into subproblems.
To avoid recalculating the same values again and again, we store results in a `dp` array.
This ensures each subproblem is solved only once.

📈 Time Complexity: O(n)
🗃️ Space Complexity: O(2n) — for the dp array + recursion call stack

⚠️ Important: vector<int> should be passed by reference to avoid copy on each call.
*/
int fib(int n, vector<int> &dp) {
    if (n == 0 || n == 1) return n;
    if (dp[n] != -1) return dp[n];

    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

/*
🔹 Approach 2: TABULATION with Space Optimization (Bottom-Up DP)

🧠 Intuition:
We start from the base cases and iteratively compute the Fibonacci sequence.
Instead of storing all values in a dp array, we only store the last two values needed.

📈 Time Complexity: O(n)
🗃️ Space Complexity: O(1) — only two variables used (prev, prev2)

✅ This is the most space-efficient way to compute Fibonacci numbers.
*/
int fib2(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev2 = 0;
    int prev = 1;

    for (int i = 2; i <= n; i++) {
        int curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }

    return prev;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // 🔸 MEMOIZATION
    // vector<int> dp(n + 1, -1);
    // cout << fib(n, dp) << endl;

    // 🔸 TABULATION
    cout << fib2(n) << endl;

    return 0;
}

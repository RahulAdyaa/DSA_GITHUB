#include<iostream>
#include<vector>
using namespace std;

/*
================================================================
🔁 INTUITION – FREQ ARRAY + DS VECTOR (Backtracking):

This approach uses:
- `freq[]` to keep track of which indices have been used.
- `ds[]` (a temporary vector) to build permutations step-by-step.

At each step, we try every unused element, mark it as used,
recurse, and then backtrack.

================================================================
📊 TIME & SPACE COMPLEXITY:

✅ Time Complexity: O(n!)
- Because we generate all possible permutations of `n` elements.

❌ Space Complexity: O(n) + O(n)
- O(n) for the frequency array `freq[]`
- O(n) for the temporary vector `ds[]`
- Plus O(n) recursion stack space

So, total space: **O(2n)** ≈ O(n) but higher than in-place approach.

🚩 This is **less memory-efficient** compared to the in-place
swap approach (which uses only recursion stack).

================================================================
*/

void permute(vector<int>& freq, vector<int>& ds, vector<vector<int>>& ans, vector<int>& arr) {
    if(ds.size() == arr.size()) {
        ans.push_back(ds);  // base case: one permutation completed
        return;
    }

    for(int i = 0; i < arr.size(); i++) {
        if(!freq[i]) {                    // if element at i not used
            ds.push_back(arr[i]);        // choose
            freq[i] = 1;                 // mark as used
            permute(freq, ds, ans, arr); // recurse
            freq[i] = 0;                 // unmark
            ds.pop_back();               // remove last element (backtrack)
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> freq(arr.size(), 0); // freq[] initialized with 0
    vector<int> ds;
    vector<vector<int>> ans;

    permute(freq, ds, ans, arr); // start permutation generation

    for(auto& permutation : ans) {
        cout << "{ ";
        for(auto val : permutation) {
            cout << val << " ";
        }
        cout << "}\n" << endl;
    }
}

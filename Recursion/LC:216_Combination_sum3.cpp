#include<iostream>
#include<vector>
using namespace std;

/*
Time Complexity: O(2^9)
Space Complexity: O(k) (k = size of subset)
*/

void combinationsum3(int idx, int target, int size, vector<int>& ds, vector<vector<int>>& ans) {
    // ✅ Base condition: if target is met and subset size is exactly 'size'
    if (target == 0 && ds.size() == size) {
        ans.push_back(ds);
        return;
    }

    // 🔁 Iterate through numbers from idx to 9
    for (int i = idx; i <= 9; i++) {
        // ✅ Prune if remaining target is smaller than current number or subset is too big
        if (target < i || ds.size() >= size)
            break;

        ds.push_back(i);  // Include current number
        combinationsum3(i + 1, target - i, size, ds, ans);  // Move to next number
        ds.pop_back();    // Backtrack to explore other possibilities
    }
}

int main() {
    int size = 3;
    int target = 7;
    vector<int> ds;                 // Current combination
    vector<vector<int>> ans;       // All valid combinations

    combinationsum3(1, target, size, ds, ans);  // Start from number 1

    // 🔽 Print all valid combinations
    for (auto subset : ans) {
        cout << "{ ";
        for (auto val : subset)
            cout << val << " ";
        cout << "}\n";
    }

    return 0;
}

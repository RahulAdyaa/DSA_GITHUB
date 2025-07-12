#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all subsequences
void generateSubsequences(int idx, int arr[], int n, vector<int>& ds, vector<vector<int>>& ans) {
    // Base case: if index reaches the end of the array
    if (idx == n) {
        ans.push_back(ds);  // Store the current subsequence
        return;
    }

    // Include the current element
    ds.push_back(arr[idx]);
    generateSubsequences(idx + 1, arr, n, ds, ans);

    // Exclude the current element (backtrack)
    ds.pop_back();
    generateSubsequences(idx + 1, arr, n, ds, ans);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    vector<int> ds;  // Temporary vector to store current subsequence
    vector<vector<int>> ans;  // Final list of all subsequences

    generateSubsequences(0, arr, n, ds, ans);

    cout << "\nAll Subsequences:\n";
    for (auto& seq : ans) {
        cout << "{ ";
        for (int num : seq) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}

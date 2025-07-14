#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all subsets (power set)
void subsets(int idx, int arr[], int n, vector<int>& ds, vector<vector<int>>& ans) {
    // Base case: if index reaches the end of the array
    if (idx == n) {
        ans.push_back(ds); // store the current subset
        return;
    }

    // Include the current element in the subset
    subsets(idx + 1, arr, n, ds, ans);
    ds.push_back(arr[idx]);

    // Exclude the current element from the subset (backtrack)
    subsets(idx + 1, arr, n, ds, ans);
    ds.pop_back();
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Declare array of size n
    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // ds stores the current subset being built
    vector<int> ds;

    // ans stores all subsets
    vector<vector<int>> ans;

    // Generate all subsets
    subsets(0, arr, n, ds, ans);

    // Output all subsets
    cout << "\nAll Subsets:\n";
    for (auto subset : ans) {
        cout << "{ ";
        for (int val : subset) {
            cout << val << " ";
        }
        cout << "}\n";
    }

    return 0;
}

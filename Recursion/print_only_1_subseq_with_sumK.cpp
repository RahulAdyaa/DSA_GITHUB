// Time Complexity (TC): O(2^n)  
//   - At each index, we have two choices: include or exclude → 2^n subsets explored in the worst case.
// Space Complexity (SC): O(n)  
//   - At most, the call stack goes n levels deep, and the ds vector holds up to n elements.

#include<iostream>
#include<vector>
using namespace std;

// Function to print one subsequence whose sum equals 'k'
bool printS(int ind, vector<int>& ds, vector<int>& arr, int n, int sum, int k) {
    // Base case: reached the end of array
    if (ind == n) {
        // If current sum equals required sum 'k'
        if (sum == k) {
            for (auto it : ds) cout << it << " ";  // Print the valid subsequence
            cout << endl;
            return true;  // Stop after finding the first valid subsequence
        }
        return false;
    }

    // Include current element in the subsequence
    ds.push_back(arr[ind]);
    sum += arr[ind];
    if (printS(ind + 1, ds, arr, n, sum, k) == true) {
        return true;  // If a valid subsequence is found in this path, propagate true upward
    }

    // Backtrack: remove the last element and undo the sum
    sum -= arr[ind];
    ds.pop_back();

    // Exclude current element and continue
    if (printS(ind + 1, ds, arr, n, sum, k) == true) {
        return true;
    }

    return false;  // No valid subsequence found in either path
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};  // Input array
    vector<int> ds;                     // Temporary storage for current subsequence
    int k = 5;                          // Target sum
    int n = 5;                          // Size of the array

    // Start recursive search from index 0 and sum 0
    printS(0, ds, arr, n, 0, k);
}

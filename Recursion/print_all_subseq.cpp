#include<iostream>
#include<vector>
using namespace std;

// Recursive function to generate all subsets
void printF(int ind, vector<int> ds, vector<int>& arr, int n) {
    // Base case: if we've considered all elements
    if(ind == n) {
        // Print current subset
        for(auto it : ds) {
            cout << it << " ";
        }

        // If subset is empty, print {}
        if(ds.size() == 0) {
            cout << "{}";
        }

        cout << endl;
        return;
    }

    // Include the current element
    ds.push_back(arr[ind]);
    printF(ind + 1, ds, arr, n);

    // Backtrack: remove the element to explore the "exclude" path
    ds.pop_back();

    // Exclude the current element
    printF(ind + 1, ds, arr, n);
}

int main() {
    vector<int> arr = {3, 1, 2};  // Input array
    int n = 3;                    // Size of the array
    vector<int> ds;               // Temporary vector to store current subset

    // Call recursive function to print all subsets
    printF(0, ds, arr, n);
}

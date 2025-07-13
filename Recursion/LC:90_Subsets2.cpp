// Time Complexity: O(2^n)  -- Every element has two choices: include or exclude.
// Space Complexity: O(2^n * k) where k is the average subset size, 
// plus O(n) auxiliary space for recursion and subset being built.

//Sorting is necessary to easily detect and skip duplicate elements

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Recursive function to generate all subsets without duplicates
void subsets(int idx , vector<int>& arr , vector<int>& ds , vector<vector<int>>& ans){
    // Store the current subset (ds) in the result
    ans.push_back(ds);

    // Loop through elements starting from current index
    for(int i = idx; i < arr.size(); i++){
        // Skip duplicates: if current element is same as previous and not at starting index
        if(i > idx && arr[i] == arr[i-1]) continue;

        // Include the current element in the subset
        ds.push_back(arr[i]);

        // Recurse for the next elements
        subsets(i + 1, arr, ds, ans);

        // Backtrack: remove last added element
        ds.pop_back();
    }
}

int main(){
    vector<int> arr = {1, 2, 2};       // Input array (may contain duplicates)
    vector<int> ds;                    // Temporary subset (to be built during recursion)
    vector<vector<int>> ans;          // Final result containing all unique subsets

    // Sort array to bring duplicates together (required for skipping duplicates)
    sort(arr.begin(), arr.end());

    // Generate subsets
    subsets(0, arr, ds, ans);

    // Output all unique subsets
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

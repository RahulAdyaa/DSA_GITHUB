#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all subsets (power set)
void subsetsum(int idx, int arr[], int n , int sum, vector<int>& ds) {
    // Base case: if index reaches the end of the array
    if (idx == n) {
        ds.push_back(sum);
        return;
    }

    subsetsum(idx + 1, arr, n, sum+arr[idx], ds);
    subsetsum(idx + 1, arr, n , sum,  ds);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    // Input array elements
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    vector<int> ds;
    

    // Generate all subsets
    subsetsum(0, arr, n , 0 , ds);
    sort(ds.begin(),ds.end());

    // Output all subset sums
    cout << "\nAll Subset sums:\n";
    for (auto val : ds) {  
        cout << val << " ";
    }

    return 0;
}

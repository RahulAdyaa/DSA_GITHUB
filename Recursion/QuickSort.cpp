/*
===========================================
🧠 QUICK SORT ALGORITHM

🕒 TIME COMPLEXITY:
--------------------
Best Case:     O(n log n)     -> Pivot divides array equally
Average Case:  O(n log n)     -> Random pivots
Worst Case:    O(n^2)         -> Already sorted array with first/last pivot

🗂️ SPACE COMPLEXITY:
---------------------
In-place sorting: O(1) extra space
Recursive stack:
- Best/Average: O(log n)
- Worst:        O(n)

⚠️ Worst case occurs when pivot is always the smallest or largest element,
which causes unbalanced partitions (e.g., sorted input).
===========================================
*/

#include<iostream>
#include<vector>
using namespace std;

// Partition function: places pivot at correct position and partitions array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];  // Choose first element as pivot
    int i = low;
    int j = high;

    while(i < j) {
        // Increment i until element > pivot
        while(arr[i] <= pivot && i <= high - 1) i++;
        // Decrement j until element <= pivot
        while(arr[j] > pivot && j >= low + 1) j--;

        // Swap elements at i and j if needed
        if(i < j) swap(arr[i], arr[j]);
    }

    // Swap pivot with element at j (correct position)
    swap(arr[low], arr[j]);
    return j;
}

// Quicksort function (recursive)
void quicksort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pIndex = partition(arr, low, high);   // Partition and get pivot index
        quicksort(arr, low, pIndex - 1);          // Recursively sort left part
        quicksort(arr, pIndex + 1, high);         // Recursively sort right part
    }
}

int main() {
    vector<int> arr = {2, 4, 1, 5, 9, 6, 7, 8};
    int low = 0;
    int high = arr.size() - 1;

    quicksort(arr, low, high);  // Sort the array using quicksort

    // Print sorted array
    for(auto it : arr) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

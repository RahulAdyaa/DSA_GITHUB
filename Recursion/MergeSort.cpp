#include <iostream>
#include <vector>
using namespace std;

/*
    Merge Sort
    ----------
    Time Complexity (TC): O(n log n)
        - Each level of recursion processes all 'n' elements.
        - There are log n levels (due to divide by 2 each time).

    Space Complexity (SC): O(n)
        - Temporary vector stores elements during each merge step.
        - The recursion stack is O(log n), but temp arrays use O(n) extra space.
*/

// Merge function to merge two sorted halves: arr[low...mid] and arr[mid+1...high]
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    // Compare elements from both halves and store the smaller one
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements from the left half (if any)
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from the right half (if any)
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the merged elements back into the original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Recursive function to divide the array into halves and sort them
void mergesort(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    // Find the middle point of the current subarray
    int mid = (low + high) / 2;

    // Recursively sort the left half: arr[low...mid]
    mergesort(arr, low, mid);

    // Recursively sort the right half: arr[mid+1...high]
    mergesort(arr, mid + 1, high);

    // Merge the two sorted halves
    merge(arr, low, mid, high);
}

int main() {
    vector<int> arr = {1, 3, 2, 5, 4};
    int n = arr.size();

    // Call mergesort on the full array
    mergesort(arr, 0, n - 1);

    // Output the sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

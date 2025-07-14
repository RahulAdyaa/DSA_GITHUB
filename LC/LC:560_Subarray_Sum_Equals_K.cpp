#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    Problem: Count the number of subarrays whose sum equals k.

    Time Complexity: O(n)
    - We iterate over the array once.
    - All hashmap operations (insert and lookup) are O(1) on average.

    Space Complexity: O(n)
    - In the worst case, we store up to n distinct prefix sums in the map.
*/

int main() {
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k = 3;

    unordered_map<int, int> mpp;  // Hash map to store frequency of prefix sums
    mpp[0] = 1;  // Initialize with prefix sum 0 (important for subarrays starting at index 0)

    int presum = 0;  // Running prefix sum
    int cnt = 0;     // Count of subarrays with sum equal to k

    for (int i = 0; i < arr.size(); i++) {
        presum += arr[i];                // Update the running prefix sum
        int remove = presum - k;         // Check if there's a prefix sum that makes current sum = k
        cnt += mpp[remove];              // If such a prefix exists, add its count to result
        mpp[presum] += 1;                // Store/update current prefix sum in the map
    }

    cout << cnt << endl;  // Output the total count of subarrays with sum k
    return 0;
}

// Time Complexity: O(N) — Single pass with two pointers
// Space Complexity: O(1) — No extra space (excluding result vector)

// Assumes input array is sorted in non-decreasing order

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size() - 1;
        vector<int> result;

        while (l <= r) {
            int sum = arr[l] + arr[r];

            if (sum == target) {
                // Found the two indices (1-based index as per LeetCode problem #167)
                result.push_back(l + 1);
                result.push_back(r + 1);
                break; // Once found, break the loop
            } else if (sum < target) {
                l++; // Increase left pointer if sum is less than target
            } else {
                r--; // Decrease right pointer if sum is more than target
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> res = sol.twoSum(nums, target);

    cout << "Indices: ";
    for (int index : res) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}

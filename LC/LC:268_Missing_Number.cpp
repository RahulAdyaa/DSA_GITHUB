#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // ✅ Method 1: XOR Method [Most Optimized]
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int missingNumber(vector<int>& nums) {
        int XOR1 = 0; // XOR of 1 to n
        int XOR2 = 0; // XOR of array elements
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            XOR2 ^= nums[i];     // XOR all array elements
            XOR1 ^= (i + 1);     // XOR all from 1 to n
        }
        return XOR1 ^ XOR2;      // Missing number remains
    }

    /*
    // 🔒 Method 2: Sum Formula Method
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }
        return expectedSum - actualSum;
    }
    */

    /*
    // 🔒 Method 3: Hashing / Set Method
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    int missingNumber(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); i++) {
            if (seen.find(i) == seen.end()) {
                return i;
            }
        }
        return -1; // Should not reach here
    }
    */
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {3, 0, 1}; // Missing = 2
    cout << "Missing Number (Test 1): " << sol.missingNumber(nums1) << endl;

    // Test Case 2
    vector<int> nums2 = {0, 1}; // Missing = 2
    cout << "Missing Number (Test 2): " << sol.missingNumber(nums2) << endl;

    // Test Case 3
    vector<int> nums3 = {0}; 
    cout << "Missing Number (Test 3): " << sol.missingNumber(nums3) << endl;

    // Test Case 4
    vector<int> nums4 = {1,1}; 
    cout << "Missing Number (Test 3): " << sol.missingNumber(nums4) << endl;

    // Test Case 5
    vector<int> nums5 = {1,2,1,2};
    cout << "Missing Number (Test 3): " << sol.missingNumber(nums5) << endl;

    //

    return 0;
}

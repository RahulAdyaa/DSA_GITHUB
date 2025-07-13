#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

    /*
    // Approach 1: Using unordered_set
    // Time Complexity : O(n)
    // Space Complexity: O(n)
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> uniquenums;
        int val = 0;

        for (int num : nums) {
            if (uniquenums.count(num)) {
                val ^= num;
            }
            uniquenums.insert(num);
        }

        return val;
    }
    */

    // Approach 2: Using frequency array
    // Time Complexity : O(n)
    // Space Complexity: O(1)
    int duplicateNumbersXOR(vector<int>& nums) {
        const int MAX = 10001;
        int freq[MAX] = {0};
        int val = 0;

        for (int num : nums) {
            freq[num]++;
            if (freq[num] == 2) {
                val ^= num;
            }
        }

        return val;
    }
};

int main() {
    Solution sol;

    // Test case
    vector<int> nums = {1, 2, 1, 3, 2, 4, 5};  // Expected XOR of duplicates: 1 ^ 2 = 3
    int result = sol.duplicateNumbersXOR(nums);

    cout << "XOR of numbers that appear twice: " << result << endl;

    return 0;
}

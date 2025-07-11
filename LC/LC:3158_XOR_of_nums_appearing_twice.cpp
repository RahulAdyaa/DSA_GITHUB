class Solution {
public:

    /*
    // Approach 1: Using unordered_set
    // TC: O(n) average-case, where n = nums.size()
    // SC: O(n) — for storing up to n unique elements in the unordered_set
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> uniquenums;
        int val = 0;
        for (int num : nums) {
            if (uniquenums.count(num)) {
                val ^= num;  // XOR on second occurrence
            }
            uniquenums.insert(num);
        }
        return val;
    }
    */

    // Approach 2: Using frequency array
    // TC: O(n), where n = nums.size()
    // SC: O(1) — uses fixed-size array (size 10001 here, can be reduced based on constraints)
    int duplicateNumbersXOR(vector<int>& nums) {
        const int MAX = 10001;  // Assumes nums[i] ≤ 10000
        int freq[MAX] = {0};
        int val = 0;

        for (int num : nums) {
            freq[num]++;
            if (freq[num] == 2) {
                val ^= num;  // XOR on second occurrence
            }
        }
        return val;
    }
};

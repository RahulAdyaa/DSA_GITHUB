// ✅ 1991. Find the Middle Index in Array
// 📌 Intuition:
//     - Total sum of array = left sum + current element + right sum
//     - So at each index, check if left sum == total sum - left sum - nums[i]
// 🕒 Time Complexity: O(n)
// 💾 Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

// 🚀 Test code (optional for VS Code)
int main() {
    Solution sol;
    vector<int> nums = {2, 3, -1, 8, 4};
    cout << "Middle Index: " << sol.findMiddleIndex(nums) << endl;
    return 0;
}

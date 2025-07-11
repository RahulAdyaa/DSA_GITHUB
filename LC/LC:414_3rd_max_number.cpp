// Time Complexity: O(N) — where N is the number of elements in the input array.
// - Inserting N elements into a set: O(N)
// - max_element: O(N) in worst case
// - Heap operations on up to 3 elements: O(1) per insertion (constant)
// Space Complexity: O(N) — For the unordered_set to remove duplicates

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> uniqueNums;  // To remove duplicates

        // Step 1: Insert unique numbers into a set
        for (int num : nums) {
            uniqueNums.insert(num);
        }

        // Step 2: If there are fewer than 3 unique elements, return the max
        if (uniqueNums.size() < 3) {
            return *max_element(uniqueNums.begin(), uniqueNums.end());
        }

        // Step 3: Use a min-heap to keep track of the top 3 maximum elements
        priority_queue<int, vector<int>, greater<int>> minheap;

        for (int num : uniqueNums) {
            minheap.push(num);
            if (minheap.size() > 3) {
                minheap.pop();  // Keep only 3 largest elements
            }
        }

        // Step 4: Top of the heap will now be the 3rd maximum
        return minheap.top();
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {2, 2, 3, 1,2,4,5,32};

    // Output the 3rd maximum
    int ans = sol.thirdMax(nums);
    cout << "Third maximum number is: " << ans << endl;

    return 0;
}

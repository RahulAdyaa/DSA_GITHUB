// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int findLHS(vector<int>& nums) {
    unordered_map<int, int> freq;  // Store frequencies of each number

    // Step 1: Count frequency of each element
    for (int num : nums) {
        freq[num]++;
    }

    int maxlen = 0;

    // Step 2: Check for every number if (number + 1) exists
    for (auto &[num, count] : freq) {
        if (freq.count(num + 1)) {
            // Combine count of current number and its neighbor
            maxlen = max(maxlen, count + freq[num + 1]);
        }
    }

    return maxlen;
}

int main() {
    vector<int> nums;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        nums.push_back(val);
    }

    int result = findLHS(nums);
    cout << "Length of Longest Harmonious Subsequence: " << result << endl;

    return 0;
}

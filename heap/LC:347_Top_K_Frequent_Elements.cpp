// Time Complexity: O(N * log K), where N is the number of elements in the array.
//                  We iterate through all elements once and maintain a heap of size K.
// Space Complexity: O(N), for the frequency map and the heap (at most K elements in the heap).

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>     // for priority_queue
#include <utility>   // for pair
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequency of each number using unordered_map
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Min-heap to store top k frequent elements
        // Heap stores {frequency, number} pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

        for (auto& [num, count] : freq) {
            minheap.push({count, num});
            if (minheap.size() > k) {
                minheap.pop(); // remove least frequent element if size exceeds k
            }
        }

        // Step 3: Extract elements from the heap into result
        vector<int> result;
        while (!minheap.empty()) {
            result.push_back(minheap.top().second); // store the number (not the frequency)
            minheap.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    // Get the result
    vector<int> topK = sol.topKFrequent(nums, k);

    // Print the result
    cout << "Top " << k << " frequent elements are: ";
    for (int num : topK) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

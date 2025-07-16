#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
Intuition:
----------
We are given a string 's' and a dictionary of words 'wordDict'.
The goal is to determine if 's' can be segmented into a sequence of one or more dictionary words.

Approach:
---------
1. Start from index 0 and try every possible substring starting at that index.
2. If the substring exists in the dictionary (wordDict), recursively try to break the remaining string.
3. Use memoization to avoid recalculating results for the same starting index.
4. If we reach the end of the string (idx == s.size()), return true.
5. If no valid segmentation is found from a particular index, memoize and return false.

Why memoization?
----------------
Without memoization, the same subproblems are solved multiple times, leading to exponential time.
Memoization reduces time complexity to polynomial by caching results for each index.

Time Complexity:  O(n^2 * m)
Space Complexity: O(n + m)
    - n = length of string
    - m = number of words in the dictionary
*/

class Solution {
public:
    // Recursive helper function with memoization
    bool solve(int idx, string &s, unordered_set<string> &wordSet, unordered_map<int, bool> &memo) {
        // Base case: If we've reached the end of the string, return true
        if (idx == s.size()) return true;

        // If result already computed, return it
        if (memo.find(idx) != memo.end()) {
            return memo[idx];
        }

        // Try every substring starting at idx
        for (int len = 1; idx + len <= s.size(); len++) {
            string temp = s.substr(idx, len);

            // If temp is in dictionary, check remaining string
            if (wordSet.find(temp) != wordSet.end()) {
                if (solve(idx + len, s, wordSet, memo)) {
                    return memo[idx] = true;
                }
            }
        }

        // No valid segmentation found from this index
        return memo[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());  // Convert to set for O(1) lookup
        unordered_map<int, bool> memo;  // Memoization map
        return solve(0, s, wordSet, memo);
    }
};

// ---------- Driver code ----------
int main() {
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    if (sol.wordBreak(s, wordDict)) {
        cout << "True: String can be segmented." << endl;
    } else {
        cout << "False: String cannot be segmented." << endl;
    }

    return 0;
}

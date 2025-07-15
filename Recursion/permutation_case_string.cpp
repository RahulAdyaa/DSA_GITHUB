#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

// ✅ Time Complexity:  O(2^L)
// ✅ Space Complexity: O(2^L * N)

class Solution {
public:
    void permute(int index, string curr_sol, string &s, vector<string>& ans) {
        if (index == s.size()) {
            ans.push_back(curr_sol);
            return;
        }

        // Always include the character as-is first
        if(isdigit(s[index])){

            curr_sol.push_back(s[index]);
            permute(index + 1, curr_sol, s, ans);
            curr_sol.pop_back(); // backtrack
        }

        // If it's a letter, try toggled case version
        if (isalpha(s[index])) {
            curr_sol.push_back(toupper(s[index]));
            permute(index + 1, curr_sol, s, ans);
            curr_sol.pop_back(); // backtrack

            curr_sol.push_back(tolower(s[index]));
            permute(index + 1, curr_sol, s, ans);
            curr_sol.pop_back(); // backtrack
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string curr_sol;
        permute(0, curr_sol, s, ans);
        return ans;
    }
};

// Driver code
int main() {
    Solution sol;
    string input = "ab";
    vector<string> result = sol.letterCasePermutation(input);

    cout << "All permutations of \"" << input << "\" are:\n";
    for (string& str : result) {
        cout << str << endl;
    }
    return 0;
}

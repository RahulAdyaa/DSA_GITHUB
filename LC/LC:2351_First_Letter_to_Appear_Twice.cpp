// TC: O(n), SC: O(1)
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    // Returns the first character that appears more than once
    char repeatedCharacter(string s) {
        unordered_set<char> uniqueChars;

        for (char ch : s) {
            // If character already exists in the set, return it
            if (uniqueChars.count(ch)) {
                return ch;
            }
            uniqueChars.insert(ch);
        }

        // If no repeated character found (problem constraints should guarantee one)
        return '\0';
    }
};

int main() {
    Solution sol;

    string s = "aabccbaacz";
    char result = sol.repeatedCharacter(s);

    if (result != '\0') {
        cout << "First repeated character is: " << result << endl;
    } else {
        cout << "No repeated character found." << endl;
    }

    return 0;
}

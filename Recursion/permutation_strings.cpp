#include<iostream>
#include<vector>
using namespace std;

/*
================================================================
🔁 INTUITION – IN-PLACE SWAP (Backtracking):

This is the **optimized approach** for generating permutations.
We recursively fix one position at a time using in-place swaps
without any extra space like frequency array or visited markers.

🧠 At each index, we swap the current index with every other
position i (from index to end), and recursively generate the
rest of the permutations. Then, we **backtrack** (swap back).

================================================================
📊 TIME & SPACE COMPLEXITY:

✅ Time Complexity: O(n!)  
- Because total number of permutations of n elements is n!.

✅ Space Complexity: O(n)  
- Due to recursion stack only (no freq[], no auxiliary vector).

🚩 This is the **more efficient** approach in terms of memory
compared to the frequency-array-based solution.

================================================================
*/

void permute(int index, vector<string>& ans, string str) {
    if(index == str.size()) {
        ans.push_back(str);  // base case: store the permutation
        return;
    }

    for(int i = index; i < str.size(); i++) {
        swap(str[index], str[i]);              // Fix element at 'index'
        permute(index + 1, ans, str);          // Recurse
        swap(str[index], str[i]);              // Backtrack
    }
}

int main() {
    string word="abc";
    vector<string> ans;

    permute(0, ans , word);  // start from index 0

    for(auto& permutation : ans) {
        cout << "{ ";
        for(auto ch : permutation) {
            cout << ch << " ";
        }
        cout << "}\n" << endl;
    }
}

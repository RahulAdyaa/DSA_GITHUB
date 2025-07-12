#include<iostream>
using namespace std;

// Time: O(2^n), Space: O(2^n)
// void getSubseq(int idx, string current, string &t, vector<string>& ans) {
//         if (idx == t.size()) {
//             ans.push_back(current); // Store each complete subsequence
//             return;
//         }

//         // Include current character
//         getSubseq(idx + 1, current + t[idx], t, ans);

//         // Exclude current character
//         getSubseq(idx + 1, current, t, ans);
//     }

//     bool isSubsequence(string s, string t) {
//         vector<string> ans;
//         getSubseq(0, "", t, ans); // Generate all subsequences of t

//         // Check if s is one of the generated subsequences
//         return std::find(ans.begin(), ans.end(), s) != ans.end();
//     }


int main(){
    string s;
    string t;
    getline(cin,s);
    getline(cin,t);
    

    int i = 0;
    int j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) i++;  // If match, move pointer in s
        j++;                    // Always move pointer in t
    }

    // All characters in s matched in order?
    if (i == s.size()) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;

    // Time: O(n), Space: O(1)
}
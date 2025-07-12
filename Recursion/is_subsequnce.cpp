#include<iostream>
using namespace std;


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
}
#include<iostream>
#include<vector>
using namespace std;

bool ispalindrome(int n, string &s){
    if(n>=s.size()/2) return true;
    if(s[n]!= s[s.size()-n-1]){
        return false;
    }
    return ispalindrome(n+1,s);
}
int main(){
    string s;
    getline(cin,s);
    cout<<ispalindrome(0,s);
}

#include<iostream>
using namespace std;

void getsubsequences(int idx,string &s , string current , vector<string>&ans){
    if(idx==s.size()){
        ans.push_back(current);
        return ;
    }
    // Include the current character
    getsubsequences(idx+1,s,current+s[idx],ans);
    // Exclude the current character
    getsubsequences(idx+1,s,current,ans);
}
int main(){
    string s;
    cout<<"enter a string"<<endl;
    getline(cin,s);
    vector<string>ans;
    getsubsequences(0,s,"",ans);
    cout << "\nAll Subsequences:\n";
    for (const string &subseq : ans) {
        cout << "\"" << subseq << "\"\n";
    }


} 
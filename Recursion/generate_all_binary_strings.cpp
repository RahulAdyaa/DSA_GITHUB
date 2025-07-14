#include<iostream>
using namespace std;

void generatestrings(string &ds,int n, vector<string>&ans){
    if(ds.size()==n){
        ans.push_back(ds);
        return;
    }
    ds.push_back('0');
    generatestrings(ds,n,ans);
    ds.pop_back();
    
    ds.push_back('1');
    generatestrings(ds,n,ans);
    ds.pop_back();



}

int main(){
    string ds;
    vector<string>ans;
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;

    generatestrings(ds,n,ans);

    for(auto str:ans){
        cout<<"{";
        for(auto val:str){
            cout<<val;
        }
        cout<<"}\n";
    }

}
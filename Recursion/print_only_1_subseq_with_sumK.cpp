#include<iostream>
using namespace std;

bool printS(int ind , vector<int>& ds, vector<int>& arr,int n , int sum , int k){
    if(ind==n){
        if(sum==k){
            //condn satisfied
            for(auto it:ds) cout<<it<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }

    ds.push_back(arr[ind]);
    sum+=arr[ind];
    if(printS(ind+1,ds,arr,n,sum,k) ==true){
        return true;
    }

    sum-=arr[ind];
    ds.pop_back();
    if(printS(ind+1,ds,arr,n,sum,k) ==true){
        return true;
    }
    return false;


}


int main(){
    vector<int>arr={1,2,3,4,5};
    vector<int>ds;
    int k=5;
    int n=5;
    printS(0,ds,arr,n,0,k);

}
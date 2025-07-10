#include<iostream>
using namespace std;

int countS(int ind , vector<int>& arr, int sum , int n , int k ){
    if(ind==n){
        if(sum==k) return 1;
        else return 0;
    }
   
    sum+=arr[ind];
    int l=countS(ind+1,arr,sum,n,k);

    sum-=arr[ind];
    int r=countS(ind+1,arr,sum,n,k);

    return l+r;
}

int main(){
    vector<int> arr={3,1,2};

    int k=3;
    int n=3;
    vector<int>ds;

    cout<<countS(0,arr,0,n,k)<<endl;
}
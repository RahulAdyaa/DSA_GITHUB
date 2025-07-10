#include <iostream>
#include <vector>
using namespace std;

void printS(int ind, vector<int> &ds, vector<int> &arr, int n, int sum, int k){
    if(ind==n){
        if(sum==k){
            for(auto it:ds) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }

    ds.push_back(arr[ind]);
    sum+=arr[ind];
    printS(ind+1,ds,arr,n,sum,k);
    
    sum-=arr[ind];
    ds.pop_back();
    printS(ind+1,ds,arr,n,sum,k);
    
}


int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 5;
    int n=5;
    vector<int> ds;
    printS(0, ds, arr, n,0,k);
}

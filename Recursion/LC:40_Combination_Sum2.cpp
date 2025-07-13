#include<iostream>
using namespace std;

void getcombinations(int ind,int target , vector<int>&arr , vector<int>&ds , vector<vector<int>>&ans ){
    if(target==0){
        ans.push_back(ds);
        return;
    }

    for(int i=ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;

        ds.push_back(arr[i]);
        getcombinations(i+1,target-arr[i],arr,ds,ans);
        ds.pop_back();
    }
}

int main(){
    vector<int>arr={10,1,2,7,6,1,5};
    int target=8;
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>ds;
    getcombinations(0,target,arr,ds,ans);

    cout << "\nAll possible sombinations:\n";
    for (auto comb : ans) {
        cout << "{ ";
        for (int val : comb) {
            cout << val << " ";
        }
        cout << "}\n";
    }

    return 0;


}
// ✅ Time Complexity:
// Sorting greed[]  -> O(n log n), where n = greed.size()
// Sorting size[]   -> O(m log m), where m = size.size()
// Two-pointer loop -> O(n + m)
// 👉 Total TC = O(n log n + m log m)

// ✅ Space Complexity:
// Uses constant extra space → O(1) (excluding input vectors)

// ✅ Intuition:
// Each child has a "greed factor" (minimum cookie size they need).
// Each cookie has a size.
// Our goal is to assign cookies to as many children as possible such that
// the cookie size >= child's greed. One cookie per child, one child per cookie.
//
// Steps:
// 1. Sort both greed[] and size[].
// 2. Use two pointers (l for children, r for cookies).
// 3. If the current cookie (size[r]) can satisfy the current child (greed[l]),
//    assign it and move both pointers forward.
//    Else, try the next larger cookie (r++).
// 4. Return the count of satisfied children (l).

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>&greed , vector<int>&size){
    sort(greed.begin(), greed.end());
    sort(size.begin(), size.end());
    int l = 0;
    int r = 0;
    while(l < greed.size() && r < size.size()){
        if(size[r] >= greed[l]){
            l++;
        }
        r++;
    }
    return l;
}

int main(){
    vector<int>greed = {12, 6, 3, 4, 5};
    vector<int>size = {12, 1, 4, 5};
    cout << solve(greed, size);  // Output: 3
}

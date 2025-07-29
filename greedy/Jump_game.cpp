#include <iostream>
#include <vector>
using namespace std;

/*
✅ Intuition:
You're at index `i`, and can jump up to `i + arr[i]`.
Greedily track the farthest index you can reach (`maxInd`).
If at any point `i > maxInd`, you can't reach `i`, so return false.

🕒 Time Complexity: O(n)
🧠 Space Complexity: O(1)
*/

bool solve(vector<int>& arr) {
    int n = arr.size();
    int maxInd = 0;
    for (int i = 0; i < n; i++) {
        if (i > maxInd) return false;
        maxInd = max(maxInd, i + arr[i]);
        if (maxInd >= n - 1) return true;
    }
    return true;
}

int main() {
    vector<int> arr = {1, 2, 4, 1, 1, 0, 2, 4};
    
    cout << boolalpha << solve(arr) << endl;  // prints true or false as words
    return 0;
}

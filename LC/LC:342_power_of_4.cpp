// TC: O(1) for Bit Manipulation and Logarithmic methods; O(log n) for Iterative
// SC: O(1)

#include <iostream>
#include <cmath>       // for log and pow
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {

        // ✅ APPROACH 1: Iterative Division
        
        // if (n <= 0) return false;
        // while (n % 4 == 0) {
        //     n /= 4;
        // }
        // return n == 1;
        

        // ✅ APPROACH 2: Logarithmic Check
        
        // if (n <= 0) return false;
        // int x = (log(n) / log(4)); // truncated towards zero
        // return pow(4, x) == n;
        

        // ✅ APPROACH 3: Bit Manipulation (Optimal)
        if (n <= 0) return false;
        return (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }
};

int main() {
    Solution sol;

    // Sample test case
    int n;
    cout << "Enter number: ";
    cin >> n;

    if (sol.isPowerOfFour(n)) {
        cout << n << " is a power of four.\n";
    } else {
        cout << n << " is NOT a power of four.\n";
    }

    return 0;
}

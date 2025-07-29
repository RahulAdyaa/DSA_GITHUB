#include <iostream>
#include <vector>
using namespace std;

/*
🧠 INTUITION:
Each customer gives a $5, $10, or $20 bill. We must give correct change using only $5 and $10 bills.
We always try to give the highest denomination first (greedy approach).

📈 TIME COMPLEXITY: O(n), where n = number of customers
📦 SPACE COMPLEXITY: O(1), constant extra space for five and ten dollar counters
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } 
            else if (bill == 10) {
                if (five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } 
            else { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};

// ✅ Driver code for testing in VS Code
int main() {
    Solution sol;
    vector<int> bills = {5, 5, 5, 10, 20};  // You can change this test case
    bool result = sol.lemonadeChange(bills);

    if (result) {
        cout << "All customers received correct change.\n";
    } else {
        cout << "Could not provide correct change to a customer.\n";
    }

    return 0;
}

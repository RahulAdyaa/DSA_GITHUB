#include <iostream>
#include <vector>
using namespace std;

/*
🧠 INTUITION:
You're given a value `V`, and you want to find the **minimum number of Indian currency coins/notes**
to sum up to `V`. The denominations available are:
{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000}

Approach:
- Use a greedy strategy: always pick the largest coin ≤ V.
- Subtract it from V and repeat.
- This works because the Indian currency system is canonical (greedy gives optimal).

📈 TIME COMPLEXITY:
- O(N), where N = number of coins used (in worst case, like all 1s)

📦 SPACE COMPLEXITY:
- O(N) for storing the answer (number of coins used)
*/

class Solution {
  public:
    pair<vector<int>,int> minPartition(int V) {
        vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int> ans;
        int count=0;

        // Start from largest coin, move toward smaller
        for (int i = coins.size() - 1; i >= 0; i--) {
            while (V >= coins[i]) {
                V -= coins[i];
                ans.push_back(coins[i]);
                count++;
            }
        }

        return {ans,count};
    }
};

// ✅ Driver code
int main() {
    int V;
    cout << "Enter the amount: ";
    cin >> V;

    Solution sol;
    auto [coinsUsed, totalCount] = sol.minPartition(V);

    cout << "Minimum coins/notes used: ";
    for (int coin : coinsUsed) {
        cout << coin << " ";
    }

    cout << "\nTotal coins/notes used: " << totalCount << endl;
    cout << endl;

    return 0;
}

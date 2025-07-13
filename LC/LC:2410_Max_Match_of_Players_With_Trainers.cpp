#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // Sort both arrays to use greedy matching
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        //if not sort , it fail for test case 
        //      [1    100]
        //      [100    1]
        // it will return 1 but should return 2 as 1 can be with 1 and 100 be with 100

        int count = 0;
        int i = 0;  // Pointer for players
        int j = 0;  // Pointer for trainers

        // Greedy approach: Try to match each player to the smallest trainer that fits
        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                // Trainer can handle this player
                count++;
                i++;  // Move to next player
                j++;  // Move to next trainer
            } else {
                // Trainer too weak, try next trainer
                j++;
            }
        }

        return count;  // Total matched pairs
    }
};

// ✅ Time Complexity:
// - Sorting: O(n log n + m log m), where n = players.size(), m = trainers.size()
// - Matching loop: O(n + m)
// - Overall: O(n log n + m log m)

// ✅ Space Complexity:
// - O(1) extra space (in-place sorting)

int main() {
    Solution sol;

    vector<int> players = {1 , 10};
    vector<int> trainers = {10,1};

    int maxMatches = sol.matchPlayersAndTrainers(players, trainers);
    cout << "Maximum matched pairs: " << maxMatches << endl;

    return 0;
}

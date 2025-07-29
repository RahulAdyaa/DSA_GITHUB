#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    /*
    ---------------------------------------------------
    ✅ Approach 1: Two Arrays (Left-to-Right + Right-to-Left)
    ---------------------------------------------------
    Intuition:
    - Each child gets at least one candy.
    - Traverse left-to-right and assign +1 if rating increases.
    - Traverse right-to-left and assign +1 if rating increases.
    - Final result = max(left[i], right[i]) for each child.

    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    int candyTwoArrays(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1), right(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                right[i] = right[i + 1] + 1;
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            total += max(left[i], right[i]);
        }
        return total;
    }

    /*
    ---------------------------------------------------
    ✅ Approach 2: One Array + Right-to-Left Scan
    ---------------------------------------------------
    Intuition:
    - Store left-to-right in one array.
    - Do right-to-left with one variable.
    - At each step: max(left[i], current right count).

    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    int candyOneArray(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
        }

        int total = left[n - 1];
        int right = 1;

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }
            total += max(left[i], right);
        }
        return total;
    }

    /*
    ---------------------------------------------------
    ✅ Approach 3: Greedy (Peak-Valley)
    ---------------------------------------------------
    Intuition:
    - Traverse and track increasing (up) and decreasing (down) slopes.
    - Add candies during up and down slopes.
    - Compensate if the down slope is longer than the up.

    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    int candyGreedy(vector<int>& ratings) {
        int n = ratings.size();
        int total = 1;
        int i = 1;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                total++;
                i++;
                continue;
            }

            // increasing slope
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                total += peak;
                i++;
            }

            // decreasing slope
            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                total += down;
                down++;
                i++;
            }

            // compensate if down > peak
            if (down > peak)
                total += down - peak;
        }

        return total;
    }
};


// 🔍 Sample Usage
int main() {
    Solution sol;
    vector<int> ratings = {1, 0, 2};

    cout << "Approach 1 (Two Arrays): " << sol.candyTwoArrays(ratings) << endl;
    cout << "Approach 2 (One Array): " << sol.candyOneArray(ratings) << endl;
    cout << "Approach 3 (Greedy): " << sol.candyGreedy(ratings) << endl;

    return 0;
}

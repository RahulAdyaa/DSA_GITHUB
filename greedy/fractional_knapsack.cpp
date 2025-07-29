#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
🧠 INTUITION:
You're given two arrays:
- val[]: values of items
- wt[]: weights of items
You can take fractional parts of an item.
Your goal is to maximize the value that fits into the knapsack of given capacity.

Approach:
- Create a list of items with their value and weight.
- Sort items based on value/weight ratio in descending order.
- Pick as many whole items as you can, then take a fraction of the next if needed.

📈 TIME COMPLEXITY:
- Sorting items: O(n log n)
- Picking items: O(n)
- Total: O(n log n)

📦 SPACE COMPLEXITY:
- O(n) → for the vector of Item objects
*/

// Structure to hold each item's value and weight
class Item {
  public:
    int value;
    int weight;
};

// Comparator function to sort items by decreasing value/weight ratio
bool static cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> items(n);

        // Step 1: Create Item list from val[] and wt[]
        for (int i = 0; i < n; i++) {
            items[i].value = val[i];
            items[i].weight = wt[i];
        }

        // Step 2: Sort items by value/weight ratio
        sort(items.begin(), items.end(), cmp);

        double totalVal = 0.0;
        int finalWt = 0;

        // Step 3: Greedily pick full or fractional items
        for (int i = 0; i < n; i++) {
            if (finalWt + items[i].weight <= capacity) {
                // Take full item
                totalVal += items[i].value;
                finalWt += items[i].weight;
            } else {
                // Take fraction of item
                int remain = capacity - finalWt;
                totalVal += ((double)items[i].value / items[i].weight) * remain;
                break; // Knapsack is full
            }
        }

        return totalVal;
    }
};

// ✅ Driver code for testing
int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    Solution sol;
    double maxValue = sol.fractionalKnapsack(val, wt, capacity);

    cout << "Maximum value in Knapsack = " << maxValue << endl;
    return 0;
}

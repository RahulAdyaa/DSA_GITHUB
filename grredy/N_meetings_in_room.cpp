#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
✅ Intuition:
We are given multiple meetings with start and end times.
To schedule the **maximum number of non-overlapping meetings**, we:
1. Sort all meetings by their end times.
2. Always pick the next meeting whose start time is after the end time of the last selected one.

This greedy strategy works because finishing earlier leaves more room for future meetings.

🕒 Time Complexity: O(n log n)
    - Sorting takes O(n log n)
    - Iteration takes O(n)

🧠 Space Complexity: O(n)
    - For storing meeting data in a vector of structs
*/

struct Data {
    int start;
    int end;
    int pos;
};

// Comparator: sort by end time
bool comp(Data val1, Data val2) {
    return val1.end < val2.end;
}

vector<int> solve(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<Data> items(n);

    for (int i = 0; i < n; i++) {
        items[i].start = start[i];
        items[i].end = end[i];
        items[i].pos = i + 1;
    }

    sort(items.begin(), items.end(), comp);

    vector<int> ans;
    if (n == 0) return ans;

    ans.push_back(items[0].pos);
    int freetime = items[0].end;

    for (int i = 1; i < n; i++) {
        if (items[i].start > freetime) {
            freetime = items[i].end;
            ans.push_back(items[i].pos);
        }
    }

    return ans;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    vector<int> ans = solve(start, end);

    for (auto val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

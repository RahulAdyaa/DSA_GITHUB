#include <iostream>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool static compare(Job a, Job b) {
    return a.profit > b.profit;
}

pair<int, int> jobSequencing(Job jobs[], int n) {
    // Step 1: Sort by profit descending
    sort(jobs, jobs + n, compare);

    // Step 2: Find max deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Step 3: Create slot array
    vector<int> slot(maxDeadline + 1, -1); // -1 means free

    int countJobs = 0;
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        // Step 4: Try to schedule job from its deadline to earlier slots
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i; // assign job i to this slot
                countJobs++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    return {countJobs, totalProfit};
}

int main() {
    Job jobs[] = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    pair<int, int> result = jobSequencing(jobs, n);
    cout << "Max Jobs Done: " << result.first << ", Total Profit: " << result.second << endl;

    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

/*
    Problem: Ninja’s Training
    Task: Maximize the total points over n days such that the same task is not done on two consecutive days.

    Time Complexity: O(n * 4 * 3) = O(n)
    Space Complexity: O(n * 4) [for memo dp]
*/

int solve(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
    // Base Case: First day, choose the max from tasks not equal to last
    if(day == 0) {
        int maxi = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];

    int maxi = 0;
    for(int task = 0; task < 3; task++) {
        if(task != last) {
            int point = points[day][task] + solve(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }

    return dp[day][last] = maxi;
}

//TABULATION

int solve(int n , vector<vector<int>>&nums){
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0]=max(nums[0][1],nums[0][2]);
    dp[0][1]=max(nums[0][0],nums[0][2]);
    dp[0][2]=max(nums[0][0],nums[0][1]);
    dp[0][3]=max(nums[0][1],max(nums[0][1],nums[0][2]));

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int point=nums[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}

int main() {
    vector<vector<int>> points = {
        {2, 1, 3},
        {3, 4, 6},
        {10, 1, 6}
    };

    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));  // dp[day][last_task]

    cout << "Maximum Points: " << solve(n - 1, 3, points, dp) << endl;
    cout << "Maximum Points: " << solve(n ,points) << endl;
    return 0;
}

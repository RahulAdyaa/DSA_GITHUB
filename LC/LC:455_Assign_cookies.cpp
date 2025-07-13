#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = 0;
        int j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};

int main() {
    Solution sol;

    vector<int> greed = {1, 2};
    vector<int> cookies = {1, 2, 3};

    int result = sol.findContentChildren(greed, cookies);
    cout << "Maximum content children: " << result << endl;

    return 0;
}

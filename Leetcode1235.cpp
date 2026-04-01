#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> jobs;
    vector<int> dp;

    int binarySearch(int index) {
        int l = index + 1, r = jobs.size() - 1;
        int ans = jobs.size();

        while (l <= r) {
            int mid = (l + r) / 2;
            if (jobs[mid][0] >= jobs[index][1]) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int solve(int index) {
        if (index >= jobs.size()) return 0;
        if (dp[index] != -1) return dp[index];

        // skip
        int skip = solve(index + 1);

        // take
        int next = binarySearch(index);
        int take = jobs[index][2] + solve(next);

        return dp[index] = max(skip, take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
        dp.resize(n, -1);

        return solve(0);
    }
};
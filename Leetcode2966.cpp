#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % 3 != 0) return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i += 3) {
            int a = nums[i], b = nums[i+1], c = nums[i+2];
            if (c - a <= k) {
                ans.push_back({a, b, c});
            } else {
                return {};
            }
        }

        return ans;
    }
};


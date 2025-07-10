#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int robber(int i, vector<int>& dp,vector<int>& nums){
        
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1){
        return dp[i];
        }
        dp[i] =max(nums[i]+robber(i+2,dp,nums),robber(i+1,dp,nums));
        
        return dp[i];
    }
    int rob(vector<int>& nums) {
     vector<int> dp(nums.size() + 1, -1);
     int steal = 0;
     steal =  robber(0,dp,nums);
     return steal;
    }
};
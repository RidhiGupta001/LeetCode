#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countsteps(int n, vector<int>&dp){
         if(n<0){
            return 0;
        }
        if (dp[n] != -1){
            return dp[n];
        }
       
        if(n==0){
            return 1;
        }
        return dp[n] = countsteps(n-1,dp) + countsteps(n-2,dp);
    }
    int climbStairs(int n) {
    vector<int> dp(n+1,-1);
    int ways = countsteps(n,dp);
    return ways; 
    }
};
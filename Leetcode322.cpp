#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int solve(int value,vector<int> coins,vector<int> &dp){
    if(value<0){
        return INT_MAX;
    }
    if(dp[value] != -1){
        return dp[value];
    }
    if(value == 0){
        return 0;
    }
    int number_coins = INT_MAX;
    for(int i = 0;i<coins.size();i++){
        int diff = value - coins[i];
        int res = solve(diff,coins,dp);
        if(res != INT_MAX){
            number_coins = min(number_coins,1+res);
            dp[value] = number_coins;
        }
    }
    return dp[value];
    }
    int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount +1 , -1);
    int no_coins = solve(amount,coins,dp);
    vector<int> dp(amount,-1);
    if(no_coins == INT_MAX){
        return -1;
    }
    else{return no_coins;}

    }
};
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int gridtraveller(int m,int n,vector<vector<int>> &dp){
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        else if(m == 1 && n == 1){
            dp[m][n]=1;
        }
        else if(m ==0 || n ==0){
            dp[m][n]=0;
        }
        else{
            dp[m][n] = gridtraveller(m-1,n,dp) + gridtraveller(m,n-1,dp);
        }
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
    gridtraveller(m,n,dp);
    return dp[m][n] ;  
    }
};
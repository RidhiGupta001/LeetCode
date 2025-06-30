#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int ispalindrome(string s, int i, int j, vector<vector<int>> &dp) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i >= j) {
            dp[i][j] = 1;
        } else if (s[i] == s[j]) {
            dp[i][j] = ispalindrome(s, i + 1, j - 1, dp);  
        } else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

    int countSubstrings(string s) {
        int palindrome = 0;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (ispalindrome(s, i, j, dp) == 1) {
                    palindrome++;
                }
            }
        } 
        return palindrome;
    }
};
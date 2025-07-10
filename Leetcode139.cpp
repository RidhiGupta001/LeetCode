#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    unordered_set<string> words;
    
    bool solve(int idx, string s,vector<int> &dp){
        if(idx >= s.size()){
         return true;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        if (words.find(s)!=words.end()){
            return true;
        }
        for(int l = 1; l<=s.size();l++){
            string x = s.substr(idx,l);
            if(words.find(x) != words.end() && solve(idx+l,s,dp)){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
    for(string word : wordDict){
        words.insert(word);
    } 
    vector<int> dp(s.size()+1,-1);
    bool ans = solve(0,s,dp);
    return ans;  
    }
};
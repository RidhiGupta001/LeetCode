#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxlen = 0;
    vector<int>dict(256,-1);
    int start = 0;
    for(int i = 0; i<n;i++){
    if(dict[s[i]] != -1){
    if(dict[s[i]] >= start){
        start = dict[s[i]]+1;
    }    
    }
    maxlen = max(maxlen, i - start + 1);
    dict[s[i]] = i;
    }
    return maxlen; 
    }
};
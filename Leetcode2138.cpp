#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();
        
        for (int i = 0; i < n; i += k) {
            string part = s.substr(i, k);
            while (part.length() < k) {
                part += fill;
            }
            ans.push_back(part);
        }
        
        return ans;
    }
};

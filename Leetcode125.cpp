#include <bits/stdc++.h>
#include <string>
class Solution {
public:
    bool isPalindrome(string s) {
        
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(c);
        }), s.end());

        
        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }

       
        int i = 0;
        int j = s.length() - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

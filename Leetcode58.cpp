#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int i = s.length() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count length of last word
        while (i >= 0 && s[i] != ' ') {
            ans++;
            i--;
        }

        return ans;
    }
};
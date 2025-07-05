#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.length() < needle.length()) return -1;

        int n = 0, s = 0;
        int x = needle.length();

        for (int i = 0; i < x; i++) {
            n += needle[i] - 'a' + 1;
            s += haystack[i] - 'a' + 1;
        }

        if (n == s && needle == haystack.substr(0, x)) {
            return 0;
        }

        for (int i = 1; i <= haystack.length() - x; i++) {
            s = s - (haystack[i - 1] - 'a' + 1);
            s = s + haystack[i + x - 1] - 'a' + 1;
            if (s == n && needle == haystack.substr(i, x)) {
                return i;
            }
        }

        return -1;
    }
};
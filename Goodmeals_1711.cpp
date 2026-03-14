#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1e9 + 7;
        unordered_map<int,int> freq;
        int count = 0;

        for(int i = 0; i < deliciousness.size(); i++) {

            int y = deliciousness[i];

            for(int p = 1; p <= (1<<21); p <<= 1) {

                int x = p - y;

                if(freq.count(x)) {
                    count = (count + freq[x]) % MOD;
                }
            }

            freq[y]++;
        }

        return count;
    }
};

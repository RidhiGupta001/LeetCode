#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
     sort(g.begin(),g.end());
     sort(s.begin(),s.end());
     int s1 = g.size();
     int s2 = s.size();
     int c= 0;
     int i=0,j=0;
     while(i<s1 && j<s2){
        if(g[i]<=s[j]){
            c++;
            i++;
            j++;
        }else{
            j++;
        }
     }
     return c;   
    }
};
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> t(n,0);
    vector<int> p(n,0);
    int x = trust.size();
    for(int i = 0; i<x ; i++){
        int z = trust[i][0] - 1; //truster
        int y = trust[i][1] -1;  // trusted
        t[y]++;
        p[z]++;
    } 
    for(int i = 0; i<n ;i++){
        if (t[i] == n-1 && p[i]  == 0){
            return i+1;
        }

    } 
    return -1;  
    }
};
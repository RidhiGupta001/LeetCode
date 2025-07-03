#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
    int n = t.size();
    int x = s.size();
    int i = 0;
    int j = 0;
    while(i<x && j<n){
    if(s[i] == t[j]){
        i++;
        j++;
    }else{
        j++; 
    }
    }   
    if (i == x){
        return true;
    }else{
        return false;
    }
    }
};
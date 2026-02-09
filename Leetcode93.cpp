#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int n;
    vector<string> result;

    bool isValid(string str){
        if(str[0]=='0'){
            return false;
        }

        int val = stoi(str);
        if(val > 255){
            return false;
        }
        return true;
    }

    void solve(string &s,int idx,int parts, string curr){
    
    if(parts == 4 && idx == n){
        curr.pop_back();
        result.push_back(curr);
        return;
    }
    if(idx + 1 <=n){ 
    solve(s,idx+1,parts+1,curr + s.substr(idx,1) + ".");}

    if(idx + 2 <=n && isValid(s.substr(idx,2))){ 
    solve(s,idx+2,parts+1,curr + s.substr(idx,2) + ".");}

    if(idx + 3 <=n && isValid(s.substr(idx,3))){ 
    solve(s,idx+3,parts+1,curr + s.substr(idx,3)+".");}}

    vector<string> restoreIpAddresses(string s) {
    n = s.size();

    if(n > 12 ){
        return {};
    }   
    int parts=0;
    string curr = "";
    solve(s,0,parts,curr);
    return result;
    }
};
//leetcode 440
//hard
#include <iostream>
using namespace std;


class Solution{
public:
int countsteps(int cur, int n){
    int res = 0;
    int neighbour = cur+1;
    while(cur <= n){
        int small = (neighbour < n+1)?neighbour:n+1;
        res = small - cur;  //moving downwards
        cur = cur*10;
        neighbour = neighbour*10;
    }
    return res;
}
int findnumber(int n, int k){
int iter = 1;
int cur = 1;
while(iter<k){
int steps = countsteps(cur,n);
if(iter + steps <= k)
{
cur = cur+1;        //moving rightwards
iter = iter + steps;
}
else
{
    cur = cur*10;  //moving downwards 
    iter = iter+1;
}}
return cur;
}
};


int main(){
    Solution s1;
    int k = 20;
    int n = 1361;
    int ans = s1.findnumber(n,k);
    cout<<"Lexicographically number = "<<ans;

    return 0;
}
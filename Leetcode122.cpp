#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int i = 0;
    int profit = 0;
    int maxprofit = 0;
    while(i<n-1){
        profit = prices[i+1] - prices[i];
        if(profit < 0){
            i++;
            continue;
        }else{
            maxprofit = maxprofit + profit;
            i++;
        }
    } 
    return maxprofit;  
    }
};
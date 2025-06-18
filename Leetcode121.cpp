#include <iostream>
#include <vector>
using namespace std;
//Leetcode 121 - best time to sell and buy stocks
class Solution{
public:
    int maxProfit(vector<int>& prices) {
        int min_price = 1e9;
        int max_profit = 0;

        for (int price : prices) {
            min_price = min(min_price, price);           //minimise the buying 
            max_profit = max(max_profit, price - min_price); //maximise the selling profit
        }

        return max_profit;}
};
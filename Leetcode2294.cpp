#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int count = 1;
    int min = nums[0];
    for(int i = 0;i<n;i++){
    if(nums[i] - min  > k){
        min = nums[i];
        count++;
    }
    }
    return count;   
    }
};
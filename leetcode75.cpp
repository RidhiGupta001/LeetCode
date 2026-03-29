#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
    int n = nums.size();
    int z = 0;
    int o = 0;
    int t = 0;
    for(int i = 0;i<n;i++){
        if(nums[i] == 0){
            z++;
        }else if(nums[i] == 1){
            o++;
        }else{
            t++;
        }
    }
    for(int i = 0;i<z;i++){
        nums[i] = 0;
    } 
    for(int i = z;i<o+z;i++){
        nums[i]=1;
    } 
    for(int i = z+o;i<z+o+t;i++){
        nums[i]=2;
    } 
    }
};

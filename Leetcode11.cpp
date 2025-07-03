#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
    int maxwater = 0;
    int i = 0;
    int j = height.size()-1;
    while(i<=j){
        maxwater = max(maxwater,min(height[i],height[j])*(j-i));
        if(height[i]>height[j]){
            j--;
        }else{
            i++;
        }
        }
        return maxwater;    
    }
};
// Given arrival arr[] and departure dep[] times of trains on the 
// same day, find the minimum number of platforms needed so that no 
// train waits. A platform cannot serve two trains at the same time; 
// if a train arrives before another departs, an extra platform is needed.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int size = arr.size();
        int count = 0;
        int maxcount = 0;
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i = 0,j=0;
        while(i<size){
            if(arr[i] <= dep[j]){
                count ++;
                i++;
            }else{
                count--;
                j++;
            }
        maxcount = max(count,maxcount);
        }
        return maxcount;
    }
};
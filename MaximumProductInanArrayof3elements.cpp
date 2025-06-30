#include <iostream>
#include <vector>
#include <climits> 
using namespace std;
class Solution {
  public:
    int maxProduct(vector<int> arr) {
        // code here
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        int n = arr.size();
        
        for(int i=0 ; i<n ; i++){
        if(arr[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i]>max2){
            max3 = max2;
            max2 = arr[i];   
        }
        else if(arr[i]>max3){
            max3 = arr[i];
        }
        
        if(arr[i]<min1){
            min2 = min1;
            min1 = arr[i];
        }
        else if(arr[i]<min2){
            min2 = arr[i];
        }
        }
        return max(max1*max2*max3, min1*min2*max1);
    }
};
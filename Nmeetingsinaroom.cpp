// Given one meeting room and N meetings represented by two arrays,
//  start and end, where start[i] represents the start time of the 
//  ith meeting and end[i] represents the end time of the ith meeting, 
//  determine the maximum number of meetings that can be accommodated 
//  in the meeting room if only one meeting can be held at a time.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end){
        //your code goes here
        
        int meeting = 1;
        int size = start.size();
        vector<pair<int,int>> arr;
        for(int i = 0;i<size;i++){
            arr.push_back({end[i],start[i]});
            }
        
        sort(arr.begin(),arr.end());
        int s =0;
        int e = arr[0].first;
        for(int i = 0;i<size;i++){
            s = arr[i].second;
        if(s > e){
            meeting++;
            e = arr[i].first;        }
        }
        return meeting;
    }
};
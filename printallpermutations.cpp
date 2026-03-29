//using extra space and recursion
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void printpermutations(vector<pair<int,int>>& picked,vector<vector<int>>& ans,int n,vector<int>& ds){
//base case
if(ds.size()==n){
   ans.push_back(ds); 
   for(int i : ds){
    cout<<i<<" ";
   }
   cout<<"\n";
   return;
}
for(int i = 0;i<n;i++){
    if(picked[i].second == 0){
        ds.push_back(picked[i].first);
        picked[i].second = 1;
        printpermutations(picked,ans,n,ds);
        picked[i].second = 0;
        ds.pop_back();
    }
    
}
}
int main(){
    vector<int> arr = {8,4,2,7,6};
    int n = arr.size();
    vector<vector<int>> ans;
    vector<int> ds;
    vector<pair<int,int>> picked;
    for(int i = 0;i<n;i++){
    picked.push_back({arr[i],0});
    
    }
    printpermutations(picked,ans,n,ds);
}

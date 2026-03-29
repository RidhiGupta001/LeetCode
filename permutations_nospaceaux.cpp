#include <iostream>
#include <vector>
using namespace std;
void printallpermutations(vector<int> &arr,int index,int n){
if(index == n){
    for(int x:arr){
        cout<<x<<" ";
    }
    cout<<"\n";
    return;
}

for(int i = index; i<n ;i++){
    swap(arr[index],arr[i]);
    printallpermutations(arr,index+1,n);
    swap(arr[index],arr[i]);
}
}
int main(){
    vector<int>arr = {1,2,3};
    int index = 0;
    int n = arr.size();
    printallpermutations(arr,index,n);
}
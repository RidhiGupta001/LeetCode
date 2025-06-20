#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int maxDistance(string s, int k) {
    int ans = 0;
    for(char hor : {'E','W'}){
    for(char ver : {'N','S'}){
    int x = 0 , y = 0, remaining = k;
    for(int i = 0;i<s.length();i++){
    char ch = s[i];
    if(ch == hor && remaining > 0){
        ch = (ch == 'E')? 'W':'E';
        remaining--;
    }else if( ch == ver && remaining>0){
        ch = (ch == 'N')? 'S' : 'N';
        remaining--;
    }
    x += (ch=='E');
    x -= (ch=='W');
    y += (ch=='N');
    y -= (ch=='S');
    ans = max(ans,abs(x)+abs(y));
    }
    }
    }
    return ans; 
    }
};

// int main(){
//     Solution s1;
//     string s = "NEWS";
//     int ans = s1.maxDistance(s,1);
//     cout<<ans;
// }
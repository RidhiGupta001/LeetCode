#include <iostream>
#include <vector>
#include <string>
using namespace std;
//goal -> max odd freq - min even freq
class Solution {
public:
    int maxDifference(string s) {
    vector<int>freq(26,0);
    //computing the frequency 
    for(int i = 0; i<s.length();i++){
        int pos = s[i] - 'a';
        freq[pos] ++;
    }
    int maxOdd = 0;
    int minEven = 1e9;
    for(int i = 0; i<26 ;i++){
        if (freq[i] % 2 != 0){
            maxOdd = max(maxOdd,freq[i]);
        }
        else if(freq[i] % 2 == 0 && freq[i] != 0){
            minEven = min(minEven,freq[i]);
        }
    }
    if(minEven  == 1e9 ){
        minEven  = 0;
    } 
    return maxOdd-minEven;    
    }
};
int main(){
Solution s1;
string s = "aaaaabbc";
int difference = s1.maxDifference(s);
cout<<"Max difference = "<<difference;
return 0;   
}
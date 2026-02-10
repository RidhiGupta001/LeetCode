#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
    int n = s.size();
     vector<int> count(26,0);
     string result;
     //recorded frequencies
     for(int i=0;i<n;i++){
       char ch = s[i];
       count[ch - 'a']++; 
     } 

     int i = 25; //largest index
     int j;
     int freq = 0;
     while(i >= 0){
        if(count[i] == 0){
            i--;
            continue;
        }

        if(count[i] != 0){
        freq = min(count[i],repeatLimit);
        result.append(freq,char('a' + i));
        count[i] -= freq;
        
        if(count[i] != 0){
            j = i-1;
            while(j >= 0 && count[j] == 0){
                j--;
            }
            if( j < 0 ){
                break;
            }
            result.push_back(char('a' + j));
            count[j]--;

        }}
     }

     return result;
    }
};

int main(){
    return 0;
}
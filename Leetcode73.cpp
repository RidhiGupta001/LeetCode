
#include <iostream>
#include <vector>
using namespace std;
//Brute Force
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[1].size();
    vector<vector<int>>zeroes; //record position of zeroes

    for(int i = 0; i<row;i++ ){
        for(int j = 0;j<col;j++){
            if(matrix[i][j] == 0){
                for(int r = 0; r<col;r++){
                    if(matrix[i][r] != 0){
                    matrix[i][r] = -1;}
                }
                for(int c = 0; c<row;c++){
                    if(matrix[c][j] != 0){
                    matrix[c][j] =-1;}
                }
            }
        }
    }

    for(int i = 0; i<row;i++ ){
        for(int j = 0;j<col;j++){
            if(matrix[i][j] == -1){
                matrix[i][j]=0;
            }
        }}
    
    }
};

//Optimal 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[1].size();
    vector<int> rows(row,0);
    vector<int>cols(col,0);

    for(int i = 0; i<row;i++ ){
        for(int j = 0;j<col;j++){
            if(matrix[i][j] == 0){
            rows[i] = 1;
            cols[j] = 1;    
        }
    }}

    for(int i = 0; i<row;i++ ){
        for(int j = 0;j<col;j++){
            if(rows[i]==1 || cols[j] ==1){
                matrix[i][j]=0;
            }
        }}
    
    }
};
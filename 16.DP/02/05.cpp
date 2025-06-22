// Minimum path sum in Triangular Grid

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recc(vector<vector<int>>&arr, int row, int col, vector<vector<int>>&dp){
    if(row==arr.size()-1){
        return arr[row][col];
    }

    if(dp[row][col] != -1) return dp[row][col];

    int down = arr[row][col] + recc(arr, row+1, col, dp);
    int diagonal = arr[row][col] + recc(arr, row+1, col+1, dp);

    return dp[row][col] = min(down, diagonal);
}

int minSumMemo(vector<vector<int>>&arr){
    int row = arr.size(), col=row;

    if(row==1) return arr[0][0];

    vector<vector<int>>dp(row, vector<int>(col, -1));

    return recc(arr, 0, 0, dp);
}

int minSumTabs(vector<vector<int>>&arr){
    int row = arr.size(), col=row;

    if(row==1) return arr[0][0];

    vector<vector<int>>dp(row, vector<int>(col, -1));

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(i==0 && j==0)
        }
    }
}

int main(){
    vector<vector<int>>arr = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout<<minSumMemo(arr)<<" ";
}
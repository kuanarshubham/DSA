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

    vector<vector<int>>dp(row, vector<int>(col, -1));

    for(int j=0; j<col; j++){
        dp[row-1][j] = arr[row-1][j];
    }

    for(int i=row-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int up = arr[i][j] + dp[i+1][j];
            int diagonal = arr[i][j] + dp[i+1][j+1];

            dp[i][j] = min(up, diagonal);
        }
    }

    return dp[0][0];
}

int spaceOpt(vector<vector<int>>&arr){
    int row = arr.size(), col=row;

    vector<int>prev(arr[row-1].begin(), arr[row-1].end()), temp(col, -1);

    for(int i=row-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int up = arr[i][j] + prev[j];
            int diagonal = arr[i][j] + prev[j+1];

            temp[j] = min(up, diagonal);
        }

        prev = temp;
    }

    return prev[0];
}

int main(){
    vector<vector<int>>arr = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout<<minSumMemo(arr)<<" "<<minSumTabs(arr)<<" "<<spaceOpt(arr)<<endl;
}
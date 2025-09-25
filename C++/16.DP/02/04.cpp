// Minimum path sum in Grid

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recc(vector<vector<int>>&grid, int i, int j, vector<vector<int>>&dp){
    if(i==0 && j==0){
        return grid[0][0];
    }

    if(i<0 || j<0) return 1e8;

    if(dp[i][j] != -1) return dp[i][j];

    int goUp = grid[i][j] + recc(grid, i-1, j, dp);
    int goLeft = grid[i][j] + recc(grid, i, j-1, dp);

    return dp[i][j] = min(goLeft, goUp);
}

int minSumMemo(vector<vector<int>>&grid){
    int m=grid.size(), n=grid[0].size();
    vector<vector<int>>dp(m, vector<int>(n, -1));
    return recc(grid, m-1, n-1, dp);
}

int minSumTabs(vector<vector<int>>&grid){
    int m=grid.size(), n=grid[0].size();
    vector<vector<int>>dp(m, vector<int>(n, -1));

    for(int row=0; row<m; row++){
        for(int col=0; col<n; col++){
            if(row==0 && col==0){
                dp[row][col] = grid[row][col];
                continue;
            }

            int goUp=1e8, goLeft=1e8;
            if(row-1>=0) goUp = grid[row][col] + dp[row-1][col];
            if(col-1>=0) goLeft = grid[row][col] + dp[row][col-1];

            dp[row][col] = min(goLeft, goUp);
        }
    }

    return dp[m-1][n-1];
}

int spaceOpt(vector<vector<int>>&grid){
    int m=grid.size(), n=grid[0].size();

    vector<int>prev(n, -1);

    for(int row=0; row<m; row++){
        vector<int>temp(n, -1);
        for(int col=0; col<n; col++){
            if(row==0 && col==0){
                temp[col] = grid[row][col];
                continue;
            }

            int goUp=1e8, goLeft=1e8;
            if(row-1>=0) goUp = grid[row][col] + prev[col];
            if(col-1>=0) goLeft = grid[row][col] + temp[col-1];

            temp[col] = min(goLeft, goUp);
        }

        prev = temp;
    }

    return prev[n-1];
}

int main(){
    vector<vector<int>>grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout<<minSumMemo(grid)<<" "<<minSumTabs(grid)<<" "<<spaceOpt(grid)<<endl;
}
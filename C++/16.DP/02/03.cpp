// place -1 in the maze

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recc(int n, int m, vector<vector<int>>&mat, vector<vector<int>>&dp){
    if(m==0 && n==0) return 1;
    
    if(m<0 || n<0) return 0;

    if(mat[m][n] == -1) return 0;

    if(dp[m][n]!=-1) return dp[m][n];

    int goUp = recc(m-1, n, mat, dp);
    int goLeft = recc(m, n-1, mat, dp);

    return dp[m][n] = goUp + goLeft;
}

int uniqueWaysMemo(vector<vector<int>>&mat){
    int m = mat.size(), n=mat[0].size();

    vector<vector<int>>dp(m, vector<int>(n, -1));

    return recc(m-1, n-1, mat, dp);
}

int uniqueWaysTabs(vector<vector<int>>&mat){
    int m=mat.size(), n=mat[0].size();
    vector<vector<int>>dp(m, vector<int>(n, -1));

    for(int row=0; row<m; row++){
        for(int col=0; col<n; col++){
            if(row==0 && col==0) {
                dp[0][0] = 1;
                continue;
            }

            if(mat[row][col] == -1) dp[row][col] = 0;
            else if(row==0 && col!=0) dp[row][col] = dp[row][col-1];
            else if(row!=0 && col==0) dp[row][col] = dp[row-1][col];
            else dp[row][col] = dp[row-1][col] + dp[row][col-1];
        }
    }

    return dp[m-1][n-1];
}

int spaceOpt(vector<vector<int>>&mat){
    int m=mat.size(), n=mat[0].size();
    vector<int>prev(n, 1);

    for(int row=1; row<m; row++){
        vector<int>temp(n, 0);
        for(int col=0; col<n; col++){
            if(mat[row][col] == -1) prev[col] = 0;
            else if(row==0 && col!=0) temp[col] = 1;
            else if(row!=0 && col==0) temp[col] = 1;
            else temp[col] = temp[col-1] + prev[col];
        }

        prev = temp;
    }

    return prev[n-1];
}

int main(){
    vector<vector<int>>mat = {
        {1, 1, 1},
        {1, -1, 1},
        {1, 1, 1}
    };

    cout<<uniqueWaysMemo(mat)<<" "<<uniqueWaysTabs(mat)<<" "<<spaceOpt(mat);
}
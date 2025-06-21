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
    
}

int main(){
    vector<vector<int>>mat = {
        {1, 1, 1},
        {1, -1, 1},
        {1, 1, 1}
    };

    cout<<uniqueWaysMemo(mat);
}
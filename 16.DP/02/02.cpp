// total number of unique paths

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recc(int m, int n, vector<vector<int>>&dp){
    if(m==0 && n==0) return 1;
    
    if(m<0 || n<0) return 0;

    if(dp[m][n]!=-1) return dp[m][n];

    int goUp = recc(m-1, n, dp);
    int goLeft = recc(m, n-1, dp);

    return dp[m][n] = goUp + goLeft;
}

int uniqueWaysMemo(int m, int n){
    vector<vector<int>>dp(m, vector<int>(n, -1));
    return recc(m-1, n-1, dp);
}

int uniqueWaysTabs(int m, int n){
    vector<vector<int>>dp(m, vector<int>(n, -1));
    dp[0][0] = 1;

    for(int row=0; row<m; row++){
        for(int col=0; col<n; col++){
            if(row==0 && col==0) continue;

            if(row==0 && col!=0) dp[row][col] = dp[row][col-1];
            else if(row!=0 && col==0) dp[row][col] = dp[row-1][col];
            else dp[row][col] = dp[row-1][col] + dp[row][col-1];
        }
    }

    return dp[m-1][n-1];
}

int spaceOpt(int m, int n){
    int base = 1;

    vector<int>prev(n, 1);

    for(int row=1; row<m; row++){
        vector<int>temp(n, 0);
        for(int col=0; col<n; col++){
            if(row==0 && col!=0) temp[col] = 1;
            else if(row!=0 && col==0) temp[col] = 1;
            else temp[col] = temp[col-1] + prev[col];
        }

        prev = temp;
    }

    return prev[n-1];
}

int main(){
    cout<<uniqueWaysMemo(3, 2)<<" "<<uniqueWaysTabs(3, 2)<<" "<<spaceOpt(3, 2)<<endl;
}
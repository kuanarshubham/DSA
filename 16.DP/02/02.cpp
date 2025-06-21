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

    
}

int main(){
    cout<<uniqueWaysMemo(3, 2)<<endl;
}